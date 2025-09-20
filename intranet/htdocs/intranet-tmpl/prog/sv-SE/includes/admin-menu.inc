[% USE Koha %]

<div id="navmenu">
<div id="navmenulist">

 [% IF ( CAN_user_parameters_manage_sysprefs ) %]
 <h5>Systeminställningar</h5>
 <ul>
 <li><a href="/cgi-bin/koha/admin/preferences.pl">Systeminställningar</a></li>
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_libraries || CAN_user_parameters_manage_itemtypes || CAN_user_parameters_manage_auth_values ) %]
 <h5>Grundparametrar</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_libraries ) %]
 <li><a href="/cgi-bin/koha/admin/branches.pl">Bibliotek</a></li>
 <li><a href="/cgi-bin/koha/admin/library_groups.pl">Biblioteksgrupper</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_itemtypes ) %]
 <li><a href="/cgi-bin/koha/admin/itemtypes.pl">Exemplartyper</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_auth_values ) %]
 <li><a href="/cgi-bin/koha/admin/authorised_values.pl">Auktoriserade värden</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_patron_categories || CAN_user_parameters_manage_circ_rules || CAN_user_parameters_manage_patron_attributes || CAN_user_parameters_manage_transfers || CAN_user_parameters_manage_item_circ_alerts || CAN_user_parameters_manage_cities || CAN_user_parameters_manage_curbside_pickups || CAN_user_parameters_manage_patron_restrictions ) %]
 <h5>Låntagare och cirkulation</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_patron_categories ) %]
 <li><a href="/cgi-bin/koha/admin/categories.pl">Låntagarkategorier</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_circ_rules ) %]
 <li><a href="/cgi-bin/koha/admin/smart-rules.pl">Regler för utlån och avgifter</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_patron_attributes ) %]
 <li><a href="/cgi-bin/koha/admin/patron-attr-types.pl">Attributtyper för låntagare</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_transfers ) %]
 <li><a href="/cgi-bin/koha/admin/branch_transfer_limits.pl">Överföringsbegränsningar för bibliotek</a></li>
 <li><a href="/cgi-bin/koha/admin/transport-cost-matrix.pl">Fraktkostnadstabell</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_item_circ_alerts ) %]
 <li><a href="/cgi-bin/koha/admin/item_circulation_alerts.pl">Lånenotifikationer för exemplar</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCirculationDesks') && CAN_user_parameters_manage_libraries ) %]
 <li><a href="/cgi-bin/koha/admin/desks.pl">Diskar</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_cities ) %]
 <li><a href="/cgi-bin/koha/admin/cities.pl">Orter</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_curbside_pickups ) %]
 <li><a href="/cgi-bin/koha/admin/curbside_pickup.pl">Upphämtning</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_patron_restrictions ) %]
 <li><a href="/cgi-bin/koha/admin/restrictions.pl">Låntagarbegränsningar</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_accounts || ( Koha.Preference('UseCashRegisters') && CAN_user_parameters_manage_cash_registers ) ) %]
 <h5>Avgifter</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_accounts ) %]
 <li><a href="/cgi-bin/koha/admin/debit_types.pl">Debiteringstyper</a></li>
 <li><a href="/cgi-bin/koha/admin/credit_types.pl">Kredittyper</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCashRegisters') && CAN_user_parameters_manage_cash_registers ) %]
 <li><a href="/cgi-bin/koha/admin/cash_registers.pl">Kassaregister</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF CAN_user_plugins && plugins_enabled %]
 <h5>Plugins</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl">Plugins</a></li>
 </ul>
 [% END %]

 [% IF CAN_user_parameters_manage_background_jobs %]
 <h5>Jobb</h5>
 <ul>
 <li><a href="/cgi-bin/koha/admin/background_jobs.pl">Jobb</a></li>
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_marc_frameworks || CAN_user_parameters_manage_classifications || CAN_user_parameters_manage_matching_rules || CAN_user_parameters_manage_oai_sets || CAN_user_parameters_manage_item_search_fields || CAN_user_parameters_manage_search_engine_config || CAN_user_parameters_manage_marc_overlay_rules || ( Koha.Preference('SavedSearchFilters') && CAN_user_parameters_manage_search_filters ) ) %]
 <h5>Katalog</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_marc_frameworks ) %]
 <li><a href="/cgi-bin/koha/admin/biblio_framework.pl">MARC bibliografiskt ramverk</a></li>
 <li><a href="/cgi-bin/koha/admin/koha2marclinks.pl">Koha till MARC-mappning</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_marc_frameworks ) %]
 <li><a href="/cgi-bin/koha/admin/checkmarc.pl">Test av MARC bibliografiskt ramverk</a></li>
 <li><a href="/cgi-bin/koha/admin/authtypes.pl">Auktoritetstyper</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_classifications ) %]
 <li><a href="/cgi-bin/koha/admin/classsources.pl">Klassificeringsinställningar</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_matching_rules ) %]
 <li><a href="/cgi-bin/koha/admin/matching-rules.pl">Regler för postmatchning</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_record_sources ) %]
 <li><a href="/cgi-bin/koha/admin/record_sources">Postkällor</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_marc_overlay_rules ) %]
 <li><a href="/cgi-bin/koha/admin/marc-overlay-rules.pl">Regler för överskrivning av poster</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_oai_sets ) %]
 <li><a href="/cgi-bin/koha/admin/oai_sets.pl">Konfiguration av OAI-uppsättningar</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_item_search_fields ) %]
 <li><a href="/cgi-bin/koha/admin/items_search_fields.pl">Exemplarsökfält</a></li>
 [% END %]
 [% IF ( Koha.Preference('SavedSearchFilters') && CAN_user_parameters_manage_search_filters ) %]
 <li><a href="/cgi-bin/koha/admin/search_filters.pl">Sökfilter</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_search_engine_config ) %]
 <li><a href="/cgi-bin/koha/admin/searchengine/elasticsearch/mappings.pl">Sökmotorinställningar (Elasticsearch)</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_acquisition_currencies_manage || CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) ) || ( Koha.Preference('MarcOrderingAutomation') && CAN_user_acquisition_marc_order_manage ) %]
 <h5>Inköpsparametrar</h5>
 <ul>
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">Valutor och växelkurser</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">Budgetar</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">Budgetställen</a></li>
 [% END %]
 [% IF ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">EDI-konton</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">Biblioteks-EAN</a></li>
 [% END %]
 [% IF ( Koha.Preference('MarcOrderingAutomation') && CAN_user_acquisition_marc_order_manage ) %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">Konton för MARC-beställningar</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_identity_providers || CAN_user_parameters_manage_smtp_servers || CAN_user_parameters_manage_search_targets || CAN_user_parameters_manage_didyoumean || CAN_user_parameters_manage_column_config || CAN_user_parameters_manage_audio_alerts || ( CAN_user_parameters_manage_sms_providers && Koha.Preference('SMSSendDriver') == 'Email' ) || CAN_user_parameters_manage_usage_stats || CAN_user_parameters_manage_additional_fields || ( Koha.Preference('EnableAdvancedCatalogingEditor') && CAN_user_parameters_manage_keyboard_shortcuts ) ) %]
 <h5>Fler parametrar</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_identity_providers) %]
 <li><a href="/cgi-bin/koha/admin/identity_providers.pl">Identitetsleverantörer</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_search_targets ) %]
 <li><a href="/cgi-bin/koha/admin/z3950servers.pl">Z39.50/SRU-servrar</a></li>
 <li><a href="/cgi-bin/koha/admin/oai_servers.pl">OAI-uppsättning</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_smtp_servers ) %]
 <li><a href="/cgi-bin/koha/admin/smtp_servers.pl">SMTP-servrar</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_didyoumean ) %]
 <li><a href="/cgi-bin/koha/admin/didyoumean.pl">Menade du?</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_column_config ) %]
 <li><a href="/cgi-bin/koha/admin/columns_settings.pl">Kolumnvisning</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_audio_alerts ) %]
 <li><a href="/cgi-bin/koha/admin/audio_alerts.pl">Ljudnotifikationer</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_sms_providers && Koha.Preference('SMSSendDriver') == 'Email' ) %]
 <li><a href="/cgi-bin/koha/admin/sms_providers.pl">SMS-leverantörer</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_usage_stats ) %]
 <li><a href="/cgi-bin/koha/admin/usage_statistics.pl">Dela användningsstatistik</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_mana ) %]
 <li><a href="/cgi-bin/koha/admin/share_content.pl">Dela innehåll med Mana KB</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_additional_fields ) %]
 <li><a href="/cgi-bin/koha/admin/additional-fields.pl">Ytterligare fält</a></li>
 [% END %]
 [% IF ( Koha.Preference('EnableAdvancedCatalogingEditor') && CAN_user_parameters_manage_keyboard_shortcuts ) %]
 <li><a href="/cgi-bin/koha/admin/adveditorshortcuts.pl">Tangentbordsgenvägar</a></li>
 [% END %]
 [% IF Koha.Preference('ILLModule ') && CAN_user_ill %]
 <li><a href="/cgi-bin/koha/admin/ill_batch_statuses.pl">Satsstatusar för fjärrlån</a></li>
 [% END %]
 </ul>
 [% END %]
</div>
</div>
