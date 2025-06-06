package C4::InstallAuth;

# Copyright 2000-2002 Katipo Communications
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
use CGI::Session;
use File::Spec;

require Exporter;

use C4::Context;
use C4::Output qw( output_html_with_http_headers );
use C4::Templates;

use Koha::Session;

our ( @ISA, @EXPORT_OK );

BEGIN {
    @ISA       = qw(Exporter);
    @EXPORT_OK = qw(
        checkauth
        get_template_and_user
    );
}

=head1 NAME

InstallAuth - Authenticates Koha users for Install process

=head1 SYNOPSIS

  use CGI qw ( -utf8 );
  use InstallAuth;
  use C4::Output;

  my $query = new CGI;

    my ( $template, $borrowernumber, $cookie ) = get_template_and_user(
        {   template_name   => "opac-main.tt",
            query           => $query,
            type            => "opac",
            authnotrequired => 1,
            flagsrequired   => { acquisition => '*' },
        }
    );

  output_html_with_http_headers $query, $cookie, $template->output;

=head1 DESCRIPTION

The main function of this module is to provide
authentication. However the get_template_and_user function has
been provided so that a users login information is passed along
automatically. This gets loaded into the template.
This package is different from C4::Auth in so far as
C4::Auth uses many preferences which are supposed NOT to be obtainable when installing the database.

As in C4::Auth, Authentication is based on cookies.

=head1 FUNCTIONS

=head2 get_template_and_user

    my ( $template, $borrowernumber, $cookie ) = get_template_and_user(
        {   template_name   => "opac-main.tt",
            query           => $query,
            type            => "opac",
            authnotrequired => 1,
            flagsrequired   => { acquisition => '*' },
        }
    );

This call passes the C<query>, C<flagsrequired> and C<authnotrequired>
to C<&checkauth> (in this module) to perform authentication.
See C<&checkauth> for an explanation of these parameters.

The C<template_name> is then used to find the correct template for
the page. The authenticated users details are loaded onto the
template in the logged_in_user variable (which is a Koha::Patron object). Also the
C<sessionID> is passed to the template. This can be used in templates
if cookies are disabled. It needs to be put as and input to every
authenticated page.

More information on the C<gettemplate> sub can be found in the
Templates.pm module.

=cut

sub get_template_and_user {
    my $in       = shift;
    my $query    = $in->{'query'};
    my $language = _get_template_language( $query->cookie('KohaOpacLanguage') );
    my $path     = C4::Context->config('intrahtdocs') . "/prog/" . $language;

    my $tmplbase  = $in->{template_name};
    my $filename  = "$path/modules/" . $tmplbase;
    my $interface = 'intranet';
    my $template  = C4::Templates->new( $interface, $filename, $tmplbase, $query );

    my $request_method = $in->{query}->request_method // q{};
    unless ( $request_method eq 'POST' && $in->{query}->param('op') eq 'cud-login' ) {
        $in->{query}->param( 'login_userid',   '' );
        $in->{query}->param( 'login_password', '' );
    }

    my ( $user, $cookie, $sessionID, $flags ) = checkauth(
        $in->{'query'},
        $in->{'authnotrequired'},
        $in->{'flagsrequired'},
        $in->{'type'}
    );

    my $session = Koha::Session->get_session( { sessionID => $sessionID, storage_method => 'file' } );

    my $borrowernumber;
    if ($user) {
        $template->param( loggedinusername => $user );
        $template->param( sessionID        => $sessionID );

        # We are going to use the $flags returned by checkauth
        # to create the template's parameters that will indicate
        # which menus the user can access.
        if ( ( $flags && $flags->{superlibrarian} == 1 ) ) {
            $template->param( CAN_user_circulate        => 1 );
            $template->param( CAN_user_catalogue        => 1 );
            $template->param( CAN_user_parameters       => 1 );
            $template->param( CAN_user_borrowers        => 1 );
            $template->param( CAN_user_permission       => 1 );
            $template->param( CAN_user_reserveforothers => 1 );
            $template->param( CAN_user_editcatalogue    => 1 );
            $template->param( CAN_user_updatecharges    => 1 );
            $template->param( CAN_user_acquisition      => 1 );
            $template->param( CAN_user_tools            => 1 );
            $template->param( CAN_user_editauthorities  => 1 );
            $template->param( CAN_user_serials          => 1 );
            $template->param( CAN_user_reports          => 1 );
            $template->param( CAN_user_problem_reports  => 1 );
            $template->param( CAN_user_recalls          => 1 );
        }

        my $minPasswordLength = C4::Context->preference('minPasswordLength');
        $minPasswordLength = 3 if not $minPasswordLength or $minPasswordLength < 3;
        $template->param( minPasswordLength => $minPasswordLength, );
    }
    return ( $template, $borrowernumber, $cookie );
}

sub _get_template_language {

    #verify if opac language exists in staff (bug 5660)
    #conditions are 1) dir exists and 2) enabled in prefs
    my ($opaclang) = @_;
    return 'en' unless $opaclang;
    $opaclang =~ s/[^a-zA-Z_-]*//g;
    my $path = C4::Context->config('intrahtdocs') . "/prog/$opaclang";
    -d $path ? $opaclang : 'en';
}

=head2 checkauth

  ($userid, $cookie, $sessionID) = &checkauth($query, $noauth, $flagsrequired, $type);

Verifies that the user is authorized to run this script.  If
the user is authorized, a (userid, cookie, session-id, flags)
quadruple is returned.  If the user is not authorized but does
not have the required privilege (see $flagsrequired below), it
displays an error page and exits.  Otherwise, it displays the
login page and exits.

Note that C<&checkauth> will return if and only if the user
is authorized, so it should be called early on, before any
unfinished operations (e.g., if you've opened a file, then
C<&checkauth> won't close it for you).

C<$query> is the CGI object for the script calling C<&checkauth>.

The C<$noauth> argument is optional. If it is set, then no
authorization is required for the script.

C<&checkauth> fetches user and session information from C<$query> and
ensures that the user is authorized to run scripts that require
authorization.

The C<$flagsrequired> argument specifies the required privileges
the user must have if the username and password are correct.
It should be specified as a reference-to-hash; keys in the hash
should be the "flags" for the user, as specified in the Members
intranet module. Any key specified must correspond to a "flag"
in the userflags table. E.g., { circulate => 1 } would specify
that the user must have the "circulate" privilege in order to
proceed. To make sure that access control is correct, the
C<$flagsrequired> parameter must be specified correctly.

The C<$type> argument specifies whether the template should be
retrieved from the opac or intranet directory tree.  "opac" is
assumed if it is not specified; however, if C<$type> is specified,
"intranet" is assumed if it is not "opac".

If C<$query> does not have a valid session ID associated with it
(i.e., the user has not logged in) or if the session has expired,
C<&checkauth> presents the user with a login page (from the point of
view of the original script, C<&checkauth> does not return). Once the
user has authenticated, C<&checkauth> restarts the original script
(this time, C<&checkauth> returns).

The login page is provided using a HTML::Template, which is set in the
systempreferences table or at the top of this file. The variable C<$type>
selects which template to use, either the opac or the intranet 
authentication template.

C<&checkauth> returns a user ID, a cookie, and a session ID. The
cookie should be sent back to the browser; it verifies that the user
has authenticated.

=cut

sub checkauth {
    my $query = shift;

    # $authnotrequired will be set for scripts which will run without authentication
    my $authnotrequired = shift;
    my $flagsrequired   = shift;
    my $type            = shift;
    $type = 'intranet' unless $type;

    my $dbh = C4::Context->dbh();
    my $template_name;
    $template_name = "installer/auth.tt";

    # state variables
    my $loggedin = 0;
    my %info;
    my ( $userid, $cookie, $flags, $envcookie );
    my $logout = $query->param('logout.x');

    my $sessionID = $query->cookie("CGISESSID");
    my $session   = Koha::Session->get_session( { sessionID => $sessionID, storage_method => 'file' } );

    if ($session) {
        if ( $session->param('cardnumber') ) {
            C4::Context->set_userenv(
                $session->param('number'),
                $session->param('id'),
                $session->param('cardnumber'),
                $session->param('firstname'),
                $session->param('surname'),
                $session->param('branch'),
                $session->param('branchname'),
                $session->param('flags'),
                $session->param('emailaddress')
            );
            $cookie = $query->cookie(
                -name     => 'CGISESSID',
                -value    => $session->id,
                -HttpOnly => 1,
                -secure   => ( C4::Context->https_enabled() ? 1 : 0 ),
                -sameSite => 'Lax'
            );
            $loggedin = 1;
            $userid   = $session->param('cardnumber');
        }
    }

    if ( $logout || !$session ) {

        # voluntary logout the user
        C4::Context->unset_userenv();
        $session = Koha::Session->get_session( { storage_method => 'file' } );
    }

    $sessionID = $session->id;

    unless ($userid) {
        $userid = $query->param('login_userid');
        my $password = $query->param('login_password');
        my ( $return, $cardnumber ) = checkpw( $userid, $password );
        if ($return) {
            $loggedin = 1;

            # open L, ">>/tmp/sessionlog";
            # my $time = localtime( time() );
            # printf L "%20s from %16s logged in  at %30s.\n", $userid,
            #  $ENV{'REMOTE_ADDR'}, $time;
            # close L;
            $cookie = $query->cookie(
                -name     => 'CGISESSID',
                -value    => $sessionID,
                -HttpOnly => 1,
                -secure   => ( C4::Context->https_enabled() ? 1 : 0 ),
                -sameSite => 'Lax'
            );
            if ( $return == 2 ) {

                #Only superlibrarian should have access to this page.
                #Since if it is a user, it is supposed that there is a borrower table
                #And thus that data structure is loaded.
                my $hash = C4::Context->set_userenv(
                    0,                           0,
                    C4::Context->config('user'), C4::Context->config('user'),
                    C4::Context->config('user'), "",
                    "NO_LIBRARY_SET",            1,
                    ""
                );
                $session->param( 'number',     0 );
                $session->param( 'id',         C4::Context->config('user') );
                $session->param( 'cardnumber', C4::Context->config('user') );
                $session->param( 'firstname',  C4::Context->config('user') );
                $session->param( 'surname',    C4::Context->config('user'), );
                $session->param( 'branch',     'NO_LIBRARY_SET' );
                $session->param( 'branchname', 'NO_LIBRARY_SET' );
                $session->param( 'flags',      1 );
                $session->param(
                    'emailaddress',
                    C4::Context->preference('KohaAdminEmailAddress')
                );
                $session->param( 'ip',       $session->remote_addr() );
                $session->param( 'lasttime', time() );
                $userid = C4::Context->config('user');
            }
        } else {
            if ($userid) {
                $info{'invalid_username_or_password'} = 1;
                C4::Context->unset_userenv();
            }
        }
    }

    # finished authentication, now respond
    if ($loggedin) {

        # successful login
        unless ($cookie) {
            $cookie = $query->cookie(
                -name     => 'CGISESSID',
                -value    => '',
                -HttpOnly => 1,
                -expires  => '',
                -secure   => ( C4::Context->https_enabled() ? 1 : 0 ),
                -sameSite => 'Lax'
            );
        }
        if ($envcookie) {
            return ( $userid, [ $cookie, $envcookie ], $sessionID, $flags );
        } else {
            return ( $userid, $cookie, $sessionID, $flags );
        }
    }

    # else we have a problem...
    # get the inputs from the incoming query
    my @inputs = ();
    foreach my $name ( param $query) {
        (next) if ( $name eq 'userid' || $name eq 'password' );
        my $value = $query->param($name);
        push @inputs, { name => $name, value => $value };
    }

    my $path =
          C4::Context->config('intrahtdocs')
        . "/prog/"
        . ( $query->param('language') ? $query->param('language') : "en" );
    my $filename  = "$path/modules/$template_name";
    my $interface = 'intranet';
    my $template  = C4::Templates->new( $interface, $filename, '', $query );
    $template->param(
        INPUTS => \@inputs,

    );
    $template->param( login       => 1 );
    $template->param( loginprompt => 1 ) unless $info{'nopermission'};

    if ( $info{'invalid_username_or_password'} && $info{'invalid_username_or_password'} == 1 ) {
        $template->param( 'invalid_username_or_password' => $info{'invalid_username_or_password'} );
    }

    unless ($sessionID) {
        $session   = Koha::Session->get_session( { storage_method => 'file' } );
        $sessionID = $session->id;
    }
    $template->param(
        %info,
        sessionID => $sessionID,
    );
    $cookie = $query->cookie(
        -name     => 'CGISESSID',
        -value    => $sessionID,
        -HttpOnly => 1,
        -expires  => '',
        -secure   => ( C4::Context->https_enabled() ? 1 : 0 ),
        -sameSite => 'Lax'
    );
    print $query->header(
        -type   => 'text/html; charset=utf-8',
        -cookie => $cookie
        ),
        $template->output;
    exit;
}

=head2 checkpw

Missing POD for checkpw.

=cut

sub checkpw {

    my ( $userid, $password ) = @_;

    if (   $userid
        && $userid eq C4::Context->config('user')
        && "$password" eq C4::Context->config('pass') )
    {

        # Koha superuser account
        C4::Context->set_userenv(
            0, 0,
            C4::Context->config('user'),
            C4::Context->config('user'),
            C4::Context->config('user'),
            "", "NO_LIBRARY_SET", 1
        );
        return 2;
    }
    return 0;
}

END { }    # module clean-up code here (global destructor)
1;
__END__

=head1 SEE ALSO

CGI(3)

C4::Output(3)

Digest::MD5(3)

=cut
