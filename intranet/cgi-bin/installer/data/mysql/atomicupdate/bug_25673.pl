use Modern::Perl;
use Koha::Installer::Output qw(say_warning say_success say_info);

return {
    bug_number  => "25673",
    description => "Add preference BorrowersViewLog",
    up          => sub {
        my ($args) = @_;
        my ( $dbh, $out ) = @$args{qw(dbh out)};

        $dbh->do(
            q{INSERT IGNORE INTO systempreferences (variable,value,options,explanation,type) VALUES ('BorrowersViewLog','0',NULL,'If enabled, log when patron data is viewed','YesNo')}
        );

        say_success( $out, "Added new system preference 'BorrowersViewLog'" );

    },
};