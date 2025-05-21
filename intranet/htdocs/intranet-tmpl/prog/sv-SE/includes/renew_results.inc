[% IF renew_results && renew_results.size > 0 %]
 <div class="alert">
 Avgifterna på följande exemplar är betalade, resultat av omlån visas nedan: [% FOREACH result IN renew_results %] [% IF result.success %] <p>[% INCLUDE 'biblio-title.inc' biblio=result.item.biblio %] ( [% result.item.barcode | html %] ): Omlånad - återlämningsdatum [% result.info | html %]</p>
 [% ELSE %]
 <p>[% INCLUDE 'biblio-title.inc' biblio=result.item.biblio %] ( [% result.item.barcode | html %] ): Ej omlånad - [% INCLUDE 'renew_strings.inc' error=result.info %]</p>
 [% END %]
 [% END %]
 </div>
[% END %]
