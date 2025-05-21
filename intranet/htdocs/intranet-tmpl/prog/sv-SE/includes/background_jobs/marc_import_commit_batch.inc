[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="alert alert-info">Slutförde import av poster</div>
 [% END %]
 <table>
 <tr>
 <td>Antal poster som lagts till</td>
 <td>[% report.num_added | html %]</td>
 </tr>
 <tr>
 <td>Antal poster som uppdaterats</td>
 <td>[% report.num_updated | html %]</td>
 </tr>
 <tr>
 <td>Antal poster som ignorerats</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>Antal exemplar som lagts till</td>
 <td>[% report.num_items_added | html %]</td>
 </tr>
 <tr>
 <td>Antal ersatta exemplar</td>
 <td>[% report.num_items_replaced | html %]</td>
 </tr>
 <tr>
 <td>Antal exemplar som ignoreras</td>
 <td>[% report.num_items_errored | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">Hantera importerad sats</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
