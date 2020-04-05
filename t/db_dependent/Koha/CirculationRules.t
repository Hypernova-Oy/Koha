#!/usr/bin/perl

# Copyright 2018 Koha Development team
#
# This file is part of Koha
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

use Test::More tests => 3;
use Test::Exception;

use Koha::Checkouts;
use Koha::CirculationRules;
use Koha::Database;

use t::lib::TestBuilder;

my $schema = Koha::Database->new->schema;
my $builder = t::lib::TestBuilder->new;

subtest 'set_rule + get_effective_rule' => sub {
    plan tests => 8;

    $schema->storage->txn_begin;

    my $checkout_type = $Koha::Checkouts::type->{checkout};
    my $categorycode = $builder->build_object( { class => 'Koha::Patron::Categories' } )->categorycode;
    my $itemtype     = $builder->build_object( { class => 'Koha::ItemTypes' } )->itemtype;
    my $branchcode   = $builder->build_object( { class => 'Koha::Libraries' } )->branchcode;
    my $branchcode_2 = $builder->build_object( { class => 'Koha::Libraries' } )->branchcode;
    my $rule_name    = 'maxissueqty';
    my $default_rule_value = 1;

    my $rule;
    Koha::CirculationRules->delete;

    throws_ok { Koha::CirculationRules->get_effective_rule }
    'Koha::Exceptions::MissingParameter',
    "Exception should be raised if get_effective_rule is called without rule_name parameter";

    $rule = Koha::CirculationRules->get_effective_rule(
        {
            branchcode   => $branchcode,
            categorycode => $categorycode,
            itemtype     => $itemtype,
            checkout_type => $checkout_type,
            rule_name    => $rule_name,
        }
    );
    is( $rule, undef, 'Undef should be returned if no rule exist' );

    Koha::CirculationRules->set_rule(
        {
            branchcode   => '*',
            categorycode => '*',
            itemtype     => '*',
            checkout_type => '*',
            rule_name    => $rule_name,
            rule_value   => $default_rule_value,
        }
    );

    $rule = Koha::CirculationRules->get_effective_rule(
        {
            branchcode   => undef,
            categorycode => undef,
            itemtype     => undef,
            checkout_type => undef,
            rule_name    => $rule_name,
        }
    );
    is( $rule->rule_value, $default_rule_value, 'undef means default' );
    $rule = Koha::CirculationRules->get_effective_rule(
        {
            branchcode   => '*',
            categorycode => '*',
            itemtype     => '*',
            checkout_type => '*',
            rule_name    => $rule_name,
        }
    );

    is( $rule->rule_value, $default_rule_value, '* means default' );

    $rule = Koha::CirculationRules->get_effective_rule(
        {
            branchcode   => $branchcode_2,
            categorycode => '*',
            itemtype     => '*',
            checkout_type => '*',
            rule_name    => $rule_name,
        }
    );
    is( $rule->rule_value, 1,
        'Default rule is returned if there is no rule for this branchcode' );

    subtest 'test rule matching with different combinations of rule scopes' => sub {

        my ( $tests, $order ) = prepare_tests_for_rule_scope_combinations( {
            branchcode => $branchcode,
            categorycode => $categorycode,
            itemtype => $itemtype,
            checkout_type => $checkout_type,
        }, 'maxissueqty' );

        plan tests => 2**scalar @$order;

        foreach my $test ( @$tests ) {
            my $rule_params = { %$test };
            $rule_params->{rule_name} = $rule_name;
            my $rule_value = $rule_params->{rule_value} = int( rand( 10 ) );

            Koha::CirculationRules->set_rule( $rule_params );

            my $rule = Koha::CirculationRules->get_effective_rule( $rule_params );

            my $scope_output = '';
            foreach my $key ( values @$order ) {
                $scope_output .= " $key" if $test->{$key} ne '*';
            }

            is( $rule->rule_value, $rule_value,
                'Explicitly scoped' . ( $scope_output
                                       ? $scope_output : ' nothing' ) );
        }
    };

    my $our_branch_rules = Koha::CirculationRules->search({branchcode => $branchcode});
    is( $our_branch_rules->count, 8, "We added 16 rules");
    $our_branch_rules->delete;
    is( $our_branch_rules->count, 0, "We deleted 16 rules");

    $schema->storage->txn_rollback;
};

subtest 'get_onshelfholds_policy() tests' => sub {

    plan tests => 2;

    $schema->storage->txn_begin;

    my $item = $builder->build_sample_item();

    my $circ_rules = Koha::CirculationRules->new;
    # Cleanup
    $circ_rules->search({ rule_name => 'onshelfholds' })->delete;

    $circ_rules->set_rule(
        {
            branchcode   => '*',
            categorycode => '*',
            itemtype     => '*',
            rule_name    => 'onshelfholds',
            rule_value   => 1,
        }
    );

    is( $circ_rules->get_onshelfholds_policy({ item => $item }), 1, 'If rule_value is set on a matching rule, return it' );
    # Delete the rule (i.e. get_effective_rule returns undef)
    $circ_rules->delete;
    is( $circ_rules->get_onshelfholds_policy({ item => $item }), 0, 'If no matching rule, fallback to 0' );

    $schema->storage->txn_rollback;
};

subtest 'set_rules() tests' => sub {
    plan tests => 1;

    subtest 'scope validation' => sub {
        plan tests => 7;

        $schema->storage->txn_begin;

        my $categorycode = $builder->build_object( {
            class => 'Koha::Patron::Categories' } )->categorycode;
        my $itemtype     = $builder->build_object( {
            class => 'Koha::ItemTypes' } )->itemtype;
        my $branchcode   = $builder->build_object( {
            class => 'Koha::Libraries' } )->branchcode;
        my $checkout_type = $Koha::Checkouts::type->{checkout};

        my $rule;
        Koha::CirculationRules->delete;

        is( scalar @{Koha::CirculationRules->set_rules( {
            branchcode   => $branchcode,
            categorycode => $categorycode,
            itemtype     => $itemtype,
            checkout_type => $checkout_type,
            rules        => {
                refund              => 1,
                max_holds           => 9001,
                patron_maxissueqty  => 2,
                holdallowed         => 3,
                article_requests    => 4,
                maxissueqty         => 5,
            }
        } )}, 6, 'All rules added' );

        is( Koha::CirculationRules->get_effective_rule( {
            branchcode      => $branchcode,
            rule_name       => 'refund'
        } )->rule_value, 1, 'Found rule refund' );

        is( Koha::CirculationRules->get_effective_rule( {
            branchcode      => $branchcode,
            categorycode    => $categorycode,
            checkout_type   => $checkout_type,
            rule_name       => 'max_holds'
        } )->rule_value, 9001, 'Found rule patron_maxissueqty' );

        is( Koha::CirculationRules->get_effective_rule( {
            branchcode      => $branchcode,
            categorycode    => $categorycode,
            checkout_type   => $checkout_type,
            rule_name       => 'patron_maxissueqty'
        } )->rule_value, 2, 'Found rule patron_maxissueqty' );

        is( Koha::CirculationRules->get_effective_rule( {
            branchcode      => $branchcode,
            itemtype        => $itemtype,
            rule_name       => 'holdallowed'
        } )->rule_value, 3, 'Found rule holdallowed' );

        is( Koha::CirculationRules->get_effective_rule( {
            branchcode      => $branchcode,
            categorycode    => $categorycode,
            itemtype        => $itemtype,
            rule_name       => 'article_requests'
        } )->rule_value, 4, 'Found rule article_requests' );

        is( Koha::CirculationRules->get_effective_rule( {
            branchcode      => $branchcode,
            categorycode    => $categorycode,
            itemtype        => $itemtype,
            checkout_type   => $checkout_type,
            rule_name       => 'maxissueqty'
        } )->rule_value, 5, 'Found rule maxissueqty' );

        $schema->storage->txn_rollback;
    };
};

sub prepare_tests_for_rule_scope_combinations {
    my ( $scope, $rule_name ) = @_;

    # Here we create a combinations of 1s and 0s the following way
    #
    # 000...
    # 001...
    # 010...
    # 011...
    # 100...
    # 101...
    # 110...
    # 111...
    #
    # (the number of columns equals to the amount of rule scopes)
    # The ... symbolizes possible future scopes.
    #
    # - 0 equals to circulation rule scope with any value (aka. *)
    # - 1 equals to circulation rule scope exact value, e.g.
    #     "CPL" (for branchcode).
    #
    # The order is the same as the weight of scopes when sorting circulation
    # rules. So the first column of numbers is the scope with most weight.
    # This is defined by C<$order> which will be assigned next.
    #
    # We must maintain the order in order to keep the test valid. This should be
    # equal to Koha/CirculationRules.pm "order_by" of C<get_effective_rule> sub.
    # Let's explicitly define the order and fail test if we are missing a scope:
    my $order = [ 'branchcode', 'categorycode', 'itemtype', 'checkout_type' ];
    is( join(", ", sort keys %$scope),
       join(", ", sort @$order), 'Missing a scope!' ) if keys %$scope ne scalar @$order;

    my @tests = ();
    foreach my $value ( glob( "{0,1}" x keys %$scope || 1 ) ) {
        my $test = { %$scope };
        for ( my $i=0; $i < keys %$scope; $i++ ) {
            $test->{$order->[$i]} = '*' unless substr( $value, $i, 1 );
        }
        push @tests, $test;
    }

    return \@tests, $order;
}
