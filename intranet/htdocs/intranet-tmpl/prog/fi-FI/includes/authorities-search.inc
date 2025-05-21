[% USE raw %]
[% PROCESS 'html_helpers.inc' %]
<!-- authorities-search.inc -->

[% BLOCK orderby %]
 <div>
 <label class="control-label">
 Järjestä <select name="orderby" class="form-select">
 [% IF ( orderby == 'HeadingAsc' ) %]
 <option value="HeadingAsc" selected="selected">Otsikko A-Z</option>
 [% ELSE %]
 <option value="HeadingAsc">Otsikko A-Z</option>
 [% END %]
 [% IF ( orderby == 'HeadingDsc' ) %]
 <option value="HeadingDsc" selected="selected">Otsikko Z-A</option>
 [% ELSE %]
 <option value="HeadingDsc">Otsikko Z-A</option>
 [% END %]
 [% IF ( orderby == '' && op ) %]
 <option value="" selected="selected">Ei mitään</option>
 [% ELSE %]
 <option value="">Ei mitään</option>
 [% END %]
 </select>
 </label>
 </div>
[% END %]

[% BLOCK operator %]
 <div>
 <label class="control-label">
 Operaattori <select name="operator" class="form-select">
 [% IF ( operator == 'contains' ) %]
 <option value="contains" selected="selected">sisältää</option>
 [% ELSE %]
 <option value="contains">sisältää</option>
 [% END %]
 [% IF ( operator == 'start' ) %]
 <option value="start" selected="selected">alkaa sanalla</option>
 [% ELSE %]
 <option value="start">alkaa sanalla</option>
 [% END %]
 [% IF ( operator == 'exact' ) %]
 <option value="exact" selected="selected">on</option>
 [% ELSE %]
 <option value="exact">on</option>
 [% END %]
 </select>
 </label>
 </div>
[% END %]

[% BLOCK authtype %]
 <div>
 <label>
 Auktoriteettityyppi <select name="authtypecode" class="form-select">
 [% IF (marcflavour == 'UNIMARC' ) %]<option value="">Kaikki auktoriteettityypit</option>[% END %]
 [% FOREACH authority_type IN authority_types %]
 [% IF authority_type.authtypecode == authtypecode %]
 <option value="[% authority_type.authtypecode | html %]" selected="selected">[% authority_type.authtypetext | html %]</option>
 [% ELSE %]
 <option value="[% authority_type.authtypecode | html %]">[% authority_type.authtypetext | html %]</option>
 [% END %]
 [% END %]
 </select>
 </label>
 </div>
[% END %]

[% WRAPPER tabs id="header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="mainmain_heading" bt_active= 1 %]
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />

 <div class="form-title">
 <label class="control-label" for="value_mainentry"><span class="control-text">Hae pääotsikosta</span> <i class="fa fa-fw fa-main-heading-a" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_mainentry" name="value" placeholder="Hae pääotsikosta (vain $a)" type="text" value="[% value | html %]" />
 <button class="form-extra-content-toggle" title="Enemmän vaihtoehtoja" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>
 </div>

 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </div>
 </form>
 [% END # /tab_panel %]

 [% WRAPPER tab_panel tabname="main_heading" %]
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />

 <div class="form-title">
 <label class="control-label" for="value_mainheading"><span class="control-text">Hae pääotsikosta</span> <i class="fa fa-fw fa-header" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_mainheading" name="value" placeholder="Hae pääotsikosta" type="text" value="[% value | html %]" />
 <button class="form-extra-content-toggle" title="Enemmän vaihtoehtoja" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>
 </div>

 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </div>
 </form>
 [% END # /tab_panel %]

 [% WRAPPER tab_panel tabname="matchheading_search" %]
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="match" />

 <div class="form-title">
 <label class="control-label" for="value_matchheading"><span class="control-text">Hae kaikista otsikoista</span> <i class="fa fa-fw fa-align-center" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_matchheading" name="value" placeholder="Hae otsikkoa" type="text" value="[% value | html %]" />
 <button class="form-extra-content-toggle" title="Enemmän vaihtoehtoja" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>
 </div>

 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </div>
 </form>
 [% END # /tab_panel %]

 [% WRAPPER tab_panel tabname="entire_record" %]
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="all" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />

 <div class="form-title">
 <label class="control-label" for="value_anywhere"><span class="control-text">Hae koko tietue</span> <i class="fa-solid fa-fw fa-folder-open" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_anywhere" name="value" placeholder="Hae auktoriteettikenttää" type="text" value="[% value | html %]" />
 <button class="form-extra-content-toggle" title="Enemmän vaihtoehtoja" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>
 </div>

 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </div>
 </form>
 [% END # /tab_panel %]

 [% END # /tab_panels %]
 [% WRAPPER tabs_nav %]
 [% WRAPPER tab_item tabname= "mainmain_heading" bt_active= 1 %]
 <i class="fa fa-fw fa-main-heading-a" aria-hidden="true"></i> <span class="tab-title">Pääotsikko (vain $a)</span>
 [% END %]
 [% WRAPPER tab_item tabname= "main_heading" %]
 <i class="fa fa-fw fa-header" aria-hidden="true"></i> <span class="tab-title">Pääotsikko</span>
 [% END %]
 [% WRAPPER tab_item tabname= "matchheading_search" %]
 <i class="fa fa-fw fa-align-center" aria-hidden="true"></i> <span class="tab-title">Kaikki otsikot</span>
 [% END %]
 [% WRAPPER tab_item tabname= "entire_record" %]
 <i class="fa-solid fa-fw fa-folder-open" aria-hidden="true"></i> <span class="tab-title">Koko tietue</span>
 [% END %]
 [% END # /tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /authorities-search.inc -->
