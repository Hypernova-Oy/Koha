[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_biblios == report.total_success %]
 <div class="alert alert-info">
 Reservationskön har uppdaterats. </div>
 [% ELSE %]
 <div class="alert alert-info">
 <span>Reservationskön för [% report.total_success | html %] / [% report.total_biblios | html %] har uppdaterats, men vissa fel uppstod.</span>
 [% IF job.status == 'cancelled' %]<span>Jobbet har avbrutits innan det var klart.</span>[% END %]
 </div>
 [% END %]
 [% END %]

[% END %]

[% BLOCK detail %]
 [% FOR m IN report_messages %]
 <div class="alert alert-info">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa-solid fa-triangle-exclamation warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% SWITCH m.code %]
 [% CASE 'holds_queue_update_error' %]
 [% IF m.biblio_id %]
 <span>Reservationskö för biblio <a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% m.biblio_id | uri %]">[% m.biblio.title | html %]</a>.</span>
 [% END %]
 <span>Ett fel har inträffat ([% m.error | html %])</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
