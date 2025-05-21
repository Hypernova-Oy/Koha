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
 [% IF m.code == 'authority_not_exists' %]
 <span>Auktoritets-ID [% m.authid | html %] finns inte i databasen.</span>
 [% ELSIF m.code == 'authority_not_deleted' %]
 <span>Auktoritetsposten [% m.authid | html %] kunde inte tas bort. Ett fel uppstod.</span>
 [% ELSIF m.code == 'authority_deleted' %]
 <span>Auktoriserat värde [% m.authid | html %] har tagits bort.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
