[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="alert alert-info">
 Alla poster har blivit ändrade! <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="Ny satsvis redigering av poster">Ny satsvis redigering av poster</a>
 </div>
 [% ELSE %]
 <div class="alert alert-info">
 <span>[% report.total_success | html %] / [% report.total_records | html %] poster har redigerats, men vissa fel uppstod.</span>
 [% IF job.status == 'cancelled' %]<span>Jobbet har avbrutits innan det var klart.</span>[% END %]
 <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="Ny satsvis redigering av poster">Ny satsvis redigering av poster</a>
 </div>
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
 [% authority_link = BLOCK %]<a href="/cgi-bin/koha/authorities/detail.pl?authid=[% m.authid | uri %]">[% m.authid | html %]</a>[% END %]
 [% SWITCH m.code %]
 [% CASE 'authority_not_modified' %]
 <span>Auktoritetsposten [% authority_link | $raw | $KohaSpan %] har inte ändrats eftersom ett fel inträffade.</span>
 [% IF m.error %] ([% m.error | html %])[% END %].
 [% CASE 'authority_modified' %]
 <span>Auktoritetsposten [% authority_link | $raw | $KohaSpan %] har ändrats.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
