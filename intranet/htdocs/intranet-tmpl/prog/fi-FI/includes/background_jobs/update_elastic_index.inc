[% USE Koha %]

[% SET report = job.decoded_data %]
[% BLOCK report %]
 [% IF job.status == 'finished' %]
 [% IF report %]
 <div class="alert alert-info">
 [% report.record_ids.size | html %] tietuetta on uudelleen indeksoitu. </div>
 [% ELSE %]
 <div class="alert alert-info">
 Työn tietoja ei voitu lukea, katso lokeilta tarkemmat tiedot </div>
 [% END %]
 [% ELSIF job.status == 'cancelled' %]
 <span>Ajo keskeytettiin ennen kuin se valmistui.</span>
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
 [% END %] [% SWITCH m.code %] [% CASE 'index_error' %] Jotain meni pieleen indeksoinnin aikana: [% m.error | html %] [% END %] </div>
 [% END %]
 [% IF report %]
 <h3> Tietue IDt:</h3>
 <ul>
 [% FOREACH record_id IN report.record_ids %]
 <li><a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% record_id | uri %]">[% record_id | html %]</a></li>
 [% END %]
 </ul>
 [% END %]
[% END %]


[% BLOCK js %]
[% END %]
