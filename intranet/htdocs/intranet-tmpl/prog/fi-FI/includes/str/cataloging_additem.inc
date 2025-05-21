[% USE raw %]
<!-- str/cataloging_additem.inc -->
<script>
    var searchid = '[% searchid | html %]';
    var biblionumber = '[% biblionumber | html %]';
    var frameworkcode = '[% frameworkcode | html %]';
    [% IF popup %]
      var popup = true;
    [% ELSE %]
      var popup = false;
    [% END %]
    var op = '[% op | html %]';
    var LABEL_EDIT_ITEM = _("Muokkaa nidettä");
    var LABEL_DELETE_ITEM = _("Poista nide");
    var MSG_FORM_NOT_SUBMITTED = _("Tietoja ei tallennettu seuraavista syistä");
    var MSG_MANDATORY_FIELDS_EMPTY = _("%s pakollista kenttää tyhjinä (korostettuna)");
    var MSG_IMPORTANT_FIELDS_EMPTY = _("%s tärkeää kenttää tyhjinä (korostettuna)");
    var MSG_ADD_MULTIPLE_ITEMS = _("Olet lisäämässä %s nidettä. Jatketaanko?");
    var MSG_ENTER_NUM_ITEMS = _("Kuinka monta nidettä luodaan.");
    var MSG_CONFIRM_DELETE_ITEM = _("Haluatko varmasti poistaa tämän niteen?");
    var MSG_CONFIRM_ADD_ITEM = _("Haluatko varmasti lisätä uuden niteen? Kaikki tälle sivulle tehdyt muutokset häviävät.");
    var MSG_CONFIRM_SAVE = _("Haluatko varmasti tallentaa?");
    var table_settings = [% TablesSettings.GetTableSettings( 'cataloguing', 'additem', 'itemst', 'json' ) | $raw %];
</script>
<!-- / str/cataloging_additem.inc -->
