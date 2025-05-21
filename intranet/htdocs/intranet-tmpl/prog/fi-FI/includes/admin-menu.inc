[% USE Koha %]

<div id="navmenu">
<div id="navmenulist">

 [% IF ( CAN_user_parameters_manage_sysprefs ) %]
 <h5>Järjestelmäasetukset</h5>
 <ul>
 <li><a href="/cgi-bin/koha/admin/preferences.pl">Järjestelmäasetukset</a></li>
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_libraries || CAN_user_parameters_manage_itemtypes || CAN_user_parameters_manage_auth_values ) %]
 <h5>Perusasetukset</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_libraries ) %]
 <li><a href="/cgi-bin/koha/admin/branches.pl">Kirjastot</a></li>
 <li><a href="/cgi-bin/koha/admin/library_groups.pl">Kirjastoryhmät</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_itemtypes ) %]
 <li><a href="/cgi-bin/koha/admin/itemtypes.pl">Nidetyypit</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_auth_values ) %]
 <li><a href="/cgi-bin/koha/admin/authorised_values.pl">Auktorisoidut arvot</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_patron_categories || CAN_user_parameters_manage_circ_rules || CAN_user_parameters_manage_patron_attributes || CAN_user_parameters_manage_transfers || CAN_user_parameters_manage_item_circ_alerts || CAN_user_parameters_manage_cities || CAN_user_parameters_manage_curbside_pickups || CAN_user_parameters_manage_patron_restrictions ) %]
 <h5>Asiakkaat ja lainaus</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_patron_categories ) %]
 <li><a href="/cgi-bin/koha/admin/categories.pl">Asiakastyypit</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_circ_rules ) %]
 <li><a href="/cgi-bin/koha/admin/smart-rules.pl">Laina- ja maksusäännöt</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_patron_attributes ) %]
 <li><a href="/cgi-bin/koha/admin/patron-attr-types.pl">Asiakasmääreet</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_transfers ) %]
 <li><a href="/cgi-bin/koha/admin/branch_transfer_limits.pl">Aineistokuljetusten rajoitukset</a></li>
 <li><a href="/cgi-bin/koha/admin/transport-cost-matrix.pl">Kuljetusten painomatriisi</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_item_circ_alerts ) %]
 <li><a href="/cgi-bin/koha/admin/item_circulation_alerts.pl">Nidekierron huomautukset</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCirculationDesks') && CAN_user_parameters_manage_libraries ) %]
 <li><a href="/cgi-bin/koha/admin/desks.pl">Tiskit</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_cities ) %]
 <li><a href="/cgi-bin/koha/admin/cities.pl">Kaupungit ja kunnat</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_curbside_pickups ) %]
 <li><a href="/cgi-bin/koha/admin/curbside_pickup.pl">Noutopalvelu</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_patron_restrictions ) %]
 <li><a href="/cgi-bin/koha/admin/restrictions.pl">Asiakkaan rajoitustyypit</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_accounts || ( Koha.Preference('UseCashRegisters') && CAN_user_parameters_manage_cash_registers ) ) %]
 <h5>Maksut</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_accounts ) %]
 <li><a href="/cgi-bin/koha/admin/debit_types.pl">Maksutyypit</a></li>
 <li><a href="/cgi-bin/koha/admin/credit_types.pl">Credit-tyypit</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCashRegisters') && CAN_user_parameters_manage_cash_registers ) %]
 <li><a href="/cgi-bin/koha/admin/cash_registers.pl">Kassat</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF CAN_user_plugins && plugins_enabled %]
 <h5>Liitännäiset</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl">Liitännäiset</a></li>
 </ul>
 [% END %]

 [% IF CAN_user_parameters_manage_background_jobs %]
 <h5>Taustatyöt</h5>
 <ul>
 <li><a href="/cgi-bin/koha/admin/background_jobs.pl">Taustatyöt</a></li>
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_marc_frameworks || CAN_user_parameters_manage_classifications || CAN_user_parameters_manage_matching_rules || CAN_user_parameters_manage_oai_sets || CAN_user_parameters_manage_item_search_fields || CAN_user_parameters_manage_search_engine_config || CAN_user_parameters_manage_marc_overlay_rules || ( Koha.Preference('SavedSearchFilters') && CAN_user_parameters_manage_search_filters ) ) %]
 <h5>Luettelo</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_marc_frameworks ) %]
 <li><a href="/cgi-bin/koha/admin/biblio_framework.pl">MARC-kuvailupohjat</a></li>
 <li><a href="/cgi-bin/koha/admin/koha2marclinks.pl">Kohan MARC-määritykset</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_marc_frameworks ) %]
 <li><a href="/cgi-bin/koha/admin/checkmarc.pl">MARC-kuvailupohjan testaus</a></li>
 <li><a href="/cgi-bin/koha/admin/authtypes.pl">Auktoriteettityypit</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_classifications ) %]
 <li><a href="/cgi-bin/koha/admin/classsources.pl">Luokitusjärjestelmät</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_matching_rules ) %]
 <li><a href="/cgi-bin/koha/admin/matching-rules.pl">Tietueiden täsmäytyssäännöt</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_record_sources ) %]
 <li><a href="/cgi-bin/koha/admin/record_sources">Tietuelähteet</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_marc_overlay_rules ) %]
 <li><a href="/cgi-bin/koha/admin/marc-overlay-rules.pl">Tietueiden yhdistämissäännöt</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_oai_sets ) %]
 <li><a href="/cgi-bin/koha/admin/oai_sets.pl">OAI-joukkojen asetukset</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_item_search_fields ) %]
 <li><a href="/cgi-bin/koha/admin/items_search_fields.pl">Nidehakukentät</a></li>
 [% END %]
 [% IF ( Koha.Preference('SavedSearchFilters') && CAN_user_parameters_manage_search_filters ) %]
 <li><a href="/cgi-bin/koha/admin/search_filters.pl">Haun rajaukset</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_search_engine_config ) %]
 <li><a href="/cgi-bin/koha/admin/searchengine/elasticsearch/mappings.pl">Hakukoneen asetukset (Elasticsearch)</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_acquisition_currencies_manage || CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) ) || ( Koha.Preference('MarcOrderingAutomation') && CAN_user_acquisition_marc_order_manage ) %]
 <h5>Hankinnan asetukset</h5>
 <ul>
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">Rahayksiköt ja vaihtokurssit</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">Budjetit</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">Tilit</a></li>
 [% END %]
 [% IF ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">EDI-tilit</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">Kirjasto-EANit</a></li>
 [% END %]
 [% IF ( Koha.Preference('MarcOrderingAutomation') && CAN_user_acquisition_marc_order_manage ) %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">MARC-tilausten tilit</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_identity_providers || CAN_user_parameters_manage_smtp_servers || CAN_user_parameters_manage_search_targets || CAN_user_parameters_manage_didyoumean || CAN_user_parameters_manage_column_config || CAN_user_parameters_manage_audio_alerts || ( CAN_user_parameters_manage_sms_providers && Koha.Preference('SMSSendDriver') == 'Email' ) || CAN_user_parameters_manage_usage_stats || CAN_user_parameters_manage_additional_fields || ( Koha.Preference('EnableAdvancedCatalogingEditor') && CAN_user_parameters_manage_keyboard_shortcuts ) ) %]
 <h5>Muut parametrit</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_identity_providers) %]
 <li><a href="/cgi-bin/koha/admin/identity_providers.pl">Tunnistustietojen tarjoajat</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_search_targets ) %]
 <li><a href="/cgi-bin/koha/admin/z3950servers.pl">Z39.50/SRU-palvelimet</a></li>
 <li><a href="/cgi-bin/koha/admin/oai_servers.pl">OAI-tietovarannot</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_smtp_servers ) %]
 <li><a href="/cgi-bin/koha/admin/smtp_servers.pl">SMTP-palvelimet</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_didyoumean ) %]
 <li><a href="/cgi-bin/koha/admin/didyoumean.pl">Tarkoititko?</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_column_config ) %]
 <li><a href="/cgi-bin/koha/admin/columns_settings.pl">Taulujen asetukset</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_audio_alerts ) %]
 <li><a href="/cgi-bin/koha/admin/audio_alerts.pl">Äänihälytykset</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_sms_providers && Koha.Preference('SMSSendDriver') == 'Email' ) %]
 <li><a href="/cgi-bin/koha/admin/sms_providers.pl">SMS-puhelinoperaattorit</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_usage_stats ) %]
 <li><a href="/cgi-bin/koha/admin/usage_statistics.pl">Jaa käyttötilastoja</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_mana ) %]
 <li><a href="/cgi-bin/koha/admin/share_content.pl">Jaa sisältö Mana-tietämyskannassa</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_additional_fields ) %]
 <li><a href="/cgi-bin/koha/admin/additional-fields.pl">Lisäkentät</a></li>
 [% END %]
 [% IF ( Koha.Preference('EnableAdvancedCatalogingEditor') && CAN_user_parameters_manage_keyboard_shortcuts ) %]
 <li><a href="/cgi-bin/koha/admin/adveditorshortcuts.pl">Pikanäppäimet</a></li>
 [% END %]
 [% IF Koha.Preference('ILLModule ') && CAN_user_ill %]
 <li><a href="/cgi-bin/koha/admin/ill_batch_statuses.pl">Kaukolainaerän tilat</a></li>
 [% END %]
 </ul>
 [% END %]
</div>
</div>
