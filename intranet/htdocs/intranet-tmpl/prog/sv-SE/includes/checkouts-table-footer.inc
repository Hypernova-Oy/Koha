<tfoot>
 <tr>
 <td colspan="15" style="text-align: right; font-weight:bold;">Totalt:</td>
 <td id="totaldue" style="text-align: right;"></td>
 <td id="totalfine" style="text-align: right;"></td>
 <td id="totalprice" style="text-align: right;"></td>
 [% IF Koha.Preference('ExportCircHistory') %]
 <td colspan="4">
 [% ELSE %]
 <td colspan="3">
 [% END %]
 <div class="date-select">
 <p><label for="newduedate">Förfallodatum för omlån:</label> <input type="text" size="20" id="newduedate" name="newduedate" value="" class="flatpickr" data-flatpickr-enable-time="true"/></p>
 <p id="newonholdduedate"><label for="newonholdduedatefield">Förfallodatum för reservation:</label> <input type="text" size="20" name="newonholdduedate" value="" id="newonholdduedatefield" class="flatpickr" data-flatpickr-enable-time="true" /></p>
 <p><label for="exemptfine">Efterskänk avgifter vid återlämnande:</label> <input type="checkbox" id="exemptfine" name="exemptfine" value="1" /></p>
 </div>
 </td>
 </tr>
</tfoot>
