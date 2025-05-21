[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<!-- serials-search.inc -->
[% WRAPPER tabs id="header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="subscription_search" bt_active= 1 %]
 <form action="/cgi-bin/koha/serials/serials-search.pl" method="get">
 [% IF ( routing ) %]
 <input type="hidden" name="routing" value="[% routing | html %]" />
 [% END %]
 <input type="hidden" name="searched" value="1" />

 <div class="form-title">
 <label class="control-label" for="ISSN_filter"><span class="control-text">Hae kausijulkaisutilauksia</span> <i class="fa fa-fw fa-book" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input type="text" class="form-control" placeholder="ISSN" size="11" name="ISSN_filter" id="ISSN_filter" value="[% ISSN_filter | html %]" />

 [% IF (UNIMARC) %]
 <input type="text" class="form-control" placeholder="EAN" size="11" name="EAN_filter" id="EAN_filter" value="[% EAN_filter | html %]" />
 [% END %]

 <input class="form-control" id="title_filter" name="title_filter" placeholder="Nimeke" size="11" type="text" value="[% title_filter | html %]" />
 <button class="form-extra-content-toggle" title="Enemmän vaihtoehtoja" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>

 </div>

 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 <div class="form-extra-content">
 <div>
 <label for="callnumber_filter">Luokka:</label>
 <input class="form-control" id="callnumber_filter" name="callnumber_filter" placeholder="Luokka" type="text" value="[% callnumber_filter | html %]">
 </div>
 <div>
 <label for="publisher_filter">Julkaisija:</label>
 <input class="form-control" id="publisher_filter" name="publisher_filter" placeholder="Julkaisija" type="text" value="[% publisher_filter | html %]">
 </div>
 <div>
 <label for="bookseller_filter">Toimittaja:</label>
 <input class="form-control" id="bookseller_filter" name="bookseller_filter" placeholder="Toimittaja" type="text" value="[% bookseller_filter | html %]">
 </div>
 <div>
 <a href="/cgi-bin/koha/serials/serials-search.pl">Tarkka haku</a>
 </div>
 </div> <!-- /.form-extra-content -->
 </form>
 [% END # /tab_panel %]

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]

 [% END # /tab_panels %]
 [% WRAPPER tabs_nav %]
 [% WRAPPER tab_item tabname= "subscription_search" bt_active= 1 %]
 <i class="fa fa-book" aria-hidden="true"></i> <span class="tab-title">Hae kausijulkaisutilauksia</span>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% WRAPPER tab_item tabname= "circ_search" %]
 <i class="fa fa-upload" aria-hidden="true"></i> <span class="tab-title">Lainaus</span>
 [% END %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% WRAPPER tab_item tabname= "catalog_search" %]
 <i class="fa fa-fw fa-search" aria-hidden="true"></i> <span class="tab-title">Hae tietokannasta</span>
 [% END %]
 [% END %]
 [% END # /tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /serials-search.inc -->
