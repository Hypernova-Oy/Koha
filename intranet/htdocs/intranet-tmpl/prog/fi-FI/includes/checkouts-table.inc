[% USE Koha %]
[% PROCESS 'modal-claims.inc' %]
[% INCLUDE 'format_price.inc' %]

[% IF ( issuecount ) %]
 <div id="issues-table-loading-message">
 <p>
 <a id="issues-table-load-now-button" href="#" class="btn btn-default"><i class="fa fa-book"></i> Lainassa</a>
 [% SET LoadCheckoutsTableDelay = Koha.Preference('LoadCheckoutsTableDelay') %]
 [% IF LoadCheckoutsTableDelay && patronpage == 'circ' %]
 <span id="issues-table-load-delay">
 <i id="issues-table-load-delay-spinner" class="fa fa-spinner fa-pulse fa-fw"></i>
 <span id="issues-table-load-delay-message">Lainaustaulu näytetään automaattisesti [% LoadCheckoutsTableDelay | html %] sekunnissa...</span>
 <span>
 [% END %]
 </p>
 </div>
 <form name="issues" action="/cgi-bin/koha/tools/export.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <table id="issues-table" style="width: 100% !Important; display: none;">
 <thead>
 <tr>
 <th scope="col">&nbsp;</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">Eräpäivä</th>
 <th scope="col">Eräpäivä</th>
 <th scope="col">Nimeke</th>
 <th scope="col">Aineistotyyppi</th>
 <th scope="col">Nidetyyppi</th>
 <th scope="col">Kokoelma</th>
 <th scope="col">Paikka</th>
 <th scope="col">Kotikirjasto</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">Lainattu</th>
 <th scope="col">Lainauspiste</th>
 <th scope="col">Luokka</th>
 <th scope="col">Nidenumero</th>
 <th scope="col">Maksu</th>
 <th scope="col">Myöhästymismaksu</th>
 <th scope="col">Hinta</th>
 <th scope="col">Uusinta <p class="column-tool"><a href="#" id="CheckAllRenewals">valitse kaikki</a> | <a href="#" id="UncheckAllRenewals">ei valintaa</a></p></th>
 <th scope="col">Palautus <p class="column-tool"><a href="#" id="CheckAllCheckins">valitse kaikki</a> | <a href="#" id="UncheckAllCheckins">ei valintaa</a></p></th>
 <th scope="col">Palautusilmoitukset</th>
 <th scope="col">Vie <p class="column-tool"><a href="#" id="CheckAllExports">valitse kaikki</a> | <a href="#" id="UncheckAllExports">ei valintaa</a></p></th>
 </tr>
 </thead>
 [% INCLUDE 'checkouts-table-footer.inc' %]
 </table>
 [% UNLESS Koha.Preference( 'AlwaysLoadCheckoutsTable' ) %]
 <label for="issues-table-load-immediately">Näytä aina lainat reaaliaikaisesti</label>
 <input id="issues-table-load-immediately" type="checkbox" />
 [% END %]

 <div id="issues-table-actions" style="display: none;">
 <fieldset class="action">
 [% IF ( CAN_user_circulate_override_renewals ) %]
 [% IF Koha.Preference( 'AllowRenewalLimitOverride' ) || Koha.Preference( 'AllowRenewalOnHoldOverride' ) %]
 <label for="override_limit">Ohita uusintarajoitus:</label>
 <input type="checkbox" name="override_limit" id="override_limit" value="1" />
 [% END %]
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% IF Koha.Preference( 'UnseenRenewals' ) %]
 <label id="renew_as_unseen_label" for="override_limit">Uusi lainat &quot;verkkokirjastouusintana&quot; jos sopii:</label>
 <input type="checkbox" name="renew_as_unseen" id="renew_as_unseen_checkbox" value="1" />
 [% END %]
 <button class="btn btn-default" id="CheckinChecked" disabled="disabled"><i class="fa fa-download"></i> Palauta valitut niteet</button>
 <button class="btn btn-default" id="RenewChecked" disabled="disabled"><i class="fa fa-retweet"></i> Uusi valitut niteet</button>
 <button class="btn btn-default" id="RenewAll"><i class="fa fa-book"></i> Uusi kaikki</button>
 [% END %]
 </fieldset>

 [% IF Koha.Preference('ExportCircHistory') %]
 <fieldset>
 <label for="issues-table-output-format"><strong>Vie lainat tässä muodossa:</strong></label>
 <select name="issues-table-output-format" id="issues-table-output-format">
 <option value="iso2709_995">MARC ja niteet</option>
 <option value="iso2709">MARC ilman niteitä</option>
 [% IF csv_profiles.count %]
 <option value="csv">CSV</option>
 [% END %]
 </select>

 [% IF csv_profiles.count %]
 <select name="csv_profile_id">
 [% FOREACH csv_profile IN csv_profiles %]
 <option value="[% csv_profile.export_format_id | html %]">[% csv_profile.profile | html %]</option>
 [% END %]
 </select>
 [% END %]
 <label for="export_items_bundle_contents">Vie nidepakettien sisältöjä</label> <input type="checkbox" name="export_items_bundle_contents" id="export_items_bundle_contents">
 <label for="export_remove_fields">Älä tuo kenttiä:</label> <input id="export_remove_fields" name="export_remove_fields" title="Käytä MARC-vientiin" type="text" value="[% Koha.Preference('ExportRemoveFields') | html %]" />
 <input type="hidden" name="op" value="cud-export" />
 <input type="hidden" id="output_format" name="output_format" value="iso2709" />
 <input type="hidden" id="dont_export_item" name="dont_export_item" value="0" />
 <input type="hidden" id="record_type" name="record_type" value="bibs" />
 <button class="btn btn-default btn-sm" id="export_submit"><i class="fa fa-download"></i> Vie</button>
 </fieldset>
 [% END %]
 </div>
 </form>
[% ELSE %]
 <p>Asiakkaalla ei ole lainoja.</p>
[% END %]

<!-- Claims Returned Modal -->
[% PROCESS 'modal-claims-display' %]
