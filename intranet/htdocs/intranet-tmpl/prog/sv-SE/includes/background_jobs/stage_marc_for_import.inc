[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="alert alert-info">Slutförde hantering av poster</div>
 [% END %]

 <h2>MARC förberedda resultat</h2>
 [% SWITCH job.decoded_data.record_type %]
 [% CASE 'biblio' %]
 <h3>Bearbetar bibliografiska poster</h3>
 [% CASE 'auth' %]
 <h3>Bearbetar auktoritetsposter</h3>
 [% END %]
 <ul>
 <li>[% report.total | html %] poster i fil</li>
 <li>[% report.import_errors | html %] poster inte förberedda på grund av MARC-fel</li>
 <li>[% report.staged | html %] poster förberedda</li>
 [% IF ( report.checked_matches ) %]
 <li>[% report.matched | html %] poster med minst en träff i katalog per matchningsregel &quot;[% report.matcher_code | html %]&quot;</li>
 [% ELSE %]
 [% IF ( report.matcher_failed ) %]
 <li>Postmatchning misslyckades – kan inte ladda vald matchningsregel.</li>
 [% ELSE %]
 <li>Kontrollerade inte om träffar fanns i katalogens befintliga poster</li>
 [% END %]
 [% END %]
 [% IF report.record_type == 'biblio' %]
 <li>[% report.num_items | html %] exemplarsposter hittade och förberedda</li>
 [% END %]
 [% IF ( report.label_batch ) %]
 <li>Ny etikettsats skapad: # [% report.label_batch | html %] </li>
 [% END %]
 </ul>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | uri %]">Visa sats</a>
 </p>
 [% IF report.basket_id && report.vendor_id %]
 <p>
 <a id="addtobasket" class="btn btn-default" href="/cgi-bin/koha/acqui/addorderiso2709.pl?import_batch_id=[% report.import_batch_id | html %]&basketno=[% report.basket_id | html %]&booksellerid=[% report.vendor_id | html %]">Lägg till förberedda filer till korg</a>
 </p>
 [% END %]
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
