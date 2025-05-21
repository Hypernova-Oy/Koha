[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="alert alert-info">
 Kaikki tietueet on poistettu! </div>
 [% ELSIF report.total_success == 0 %]
 <div class="alert alert-info">
 Tietueita ei poistettu. Tapahtui virhe. </div>
 [% ELSE %]
 <div class="alert alert-info">
 [% report.total_success | html %] / [% report.total_records | html %] tietueen poisto onnistui, mutta joitakin virheitä esiintyi. </div>
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
 <span>Auktoriteetin ID:tä [% m.authid | html %] ei löydy tietokannasta.</span>
 [% ELSIF m.code == 'authority_not_deleted' %]
 <span>Auktoriteettitietuetta [% m.authid | html %] ei poistettu. Tapahtui virhe.</span>
 [% ELSIF m.code == 'authority_deleted' %]
 <span>Auktoriteetti [% m.authid | html %] on poistettu.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
