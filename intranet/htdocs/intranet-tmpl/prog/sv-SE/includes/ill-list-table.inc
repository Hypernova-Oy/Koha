[% IF patron.borrowernumber %]
<table id="ill-requests-patron-[% patron.borrowernumber | html %]">
[% ELSIF batch.id %]
<table id="ill-requests-batch-[% batch.id | html %]">
[% ELSE %]
<table id="ill-requests">
[% END %]
 <thead>
 <tr id="ill_requests_header">
 <th scope="col">Beställningsnr</th>
 <th scope="col">Sats</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="author"         data-related-search-on="value">Författare</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="title"         data-related-search-on="value">Titel</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="article_title" data-related-search-on="value">Artikeltitel</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="issue"         data-related-search-on="value">Nummer</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="volume"        data-related-search-on="value">Volym</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="year"          data-related-search-on="value">År</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="pages"         data-related-search-on="value">Sidor</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="type"          data-related-search-on="value">Typ av fjärrlånebeställning</th>
 <th scope="col">Beställnings-ID</th>
 <th scope="col">Låntagare</th>
 <th scope="col">Bibliografisk post-id</th>
 <th scope="col">Bibliotek</th>
 <th scope="col">Status</th>
 <th scope="col" class="placed_formatted">Lades den</th>
 <th scope="col" class="updated_formatted">Uppdaterad</th>
 <th scope="col">Svarade</th>
 <th scope="col" class="completed_formatted">Avslutad den</th>
 <th scope="col">Åtkomst URL</th>
 <th scope="col">Kostnad</th>
 <th scope="col">Betalat pris</th>
 <th scope="col">Kommentarer</th>
 <th scope="col">OPAC-kommentarer</th>
 <th scope="col">Personalkommentar</th>
 <th scope="col">Backend</th>
 <th scope="col" class="actions"></th>
 </tr>
 </thead>
 <tbody id="illview-body">
 </tbody>
</table>