[% BLOCK asksysadmin %]<span>Be systemadministratören kontrollera felloggen för mer information.</span>[% END %]
[% BLOCK b_batch %]<span>Sats: </span>[% END %]
[% BLOCK b_patronlist %]<span>Låntagarlista: </span>[% END %]
[% BLOCK b_patronnumber %]<span>Låntagarnummer: </span>[% END %]
[% BLOCK b_layout %]<span>Layout: </span>[% END %]
[% BLOCK b_template %]<span>Mall: </span>[% END %]

[% IF ( error || error_pdferr )  %]
<div class="alert alert-warning">
 <p>
 <strong>VARNING:</strong>
 [% IF error_pdferr %]<span>Fel vid skapandet av en PDF-fil. </span>
 [% IF error_errnocards %]<span>Inga kort skapades (tom sats eller lista?) </span>[% END %]
 [% IF error_errba %][% INCLUDE b_batch %]<span class="ex">[%- error_errba | html -%]</span>[% END %]
 [% IF error_errpl %][% INCLUDE b_patronlist %]<span class="ex">[%- error_errpl | html -%]</span>][% END %]
 [% IF error_errpt %][% INCLUDE b_patronnumber %]<span class="ex">[%- error_errpt | html -%]</span>[% END %]
 [% IF error_errlo %][% INCLUDE b_layout %]<span class="ex">[%- error_errlo | html -%]</span>[% END %]
 [% IF error_errtpl %][% INCLUDE b_template %]<span class="ex">[%- error_errtpl | html -%]</span>[% END %]
 [% INCLUDE asksysadmin %]
 [% END %]

 [% IF ( error == 101 ) %]
 [% IF ( card_element ) %]<span>Databasen returnerade ett fel vid försök att spara [% card_element | html %] [% element_id | html %]. </span>
 [% ELSE %]<span>Databasen returnerade ett felmeddelande vid försök att spara. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 102 ) %]
 [% IF ( card_element ) %]<span>Databasen returnerade ett fel vid borttagning av [% card_element | html %] [% element_id | html %]. </span>
 [% ELSIF ( image_ids ) %]<span>Databasen returnerade ett fel vid borttagning av [% image_ids | html %]. </span>
 [% ELSE %]<span>Databasen returnerade ett felmeddelande vid försök att ta bort. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 201 ) %]
 [%IF ( element_id ) %]<span>En felaktig operation försöktes på [% card_element | html %] [% element_id | html %]. </span>
 [% ELSE %]<span>En felaktig operation försöktes. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 202 ) %]
 <span>Ett fel har uppstått. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 203 ) %]
 <span>En icke-existerande eller ogiltig bibliotekskod angavs. Var snäll och kontrollera att du har valt ett bibliotek. </span><a href="/cgi-bin/koha/circ/set-library.pl">Ange bibliotek</a>
 [% ELSIF ( error == 301 ) %]
 <span>Ett fel inträffade när du försökte ladda upp bilden. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 302 ) %]
 <span>Bilden är större än 2 MB. Minska storleken och importera igen. </span>
 [% ELSIF ( error == 303 ) %]
 <span>Databasens bildkvot tillåter för närvarande endast maximalt [% image_limit | html %] bilder på en gång. Ta bort en eller flera bilder för att frigöra utrymme. </span>
 [% ELSIF ( error == 304 ) %]
 <span>En bild med namnet '[% IMAGE_NAME | html %]' finns redan.</span>
 [% ELSIF ( error == 401 ) %]
 <span>Ett fel har inträffat och inga exemplar har lagts till i sats [% batch_id | html %]. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 402 ) %]
 <span>Inga objekt lades till eftersom bibliotek inte är valt. Välj bibliotek innan du lägger till exemplar i en sats. </span><a href="/cgi-bin/koha/circ/set-library.pl">Ange bibliotek</a>
 [% ELSIF ( error == 403 ) %]
 <span>Ett fel har inträffat och exemplar(en) togs inte bort från sats [% batch_id | html %]. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 404 ) %]
 <span>Ett fel uppstod, så sats [% batch_id | html %] har inte raderats. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 405 ) %]
 <span>Ett fel har inträffat och sats [% batch_id | html %] kunde inte behandlas till fullo. </span>
 [% END %]
 </p>
</div>
[% END %]
