[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="alert alert-info">
 Alla poster har tagits bort! </div>
 [% ELSIF report.total_success == 0 %]
 <div class="alert alert-info">
 Ingen post blev borttagen. Ett fel inträffade. </div>
 [% ELSE %]
 <div class="alert alert-info">
 [% report.total_success | html %] / [% report.total_records | html %] poster har blivit borttagna utan att några fel inträffade. </div>
 [% END %]
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
 [% CASE 'biblio_not_exists' %]
 <span>Biblionummer [% m.biblionumber | html %] finns inte i databasen.</span>
 [% CASE 'item_issued' %]
 <span>Det är minst ett exemplar utlånat i posten [% m.biblionumber | html %].</span>
 [% CASE 'reserve_not_cancelled' %]
 <span>Den bibliografiska posten [% m.biblionumber | html %] kunde inte tas bort eftersom en reservation inte kunde tas bort (reserve_id [% m.reserve_id | html %]).</span>
 [% CASE 'item_not_deleted' %]
 <span>Bibliografiska posten [% m.biblionumber | html %] blev inte borttagen. Ett fel inträffade när exemplaret skulle tas bort (exemplarnummer [% m.itemnumber | html %]).</span>
 [% CASE 'biblio_not_deleted' %]
 <span>Den bibliografiska posten [% m.biblionumber | html %] kunde inte tas bort. Ett fel uppstod.</span>
 [% CASE 'biblio_deleted' %]
 <span>Bibliografiska poster [% m.biblionumber | html %] har tagits bort.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
