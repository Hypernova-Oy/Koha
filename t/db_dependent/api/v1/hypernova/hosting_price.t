#!/usr/bin/env perl

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

use Test::More tests => 1;
use Test::Mojo;
use t::lib::TestBuilder;
use t::lib::Mocks;

use Koha::Database;

my $schema  = Koha::Database->new->schema;
my $builder = t::lib::TestBuilder->new;

my $t = Test::Mojo->new('Koha::REST::V1');

subtest 'get_hosting_price() tests' => sub {
    plan tests => 6;

    $schema->storage->txn_begin;

    my $currency = $builder->build_object({
        class => 'Koha::Acquisition::Currencies',
        value => { active => 1 }
    })->store; # removes active 1 from all other currencies

    my $method = q{my $total = 0;
    $total += $params->{kohaBasicAnnualCirc};
    $total += $params->{kohaBasicBibRecords};
    $total += $params->{kohaBasicActiveStaff};
    $total += $params->{kohaIntgFinna}       ? 999 : 0;
    $total += $params->{kohaIntgMelinda}     ? 998 : 0;
    $total += $params->{kohaIntgSip2Clients} ? 997 : 0;
    $total += $params->{kohaIntgSmtp}        ? 996 : 0;
    $total += $params->{kohaIntgSms}         ? 995 : 0;
};

    t::lib::Mocks::mock_preference('HypernovaKohaHostingPriceFormula', $method);

    my $fields = {
        kohaBasicAnnualCirc  => 10000,
        kohaBasicBibRecords  => 1000,
        kohaBasicActiveStaff => 777,
        kohaIntgFinna        => Mojo::JSON->true,
        kohaIntgMelinda      => Mojo::JSON->false,
        kohaIntgSip2Clients  => Mojo::JSON->true,
        kohaIntgSmtp         => Mojo::JSON->true,
        kohaIntgSms          => Mojo::JSON->false,
    };

    my $query = join('&', hashref_to_query_without_URI_perldep($fields));
    # Warn on unsupported query parameter
    $t->get_ok("/api/v1/hypernova/hosting/price?$query")
        ->status_is(200)
        ->json_is('/price' => 14769)
        ->json_is('/price_formatted' => $currency->symbol . ' 14,769.00');

    $t->get_ok("/api/v1/hypernova/hosting/price?bad_request")
        ->status_is(400);

    $schema->storage->txn_rollback;

};

sub hashref_to_query_without_URI_perldep {
    my ($v, $p) = @_;
    my $r = ref($v);
    my $c = \&hashref_to_query_without_URI_perldep;
    return map { &$c($v->{$_}, $p ? $p . '.' . $_ : $_) } keys(%$v) if $r eq 'HASH';
    return $p . '=' . join('|', @$v) if $r eq 'ARRAY';
    return $p . '=' . $v;
}
