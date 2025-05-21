[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<!-- z3950-admin-search.inc -->
[% WRAPPER tabs id="header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="z3950_search" bt_active= 1 %]
 <form action="/cgi-bin/koha/admin/z3950servers.pl" method="get">
 <div class="form-title">
 <label class="control-label" for="searchfield"><span class="control-text">Sök Z39.50/SRU-servrar</span> <i class="fa fa-fw fa-search" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="searchfield" name="searchfield" placeholder="Z39.50/SRU-serversökning" type="text" value="[% searchfield | html %]" />
 </div>
 <input type="hidden" name="op" value="search" />
 <button aria-label="Sök" type="submit"><i class="fa fa-arrow-right"></i></button>
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
 [% WRAPPER tab_item tabname= "z3950_search" bt_active= 1 %]
 <i class="fa fa-search" aria-hidden="true"></i> <span class="tab-title">Sök Z39.50/SRU-servrar</span>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% WRAPPER tab_item tabname= "circ_search" %]
 <i class="fa fa-upload" aria-hidden="true"></i> <span class="tab-title">Låna ut</span>
 [% END %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% WRAPPER tab_item tabname= "catalog_search" %]
 <i class="fa fa-fw fa-search" aria-hidden="true"></i> <span class="tab-title">Sök i katalogen</span>
 [% END %]
 [% END %]
 [% END # /tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /z3950-admin-search.inc -->
