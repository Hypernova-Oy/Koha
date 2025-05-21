[% USE raw %]
[% IF ( PAGE_NUMBERS ) %]
 <nav aria-label="Paginering av sökresultat" class="noprint">
 [% IF hits_to_paginate < total %]
 <span class="h6">[% hits_to_paginate | html %] av [% total | html %] resultat laddade, förfina din sökning för att visa andra poster</span>
 [% END %]
 <ul class="pagination pagination-sm">
 [% IF ( previous_page_offset.defined ) %]
 <li class="page-item">
 <a aria-label="Gå till första sidan" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]"><i class="fa fa-fw fa-angle-double-left" aria-hidden="true"></i> Första</a>
 </li>
 <li class="page-item">
 <a aria-label="Gå till föregående sida" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% previous_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]"> <i class="fa fa-fw fa-angle-left" aria-hidden="true"></i> Föregående</a>
 </li>
 [% END %]
 [% FOREACH PAGE_NUMBER IN PAGE_NUMBERS %]
 [% IF ( PAGE_NUMBER.highlight ) %]
 <li class="page-item active" aria-current="active">
 <a aria-current="true" aria-label="Aktuell sida: Sida [% PAGE_NUMBER.pg | html %]" class="page-link" href="#">[% PAGE_NUMBER.pg | html %]</a>
 </li>
 [% ELSE %]
 <li class="page-item">
 <a aria-label="Gå till sida [% PAGE_NUMBER.pg | html %]" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% PAGE_NUMBER.offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">[% PAGE_NUMBER.pg | html %]</a>
 </li>
 [% END %]
 [% END %]
 [% IF ( next_page_offset ) %]
 <li class="page-item">
 <a aria-label="Gå till nästa sida" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% next_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">Nästa <i class="fa fa-fw fa-angle-right" aria-hidden="true"></i></a>
 </li>
 <li class="page-item">
 <a aria-label="Gå till den sista sidan" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% last_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">Sista <i class="fa fa-fw fa-angle-double-right" aria-hidden="true"></i></a>
 </li>
 [% END %]
 </ul>
 </nav>
[% END %]
