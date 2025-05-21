[% BLOCK translate_log_module %]
[%    SWITCH module %]
[%        CASE 'AUTH'         %]<span>Todennus</span>[% UNLESS Koha.Preference('AuthFailureLog') && Koha.Preference('AuthSuccessLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="AuthFailureLog|AuthSuccessLog" title="Lokitus ei käytössä"></i>[% END %]
[%        CASE 'CATALOGUING'  %]<span>Kuvailu</span>[% UNLESS Koha.Preference('CataloguingLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="CataloguingLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'AUTHORITIES'  %]<span>Auktoriteetit</span>[% UNLESS Koha.Preference('AuthoritiesLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="AuthoritiesLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'MEMBERS'      %]<span>Asiakkaat</span>[% UNLESS Koha.Preference('BorrowersLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="BorrowersLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'ACQUISITIONS' %]<span>Hankinnat</span>[% UNLESS Koha.Preference('AcquisitionLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="AcquisitionLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'SERIAL'       %]<span>Kausijulkaisut</span>[% UNLESS Koha.Preference('SubscriptionLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="SubscriptionLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'HOLDS'        %]<span>Varaukset</span>[% UNLESS Koha.Preference('HoldsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="HoldsLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'ILL'          %]<span>Kaukolainat</span>[% UNLESS Koha.Preference('IllLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="IllLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'CIRCULATION'  %]<span>Lainaus ja palautus</span>[% UNLESS Koha.Preference('IssueLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="IssueLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'CLAIMS'       %]<span>Reklamaatiot</span>[% UNLESS Koha.Preference('ClaimsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="ClaimsLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'FINES'        %]<span>Maksut</span>[% UNLESS Koha.Preference('FinesLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="FinesLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'SYSTEMPREFERENCE' %]<span>Järjestelmäasetukset</span>

[%        CASE 'CRONJOBS' %]<span>Ajastetut ajot</span>[% UNLESS Koha.Preference('CronjobLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="CronjobLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'REPORTS'      %]<span>Raportit</span>[% UNLESS Koha.Preference('ReportsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="ReportsLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE 'SEARCHENGINE' %]<span>Hakukone</span>

[%        CASE 'NOTICES'      %]<span>Ilmoitukset</span>[% UNLESS Koha.Preference('NoticesLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="NoticesLog" title="Lokitus ei käytössä"></i>[% END %]
[%        CASE 'NEWS'      %]<span>Uutiset</span>[% UNLESS Koha.Preference('NewsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="NewsLog" title="Lokitus ei käytössä"></i>[% END %]
[%        CASE 'RECALLS'      %]<span>Palautuspyynnöt</span>[% UNLESS Koha.Preference('RecallsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="RecallsLog" title="Lokitus ei käytössä"></i>[% END %]
[%        CASE 'SUGGESTION'      %]<span>Hankintaehdotukset</span>[% UNLESS Koha.Preference('SuggestionsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="SuggestionsLog" title="Lokitus ei käytössä"></i>[% END %]

[%        CASE %][% module | html %]
[%    END %]
[% END %]

[% BLOCK translate_log_action %]
[%    SWITCH action %]
[%        CASE 'ADD'    %]<span>Lisää</span>
[%        CASE 'DELETE' %]<span>Poista</span>
[%        CASE 'MODIFY' %]<span>Muokkaa</span>
[%        CASE 'ISSUE'  %]<span>Lainaus</span>
[%        CASE 'RETURN' %]<span>Palautus</span>
[%        CASE 'CREATE' %]<span>Luo</span>
[%        CASE 'CANCEL' %]<span>Peruuta</span>
[%        CASE 'FILL'   %]<span>Täytä</span>
[%        CASE 'RESUME' %]<span>Aktivoi</span>
[%        CASE 'SUSPEND' %]<span>Keskeytä varaus</span>
[%        CASE 'RENEW'  %]<span>Uusinta</span>
[%        CASE 'RENEWAL' %]<span>Uusinta</span>
[%        CASE 'CHANGE PASS' %]<span>Vaihda salasana</span>
[%        CASE 'RESET PASS' %]<span>Uusi salasana</span>
[%        CASE 'ADDCIRCMESSAGE' %]<span>Lisää lainaus- ja palautusviesti</span>
[%        CASE 'MODCIRCMESSAGE' %]<span>Muokkaa lainaus- ja palautusviestiä</span>
[%        CASE 'DELCIRCMESSAGE' %]<span>Poista lainaus- ja palautusviesti</span>
[%        CASE 'STATUS_CHANGE'  %]<span>Muuta kaukolainapyynnön tilaa</span>
[%        CASE 'PATRON_NOTICE'  %]<span>Kaukolainailmoitus lähetetty asiakkaalle</span>
[%        CASE 'ADD_BASKET' %]<span>Luo tilauskori</span>
[%        CASE 'MODIFY_BASKET' %]<span>Muokkaa tilauskoria</span>
[%        CASE 'MODIFY_BASKET_HEADER' %]<span>Muokkaa tilauskoria</span>
[%        CASE 'MODIFY_BASKET_USERS' %]<span>Muokkaa tilauskorin käyttäjiä</span>
[%        CASE 'CLOSE_BASKET' %]<span>Sulje tilauskori</span>
[%        CASE 'APPROVE_BASKET' %]<span>Hyväksy tilauskori</span>
[%        CASE 'REOPEN_BASKET' %]<span>Avaa tilauskori uudelleen</span>
[%        CASE 'CANCEL_ORDER' %]<span>Peruuta teoksen tilaus</span>
[%        CASE 'CREATE_ORDER' %]<span>Luo tilaus</span>
[%        CASE 'MODIFY_ORDER' %]<span>Muokkaa tilausta</span>
[%        CASE 'CREATE_INVOICE_ADJUSTMENT' %]<span>Luo laskun oikaisu</span>
[%        CASE 'UPDATE_INVOICE_ADJUSTMENT' %]<span>Muokkaa laskun oikaisua</span>
[%        CASE 'DELETE_INVOICE_ADJUSTMENT' %]<span>Poista laskun oikaisu</span>
[%        CASE 'RECEIVE_ORDER' %]<span>Vastaanota tilaus</span>
[%        CASE 'MODIFY_BUDGET' %]<span>Muokkaa budjettia</span>
[%        CASE 'CREATE_FUND' %]<span>Luo tili</span>
[%        CASE 'MODIFY_FUND' %]<span>Muokkaa tiliä</span>
[%        CASE 'DELETE_FUND' %]<span>Poista tili</span>
[%        CASE 'CREATE_RESTRICTION' %]<span>Uusi rajoitus</span>
[%        CASE 'MODIFY_RESTRICTION' %]<span>Muokkaa rajoitusta</span>
[%        CASE 'DELETE_RESTRICTION' %]<span>Poista rajoitus</span>
[%        CASE 'Run'    %]<span>Käynnistä</span>
[%        CASE 'End'    %]<span>Loppupvm</span>
[%        CASE 'EDIT_MAPPINGS' %]<span>Muokkaa määrityksiä</span>
[%        CASE 'RESET_MAPPINGS' %]<span>Nollaa määritykset</span>
[%        CASE 'SERIAL CLAIM' %]<span>Kausijulkaisureklamaatio</span>
[%        CASE 'ACQUISITION CLAIM' %]<span>Hankintavaatimus</span>
[%        CASE 'ACQUISITION ORDER' %]<span>Hankintatilaus</span>
[%        CASE 'OVERDUE' %]<span>Myöhässä</span>
[%        CASE 'EXPIRE'  %]<span>Umpeutuu</span>
[%        CASE %][% action | html %]
[%    END %]
[% END %]

[% BLOCK translate_log_interface %]
[%    SWITCH log_interface.upper %]
[%        CASE 'INTRANET'    %]<span>Virkailijaliittymä</span>
[%        CASE 'OPAC'        %]<span>OPAC</span>
[%        CASE 'SIP'         %]<span>SIP</span>
[%        CASE 'COMMANDLINE' %]<span>Komentorivi</span>
[%        CASE 'API'         %]<span>REST API</span>
[%        CASE 'CRON'        %]<span>Ajastettu ajo</span>
[%        CASE 'UPGRADE'     %]<span>Päivitys</span>
[%        CASE %]<span>[% log_interface | html %]</span>
[%    END %]
[% END %]
