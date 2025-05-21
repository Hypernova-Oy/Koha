[% USE raw %]
[% PROCESS 'html_helpers.inc' %]
<!-- acquisitions-search.inc -->
[% FILTER collapse %]
 [% WRAPPER tabs id="header_search" %]

 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="supplier_search" bt_active= 1 %]
 <form name="findsupplier" action="/cgi-bin/koha/acqui/booksellers.pl" method="get">
 <div class="form-title">
 <label class="control-label" for="supplier"><span class="control-text">Leverantörssökning</span> <i class="fa fa-fw fa-upload" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="supplier" name="supplier" placeholder="Sök leverantörer" type="text" />
 </div>
 <button aria-label="Sök" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel# %]
 [% WRAPPER tab_panel tabname="orders_search" %]
 <form action="/cgi-bin/koha/acqui/histsearch.pl" method="get">
 <div class="form-title">
 <label class="control-label" for="order_title"><span class="control-text">Beställningssökning</span> <i class="fa fa-fw fa-download" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="form-control" id="order_title" name="title" placeholder="Titel" size="13" type="text" value="[% title | html %]" />
 <input class="form-control" id="searchsupplier" name="name" placeholder="Leverantör" size="13" type="text" value="[% name | html %]" />
 <button class="form-extra-content-toggle" title="Fler alternativ" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>
 <input type="hidden" id="do_search" name="do_search" value="do" />
 </div>
 <button aria-label="Sök" type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 <div>
 <label for="basket" class="control-label">Korg</label>
 <input class="form-control" id="basket" name="basket" placeholder="Korg" type="text" />
 </div>
 <div>
 <label for="booksellerinvoicenumber" class="control-label">Fakturanummer</label>
 <input class="form-control" id="booksellerinvoicenumber" name="booksellerinvoicenumber" placeholder="Fakturanummer" type="text" />
 </div>
 <div>
 <a href="/cgi-bin/koha/acqui/histsearch.pl">Avancerad sökning</a>
 </div>
 </div>
 </form>
 [% END # /tab_panel# %]
 [% END # /WRAPPER tab_panels %]

 [% WRAPPER tabs_nav %]
 [% WRAPPER tab_item tabname= "supplier_search" bt_active= 1 %]
 <i class="fa fa-upload" aria-hidden="true"></i> <span class="tab-title">Leverantörssökning</span>
 [% END %]
 [% WRAPPER tab_item tabname= "orders_search" %]
 <i class="fa fa-download" aria-hidden="true"></i> <span class="tab-title">Beställningssökning</span>
 [% END %]
 [% END # /WRAPPER tabs_nav %]

 [% END # /WRAPPER tabs %]
[% END %]

<!-- /acquisitions-search.inc -->
