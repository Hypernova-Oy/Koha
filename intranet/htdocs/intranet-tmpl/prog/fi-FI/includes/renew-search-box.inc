[% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <!-- renew-search-box.inc -->
 [% WRAPPER tab_panel tabname="renew_search" bt_active= bs_tab_active %]
 <form method="post" action="/cgi-bin/koha/circ/renew.pl" autocomplete="off">
 [% INCLUDE 'csrf-token.inc' %]

 <div class="form-title">
 <label class="control-label" for="ren_barcode"><span class="control-text">Uusinta</span> <i class="fa fa-fw fa-retweet" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input accesskey="r" class="head-searchbox form-control" id="ren_barcode" name="barcode" placeholder="Syötä viivakoodi uusiaksesi" size="40" type="text" />
 </div>
 <input type="hidden" name="op" value="cud-renew" />
 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]
 <!-- /renew-search-box.inc -->
[% END %]
