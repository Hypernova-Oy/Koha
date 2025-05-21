[% USE Koha %]

<div id="navmenu">
 <div id="navmenulist">

 <h5>Rapporter med guider</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl">Rapporter med guider</a></li>
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form">Skapa ny</a></li>
 [% END %]
 [% IF ( CAN_user_reports_execute_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=list">Använd sparad</a></li>
 [% END %]
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form_sql">Skapa från SQL</a></li>
 [% END %]
 </ul>

 <h5>Statistikguider</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">Inköp</a></li>
 <li><a href="/cgi-bin/koha/reports/borrowers_stats.pl">Låntagare</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_stats.pl">Katalog</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_stats.pl">Cirkulation</a></li>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">Periodika</a></li>
 <li><a href="/cgi-bin/koha/reports/cash_register_stats.pl">Kassaregister</a></li>
 <li><a href="/cgi-bin/koha/reports/reserves_stats.pl">Reservationer</a></li>
 </ul>

 [% IF plugins_enabled %]
 <h5>Instickprogram för rapporter</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl?method=report">Instickprogram för rapporter</a></li>
 </ul>
 [% END %]

 <h5>Topplistor</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/bor_issues_top.pl">Låntagare med flest lån</a></li>
 <li><a href="/cgi-bin/koha/reports/cat_issues_top.pl">Mest lånade exemplar</a></li>
 </ul>

 <h5>Inaktiv</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/borrowers_out.pl">Låntagare som inte lånat</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_out.pl">Exemplar utan lån</a></li>
 </ul>


 <h5>Annat</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/itemslost.pl">Förlorade exemplar</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">Sortera efter kostnadsställe</a></li>
 <li><a href="/cgi-bin/koha/reports/catalog_by_itemtype.pl">Katalog per exemplartyp</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_avg_stats.pl">Genomsnittlig lånetid</a></li>
 </ul>
 </div>
</div>
