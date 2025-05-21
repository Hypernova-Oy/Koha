<p id="return-claims-controls">
 [% IF ( patron.return_claims.resolved.count > 0 || patron.return_claims.unresolved.count > 0 ) %]
 <a id="show_all_claims" class="ctrl_link" href="#">Visa alla [% patron.return_claims.count | html %] ärende(n)</a>
 <a id="show_unresolved_claims" class="ctrl_link disabled" href="#">Visa [% patron.return_claims.unresolved.count | html %] olösta "påstås återlämnad"</a>
 [% ELSE %]
 <a id="show_all_claims" class="ctrl_link" href="#"></a>
 <a id="show_unresolved_claims" class="ctrl_link disabled" href="#"></a>
 [% END %]
</p>
<table id="return-claims-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="return-claim-id">Claim ID</th>
 <th class="return-claim-id">Löst?</th>
 <th class="return-claim-record-title anti-the">Titel</th>
 <th class="return-claim-notes">Kommentarer</th>
 <th class="return-claim-created-on">Skapad den</th>
 <th class="return-claim-created-on">Skapad den</th>
 <th class="return-claim-updated-on">Uppdaterad</th>
 <th class="return-claim-updated-on">Uppdaterad</th>
 <th class="return-claim-resolution">Lösning</th>
 <th class="return-claim-actions NoSort">&nbsp;</th>
 </tr>
 </thead>
</table>
