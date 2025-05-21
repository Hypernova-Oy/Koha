[% USE Koha %]
<!-- oai-admin-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="oai_search" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/admin/oai_servers.pl" method="get">
 <div class="form-title">
 <label class="control-label" for="searchfield">Hae OAI-tietovarantoja</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="searchfield" name="searchfield" placeholder="OAI-tietovarantohaku" type="text" value="[% searchfield | html %]" />
 </div>
 <input type="hidden" name="op" value="search" />
 <button aria-label="Haku" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="z3950_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#oai_search" role="tab" title="Hae OAI-tietovarantoja"><i class="fa fa-search"></i> <span class="tab-title">Hae OAI-tietovarantoja</span></a>
 </li>
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li role="presentation">
 <a aria-controls="circ_search" class="keep_text" data-toggle="tab" href="#circ_search" role="tab" title="Lainaus"><i class="fa fa-upload"></i> <span class="tab-title">Lainaus</span></a>
 </li>
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 <li role="presentation">
 <a aria-controls="catalog_search" class="keep_text" data-toggle="tab" href="#catalog_search" role="tab" title="Hae tietokannasta"><i class="fa fa-fw fa-search"></i> <span class="tab-title">Hae tietokannasta</span></a>
 </li>
 [% END %]
 </ul>
</div><!-- /#header_search -->
<!-- /oai-admin-search.inc -->
