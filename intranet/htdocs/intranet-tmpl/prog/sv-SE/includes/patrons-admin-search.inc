[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<!-- patrons-admin-search.inc -->

[% WRAPPER tabs id= "header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="patron_category_search" bt_active= 1 %]
 <form action="/cgi-bin/koha/admin/categories.pl" method="get">
 <div class="form-title">
 <label class="control-label" for="category_search"><span class="control-text">Sök kategorier för låntagare</span> <i class="fa fa-fw fa-id-card" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="category_search" name="description" placeholder="Sök på kategorinamn för låntagare" type="text" value="[% searchfield | html %]" />
 </div>

 <button aria-label="Sök" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]

 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]
 [% END # /WRAPPER tab_panels %]

 [% WRAPPER tabs_nav %]
 [% WRAPPER tab_item tabname= "patron_category_search" bt_active= 1 %]
 <i class="fa fa-fw fa-id-card" aria-hidden="true"></i> <span class="tab-title">Sök kategorier för låntagare</span>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% WRAPPER tab_item tabname= "circ_search" %]
 <i class="fa fa-fw fa-upload" aria-hidden="true"></i> <span class="tab-title">Låna ut</span>
 [% END %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% WRAPPER tab_item tabname= "catalog_search" %]
 <i class="fa fa-fw fa-search" aria-hidden="true"></i> <span class="tab-title">Sök i katalogen</span>
 [% END %]
 [% END %]
 [% END # /WRAPPER tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /patrons-admin-search.inc -->
