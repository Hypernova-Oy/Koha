[% USE Koha %]
<div id="navmenu">
 <div id="navmenulist">
 <h5>Hankinnat</h5>
 <ul>
 <li><a href="/cgi-bin/koha/acqui/acqui-home.pl">Hankinnat</a></li>
 <li><a href="/cgi-bin/koha/acqui/histsearch.pl">Tarkka haku</a></li>
 [% IF ( CAN_user_acquisition_order_receive ) %]<li><a href="/cgi-bin/koha/acqui/lateorders.pl">Myöhässä olevat tilaukset</a></li>[% END %]
 [% IF CAN_user_suggestions_suggestions_create || CAN_user_suggestions_suggestions_manage || CAN_user_suggestions_suggestions_delete %]<li><a href="/cgi-bin/koha/suggestion/suggestion.pl">Hankintaehdotukset</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/invoices.pl">Laskut</a></li>
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/acqui/edifactmsgs.pl">EDIFACT-viestit</a></li>
 [% END %]
 </ul>
 [% IF ( CAN_user_reports || CAN_user_circulate_circulate_remaining_permissions ) %]
 <h5>Raportit</h5>
 <ul>
 [% IF ( CAN_user_reports ) %]
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">Hankinnan tilastovelho</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">Tilaukset tilin mukaan</a></li>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li><a href="/cgi-bin/koha/circ/reserveratios.pl">Varauksia per nide</a></li>
 [% END %]
 </ul>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || CAN_user_acquisition_currencies_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) || CAN_user_parameters_manage_additional_fields ) || ( Koha.Preference('MarcOrderingAutomation') && CAN_user_acquisition_marc_order_manage ) %]
 <h5>Ylläpito</h5>
 <ul>
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">Budjetit</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">Tilit</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">Valuutat</a></li>
 [% END %]
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">EDI-tilit</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">Kirjasto-EANit</a></li>
 [% END %]
 [% IF Koha.Preference('MarcOrderingAutomation') && CAN_user_acquisition_marc_order_manage %]
 <li><a href="/cgi-bin/koha/admin/marc_order_accounts.pl">MARC-tilausten tilit</a></li>
 [% END %]
 [% IF CAN_user_acquisition_edit_invoices && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqinvoices">Hallinnoi laskukenttiä</a>
 </li>
 [% END %]
 [% IF CAN_user_acquisition_order_manage && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqbasket">Hallinnoi tilauskorien kenttiä</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqorders">Hallinnoi tilausrivien kenttiä</a>
 </li>
 [% END %]
 </ul>
 [% END %]
 </div>
</div>
