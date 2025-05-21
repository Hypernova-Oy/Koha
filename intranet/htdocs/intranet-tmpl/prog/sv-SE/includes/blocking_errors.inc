[% IF blocking_error %]
 [% SWITCH blocking_error %]
 [% CASE 'unknown_patron' %]
 <div class="alert alert-info">Låntagare hittades inte. <a href="/cgi-bin/koha/members/members-home.pl">Återgå till sökning</a></div>
 [% CASE 'cannot_see_patron_infos' %]Den begärda låntagarinformationen kan inte visas för detta kontot. [% CASE 'unknown_biblio' %] <div class="alert alert-info">Bibliografisk post ej funnen.</div>
 [% CASE 'unknown_item' %]
 <div class="alert alert-info">Exemplaret hittas inte.</div>
 [% CASE 'unknown_subscription' %]
 <div class="alert alert-info">Prenumerationen hittas inte.</div>
 [% CASE 'unknown_basket' %]
 <div class="alert alert-info">Korg hittades inte.</div>
 [% CASE 'unknown_vendor' %]
 <div class="alert alert-info">Leverantör hittades inte.</div>
 [% CASE 'unknown_ill_request' %]
 <div class="alert alert-info">Fjärrlånebeställning hittades inte.</div>
 [% CASE 'order_cannot_be_edited' %]
 <div class="alert alert-info">Ordern kan inte redigeras, korgen är stängd eller så är leveransen redan mottagen.</div>
 [% CASE 'wrong_csrf_token' %]
 <div class="alert alert-info">Det gick inte att skicka formuläret (fel CSRF-token). Försök att gå tillbaka, uppdatera sidan och försök sedan igen.</div>
 [% CASE 'budget_is_locked' %]
 <div class="alert alert-info">Budgeten är låst, så det går inte att skapa budgetställe.</div>
 [% CASE 'missing_es_modules' %]
 <div class="alert alert-info">Nödvändiga Elasticsearch-paket är inte installerade på din server. Kontakta din serveradministratör om du önskar konfigurera Elasticsearch.</div>
 [% CASE 'insufficient_permission' %]
 <div class="alert alert-info">Du har inte behörighet att fortsätta.</div>
 [% CASE 'duplicate_tagfield' %]
 <div class="alert alert-info">MARC-fältet lades inte till i det bibliografiska MARC-ramverket. MARC-taggen finns redan i ramverket.</div>
 [% CASE %]
 <div class="alert alert-warning">[% blocking_error | html %]</div>
 [% END %]

 [% INCLUDE 'intranet-bottom.inc' %]
 [% STOP %] [%# Will stop gracefully without processing any more of the template document.%]
[% END %]
