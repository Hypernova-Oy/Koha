[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report && job.status != 'started' && job.status != 'new' %]
 [% IF report.total_records == report.total_success %]
 <div class="alert alert-info">
 Alla eHolding-titlar har skapats! </div>
 [% ELSIF report.total_success == 0 %]
 <div class="alert alert-info">
 Ingen eHolding-titel blev skapad. Ett fel inträffade. </div>
 [% ELSE %]
 <div class="alert alert-info">
 [% report.total_success | html %] / [% report.total_records | html %] eHolding-titlar har skapats men några fel inträffade. </div>
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
 [% CASE 'package_do_not_exist' %]
 <span>Paketet #[% m.package_id | html %] finns inte.</span>
 [% CASE 'biblio_already_exists' %]
 <span>Den bibliografiska posten ([% m.biblio_id | html %]) finns redan i denna databas (<a href="/cgi-bin/koha/erm/eholdings/local/resources/[% m.resource_id | uri %]">resurs #[% m.resource_id | html %]</a>)</span>
 [% CASE 'eholding_not_created' %]
 <span>eHolding-titel kan inte skapat från den bibliografiska posten #[% m.biblio_id | html %], stötte på följande problem: [% m.error | html %].</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
