<div id="multi_receiving" class="modal" tabindex="-1" role="dialog" aria-labelledby="multi_receiving_label" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="multi_receiving_label">Vastaanota useita lehtiä</h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <form action="/cgi-bin/koha/serials/serials-collection.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <div class="modal-body">
 <fieldset class="rows">
 <legend class="sr-only">Vastaanota useita lehtiä</legend>
 <ol>
 <li>
 <label for="nbissues" class="required">Kuinka monta numeroa haluat vastaanottaa?</label>
 <input type="text"  size="25" id="nbissues" name="nbissues" required="required" />
 <li>
 <li>
 <label for="date_received_today">Aseta vastaanottopäiväksi tämä päivä?</label>
 <input type="checkbox" id="date_received_today" name="date_received_today" />
 </li>
 </ol>
 <input type="hidden" name="op" value="cud-gennext" />

 [%# subscriptionidlist is used from serials-collection, subscriptionid is used from serils-edit %]
 <input type="hidden" name="subscriptionid" value="[% subscriptionidlist || subscriptionid | html %]" />
 </fieldset>
 </div>

 <div class="modal-footer">
 <button type="submit" class="btn btn-default approve">OK</button>
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Peruuta</button>
 </div>
 </form>
 </div>
 </div>
</div>
