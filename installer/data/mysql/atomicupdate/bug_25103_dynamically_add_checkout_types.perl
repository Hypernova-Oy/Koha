$DBversion = 'XXX'; # will be replaced by the RM
if( CheckVersion( $DBversion ) ) {

    if ($dbh->do("SELECT 1 FROM authorised_value_categories WHERE category_name='CHECKOUT_TYPE'") == 0) {
        # Add authorised value category "CHECKOUT_TYPE"
        $dbh->do( q|
            INSERT IGNORE INTO authorised_value_categories( category_name ) VALUES ('CHECKOUT_TYPE');
        | );
    }

    if ($dbh->do("SELECT 1 FROM authorised_values WHERE authorised_value='ONSITE'") == 0) {
        # Add authorised value "ONSITE" under "CHECKOUT_TYPE" category
        $dbh->do( q|
            INSERT IGNORE INTO authorised_values(category, authorised_value, lib, lib_opac) VALUES ('CHECKOUT_TYPE', 'ONSITE', 'On-site checkout', 'On-site checkout');
        | );
    }
    if ($dbh->do("SELECT 1 FROM authorised_values WHERE authorised_value='CHECKOUT'") == 0) {
        # Add authorised value "CHECKOUT" under "CHECKOUT_TYPE" category
        $dbh->do( q|
            INSERT IGNORE INTO authorised_values(category, authorised_value, lib, lib_opac) VALUES ('CHECKOUT_TYPE', 'CHECKOUT', 'Normal checkout', 'Normal checkout');
        | );
    }

    $dbh->do( q|
        ALTER TABLE issues MODIFY COLUMN checkout_type VARCHAR(80) NOT NULL DEFAULT 'CHECKOUT';
    | );

    $dbh->do( q|
        ALTER TABLE old_issues MODIFY COLUMN checkout_type VARCHAR(80) NOT NULL DEFAULT 'CHECKOUT';
    | );

    # Add a foreign key between old_issues.checkout_type and authorised_values.authorised_value
    if ( !foreign_key_exists( 'issues', 'issues_ctfk' ) ) {
        $dbh->do( "ALTER TABLE issues ADD CONSTRAINT issues_ctfk FOREIGN KEY (checkout_type) REFERENCES authorised_values(authorised_value) ON UPDATE CASCADE ON DELETE RESTRICT" );
    }

    # Add a foreign key between issues.checkout_type and authorised_values.authorised_value
    if ( !foreign_key_exists( 'old_issues', 'old_issues_ctfk' ) ) {
        $dbh->do( "ALTER TABLE old_issues ADD CONSTRAINT old_issues_ctfk FOREIGN KEY (checkout_type) REFERENCES authorised_values(authorised_value) ON UPDATE CASCADE ON DELETE RESTRICT" );
    }

    # Always end with this (adjust the bug info)
    SetVersion( $DBversion );
    print "Upgrade to $DBversion done (Bug 25103 - Dynamically add checkout types\n";
}
