<!-- Resolve Return Claim Modal -->
<div class="modal" id="claims-returned-resolved-modal" tabindex="-1" role="dialog" aria-labelledby="claims-returned-resolved-modal-label">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="claims-returned-resolved-modal-label">Ratkaise palautusilmoitus</h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">

 <div class="form-group">
 <label for="claims-returned-resolved-modal-resolved-code">Ratkaisu</label>
 [% SET resolutions = AuthorisedValues.GetAuthValueDropbox('RETURN_CLAIM_RESOLUTION') %]
 <select class="form-select" id="claims-returned-resolved-modal-resolved-code">
 [% FOREACH r IN resolutions %]
 <option value="[% r.authorised_value | html %]">[% r.lib | html %]</option>
 [% END %]
 </select>

 <label for="new_lost_status">Uusi kadonnut-arvo niteelle:</label>
 [% SET itemlost = AuthorisedValues.GetAuthValueDropbox('LOST') %]
 <select class="form-select" id="new_lost_status">
 <option value="0">(Ei kadoksissa)</option>
 [% FOREACH lost IN itemlost %]
 <option value="[% lost.authorised_value | html %]">[% lost.lib | html %]</option>
 [% END %]
 </select>
 </div>

 <input type="hidden" id="claims-returned-resolved-modal-id"/>
 </div>
 <div class="modal-footer">
 <button id="claims-returned-resolved-modal-btn-submit" type="button" class="btn btn-primary">
 <i id="claims-returned-resolved-modal-btn-submit-icon" class="fa fa-exclamation-circle"></i>
 <i id="claims-returned-resolved-modal-btn-submit-spinner" class="fa fa-spinner fa-pulse fa-fw" style="display:none"></i>
 Ratkaise ilmoitus </button>
 <button class="btn btn-default deny cancel" data-bs-dismiss="modal"><i class="fa fa-times"></i> Peruuta</button>
 </div>
 </div>
 </div>
</div>
