[% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <!-- checkin-search-box.inc -->
 [% WRAPPER tab_panel tabname="checkin_search" bt_active= bs_tab_active %]
 <form method="post" action="/cgi-bin/koha/circ/returns.pl" autocomplete="off">
 [% INCLUDE 'csrf-token.inc' %]
 <div class="form-title">
 <label class="control-label" for="ret_barcode"><span class="control-text">Palautus</span> <i class="fa fa-fw fa-download" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input accesskey="r" class="head-searchbox form-control" id="ret_barcode" name="barcode" placeholder="Syötä viivakoodi palauttaaksesi" size="40" type="text" />
 <input type="hidden" name="op" value="cud-checkin" />
 </div>
 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]
 <!-- /checkin-search-box.inc -->
[% END %]
