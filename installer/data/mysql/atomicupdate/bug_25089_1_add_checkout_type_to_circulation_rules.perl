$DBversion = 'XXX'; # will be replaced by the RM
if( CheckVersion( $DBversion ) ) {

    if ( ! column_exists( 'circulation_rules', 'checkout_type' ) ) {
        $dbh->do( q|
            ALTER TABLE circulation_rules ADD COLUMN checkout_type ENUM('CHECKOUT', 'ONSITE') DEFAULT NULL AFTER itemtype;
        | );

        if ( index_exists( 'circulation_rules', 'branchcode' ) ) {
            # we need to drop this forgein key before updating our unique index
            $dbh->do( "ALTER TABLE `circulation_rules` DROP FOREIGN KEY circ_rules_ibfk_1;" );
            $dbh->do( "ALTER TABLE `circulation_rules` DROP INDEX `branchcode`;" );
            $dbh->do( "ALTER TABLE `circulation_rules` ADD CONSTRAINT circ_rules_ibfk_1 FOREIGN KEY (`branchcode`) REFERENCES `branches` (`branchcode`) ON DELETE CASCADE ON UPDATE CASCADE" );
            $dbh->do( "ALTER TABLE `circulation_rules` ADD UNIQUE INDEX (`branchcode`,`categorycode`,`itemtype`,`checkout_type`,`rule_name`)" );
        }
    }

    # Always end with this (adjust the bug info)
    SetVersion( $DBversion );
    print "Upgrade to $DBversion done (Bug 25089 - Add new circulation rule scope checkout_type )\n";
}
