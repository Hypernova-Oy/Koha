#!/usr/bin/perl

# Copyright 2000-2002 Katipo Communications
# copyright 2010 BibLibre
#
# This file is part of Koha.
#
# Koha is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Koha is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Koha; if not, see <http://www.gnu.org/licenses>.

use Modern::Perl;

use CGI qw ( -utf8 );
use C4::Auth;
use C4::Context;
use C4::Output;
use C4::Koha;
use C4::Circulation qw{ IsBranchTransferAllowed DeleteBranchTransferLimits CreateBranchTransferLimit };

my $input = new CGI;

my ($template, $loggedinuser, $cookie)
    = get_template_and_user({template_name => "admin/branch_transfer_limits.tt",
			     query => $input,
			     type => "intranet",
                 flagsrequired => {parameters => 'manage_transfers'},
			     debug => 1,
			     });

my $fromBranch;
if((!defined($input->param('fromBranch'))) && C4::Context::mybranch() ne '')
{
    $fromBranch = Koha::Libraries->find(C4::Context::mybranch());
}
else
{
    $fromBranch = Koha::Libraries->find($input->param('fromBranch'));
}

# Set the template language for the correct limit type using $limitType
my $limitType = C4::Context->preference("BranchTransferLimitsType") || "ccode";

my @branches = Koha::Libraries->search({});
my @codes;

if ( $limitType eq 'ccode' ) {
    @codes = map {$_->authorised_value} Koha::AuthorisedValues->search({category => 'CCODE'}, {columns => ['authorised_value']});
}
elsif ( $limitType eq 'itemtype' ) {
    @codes = map {$_->itemtype} Koha::ItemTypes->search({}, {columns => ['itemtype']});
}

## If Form Data Passed, Update the Database
if ( $input->param('updateLimits') ) {
    DeleteBranchTransferLimits($fromBranch->branchcode);

	foreach my $code ( @codes ) {
		foreach my $toBranch ( @branches ) {
			my $isSet = not $input->param( $code . "_" . $toBranch->branchcode);
			if ( $isSet ) {
			    CreateBranchTransferLimit( $toBranch->branchcode, $fromBranch->branchcode, $code );
			}
		}
	}
}

## Caclulate the selected branch here, this is to avoid calling Branches.all(selected...) in the Template Toolkit since we already need all the branches here.
foreach my $branch ( @branches ) {
    $branch->selected(1) if $branch->branchcode eq $fromBranch->branchcode;
}
my $branchcount = scalar(@branches);

## Build the default data
my @codes_loop;
foreach my $code ( @codes ) {
	my @to_branch_loop;
	my %row_data;
	$row_data{ code } = $code;
	$row_data{ to_branch_loop } = \@to_branch_loop;
	foreach my $toBranch ( @branches ) {
		my %row_data;
                my $isChecked = IsBranchTransferAllowed( $toBranch->branchcode, $fromBranch->branchcode, $code );
		$row_data{ code }         = $code;
		$row_data{ toBranch }     = $toBranch;
		$row_data{ isChecked }    = $isChecked;	
		push( @to_branch_loop, \%row_data );
	}

	push( @codes_loop, \%row_data );
}


$template->param(
		branchcount => $branchcount,
		codes_loop => \@codes_loop,
		branches => \@branches,
		fromBranch => $fromBranch,
        limitType => $limitType,
		);

output_html_with_http_headers $input, $cookie, $template->output;

