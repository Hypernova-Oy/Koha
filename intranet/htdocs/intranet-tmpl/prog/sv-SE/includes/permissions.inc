[%- BLOCK main_permissions -%]
 [% SWITCH name %]
 [%- CASE 'superlibrarian' -%]
 <span class="main_permission superlibrarian_permission">Åtkomst till alla bibliotekariefunktioner</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'circulate' -%]
 <span class="main_permission circulate_permission">Låna ut och återlämna exemplar</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'catalogue' -%]
 <span class="main_permission catalogue_permission">Personalåtkomst, gör att katalogen kan ses i personalklienten</span>
 <span class="permissioncode">([% name | html %])</span> <span class="required">Krävs för personalinloggning.</span>
 [%- CASE 'parameters' -%]
 <span class="main_permission parameters_permission">Hantera systeminställningar för Koha (administrationspanelen)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'borrowers' -%]
 <span class="main_permission borrowers_permission">Lägg till, ändra och se låntagarinformation</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'permissions' -%]
 <span class="main_permission permissions_permission">Ställ in användarrättigheter</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reserveforothers' -%]
 <span class="main_permission reserveforothers_permission">Reservera och ändra reservationer för låntagare</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'editcatalogue' -%]
 <span class="main_permission editcatalogue_permission">Redigera katalog (Redigera data för bibpost/exemplar)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'updatecharges' -%]
 <span class="main_permission updatecharges_permission">Hantera avgifter för låntagare</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'acquisition' -%]
 <span class="main_permission acquisition_permission">Inköpshantering</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions' -%]
 <span class="main_permission suggestions_permission">Förslagshantering</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'tools' -%]
 <span class="main_permission tools_permission">Använd alla verktyg (expandera för inställning per verktyg)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'editauthorities' -%]
 <span class="main_permission editauthorities_permission">Redigera auktoriteter</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'serials' -%]
 <span class="main_permission serials_permission">Hantera prenumerationer för periodika</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reports' -%]
 <span class="main_permission reports_permission">Tillåt åtkomst till rapportmodulen</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'staffaccess' -%]
 <span class="main_permission staffaccess_permission">Tillåt personal att ändra rättigheterna för annan personal, användarnamn, och lösenord för annan personal</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'coursereserves' -%]
 <span class="main_permission coursereserves_permission">Kurslistor</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'plugins' -%]
 <span class="main_permission plugins_permission">Koha-plugins</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'lists' -%]
 <span class="main_permission lists_permission">Listor</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'clubs' -%]
 <span class="main_permission clubs_permission">Låntagarklubbar</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'ill' -%]
 <span class="main_permission ill_permission">Skapa och redigera fjärrlånebeställningar</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'self_check' -%]
 <span class="main_permission self_check_permission">Självbetjäningsmoduler</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'stockrotation' -%]
 <span class="main_permission self_check_permission">Hantera roterande samlingar</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'cash_management' -%]
 <span class="main_permission cash_management_permission">Kontanthantering</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'problem_reports' -%]
 <span class="main_permission problem_reports_permission">Hantering av OPAC-problemrapporter</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'recalls' -%]
 <span class="main_permission recalls_permission">Återkrav</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'erm' -%]
 <span class="main_permission erm_permission">Hantera modulen för elektroniska resurser</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'loggedinlibrary' -%]
 <span class="main_permission loggedinlibrary_permission">Tillåt personal att ändra inloggat bibliotek</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'preservation' -%]
 <span class="main_permission preservation_permission">Hantera bokvårdsmodulen</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- END -%]
[%- END -%]

[%- BLOCK sub_permissions -%]
 [% SWITCH name %]
 [%- CASE 'circulate_remaining_permissions' -%]
 <span class="sub_permission circulate_remaining_permissions_subpermission">
 Kvarvarande lånerättigheter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'force_checkout' -%]
 <span class="sub_permission force_checkout_subpermission">
 Tvinga utlåning om begränsning finns </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_restrictions' -%]
 <span class="sub_permission manage_restrictions_subpermission">
 Hantera begränsningar för konton </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'overdues_report' -%]
 <span class="sub_permission overdues_report_subpermission">
 Köra rapport för försenade exemplar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'override_renewals' -%]
 <span class="sub_permission override_renewals_subpermission">
 Åsidosätt blockerade omlån </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_bookings' %]
 <span class="sub_permission manage_bookings_subpermission">
 Hantera exemplarsbokningar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_checkout_notes' %]
 <span class="sub_permission manage_checkout_notes_subpermission">
 Markera utlåningsmeddelande som läst/inte läst </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_accounts' -%]
 <span class="sub_permission manage_accounts_subpermission">
 Administrera konto debit- och kredittyper </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules' -%]
 <span class="sub_permission manage_circ_rules_subpermission">
 Hantera låneregler </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules_from_any_libraries' -%]
 <span class="sub_permission manage_circ_rules_from_any_libraries_subpermission">
 Hantera låneregler för alla bibliotek. Om inte valt kan inloggad användare endast redigera låneregler för det egna biblioteket (observera att manage_circ_rules rättigheter fortfarande krävs) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'parameters_remaining_permissions' -%]
 <span class="sub_permission parameters_remaining_permissions_subpermission">
 Kvarvarande rättigheter för systemparametrar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules' -%]
 <span class="sub_permission manage_circ_rules_subpermission">
 Hantera låneregler </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_sysprefs' -%]
 <span class="sub_permission manage_sysprefs_subpermission">
 Hantera systeminställningar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_libraries' -%]
 <span class="sub_permission manage_libraries_subpermission">
 Hantera bibliotek och biblioteksgrupper </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_itemtypes' -%]
 <span class="sub_permission manage_itemtypes_subpermission">
 Hantera exemplartyper </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_auth_values' -%]
 <span class="sub_permission manage_auth_values_subpermission">
 Hantera auktoriserade värden och dess kategorier </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_categories' -%]
 <span class="sub_permission manage_patron_categories_subpermission">
 Hantera låntagarkategorier </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_restrictions' -%]
 <span class="sub_permission manage_patron_restrictions_subpermission">
 Hantera låntagarbegränsningar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_attributes' -%]
 <span class="sub_permission manage_patron_attributes_subpermission">
 Hantera utökade låntagarattribut </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_transfers' -%]
 <span class="sub_permission manage_transfers_subpermission">
 Hantera överföringsbegränsningar för bibliotek och fraktkostnadstabell </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_circ_alerts' -%]
 <span class="sub_permission manage_item_circ_alerts_subpermission">
 Hantera lånenotifikationer för exemplar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_cities' -%]
 <span class="sub_permission manage_cities_subpermission">
 Hantera orter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_marc_frameworks' -%]
 <span class="sub_permission manage_marc_frameworks_subpermission">
 Hantera MARC bibliografiskt och auktoritetsramverk samt testning av dem </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_classifications' -%]
 <span class="sub_permission manage_classifications_subpermission">
 Hantera klassificeringskällor och klassificeringsregler </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_matching_rules' -%]
 <span class="sub_permission manage_matching_rules_subpermission">
 Hantera regler för postmatchning </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_oai_sets' -%]
 <span class="sub_permission manage_oai_sets_subpermission">
 Hantera OAI-uppsättningar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_search_fields' -%]
 <span class="sub_permission manage_item_search_fields_subpermission">
 Hantera exemplarsökfält </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_filters' -%]
 <span class="sub_permission manage_search_filters_subpermission">
 Hantera sparade sökfilter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_engine_config' -%]
 <span class="sub_permission manage_search_engine_config_subpermission">
 Hantera inställningar för sökmotor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_marc_overlay_rules' -%]
 <span class="sub_permission manage_marc_overlay_rules_subpermission">
 Hantera konfiguration för regler för överskrivning av MARC-fält </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_targets' -%]
 <span class="sub_permission manage_search_targets_subpermission">
 Manage Z39.50 and SRU servers, OAI repositories configuration
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_didyoumean' -%]
 <span class="sub_permission manage_didyoumean_subpermission">
 Hantera inställningar för Menade du? </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_smtp_servers' -%]
 <span class="sub_permission manage_manage_smtp_servers_subpermission">
 Hantera SMTP-servrar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_column_config' -%]
 <span class="sub_permission manage_column_config_subpermission">
 Hantera kolumnkonfiguration </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_audio_alerts' -%]
 <span class="sub_permission manage_audio_alerts_subpermission">
 Hantera ljudnotifikationer </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_additional_fields' -%]
 <span class="sub_permission manage_aditional_fields_subpermission">
 Hantera extra fält (kräver rättigheter för någon av följande (under updatecharges): edit_subscription, order_manage, edit_invoices, eller remaining_permissions) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_sms_providers' -%]
 <span class="sub_permission manage_sms_providers_subpermission">
 Hantera SMS-leverantörer </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_usage_stats' -%]
 <span class="sub_permission manage_usage_stats_subpermission">
 Hantera inställningar för användarstatistik </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_mana' -%]
 <span class="sub_permission manage_mana_subpermission">
 Hantera delning av innehåll i Mana KB </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_keyboard_shortcuts' -%]
 <span class="sub_permission manage_keyboard_shortcuts_subpermission">
 Hantera tangentbordsgenvägar för den avancerade katalogredigeraren </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_background_jobs' -%]
 <span class="sub_permission manage_background_jobs_subpermission">
 Hantera bakgrundsjobb </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_curbside_pickups' -%]
 <span class="sub_permission manage_curbside_pickups_subpermission">
 Hantera upphämtningar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_borrowers' -%]
 <span class="sub_permission delete_borrowers_subpermission">
 Ta bort låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_borrowers' -%]
 <span class="sub_permission edit_borrowers_subpermission">
 Lägg till, ändra och se låntagarinformation </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'list_borrowers' -%]
 <span class="sub_permission list_borrowers_subpermission">
 Sök, lista och visa låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'view_borrower_infos_from_any_libraries' -%]
 <span class="sub_permission view_borrower_infos_from_any_libraries_subpermission">
 Visa låntagarinformation från alla bibliotek. Om ej inställt får den inloggade användaren enbart tillgång till låntagarinformation från sitt eget bibliotek eller biblioteksgrupp. </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'send_messages_to_borrowers' -%]
 <span class="sub_permission send_messages_to_borrowers_subpermission">
 Skicka meddelanden till låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'modify_holds_priority' -%]
 <span class="sub_permission modify_holds_priority_subpermission">
 Redigera reservationsprioritet </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'place_holds' -%]
 <span class="sub_permission place_holds_subpermission">
 Reservera för låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_all_items' -%]
 <span class="sub_permission delete_all_items_subpermission">
 Ta bort alla exemplar på en gång </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_catalogue' -%]
 <span class="sub_permission edit_catalogue_subpermission">
 Redigera katalog (Ändra data för bibpost/exemplar) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_locked_records' -%]
 <span class="sub_permission edit_locked_records_subpermission">
 Redigera låsta poster </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'set_record_sources' -%]
 <span class="sub_permission set_record_sources_subpermission">
 Ställ in källa till post </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'advanced_editor' -%]
 <span class="sub_permission advanced_editor_subpermission">
 Använd den avancerade katalogiseringsredigeraren (kräver edit_catalogue) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_shared_macros' -%]
 <span class="sub_permission create_shared_macros_subpermission">
 Skapa delade makron (kräver avancerad redigerare) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_shared_macros' -%]
 <span class="sub_permission delete_shared_macros_subpermission">
 Ta bort delade makron (kräver avancerad redigerare) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_items' -%]
 <span class="sub_permission edit_items_subpermission">
 Redigera exemplar (exkluderar exemplar som begränsas av biblioteksgrupp) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_any_item' -%]
 <span class="sub_permission edit_items_subpermission">
 Redigera vilket exemplar som helt, inklusive exemplar som annars skulle vara begränsade </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_items_restricted' -%]
 <span class="sub_permission edit_items_restricted_subpermission">
 Begränsa redigering av exemplar till delfält definierade i inställningen SubfieldsToAllowForRestrictedEditing (Obs! edit_item krävs fortfarande) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'fast_cataloging' -%]
 <span class="sub_permission fast_cataloging_subpermission">
 Snabb katalogisering </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_groups' -%]
 <span class="sub_permission manage_item_groups_subpermission">
 Skapa, uppdatera och ta bort exemplargrupper, lägg till eller ta bort exemplar från en exemplargrupp </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_editor_templates' -%]
 <span class="sub_permission manage_item_editor_templates_subpermission">
 Skapa, uppdatera och ta bort redigeringsmallar som ägs av andra </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'remaining_permissions' -%]
 <span class="sub_permission remaining_permissions_subpermission">
 Kvarvarande rättigheter för att hantera avgifter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'discount' -%]
 <span class="sub_permission discount_subpermission">
 Rabattdebiteringar för låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'payout' -%]
 <span class="sub_permission payout_subpermission">
 Utbetalningskrediter till låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'refund' -%]
 <span class="sub_permission refund_subpermission">
 Återbetalningar till låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'writeoff' -%]
 <span class="sub_permission writeoff_subpermission">
 Avskriv avgifter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manual_invoice' -%]
 <span class="sub_permission manual_invoice_subpermission">
 Lägg till manuell faktura till låntagarens konto </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manual_credit' -%]
 <span class="sub_permission manual_credit_subpermission">
 Lägga till kredit manuellt på låntagarkonto </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions_create' -%]
 <span class="sub_permission suggestions_create_subpermission">
 Skapa inköpsförslag </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions_manage' -%]
 <span class="sub_permission suggestions_manage_subpermission">
 Redigera inköpsförslag </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions_delete' -%]
 <span class="sub_permission suggestions_delete_subpermission">
 Ta bort inköpsförslag </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_add_del' -%]
 <span class="sub_permission budget_add_del_subpermission">
 Lägg till och ta bort budgetar (men kan inte redigera budgetar) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_manage' -%]
 <span class="sub_permission budget_manage_subpermission">
 Hantera budgetställen </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_manage_all' -%]
 <span class="sub_permission budget_manage_all_subpermission">
 Hantera alla budgetställen </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_modify' -%]
 <span class="sub_permission budget_modify_subpermission">
 Modifiera budgetställe (kan inte skapa rader, men kan redigera befintliga) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'contracts_manage' -%]
 <span class="sub_permission contracts_manage_subpermission">
 Hantera avtal </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'group_manage' -%]
 <span class="sub_permission group_manage_subpermission">
 Hantera korggrupper </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_manage' -%]
 <span class="sub_permission order_manage_subpermission">
 Hantera korgar och orderrader </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_manage_all' -%]
 <span class="sub_permission order_manage_all_subpermission">
 Hantera beställningar och korgar, oavsett deras begränsningar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'issue_manage' -%]
 <span class="sub_permission issue_manage_subpermission">
 Hantera leverantörsärenden </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_receive' -%]
 <span class="sub_permission order_receive_subpermission">
 Ta emot beställningar och hantera leveranser </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'period_manage' -%]
 <span class="sub_permission period_manage_subpermission">
 Hantera budgetar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'planning_manage' -%]
 <span class="sub_permission planning_manage_subpermission">
 Hantera budgetplanering </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'vendors_manage' -%]
 <span class="sub_permission vendors_manage_subpermission">
 Hantera leverantörer </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'currencies_manage' -%]
 <span class="sub_permission currencies_manage_subpermission">
 Hantera valutor och växlingskurser </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'batch_upload_patron_images' -%]
 <span class="sub_permission batch_upload_patron_images_subpermission">
 Ladda upp låntagarbilder satsvis eller ett i taget </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_anonymize_patrons' -%]
 <span class="sub_permission delete_anonymize_patrons_subpermission">
 Ta bort gamla låntagare och anonymisera lånehistorik (tar bort låntagarens lånehistorik) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'batch_extend_due_dates' -%]
 <span class="sub_permission batch_extend_due_dates_subpermission">
 Utför satsvis förlängning av förfallodatum </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_calendar' -%]
 <span class="sub_permission edit_calendar_subpermission">
 Ange dagar då biblioteket är stängt </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_additional_contents' -%]
 <span class="sub_permission edit_additional_contents_subpermission">
 Skriv ytterligare innehåll för katalogen och personalgränssnittet (nyheter och HTML-anpassningar) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_notice_status_triggers' -%]
 <span class="sub_permission edit_notice_status_triggers_subpermission">
 Ställ in utlösare för meddelanden/status för försenade exemplar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_notices' -%]
 <span class="sub_permission edit_notices_subpermission">
 Definiera meddelanden </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_patrons' -%]
 <span class="sub_permission edit_patrons_subpermission">
 Utför satsvis redigering av låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_quotes' -%]
 <span class="sub_permission edit_quotes_subpermission">
 Redigera citat för funktionen Dagens citat </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'export_catalog' -%]
 <span class="sub_permission export_catalog_subpermission">
 Exportera bibliografiska data och reservationsdata </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'import_patrons' -%]
 <span class="sub_permission import_patrons_subpermission">
 Importera låntagardata </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'inventory' -%]
 <span class="sub_permission inventory_subpermission">
 Utför inventering av katalogen </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchdel' -%]
 <span class="sub_permission items_batchdel_subpermission">
 Utför satsvis borttagning av exemplar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchmod' -%]
 <span class="sub_permission items_batchmod_subpermission">
 Utför satsvis redigering av exemplar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchmod_restricted' -%]
 <span class="sub_permission items_batchmod_restricted_subpermission">
 Begränsa satsvis rmodifiering av exemplar till delfält definierade i inställningen SubfieldsToAllowForRestrictedBatchmod (Obs! items_batchmod krävs fortfarande) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'label_creator' -%]
 <span class="sub_permission label_creator_subpermission">
 Skapa utskrivbara etiketter och streckkoder från katalog- och låntagardata </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_csv_profiles' -%]
 <span class="sub_permission manage_csv_profiles_subpermission">
 Hantera exportprofiler för CSV </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_lists' -%]
 <span class="sub_permission manage_patron_lists_subpermission">
 Lägg till, redigera och ta bort låntagarlistor och dess innehåll </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_staged_marc' -%]
 <span class="sub_permission manage_staged_marc_subpermission">
 Hanterade förberedda MARC-poster, inklusive slutföra och ångra importer </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'marc_modification_templates' -%]
 <span class="sub_permission marc_modification_templates_subpermission">
 Hantera mallar för marc-redigering </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'moderate_comments' -%]
 <span class="sub_permission moderate_comments_subpermission">
 Hantera låntagarkommentarer </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'moderate_tags' -%]
 <span class="sub_permission moderate_tags_subpermission">
 Hantera låntagartaggar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'records_batchdel' -%]
 <span class="sub_permission records_batchdel_subpermission">
 Utför satsvis borttagning av poster (bibliografisk eller auktoritet) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'records_batchmod' -%]
 <span class="sub_permission records_batchmod_subpermission">
 Utför satsvis redigering av poster (bibliografisk eller auktoritet) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'rotating_collections' -%]
 <span class="sub_permission rotating_collections_subpermission">
 Hantera roterande samlingar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'schedule_tasks' -%]
 <span class="sub_permission schedule_tasks_subpermission">
 Schemalägg uppgifter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'stage_marc_import' -%]
 <span class="sub_permission stage_marc_import_subpermission">
 Förbered MARC-poster i reservoaren </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_local_cover_images' -%]
 <span class="sub_permission upload_local_cover_images_subpermission">
 Ladda upp lokala omslagsbilder </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'view_system_logs' -%]
 <span class="sub_permission view_system_logs_subpermission">
 Bläddra i systemloggarna </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'check_expiration' -%]
 <span class="sub_permission check_expiration_subpermission">
 Kontrollera utgångsdatum för periodika </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'claim_serials' -%]
 <span class="sub_permission claim_serials_subpermission">
 Reklamera saknade nummer av periodika </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_subscription' -%]
 <span class="sub_permission create_subscription_subpermission">
 Påbörja en ny prenumeration </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_subscription' -%]
 <span class="sub_permission delete_subscription_subpermission">
 Ta bort en befintlig prenumeration </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_subscription' -%]
 <span class="sub_permission edit_subscription_subpermission">
 Redigera en befintlig prenumeration </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'receive_serials' -%]
 <span class="sub_permission receive_serials_subpermission">
 Ta emot periodika </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'renew_subscription' -%]
 <span class="sub_permission renew_subscription_subpermission">
 Förnya en prenumeration </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'routing' -%]
 <span class="sub_permission routing_subpermission">
 Mottagarlista </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'superserials' -%]
 <span class="sub_permission superserials_subpermission">
 Hantera prenumerationer oavsett bibliotek (gäller endast när IndependentBranches används) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_reports' -%]
 <span class="sub_permission delete_reports_subpermission">
 Ta bort SQL-rapporter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_reports' -%]
 <span class="sub_permission create_reports_subpermission">
 Skapa SQL-rapporter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'execute_reports' -%]
 <span class="sub_permission execute_reports_subpermission">
 Kör SQL-rapporter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'add_reserves' -%]
 <span class="sub_permission add_reserves_subpermission">
 Lägg till kurslistor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_reserves' -%]
 <span class="sub_permission delete_reserves_subpermission">
 Ta bort kurslistor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_courses' -%]
 <span class="sub_permission manage_courses_subpermission">
 Lägg till, redigera och ta bort kurser </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'configure' -%]
 <span class="sub_permission configure_subpermission">
 Konfigurera plugins </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage' -%]
 <span class="sub_permission manage_subpermission">
 Hantera plugins (installera/avinstallera) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'report' -%]
 <span class="sub_permission report_subpermission">
 Använd insticksprogram för rapporter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'tool' -%]
 <span class="sub_permission tool_subpermission">
 Använd insticksprogram för verktyg </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'admin' -%]
 <span class="sub_permission admin_subpermission">
 Använda administrativa insticksprogram </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_public_lists' -%]
 <span class="sub_permission create_public_lists_subpermission">
 Skapa offentliga listor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_public_lists' -%]
 <span class="sub_permission delete_public_lists_subpermission">
 Ta bort offentliga listor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_public_lists' -%]
 <span class="sub_permission edit_public_lists_subpermission">
 Redigera offentliga listor (Namn, inställningar och rättigheter, men inte explicit innehåll) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_public_list_contents' -%]
 <span class="sub_permission edit_public_list_contents_subpermission">
 Redigera innehåll i publika listor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'use_public_lists' -%]
 <span class="sub_permission use_public_lists_subpermission">
 Använd offentliga listor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_general_files' -%]
 <span class="sub_permission upload_general_files_subpermission">
 Ladda upp valfri fil </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_manage' -%]
 <span class="sub_permission upload_manage_subpermission">
 Hantera uppladdade filer (<em>Oanvändbar utan upload_general_files</em>)
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'access_files' -%]
 <span class="sub_permission access_files_subpermission">
 Tillgång till de filer som finns lagrade på servern </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_clubs' -%]
 <span class="sub_permission edit_clubs_subpermission">
 Skapa och redigera klubbar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_templates' -%]
 <span class="sub_permission edit_templates_subpermission">
 Skapa och redigera klubbmallar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'enroll' -%]
 <span class="sub_permission enroll_subpermission">
 Registrera låntagare i klubbar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edi_manage' -%]
 <span class="sub_permission edi_manage_subpermission">
 Hantera EDIFACT-sändningar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'marc_order_manage' -%]
 <span class="sub_permission marc_order_manage_subpermission">
 Manage MARC ordering
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reopen_closed_invoices' -%]
 <span class="sub_permission reopen_closed_invoices_subpermission">
 Öppna stängda fakturor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_invoices' -%]
 <span class="sub_permission edit_invoices_subpermission">
 Redigera fakturor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_invoices' -%]
 <span class="sub_permission delete_invoices_subpermission">
 Ta bort fakturor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'merge_invoices' -%]
 <span class="sub_permission merge_invoices_subpermission">
 Slå samman fakturor </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_baskets' -%]
 <span class="sub_permission delete_baskets_subpermission">
 Ta bort korgar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# self_check %]
 [%- CASE 'self_checkin_module' -%]
 <span class="sub_permission self_checkin_module_subpermission">
 Logga in i självbetjäningsmodulen. Obs: detta tillstånd hindrar låntagaren från att använda någon annan OPAC-funktionalitet </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'self_checkout_module' -%]
 <span class="sub_permission self_checkout_module_subpermission">
 Utför självutlåning i OPAC. Ska användas för låntagarmatchning av AutoSelfCheckID </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_rota_items' -%]
 <span class="sub_permission manage_rota_items_subpermission">
 Lägg till och ta bort exemplar från rotationsschema </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_rotas' -%]
 <span class="sub_permission manage_rotas_subpermission">
 Skapa, redigera och radera rotationsscheman </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# cash_management %]
 [%- CASE 'manage_cash_registers' -%]
 <span class="sub_permission manage_cash_registers_subpermission">
 Lägg till, redigera och ta bort kassaregister </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'takepayment' -%]
 <span class="sub_permission takepayment_subpermission">
 Gå till försäljningsställets sida och ta emot betalningar </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'cashup' -%]
 <span class="sub_permission cashup_subpermission">
 Utför kassaregisteråtgärd </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'anonymous_refund' -%]
 <span class="sub_permission anonymous_refund_subpermission">
 Utföra anonyma återbetalningsåtgärder </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# problem_reports %]
 [%- CASE 'manage_problem_reports' -%]
 <span class="sub_permission manage_problem_reports_subpermission">
 Hantera OPAC-problemrapporter </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# recalls %]
 [%- CASE 'manage_recalls' -%]
 <span class="sub_permission place_recalls_subpermission">
 Hantera återkrav för låntagare </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# identity_providers %]
 [%- CASE 'manage_identity_providers' -%]
 <span class="sub_permission manage_identity_providers_subpermission">
 Hantera identitetsleverantörer </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# record_sources %]
 [%- CASE 'manage_record_sources' -%]
 <span class="sub_permission manage_record_sources_subpermission">
 Hantera källor för poster </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- END -%]
[%- END -%]
