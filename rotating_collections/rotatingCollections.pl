#!/usr/bin/perl

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

use CGI qw ( -utf8 );

use C4::Output qw( output_html_with_http_headers );
use C4::Auth   qw( get_template_and_user );
use C4::Context;
use C4::RotatingCollections;

my $query = CGI->new;

my ( $template, $loggedinuser, $cookie ) = get_template_and_user(
    {
        template_name => "rotating_collections/rotatingCollections.tt",
        query         => $query,
        type          => "intranet",
        flagsrequired => { tools => 'rotating_collections' },
    }
);

my $branchcode = $query->cookie('branch');

my $collections = GetCollections();

$template->param(
    collectionsLoop => $collections,
);

output_html_with_http_headers $query, $cookie, $template->output;
