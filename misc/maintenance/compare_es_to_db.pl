#!/usr/bin/perl
#
# This compares record counts from a Koha database to Elasticsearch

# Copyright 2019 ByWater Solutions
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

=head1 NAME

compare_es_to_db.pl - compares record counts from a Koha database to Elasticsearch

=head1 SYNOPSIS

B<compare_es_to_db.pl>

=cut

use Modern::Perl;

use Array::Utils qw( array_minus );
use Getopt::Long qw( GetOptions );

use C4::Context;

use Koha::Authorities;
use Koha::Biblios;
use Koha::Items;
use Koha::SearchEngine::Elasticsearch;

my $help;
my $fix;

GetOptions(
    'h|help' => \$help,
    'f|fix'  => \$fix,
);

my $usage = <<'ENDUSAGE';

This script finds differences between the records on the Koha database
and the Elasticsearch index.

The `--fix` option switch can be passed to try fixing them.

This script has the following parameters :

    -f|--fix     Try to fix errors
    -h|--help    Print this message

ENDUSAGE

if ($help) {
    print $usage;
    exit;
}

foreach my $index ( ( 'biblios', 'authorities' ) ) {
    print "=================\n";
    print "Checking $index\n";
    my @db_records =
        $index eq 'biblios'
        ? Koha::Biblios->search()->get_column('biblionumber')
        : Koha::Authorities->search()->get_column('authid');

    my $searcher = Koha::SearchEngine::Elasticsearch->new( { index => $index } );
    my $es       = $searcher->get_elasticsearch();
    my $count    = $es->indices->stats( index => $searcher->index_name )->{_all}{primaries}{docs}{count};
    print "Count in db for $index is " . scalar @db_records . ", count in Elasticsearch is $count\n";

    # Now we get all the ids from Elasticsearch
    # The scroll lets us iterate through, it fetches chunks of 'size' as we move through
    my $scroll = $es->scroll_helper(
        index   => $searcher->index_name,
        _source => 0,
        body    => {
            size  => 5000,
            query => { match_all => {} },
        },
    );

    my @es_ids;

    # Here is where we actually iterate through
    # Fetching each record, pushing the id into the array
    my $i = 1;
    print "Fetching Elasticsearch records ids";
    while ( my $doc = $scroll->next ) {
        print "."                      if !( $i % 500 );
        print "\n$i records retrieved" if !( $i % 5000 );
        push @es_ids, $doc->{_id};
        $i++;
    }

    # Fetch values for providing record links
    my $es_params  = $searcher->get_elasticsearch_params;
    my $es_base    = "$es_params->{nodes}[0]/" . $searcher->index_name;
    my $staff_base = C4::Context->preference('staffClientBaseURL');

    print "\nComparing arrays, this may take a while\n";

    my @koha_problems = sort { $a <=> $b } array_minus( @db_records, @es_ids );
    my @es_problems   = sort { $a <=> $b } array_minus( @es_ids,     @db_records );

    print "All records match\n" unless ( @koha_problems || @es_problems );

    if (@koha_problems) {
        print "=================\n";
        print "Records that exist in Koha but not in ES\n";
        for my $problem (@koha_problems) {
            if ( $index eq 'biblios' ) {
                print "  #$problem";
                print
                    "  Visit here to see record: $staff_base/cgi-bin/koha/catalogue/detail.pl?biblionumber=$problem\n";
            } elsif ( $index eq 'authorities' ) {
                print "#$problem";
                print "  Visit here to see record: $staff_base/cgi-bin/koha/authorities/detail.pl?authid=$problem\n";
            }
        }
    }

    if (@es_problems) {
        print "=================\n";
        print "Records that exist in ES but not in Koha\n";
        for my $problem (@es_problems) {
            print "  #$problem";
            print "  Enter this command to view record: curl $es_base/data/$problem?pretty=true\n";
        }
    }

    if ( $fix && ( @koha_problems || @es_problems ) ) {

        print "=================\n";
        print "Trying to fix problems:\n\n";

        my $indexer;
        my $server;
        if ( $index eq 'biblios' ) {
            $indexer = Koha::SearchEngine::Indexer->new( { index => $Koha::SearchEngine::BIBLIOS_INDEX } );
            $server  = 'biblioserver';
        } else {
            $indexer = Koha::SearchEngine::Indexer->new( { index => $Koha::SearchEngine::AUTHORITIES_INDEX } );
            $server  = 'authorityserver';
        }

        if (@koha_problems) {

            print "=================\n";
            print "Scheduling indexing of missing records ($index):\n\n";

            # index_records() takes care of splitting into chunks.
            $indexer->index_records( \@koha_problems, 'specialUpdate', $server );
        }

        if (@es_problems) {

            print "=================\n";
            print "Deleting non-existent records from the index ($index)...\n";

            $indexer->delete_index( \@es_problems );
        }
    }
}

1;
