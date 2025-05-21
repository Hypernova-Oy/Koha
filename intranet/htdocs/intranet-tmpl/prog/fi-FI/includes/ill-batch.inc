[% IF op == "batch_list" %]
<h1>
 <span>Tarkastele kaukolainapyyntöjen eriä</span>
</h1>
<div class="page-section">
 <h2>Kaikkien erien tiedot</h2>
 <table id="ill-batch-requests">
 <thead>
 <tr id="ill-batch-header">
 <th scope="col">Eräajon tunnus</th>
 <th scope="col">Nimi</th>
 <th scope="col">Pyyntöjä</th>
 <th scope="col">Tila</th>
 <th scope="col">Asiakas</th>
 <th scope="col">Kirjasto</th>
 <th scope="col"></th>
 </tr>
 </thead>
 <tbody id="ill-batch-body">
 </tbody>
 </table>
</div>
[% END %]