[%- BLOCK main_permissions -%]
 [% SWITCH name %]
 [%- CASE 'superlibrarian' -%]
 <span class="main_permission superlibrarian_permission">Pääsy kaikkiin virkailijan toimintoihin</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'circulate' -%]
 <span class="main_permission circulate_permission">Lainata ja palauttaa niteitä</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'catalogue' -%]
 <span class="main_permission catalogue_permission">Virkailijaliittymään pääsy, sallii luettelon katselemisen virkailijaliittymässä</span>
 <span class="permissioncode">([% name | html %])</span> <span class="required">Vaaditaan virkailijaliittymään kirjautumisessa.</span>
 [%- CASE 'parameters' -%]
 <span class="main_permission parameters_permission">Hallinnoida Kohan järjestelmäasetuksia (Ylläpidon paneli)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'borrowers' -%]
 <span class="main_permission borrowers_permission">Lisätä, muokata ja katsoa asiakastietoja</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'permissions' -%]
 <span class="main_permission permissions_permission">Asettaa käyttäjäoikeuksia</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reserveforothers' -%]
 <span class="main_permission reserveforothers_permission">Tehdä ja muokata asiakkaiden varauksia</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'editcatalogue' -%]
 <span class="main_permission editcatalogue_permission">Muokata luetteloa (Muokata nimeke/kokoelmatietoa)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'updatecharges' -%]
 <span class="main_permission updatecharges_permission">Hallinnoida asiakkaan maksuja</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'acquisition' -%]
 <span class="main_permission acquisition_permission">Hankinnan hoito</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions' -%]
 <span class="main_permission suggestions_permission">Hankintaehdotusten hallinta</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'tools' -%]
 <span class="main_permission tools_permission">Käyttää kaikkia työkaluja (laajenna yksityiskohtaisiin työkalujen oikeuksiin)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'editauthorities' -%]
 <span class="main_permission editauthorities_permission">Muokata auktoriteettejä</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'serials' -%]
 <span class="main_permission serials_permission">Hallinnoida kausijulkaisutilauksia</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reports' -%]
 <span class="main_permission reports_permission">Pääsy raportit-osioon</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'staffaccess' -%]
 <span class="main_permission staffaccess_permission">Salli virkailijan muokata toisen virkailijan oikeuksia, käyttäjätunnusta ja salasanaa</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'coursereserves' -%]
 <span class="main_permission coursereserves_permission">Kurssivarannot</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'plugins' -%]
 <span class="main_permission plugins_permission">Kohan liitännäiset</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'lists' -%]
 <span class="main_permission lists_permission">Listat</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'clubs' -%]
 <span class="main_permission clubs_permission">Asiakaskerhot</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'ill' -%]
 <span class="main_permission ill_permission">Luoda ja muokata kaukolainapyyntöjä</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'self_check' -%]
 <span class="main_permission self_check_permission">Itsepalvelumodulit</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'stockrotation' -%]
 <span class="main_permission self_check_permission">Hallinnoida kiertokokoelmia</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'cash_management' -%]
 <span class="main_permission cash_management_permission">Kassan hallinta</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'problem_reports' -%]
 <span class="main_permission problem_reports_permission">Hallinnoida verkkokirjaston vikailmoituksia</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'recalls' -%]
 <span class="main_permission recalls_permission">Palautuspyynnöt</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'erm' -%]
 <span class="main_permission erm_permission">Hallinnoida elektronisten aineistojen moduulia</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'loggedinlibrary' -%]
 <span class="main_permission loggedinlibrary_permission">Salli virkailijan muuttaa kirjautunutta kirjastoa</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'preservation' -%]
 <span class="main_permission preservation_permission">Hallinnoida käsittelyerien moduulia</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- END -%]
[%- END -%]

[%- BLOCK sub_permissions -%]
 [% SWITCH name %]
 [%- CASE 'circulate_remaining_permissions' -%]
 <span class="sub_permission circulate_remaining_permissions_subpermission">
 Jäljellä olevat lainauksen ja palautuksen oikeudet </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'force_checkout' -%]
 <span class="sub_permission force_checkout_subpermission">
 Pakota lainaus, jos on rajoitus </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_restrictions' -%]
 <span class="sub_permission manage_restrictions_subpermission">
 Hallinnoida asiakastilien rajoituksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'overdues_report' -%]
 <span class="sub_permission overdues_report_subpermission">
 Ajaa myöhässä olevien niteiden raportteja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'override_renewals' -%]
 <span class="sub_permission override_renewals_subpermission">
 Ohittaa uusintojen esto </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_bookings' %]
 <span class="sub_permission manage_bookings_subpermission">
 Hallinnoida niteiden käyttövarauksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_checkout_notes' %]
 <span class="sub_permission manage_checkout_notes_subpermission">
 Merkata lainahuomautukset nähdyksi/näkemättömiksi </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_accounts' -%]
 <span class="sub_permission manage_accounts_subpermission">
 Hallinnoida maksu- ja credit-tyyppejä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules' -%]
 <span class="sub_permission manage_circ_rules_subpermission">
 Hallinnoida lainasääntöjä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules_from_any_libraries' -%]
 <span class="sub_permission manage_circ_rules_from_any_libraries_subpermission">
 Hallinnoida lainasääntöjä kaikille kirjastoille. Jos ei asetettu, kirjautunut käyttäjä voi muokata vain oman kirjaston lainasääntöjä (manage_circ_rules vaaditaan lisäksi) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'parameters_remaining_permissions' -%]
 <span class="sub_permission parameters_remaining_permissions_subpermission">
 Järjestelmäasetusten jäljelle jäävät oikeudet </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules' -%]
 <span class="sub_permission manage_circ_rules_subpermission">
 Hallinnoida lainasääntöjä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_sysprefs' -%]
 <span class="sub_permission manage_sysprefs_subpermission">
 Hallinnoida järjestelmäasetuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_libraries' -%]
 <span class="sub_permission manage_libraries_subpermission">
 Hallinnoida kirjastoja ja kirjastoryhmiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_itemtypes' -%]
 <span class="sub_permission manage_itemtypes_subpermission">
 Hallinnoida nidetyyppejä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_auth_values' -%]
 <span class="sub_permission manage_auth_values_subpermission">
 Määritellä auktorisoitujen arvojen luokkia ja auktorisoituja arvoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_categories' -%]
 <span class="sub_permission manage_patron_categories_subpermission">
 Hallinnoida asiakastyyppejä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_restrictions' -%]
 <span class="sub_permission manage_patron_restrictions_subpermission">
 Hallinnoida asiakkaan rajoituksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_attributes' -%]
 <span class="sub_permission manage_patron_attributes_subpermission">
 Hallinnoida asiakasmääreitä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_transfers' -%]
 <span class="sub_permission manage_transfers_subpermission">
 Hallinnoida kuljetusten rajoituksia ja painomatriisia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_circ_alerts' -%]
 <span class="sub_permission manage_item_circ_alerts_subpermission">
 Hallinnoida niteen lainaushuomautuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_cities' -%]
 <span class="sub_permission manage_cities_subpermission">
 Hallinnoida kaupunkeja ja kuntia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_marc_frameworks' -%]
 <span class="sub_permission manage_marc_frameworks_subpermission">
 Hallinnoida MARC-tietueiden ja auktoriteettien kuvailupohjia ja testata niitä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_classifications' -%]
 <span class="sub_permission manage_classifications_subpermission">
 Hallinnoida luokitusjärjestelmiä ja luokitusoppaita </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_matching_rules' -%]
 <span class="sub_permission manage_matching_rules_subpermission">
 Hallinnoida tietueiden täsmäytyssääntöjä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_oai_sets' -%]
 <span class="sub_permission manage_oai_sets_subpermission">
 Hallinnoida OAI-joukkoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_search_fields' -%]
 <span class="sub_permission manage_item_search_fields_subpermission">
 Hallinnoida nidehakukenttiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_filters' -%]
 <span class="sub_permission manage_search_filters_subpermission">
 Hallinnoida tallennettuja räätälöityjä haun rajauksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_engine_config' -%]
 <span class="sub_permission manage_search_engine_config_subpermission">
 Hallinnoida hakukoneen asetuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_marc_overlay_rules' -%]
 <span class="sub_permission manage_marc_overlay_rules_subpermission">
 Hallinnoida MARC-tietueiden yhdistämissääntöjä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_targets' -%]
 <span class="sub_permission manage_search_targets_subpermission">
 Hallinnoida Z39.50 ja SRU-palvelimia sekä OAI-tietovarantojen asetuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_didyoumean' -%]
 <span class="sub_permission manage_didyoumean_subpermission">
 Hallinnoida Tarkoititko? -asetuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_smtp_servers' -%]
 <span class="sub_permission manage_manage_smtp_servers_subpermission">
 Hallinnoida SMTP-palvelimia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_column_config' -%]
 <span class="sub_permission manage_column_config_subpermission">
 Hallinnoida sarakemäärityksiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_audio_alerts' -%]
 <span class="sub_permission manage_audio_alerts_subpermission">
 Hallinnoida äänihälytyksiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_additional_fields' -%]
 <span class="sub_permission manage_aditional_fields_subpermission">
 Hallinnoida tilauskorien tai kausijulkaisutilausten lisäkenttiä (vaaditaan oikeuksia joko edit_subscription, order_manage, edit_invoices tai remaining_permissions asiakkaan maksujen osalta) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_sms_providers' -%]
 <span class="sub_permission manage_sms_providers_subpermission">
 Hallinnoida SMS-puhelinoperaattoreita </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_usage_stats' -%]
 <span class="sub_permission manage_usage_stats_subpermission">
 Hallinnoida käyttötilastojen asetuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_mana' -%]
 <span class="sub_permission manage_mana_subpermission">
 Hallinnoida Mana-tietämyskannan sisällön jakoa </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_keyboard_shortcuts' -%]
 <span class="sub_permission manage_keyboard_shortcuts_subpermission">
 Hallinnoida kehittyneen kuvailueditorin pikanäppäimiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_background_jobs' -%]
 <span class="sub_permission manage_background_jobs_subpermission">
 Hallinnoida taustatöitä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_curbside_pickups' -%]
 <span class="sub_permission manage_curbside_pickups_subpermission">
 Hallinnoida noutopalvelua </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_borrowers' -%]
 <span class="sub_permission delete_borrowers_subpermission">
 Poistaa asiakkaita </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_borrowers' -%]
 <span class="sub_permission edit_borrowers_subpermission">
 Lisätä, muokata ja katsoa asiakastietoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'list_borrowers' -%]
 <span class="sub_permission list_borrowers_subpermission">
 Hakea, listata ja katsella asiakastietoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'view_borrower_infos_from_any_libraries' -%]
 <span class="sub_permission view_borrower_infos_from_any_libraries_subpermission">
 Katsoa asiakastietoja kaikista kirjastoista. Jos tämä ei ole valittuna, käyttäjällä on pääsy vain oman kirjastonsa tai kirjastoryhmänsä asiakastietoihin. </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'send_messages_to_borrowers' -%]
 <span class="sub_permission send_messages_to_borrowers_subpermission">
 Lähettää viestejä asiakkaille </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'modify_holds_priority' -%]
 <span class="sub_permission modify_holds_priority_subpermission">
 Muokata varausten järjestystä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'place_holds' -%]
 <span class="sub_permission place_holds_subpermission">
 Tehdä varauksia asiakkaille </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_all_items' -%]
 <span class="sub_permission delete_all_items_subpermission">
 Poistaa kaikki niteet kerralla </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_catalogue' -%]
 <span class="sub_permission edit_catalogue_subpermission">
 Muokata luetteloa (Muokata nimeke/kokoelmatietoa) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_locked_records' -%]
 <span class="sub_permission edit_locked_records_subpermission">
 Muokata lukittuja tietueita </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'set_record_sources' -%]
 <span class="sub_permission set_record_sources_subpermission">
 Asettaa tietuelähteitä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'advanced_editor' -%]
 <span class="sub_permission advanced_editor_subpermission">
 Käyttää edistynyttä kuvailueditoria (vaatii edit_catalogue) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_shared_macros' -%]
 <span class="sub_permission create_shared_macros_subpermission">
 Luoda jaettuja makroja (vaatii advanced_editor-käyttäjäoikeuden) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_shared_macros' -%]
 <span class="sub_permission delete_shared_macros_subpermission">
 Poistaa jaettuja makroja (vaatii advanced_editor-käyttäjäoikeuden) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_items' -%]
 <span class="sub_permission edit_items_subpermission">
 Muokata niteitä (ei sisällä niteitä, jotka on rajoitettu kirjastoryhmällä) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_any_item' -%]
 <span class="sub_permission edit_items_subpermission">
 Muokata mitä tahansa nidettä mukaan lukien niteitä, jotka olisi muutoin rajoitettu </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_items_restricted' -%]
 <span class="sub_permission edit_items_restricted_subpermission">
 Rajoita niteiden muokkaus osakenttiin, jotka on määritelty SubfieldsToAllowForRestrictedEditing-asetuksessa (huomaa, että edit_item vaaditaan lisäksi) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'fast_cataloging' -%]
 <span class="sub_permission fast_cataloging_subpermission">
 Pikakuvailu </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_groups' -%]
 <span class="sub_permission manage_item_groups_subpermission">
 Luoda, päivittää ja poistaa nideryhmiä, lisätä tai poistaa niteitä nideryhmästä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_editor_templates' -%]
 <span class="sub_permission manage_item_editor_templates_subpermission">
 Luoda, muokata ja poistaa toisten luomia niteen muokkauspohjia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'remaining_permissions' -%]
 <span class="sub_permission remaining_permissions_subpermission">
 Jäljelle jäävät oikeudet maksujen hallintaan </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'discount' -%]
 <span class="sub_permission discount_subpermission">
 Antaa asiakkaille alennuksia maksuista </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'payout' -%]
 <span class="sub_permission payout_subpermission">
 Antaa asiakkaan hyvitykset takaisin rahana </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'refund' -%]
 <span class="sub_permission refund_subpermission">
 Hyvittää maksuja asiakkaille </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'writeoff' -%]
 <span class="sub_permission writeoff_subpermission">
 Poistaa maksuja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manual_invoice' -%]
 <span class="sub_permission manual_invoice_subpermission">
 Lisätä maksuja asiakkaalle </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manual_credit' -%]
 <span class="sub_permission manual_credit_subpermission">
 Lisätä hyvityksiä asiakkaille </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions_create' -%]
 <span class="sub_permission suggestions_create_subpermission">
 Luoda hankintaehdotuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions_manage' -%]
 <span class="sub_permission suggestions_manage_subpermission">
 Muokata hankintaehdotuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions_delete' -%]
 <span class="sub_permission suggestions_delete_subpermission">
 Poistaa hankintaehdotuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_add_del' -%]
 <span class="sub_permission budget_add_del_subpermission">
 Lisätä ja poistaa tilejä (mutta ei voi muokata budjetteja) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_manage' -%]
 <span class="sub_permission budget_manage_subpermission">
 Hallinnoida tilejä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_manage_all' -%]
 <span class="sub_permission budget_manage_all_subpermission">
 Hallinnoida kaikkia tilejä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_modify' -%]
 <span class="sub_permission budget_modify_subpermission">
 Muokata tilejä (ei voi luoda rivejä, mutta voi muokata olemassa olevia) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'contracts_manage' -%]
 <span class="sub_permission contracts_manage_subpermission">
 Hallinnoida sopimuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'group_manage' -%]
 <span class="sub_permission group_manage_subpermission">
 Hallinnoida tilausryhmiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_manage' -%]
 <span class="sub_permission order_manage_subpermission">
 Hallinnoida tilauskoreja ja tilauksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_manage_all' -%]
 <span class="sub_permission order_manage_all_subpermission">
 Hallinnoida kaikkia tilauskoreja ja tilauksia niiden rajoituksista huolimatta </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'issue_manage' -%]
 <span class="sub_permission issue_manage_subpermission">
 Hallinnoida toimittajien ongelmia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_receive' -%]
 <span class="sub_permission order_receive_subpermission">
 Vastaanottaa ja hallinnoida tilauksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'period_manage' -%]
 <span class="sub_permission period_manage_subpermission">
 Hallinnoida budjetteja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'planning_manage' -%]
 <span class="sub_permission planning_manage_subpermission">
 Hallinnoida budjetin suunnittelua </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'vendors_manage' -%]
 <span class="sub_permission vendors_manage_subpermission">
 Hallinnoida toimittajia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'currencies_manage' -%]
 <span class="sub_permission currencies_manage_subpermission">
 Hallinnoida rahayksiköitä ja vaihtokursseja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'batch_upload_patron_images' -%]
 <span class="sub_permission batch_upload_patron_images_subpermission">
 Ladata asiakaskuvia eräajona tai yksitellen </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_anonymize_patrons' -%]
 <span class="sub_permission delete_anonymize_patrons_subpermission">
 Poistaa vanhoja asiakkaita ja anonymisoida lainahistoriaa (poistaa asiakkaan lainahistoria) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'batch_extend_due_dates' -%]
 <span class="sub_permission batch_extend_due_dates_subpermission">
 Tehdä eräpäivien siirto eräajona </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_calendar' -%]
 <span class="sub_permission edit_calendar_subpermission">
 Määritellä kirjaston kiinniolopäiviä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_additional_contents' -%]
 <span class="sub_permission edit_additional_contents_subpermission">
 Kirjoitaa lisäsisältöä verkkokirjastoon ja virkailijaliittymään (uutiset ja HTML muokkaukset) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_notice_status_triggers' -%]
 <span class="sub_permission edit_notice_status_triggers_subpermission">
 Määritellä myöhästymisilmoituksia myöhässä oleville niteille </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_notices' -%]
 <span class="sub_permission edit_notices_subpermission">
 Määritellä ilmoituksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_patrons' -%]
 <span class="sub_permission edit_patrons_subpermission">
 Tehdä asiakkaiden erämuokkaus </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_quotes' -%]
 <span class="sub_permission edit_quotes_subpermission">
 Muokata sitaatteja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'export_catalog' -%]
 <span class="sub_permission export_catalog_subpermission">
 Viedä bibliografisia ja kokoelmatietoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'import_patrons' -%]
 <span class="sub_permission import_patrons_subpermission">
 Tuoda asiakkaiden tietoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'inventory' -%]
 <span class="sub_permission inventory_subpermission">
 Inventoida kokoelmaa </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchdel' -%]
 <span class="sub_permission items_batchdel_subpermission">
 Tehdä niteiden eräpoisto </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchmod' -%]
 <span class="sub_permission items_batchmod_subpermission">
 Tehdä niteiden erämuokkaus </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchmod_restricted' -%]
 <span class="sub_permission items_batchmod_restricted_subpermission">
 Rajoita niteiden erämuokkaus osakenttiin, jotka on määritelty SubfieldsToAllowForRestrictedBatchmod-asetuksessa (huomaa, että items_batchmod vaaditaan lisäksi) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'label_creator' -%]
 <span class="sub_permission label_creator_subpermission">
 Luoda tulostettavia tarroja ja viivakoodeja niteille ja asiakkaille </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_csv_profiles' -%]
 <span class="sub_permission manage_csv_profiles_subpermission">
 Hallinnoida CSV-viennin profiileja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_lists' -%]
 <span class="sub_permission manage_patron_lists_subpermission">
 Lisätä, muokata ja poistaa asiakaslistoja ja niiden sisältöjä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_staged_marc' -%]
 <span class="sub_permission manage_staged_marc_subpermission">
 Hallinnoida välivarastoituja MARC-tietueita, myös tuontien hyväksyminen ja peruutus </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'marc_modification_templates' -%]
 <span class="sub_permission marc_modification_templates_subpermission">
 Hallinnoida MARC-muokkauksen pohjia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'moderate_comments' -%]
 <span class="sub_permission moderate_comments_subpermission">
 Hyväksyä asiakkaiden kommentteja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'moderate_tags' -%]
 <span class="sub_permission moderate_tags_subpermission">
 Hyväksyä asiakkaiden tageja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'records_batchdel' -%]
 <span class="sub_permission records_batchdel_subpermission">
 Poistaa tietueita eräajona (nimeketietueet tai auktoriteettitietueet) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'records_batchmod' -%]
 <span class="sub_permission records_batchmod_subpermission">
 Muokata tietueita eräajona (nimekkeet tai auktoriteetit) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'rotating_collections' -%]
 <span class="sub_permission rotating_collections_subpermission">
 Hallinnoida siirtokokoelmia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'schedule_tasks' -%]
 <span class="sub_permission schedule_tasks_subpermission">
 Ajastaa tehtäviä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'stage_marc_import' -%]
 <span class="sub_permission stage_marc_import_subpermission">
 Viedä MARC-tietueita väliaikaisvarastoon </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_local_cover_images' -%]
 <span class="sub_permission upload_local_cover_images_subpermission">
 Ladata paikallisia kansikuvia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'view_system_logs' -%]
 <span class="sub_permission view_system_logs_subpermission">
 Selata järjestelmän lokeja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'check_expiration' -%]
 <span class="sub_permission check_expiration_subpermission">
 Tarkistaa kausijulkaisun tilauksen päättymisaika </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'claim_serials' -%]
 <span class="sub_permission claim_serials_subpermission">
 Reklamoida puuttuvia kausijulkaisuja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_subscription' -%]
 <span class="sub_permission create_subscription_subpermission">
 Luoda uusia kausijulkaisutilauksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_subscription' -%]
 <span class="sub_permission delete_subscription_subpermission">
 Poistaa kausijulkaisutilauksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_subscription' -%]
 <span class="sub_permission edit_subscription_subpermission">
 Muokata kausijulkaisutilausta </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'receive_serials' -%]
 <span class="sub_permission receive_serials_subpermission">
 Ottaa vastaan kausijulkaisuja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'renew_subscription' -%]
 <span class="sub_permission renew_subscription_subpermission">
 Uusia kausijulkaisutilauksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'routing' -%]
 <span class="sub_permission routing_subpermission">
 Kierto </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'superserials' -%]
 <span class="sub_permission superserials_subpermission">
 Hallinnoida kausijulkaisutilauksia mistä tahansa kirjastosta (toimii vain, jos IndependentBranches on käytössä) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_reports' -%]
 <span class="sub_permission delete_reports_subpermission">
 Poistaa SQL-raportteja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_reports' -%]
 <span class="sub_permission create_reports_subpermission">
 Luoda SQL-raportteja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'execute_reports' -%]
 <span class="sub_permission execute_reports_subpermission">
 Ajaa SQL-raportteja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'add_reserves' -%]
 <span class="sub_permission add_reserves_subpermission">
 Lisätä kurssivarantoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_reserves' -%]
 <span class="sub_permission delete_reserves_subpermission">
 Poistaa kurssivarantoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_courses' -%]
 <span class="sub_permission manage_courses_subpermission">
 Lisätä, muokata ja poistaa kursseja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'configure' -%]
 <span class="sub_permission configure_subpermission">
 Määrittää liitännäisten asetuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage' -%]
 <span class="sub_permission manage_subpermission">
 Hallinnoida liitännäisiä (asentaa / poistaa) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'report' -%]
 <span class="sub_permission report_subpermission">
 Käyttää raporttiliitännäisiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'tool' -%]
 <span class="sub_permission tool_subpermission">
 Käytä työkaluliitännäisiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'admin' -%]
 <span class="sub_permission admin_subpermission">
 Käyttää ylläpito-liitännäisiä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_public_lists' -%]
 <span class="sub_permission create_public_lists_subpermission">
 Luoda julkisia listoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_public_lists' -%]
 <span class="sub_permission delete_public_lists_subpermission">
 Poistaa julkisia listoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_public_lists' -%]
 <span class="sub_permission edit_public_lists_subpermission">
 Muokkaa julkisia listoja (Nimi, asetukset ja käyttöoikeudet, mutta ei nimenomaisesti sisältöä) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_public_list_contents' -%]
 <span class="sub_permission edit_public_list_contents_subpermission">
 Muokata julkisten listojen sisältöjä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'use_public_lists' -%]
 <span class="sub_permission use_public_lists_subpermission">
 Käyttää julkisia listoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_general_files' -%]
 <span class="sub_permission upload_general_files_subpermission">
 Ladata mikä tahansa tiedosto </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_manage' -%]
 <span class="sub_permission upload_manage_subpermission">
 Hallinnoida ladattuja tiedostoja (<em>Hyödytön ilman oikeutta "upload_general_files"</em>)
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'access_files' -%]
 <span class="sub_permission access_files_subpermission">
 Käyttää palvelimelle tallennettuja tiedostoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_clubs' -%]
 <span class="sub_permission edit_clubs_subpermission">
 Luoda ja muokata kerhoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_templates' -%]
 <span class="sub_permission edit_templates_subpermission">
 Luoda ja muokata kerhopohjia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'enroll' -%]
 <span class="sub_permission enroll_subpermission">
 Ilmoitaa asiakkaita kerhoihin </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edi_manage' -%]
 <span class="sub_permission edi_manage_subpermission">
 Hallinnoida EDIFACT-siirtoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'marc_order_manage' -%]
 <span class="sub_permission marc_order_manage_subpermission">
 Hallinnoida MARC-tilauksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reopen_closed_invoices' -%]
 <span class="sub_permission reopen_closed_invoices_subpermission">
 Avata suljetut laskut uudelleen </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_invoices' -%]
 <span class="sub_permission edit_invoices_subpermission">
 Muokata laskuja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_invoices' -%]
 <span class="sub_permission delete_invoices_subpermission">
 Poistaa laskuja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'merge_invoices' -%]
 <span class="sub_permission merge_invoices_subpermission">
 Yhdistää laskuja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_baskets' -%]
 <span class="sub_permission delete_baskets_subpermission">
 Poistaa tilauskoreja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# self_check %]
 [%- CASE 'self_checkin_module' -%]
 <span class="sub_permission self_checkin_module_subpermission">
 Kirjautua itsepalvelupalautukseen. Huom: tämä oikeus estää asiakasta käyttämästä muita verkkokirjaston toiminnallisuuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'self_checkout_module' -%]
 <span class="sub_permission self_checkout_module_subpermission">
 Tehdä itsepalvelulainausta verkkokirjastossa. Tätä tulisi käyttää asiakkaalle, joka on määritetty AutoSelfCheckID-järjestelmäasetukseen </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_rota_items' -%]
 <span class="sub_permission manage_rota_items_subpermission">
 Lisätä ja poistaa niteitä kiertokokoelmasta </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_rotas' -%]
 <span class="sub_permission manage_rotas_subpermission">
 Lisätä, muokata ja poistaa kiertokokoelmia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# cash_management %]
 [%- CASE 'manage_cash_registers' -%]
 <span class="sub_permission manage_cash_registers_subpermission">
 Lisätä, muokata ja arkistoida kassoja </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'takepayment' -%]
 <span class="sub_permission takepayment_subpermission">
 Pääsy myyntipisteeseen ja maksujen vastaanotto </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'cashup' -%]
 <span class="sub_permission cashup_subpermission">
 Tehdä kassajärjestelmän tilitystoimet </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'anonymous_refund' -%]
 <span class="sub_permission anonymous_refund_subpermission">
 Tehdä nimettömiä maksujen palautuksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# problem_reports %]
 [%- CASE 'manage_problem_reports' -%]
 <span class="sub_permission manage_problem_reports_subpermission">
 Hallinnoida verkkokirjaston vikailmoituksia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# recalls %]
 [%- CASE 'manage_recalls' -%]
 <span class="sub_permission place_recalls_subpermission">
 Hallinnoida asiakkaiden palautuspyyntöjä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# identity_providers %]
 [%- CASE 'manage_identity_providers' -%]
 <span class="sub_permission manage_identity_providers_subpermission">
 Hallinnoi tunnistustietojen tarjoajia </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# record_sources %]
 [%- CASE 'manage_record_sources' -%]
 <span class="sub_permission manage_record_sources_subpermission">
 Hallinnoida tietuelähteitä </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- END -%]
[%- END -%]
