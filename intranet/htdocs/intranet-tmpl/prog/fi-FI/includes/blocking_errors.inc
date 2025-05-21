[% IF blocking_error %]
 [% SWITCH blocking_error %]
 [% CASE 'unknown_patron' %]
 <div class="alert alert-info">Asiakasta ei löytynyt. <a href="/cgi-bin/koha/members/members-home.pl">Palaa hakuun</a></div>
 [% CASE 'cannot_see_patron_infos' %]Ei oikeutta nähdä valitun asiakkaan tietoja. [% CASE 'unknown_biblio' %] <div class="alert alert-info">Nimeketietuetta ei löydy.</div>
 [% CASE 'unknown_item' %]
 <div class="alert alert-info">Nidettä ei löytynyt.</div>
 [% CASE 'unknown_subscription' %]
 <div class="alert alert-info">Kausijulkaisutilausta ei löytynyt.</div>
 [% CASE 'unknown_basket' %]
 <div class="alert alert-info">Tilauskoria ei löytynyt.</div>
 [% CASE 'unknown_vendor' %]
 <div class="alert alert-info">Toimittajaa ei löytynyt.</div>
 [% CASE 'unknown_ill_request' %]
 <div class="alert alert-info">Kaukolainapyyntöä ei löytynyt.</div>
 [% CASE 'order_cannot_be_edited' %]
 <div class="alert alert-info">Tätä tilausta ei voi muokata, tilauskori on suljettu tai tilaus on jo vastaanotettu.</div>
 [% CASE 'wrong_csrf_token' %]
 <div class="alert alert-info">Lomakkeen lähetys epäonnistui (väärä CSRF token). Päivitä sivu yrittääksesi uudelleen.</div>
 [% CASE 'budget_is_locked' %]
 <div class="alert alert-info">Budjetti on lukittu, tilin lisääminen ei ole mahdollista.</div>
 [% CASE 'missing_es_modules' %]
 <div class="alert alert-info">Tarpeellisia Elasticsearchin paketteja ei ole asennettu palvelimellesi. Ota yhteyttä palvelimen ylläpitäjään, jos haluat konfiguroida Elasticsearchin.</div>
 [% CASE 'insufficient_permission' %]
 <div class="alert alert-info">Sinulla ei ole riittäviä oikeuksia jatkaa.</div>
 [% CASE 'duplicate_tagfield' %]
 <div class="alert alert-info">MARC-kenttää ei lisätty MARC-kuvailupohjaan. MARC-kenttä on jo olemassa kuvailupohjassa.</div>
 [% CASE %]
 <div class="alert alert-warning">[% blocking_error | html %]</div>
 [% END %]

 [% INCLUDE 'intranet-bottom.inc' %]
 [% STOP %] [%# Will stop gracefully without processing any more of the template document.%]
[% END %]
