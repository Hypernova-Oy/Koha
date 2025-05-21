<div id="avCreate" class="modal" tabindex="-1" role="dialog" aria-labelledby="avCreateLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="avCreateLabel">Skapa ett nytt auktoriserat värde</h1>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <form id="add_new_av" method="get">
 <div class="modal-body">
 <fieldset class="rows">
 <ol>
 <li>
 <span class="label">Kategori:</span>
 <input type="hidden" name="category" value="" />
 <span id="new_av_category"></span>
 </li>
 <li>
 <label for="value" class="required">Auktoriserat värde:</label>
 <input class="required" required="required" type="text" id="value" name="value" />
 <span class="required">Obligatoriskt</span>
 </li>
 <li>
 <label for="description" class="required">Beskrivning:</label>
 <input class="required" required="required" type="text" id="description" name="description" />
 <span class="required">Obligatoriskt</span>
 </li>
 <li>
 <label for="opac_description">Beskrivning (OPAC):</label>
 <input type="text" id="opac_description" name="opac_description" />
 </li>
 </ol>
 </fieldset>
 <div class="avCreate_error alert alert-warning" style="display:none;"></div>
 </div>
 <div class="modal-footer">
 <input type="hidden" name="select2" value="" />
 <button type="submit" class="btn btn-default">Spara</button>
 <button class="btn btn-default" data-bs-dismiss="modal">Avbryt</button>
 </div>
 </form>
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /#avCreate -->
