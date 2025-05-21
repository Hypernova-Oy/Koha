<div id="generate_next" class="modal" tabindex="-1" role="dialog" aria-labelledby="generate_next" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <form action="/cgi-bin/koha/serials/serials-collection.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <div class="modal-body">
 <fieldset class="rows">
 <legend>Vill du verkligen generera nästa periodika?</legend>
 <input type="hidden" name="op" value="cud-gennext" />
 <input type="hidden" name="subscriptionid" value="[% subscriptionidlist || subscriptionid | html %]" />
 </fieldset>
 </div>

 <div class="modal-footer">
 <button type="submit" class="btn btn-default approve">Ja</button>
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Avbryt</button>
 </div>
 </form>
 </div>
 </div>
</div>
