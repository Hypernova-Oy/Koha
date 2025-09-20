[% USE Context %]
[% SET current_article_requests = Context.Scalar( Context.Scalar( patron, 'article_requests' ), 'filter_by_current' ) %]
[% IF current_article_requests.count > 0 %]
 <table id="article-requests-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="article-request-record-title anti-the">Teoksen nimeke</th>
 <th class="article-request-created_on psort">Tilattu</th>
 <th class="article-request-title anti-the">Nimeke</th>
 <th class="article-request-author">Tekijä</th>
 <th class="article-request-volume">Osa</th>
 <th class="article-request-issue">Numero</th>
 <th class="article-request-date">Päivämäärä</th>
 <th class="article-request-toc" title="Sisällysluettelo">Sisällysluettelo</th>
 <th class="article-request-pages">Sivut</th>
 <th class="article-request-chapters">Luvut</th>
 <th class="article-request-notes">Huomautukset</th>
 <th class="article-request-format">Aineistotyyppi</th>
 <th class="article-request-status">Tila</th>
 <th class="article-request-branchcode">Noutokirjasto</th>
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
 [% IF ar.itemnumber %] <em>(vain [% ar.item.barcode | html %])</em>[% END %]
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
 [% IF ar.toc_request %]<span>Kyllä</span>[% END %]
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
 [% IF ar.format == 'PHOTOCOPY' %]<span>Kopioi</span>
 [% ELSIF ar.format == 'SCAN' %]<span>Lue viivakoodi</span>
 [% END %]
 </td>

 <td class="article-request-status">
 [% IF ar.status == 'PENDING' %]
 <span>Odottava</span>
 [% ELSIF ar.status == 'PROCESSING' %]
 <span>Käsittelypohja</span>
 [% ELSIF ar.status == 'COMPLETED' %]
 <span>Valmis</span>
 [% ELSIF ar.status == 'CANCELED' %]
 <span>Peruutettu</span>
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
 <span>Asiakkaalla ei ole artikkelipyyntöjä.</span>
 [% END %]
