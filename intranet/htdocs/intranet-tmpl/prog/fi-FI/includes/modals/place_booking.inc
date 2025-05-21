[% USE ItemTypes %]
<!-- Place booking modal -->
<div class="modal" id="placeBookingModal" tabindex="-1" role="dialog" aria-labelledby="placeBookingLabel">
 <form method="get" id="placeBookingForm">
 <div class="modal-dialog modal-lg">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="placeBookingLabel"></h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <div id="booking_result"></div>
 <fieldset class="brief">
 <input type="hidden" name="biblio_id" id="booking_id">
 <input type="hidden" name="biblio_id" id="booking_biblio_id">
 <input type="hidden" name="start_date" id="booking_start_date">
 <input type="hidden" name="end_date" id="booking_end_date">
 <ol>
 <li>
 <label class="required" for="booking_patron_id">Asiakas: </label>
 <select name="booking_patron_id" id="booking_patron_id" required="required">
 <option></option>
 [% IF patron %]
 <option value="[% borrowernumber | uri %]" selected="selected">[% patron.firstname | html %] [% patron.surname | html %] ([% patron.cardnumber | html %] )</option>
 [% END %]
 </select>
 <div class="hint">Syötä kirjastokortin numero tai osa nimestä</div>
 </li>
 <li>
 <label class="required" for="pickup_library_id">Noutopaikka:</label>
 <select name="booking_pickup" id="pickup_library_id" required="required" disabled="disabled"></select>
 <span class="required">Pakollinen tieto</span>
 </li>
 <li>
 <label for="booking_itemtype">Nidetyyppi: </label>
 <select id="booking_itemtype" name="booking_itemtype" disabled="disabled">
 </select>
 <li>
 <label for="booking_item_id">Nide: </label>
 <select name="booking_item_id" id="booking_item_id" disabled="disabled">
 <option value="0">Mikä tahansa nide</option>
 </select>
 </li>
 <li>
 <div id="period_fields">
 <label class="required" for="period">Käyttövarauksen päivämääräväli: </label>
 <input type="text" id="period" name="period" class="flatpickr" data-flatpickr-futuredate="true" data-flatpickr-disable-shortcuts="true" required="required" disabled="disabled" autocomplete="off">
 <span class="required">Pakollinen tieto</span>
 </div>
 <div class="hint">Valitse käyttövarauksen alku- ja loppupäivämäärä</div>
 </li>
 </ol>
 </fieldset>
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <button type="submit" class="btn btn-primary">OK</button>
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Peruuta</button>
 </div> <!-- /.modal-footer -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
 </form>
</div> <!-- /#placeBookingModal -->
