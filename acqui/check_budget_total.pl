#!/usr/bin/perl

# Copyright 2008-2009 BibLibre SARL
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
use C4::Context;
use C4::Output  qw( output_html_with_http_headers );
use C4::Auth    qw( get_template_and_user );
use C4::Budgets qw( GetBudget );

=head1 DESCRIPTION

fetches the budget amount from the DB

=cut

my $input     = CGI->new;
my $budget_id = $input->param('budget_id');
my $total     = $input->param('total');

my ( $template, $loggedinuser, $cookie ) = get_template_and_user(
    {
        template_name => "acqui/ajax.tt",
        query         => $input,
        type          => "intranet",
    }
);

my $budget = GetBudget($budget_id);

$template->param( return => $budget->{'budget_amount'} );

output_html_with_http_headers $input, $cookie, $template->output;
1;
