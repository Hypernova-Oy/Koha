use Modern::Perl;
use Koha::Installer::Output qw(say_warning say_success say_info);

return {
    bug_number  => "38522",
    description => "increase erm_agreements.license_info length",
    up          => sub {
        my ($args) = @_;
        my ( $dbh, $out ) = @$args{qw(dbh out)};

        # Do you stuffs here
        $dbh->do(q{ALTER TABLE erm_agreements MODIFY COLUMN license_info mediumtext});

        # Print useful stuff here
        # tables
        say $out "Set erm_agreements.license_info to type mediumtext.";
    },
};
