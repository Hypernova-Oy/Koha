[% IF patron.borrowernumber %]
<table id="ill-requests-patron-[% patron.borrowernumber | html %]">
[% ELSIF batch.id %]
<table id="ill-requests-batch-[% batch.id | html %]">
[% ELSE %]
<table id="ill-requests">
[% END %]
 <thead>
 <tr id="ill_requests_header">
 <th scope="col">Pyynnön ID</th>
 <th scope="col">Erä</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="author"         data-related-search-on="value">Tekijä</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="title"         data-related-search-on="value">Nimeke</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="article_title" data-related-search-on="value">Artikkelin nimeke</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="issue"         data-related-search-on="value">Numero</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="volume"        data-related-search-on="value">Osa</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="year"          data-related-search-on="value">Vuosi</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="pages"         data-related-search-on="value">Sivut</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="type"          data-related-search-on="value">Pyynnön tyyppi</th>
 <th scope="col">Tilaus ID</th>
 <th scope="col">Asiakas</th>
 <th scope="col">Nimeketietueen ID</th>
 <th scope="col">Kirjasto</th>
 <th scope="col">Tila</th>
 <th scope="col" class="placed_formatted">Tilattu</th>
 <th scope="col" class="updated_formatted">Päivitetty</th>
 <th scope="col">Vastattu</th>
 <th scope="col" class="completed_formatted">Valmis</th>
 <th scope="col">Tietueen URL</th>
 <th scope="col">Kustannus</th>
 <th scope="col">Maksettu hinta</th>
 <th scope="col">Kommentit</th>
 <th scope="col">Huomautus verkkokirjastossa</th>
 <th scope="col">Virkailijahuomautus</th>
 <th scope="col">Taustajärjestelmä</th>
 <th scope="col" class="actions"></th>
 </tr>
 </thead>
 <tbody id="illview-body">
 </tbody>
</table>