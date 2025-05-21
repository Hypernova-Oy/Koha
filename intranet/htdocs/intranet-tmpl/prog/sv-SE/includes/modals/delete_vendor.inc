<!-- Delete Vendor modal form -->
<div id="deleteVendorModal" class="modal" tabindex="-1" role="dialog" aria-labelledby="deleteVendorModalLabel">
 <form method="post" action="/cgi-bin/koha/acqui/supplier.pl">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete" />
 <input type="hidden" name="booksellerid" id="booksellerid" value="" />
 <div class="modal-dialog" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <h4 class="modal-title" id="deleteVendorModalLabel">Ta bort leverantör</h4>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <p>Är du säker på att du vill radera denna leverantör?</p>
 </div>
 <div class="modal-footer">
 <button type="submit" id="deleteVendorModaConfirmBtn" class="btn btn-default approve"><i class="fa fa-check" aria-hidden="true"></i> Ja</button>
 <button type="button" id="deleteVendorModaCancelBtn" data-bs-dismiss="modal" class="btn btn-default deny"><i class="fa fa-times" aria-hidden="true"></i> Nej</button>
 </div>
 </div>
 </div>
 </form>
</div>
