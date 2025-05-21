[% USE Koha %]
[% INCLUDE 'columns_settings.inc' %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="alert alert-info">
 [% IF report.modified_itemnumbers.size %]
 <span>[% report.modified_itemnumbers.size | html %] exemplar redigerade (med [% report.modified_fields | html %] redigerade fält).</span>
 [% ELSE %]
 <span>Inga exemplar redigerade.</span>
 [% END %]

 [% IF job.status == 'cancelled' %]<span>Jobbet har avbrutits innan det var klart.</span>[% END %]
 <a href="/cgi-bin/koha/tools/batchMod.pl" title="Ny satsvis redigering av exemplar">Ny satsvis redigering av exemplar</a>
 </div>
 [% END %]
[% END %]

[% BLOCK detail %]
 [% FOR m IN job.messages %]
 <div class="alert alert-info">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa-solid fa-triangle-exclamation warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% SWITCH m.code %]
 [% CASE %]<span>Okänt meddelande '[% m.code | html %]'</span>
 [% END %]
 </div>
 [% END %]

 [% IF too_many_items_display %]
 <p>För många exemplar ([% report.modified_itemnumbers.size | html %]): Du har redigerat fler än [% Koha.Preference('MaxItemsToDisplayForBatchMod') | html %] exemplar i en sats, exemplar kommer inte att visas.</p>
 [% ELSIF items.size %]
 [% PROCESS items_table_batchmod headers => item_header_loop, items => items, display_columns_selection => 1 %]
 [% END %]
[% END %]

[% BLOCK js %]
 [% Asset.js("js/pages/batchMod.js") | $raw %]
[% END %]
