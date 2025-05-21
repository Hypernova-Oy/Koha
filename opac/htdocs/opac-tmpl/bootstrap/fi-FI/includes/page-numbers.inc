[% USE raw %]
[% IF ( PAGE_NUMBERS ) %]
 <nav aria-label="Hakutulosten sivut" class="noprint">
 [% IF hits_to_paginate < total %]
 <span class="h6">[% hits_to_paginate | html %] / [% total | html %] hakutulosta ladattu, tarkenna hakuasi nähdäksesi muita tietueita</span>
 [% END %]
 <ul class="pagination pagination-sm">
 [% IF ( previous_page_offset.defined ) %]
 <li class="page-item">
 <a aria-label="Siirry ensimmäiselle sivulle" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]"><i class="fa fa-fw fa-angle-double-left" aria-hidden="true"></i> Ensimmäinen</a>
 </li>
 <li class="page-item">
 <a aria-label="Siirry edelliselle sivulle" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% previous_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]"> <i class="fa fa-fw fa-angle-left" aria-hidden="true"></i> Edellinen</a>
 </li>
 [% END %]
 [% FOREACH PAGE_NUMBER IN PAGE_NUMBERS %]
 [% IF ( PAGE_NUMBER.highlight ) %]
 <li class="page-item active" aria-current="active">
 <a aria-current="true" aria-label="Nykyinen sivu: Sivu [% PAGE_NUMBER.pg | html %]" class="page-link" href="#">[% PAGE_NUMBER.pg | html %]</a>
 </li>
 [% ELSE %]
 <li class="page-item">
 <a aria-label="Siirry sivulle [% PAGE_NUMBER.pg | html %]" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% PAGE_NUMBER.offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">[% PAGE_NUMBER.pg | html %]</a>
 </li>
 [% END %]
 [% END %]
 [% IF ( next_page_offset ) %]
 <li class="page-item">
 <a aria-label="Siirry seuraavalle sivulle" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% next_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">Seuraava <i class="fa fa-fw fa-angle-right" aria-hidden="true"></i></a>
 </li>
 <li class="page-item">
 <a aria-label="Siirry viimeiselle sivulle" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% last_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">Viimeinen <i class="fa fa-fw fa-angle-double-right" aria-hidden="true"></i></a>
 </li>
 [% END %]
 </ul>
 </nav>
[% END %]
