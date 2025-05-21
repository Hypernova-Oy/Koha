[% USE Koha %]
[% IF ( relatives_issues_count ) %]
 <table id="relatives-issues-table" style="width: 100% !Important;">
 <thead>
 <tr>
 <th scope="col">Återlämningsdatum (oformatterat, dolt)</th>
 <th scope="col">Återlämningsdatum</th>
 <th scope="col">Titel</th>
 <th scope="col">Exemplartyp (bibliografisk)</th>
 <th scope="col">Exemplartyp</th>
 <th scope="col">Avdelning</th>
 <th scope="col">Plats</th>
 <th scope="col">Utlånad den (dolt, oformatterat)</th>
 <th scope="col">Utlånad den</th>
 <th scope="col">Utlånad från</th>
 <th scope="col">Hyllsignatur</th>
 <th scope="col">Ex.nummer</th>
 <th scope="col">Avgift</th>
 <th scope="col">Avgift</th>
 <th scope="col">Pris</th>
 <th scope="col">Låntagare</th>
 </tr>
 </thead>
 </table>
[% END %]
