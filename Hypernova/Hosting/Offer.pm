package Hypernova::Hosting::Offer;

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

use Koha::Config::SysPrefs;
use Koha::Number::Price;

use Koha::Exceptions::Config;

=head1 NAME

Hypernova::Hosting::Offer - Hypernova Koha hosting offer form

=head1 API

=head2 Class methods

=cut

=head3 get_price

Get offer for Koha hosting

=cut

sub get_price {
    my ( $self, $params ) = @_;

    my $sub = C4::Context->preference('HypernovaKohaHostingPriceFormula');
    $sub =~ s/^\s+|\s+$//g;

    Koha::Exceptions::Config::MissingEntry->throw(
        error => 'Preference HypernovaKohaHostingPriceFormula is not defined.'
    ) unless $sub;

    # Attempt loading price function dynamically
    my $function = eval "sub { my (\$params) = \@_; $sub }";
    Koha::Exceptions::BadParameter->throw( error => $@ ) if $@;

    my $price;

    # Attempt executing price function
    eval { $price = $function->($params); };
    Koha::Exceptions::BadParameter->throw( error => $@ ) if $@;

    my $formatted = Koha::Number::Price->new( $price )->format( {
        with_symbol => 1
    } );
    return {
        price           => $price,
        price_formatted => $formatted,
    };
}

1;
