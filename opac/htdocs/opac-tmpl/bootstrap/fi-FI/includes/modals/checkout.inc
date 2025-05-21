<!-- Checkout form hidden by default, used for modal window -->
<div class="modal" id="checkoutModal" tabindex="-1" role="dialog" aria-labelledby="checkoutModalLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="checkoutModalLabel">Itsepalvelulainaus</h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <div id="checkoutResults"></div>
 <div id="availabilityResult"></div>
 <div class="form-group">
 <label for="checkout_barcode">Lue viivakoodi: </label>
 <input type="text" name="checkout_barcode" id="checkout_barcode" required="required"></input>
 </div>
 <table id="checkoutsTable" class="table table-bordered table-striped" style="width:100%;">
 <thead>
 <tr>
 <th>Viivakoodi</th>
 <th>Nimeke</th>
 <th>Luokka</th>
 <th>Eräpäivä</th>
 </tr>
 </thead>
 <tbody>
 </tbody>
 <tfoot>
 <tr>
 <td colspan="4" class="text-right"><span id="checkoutsCount"></span> lainattua nidettä</td>
 </tr>
 </tfoot>
 </table>
 </div>
 <div class="modal-footer">
 <button type="submit" id="checkoutSubmit" class="btn btn-primary">OK</button>
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Sulje</button>
 </div>
 </div>
 </div>
</div>
