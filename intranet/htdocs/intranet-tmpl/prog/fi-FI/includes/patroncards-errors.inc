[% BLOCK asksysadmin %]<span>Pyydä järjestelmän ylläpitäjää tarkistamaan virhelokit saadaksesi tarkempia tietoja.</span>[% END %]
[% BLOCK b_batch %]<span>Erä: </span>[% END %]
[% BLOCK b_patronlist %]<span>Asiakaslista: </span>[% END %]
[% BLOCK b_patronnumber %]<span>Asiakasnumero: </span>[% END %]
[% BLOCK b_layout %]<span>Asettelu: </span>[% END %]
[% BLOCK b_template %]<span>Mallipohja: </span>[% END %]

[% IF ( error || error_pdferr )  %]
<div class="alert alert-warning">
 <p>
 <strong>Varoitus:</strong>
 [% IF error_pdferr %]<span>Virhe PDF-tiedoston luonnissa. </span>
 [% IF error_errnocards %]<span>Kortteja ei luotu (tyhjä erä tai lista?) </span>[% END %]
 [% IF error_errba %][% INCLUDE b_batch %]<span class="ex">[%- error_errba | html -%]</span>[% END %]
 [% IF error_errpl %][% INCLUDE b_patronlist %]<span class="ex">[%- error_errpl | html -%]</span>][% END %]
 [% IF error_errpt %][% INCLUDE b_patronnumber %]<span class="ex">[%- error_errpt | html -%]</span>[% END %]
 [% IF error_errlo %][% INCLUDE b_layout %]<span class="ex">[%- error_errlo | html -%]</span>[% END %]
 [% IF error_errtpl %][% INCLUDE b_template %]<span class="ex">[%- error_errtpl | html -%]</span>[% END %]
 [% INCLUDE asksysadmin %]
 [% END %]

 [% IF ( error == 101 ) %]
 [% IF ( card_element ) %]<span>Tietokannassa tapahtui virhe, kun [% card_element | html %] [% element_id | html %] yritettiin poistaa. </span>
 [% ELSE %]<span>Tietokannassa tapahtui virhe tallennuksen yhteydessä. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 102 ) %]
 [% IF ( card_element ) %]<span>Tietokannassa tapahtui virhe, kun [% card_element | html %] [% element_id | html %] yritettiin poistaa. </span>
 [% ELSIF ( image_ids ) %]<span>Tietokannassa tapahtui virhe, kun [% image_ids | html %] yritettiin poistaa. </span>
 [% ELSE %]<span>Tietokannassa tapahtui virhe poiston yhteydessä. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 201 ) %]
 [%IF ( element_id ) %]<span>Yritettiin tehdä elementille [% card_element | html %] [% element_id | html %] toimintoa, jota ei tueta. </span>
 [% ELSE %]<span>Yritetty toimintoa, joka ei ole tuettu. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 202 ) %]
 <span>Tapahtui virhe. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 203 ) %]
 <span>Kirjaston tunnusta ei löytynyt tai se oli väärä. Tarkista, että kirjasto on valittuna. </span><a href="/cgi-bin/koha/circ/set-library.pl">Aseta kirjasto</a>
 [% ELSIF ( error == 301 ) %]
 <span>Kuvan lataamisessa tapahtui virhe. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 302 ) %]
 <span>Kuvan koko ylittää 2MB. Pienennä ja tuo uudelleen. </span>
 [% ELSIF ( error == 303 ) %]
 <span>Kuvia voi tällä hetkellä ladata korkeintaan [% image_limit | html %] kappaletta kerrallaan. Poista yksi tai useampi kuva. </span>
 [% ELSIF ( error == 304 ) %]
 <span>'[% IMAGE_NAME | html %]' -niminen kuva on jo olemassa.</span>
 [% ELSIF ( error == 401 ) %]
 <span>Tapahtui virhe ja erään [% batch_id | html %] ei lisätty niteitä. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 402 ) %]
 <span>Tietoja ei lisätty, koska kirjastoa ei ole valittu. Valitse kirjasto ennen kuin lisäät tietoja tähän erään. </span><a href="/cgi-bin/koha/circ/set-library.pl">Aseta kirjasto</a>
 [% ELSIF ( error == 403 ) %]
 <span>Tapahtui virhe ja niteitä ei poistettu erästä [% batch_id | html %]. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 404 ) %]
 <span>Tapahtui virhe ja erää [% batch_id | html %] ei poistettu. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 405 ) %]
 <span>Tapahtui virhe ja erän [% batch_id | html %] tietueita ei täysin käsitelty. </span>
 [% END %]
 </p>
</div>
[% END %]
