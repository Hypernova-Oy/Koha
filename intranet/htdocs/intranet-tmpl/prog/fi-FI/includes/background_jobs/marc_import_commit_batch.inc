[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="alert alert-info">Tietueiden tuonti on valmis</div>
 [% END %]
 <table>
 <tr>
 <td>Lisättyjä tietueita</td>
 <td>[% report.num_added | html %]</td>
 </tr>
 <tr>
 <td>Päivitettyjä tietueita</td>
 <td>[% report.num_updated | html %]</td>
 </tr>
 <tr>
 <td>Ohitettuja tietueita</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>Lisättyjä niteitä</td>
 <td>[% report.num_items_added | html %]</td>
 </tr>
 <tr>
 <td>Korvattuja niteitä</td>
 <td>[% report.num_items_replaced | html %]</td>
 </tr>
 <tr>
 <td>Ohitettuja niteitä</td>
 <td>[% report.num_items_errored | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">Hallinnoi tuontierää</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
