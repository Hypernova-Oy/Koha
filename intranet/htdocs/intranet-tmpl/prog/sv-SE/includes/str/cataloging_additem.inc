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
    var LABEL_EDIT_ITEM = _("Redigera exemplar");
    var LABEL_DELETE_ITEM = _("Ta bort exemplar");
    var MSG_FORM_NOT_SUBMITTED = _("Formuläret kunde inte skickas på grund av följande problem");
    var MSG_MANDATORY_FIELDS_EMPTY = _("%s obligatoriska fält är tomma (markerade)");
    var MSG_IMPORTANT_FIELDS_EMPTY = _("%s obligatoriska fält är tomma (markerade)");
    var MSG_ADD_MULTIPLE_ITEMS = _("Du kommer att lägga till %s exemplar. Fortsätta?");
    var MSG_ENTER_NUM_ITEMS = _("Ange antalet exemplar som ska skapas.");
    var MSG_CONFIRM_DELETE_ITEM = _("Är du säker på att du vill ta bort exemplaret?");
    var MSG_CONFIRM_ADD_ITEM = _("Är du säker på att du vill lägga till ett nytt exemplar? Eventuella ändringar på denna sida kommer att försvinna.");
    var MSG_CONFIRM_SAVE = _("Är du säker på att du vill spara?");
    var table_settings = [% TablesSettings.GetTableSettings( 'cataloguing', 'additem', 'itemst', 'json' ) | $raw %];
</script>
<!-- / str/cataloging_additem.inc -->
