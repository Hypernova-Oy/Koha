[% IF renew_results && renew_results.size > 0 %]
 <div class="alert">
 Seuraavien niteiden maksut on maksettu, uusinnan tulokset näkyvät alapuolella: [% FOREACH result IN renew_results %] [% IF result.success %] <p>[% INCLUDE 'biblio-title.inc' biblio=result.item.biblio %] ( [% result.item.barcode | html %] ): Uusittu - eräpäivä [% result.info | html %]</p>
 [% ELSE %]
 <p>[% INCLUDE 'biblio-title.inc' biblio=result.item.biblio %] ( [% result.item.barcode | html %] ): Ei uusittu - [% INCLUDE 'renew_strings.inc' error=result.info %]</p>
 [% END %]
 [% END %]
 </div>
[% END %]
