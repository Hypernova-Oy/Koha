<div id="toolbar" class="btn-toolbar">
 [% IF ( CAN_user_reports_create_reports ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa fa-plus"></i> Ny rapport</button>
 <ul class="dropdown-menu">
 <li id="newmenuc"><a class="dropdown-item" href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form">Ny rapport med guide</a> </li>
 <li id="newsql"><a class="dropdown-item" href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form_sql">Ny SQL-rapport</a> </li>
 [% IF Koha.Preference('Mana')==1 %]
 <li id="new_mana_sql"><a class="dropdown-item" href="#" data-bs-toggle="modal" data-bs-target="#mana_search_result">Ny SQL-rapport från Mana</a> </li>
 [% END %]
 </ul>
 </div>
 [% END %]

 [% IF ( showsql || execute || editsql || save_successful ) %]
 [% IF ( CAN_user_reports_delete_reports && !CAN_user_reports_create_reports ) %]
 <div class="btn-group">
 <form>
 <input type="hidden" name="op" value="cud-delete" />
 <input type="hidden" name="id" value="[% id | html %]" />
 <button type="submit" class="delete btn btn-default">
 <i class="fa fa-trash-can"></i> Ta bort </button>
 </form>
 </div>
 [% ELSE %]
 [% IF ( CAN_user_reports_create_reports || CAN_user_reports_delete_reports ) %]
 <div class="btn-group">
 <button type="button" class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-haspopup="true"
                        aria-expanded="false">
 <i class="fa-solid fa-pencil" aria-hidden="true"></i> Redigera </button>
 <ul class="dropdown-menu">
 [% IF ( CAN_user_reports_create_reports ) %]
 [% UNLESS ( editsql ) # Do not show edit button on edit page %]
 <li>
 <a class="dropdown-item" id="editreport" href="/cgi-bin/koha/reports/guided_reports.pl?id=[% id | html %]&amp;op=edit_form">
 Redigera </a>
 </li>
 [% END %]
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/reports/guided_reports.pl?op=duplicate&id=[% id | uri %]" title="Kopiera denna sparade rapport">
 Duplicera </a>
 </li>
 [% END %]

 [% IF ( CAN_user_reports_delete_reports ) %]
 <li>
 <form method="post" action="/cgi-bin/koha/reports/guided_reports.pl">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete" />
 <input type="hidden" name="id" value="[% id | html %]" />
 <a class="dropdown-item submit-form-link" href="#" data-id="[% id | html %]" data-action="guided_reports.pl" data-method="post" data-op="cud-delete" data-confirmation-msg="Are you sure you want to delete this report?">Ta bort</a>
 </form>
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
 [% END %]
 [% END %]

 [% IF ( showsql || execute || editsql || save_successful ) %]
 [% UNLESS ( errors ) # Unless there are errors saving a report %]
 <div class="btn-group">
 <a id="runreport" class="btn btn-default" href="/cgi-bin/koha/reports/guided_reports.pl?id=[% id | html %]&amp;op=run">
 <i class="fa fa-play"></i> Kör rapport </a>
 </div>
 [% IF templates.count %]
 <div class="btn-group">
 <button type="button" class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-haspopup="true"
                    aria-expanded="false">
 <i class="fa fa-code"></i> Kör via mall </button>
 <ul class="dropdown-menu">
 [% FOREACH tmpl IN templates %]
 <li>
 <a class="dropdown-item" id="runreport_[% tmpl.id | html %]" href="/cgi-bin/koha/reports/guided_reports.pl?id=[% id | html %]&amp;op=run&amp;template=[% tmpl.id | html %][% PROCESS params %]">
 [% tmpl.name | html %]
 </a>
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
 <div class="btn-group">
 <a class="btn btn-default" href="/cgi-bin/koha/tools/scheduler.pl?id=[% id | html %]">
 <i class="fa-solid fa-clock"></i> Schema </a>
 </div>
 [% END %]

 [% IF ( mana_id && Koha.Preference('Mana') == 1 ) %]
 <div class="btn-group">
 <button class="btn btn-default btn-sm dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"> Rapportera misstag</button>
 <ul class="dropdown-menu">
 [% FOREACH c IN mana_comments %]
 <li class="mana-comment" data-id="[% c.id | $raw %]">
 <a class="dropdown-item" href="#">[% c.message | html %] ([% c.nb | html %])</a>
 </li>
 [% END %]
 <li><hr class="dropdown-divider"></li>
 <li class="mana-other-comment"><a class="dropdown-item" href="#">Annat</a> </li>
 </ul>
 </div>

 <div id="mana-comment-box" class="modal" tabindex="-1" role="dialog" aria-labelledby="mana_search_result_label">
 <div class="modal-dialog modal-lg">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="mana_submit_comment">Skriv en ny kommentar (max 35 tecken)</h1>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <input hidden="hidden" id="mana-resource" value="rapport">
 <input hidden id="mana-resource-id" value="[% mana_id | $raw %]">
 <div>
 <input type="text" maxlength="35" size="35" id="mana-comment">
 </div>
 <button id="mana-send-comment"> Kommentar </button>
 </div>
 </div>
 </div>
 </div>
 [% END %] [% IF ( execute ) %] [% BLOCK params %] [%- FOREACH param IN sql_params %]&amp;sql_params=[% param | uri %][% END %] [%- FOREACH param_name IN param_names %]&amp;param_name=[% param_name | uri %][% END %] [%- END %] <div class="btn-group">
 <button aria-haspopup="menu" aria-label="Välj nedladdningsformat" class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" id="format"><i class="fa fa-download"></i> Ladda ned</button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" id="csv" href="/cgi-bin/koha/reports/guided_reports.pl?op=export&amp;format=csv&amp;id=[% id | html %]&amp;reportname=[% name |uri %][% PROCESS params %]">[% PROCESS 'delimiter_text.inc' %]</a></li>
 <li><a class="dropdown-item" id="tab" href="/cgi-bin/koha/reports/guided_reports.pl?op=export&amp;format=tab&amp;id=[% id | html %]&amp;reportname=[% name |uri %][% PROCESS params %]">Tabbseparerad text</a></li>
 [% IF Koha.Preference('ReportsExportFormatODS') %]
 <li><a class="dropdown-item" id="ods" href="/cgi-bin/koha/reports/guided_reports.pl?op=export&amp;format=ods&amp;id=[% id | html %]&amp;reportname=[% name |uri %][% PROCESS params %]">OpenDocument-kalkylblad</a></li>
 [% END %]
 [% IF processed_notice_title %]
 <li><a class="dropdown-item" id="template" href="/cgi-bin/koha/reports/guided_reports.pl?op=export&amp;format=template&amp;id=[% id | html %]&amp;template=[% template_id | html %]&amp;reportname=[% name |uri %][% PROCESS params %]">Renderad mall ([% processed_notice_title | html %])</a></li>
 [% END %]
 [% IF (results.json) %]
 <li><a class="dropdown-item" id="download-chart" href="#">Diagram (.svg)</a></li>
 [% END %]
 </ul>
 </div>
 <div class="btn-group">
 <button type="button" id="toggle_sql" class="btn btn-default toggle_sql" data-complete-text="<i class='fa-solid fa-eye-slash'></i> [% t('Hide SQL code') | html %]" data-bs-toggle="button" aria-pressed="false" autocomplete="off">
 <i class="fa-solid fa-eye"></i> Visa SQL-kod </button>
 </div>
 <div class="btn-group">
 [% IF allresults.size %]
 <a class="btn btn-default" href="#" data-bs-toggle="modal" data-bs-target="#chartModal"><i class="fa fa-chart-bar"></i> Skapa diagram</a>
 [% ELSE %]
 <a class="btn btn-default" href="#" data-bs-toggle="modal" data-bs-target="#chartModal"><i class="fa fa-chart-bar"></i> Skapa diagram</a>
 <a class="btn btn-default fetch_chart_data" href="/cgi-bin/koha/reports/guided_reports.pl?id=[% id | html %]&amp;op=run&amp;reportname=[% name |uri %][% PROCESS params %]&amp;want_full_chart=1"><i class="fa fa-chart-bar"></i> Hämta all data för diagram</a>
 [% END %]

 </div>
 [% END %]

 [% END %]
</div>

[% IF Koha.Preference('Mana')==1 %]
 <div id="mana_search_result" class="modal" tabindex="-1" role="dialog" aria-labelledby="mana_search_result_label">
 <div class="modal-dialog modal-lg">
 <form method="get" id="mana_search_form">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="mana_search_result_label">Sök i Mana</h1>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <div id="mana_search_failed" class="alert alert-warning mana_search_status" style="display:none">
 Din sökning kunde inte slutföras. Försök igen senare. <div id="mana_search_errortext"></div>
 </div>
 <div id="mana_use_failed" class="alert alert-warning mana_search_status" style="display:none">
 Det gick inte att importera rapporten. Försök igen lite senare. <div id="mana_use_errortext"></div>
 </div>
 <fieldset>
 <p>
 Sök rapporter med nyckelord: <input type="text" id="mana_search_field" />
 <input class="mana_search_button" type="submit" value="Sök" />
 <span id="mana-loading" style="display:none"> <img src="[% interface | html %]/[% theme | html %]/img/spinner-small.gif" alt="" /> Laddar </span>
 </p>
 </fieldset>
 <div id="mana_result_content">
 </div>
 </div>
 <div class="modal-footer">
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Avbryt</button>
 </div>
 </div>
 </form>
 </div>
 </div>
[% END %]
