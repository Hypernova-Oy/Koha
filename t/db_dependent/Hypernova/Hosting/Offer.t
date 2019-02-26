#!/usr/bin/perl

# This file is part of Koha.
#
# Copyright 2019 Hypernova Oy
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
use Test::More tests => 7;

use Koha::Database;
use t::lib::Mocks;

my $schema = Koha::Database->new->schema;

use_ok('Hypernova::Hosting::Offer');

my $params = {
    'kohaBasicAnnualCirc'  => 100000,
    'kohaBasicBibRecords'  => 777,
    'kohaBasicActiveStaff' => 589,
};

subtest 'No configuration' => sub {
    plan tests => 2;

    $schema->storage->txn_begin;

    my $method = q{};
    t::lib::Mocks::mock_preference('HypernovaKohaHostingPriceFormula', $method);
    like(C4::Context->preference('HypernovaKohaHostingPriceFormula'), qr/^$/,
        'Price function empty in database');

    eval {
        Hypernova::Hosting::Offer->get_price($params)
    };
    is(ref($@), 'Koha::Exceptions::Config::MissingEntry', 'Exception thrown');

    $schema->storage->txn_rollback;
};

subtest 'Code with invalid syntax' => sub {
    plan tests => 3;

    $schema->storage->txn_begin;

    my $method = q{)};
    t::lib::Mocks::mock_preference('HypernovaKohaHostingPriceFormula', $method);
    like(C4::Context->preference('HypernovaKohaHostingPriceFormula'), qr/^\)$/,
        'Price function defined in database');

    eval {
        Hypernova::Hosting::Offer->get_price($params)
    };
    is(ref($@), 'Koha::Exceptions::BadParameter', 'Exception thrown');
    like($@->error, qr/^syntax error/, 'Syntax error');

    $schema->storage->txn_rollback;
};

subtest 'Simple price' => sub {
    plan tests => 2;

    $schema->storage->txn_begin;

    my $method = q{return 5;};
    t::lib::Mocks::mock_preference('HypernovaKohaHostingPriceFormula', $method);
    like(C4::Context->preference('HypernovaKohaHostingPriceFormula'), qr/^return/,
        'Price function defined in database');

    is(Hypernova::Hosting::Offer->get_price($params)->{price}, 5, 'Got simple price');

    $schema->storage->txn_rollback;
};

subtest 'Simple math operations' => sub {
    plan tests => 2;

    $schema->storage->txn_begin;

    my $method = q{return (5+5)*2/5;};
    t::lib::Mocks::mock_preference('HypernovaKohaHostingPriceFormula', $method);
    like(C4::Context->preference('HypernovaKohaHostingPriceFormula'), qr/^return/,
        'Price function defined in database');

    is(Hypernova::Hosting::Offer->get_price($params)->{price}, 4, 'Got correct price');

    $schema->storage->txn_rollback;
};

subtest 'Use sub parameters' => sub {
    plan tests => 2;

    $schema->storage->txn_begin;

    my $method = q{return $params->{kohaBasicAnnualCirc};};
    t::lib::Mocks::mock_preference('HypernovaKohaHostingPriceFormula', $method);
    like(C4::Context->preference('HypernovaKohaHostingPriceFormula'), qr/^return/,
        'Price function defined in database');

    is(Hypernova::Hosting::Offer->get_price($params)->{price},
        $params->{'kohaBasicAnnualCirc'}, 'Got correct parameter value');

    $schema->storage->txn_rollback;
};

subtest 'Use math operations on parameters' => sub {
    plan tests => 2;

    $schema->storage->txn_begin;

    my $method = q{my $multiplier = 5;
my $first = $params->{kohaBasicAnnualCirc} * $multiplier;
my ($second, $third) = (2, 3.5);
my $return;
$return = {
  value => $first/$second+$third,
};
return $return->{value}
};

    t::lib::Mocks::mock_preference('HypernovaKohaHostingPriceFormula', $method);
    like(C4::Context->preference('HypernovaKohaHostingPriceFormula'), qr/^my /,
        'Price function defined in database');

    is(Hypernova::Hosting::Offer->get_price($params)->{price},
        250003.5, 'Got correct parameter value');

    $schema->storage->txn_rollback;
};
