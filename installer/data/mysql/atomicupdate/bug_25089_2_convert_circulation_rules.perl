$DBversion = 'XXX'; # will be replaced by the RM
if( CheckVersion( $DBversion ) ) {

    # First, convert maxonsiteissueqty to maxissueqty
    my $update_sth = $dbh->prepare(q|
        UPDATE circulation_rules
        SET checkout_type = ?,
            rule_name = ?
        WHERE rule_name=?
    |);
    $update_sth->execute(
        'ONSITE',                       # checkout_type => 'ONSITE' (on-site checkout)
        'maxissueqty',
        'maxonsiteissueqty'
    );

    # Then, convert patron_maxonsiteissueqty to patron_maxissueqty
    $update_sth = $dbh->prepare(q|
        UPDATE circulation_rules
        SET checkout_type = ?,
            rule_name = ?
        WHERE rule_name=?
    |);
    $update_sth->execute(
        'ONSITE',                       # checkout_type => 'ONSITE' (on-site checkout)
        'patron_maxissueqty',
        'patron_maxonsiteissueqty'
    );

    # Always end with this (adjust the bug info)
    SetVersion( $DBversion );
    print "Upgrade to $DBversion done (Bug 25089 - Convert maxonsiteissueqty to maxissueqty )\n";
}
