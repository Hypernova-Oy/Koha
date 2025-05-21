[% USE Koha %]
[% INCLUDE 'columns_settings.inc' %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="alert alert-info">
 [% IF report.modified_itemnumbers.size %]
 <span>[% report.modified_itemnumbers.size | html %] nidettä muokattu (joista [% report.modified_fields | html %] kenttää muokattu).</span>
 [% ELSE %]
 <span>Ei muokattuja niteitä.</span>
 [% END %]

 [% IF job.status == 'cancelled' %]<span>Ajo keskeytettiin ennen kuin se valmistui.</span>[% END %]
 <a href="/cgi-bin/koha/tools/batchMod.pl" title="Uusi niteiden muokkaus eräajona">Uusi niteiden muokkaus eräajona</a>
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
 [% CASE %]<span>Tuntematon viesti '[% m.code | html %]'</span>
 [% END %]
 </div>
 [% END %]

 [% IF too_many_items_display %]
 <p>Liian paljon niteitä ([% report.modified_itemnumbers.size | html %]): Olet muokannut yli [% Koha.Preference('MaxItemsToDisplayForBatchMod') | html %] nidettä erässä, niteitä ei näytetä.</p>
 [% ELSIF items.size %]
 [% PROCESS items_table_batchmod headers => item_header_loop, items => items, display_columns_selection => 1 %]
 [% END %]
[% END %]

[% BLOCK js %]
 [% Asset.js("js/pages/batchMod.js") | $raw %]
[% END %]
