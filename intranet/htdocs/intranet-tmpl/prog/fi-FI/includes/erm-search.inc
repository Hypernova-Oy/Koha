[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<!-- erm-search.inc -->
[% WRAPPER tabs id="header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="agreement_search" bt_active= 1 %]
 <form action="/cgi-bin/koha/erm/agreements" method="get">
 <div class="form-title">
 <label class="control-label" for="agreement_filter"><span class="control-text">Sopimushaku</span> <i class="fa fa-fw fa-check-circle" aria-hidden="true"></i></label>
 </div>
 <div class="form-content">
 <input class="head-searchbox form-control" id="agreement_filter" name="q" placeholder="Syötä hakusanat" size="40" type="text" />
 </div>
 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]

 [% WRAPPER tab_panel tabname="license_search" %]
 <form action="/cgi-bin/koha/erm/licenses" method="get">
 <div class="form-title">
 <label class="control-label" for="license_filter"><span class="control-text">Lisenssihaku</span> <i class="fa fa-fw fa-gavel" aria-hidden="true"></i></label>
 </div>
 <div class="form-content">
 <input class="head-searchbox form-control" id="license_filter" name="q" placeholder="Syötä hakusanat" size="40" type="text" />
 </div>
 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]

 [% WRAPPER tab_panel tabname="package_search" %]
 <form action="/cgi-bin/koha/erm/eholdings/local/packages" method="get">
 <div class="form-title">
 <label class="control-label" for="package_name_filter"><span class="control-text">Pakettien haku</span> <i class="fa fa-fw fa-archive" aria-hidden="true"></i></label>
 </div>
 <div class="form-content">
 <input class="head-searchbox form-control" id="package_name_filter" name="package_name" placeholder="Syötä hakusanat" size="40" type="text" />
 </div>
 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]

 [% WRAPPER tab_panel tabname="title_search" %]
 <form action="/cgi-bin/koha/erm/eholdings/local/titles" method="get">
 <div class="form-title">
 <label class="control-label" for="title_filter"><span class="control-text">Nimekehaku</span> <i class="fa-solid fa-fw fa-arrow-down-a-z" aria-hidden="true"></i></label>
 </div>
 <div class="form-content">
 <input class="head-searchbox form-control" id="title_filter" name="publication_title" placeholder="Syötä hakusanat" size="40" type="text" />
 </div>
 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]
 [% END # /tab_panels %]

 [% WRAPPER tabs_nav %]
 [% WRAPPER tab_item tabname= "agreement_search" bt_active= 1 %]
 <i class="fa fa-fw fa-check-circle" aria-hidden="true"></i> <span class="tab-title">Hae sopimuksia</span>
 [% END %]
 [% WRAPPER tab_item tabname= "license_search" %]
 <i class="fa fa-fw fa-gavel" aria-hidden="true"></i> <span class="tab-title">Hae lisenssejä</span>
 [% END %]
 [% WRAPPER tab_item tabname= "package_search" %]
 <i class="fa fa-fw fa-archive" aria-hidden="true"></i> <span class="tab-title">Hae paketteja</span>
 [% END %]
 [% WRAPPER tab_item tabname= "title_search" %]
 <i class="fa-solid fa-fw fa-arrow-down-a-z" aria-hidden="true"></i> <span class="tab-title">Hae nimekkeitä</span>
 [% END %]
 [% END # /tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /erm-search.inc -->
