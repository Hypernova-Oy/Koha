[% USE Koha %]
<div id="navmenu">
 <div id="navmenulist">

 [% IF ( CAN_user_tools_stage_marc_import || CAN_user_tools_manage_staged_marc ) %]
 <h5>Tuo</h5>
 <ul>
 [% IF ( CAN_user_tools_stage_marc_import ) %]
 <li>
 <a href="/cgi-bin/koha/tools/stage-marc-import.pl">Välivarastoitujen tietueiden hallinta</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_manage_staged_marc ) %]
 <li>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl">Hallinnoi välivarastoituja tietueita</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_export_catalog ) %]
 <h5>Vie</h5>
 <ul>
 [% IF ( CAN_user_tools_export_catalog ) %]
 <li>
 <a href="/cgi-bin/koha/tools/export.pl">Luettelon tietojen vienti</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_inventory || ( ( Koha.Preference('OpacCatalogConcerns') || Koha.Preference('CatalogConcerns') ) && CAN_user_editcatalogue_edit_catalogue ) ) %]
 <h5>Raportit</h5>
 <ul>
 [% IF ( CAN_user_tools_inventory ) %]
 <li>
 <a href="/cgi-bin/koha/tools/inventory.pl">Inventaario</a>
 </li>
 [% END %]
 [% IF ( Koha.Preference('OpacCatalogConcerns') || Koha.Preference('CatalogConcerns') ) && CAN_user_editcatalogue_edit_catalogue %]
 <li>
 <a href="/cgi-bin/koha/cataloguing/concerns.pl">Kuvailutietojen virheet</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_items_batchmod || CAN_user_tools_items_batchdel || CAN_user_tools_records_batchmod || CAN_user_tools_records_batchdel || CAN_user_tools_marc_modification_templates ) %]
 <h5>Erämuokkaukset</h5>
 <ul>
 [% IF ( CAN_user_tools_items_batchmod ) %]
 <li>
 <a href="/cgi-bin/koha/tools/batchMod.pl">Niteiden muokkaus eräajona</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_items_batchdel ) %]
 <li>
 <a href="/cgi-bin/koha/tools/batchMod.pl?del=1">Niteiden poisto eräajona</a>
 </li>
 [% END %]
 [% IF CAN_user_tools_records_batchmod %]
 <li>
 <a href="/cgi-bin/koha/tools/batch_record_modification.pl">Tietueiden muokkaus eräajona</a>
 </li>
 [% END %]
 [% IF CAN_user_tools_records_batchdel %]
 <li>
 <a href="/cgi-bin/koha/tools/batch_delete_records.pl">Tietueiden poisto eräajona</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_marc_modification_templates ) %]
 <li>
 <a href="/cgi-bin/koha/tools/marc_modification_templates.pl">MARC-muokkauksen pohjat</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_items_batchmod || ( CAN_user_stockrotation_manage_rotas && Koha.Preference('StockRotation') ) ) %]
 <h5>Automaatiot</h5>
 <ul>
 [% IF ( CAN_user_tools_items_batchmod ) %]
 <li>
 <a href="/cgi-bin/koha/tools/automatic_item_modification_by_age.pl">Niteen muokkaus iän mukaan</a>
 </li>
 [% END %]
 [% IF ( CAN_user_stockrotation_manage_rotas && Koha.Preference('StockRotation') ) %]
 <li>
 <a href="/cgi-bin/koha/tools/stockrotation.pl">Kiertokokoelma</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_label_creator || CAN_user_tools_upload_local_cover_images ) %]
 <h5>Työkalut</h5>
 <ul>
 [% IF ( CAN_user_tools_label_creator ) %]
 <li>
 <a href="/cgi-bin/koha/labels/label-home.pl">Tarrojen luonti</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/labels/barcode-print.pl">Viivakoodikuvan luonti</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/labels/spinelabel-home.pl">Selkätarrojen pikaluonti</a>
 </li>
 [% END %]

 [% IF ( CAN_user_tools_upload_local_cover_images ) %]
 <li>
 <a href="/cgi-bin/koha/tools/upload-cover-image.pl">Lataa paikallinen kansikuva</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters ) %]
 <h5>Ylläpito</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_sysprefs ) %]
 <li>
 <a class="circ-button" href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing">Asetukset</a>
 </li>
 [% END %]
 <li>
 <a class="circ-button" href="/cgi-bin/koha/admin/admin-home.pl">Ylläpito</a>
 </li>
 </ul>
 [% END %]

 </div>
</div>
