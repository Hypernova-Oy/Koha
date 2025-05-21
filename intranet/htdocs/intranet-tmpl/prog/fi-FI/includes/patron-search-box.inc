[% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <!-- patron-search-box.inc -->
 [% WRAPPER tab_panel tabname="circ_search" bt_active= bs_tab_active %]
 <form action="/cgi-bin/koha/circ/circulation.pl" id="patronsearch" method="get">
 <div class="form-title">
 <label class="control-label" for="findborrower"><span class="control-text">Lainaus</span> <i class="fa fa-fw fa-upload" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input autocomplete="off" class="head-searchbox form-control" id="findborrower" name="findborrower" placeholder="Syötä kirjastokortin numero tai osa nimestä" size="40" type="text" />

 [% IF ( stickyduedate ) %]
 <input type="hidden" name="duedatespec" value="[% duedatespec | html %]" />
 <input type="hidden" name="stickyduedate" value="[% stickyduedate | html %]" />
 [% END %]
 </div>

 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]
 <!-- /patron-search-box.inc -->
[% END %]
