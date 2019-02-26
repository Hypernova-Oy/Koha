$DBversion = 'XXX';
if( CheckVersion( $DBversion ) ) {
    $dbh->do( "INSERT INTO systempreferences " .
     " (variable, value, options, explanation, type) VALUES ".
     " ('HypernovaKohaHostingPriceFormula','','','','Free')" );

    SetVersion( $DBversion );
    print "Upgrade to $DBversion done (HD-1 - Create a hosting offer form - " .
          "Add system preference HypernovaKohaHostingPriceFormula)\n";
}
