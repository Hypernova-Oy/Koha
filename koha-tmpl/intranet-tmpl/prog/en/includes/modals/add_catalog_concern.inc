[% USE raw %]
[% USE AdditionalContents %]
[% SET CatalogConcernHelp = AdditionalContents.get( location => "CatalogConcernHelp", lang => lang, library => logged_in_user.branchcode ) %]
[% SET CatalogConcernTemplate = AdditionalContents.get( location => "CatalogConcernTemplate", lang => lang, library => logged_in_user.branchcode ) %]
<!-- Add concern modal -->
<div class="modal" id="addConcernModal" tabindex="-1" role="dialog" aria-labelledby="addConcernModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-content modal-lg">
            <div class="modal-header">
                <h1 class="modal-title" id="addConcernModalLabel">Add concern</h1>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body">
                <fieldset id="concern_fieldset">
                    <ol>
                        <li class="form-group row">
                            <label for="concern_title" class="col-sm-1 col-form-label">Title: </label>
                            <div class="col-sm-11">
                                <input type="text" name="concern_title" id="concern_title" class="form-control" required="required" />
                            </div>
                        </li>
                        <li class="form-group">
                            <label class="required" for="concern_body">Please describe your concern: </label>
                            <textarea class="form-control" id="concern_body" name="concern_body" required="required" rows="15"></textarea>
                            [%- IF CatalogConcernHelp && CatalogConcernHelp.content && CatalogConcernHelp.content.count > 0 -%]
                                <div class="help-block">
                                    [%- FOREACH help IN CatalogConcernHelp.content -%]
                                        [%- help.content | $raw -%]
                                    [%- END -%]
                                </div>
                            [%- END -%]
                            <div style="display:none" id="concern_template">
                                [%- IF CatalogConcernTemplate && CatalogConcernTemplate.content && CatalogConcernTemplate.content.count > 0 -%]
                                    [%- FOREACH template IN CatalogConcernTemplate.content -%]
                                        [%- template.content | $raw -%]
                                    [%- END -%]
                                [%- END -%]
                            </div>
                        </li>
                    </ol>
                </fieldset>
            </div>
            <!-- /.modal-body -->
            <div class="modal-footer">
                <input type="hidden" id="concern_biblio" name="biblio_id" value="[% biblionumber | html %]" />
                <button type="submit" class="btn btn-primary" id="addConfirm">Submit <i id="concern-submit-spinner" class="fa fa-spinner fa-pulse fa-fw" style="display:none"></i></button>
                <button type="button" class="btn btn-default" data-bs-dismiss="modal">Cancel</button>
            </div>
            <!-- /.modal-footer -->
        </div>
        <!-- /.modal-content -->
    </div>
    <!-- /.modal-dialog -->
</div>
<!-- /#addConcernModal -->
