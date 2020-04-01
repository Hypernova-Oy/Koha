$DBversion = 'XXX'; # will be replaced by the RM
if( CheckVersion( $DBversion ) ) {

    # ISSUES
    # Convert issues.onsite_checkout to checkout_type => 'CHECKOUT' / 'ONSITE'
    if ( ! column_exists( 'issues', 'checkout_type' ) ) {
        $dbh->do( q|
            ALTER TABLE issues ADD COLUMN checkout_type ENUM('CHECKOUT', 'ONSITE') NOT NULL DEFAULT 'CHECKOUT' AFTER onsite_checkout;
        | );
    }
    if ( column_exists( 'issues', 'onsite_checkout' ) && column_exists( 'issues', 'checkout_type' ) ) {
        $dbh->do( q|
            UPDATE issues SET checkout_type='CHECKOUT' WHERE onsite_checkout<>1;
        | );
        $dbh->do( q|
            UPDATE issues SET checkout_type='ONSITE' WHERE onsite_checkout=1;
        | );
    }
    if ( column_exists( 'issues', 'onsite_checkout' ) ) {
        $dbh->do( q|
            ALTER TABLE issues DROP COLUMN onsite_checkout;
        | );
    }

    # OLD_ISSUES
    # Convert old_issues.onsite_checkout to checkout_type => 'CHECKOUT' / 'ONSITE'
    if ( ! column_exists( 'old_issues', 'checkout_type' ) ) {
        $dbh->do( q|
            ALTER TABLE old_issues ADD COLUMN checkout_type ENUM('CHECKOUT', 'ONSITE') NOT NULL DEFAULT 'CHECKOUT' AFTER onsite_checkout;
        | );
    }
    if ( column_exists( 'old_issues', 'onsite_checkout' ) && column_exists( 'old_issues', 'checkout_type' ) ) {
        $dbh->do( q|
            UPDATE old_issues SET checkout_type='CHECKOUT' WHERE onsite_checkout<>1;
        | );
        $dbh->do( q|
            UPDATE old_issues SET checkout_type='ONSITE' WHERE onsite_checkout=1;
        | );
    }
    if ( column_exists( 'old_issues', 'onsite_checkout' ) ) {
        $dbh->do( q|
            ALTER TABLE old_issues DROP COLUMN onsite_checkout;
        | );
    }

    # Always end with this (adjust the bug info)
    SetVersion( $DBversion );
    print "Upgrade to $DBversion done (Bug 25037 - Convert issues.onsite_checkout to issues.checkout_type column)\n";
}
