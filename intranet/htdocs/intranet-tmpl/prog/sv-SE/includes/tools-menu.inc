[% USE Koha %]
[% USE Branches %]
[% USE Registers %]

<div id="navmenu">
 <div id="navmenulist">
 <ul>
 <li><a href="/cgi-bin/koha/tools/tools-home.pl">Verktyg hem</a></li>
 </ul>
 [% IF ( CAN_user_tools_manage_patron_lists || CAN_user_clubs || CAN_user_tools_moderate_comments || CAN_user_tools_import_patrons  || CAN_user_tools_edit_notices || CAN_user_tools_edit_notice_status_triggers || CAN_user_tools_label_creator || CAN_user_tools_delete_anonymize_patrons  || CAN_user_tools_edit_patrons || CAN_user_tools_moderate_tags || ( CAN_user_tools_batch_upload_patron_images && Koha.Preference('patronimages') ) || CAN_user_tools_rotating_collections ) %]
 <h5>Låntagare och cirkulation</h5>
 <ul>
 [% IF ( CAN_user_tools_manage_patron_lists ) %]
 <li><a href="/cgi-bin/koha/patron_lists/lists.pl">Låntagarlistor</a></li>
 [% END %]
 [% IF (CAN_user_clubs) %]
 <li><a href="/cgi-bin/koha/clubs/clubs.pl">Låntagarklubbar</a></li>
 [% END %]
 [% IF ( CAN_user_tools_moderate_comments ) %]
 <li><a href="/cgi-bin/koha/reviews/reviewswaiting.pl">Kommentarer</a></li>
 [% END %]
 [% IF ( CAN_user_tools_import_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/import_borrowers.pl">Importera låntagare</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_notices ) %]
 <li><a href="/cgi-bin/koha/tools/letter.pl">Meddelanden och kvitton</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_notice_status_triggers ) %]
 <li><a href="/cgi-bin/koha/tools/overduerules.pl">Inställningar för förseningsmeddelande/status</a></li>
 [% END %]
 [% IF ( CAN_user_tools_label_creator ) %]
 <li><a href="/cgi-bin/koha/patroncards/home.pl">Lånekortsverktyg</a></li>
 [% END %]
 [% IF ( CAN_user_tools_delete_anonymize_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/cleanborrowers.pl">Satsvis borttagning/anonymisering av låntagare</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/modborrowers.pl">Satsvis redigering av låntagare</a></li>
 [% END %]
 [% IF ( CAN_user_tools_batch_extend_due_dates ) %]
 <li><a href="/cgi-bin/koha/tools/batch_extend_due_dates.pl">Förläng återlämningsdatum satsvis</a></li>
 [% END %]
 [% IF ( CAN_user_tools_moderate_tags ) %]
 <li><a href="/cgi-bin/koha/tags/review.pl">Taggar</a></li>
 [% END %]
 [% IF ( CAN_user_tools_batch_upload_patron_images && Koha.Preference('patronimages') ) %]
 <li><a href="/cgi-bin/koha/tools/picture-upload.pl">Ladda upp låntagarbilder</a></li>
 [% END %]
 [% IF ( CAN_user_tools_rotating_collections ) %]
 <li><a href="/cgi-bin/koha/rotating_collections/rotatingCollections.pl">Roterande samlingar</a></li>
 [% END %]
 </ul>
 [% END # /IF ( CAN_user_tools_items_batchdel... %]

 [% IF ( CAN_user_tools_edit_calendar || CAN_user_tools_manage_csv_profiles || CAN_user_tools_view_system_logs || CAN_user_tools_edit_additional_contents  || CAN_user_tools_schedule_tasks || CAN_user_tools_edit_quotes || ( Koha.ArePluginsEnabled() && CAN_user_plugins_tool )  || CAN_user_tools_upload_general_files || CAN_user_tools_access_files ) %]
 <h5>Fler verktyg</h5>
 <ul>
 [% IF ( CAN_user_tools_edit_calendar ) %]
 <li><a href="/cgi-bin/koha/tools/holidays.pl">Kalender</a></li>
 [% END %]
 [% IF ( CAN_user_tools_manage_csv_profiles ) %]
 <li><a href="/cgi-bin/koha/tools/csv-profiles.pl">CSV-profiler</a></li>
 [% END %]
 [% IF ( CAN_user_tools_view_system_logs ) %]
 <li><a href="/cgi-bin/koha/tools/viewlog.pl">Loggranskning</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_additional_contents ) %]
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=news">Nyheter</a></li>
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=html_customizations">HTML-anpassningar</a></li>
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=pages">Sidor</a></li>
 [% END %]
 [% IF ( CAN_user_tools_schedule_tasks ) %]
 <li><a href="/cgi-bin/koha/tools/scheduler.pl">Schemaläggare</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_quotes ) %]
 <li><a href="/cgi-bin/koha/tools/quotes.pl">Citatredigerare</a></li>
 [% END %]
 [% IF ( plugins_enabled && CAN_user_plugins_tool ) %]
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl?method=tool">Verktygspluginer</a></li>
 [% END %]
 [% IF ( CAN_user_tools_upload_general_files ) %]
 <li><a href="/cgi-bin/koha/tools/upload.pl">Uppladdningar</a></li>
 [% END %]
 [% IF ( CAN_user_tools_access_files ) %]
 <li><a href="/cgi-bin/koha/tools/access_files.pl">Kom åt filer</a></li>
 [% END %]
 [% IF ( Koha.Preference('OPACReportProblem') && CAN_user_problem_reports ) %]
 <li><a href="/cgi-bin/koha/tools/problem-reports.pl">OPAC-problemrapport</a></li>
 [% END %]
 </ul>
 [% END # /IF ( CAN_user_tools_edit_calendar... %]
 [% IF ( Koha.Preference('UseCashRegisters') && ( CAN_user_cash_management_cashup || CAN_user_cash_management_anonymous_refund ) ) %]
 <h5>Kontanthantering</h5>
 <ul>
 <li><a href="/cgi-bin/koha/pos/registers.pl">Kontantöversikt för [% Branches.GetLoggedInBranchname | html %]</a></li>
 <li><a href="/cgi-bin/koha/pos/register.pl">Transaktionshistorik för [% Registers.session_register_name | html %]</a></li>
 </ul>
 [% END %]
 </div> <!-- /#navmenulist -->
</div> <!-- /#navmenu -->
