<p id="return-claims-controls">
 [% IF ( patron.return_claims.resolved.count > 0 || patron.return_claims.unresolved.count > 0 ) %]
 <a id="show_all_claims" class="ctrl_link" href="#">Näytä kaikki [% patron.return_claims.count | html %] palautusilmoitukset</a>
 <a id="show_unresolved_claims" class="ctrl_link disabled" href="#">Näytä [% patron.return_claims.unresolved.count | html %] ratkaisemattomat palautusilmoitukset</a>
 [% ELSE %]
 <a id="show_all_claims" class="ctrl_link" href="#"></a>
 <a id="show_unresolved_claims" class="ctrl_link disabled" href="#"></a>
 [% END %]
</p>
<table id="return-claims-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="return-claim-id">Palautusilmoituksen ID</th>
 <th class="return-claim-id">Ratkaistu?</th>
 <th class="return-claim-record-title anti-the">Nimeke</th>
 <th class="return-claim-notes">Huomautukset</th>
 <th class="return-claim-created-on">Luotu</th>
 <th class="return-claim-created-on">Luotu</th>
 <th class="return-claim-updated-on">Päivitetty</th>
 <th class="return-claim-updated-on">Päivitetty</th>
 <th class="return-claim-resolution">Ratkaisu</th>
 <th class="return-claim-actions NoSort">&nbsp;</th>
 </tr>
 </thead>
</table>
