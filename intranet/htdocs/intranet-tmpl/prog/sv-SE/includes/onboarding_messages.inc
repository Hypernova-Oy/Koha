[% FOR m IN messages %]
 [% SWITCH m.code %]
 [% CASE 'success_on_insert_library' %]
 <div class="alert alert-success">Bibliotek skapat!</div>
 [% CASE 'error_on_insert_library' %]
 <div class="alert alert-danger">Biblioteket finns redan och kan inte ändras!</div>
 [% CASE 'success_on_insert_category' %]
 <div class="alert alert-success">Låntagarkategori skapad!</div>
 [% CASE 'error_on_insert_category' %]
 <div class="alert alert-danger">Låntagarkategori finns redan och kan inte redigeras!</div>
 [% CASE 'success_on_insert_patron' %]
 <div class="alert alert-success">Administratörskonto skapat!</div>
 [% CASE 'error_on_insert_patron' %]
 <div class="alert alert-danger">Låntagaren skapades inte. Lånekortsnummer eller användarnamn finns redan.</div>
 [% CASE 'ERROR_cardnumber_already_exists' %]
 <div class="alert alert-danger">Kortnummer upptaget.</div>
 [% CASE 'ERROR_cardnumber_length' %]
 <div class="alert alert-danger">Kortnummerlängd är felaktig.</div>
 [% CASE 'ERROR_password_mismatch' %]
 <div class="alert alert-danger">Lösenorden är olika.</div>
 [% CASE 'success_on_insert_itemtype' %]
 <div class="alert alert-success">Ny exemplartyp skapad!</div>
 [% CASE 'error_on_insert_itemtype' %]
 <div class="alert alert-danger">Exemplartyp finns redan!</div>
 [% CASE 'success_on_insert_circ_rule' %]
 <div class="alert alert-success">Cirkulationsregel skapad!</div>
 [% CASE 'error_on_insert_circ_rule' %]
 <div class="alert alert-danger">Cirkulationsregel ej skapad!</div>
 [% CASE 'ERROR_password_too_short' %]
 <div class="alert alert-danger">Låntagaren skapades inte, lösenordet var för kort</div>
 [% CASE 'ERROR_password_too_weak' %]
 <div class="alert alert-danger">Låntagaren skapades inte, lösenordet var för svagt. Ett lösenord måste innehålla minst en versal, en gemen och en siffra</div>
 [% CASE 'ERROR_password_has_whitespaces' %]
 <div class="alert alert-danger">Låntagaren skapades inte, lösenordet innehöll mellanslag</div>
 [% CASE %][% message | html %]
 [% END %]
[% END %]
