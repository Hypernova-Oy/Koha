[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<!-- currencies-admin-search.inc -->
[% WRAPPER tabs id="header_search" %]
    [% WRAPPER tab_panels %]
        [% WRAPPER tab_panel tabname="currency_search" bt_active= 1 %]
            <form action="/cgi-bin/koha/admin/currency.pl" method="get">
                <div class="form-title">
                    <label class="control-label" for="description"><span class="control-text">Search currencies</span> <i class="fa-solid fa-fw fa-dollar-sign" aria-hidden="true"></i></label>
                </div>

                <div class="form-content">
                    <input class="head-searchbox form-control" type="text" name="description" id="description" value="[% searchfield | html %]" placeholder="Currencies search" />
                </div>

                <button type="submit" aria-label="Search"><i class="fa fa-arrow-right"></i></button>
            </form>
        [% END %]

        [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
            [% INCLUDE 'patron-search-box.inc' %]
        [% END %]
        [% IF ( CAN_user_catalogue ) %]
            [% INCLUDE 'catalogue-search-box.inc' %]
        [% END %]
    [% END # /tab_panels %]
    [% WRAPPER tabs_nav %]
        [% WRAPPER tab_item tabname= "currency_search" bt_active= 1 %]
            <i class="fa-solid fa-fw fa-dollar-sign" aria-hidden="true"></i> <span class="tab-title">Search currencies</span>
        [% END %]
        [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
            [% WRAPPER tab_item tabname= "circ_search" %]
                <i class="fa fa-fw fa-upload" aria-hidden="true"></i> <span class="tab-title">Check out</span>
            [% END %]
        [% END %]
        [% IF ( CAN_user_catalogue ) %]
            [% WRAPPER tab_item tabname= "catalog_search" %]
                <i class="fa fa-fw fa-search" aria-hidden="true"></i> <span class="tab-title">Search catalog</span>
            [% END %]
        [% END %]
    [% END # /tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /currencies-admin-search.inc -->
