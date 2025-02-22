use Modern::Perl;
use Koha::Installer::Output qw(say_warning say_success say_info);

return {
    bug_number  => "34355",
    description => "Add a table to allow creation of MARC order accounts and a system preference to activate it",
    up          => sub {
        my ($args) = @_;
        my ( $dbh, $out ) = @$args{qw(dbh out)};

        unless ( TableExists('marc_order_accounts') ) {
            $dbh->do(
                q{
                CREATE TABLE `marc_order_accounts` (
                `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'unique identifier and primary key',
                `description` varchar(250) NOT NULL COMMENT 'description of this account',
                `vendor_id` int(11) DEFAULT NULL COMMENT 'vendor id for this account',
                `budget_id` int(11) DEFAULT NULL COMMENT 'budget id for this account',
                `download_directory` mediumtext DEFAULT NULL COMMENT 'download directory for this account',
                `matcher_id` int(11) DEFAULT NULL COMMENT 'the id of the match rule used (matchpoints.matcher_id)',
                `overlay_action` varchar(50) DEFAULT NULL COMMENT 'how to handle duplicate records',
                `nomatch_action` varchar(50) DEFAULT NULL COMMENT 'how to handle records where no match is found',
                `item_action` varchar(50) DEFAULT NULL COMMENT 'what to do with item records',
                `parse_items` tinyint(1) DEFAULT NULL COMMENT 'should items be parsed',
                `record_type` varchar(50) DEFAULT NULL COMMENT 'type of record in the file',
                `encoding` varchar(50) DEFAULT NULL COMMENT 'file encoding',
                `match_field` varchar(10) DEFAULT NULL COMMENT 'the field that a vendor account has been mapped to in a marc record',
                `match_value` varchar(50) DEFAULT NULL COMMENT 'the value to be matched against the marc record',
                PRIMARY KEY (`id`),
                CONSTRAINT `marc_ordering_account_ibfk_1` FOREIGN KEY (`vendor_id`) REFERENCES `aqbooksellers` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
                CONSTRAINT `marc_ordering_account_ibfk_2` FOREIGN KEY (`budget_id`) REFERENCES `aqbudgets` (`budget_id`) ON DELETE CASCADE ON UPDATE CASCADE
                ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
            }
            );

            say_success( $out, "Added new table 'marc_order_accounts'" );
        } else {
            say_info( $out, "Table 'marc_order_accounts' already exists" );
        }

        $dbh->do(
            q{
            INSERT IGNORE INTO systempreferences (variable, value, options, explanation, type) VALUES ('MarcOrderingAutomation', '0', 'NULL', 'Enables automatic order line creation from MARC records', 'YesNo');
            }

        );
        say_success( $out, "Added new system preference 'MarcOrderingAutomation'" );

        $dbh->do(
            q{
                INSERT IGNORE INTO permissions (module_bit, code, description) values (11, 'marc_order_manage', 'Manage MARC ordering');
                }
        );
        say_success( $out, "Added new permission 'marc_order_manage'" );

    },
};
