[% USE Koha %]
<div id="navmenu">
 <div id="navmenulist">
 <h5>Inköp</h5>
 <ul>
 <li><a href="/cgi-bin/koha/acqui/acqui-home.pl">Inköp startsida</a></li>
 <li><a href="/cgi-bin/koha/acqui/histsearch.pl">Avancerad sökning</a></li>
 [% IF ( CAN_user_acquisition_order_receive ) %]<li><a href="/cgi-bin/koha/acqui/lateorders.pl">Sena beställningar</a></li>[% END %]
 [% IF CAN_user_suggestions_suggestions_create || CAN_user_suggestions_suggestions_manage || CAN_user_suggestions_suggestions_delete %]<li><a href="/cgi-bin/koha/suggestion/suggestion.pl">Förslag</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/invoices.pl">Fakturor</a></li>
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/acqui/edifactmsgs.pl">EDIFACT-meddelanden</a></li>
 [% END %]
 </ul>
 [% IF ( CAN_user_reports || CAN_user_circulate_circulate_remaining_permissions ) %]
 <h5>Rapporter</h5>
 <ul>
 [% IF ( CAN_user_reports ) %]
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">Guide för inköpsstatistik</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">Sortera efter kostnadsställe</a></li>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li><a href="/cgi-bin/koha/circ/reserveratios.pl">Reservationsförhållanden</a></li>
 [% END %]
 </ul>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || CAN_user_acquisition_currencies_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) || CAN_user_parameters_manage_additional_fields ) || ( Koha.Preference('MarcOrderingAutomation') && CAN_user_acquisition_marc_order_manage ) %]
 <h5>Administration</h5>
 <ul>
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">Budgetar</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">Budgetställen</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">Valutor</a></li>
 [% END %]
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">EDI-konton</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">Biblioteks-EAN</a></li>
 [% END %]
 [% IF Koha.Preference('MarcOrderingAutomation') && CAN_user_acquisition_marc_order_manage %]
 <li><a href="/cgi-bin/koha/admin/marc_order_accounts.pl">Konton för MARC-beställningar</a></li>
 [% END %]
 [% IF CAN_user_acquisition_edit_invoices && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqinvoices">Hantera faktureringsfält</a>
 </li>
 [% END %]
 [% IF CAN_user_acquisition_order_manage && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqbasket">Hantera fält i beställningskorg</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqorders">Hantera rader i beställning</a>
 </li>
 [% END %]
 </ul>
 [% END %]
 </div>
</div>
