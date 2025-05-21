[% USE Branches %]
[% USE ItemTypes %]
[% USE KohaDates %]
[% PROCESS 'i18n.inc' %]

<table id="holdst" class="table table-bordered table-striped">
 <caption>Varaukset <span class="count">(Yhteensä [% HOLDS.count | html %])</span></caption>
 <!-- HOLDS TABLE ROWS -->
 <thead>
 <tr>
 <th class="all anti-the">Nimeke</th>
 [% IF ( showpriority ) %]
 <th>Varauspvm</th>
 [% ELSE %]
 <th class="psort">Varauspvm</th>
 [% END %]
 <th>Vanhenee</th>
 [% UNLESS( singleBranchMode) %]
 <th>Noutopiste</th>
 [% END %]
 [% IF ( showpriority ) %]
 <th class="psort">Sija jonossa</th>
 [% END %]
 [% IF Koha.Preference('OpacHoldNotes') %]
 <th>Huomautukset</th>
 [% END %]
 <th>Tila</th>
 [% IF SuspendHoldsOpac and ! onlyinfo %]
 <th class="nosort" >Keskeytä varaus</th>
 [% END %]
 [% IF ! onlyinfo %]
 <th class="nosort">Muokkaa</th>
 [% END %]
 <th></th>
 </tr>
 </thead>
 <tbody>
 [% SET all_holds_waiting = 1 %]
 [% FOREACH HOLD IN HOLDS %]
 [% UNLESS ( HOLD.is_waiting || HOLD.is_in_transit || HOLD.is_in_processing) %]
 [% SET all_holds_waiting = 0 %]
 [% END %]
 [% IF ( HOLD.is_at_destination ) %]
 <tr class="reserved">
 [% ELSIF HOLD.is_in_transit %]
 <tr class="transfered">
 [% ELSE %]
 <tr>
 [% END %]
 <td class="title">
 [% IF ! onlyinfo %]
 [% INCLUDE 'biblio-title.inc' biblio=HOLD.biblio link=> 1 %]
 [% HOLD.item.enumchron | html %]
 [% ELSE %]
 <strong>
 [% INCLUDE 'biblio-title.inc' biblio=HOLD.biblio %]
 [% HOLD.item.enumchron | html %]
 </strong>
 [% END %]
 [% HOLD.biblio.author | html %]
 [% IF HOLD.item_group_id %]
 <p>Seuraava vapaa nide ryhmästä: <strong>[% HOLD.item_group.description | html %]</strong></p>
 [% END %]
 [% IF HOLD.item_level_hold %]
 <p class="hint">Nide varauksessa: [% HOLD.item.barcode | html %]</p>
 [% END %]
 </td>
 <td class="reservedate" data-order="[% HOLD.reservedate | html %]">
 [% HOLD.reservedate | $KohaDates %]
 </td>
 [% IF ! HOLD.found %]
 <td class="expirationdate" data-order="[% HOLD.expirationdate | html %]">
 [% IF ( HOLD.expirationdate ) %] [% HOLD.expirationdate | $KohaDates %] [% ELSE %] Ei vanhene koskaan [% END %] [% ELSE %] <td class="expirationdate" data-order="0000-00-00">
 -
 [% END %]
 </td>
 [% UNLESS( singleBranchMode) %]
 <td class="branch">
 [% HOLD.branch.branchname | html %]
 [% IF ( HOLD.can_update_pickup_location_opac ) %]
 <button type="button" class="btn btn-sm btn-link" data-bs-toggle="modal" data-bs-target="#changePickup[% HOLD.reserve_id | html %]">
 <i class="fa fa-pencil-alt" aria-hidden="true"></i> Muuta </button>
 <!-- Change pickup location modal -->
 <div class="modal" id="changePickup[% HOLD.reserve_id | html %]" tabindex="-1" aria-labelledby="changePickup[% HOLD.reserve_id | html %]Label" aria-hidden="true">
 <div class="modal-dialog">
 <form id="change_branch_form[% HOLD.reserve_id | html %]" action="/cgi-bin/koha/opac-modrequest.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-change_branch">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="changePickup[% HOLD.reserve_id | html %]Label">Vaihda noutopaikka niteelle <em>[% INCLUDE 'biblio-title.inc' biblio=HOLD.biblio %]</em></h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <div class="form-group">
 <label for="new_branch[% HOLD.reserve_id | html %]">Uusi noutopaikka:</label>
 <select name="new_pickup_location" id="new_branch[% HOLD.reserve_id | html %]" class="form-select">
 [% PROCESS options_for_libraries libraries = Branches.pickup_locations({ search_params => { biblio => HOLD.biblionumber, patron => HOLD.borrower }, selected => HOLD.branchcode }) %]
 </select>
 </div>
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 </div>
 <div class="modal-footer">
 <button type="submit" name="change_branch" value="1" class="btn btn-primary"><i class="fa fa-check" aria-hidden="true"></i> Tallenna</button>
 <button type="button" class="btn btn-secondary" data-bs-dismiss="modal"><i class="fa fa-times" aria-hidden="true"></i> Peruuta</button>
 </div>
 </div> <!-- /.modal-content -->
 </form>
 </div> <!-- /.modal-dialog -->
 </div> <!-- /.modal -->
 [% END  %]
 </td>
 [% END %]
 [% IF ( showpriority ) %]
 <td data-order="[% HOLD.priority | html %]" class="priority">
 [% HOLD.priority | html %]
 </td>
 [% END %]
 [% IF Koha.Preference('OpacHoldNotes') %]
 <td>[% HOLD.reservenotes | html | html_line_break %]</td>
 [% END %]
 <td class="status">
 [% IF ( HOLD.is_waiting ) %]
 <i class="fa fa-exclamation-circle text-warning" aria-hidden="true"></i>
 [% IF ( HOLD.is_at_destination ) %] Nide odottaa <strong> [% HOLD.branch.branchname | html %]</strong>
 [% IF ( HOLD.desk_id ) %], [% HOLD.desk.desk_name | html %],[% END %] [% IF ( HOLD.waitingdate ) %] lähtien [% HOLD.waitingdate | $KohaDates %] [% IF HOLD.expirationdate %] saakka [% HOLD.expirationdate | $KohaDates %] [% END %] [% END %] <input type="hidden" name="pickup" value="[% HOLD.branchcode | html %]" />
 [% ELSE %] Aineisto kuljetettavana kirjastoon <strong> [% Branches.GetName( HOLD.branchcode ) | html %]</strong> <input type="hidden" name="pickup" value="[% HOLD.branchcode | html %]" />
 [% END %]
 [% ELSE %]
 [% IF ( HOLD.is_in_transit ) %]
 [% SET transfer = HOLD.item.get_transfer %]
 [% branch_name = BLOCK %]<strong>[% Branches.GetName( transfer.frombranch ) | html %]</strong>[% END %]
 <span>Kuljetettavana kirjastosta [% branch_name| $raw %] lähtien</span>
 [% transfer.datesent | $KohaDates %]
 [% ELSIF ( HOLD.is_in_processing ) %]
 <span>Nide käsiteltävänä</span>
 [% ELSIF ( HOLD.suspend ) %]
 <span>Keskeytetty</span>[% IF ( HOLD.suspend_until ) %] <span>ja aktivoi varaukset</span> [% HOLD.suspend_until | $KohaDates %][% END %]
 [% ELSE %]
 [% IF HOLD.itemtype %]
 <span>Odottaa seuraavaa vapaa olevaa nidettä nidetyypillä '[% ItemTypes.GetDescription( HOLD.itemtype ) | html %]'</span>
 [% ELSE %]
 <span>Odottava</span>
 [% END %]
 [% END %]
 [% END %]
 </td>
 [% IF SuspendHoldsOpac and ! onlyinfo %]
 <td>
 [% IF ( HOLD.is_cancelable_from_opac ) %]
 [% IF HOLD.suspend %]
 <form class="form-inline" action="/cgi-bin/koha/opac-modrequest-suspend.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-unsuspend" />
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 <button class="btn btn-link" type="submit" name="submit"><i class="fa fa-play" aria-hidden="true"></i> Aktivoi</button>
 </form>
 [% ELSE %]
 [% IF AutoResumeSuspendedHolds %]
 <a class="btn btn-link suspend_hold js-show" href="#" role="button" data-title="[% HOLD.biblio.title | html %] [% FOREACH subtitle IN HOLD.biblio.subtitle.split(' \| ') %][% IF Koha.Preference('marcflavour')=='UNIMARC' %],[% END %][% subtitle | html %][% END %]" data-reserve_id="[% HOLD.reserve_id | html %]"><i class="fa fa-pause" aria-hidden="true"></i> Keskeytä varaus</a>
 [% ELSE %]
 <form class="form-inline" action="/cgi-bin/koha/opac-modrequest-suspend.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-suspend" />
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 <button class="btn btn-link" type="submit" name="submit"><i class="fa fa-pause" aria-hidden="true"></i> Keskeytä varaus</button>
 </form>
 [% END # / IF AutoResumeSuspendedHolds %]
 [% END # / IF HOLD.suspend %]
 [% END # / IF ( HOLD.is_cancelable_from_opac )%]
 </td>
 [% END # / IF SuspendHoldsOpac %]
 [% IF ! onlyinfo %]
 <td class="modify">
 [% IF ( HOLD.is_cancelable_from_opac ) %]
 <form id="delete_hold_[% HOLD.reserve_id | html %]" action="/cgi-bin/koha/opac-modrequest.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-cancel" />
 <input type="hidden" name="biblionumber" value="[% HOLD.biblionumber | html %]" />
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 <button data-title="[% INCLUDE 'biblio-title-head.inc' biblio=HOLD.biblio %]" data-reserve_id="[% HOLD.reserve_id | html %]" type="submit" class="btn btn-sm btn-danger btn-delete-hold"><i class="fa fa-times" aria-hidden="true"></i> [% tp('Cancel hold button', 'Cancel') | html %]</button>
 </form>
 [% ELSIF HOLD.is_waiting && HOLD.cancellation_requestable_from_opac %]
 <form id="req_cancel_hold_[% HOLD.reserve_id | html %]" action="/cgi-bin/koha/opac-modrequest.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-request_cancellation" />
 <input type="hidden" name="biblionumber" value="[% HOLD.biblionumber | html %]" />
 <input type="hidden" name="reserve_id" value="[% HOLD.reserve_id | html %]" />
 <button data-title="[% INCLUDE 'biblio-title-head.inc' biblio=HOLD.biblio %]" data-reserve_id="[% HOLD.reserve_id | html %]" type="submit" class="btn btn-sm btn-danger btn-req-delete-hold"><i class="fa fa-times" aria-hidden="true"></i> [% tp('Request to cancel hold button', 'Request to cancel') | html %]</button>
 </form>
 [% END %]
 </td>
 [% END # / IF onlyinfo %]
 <td></td>
 </tr>
 [% END # /FOREACH HOLDS %]
 </tbody>
</table>

[% IF SuspendHoldsOpac and ! onlyinfo %]
 [% UNLESS ( all_holds_waiting ) %]
 <div>
 <form class="form-inline" id="suspend_all_holds" action="/cgi-bin/koha/opac-modrequest-suspend.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-suspend_all" />
 <button type="submit" id="suspend_all_submit" class="btn btn-primary"><i class="fa fa-pause" aria-hidden="true"></i> Keskeytä kaikki varaukset</button>
 <input type="hidden" name="suspend" value="1" />

 [% IF AutoResumeSuspendedHolds %]
 <label for="suspend_until"> tähän saakka </label>
 <input type="text" name="suspend_until" id="suspend_until" class="flatpickr futuredate" size="10" />
 <p><a href="#" class="clear-flatpickr" data-fp="suspend_until">Jos kentässä ei ole päivämäärää, keskeytyvät varaukset toistaiseksi</a></p>
 [% END %]
 </form>
 </div>
 <br/>
 <div>
 <form id="resume_all_holds" action="/cgi-bin/koha/opac-modrequest-suspend.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-unsuspend_all" />
 <button type="submit" id="resume_all_submit" class="btn btn-primary"><i class="fa fa-play" aria-hidden="true"></i> Aktivoi kaikki keskeytetyt varaukset</button>
 <input type="hidden" name="suspend" value="0" />
 </form>
 </div>
 [% END %]
[% END %]
