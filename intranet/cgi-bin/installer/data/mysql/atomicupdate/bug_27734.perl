$DBversion = 'XXX';
if( CheckVersion( $DBversion ) ) {
    $dbh->do(q{
        INSERT IGNORE INTO systempreferences ( `variable`, `value`, `options`, `explanation`, `type` ) VALUES
        ('OpacHiddenRecordRedirect','0','Redirect the opac detail page for records hidden by OpacHiddenItems to an explanatory page (otherwise redirect to 404 error page)','','YesNo')
    });

    NewVersion( $DBversion, 27734, "Add OpacHiddenRecordRedirect preference");
}
