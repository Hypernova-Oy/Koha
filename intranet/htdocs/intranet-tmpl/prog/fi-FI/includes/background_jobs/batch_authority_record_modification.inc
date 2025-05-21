[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="alert alert-info">
 Kaikki tietueet on muokattu! <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="Uusi tietueiden muokkaus eräajona">Uusi tietueiden muokkaus eräajona</a>
 </div>
 [% ELSE %]
 <div class="alert alert-info">
 <span>[% report.total_success | html %] / [% report.total_records | html %] tietueen muokkaus onnistui. Joitain virheitä esiintyi.</span>
 [% IF job.status == 'cancelled' %]<span>Ajo keskeytettiin ennen kuin se valmistui.</span>[% END %]
 <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="Uusi tietueiden muokkaus eräajona">Uusi tietueiden muokkaus eräajona</a>
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
 <span>Auktoriteettitietuetta [% authority_link | $raw | $KohaSpan %] ei ole muokattu. Muokkauksen aikana tapahtui virhe</span>
 [% IF m.error %] ([% m.error | html %])[% END %].
 [% CASE 'authority_modified' %]
 <span>Auktoriteettitietue [% authority_link | $raw | $KohaSpan %] on muokattu.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
