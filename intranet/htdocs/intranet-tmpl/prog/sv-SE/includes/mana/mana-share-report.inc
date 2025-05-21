<div id="mana_share_report" class="modal" tabindex="-1" role="dialog" aria-labelledby="mana_share_modal_label">
 <div class="modal-dialog modal-xl">
 <div class="modal-content">
 <form method="post" id="mana_share_form" action="/cgi-bin/koha/reports/guided_reports.pl">
 [% INCLUDE 'csrf-token.inc' %]
 <div class="modal-header">
 <h1 class="modal-title" id="mana_share_modal_label">Dela med Mana</h1>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 [% IF (mana_id) %]
 <div class="alert alert-warning">
 <p>Din rapport är redan länkad till en Mana-rapport. Dela den om du har gjort förändringar, annars görs ingenting.</p>
 </div>
 [% END %]
 <div id="note-error" class="alert alert-warning" role="alert">
 Ange ett rapportnamn och en beskrivande anteckning före delning (minst 20 tecken) </div>
 <div class="shared_infos rows">
 <ul>
 <li><span class="label">Id: </span><div id="shared_id"></div></li>
 <li><span class="label">Namn: </span><div id="shared_name"></div></li>
 <li><span class="label">SQL: </span><div id="shared_sql"></div></li>
 <li><span class="label">Grupp: </span><div id="shared_group"></div></li>
 <li><span class="label">Typ: </span><div id="shared_type"></div></li>
 <li><span class="label">Kommentarer: </span><div id="shared_notes"></div></li>
 [% IF (languages_loop) %]
 <li>
 <input type="hidden" name="op" value="cud-share">
 <label for="mana_language">Språk:</label>
 <select id="mana_language" name="mana_language">
 [% FOREACH languages_loo IN languages_loop %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.plural ) %]
 [% FOREACH sublanguages_loo IN languages_loo.sublanguages_loop %]
 [% IF ( sublanguages_loo.enabled ) %]
 [% IF ( sublanguages_loo.sublanguage_current ) %]
 <option value="[% languages_loo.rfc4646_subtag | html %]" selected="selected">
 [% sublanguages_loo.native_description | html %]
 [% sublanguages_loo.script_description | html %]
 [% sublanguages_loo.region_description | html %]

 [% sublanguages_loo.variant_description | html %]
 ([% sublanguages_loo.rfc4646_subtag | html %])
 </option>
 [% ELSE %]
 <option value="[% languages_loo.rfc4646_subtag | html %]">
 [% sublanguages_loo.native_description | html %]
 [% sublanguages_loo.script_description | html %]
 [% sublanguages_loo.region_description | html %]
 [% sublanguages_loo.variant_description | html %]
 ([% sublanguages_loo.rfc4646_subtag | html %])
 </option>
 [% END %]
 [% END %]
 [% END %]
 [% ELSE %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.current ) %]
 <option value="[% languages_loo.rfc4646_subtag | html %]" selected="selected">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </option>
 [% ELSE %]
 <option value="[% languages_loo.rfc4646_subtag | html %]">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </option>
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 </select>
 </li>
 [% ELSE %]
 <input type="hidden" name="mana_language" value="[% lang | html %]" />
 [% END %]
 </ul>
 </div> <!-- /.shared_infos rows -->
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <input type="hidden" id="reportid" name="reportid"/>
 <button id="ManaShareButton" type="submit" class="btn btn-primary shared_infos">Dela</button>
 <button type="button" class="btn btn-default" id="ManaCloseButton" data-bs-dismiss="modal">Avbryt</button>
 </div>
 </form> <!-- /#mana_share_form -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /#mana_share_report -->
