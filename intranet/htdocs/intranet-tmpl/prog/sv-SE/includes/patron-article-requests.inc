[% USE Context %]
[% SET current_article_requests = Context.Scalar( Context.Scalar( patron, 'article_requests' ), 'filter_by_current' ) %]
[% IF current_article_requests.count > 0 %]
 <table id="article-requests-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="article-request-record-title anti-the">Posttitel</th>
 <th class="article-request-created_on psort">Lades den</th>
 <th class="article-request-title anti-the">Titel</th>
 <th class="article-request-author">Författare</th>
 <th class="article-request-volume">Volym</th>
 <th class="article-request-issue">Nummer</th>
 <th class="article-request-date">Datum</th>
 <th class="article-request-toc" title="Innehållsförteckning">Innehållsförteckning</th>
 <th class="article-request-pages">Sidor</th>
 <th class="article-request-chapters">Kapitel</th>
 <th class="article-request-notes">Kommentarer</th>
 <th class="article-request-format">Format</th>
 <th class="article-request-status">Status</th>
 <th class="article-request-branchcode">Avhämtningsbibliotek</th>
 </tr>
 </thead>

 <tbody>
 [% FOREACH ar IN current_article_requests %]
 <tr>
 <td class="article-request-record-title">
 <a class="article-request-record-link-title" href="/cgi-bin/koha/circ/request-article.pl?biblionumber=[% ar.biblionumber | html %]">
 [% ar.biblio.title | html %]
 [% ar.item.enumchron | html %]
 </a>
 [% ar.biblio.author | html %]
 [% IF ar.itemnumber %] <em>(endast [% ar.item.barcode | html %])</em>[% END %]
 </td>

 <td class="article-request-created_on">
 [% ar.created_on | $KohaDates %]
 </td>

 <td class="article-request-title">
 [% ar.title | html %]
 </td>

 <td class="article-request-author">
 [% ar.author | html %]
 </td>

 <td class="article-request-volume">
 [% ar.volume | html %]
 </td>

 <td class="article-request-issue">
 [% ar.issue | html %]
 </td>

 <td class="article-request-date">
 [% ar.date | html %]
 </td>

 <td class="article-request-toc">
 [% IF ar.toc_request %]<span>Ja</span>[% END %]
 </td>

 <td class="article-request-pages">
 [% ar.pages | html %]
 </td>

 <td class="article-request-chapters">
 [% ar.chapters | html %]
 </td>

 <td class="article-request-patron-notes">
 [% ar.patron_notes | html %]
 </td>

 <td class="article-request-format">
 [% IF ar.format == 'PHOTOCOPY' %]<span>Kopiera</span>
 [% ELSIF ar.format == 'SCAN' %]<span>Skanna</span>
 [% END %]
 </td>

 <td class="article-request-status">
 [% IF ar.status == 'PENDING' %]
 <span>Väntande</span>
 [% ELSIF ar.status == 'PROCESSING' %]
 <span>Bearbetar</span>
 [% ELSIF ar.status == 'COMPLETED' %]
 <span>Klar</span>
 [% ELSIF ar.status == 'CANCELED' %]
 <span>Borttagen</span>
 [% END %]
 </td>

 <td class="article-request-branchcode">
 [% ar.branch.branchname | html %]
 </td>
 </tr>
 [% END %]
 </tbody>
 </table>
 [% ELSE %]
 <span>Låntagaren har inga aktuella artikelbeställningar.</span>
 [% END %]
