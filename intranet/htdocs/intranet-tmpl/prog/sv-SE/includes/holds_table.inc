[% USE Koha %]
[% SET hold_cancellation = AuthorisedValues.GetAuthValueDropbox('HOLD_CANCELLATION') %]
[% USE AuthorisedValues %]

<table id="patron_holds_table" class="holds_table">
 <thead>
 <tr>
 <th id="checkbox" data-colname="checkbox"><input type="checkbox" class="select_hold_all"/></th>
 <th id="priority" data-colname="priority">Köplats</th>
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 <th id="change_priority" data-colname="change_priority">Ändra prioriteringsordning</th>
 [% END %]
 <th id="patron" data-colname="patron">Låntagare</th>
 <th id="notes" data-colname="notes">Kommentarer</th>
 <th id="date" data-colname="date">Datum</th>
 <th id="expiration" data-colname="expiration">Utgång</th>
 <th id="pickup_library" data-colname="pickup_library">Avhämtningsbibliotek</th>
 <th id="details" data-colname="details">Detaljer</th>
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 <th id="set_lowest_priority" data-colname="set_lowest_priority"><span style="display:none;">Ställ in på lägsta prioritet</span><i class="fa fa-lg fa-rotate-90 fa-fast-forward" title="Växla ställ in på lägsta prioritet"></i></th>
 [% END %]
 <th id="delete" data-colname="delete">Ta bort</th>
 <th id="suspend" data-colname="suspend">Pausa</th>
 <th id="print_slip" data-colname="print_slip">Skriv ut reservation/överföringskvittering</th>
 </tr>
 </thead>
 [%- SET first_priority = 0 -%]
 [%- SET found_holds = 0 -%]
 [%- SET last_priority  = holds.last.priority -%]

 [% SET all_priorities = [] %]
 [% FOREACH hold IN holds %]
 [% all_priorities.push( hold.priority ) %]
 [% END %]

 <tbody>
 [% FOREACH hold IN holds %]
 [%- IF !hold.found && first_priority == 0 -%]
 [%- first_priority = hold.priority -%]
 [%- found_holds = loop.index() -%]
 [%- END -%]
 [%- IF Koha.Preference('HoldsSplitQueueNumbering') == 'actual' -%]
 [%- this_priority = hold.priority -%]
 [%- ELSE -%]
 [%- this_priority = loop.count() - found_holds -%]
 [%- END -%]
 [% IF hold.suspend %]
 <tr class="suspend">
 [% ELSE %]
 <tr>
 [% END %]
 <td><input type="checkbox" class="select_hold" data-id="[% hold.reserve_id | html %]"/></td>
 <td>
 <input type="hidden" name="reserve_id" value="[% hold.reserve_id | html %]" />
 <input type="hidden" name="borrowernumber" value="[% hold.borrowernumber | html %]" />
 <input type="hidden" name="biblionumber" value="[% hold.biblionumber | html %]" />
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 [% IF Koha.Preference('HoldsSplitQueue') == "nothing" && !hold.found %]
 <select name="rank-request" class="rank-request" data-hold-id="[% hold.reserve_id | html %]">
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 [% FOREACH priority IN all_priorities %]
 [% IF priority == this_priority %]
 <option value="[% priority | html %]" selected="selected">[% priority | html %]</option>
 [% ELSIF priority > 0 %]
 <option value="[% priority | html %]">[% priority | html %]</option>
 [% END %]
 [% END %]
 [% ELSE %]
 <option value="[% hold.priority | html %]" selected="selected">[% this_priority | html %]</option>
 [% END %]
 <option value="del">del</option>
 </select>
 [% ELSE %]
 <input type="hidden" name="rank-request" class="rank-request" value="[% hold.priority | html %]" data-hold-id="[% hold.reserve_id | html %]">
 <select name="rank-request" class="rank-request" disabled="disabled" data-hold-id="[% hold.reserve_id | html %]">
 [% IF ( hold.found ) %]
 [% IF ( hold.intransit ) %]
 <option value="T" selected="selected">Under transport</option>
 [% ELSIF (hold.inprocessing) %]
 <option value="P" selected="selected">Exemplar bearbetas</option>
 [% ELSE %]
 <option value="W" selected="selected">Väntar</option>
 [% END %]
 [% ELSE %]
 <option value="[% hold.priority | html %]" selected="selected">[% this_priority | html %]</option>
 [% END %]
 </select>
 [% END %]
 [% ELSE %]
 <input type="hidden" name="rank-request" class="rank-request" value="[% hold.priority | html %]" data-hold-id="[% hold.reserve_id | html %]">
 [% hold.priority | html %]
 [% END %]
 </td>
 [%- IF ( CAN_user_reserveforothers_modify_holds_priority ) -%]
 [%- UNLESS hold.found -%]
 [%- SET prev_priority  = loop.prev.priority -%]
 [%- SET next_priority  = loop.next.priority -%]
 <td style="white-space:nowrap;">
 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-next_priority="[% next_priority | html %]" data-op="cud-move" data-prev_priority="[% prev_priority | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-where="up" title="Flytta reservation uppåt">
 <i class="fa fa-lg icon-move-hold-up" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-next_priority="[% next_priority | html %]" data-op="cud-move" data-prev_priority="[% prev_priority | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-where="top" title="Flytta reservation till högst upp i listan">
 <i class="fa fa-lg icon-move-hold-top" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-next_priority="[% next_priority | html %]" data-op="cud-move" data-prev_priority="[% prev_priority | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-where="bottom" title="Flytta reservation till sist i listan">
 <i class="fa fa-lg icon-move-hold-bottom" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-next_priority="[% next_priority | html %]" data-op="cud-move" data-prev_priority="[% prev_priority | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-where="down" title="Flytta reservation nedåt">
 <i class="fa fa-lg icon-move-hold-down" aria-hidden="true"></i>
 </a>
 </td>
 [%- ELSE -%]
 <td></td>
 [%- END -%]
 [%- END -%]
 <td>
 [% INCLUDE 'patron-title.inc' patron=hold.patron hide_patron_infos_if_needed=1 %]
 </td>
 <td>[% hold.notes | html | html_line_break %]</td>
 <td data-order="[% hold.date| html %]">
 [% IF Koha.Preference('AllowHoldDateInFuture') %]
 <input type="text" class="flatpickr" value="[% hold.date | html %]" required="required" size="10" name="reservedate" />
 [% ELSE %]
 [% hold.date | $KohaDates %]
 [% END %]
 </td>
 <td>
 <input type="text" class="flatpickr" data-flatpickr-futuredate="true" value="[% hold.expirationdate | html %]" size="10" name="expirationdate" />
 </td>
 <td>
 [%- IF ( hold.found ) -%]
 <input type="hidden" name="pickup" value="[% hold.wbrcode | html %]" />
 [%- IF ( hold.atdestination ) -%] Exemplar väntar på <strong> [% hold.wbrname | html %]</strong>[% IF hold.desk_name %], [% hold.desk_name | html %],[% END %] sedan [% hold.waiting_date | $KohaDates %] [%- ELSIF (hold.intransit) -%] Exemplar under transport till <strong> [% hold.wbrname | html %]</strong>
 [%- ELSIF (hold.inprocessing) -%] Exemplar hanteras på <strong> [% hold.wbrname | html %]</strong>
 [%- ELSE -%] Reservation förväntad vid <strong>[% hold.wbrname | html %]</strong>, dra åter för att verifiera status [%- END -%] [%- ELSE -%] [%- IF Koha.Preference('IndependentBranches') && Branches.all().size == 1 -%] [% Branches.GetName(hold.branchcode) | html %] <input type="hidden" name="pickup" value="[% hold.branchcode | html %]" />
 [%- ELSE -%]
 <select class="pickup_location_dropdown"
                                    data-selected="[% hold.branchcode | html %]"
                                    data-hold-id="[% hold.reserve_id | html %]"
                                    data-pickup-location-source="hold"
                                    name="pickup">
 <option selected="selected" value="[% hold.branchcode | html %]">[% Branches.GetName(hold.branchcode) | html %]</option>
 <option value="" disabled="disabled" class="loading">Laddar...</option>
 </select>
 <img class="loading_[% hold.reserve_id | html %]" src="[% interface | html %]/[% theme | html %]/img/spinner-small.gif" alt="" style="display:none;"/>
 [%- END -%]
 [%- END -%]
 </td>
 <td>
 [%- IF ( hold.found ) -%]
 <a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% hold.biblionumber | uri %]&amp;itemnumber=[% hold.itemnumber | uri %]#item[% hold.itemnumber | uri %]">
 [%- IF ( hold.barcodenumber ) -%]
 [%- hold.barcodenumber | html -%]
 [%- ELSE -%]
 <span>Ingen streckkod</span>
 [%- END -%]
 <input type="hidden" name="itemnumber" value="[% hold.itemnumber | html %]" />
 </a>
 [%- ELSE -%]
 [%- IF ( hold.item_level_hold ) -%]
 <em>
 [%- IF ! hold.change_hold_type_allowed -%]
 <span>Endast exemplar</span>
 <a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% hold.biblionumber | uri %]&amp;itemnumber=[% hold.itemnumber | uri %]#item[% hold.itemnumber | uri %]">
 [%- IF ( hold.barcodenumber ) -%]
 [%- hold.barcodenumber | html -%]
 [%- ELSE -%]
 <span>Ingen streckkod</span>
 [%- END -%]
 <input type="hidden" name="itemnumber" value="[% hold.itemnumber | html %]" />
 </a>
 [%- ELSE -%]
 <select name="change_hold_type_[% hold.reserve_id | html %]">
 <option selected="selected" value="">Endast exemplar [%- IF ( hold.barcodenumber ) -%][%- hold.barcodenumber | html -%][%- ELSE -%] Ingen streckkod [%- END -%] </option>
 <option value="1">Nästa tillgängliga</option>
 </select>
 [%- IF ( hold.itemnumber ) -%]
 <input type="hidden" name="itemnumber" value="[% hold.itemnumber | html %]" />
 [%- END -%]
 [%- IF hold.itemtype -%]
 <span style="display:none">Nästa tillgängliga [% ItemTypes.GetDescription( hold.itemtype ) | html %] exemplar</span>
 [%- ELSE -%]
 <span style="display:none">Nästa tillgängliga</span>
 [%- END -%]
 [%- END -%]
 </em>
 [%- ELSE -%]
 [%- IF hold.itemtype -%]
 <em>Nästa tillgängliga [% ItemTypes.GetDescription( hold.itemtype ) | html %] exemplar</em>
 [%- ELSIF hold.object.item_group -%]
 <em>Nästa tillgängliga exemplar från grupp <strong>[% hold.object.item_group.description | html %]</strong></em>
 [%- ELSE -%]
 <em>Nästa tillgängliga</em>
 [%- END -%]

 <input type="hidden" name="itemnumber" value="" />
 [%- END -%]
 [%- END -%]
 [%- IF hold.non_priority -%]
 <br><i>Vilande reservation</i>
 [%- END -%]
 </td>
 [%- IF ( CAN_user_reserveforothers_modify_holds_priority ) -%]
 [%- UNLESS hold.found -%]
 <td>
 [% IF ( hold.lowestPriority ) %]
 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-op="cud-setLowestPriority" data-reserve_id="[% hold.reserve_id | html %]" title="Ta bort lägsta prioritet">
 <i class="fa fa-lg fa-rotate-90 icon-unset-lowest" aria-hidden="true"></i>
 [% ELSE %]
 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-op="cud-setLowestPriority" data-reserve_id="[% hold.reserve_id | html %]" title="Ställ in på lägsta prioritet">
 <i class="fa fa-lg fa-rotate-90 icon-set-lowest" aria-hidden="true"></i>
 [% END %]
 </a>
 </td>
 [%- ELSE -%]
 <td></td>
 [%- END -%]
 [%- END -%]
 <td>
 <a class="cancel-hold" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-id="[% hold.reserve_id | html %]" href="#" title="Annullera reservation">
 <i aria-label="Annullera reservation" class="fa fa-trash"></i>
 </a>
 </td>
 <td>
 [% IF Koha.Preference('SuspendHoldsIntranet') %]
 [% UNLESS ( hold.found ) %]
 [% IF ( hold.suspend ) %]
 <button class="btn btn-default btn-xs unsuspend-hold" data-reserve-id="[% hold.reserve_id | html %]" data-biblionumber="[% hold.biblionumber | html %]">
 <i class="fa fa-play" aria-hidden="true"></i> Återuppta </button>
 [% ELSE %]
 <button class="btn btn-default btn-xs suspend-hold" data-reserve-id="[% hold.reserve_id | html %]" data-biblionumber="[% hold.biblionumber | html %]">
 <i class="fa fa-pause" aria-hidden="true"></i> Pausa </button>
 [% END %]

 [% IF Koha.Preference('AutoResumeSuspendedHolds') %]
 <label for="suspend_until_[% hold.reserve_id | html %]">[% IF ( hold.suspend ) %] på [% ELSE %] tills [% END %]</label>
 <input type="text" name="suspend_until_[% hold.reserve_id | html %]" id="suspend_until_[% hold.reserve_id | html %]" size="10" value="[% hold.suspend_until | html %]" class="flatpickr" data-flatpickr-futuredate="true" />
 [%- ELSE -%]
 <input type="hidden" name="suspend_until_[% hold.reserve_id | html %]" id="suspend_until_[% hold.reserve_id | html %]" value=""/>
 [%- END -%]
 [%- END -%]
 [%- END # IF SuspendHoldsIntranet -%]
 [%- IF ( hold.found ) -%]
 <a class="btn btn-default  submit-form-link" href="#" id="revert_hold_[% hold.reserve_id | html %]" data-op="cud-move" data-where="down" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-prev_priority="0" data-next_priority="1" data-borrowernumber="[% hold.borrowernumber | html %]" data-biblionumber="[% hold.biblionumber | html %]" data-itemnumber="[% hold.itemnumber | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-date="[% hold.date | html %]" data-action="request.pl" data-method="post">[% IF hold.intransit %]Ångra transitstatus[% ELSE %]Ångra väntestatus[% END %]</a>
 [%- END -%]
 </td>
 [% IF ( hold.intransit || hold.atdestination ) %]
 <td><input class="printholdslip" data-reserve_id="[% hold.reserve_id | html %]" name="printholdslip" type="button" value="Skriv ut kvitto"></td>
 [% ELSE %]
 <td></td>
 [% END %]
 </tr>
 [% END %]
 </tbody>
</table>
