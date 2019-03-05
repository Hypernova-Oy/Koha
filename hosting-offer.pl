#!/usr/bin/perl

# Copyright 2019 Hypernova Oy
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
use C4::Output;

use Koha::Config::SysPrefs;

my $query = new CGI;

my ( $template, $loggedinuser, $cookie, $flags ) = get_template_and_user(
    {
        template_name   => "hosting-offer.tt", # Just a valid template path
        query           => $query,
        type            => "intranet",
        authnotrequired => 1,
    }
);

my $integrations = {
    kohaIntgFinna       => 1,
    kohaIntgMelinda     => 1,
    kohaIntgSip2Clients => 1,
    kohaIntgSmtp        => 1,
    kohaIntgSms         => 1,
};

my $preference = Koha::Config::SysPrefs->find( { variable => 'HypernovaKohaHostingPriceFormula'} );
   $preference = $preference->value if defined $preference;

foreach ( keys %{$integrations} ) {
    delete $integrations->{$_} unless $preference ~~ qr/$_/;
}

$template->param(
    integrations => $integrations,
);

output_html_with_http_headers $query, $cookie, $template->output;
