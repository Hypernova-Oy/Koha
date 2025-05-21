[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report && job.status != 'started' && job.status != 'new' %]
 [% IF report.total_records == report.total_success %]
 <div class="alert alert-info">
 Kaikki eKokoelma tietueet on luotu! </div>
 [% ELSIF report.total_success == 0 %]
 <div class="alert alert-info">
 eKokoelma tietueita ei luotu. Tapahtui virhe. </div>
 [% ELSE %]
 <div class="alert alert-info">
 [% report.total_success | html %] / [% report.total_records | html %] eKokoelman nimekkeet on luotu, mutta joitakin virheitä esiintyi. </div>
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
 <span>Pakettia #[% m.package_id | html %] ei ole olemassa.</span>
 [% CASE 'biblio_already_exists' %]
 <span>Bibliografinen tietue ([% m.biblio_id | html %]) on jo tässä paketissa (<a href="/cgi-bin/koha/erm/eholdings/local/resources/[% m.resource_id | uri %]">resurssi #[% m.resource_id | html %]</a>)</span>
 [% CASE 'eholding_not_created' %]
 <span>eKokoelma nimekettä ei voida luoda bibliografisesta tietueesta #[% m.biblio_id | html %], tapahtui seuraava virhe: [% m.error | html %].</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
