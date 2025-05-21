[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<div id="advsearch" style="padding-bottom:3em;">
 <form action="/cgi-bin/koha/serials/serials-search.pl" method="get">
 [% IF brief %]
 <fieldset class="brief">
 [% ELSE %]
 <fieldset class="rows">
 [% END%]
 <legend>Hae kausijulkaisutilauksia</legend>
 <ol>
 <li>
 <label for="issn">ISSN:</label>
 <input type="text" id="issn" name="ISSN_filter" value="[% ISSN_filter | html %]" />
 </li>
 <li>
 <label for="title">Nimeke:</label>
 <input type="text" id="title" name="title_filter" value="[% title_filter | html %]" />
 </li>
 [% IF ( marcflavour == "UNIMARC" ) %]
 <li>
 <label for="ean">EAN:</label>
 <input type="text" id="ean" name="EAN_filter" value="[% EAN_filter | html %]" />
 </li>
 [% END %]
 <li class="local">
 <label for="callnumber">Luokka:</label>
 <input type="text" id="callnumber" name="callnumber_filter" value="[% callnumber_filter | html %]" />
 </li>
 <li>
 <label for="publisher">Julkaisija:</label>
 <input type="text" id="publisher" name="publisher_filter" value="[% publisher_filter | html %]" />
 </li>
 <li class="local">
 <label for="bookseller">Toimittaja:</label>
 <input type="text" id="bookseller" name="bookseller_filter" value="[% bookseller_filter | html %]" />
 </li>
 <li class="local">
 <label for="branch">Kirjasto:</label>
 <select id="branch" name="branch_filter">
 <option value="">Kaikki</option>
 [%# FIXME Should not we filter the libraries? %]
 [% PROCESS options_for_libraries libraries => Branches.all( selected => branch_filter, unfiltered => 1 ) %]
 </select>
 </li>
 <li class="local">
 <label for="location">Sijainti:</label>
 [% PROCESS 'av-build-dropbox.inc' name="location_filter", category="LOC", default=location_filter, all=1 %]
 </li>
 <li class="local">
 <label for="to">Vanhenee:</label>
 <input type="text" id="to" name="expiration_date_filter" value="[% expiration_date_filter | html %]" size="10" maxlength="10" class="flatpickr" />
 </li>
 [% IF Koha.Preference( 'RoutingSerials' ) %]
 <li class="local">
 <label for="routinglist">
 <input type="checkbox" id="routinglist" name="routinglist" />
 Tilauksella on kiertolista: </label>
 </li>
 [% END %]

 [% INCLUDE 'additional-fields-entry.inc' available=additional_fields_for_subscription values=additional_field_filters wrap_fieldset=0 search_form=1 %]
 </ol>
 <input type="hidden" name="searched" value="1" />
 [% IF ( mana ) %]
 <input type="hidden" name="mana" value="1" />
 [% END %]
 </fieldset> <!-- /.rows -->
 <fieldset class="action">
 <input class="btn btn-primary" type="submit" value="Haku" />
 </fieldset>
 </form>
</div> <!-- /#advsearch -->
