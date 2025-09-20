[% PROCESS 'html_helpers.inc' %]
<div id="ill-batch-details" style="display:none"></div>
<div id="ill-batch-modal" class="modal" tabindex="-1" role="dialog" aria-labelledby="ill-batch-modal-label" aria-hidden="true">
 <div class="modal-dialog modal-lg">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="ill-batch-modal-label"></h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <div id="batch-form">
 <form method="get" id="new-batch-form">
 <fieldset class="rows">
 <legend id="legend">Erän tiedot</legend>
 <ol>
 <li id="batch_name">
 <label class="required" for="name">Erän nimi:</label>
 <input type="text" autocomplete="off" name="name" id="name" value="" />
 </li>
 <li id="batch_patron">
 <label class="required" for="batchcardnumber">Kirjastokortti, käyttäjätunnus tai sukunimi:</label>
 <input type="text" autocomplete="off" name="batchcardnumber" id="batchcardnumber" value="" />
 <span id="patron_link"></span>
 </li>
 <li id="batch_branch">
 <label class="required" for="branchcode">Kirjasto:</label>
 <select id="branchcode" name="branchcode">
 [% PROCESS options_for_libraries libraries => Branches.all( selected => branchcode ) %]
 </select>
 </li>
 <li id="batch_status_code" style="display:none">
 <label class="required" for="status_code">Tila:</label>
 <select id="status_code" name="status_code"></select>
 </li>
 </ol>
 </fieldset>
 <fieldset id="add_batch_items" class="rows" style="display:none">
 <legend id="legend">Lisää niteitä erään</legend>
 <div id="textarea-metadata">
 <div id="supported">Tuetut tunnisteet: <span id="supported_identifiers"></span></div>
 <div id="row_count">Rivien määrä: <span id="row_count_value"></span></div>
 </div>
 <div id="textarea-errors" style="display:none" class="error">
 <div id="duplicates" style="display:none">Seuraavat tuplat löytyivät, nämä on yhdistetty: <span id="dupelist"></span></div>
 <div id="badidentifiers" style="display:none">Löytyi seuraavat tuntemattomat tunnisteet, niille ei voitu määrittää tyyppiä: <span id="badids"></span></div>
 </div>
 <ol>
 <li>
 <textarea id="identifiers_input" placeholder="Lisää tunnisteet, yksi per rivi"></textarea>
 </li>
 <li id="process-button">
 <button id="process_button" disabled aria-disabled="true" type="button">Käsittele tunnisteet</button>
 </li>
 </ol>
 </fieldset>
 </form>
 <div id="create-progress" class="alert alert-info" role="alert" style="display:none">
 <span id="progress-label"><strong></strong></span> - Niteitä käsitelty: <span id="processed_count"></span> / <span id="processed_total"></span>. Niteitä epäonnistunut: <span id="processed_failed"></span>.
 <div class="progress">
 <div id="processed_progress_bar" class="progress-bar" role="progressbar" aria-valuenow="0" aria-valuemin="0" aria-valuemax="100" style="min-width: 2em;">
 0% </div>
 </div>
 </div>
 <table id="identifier-table" style="display:none">
 <thead>
 <tr id="identifier-table-header">
 <th scope="col">Tunnistetyyppi</th>
 <th scope="col">Tunnisteen arvo</th>
 <th scope="col">Metadata</th>
 <th scope="col">Pyynnön ID</th>
 <th scope="col">Pyynnön tila</th>
 [% IF Koha.Preference('ILLCheckAvailability') %]
 <th scope="col">Saatavuus</th>
 [% END %]
 <th scope="col"></th>
 </tr>
 </thead>
 <tbody id="identifier-table-body">
 </tbody>
 </table>
 </div>
 <div id="create-requests" style="display:none">
 <button aria-label="Lisää niteitä erään" class="btn btn-primary" id="create-requests-button" type="button">Lisää niteitä erään</button>
 </div>
 </div>
 <div class="modal-footer">
 <div id="lhs">
 <button class="btn btn-default" data-bs-dismiss="modal" aria-hidden="false">Peruuta</button>
 </div>
 <div id="rhs">
 <button id="button_create_batch" class="btn btn-default" aria-hidden="true" disabled>Jatka</button>
 <button id="button_finish" disabled type="button" class="btn btn-default" aria-hidden="true">Lopeta ja tarkastele erää</button>
 </div>
 </div>
 </div>
 </div>
</div>
