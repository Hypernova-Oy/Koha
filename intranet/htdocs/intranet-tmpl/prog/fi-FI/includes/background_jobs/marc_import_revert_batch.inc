[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="alert alert-info">Tuonnin peruuttaminen onnistui</div>
 [% END %]
 <table>
 <tr>
 <td>Poistettuja tietueita</td>
 <td>[% report.num_deleted | html %]</td>
 </tr>
 <tr>
 <td>Peruutettuja tietueita</td>
 <td>[% report.num_reverted | html %]</td>
 </tr>
 <tr>
 <td>Ohitettuja tietueita</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>Poistettuja niteitä</td>
 <td>[% report.num_items_deleted | html %]</td>
 </tr>
 <tr>
 <td>Virheiden määrä</td>
 <td>[% report.num_errors | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">Hallinnoi peruutettua erää</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
