[% PROCESS 'html_helpers.inc' %]
<div id="ill-batch-details" style="display:none"></div>
<div id="ill-batch-modal" class="modal" tabindex="-1" role="dialog" aria-labelledby="ill-batch-modal-label" aria-hidden="true">
 <div class="modal-dialog modal-lg">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="ill-batch-modal-label"></h1>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <div id="batch-form">
 <form method="get" id="new-batch-form">
 <fieldset class="rows">
 <legend id="legend">Detaljer för sats</legend>
 <ol>
 <li id="batch_name">
 <label class="required" for="name">Korgnamn:</label>
 <input type="text" autocomplete="off" name="name" id="name" type="text"
                                    value="" />
 </li>
 <li id="batch_patron">
 <label class="required" for="batchcardnumber">Lånekortsnummer, användarnamn eller efternamn:</label>
 <input type="text" autocomplete="off" name="batchcardnumber" id="batchcardnumber" type="text" value="" />
 <span id="patron_link"></span>
 </li>
 <li id="batch_branch">
 <label class="required" for="branchcode">Bibliotek:</label>
 <select id="branchcode" name="branchcode">
 [% PROCESS options_for_libraries libraries => Branches.all( selected => branchcode ) %]
 </select>
 </li>
 <li id="batch_status_code" style="display:none">
 <label class="required" for="status_code">Status:</label>
 <select id="status_code" name="status_code"></select>
 </li>
 </ol>
 </fieldset>
 <fieldset id="add_batch_items" class="rows" style="display:none">
 <legend id="legend">Lägg till exemplar i batch</legend>
 <div id="textarea-metadata">
 <div id="supported">Identifierare som stöds: <span id="supported_identifiers"></span></div>
 <div id="row_count">Antal rader: <span id="row_count_value"></span></div>
 </div>
 <div id="textarea-errors" style="display:none" class="error">
 <div id="duplicates" style="display:none">Följande dubbletter har hittats, dessa har blivit sammanslagna: <span id="dupelist"></span></div>
 <div id="badidentifiers" style="display:none">Följande okända identifierare hittades, det var inte möjligt att fastställa deras typ: <span id="badids"></span></div>
 </div>
 <ol>
 <li>
 <textarea id="identifiers_input" placeholder="Skriv in sökkriterier, ett per rad"></textarea>
 </li>
 <li id="process-button">
 <button id="process_button" disabled aria-disabled="true" type="button">Bearbeta sökkriterier</button>
 </li>
 </ol>
 </fieldset>
 </form>
 <div id="create-progress" class="alert alert-info" role="alert" style="display:none">
 <span id="progress-label"><strong></strong></span> - Bearbetade exemplar: <span id="processed_count"></span> av <span id="processed_total"></span>. Exemplar misslyckades: <span id="processed_failed"></span>.
 <div class="progress">
 <div id="processed_progress_bar" class="progress-bar" role="progressbar" aria-valuenow="0" aria-valuemin="0" aria-valuemax="100" style="min-width: 2em;">
 0% </div>
 </div>
 </div>
 <table id="identifier-table" style="display:none">
 <thead>
 <tr id="identifier-table-header">
 <th scope="col">kännetecken för typ</th>
 <th scope="col">Värde för identifikator</th>
 <th scope="col">Metadata</th>
 <th scope="col">Beställningsnr</th>
 <th scope="col">Beställningsstatus</th>
 [% IF Koha.Preference('ILLCheckAvailability') %]
 <th scope="col">Tillgänglighet</th>
 [% END %]
 <th scope="col"></th>
 </tr>
 </thead>
 <tbody id="identifier-table-body">
 </tbody>
 </table>
 </div>
 <div id="create-requests" style="display:none">
 <button aria-label="Lägg till exemplar till sats" class="btn btn-primary" id="create-requests-button" type="button">Lägg till exemplar till sats</button>
 </div>
 </div>
 <div class="modal-footer">
 <div id="lhs">
 <button class="btn btn-default" data-bs-dismiss="modal" aria-hidden="false">Avbryt</button>
 </div>
 <div id="rhs">
 <button id="button_create_batch" class="btn btn-default" aria-hidden="true" disabled>Fortsätt</button>
 <button id="button_finish" disabled type="button" class="btn btn-default" aria-hidden="true">Avsluta och se sats</button>
 </div>
 </div>
 </div>
 </div>
</div>
