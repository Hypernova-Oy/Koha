[% IF op == "batch_list" %]
<h1>
 <span>Visa fjärrlånebeställningar</span>
</h1>
<div class="page-section">
 <h2>Detaljer för alla beställningar</h2>
 <table id="ill-batch-requests">
 <thead>
 <tr id="ill-batch-header">
 <th scope="col">Sats-ID</th>
 <th scope="col">Namn</th>
 <th scope="col">Antal beställningar</th>
 <th scope="col">Status</th>
 <th scope="col">Låntagare</th>
 <th scope="col">Bibliotek</th>
 <th scope="col"></th>
 </tr>
 </thead>
 <tbody id="ill-batch-body">
 </tbody>
 </table>
</div>
[% END %]