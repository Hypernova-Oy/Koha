[% USE Koha %]
[% IF ( relatives_issues_count ) %]
 <table id="relatives-issues-table" style="width: 100% !Important;">
 <thead>
 <tr>
 <th scope="col">Eräpäivä (alustamaton, piilotettu)</th>
 <th scope="col">Eräpäivä</th>
 <th scope="col">Nimeke</th>
 <th scope="col">Aineistotyyppi</th>
 <th scope="col">Nidetyyppi</th>
 <th scope="col">Kokoelma</th>
 <th scope="col">Paikka</th>
 <th scope="col">Lainattu (piilotettu, muotoilematon)</th>
 <th scope="col">Lainattu</th>
 <th scope="col">Lainauspiste</th>
 <th scope="col">Luokka</th>
 <th scope="col">Kappaleen numero</th>
 <th scope="col">Maksu</th>
 <th scope="col">Myöhästymismaksu</th>
 <th scope="col">Hinta</th>
 <th scope="col">Asiakas</th>
 </tr>
 </thead>
 </table>
[% END %]
