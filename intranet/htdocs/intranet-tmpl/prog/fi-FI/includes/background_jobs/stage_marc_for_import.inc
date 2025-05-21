[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="alert alert-info">Tietueiden välivarastointi on valmis</div>
 [% END %]

 <h2>MARC-välivarastoinnin tulokset</h2>
 [% SWITCH job.decoded_data.record_type %]
 [% CASE 'biblio' %]
 <h3>Käsitellään nimeketietueita</h3>
 [% CASE 'auth' %]
 <h3>Käsitellään auktoriteettitietueita</h3>
 [% END %]
 <ul>
 <li>[% report.total | html %] tietuetta tiedostossa</li>
 <li>[% report.import_errors | html %] tietueita ei välivarastoitu MARC-formaattivirheen takia</li>
 <li>[% report.staged | html %] tietuetta välivarastoitu</li>
 [% IF ( report.checked_matches ) %]
 <li>[% report.matched | html %] tietuetta, joille ainakin yksi osuma kullekin hakuehdolle aineistoluettelossa &quot;[% report.matcher_code | html %]&quot;</li>
 [% ELSE %]
 [% IF ( report.matcher_failed ) %]
 <li>Tietueiden täsmäytys epäonnistui -- täsmäytyssäännön hakeminen epäonnistui.</li>
 [% ELSE %]
 <li>Osuvuuksia ei tarkistettu luettelossa jo olemassa olevista tietueista</li>
 [% END %]
 [% END %]
 [% IF report.record_type == 'biblio' %]
 <li>[% report.num_items | html %] nidetietuetta löydetty ja välivarastoitu</li>
 [% END %]
 [% IF ( report.label_batch ) %]
 <li>Luotiin tarratulostuksen erä #[% report.label_batch | html %] </li>
 [% END %]
 </ul>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | uri %]">Näytä erä</a>
 </p>
 [% IF report.basket_id && report.vendor_id %]
 <p>
 <a id="addtobasket" class="btn btn-default" href="/cgi-bin/koha/acqui/addorderiso2709.pl?import_batch_id=[% report.import_batch_id | html %]&basketno=[% report.basket_id | html %]&booksellerid=[% report.vendor_id | html %]">Lisää välivarastoituja tiedostoja tilauskoriin</a>
 </p>
 [% END %]
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
