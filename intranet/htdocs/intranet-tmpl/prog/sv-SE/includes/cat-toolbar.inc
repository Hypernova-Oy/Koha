[% USE Context %]
[% USE Biblio %]

[%# Parameters: %]
[%# biblio: the Koha::Biblio object %]
[%# biblionumber: FIXME what about using biblio.id? %]

<div id="toolbar" class="btn-toolbar">

[% IF ( CAN_user_editcatalogue_edit_catalogue || CAN_user_editcatalogue_edit_items || CAN_user_serials_create_subscription || Koha.Preference('CatalogConcerns') ) %]
 <div class="btn-group">
 <button type="button" class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa fa-plus"></i> Ny</button>
 <ul class="dropdown-menu">
 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a class="dropdown-item" id="newbiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl">Ny post</a></li>
 [% END %]

 [% IF ( CAN_user_editcatalogue_edit_items ) %]
 <li><a class="dropdown-item" id="newitem" href="/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber | html %]#additema">Nytt exemplar</a></li>
 [% END %]
 [% IF ( CAN_user_serials_create_subscription ) %]
 <li><a class="dropdown-item" id="newsub" href="/cgi-bin/koha/serials/subscription-add.pl?biblionumber_for_new_subscription=[% biblionumber | html %]">Ny prenumeration</a></li>
 [% END %]

 [% IF ( EasyAnalyticalRecords && CAN_user_editcatalogue_edit_catalogue ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% biblionumber | uri %]&amp;analyze=1">Analysera exemplar</a></li>
 [% END %]
 [% IF CAN_user_editcatalogue_edit_catalogue && ! EasyAnalyticalRecords %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/cataloguing/addbiblio.pl?parentbiblionumber=[% biblionumber | uri %]">Ny underpost</a></li>
 [% END %]
 [% IF Koha.Preference('CatalogConcerns') %]
 <li><a class="dropdown-item" id="newconcern" role="button" href="#" data-bs-toggle="modal" data-bs-target="#addConcernModal">Nytt katalogproblem</a></li>
 [% END %]
 </ul>
 </div>
[% END %]

[% IF ( CAN_user_editcatalogue_edit_catalogue || CAN_user_editcatalogue_edit_items || CAN_user_tools_items_batchmod || CAN_user_tools_items_batchdel ) or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Redigera</button>
 <ul class="dropdown-menu">
 [% IF CAN_user_editcatalogue_edit_catalogue or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 [% IF biblio.can_be_edited(logged_in_user) %]
 <li><a class="dropdown-item" id="editbiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber | html %]">Redigera post</a></li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Posten är låst"><a class="dropdown-item disabled" aria-disabled="true" id="editbiblio" href="#">Redigera post</a></li>
 [% END %]
 [% END %]

 [% IF CAN_user_tools_records_batchmod %]
 <li>
 <form action="/cgi-bin/koha/tools/batch_record_modification.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="recordtype" value="biblio" />
 <input type="hidden" name="op" value="cud-list" />
 <input type="hidden" name="bib_list" value="[% biblionumber | html %]" />
 <button type="submit" class="dropdown-item" id="modifybiblio">Redigera post med följande mall</button>
 </form>
 </li>
 [% END %]

 [% IF CAN_user_editcatalogue_edit_items or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 <li><a class="dropdown-item" id="manageitems" href="/cgi-bin/koha/cataloguing/additem.pl?biblionumber=[% biblionumber | html %]">Hantera exemplar</a></li>
 [% END %]

 [% IF ( CAN_user_tools_items_batchmod ) %]
 [% IF ( count ) %]
 <li>
 <form action="/cgi-bin/koha/tools/batchMod.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-show" />
 <input type="hidden" name="biblionumber" value="[% biblionumber | html %]" />
 <input type="hidden" name="src" value="CATALOGUING" />
 <button id="batchedit" type="submit" class="dropdown-item">Satsredigera exemplar</button>
 </form>
 </li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Denna post har inga exemplar">
 <a class="dropdown-item disabled" aria-disabled="true" id="batchedit-disabled" href="#">Satsredigera exemplar</a>
 </li>
 [% END %]
 [% END %]

 [% IF ( CAN_user_tools_items_batchdel ) %]
 [% IF ( count ) %]
 <li>
 <form action="/cgi-bin/koha/tools/batchMod.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-show" />
 <input type="hidden" name="del" value="1" />
 <input type="hidden" name="biblionumber" value="[% biblionumber | html %]" />
 <input type="hidden" name="src" value="CATALOGUING" />
 <button id="batchdelete" type="submit" class="dropdown-item">Ta bort exemplar i en sats</button>
 </form>
 </li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Denna post har inga exemplar">
 <a class="dropdown-item disabled" aria-disabled="true" id="batchdelete-disabled" href="#">Ta bort exemplar i en sats</a>
 </li>
 [% END %]
 [% END %]

 [% IF ( CAN_user_editcatalogue_edit_items ) %]
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/cataloguing/moveitem.pl?biblionumber=[% biblionumber | uri %]">Koppla exemplar</a>
 </li>
 [% END %]

 [% IF ( EasyAnalyticalRecords ) %]
 [% IF ( CAN_user_editcatalogue_edit_items ) %]
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/cataloguing/linkitem.pl?biblionumber=[% biblionumber | uri %]">Länk till värdpost</a>
 </li>
 [% END %]
 [% END %]
 [% IF ( LocalCoverImages || OPACLocalCoverImages) %]
 [% IF ( CAN_user_tools_upload_local_cover_images ) %]
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/tools/upload-cover-image.pl?biblionumber=[% biblionumber | uri %]&amp;filetype=image">Ladda upp bild</a>
 </li>
 [% END %]
 [% END %]

 [% IF ( CAN_user_editcatalogue_edit_catalogue ) %]
 <li>
 <a class="dropdown-item" id="duplicatebiblio" href="/cgi-bin/koha/cataloguing/addbiblio.pl?biblionumber=[% biblionumber | html %]&amp;op=duplicate">Redigera som ny (kopia)</a>
 </li>
 <li><a class="dropdown-item" href="#" id="z3950copy">Ersätt post via Z39.50/SRU</a></li>
 [% END %]

 [% IF CAN_user_editcatalogue_edit_catalogue or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 [% IF ( count ) %]
 <li data-bs-toggle="tooltip" data-bs-placement="left" title="[%- I18N.tnx('There is an item attached to this record. You must delete all items before deleting this record', 'There are {count} items attached to this record. You must delete all items before deleting this record', count, { count => count }) -%]">
 <a class="dropdown-item disabled" aria-disabled="true" id="deletebiblio" href="#">Ta bort post</a>
 </li>
 [% ELSIF ( biblio.subscriptions.count ) %]
 [%- SET subscriptions_count = biblio.subscriptions.count -%]
 <li data-bs-toggle="tooltip" data-bs-placement="left" title="[%- I18N.tnx('There is a subscription attached to this record. You must delete all subscriptions before deleting this record', 'There are {subscriptions_count} subscriptions attached to this record. You must delete all subscriptions before deleting this record', subscriptions_count, { subscriptions_count => subscriptions_count }) -%]">
 <a class="dropdown-item disabled" aria-disabled="true" id="deletebiblio" href="#">Ta bort post</a>
 </li>
 [% ELSE %]
 <li>
 <form action="/cgi-bin/koha/cataloguing/addbiblio.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete" />
 <input type="hidden" name="biblionumber" value="[% biblionumber | html %]" />
 <input type="hidden" name="searchid" value="[% searchid | html %]" />
 </form>
 <a class="dropdown-item" id="deletebiblio" data-order-manage="[% CAN_user_acquisition_order_manage | html %]" href="#">Ta bort post</a>
 </li>
 [% END %]
 [% END %]

 [% IF CAN_user_editcatalogue_delete_all_items or ( frameworkcode == 'FA' and CAN_user_editcatalogue_fast_cataloging ) %]
 [% IF ( count ) %]
 <li>
 <form action="/cgi-bin/koha/cataloguing/additem.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delallitems" />
 <input type="hidden" name="biblionumber" value="[% biblionumber | html %]" />
 <input type="hidden" name="searchid" value="[% searchid | html %]" />
 </form>
 <a class="dropdown-item" href="#" id="deleteallitems">Ta bort alla exemplar</a>
 </li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" id="deleteallitems-disabled" title="Denna post har inga exemplar">
 <a class="dropdown-item disabled" aria-disabled="true" href="#">Ta bort alla exemplar</a>
 </li>
 [% END %]
 [% END %]

 </ul>
 </div>
[% END %]

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa fa-download"></i> Spara</button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/export.pl?format=bibtex&amp;op=export&amp;bib=[% biblionumber | uri %]">BIBTEX</a></li>
 <li><a class="dropdown-item" href="#" data-bs-toggle="modal" data-bs-target="#exportModal_">Dublin Core</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/export.pl?format=marcxml&amp;op=export&amp;bib=[% biblionumber | uri %]">MARCXML</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/export.pl?format=marc8&amp;op=export&amp;bib=[% biblionumber | uri %]">MARC (icke Unicode/MARC-8)</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/export.pl?format=utf8&amp;op=export&amp;bib=[% biblionumber | uri %]">MARC (Unicode/UTF-8)</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/export.pl?format=marcstd&amp;op=export&amp;bib=[% biblionumber | uri %]">MARC (Unicode/UTF-8, Standard)</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/export.pl?format=mods&amp;op=export&amp;bib=[% biblionumber | uri %]">MODS (XML)</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/export.pl?format=ris&amp;op=export&amp;bib=[% biblionumber | uri %]">RIS</a></li>
 </ul>
 </div>

 [% IF (Koha.Preference("intranetbookbag")) %]
 [% IF ( incart ) %]
 <div class="btn-group">
 <a id="cart[% biblionumber | html %]" class="btn btn-default addtocart incart" href="#" role="button"><i class="fa fa-shopping-cart"></i> Spara i minneslista</a>
 </div>
 <div class="btn-group">
 <a id="cartR[% biblionumber | html %]" class="btn btn-default cartRemove incart" href="#" role="button"><i class="fa fa-shopping-cart"></i> Ta bort från minneslista</a>
 </div>
 [% ELSE %]
 <div class="btn-group">
 <a id="cart[% biblionumber | html %]" class="btn btn-default addtocart" href="#" role="button"><i class="fa fa-shopping-cart"></i> Spara i minneslista</a>
 </div>
 <div class="btn-group">
 <a id="cartR[% biblionumber | html %]" class="btn btn-default cartRemove" href="#" role="button"><i class="fa fa-shopping-cart"></i> Ta bort från minneslista</a>
 </div>
 [% END %]
 [% END %]

 [% IF Koha.Preference('virtualshelves') %]
 <div class="btn-group">
 <button type="button" class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
 <i class="fa fa-list"></i> Lägg till i lista </button>
 <ul class="dropdown-menu">
 [% IF add_to_some_private_shelves.count %]
 <li><h6 class="dropdown-header">Dina listor</h6></li>
 [% SET number_of_private_shelves = 0 %]
 [% FOREACH s IN add_to_some_private_shelves %]
 [% IF shelfnumber != s.shelfnumber %]
 <li>
 <a class="dropdown-item addtolist" href="#" data-shelfnumber="[% s.shelfnumber | html %]">[% s.shelfname | html %]</a>
 </li>
 [% SET number_of_private_shelves = number_of_private_shelves + 1 %]
 [% IF number_of_private_shelves == 10 %][% LAST %][% END %]
 [% END %]
 [% END %]
 [% END %]
 [% IF add_to_some_public_shelves.count %]
 <li><h6 class="dropdown-header">Offentliga listor</h6></li>
 [% SET number_of_public_shelves = 0 %]
 [% FOREACH s IN add_to_some_public_shelves %]
 [% IF shelfnumber != s.shelfnumber %]
 <li>
 <a class="dropdown-item addtolist" href="#" data-shelfnumber="[% s.shelfnumber | html %]">[% s.shelfname | html %]</a>
 </li>
 [% SET number_of_public_shelves = number_of_public_shelves + 1 %]
 [% IF number_of_public_shelves == 10 %][% LAST %][% END %]
 [% END %]
 [% END %]
 [% END %]
 <li><hr class="dropdown-divider"></li>
 [% IF ( add_to_some_private_shelves and add_to_some_private_shelves.count > 10 ) or ( add_to_some_public_shelves and add_to_some_public_shelves.count > 10 ) %]
 <li>
 <a href="#" class="addtolist morelists dropdown-item">Fler listor</a>
 </li>
 [% END %]
 <li>
 <a href="#" class="addtolist newlist dropdown-item">Ny lista</a>
 </li>
 </ul>
 </div>
 [% END # /IF virtualshelves %]

 <div class="btn-group"><a id="printbiblio" class="btn btn-default" role="button"><i class="fa fa-print"></i> Utskrift</a></div>

[% IF ( CAN_user_reserveforothers ) %]
 [% SET items = biblio.items %]
 [% IF Context.Scalar(Context.Scalar(items, "filter_by_for_hold"), "count") %]
 [% IF ( holdfor ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false">
 <i class="fa-solid fa-bookmark"></i>
 Reservera </button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber | uri %]">Reservera</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber | uri %]&amp;findborrower=[% holdfor_patron.cardnumber | uri %]">Reservera åt [% INCLUDE 'patron-title.inc' patron => holdfor_patron no_title => 1 %]</a></li>
 </ul>
 </div>
 [% ELSE %]
 <div class="btn-group"><a id="placehold" class="btn btn-default" href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblionumber | html %]" role="button"><i class="fa-solid fa-bookmark"></i> Reservera</a></div>
 [% END %]
 [% END %]
[% END %]

[% IF ( CAN_user_circulate_manage_bookings && biblio.items.filter_by_bookable.count ) %]
<div class="btn-group"><button id="placbooking" class="btn btn-default" data-bs-toggle="modal" data-bs-target="#placeBookingModal" data-biblionumber="[% biblionumber | html %]"><i class="fa fa-calendar"></i> Boka</button></div>
[% END %]

[% IF Koha.Preference('ArticleRequests') %]
 <div class="btn-group"><a id="placehold" class="btn btn-default" href="/cgi-bin/koha/circ/request-article.pl?biblionumber=[% biblionumber | html %]" role="button"><i class="fa-solid fa-file-lines"></i> Beställ artikel</a></div>
[% END %]

[% IF ( CAN_user_acquisition_order_manage ) %]
 [% IF ( searchtoorder_basketno && searchtoorder_vendorid ) %]
 <div class="btn-group">
 <a class="btn btn-default" href="/cgi-bin/koha/acqui/neworderempty.pl?booksellerid=[% searchtoorder_vendorid | uri %]&amp;basketno=[% searchtoorder_basketno | uri %]&amp;biblionumber=[% biblionumber | uri %]" role="button"><i class="fa fa-shopping-basket"></i> Lägg till beställning</a>
 </div>
 [% END %]
[% END %]

[% FOREACH p IN plugins %]
 [% p.intranet_catalog_biblio_enhancements_toolbar_button | $raw %]
[% END %]

</div>

 <!--Modal for Dublin Core-->
 <div class="modal" id="exportModal_" tabindex="-1" role="dialog" aria-labelledby="exportLabelexportModal_" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="exportLabelexportModal_">Exporterar till Dublin Core...</h1>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <form method="get" action="/cgi-bin/koha/catalogue/export.pl">
 <div class="modal-body">
 <fieldset>
 <input id="input-simple" type="radio" name="format" value="rdfdc">
 <label for="input-simple">Simpel DC-RDF</label>
 <br>
 <input id="input-oai" type="radio" name="format" value="oaidc" checked>
 <label for="input-oai">OAI-DC</label>
 <br>
 <input id="input-srw" type="radio" name="format" value="srwdc">
 <label for="input-srw">SRW-DC</label>
 <br>
 </fieldset>
 </div>
 <div class="modal-footer">
 <button type="submit" class="btn btn-primary">Exportera</button>
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Stäng</button>
 </div>
 <input type="hidden" name="op" value="export" />
 <input type="hidden" name="bib" value="[% biblionumber | html %]" />
 </form>
 </div>
 </div>
 </div>

 [% INCLUDE modals/place_booking.inc %]
