package Koha::REST::V1::Hypernova;

# This file is part of Koha.
#
# Copyright 2019 Hypernova Oy
#
# Koha is free software; you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation; either version 3 of the License, or (at your option) any later
# version.
#
# Koha is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with Koha; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

use Modern::Perl;

use Mojo::Base 'Mojolicious::Controller';
use Try::Tiny;

use Hypernova::Hosting::Offer;

sub get_hosting_price {
    my $c = shift->openapi->valid_input or return;

    return try {
        my $params = $c->req->query_params->to_hash;
        my $price = Hypernova::Hosting::Offer->get_price($params);

        return $c->render(status => 200, openapi => $price);
    } catch {
        unless ( blessed $_ && $_->can('rethrow') ) {
            return $c->render(
                status  => 500,
                openapi => { error => "Something went wrong, check Koha logs for details." }
            );
        }
        if ( $_->isa('Koha::Exceptions::Config::MissingEntry') ) {
            return $c->render(
                status  => 403,
                openapi => { error => 'Service deactivated' }
            );
        }
        elsif ( $_->isa('Koha::Exceptions::BadParameter') ) {
            return $c->render(
                status  => 500,
                openapi => { error => $_->error }
            );
        }
        else {
            return $c->render(
                status  => 500,
                openapi => { error => "Something went wrong, check Koha logs for details." }
            );
        }
    };
}

1;
