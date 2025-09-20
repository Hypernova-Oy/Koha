[% FOR m IN messages %]
 [% SWITCH m.code %]
 [% CASE 'success_on_insert_library' %]
 <div class="alert alert-success">Kirjasto luotu</div>
 [% CASE 'error_on_insert_library' %]
 <div class="alert alert-danger">Kirjasto on jo olemassa eikä sitä voi muokata.</div>
 [% CASE 'success_on_insert_category' %]
 <div class="alert alert-success">Asiakastyyppi luotu</div>
 [% CASE 'error_on_insert_category' %]
 <div class="alert alert-danger">Asiakastyyppi on jo olemassa ja sitä ei voi muokata.</div>
 [% CASE 'success_on_insert_patron' %]
 <div class="alert alert-success">Ylläpitäjätunnus luotu.</div>
 [% CASE 'error_on_insert_patron' %]
 <div class="alert alert-danger">Asiakasta ei lisätty. Kirjastokortin numero tai käyttäjätunnus ovat jo olemassa.</div>
 [% CASE 'ERROR_cardnumber_already_exists' %]
 <div class="alert alert-danger">Kirjastokortin numero on jo käytössä.</div>
 [% CASE 'ERROR_cardnumber_length' %]
 <div class="alert alert-danger">Kirjastokortin numeron pituus on epäkelpo.</div>
 [% CASE 'ERROR_password_mismatch' %]
 <div class="alert alert-danger">Salasanat eivät täsmää.</div>
 [% CASE 'success_on_insert_itemtype' %]
 <div class="alert alert-success">Uusi nidetyyppi luotu!</div>
 [% CASE 'error_on_insert_itemtype' %]
 <div class="alert alert-danger">Nidetyyppi on jo olemassa!</div>
 [% CASE 'success_on_insert_circ_rule' %]
 <div class="alert alert-success">Lainaussääntö luotu</div>
 [% CASE 'error_on_insert_circ_rule' %]
 <div class="alert alert-danger">Lainaussääntöä ei luotu</div>
 [% CASE 'ERROR_password_too_short' %]
 <div class="alert alert-danger">Asiakasta ei lisätty, koska salasana on liian lyhyt</div>
 [% CASE 'ERROR_password_too_weak' %]
 <div class="alert alert-danger">Asiakastietoa ei ole luotu liian heikon salasanan takia. Salasanassa on oltava vähintään yksi iso ja yksi pieni kirjain sekä yksi numero</div>
 [% CASE 'ERROR_password_has_whitespaces' %]
 <div class="alert alert-danger">Asiakasta ei lisätty, koska salasana sisältää tyhjiä merkkejä</div>
 [% CASE %][% message | html %]
 [% END %]
[% END %]
