[% BLOCK translate_log_module %]
[%    SWITCH module %]
[%        CASE 'AUTH'         %]<span>Autentisering</span>[% UNLESS Koha.Preference('AuthFailureLog') && Koha.Preference('AuthSuccessLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="AuthFailureLog|AuthSuccessLog" title="Logg ej aktiverad"></i>[% END %]
[%        CASE 'CATALOGUING'  %]<span>Katalogisering</span>[% UNLESS Koha.Preference('CataloguingLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="CataloguingLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'AUTHORITIES'  %]<span>Auktoriteter</span>[% UNLESS Koha.Preference('AuthoritiesLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="AuthoritiesLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'MEMBERS'      %]<span>Låntagare</span>[% UNLESS Koha.Preference('BorrowersLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="BorrowersLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'ACQUISITIONS' %]<span>Inköp</span>[% UNLESS Koha.Preference('AcquisitionLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="AcquisitionLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'SERIAL'       %]<span>Periodika</span>[% UNLESS Koha.Preference('SubscriptionLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="SubscriptionLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'HOLDS'        %]<span>Reservationer</span>[% UNLESS Koha.Preference('HoldsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="HoldsLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'ILL'          %]<span>Fjärrlån</span>[% UNLESS Koha.Preference('IllLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="IllLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'CIRCULATION'  %]<span>Cirkulation</span>[% UNLESS Koha.Preference('IssueLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="IssueLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'CLAIMS'       %]<span>Reklamationer</span>[% UNLESS Koha.Preference('ClaimsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="ClaimsLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'FINES'        %]<span>Avgifter</span>[% UNLESS Koha.Preference('FinesLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="FinesLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'SYSTEMPREFERENCE' %]<span>Systeminställningar</span>

[%        CASE 'CRONJOBS' %]<span>Cron-jobb</span>[% UNLESS Koha.Preference('CronjobLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="CronjobLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'REPORTS'      %]<span>Rapporter</span>[% UNLESS Koha.Preference('ReportsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="ReportsLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE 'SEARCHENGINE' %]<span>Sökmotor</span>

[%        CASE 'NOTICES'      %]<span>Meddelanden</span>[% UNLESS Koha.Preference('NoticesLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="NoticesLog" title="Logg ej aktiverad"></i>[% END %]
[%        CASE 'NEWS'      %]<span>Nyheter</span>[% UNLESS Koha.Preference('NewsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="NewsLog" title="Logg ej aktiverad"></i>[% END %]
[%        CASE 'RECALLS'      %]<span>Återkrav</span>[% UNLESS Koha.Preference('RecallsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="RecallsLog" title="Logg ej aktiverad"></i>[% END %]
[%        CASE 'SUGGESTION'      %]<span>Förslag</span>[% UNLESS Koha.Preference('SuggestionsLog') %] <i class="log-disabled fa-solid fa-triangle-exclamation" data-log="SuggestionsLog" title="Logg ej aktiverad"></i>[% END %]

[%        CASE %][% module | html %]
[%    END %]
[% END %]

[% BLOCK translate_log_action %]
[%    SWITCH action %]
[%        CASE 'ADD'    %]<span>Lägg till</span>
[%        CASE 'DELETE' %]<span>Ta bort</span>
[%        CASE 'MODIFY' %]<span>Redigera</span>
[%        CASE 'ISSUE'  %]<span>Utlåning</span>
[%        CASE 'RETURN' %]<span>Återlämna</span>
[%        CASE 'CREATE' %]<span>Skapa</span>
[%        CASE 'CANCEL' %]<span>Avbryt</span>
[%        CASE 'FILL'   %]<span>Uppfyll</span>
[%        CASE 'RESUME' %]<span>Återuppta</span>
[%        CASE 'SUSPEND' %]<span>Pausa</span>
[%        CASE 'RENEW'  %]<span>Låna om</span>
[%        CASE 'RENEWAL' %]<span>Låna om</span>
[%        CASE 'CHANGE PASS' %]<span>Byt lösenord</span>
[%        CASE 'RESET PASS' %]<span>Återställ lösenord</span>
[%        CASE 'ADDCIRCMESSAGE' %]<span>Lägg till cirkulationsmeddelande</span>
[%        CASE 'MODCIRCMESSAGE' %]<span>Ändra cirkulationsmeddelande</span>
[%        CASE 'DELCIRCMESSAGE' %]<span>Ta bort cirkulationsmeddelande</span>
[%        CASE 'STATUS_CHANGE'  %]<span>Ändra status för fjärrlånebeställning</span>
[%        CASE 'PATRON_NOTICE'  %]<span>Fjärrlånemeddelande skickat till låntagare</span>
[%        CASE 'ADD_BASKET' %]<span>Skapa en inköpskorg</span>
[%        CASE 'MODIFY_BASKET' %]<span>Redigera en inköpskorg</span>
[%        CASE 'MODIFY_BASKET_HEADER' %]<span>Redigera rubrik för en inköpskorg</span>
[%        CASE 'MODIFY_BASKET_USERS' %]<span>Redigera användarna av en inköpskorg</span>
[%        CASE 'CLOSE_BASKET' %]<span>Stäng en inköpskorg</span>
[%        CASE 'APPROVE_BASKET' %]<span>Godkänn en inköpskorg</span>
[%        CASE 'REOPEN_BASKET' %]<span>Öppna om en inköpskorg</span>
[%        CASE 'CANCEL_ORDER' %]<span>Avbryt beställning</span>
[%        CASE 'CREATE_ORDER' %]<span>Skapa en order</span>
[%        CASE 'MODIFY_ORDER' %]<span>Redigera en beställning</span>
[%        CASE 'CREATE_INVOICE_ADJUSTMENT' %]<span>Skapa en fakturajustering</span>
[%        CASE 'UPDATE_INVOICE_ADJUSTMENT' %]<span>Redigera en fakturajustering</span>
[%        CASE 'DELETE_INVOICE_ADJUSTMENT' %]<span>Ta bort en fakturajustering</span>
[%        CASE 'RECEIVE_ORDER' %]<span>Ta emot en beställning</span>
[%        CASE 'MODIFY_BUDGET' %]<span>Redigera budget</span>
[%        CASE 'CREATE_FUND' %]<span>Skapa ett nytt budgetställe</span>
[%        CASE 'MODIFY_FUND' %]<span>Redigera ett budgetställe</span>
[%        CASE 'DELETE_FUND' %]<span>Ta bort budgetställe</span>
[%        CASE 'CREATE_RESTRICTION' %]<span>Skapa begränsning</span>
[%        CASE 'MODIFY_RESTRICTION' %]<span>Ändra begränsning</span>
[%        CASE 'DELETE_RESTRICTION' %]<span>Ta bort begränsning</span>
[%        CASE 'Run'    %]<span>Kör</span>
[%        CASE 'End'    %]<span>Avsluta</span>
[%        CASE 'EDIT_MAPPINGS' %]<span>Redigera mappningar</span>
[%        CASE 'RESET_MAPPINGS' %]<span>Återställ mappningar</span>
[%        CASE 'SERIAL CLAIM' %]<span>Reklamationer för periodika</span>
[%        CASE 'ACQUISITION CLAIM' %]<span>Inköpsreklamation</span>
[%        CASE 'ACQUISITION ORDER' %]<span>Inköpsbeställning</span>
[%        CASE 'OVERDUE' %]<span>Försenad</span>
[%        CASE 'EXPIRE'  %]<span>Utgår</span>
[%        CASE %][% action | html %]
[%    END %]
[% END %]

[% BLOCK translate_log_interface %]
[%    SWITCH log_interface.upper %]
[%        CASE 'INTRANET'    %]<span>Personalgränssnitt</span>
[%        CASE 'OPAC'        %]<span>OPAC</span>
[%        CASE 'SIP'         %]<span>SIP</span>
[%        CASE 'COMMANDLINE' %]<span>Kommandorad</span>
[%        CASE 'API'         %]<span>REST-API</span>
[%        CASE 'CRON'        %]<span>Cron-jobb</span>
[%        CASE 'UPGRADE'     %]<span>Uppgradera</span>
[%        CASE %]<span>[% log_interface | html %]</span>
[%    END %]
[% END %]
