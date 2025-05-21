[% USE Koha %]
[% PROCESS 'modal-claims.inc' %]
[% INCLUDE 'format_price.inc' %]

[% IF ( issuecount ) %]
 <div id="issues-table-loading-message">
 <p>
 <a id="issues-table-load-now-button" href="#" class="btn btn-default"><i class="fa fa-book"></i> Visa lån</a>
 [% SET LoadCheckoutsTableDelay = Koha.Preference('LoadCheckoutsTableDelay') %]
 [% IF LoadCheckoutsTableDelay && patronpage == 'circ' %]
 <span id="issues-table-load-delay">
 <i id="issues-table-load-delay-spinner" class="fa fa-spinner fa-pulse fa-fw"></i>
 <span id="issues-table-load-delay-message">Utlån kommer att visas automatiskt o, [% LoadCheckoutsTableDelay | html %] sekunder...</span>
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
 <th scope="col">Återlämningsdatum</th>
 <th scope="col">Återlämningsdatum</th>
 <th scope="col">Titel</th>
 <th scope="col">Exemplartyp (bibliografisk)</th>
 <th scope="col">Exemplartyp</th>
 <th scope="col">Avdelning</th>
 <th scope="col">Plats</th>
 <th scope="col">Hembibliotek</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">Utlånad den</th>
 <th scope="col">Utlånad från</th>
 <th scope="col">Hyllsignatur</th>
 <th scope="col">Ex.nummer</th>
 <th scope="col">Avgift</th>
 <th scope="col">Avgift</th>
 <th scope="col">Pris</th>
 <th scope="col">Låna om <p class="column-tool"><a href="#" id="CheckAllRenewals">välj alla</a> | <a href="#" id="UncheckAllRenewals">ingen</a></p></th>
 <th scope="col">Återlämna <p class="column-tool"><a href="#" id="CheckAllCheckins">välj alla</a> | <a href="#" id="UncheckAllCheckins">ingen</a></p></th>
 <th scope="col">Påstås återlämnad</th>
 <th scope="col">Exportera <p class="column-tool"><a href="#" id="CheckAllExports">välj alla</a> | <a href="#" id="UncheckAllExports">ingen</a></p></th>
 </tr>
 </thead>
 [% INCLUDE 'checkouts-table-footer.inc' %]
 </table>
 [% UNLESS Koha.Preference( 'AlwaysLoadCheckoutsTable' ) %]
 <label for="issues-table-load-immediately">Visa alltid lån direkt</label>
 <input id="issues-table-load-immediately" type="checkbox" />
 [% END %]

 <div id="issues-table-actions" style="display: none;">
 <fieldset class="action">
 [% IF ( CAN_user_circulate_override_renewals ) %]
 [% IF Koha.Preference( 'AllowRenewalLimitOverride' ) || Koha.Preference( 'AllowRenewalOnHoldOverride' ) %]
 <label for="override_limit">Ignorera gräns för omlån:</label>
 <input type="checkbox" name="override_limit" id="override_limit" value="1" />
 [% END %]
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% IF Koha.Preference( 'UnseenRenewals' ) %]
 <label id="renew_as_unseen_label" for="override_limit">Låna om som &quot;unseen&quot; om tillämpligt:</label>
 <input type="checkbox" name="renew_as_unseen" id="renew_as_unseen_checkbox" value="1" />
 [% END %]
 <button class="btn btn-default" id="CheckinChecked" disabled="disabled"><i class="fa fa-download"></i> Återlämna valda exemplar</button>
 <button class="btn btn-default" id="RenewChecked" disabled="disabled"><i class="fa fa-retweet"></i> Låna om valda exemplar</button>
 <button class="btn btn-default" id="RenewAll"><i class="fa fa-book"></i> Låna om alla</button>
 [% END %]
 </fieldset>

 [% IF Koha.Preference('ExportCircHistory') %]
 <fieldset>
 <label for="issues-table-output-format"><strong>Exportera lån med formatet:</strong></label>
 <select name="issues-table-output-format" id="issues-table-output-format">
 <option value="iso2709_995">MARC med exemplar</option>
 <option value="iso2709">MARC utan exemplar</option>
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
 <label for="export_items_bundle_contents">Exportera innehåll i exemplarspaket</label> <input type="checkbox" name="export_items_bundle_contents" id="export_items_bundle_contents">
 <label for="export_remove_fields">Exportera inte fält:</label> <input id="export_remove_fields" name="export_remove_fields" title="Använd för MARC-export" type="text" value="[% Koha.Preference('ExportRemoveFields') | html %]" />
 <input type="hidden" name="op" value="cud-export" />
 <input type="hidden" id="output_format" name="output_format" value="iso2709" />
 <input type="hidden" id="dont_export_item" name="dont_export_item" value="0" />
 <input type="hidden" id="record_type" name="record_type" value="bibs" />
 <button class="btn btn-default btn-sm" id="export_submit"><i class="fa fa-download"></i> Exportera</button>
 </fieldset>
 [% END %]
 </div>
 </form>
[% ELSE %]
 <p>Låntagare har inga utestående lån.</p>
[% END %]

<!-- Claims Returned Modal -->
[% PROCESS 'modal-claims-display' %]
