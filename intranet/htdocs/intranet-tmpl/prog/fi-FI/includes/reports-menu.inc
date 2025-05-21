[% USE Koha %]

<div id="navmenu">
 <div id="navmenulist">

 <h5>Ohjatut raportit</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl">Ohjatut raportit</a></li>
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form">Luo uusi</a></li>
 [% END %]
 [% IF ( CAN_user_reports_execute_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=list">Käytä tallennettua raporttia</a></li>
 [% END %]
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form_sql">Luo SQL-lausekkeesta</a></li>
 [% END %]
 </ul>

 <h5>Tilastovelho</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">Hankinnat</a></li>
 <li><a href="/cgi-bin/koha/reports/borrowers_stats.pl">Asiakkaat</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_stats.pl">Luettelo</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_stats.pl">Lainaus ja palautus</a></li>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">Kausijulkaisut</a></li>
 <li><a href="/cgi-bin/koha/reports/cash_register_stats.pl">Kassajärjestelmä</a></li>
 <li><a href="/cgi-bin/koha/reports/reserves_stats.pl">Varaukset</a></li>
 </ul>

 [% IF plugins_enabled %]
 <h5>Raporttiliitännäiset</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl?method=report">Raporttiliitännäiset</a></li>
 </ul>
 [% END %]

 <h5>Eniten...</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/bor_issues_top.pl">Asiakkaat, joilla on eniten lainoja</a></li>
 <li><a href="/cgi-bin/koha/reports/cat_issues_top.pl">Eniten lainattu aineisto</a></li>
 </ul>

 <h5>Ei käytössä</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/borrowers_out.pl">Asiakkaat, jotka eivät ole lainanneet</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_out.pl">Niteet, joita ei ole lainattu</a></li>
 </ul>


 <h5>Muu</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/itemslost.pl">Kadonnut aineisto</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">Tilauksia tilin mukaan</a></li>
 <li><a href="/cgi-bin/koha/reports/catalog_by_itemtype.pl">Luettelo aineistoittain</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_avg_stats.pl">Keskimääräinen laina-aika</a></li>
 </ul>
 </div>
</div>
