=head IN THIS FILE

This module extends the SMS::Send::Driver interface
to implement a driver compatible with the BudgetSMS Gateway HTTP interface.

Module parameters are sanitated against injection attacks.

=cut

package SMS::Send::BudgetSMS::Driver;

use Modern::Perl;
use SMS::Send::Driver ();
use LWP::Curl;
use LWP::UserAgent;
use URI::Escape;
use C4::Context;
use Encode;
use Koha::Exception::ConnectionFailed;
use Koha::Exception::SMSDeliveryFailure;
use Koha::Hdiacritic;
use Koha::Notice::Messages;

use Try::Tiny;

use vars qw{$VERSION @ISA};
BEGIN {
        $VERSION = '0.01';
                @ISA     = 'SMS::Send::Driver';
}


#####################################################################
# Constructor

sub new {
    my $class = shift;
    my $params = {@_};
    my $from = $params->{_from};
    my $dbh=C4::Context->dbh;
    my $branches=$dbh->prepare("SELECT branchcode FROM branches WHERE branchemail = ?;");
    $branches->execute($from);
    my $branch = $branches->fetchrow || '';
    my $prefix = substr($branch, 0, 3);
    my $group_branch = C4::Context->config('smsProviders')->{'BudgetSMS'}->{$prefix}->{'username'};
    my $single_branch = C4::Context->config('smsProviders')->{'BudgetSMS'}->{$branch}->{'username'};

    my $username;
    my $userid;
    my $password;

    if($single_branch) {
        $username = $params->{_login} ? $params->{_login} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{$branch}->{'username'};
        $userid = $params->{_userid} ? $params->{_userid} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{$branch}->{'userid'};
        $password = $params->{_password} ? $params->{_password} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{$branch}->{'handle'};
    }elsif($group_branch) {
        $username = $params->{_login} ? $params->{_login} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{$prefix}->{'username'};
        $userid = $params->{_userid} ? $params->{_userid} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{$prefix}->{'userid'};
        $password = $params->{_password} ? $params->{_password} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{$prefix}->{'handle'};
    }else{
        $username = $params->{_login} ? $params->{_login} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{'username'};
        $userid = $params->{_userid} ? $params->{_userid} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{'userid'};
        $password = $params->{_password} ? $params->{_password} : C4::Context->config('smsProviders')->{'BudgetSMS'}->{'handle'};
    }


    if (! defined $username ) {
        warn "->send_sms(_login) must be defined!";
        return;
    }
    if (! defined $userid ) {
        warn "->send_sms(_userid) must be defined!";
        return;
    }
    if (! defined $password ) {
        warn "->send_sms(_password) must be defined!";
        return;
    }

    # Create the object
    my $self = bless {}, $class;

    $self->{UserAgent} = LWP::UserAgent->new(timeout => 5);
    $self->{_login} = $username;
    $self->{_userid} = $userid;
    $self->{_password} = $password;

    return $self;
}

sub send_sms {
    my $self    = shift;
    my $params = {@_};
    my $message = $params->{text};
    my $recipientNumber = $params->{to};

    if (! defined $message ) {
        warn "->send_sms(text) must be defined!";
        return;
    }
    if (! defined $recipientNumber ) {
        warn "->send_sms(to) must be defined!";
        return;
    }

    #Prevent injection attack!
    $recipientNumber =~ s/'//g;
    $message =~ s/(")|(\$\()|(`)/\\"/g; #Sanitate " so it won't break the system( iconv'ed curl command )

    my $base_url = "https://api.budgetsms.net/testsms/";
    my $parameters = {
        'username'  => $self->{_login},
        'userid'    => $self->{_userid},
        'handle'    => $self->{_password},
        'msg'       => $message,
        'to'        => $recipientNumber,
    };

    if (C4::Context->config('smsProviders')->{'BudgetSMS'}->{'sourceName'}) {
        $parameters->{'from'} = C4::Context->config('smsProviders')->{'BudgetSMS'}->{'sourceName'};
    }

    my $lwpcurl = LWP::Curl->new();
    my $return;
    try {
        $return = $lwpcurl->post($base_url, $parameters);
    } catch {
        if ($_ =~ /Couldn't resolve host name \(6\)/) {
            Koha::Exception::ConnectionFailed->throw(error => "Connection failed");
        }
        die $_;
    };

    warn $return;

    if (defined $lwpcurl->{retcode} && $lwpcurl->{retcode} == 6) {
        Koha::Exception::ConnectionFailed->throw(error => "Connection failed");
    }

    my $delivery_note = $return;

    return 1 if ($return =~ m/^OK \d*$/);

    # remove everything except the delivery note
    $delivery_note =~ s/ERR //g;

    # pass on the error by throwing an exception - it will be eventually caught
    # in C4::Letters::_send_message_by_sms()
    Koha::Exception::SMSDeliveryFailure->throw(error => $delivery_note);
}

1;
