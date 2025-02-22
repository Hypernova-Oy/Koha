#!/usr/bin/perl

# 2009 BibLibre <jeanandre.santoni@biblibre.com>

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
#

use Modern::Perl;

use CGI             qw ( -utf8 );
use C4::Auth        qw( get_template_and_user );
use C4::Circulation qw( GetOfflineOperation ProcessOfflineOperation DeleteOfflineOperation );

my $query = CGI->new;

my ( $template, $loggedinuser, $cookie ) = get_template_and_user(
    {
        template_name => "offline_circ/list.tt",
        query         => $query,
        type          => "intranet",
        flagsrequired => { circulate => "circulate_remaining_permissions" },
    }
);

my $operationid = $query->param('operationid');
my $op          = $query->param('op') || q{};
my $result;

if ( $op eq 'cud-process' ) {
    my $operation = GetOfflineOperation($operationid);
    $result = ProcessOfflineOperation($operation);
} elsif ( $op eq 'cud-delete' ) {
    $result = DeleteOfflineOperation($operationid);
}

print CGI::header( '-type' => 'text/plain', '-charset' => 'utf-8' );
print $result;
