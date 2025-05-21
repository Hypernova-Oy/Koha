[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="alert alert-info">Importen återställdes</div>
 [% END %]
 <table>
 <tr>
 <td>Antal poster som raderats</td>
 <td>[% report.num_deleted | html %]</td>
 </tr>
 <tr>
 <td>Antal poster som återställts</td>
 <td>[% report.num_reverted | html %]</td>
 </tr>
 <tr>
 <td>Antal poster som ignorerats</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>Antal exemplar som raderats</td>
 <td>[% report.num_items_deleted | html %]</td>
 </tr>
 <tr>
 <td>Antal fel</td>
 <td>[% report.num_errors | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">Hantera återställd sats</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
