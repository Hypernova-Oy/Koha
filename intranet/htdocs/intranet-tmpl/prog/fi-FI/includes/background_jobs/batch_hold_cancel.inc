[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_holds == report.total_success %]
 <div class="alert alert-info">
 Kaikki varaukset on peruutettu! </div>
 [% ELSE %]
 <div class="alert alert-info">
 <span>[% report.total_success | html %] / [% report.total_holds | html %] varauksen muokkaus onnistui. Joitain virheitä esiintyi.</span>
 [% IF job.status == 'cancelled' %]<span>Ajo keskeytettiin ennen kuin se valmistui.</span>[% END %]
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
 [% CASE 'hold_not_cancelled' %]
 [% IF m.biblio && m.patron %]
 <span>Varaus teoksessa <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% m.biblio.biblionumber | uri %]">[% m.biblio.title | html %]</a> kohteelle <a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% m.patron.borrowernumber | uri %]">[% INCLUDE 'patron-title.inc' patron=m.patron %]</a> ei peruutettu.</span>
 [% END %]
 <span>Peruutettaessa tapahtui virhe.</span>
 [% SWITCH m.error %]
 [% CASE 'hold_not_found' %]
 <span>Varausta ID:llä [% m.hold_id | html %] ei löytynyt.</span>
 [% CASE %]<span>Tuntematon virhe '[% m.error | html %]'.</span>
 [% END %]
 [% CASE 'hold_cancelled' %]
 [% biblio_link = BLOCK %]<a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% m.biblio_id | uri %]">[% m.biblio.title | html %]</a>[% END %]
 [% patron_link = BLOCK %]<a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% m.patron_id | uri %]">[% INCLUDE 'patron-title.inc' patron=m.patron %]</a>[% END %]
 <span>Varaus [% biblio_link | $raw | $KohaSpan %] asiakkaalle [% patron_link | $raw | $KohaSpan %] on peruutettu.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
