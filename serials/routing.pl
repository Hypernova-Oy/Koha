#!/usr/bin/perl

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

=head1 Routing.pl

script used to create a routing list for a serial subscription
In this instance it is in fact a setting up of a list of reserves for the item
where the hierarchical order can be changed on the fly and a routing list can be
printed out

=cut

use Modern::Perl;
use Try::Tiny;
use CGI qw ( -utf8 );
use C4::Koha;
use C4::Auth   qw( get_template_and_user );
use C4::Output qw( output_and_exit output_html_with_http_headers );
use C4::Context;

use C4::Serials
    qw( GetSubscription delroutingmember addroutingmember getroutinglist GetSerials GetLatestSerials check_routing );
use Koha::Patrons;

use URI::Escape;

my $query           = CGI->new;
my $subscriptionid  = $query->param('subscriptionid');
my $serialseq       = $query->param('serialseq');
my $routingid       = $query->param('routingid');
my $borrowernumbers = $query->param('borrowernumbers');
my $notes           = $query->param('notes');
my $op              = $query->param('op') || q{};
my $date_selected   = $query->param('date_selected');
$date_selected ||= q{};
my $dbh = C4::Context->dbh;

my ( $template, $loggedinuser, $cookie ) = get_template_and_user(
    {
        template_name => 'serials/routing.tt',
        query         => $query,
        type          => 'intranet',
        flagsrequired => { serials => 'routing' },
    }
);

my $subs = GetSubscription($subscriptionid);

output_and_exit( $query, $cookie, $template, 'unknown_subscription' )
    unless $subs;

if ( $op eq 'cud-delete' ) {
    delroutingmember( $routingid, $subscriptionid );
}

if ( $op eq 'cud-add_new_recipients' ) {
    for my $borrowernumber ( split ':', $borrowernumbers ) {
        try {
            addroutingmember( $borrowernumber, $subscriptionid );
        } catch {
            if ( $_ !~ m{Duplicate entry .* for key 'subscriptionid'} ) {
                warn $_;
            }
        };
    }
}
if ( $op eq 'cud-save' ) {
    my $sth = $dbh->prepare('UPDATE serial SET routingnotes = ? WHERE subscriptionid = ?');
    $sth->execute( $notes, $subscriptionid );
    my $urldate = URI::Escape::uri_escape_utf8($date_selected);
    print $query->redirect("routing-preview.pl?subscriptionid=$subscriptionid&issue=$urldate");
}

my @routinglist = getroutinglist($subscriptionid);

my ( $count, @serials ) = GetSerials($subscriptionid);
my $serialdates = GetLatestSerials( $subscriptionid, $count );

my $dates = [];
foreach my $dateseq ( @{$serialdates} ) {
    my $d = {};
    $d->{publisheddate} = $dateseq->{publisheddate};
    $d->{serialseq}     = $dateseq->{serialseq};
    $d->{serialid}      = $dateseq->{serialid};
    if ( $date_selected eq $dateseq->{serialid} ) {
        $d->{selected} = ' selected';
    } else {
        $d->{selected} = q{};
    }
    push @{$dates}, $d;
}

my $member_loop = [];
for my $routing (@routinglist) {
    my $member = Koha::Patrons->find( $routing->{borrowernumber} )->unblessed;
    $member->{location} = $member->{branchcode};
    if ( $member->{firstname} ) {
        $member->{name} = $member->{firstname} . q| |;
    } else {
        $member->{name} = q{};
    }
    if ( $member->{surname} ) {
        $member->{name} .= $member->{surname};
    }
    $member->{routingid} = $routing->{routingid} || q{};
    $member->{ranking}   = $routing->{ranking}   || q{};

    push( @{$member_loop}, $member );
}

$template->param(
    title                                            => $subs->{bibliotitle},
    subscriptionid                                   => $subscriptionid,
    memberloop                                       => $member_loop,
    op                                               => $op eq 'new',
    dates                                            => $dates,
    routingnotes                                     => $serials[0]->{'routingnotes'},
    hasRouting                                       => check_routing($subscriptionid),
    ( uc( C4::Context->preference("marcflavour") ) ) => 1

);

output_html_with_http_headers $query, $cookie, $template->output;
