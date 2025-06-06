#!/usr/bin/perl
#
# This Koha test module is a stub!
# Add more tests here!!!

use strict;
use warnings;

use Test::NoWarnings;
use Test::More tests => 7;

BEGIN {
    use_ok( 'C4::Scheduler', qw( get_jobs get_at_jobs get_at_job add_at_job remove_at_job ) );
}

ok( C4::Scheduler::get_jobs(),    "testing get_jobs with no arguments" );
ok( C4::Scheduler::get_at_jobs(), "testing get_at_jobs with no arguments" );
is( C4::Scheduler::get_at_job(),    "0",   "testing get_at_job returns '0' when given no arguments" );
is( C4::Scheduler::add_at_job(),    "",    "testing add_at_job with no arguments" );
is( C4::Scheduler::remove_at_job(), undef, "testing remove_at_job returns undef when given no arguments" );
