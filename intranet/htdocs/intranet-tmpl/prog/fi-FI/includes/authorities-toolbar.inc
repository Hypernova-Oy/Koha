[% IF ( authid || CAN_user_editauthorities) %]

 <div id="toolbar" class="btn-toolbar sticky">
 [% IF ( CAN_user_editauthorities ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false">
 <i class="fa fa-plus"></i> Uusi auktoriteetti </button>
 <ul class="dropdown-menu">
 [% FOREACH authority_type IN authority_types %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/authorities/authorities.pl?authtypecode=[% authority_type.authtypecode | uri %]">[% authority_type.authtypetext | html %]</a></li>
 [% END %]
 </ul>
 </div>
 [% IF servers.count > 0 %]
 <div class="btn-group">
 <button id="z3950_new" class="btn btn-default">
 <i class="fa fa-search"></i> Uusi Z39.50/SRU-haku </button>
 </div>
 [% END %]
 [% END %]

 [% IF ( authid ) %]
 [% IF ( CAN_user_editauthorities ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false">
 <i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa </button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" id="editAuth" href="/cgi-bin/koha/authorities/authorities.pl?authid=[% authid | html %]">Muokkaa tietuetta</a></li>
 <li><a class="dropdown-item" id="dupAuth" href="/cgi-bin/koha/authorities/authorities.pl?authid=[% authid | html %]&amp;op=duplicate">Muokkaa uutena kopiona</a></li>
 [% IF servers.count > 0 %]
 <li><a class="dropdown-item" id="z3950_replace" href="#">Korvaa tietue Z39.50/SRU-kyselyn kautta</a></li>
 [% END %]
 [% UNLESS ( count ) %]
 <li><a class="dropdown-item" href="#" id="delAuth">Poista tietue</a></li>
 [% END %]
 </ul>
 </div>
 [% END %]

 <div class="btn-group">
 <a class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" href="#"><i class="fa fa-download"></i> Tallenna</a>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" href="/cgi-bin/koha/authorities/export.pl?format=mads&amp;op=export&amp;authid=[% authid | uri %]">MADS (XML)</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/authorities/export.pl?format=marcxml&amp;op=export&amp;authid=[% authid | uri %]">MARCXML</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/authorities/export.pl?format=marc8&amp;op=export&amp;authid=[% authid | uri %]">MARC (Ei Unicode/MARC-8)</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/authorities/export.pl?format=utf8&amp;op=export&amp;authid=[% authid | uri %]">MARC (Unicode/UTF-8)</a></li>
 </ul>
 </div>
 [% END %]
 </div>

[% END %]
