[% USE Koha %]
[% USE KohaDates %]
[% PROCESS 'member-display-address-style.inc' %]
[% IF ( patron.borrowernumber ) %]
 [% SET patron_is_staff = patron.has_permission({ 'catalogue' => 1 }) %]
 [% SET patron_is_superlibrarian = patron.is_superlibrarian %]
 [% SET patron_type_class = 'is-not-staff' %]
 [% IF ( patron_is_superlibrarian ) %]
 [% patron_type_class = 'is-staff is-superlibrarian' %]
 [% ELSIF ( patron_is_staff ) %]
 [% patron_type_class = 'is-staff' %]
 [% END %]

 <div class="patroninfo [% patron_type_class | html %]">
 <h5>
 [% IF ( patron_is_staff ) %]
 <i class="fa-solid fa-shield fa-fw" title="Henkilökunta-asiakas"></i>
 [% END %]
 [% IF ( patron_is_superlibrarian ) %]
 <i class="fa fa-bolt fa-fw" title="Pääkäyttäjä"></i>
 [% END %]
 [% IF ( patron.protected ) %]
 <i class="fa fa-lock fa-fw" title="Suojattu asiakas"></i>
 [% END %]
 [% INCLUDE 'patron-title.inc' %]
 </h5>

 [% IF Koha.Preference('showLastPatron') %]
 <input type="hidden" id="hiddenborrowernumber" value="[% patron.borrowernumber | html %]">
 <input type="hidden" id="hiddenborrowername" value="[% patron.surname | html %] [% patron.firstname | html %]">
 <input type="hidden" id="hiddenborrowercard" value="[% patron.cardnumber | html %]">
 [% END %]

 <div class="patroninfo-container">
 [% IF ( patronimages ) %]
 <div class="patronimage-container">
 [% IF ( patron.image ) %]
 <img src="/cgi-bin/koha/members/patronimage.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="patronimage" alt="[% patron.firstname | html %] [% patron.surname | html %] ([% patron.cardnumber | html %])" />
 [% IF ( CAN_user_tools_batch_upload_patron_images ) %]
 <div class="patronimage-controls">
 <div class="patronimage-control">
 <a class="btn btn-default edit-patronimage" data-borrowernumber="[% patron.borrowernumber | uri %]" data-cardnumber="[% patron.cardnumber | html %]" href="#" title="Asiakaskuva"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa</a>
 </div>
 </div>
 [% END %]
 [% ELSE %]
 <div class="patronimage empty"></div>
 [% IF ( CAN_user_tools_batch_upload_patron_images ) %]
 <div class="patronimage-controls">
 <div class="patronimage-control">
 <a class="btn btn-default edit-patronimage" data-borrowernumber="[% patron.borrowernumber | uri %]" data-cardnumber="[% patron.cardnumber | html %]" href="#" title="Asiakaskuva"><i class="fa fa-plus"></i> Lisää</a>
 </div>
 </div>
 [% END %]
 [% END # /IF patron.image %]
 </div> <!-- /.patronimage-container -->
 [% END # /IF patronimages %]
 <div>
 <ul class="patronbriefinfo">
 [% IF patron.pronouns %]
 <li class="patronpronouns">([% patron.pronouns | html %])</li>
 [% END %]

 [% IF !(Koha.Preference('HidePersonalPatronDetailOnCirculation')) %]

 [% PROCESS 'display-address-style' %]

 [% IF ( patron.phone || patron.mobile || patron.phonepro ) %]
 <li class="patronphone">
 [% IF ( patron.phone ) %]
 <a href="tel:[% patron.phone | url %]">[% patron.phone | html %]</a>
 [% ELSE %]
 [% IF ( patron.mobile ) %]
 <a href="tel:[% patron.mobile | url %]">[% patron.mobile | html %]</a>
 [% ELSE %]
 [% IF ( patron.phonepro ) %]
 <a href="tel:[% patron.phonepro | url %]">[% patron.phonepro | html %]</a>
 [% END %]
 [% END %]
 [% END %]
 </li>
 [% END # /IF phones %]
 [% IF ( patron.email ) %]
 <li class="email">
 <a href="mailto:[% patron.email | url %]" title="[% patron.email | html %]">[% patron.email | html %]</a>
 </li>
 [% ELSE %]
 [% IF ( patron.emailpro ) %]
 <li class="email">
 <a href="mailto:[% patron.emailpro | url %]" title="[% patron.emailpro | html %]">[% patron.emailpro | html %]</a>
 </li>
 [% END %]
 [% END # /IF emails %]
 [% IF ( patron.dateofbirth ) %]
 <li class="patrondateofbirth">
 <span>Syntynyt:</span>
 [% INCLUDE 'patron-age.inc' %]
 </li>
 [% END %]

 [% UNLESS ( patron.address or patron.address2 ) %]
 <li><span class="empty" id="noaddressstored">Ei osoitetta.</span></li>
 [% END %]
 [% UNLESS ( patron.city ) %]
 <li><span class="empty" id="nocitystored">Ei kuntaa.</span></li>
 [% END %]
 [% UNLESS ( patron.phone or patron.mobile or patron.phonepro) %]
 <li> <span class="empty">Ei puhelinnumeroa.</span></li>
 [% END %]
 [% UNLESS ( patron.email or patron.emailpro) %]
 <li> <span class="empty">Ei sähköpostiosoitetta.</span></li>
 [% END %]
 [% UNLESS ( patron.dateofbirth ) %]
 <li> <span class="empty">Syntymäaikaa ei ole tallennettu.</span></li>
 [% END %]

 [% END # /IF HidePersonalPatronDetailOnCirculation %]

 [% IF Koha.Preference('ExtendedPatronAttributes') %]
 [% FOREACH extendedattribute IN patron.extended_attributes %]
 [% IF ( extendedattribute.type.display_checkout ) %] [%# FIXME We should filter in the line above %]
 [% IF ( extendedattribute.attribute.defined  ) %]
 <li class="patronattribute">
 <span class="patronattributelabel">[% extendedattribute.type.description | html %]</span>:
 [% IF extendedattribute.type.is_date %]
 [% extendedattribute.description | $KohaDates %]
 [% ELSE %]
 [% extendedattribute.description | html %]
 [% END %]
 </li> <!-- /.patronattribute -->
 [% END %]
 [% END # /IF display_checkout %]
 [% END # /FOREACH extendedattribute %]
 [% END # /IF ExtendedPatronAttributes %]

 <li class="patroncategory">
 Tyyppi: <span class="patroncategory_description">[% patron.category.description | html %]</span> <span class="patroncategory_code">([% patron.categorycode | html %])</span>
 </li>
 <li class="patronlibrary">
 Kotikirjasto: [% Branches.GetName( patron.branchcode ) | html %] </li>
 <li class="patronborrowernumber">
 Asiakkaan ID: [% patron.borrowernumber | html %] </li>
 <li>
 <span class="patronupdatedon">Päivitetty [% patron.updated_on | $KohaDates with_hours => 1 %]</span>
 </li>
 [% IF patron.account_locked %]
 [% IF patron.login_attempts < 0 %]
 <li class="blocker account_admin_locked">Tili on lukittu hallinnollisesti</li>
 [% ELSE %]
 <li class="blocker account_locked">Tili on lukittu</li>
 [% END %]
 [% END %]
 </ul> <!-- /.patronbriefinfo -->
 </div>
 </div>
 </div> <!-- /.patronifo -->

 <div id="menu">
 <ul>
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% IF ( circview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[% patron.borrowernumber | uri %]">Lainaus</a>
 </li>
 [% IF Koha.Preference('BatchCheckouts') && Koha.Preference('BatchCheckoutsValidCategories').split(',').grep('^' _ patron.categorycode _ '$').size > 0 %]
 [% IF ( batch_checkout_view ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;batch=1">Erälainaus</a>
 </li>
 [% END %]
 [% END # /IF CAN_user_circulate_circulate_remaining_permissions %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( detailview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% patron.borrowernumber | uri %]">Tiedot</a>
 </li>
 [% END %]
 [% IF ( CAN_user_updatecharges_remaining_permissions ) %]
 [% IF ( finesview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/pay.pl?borrowernumber=[% patron.borrowernumber | uri %]">Maksut</a>
 </li>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions  )  %]
 [% IF Koha.Preference("RoutingSerials") %]
 [% IF ( routinglistview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/routing-lists.pl?borrowernumber=[% patron.borrowernumber | uri %]">Kiertolistat</a>
 </li>
 [% END %]
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( intranetreadinghistory ) %]
 [% IF ( readingrecordview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/readingrec.pl?borrowernumber=[% patron.borrowernumber | uri %]">Lainahistoria</a>
 </li>
 [% END %]
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( IntranetReadingHistoryHolds ) %]
 [% IF ( holdshistoryview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/holdshistory.pl?borrowernumber=[% patron.borrowernumber | uri %]">Varaushistoria</a>
 </li>
 [% END %]
 [% END %]
 [% IF ( CAN_user_tools_view_system_logs ) %]
 [% IF ( logview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/tools/viewlog.pl?do_it=1&amp;modules=MEMBERS&amp;modules=CIRCULATION&amp;object=[% patron.borrowernumber | uri %]&amp;src=circ">Muutosloki</a>
 </li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( sentnotices ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]">Ilmoitukset</a>
 </li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF (  statisticsview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/statistics.pl?borrowernumber=[% patron.borrowernumber | uri %]">Tilastot</a>
 </li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF ( EnableBorrowerFiles ) %]
 [% IF ( borrower_files ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/files.pl?borrowernumber=[% patron.borrowernumber | uri %]">Tiedostot</a>
 </li>
 [% END %]
 [% END %]

 [% IF CAN_user_suggestions_suggestions_create || CAN_user_suggestions_suggestions_manage || CAN_user_suggestions_suggestions_delete %]
 [% IF ( suggestionsview ) %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/purchase-suggestions.pl?borrowernumber=[% patron.borrowernumber | uri %]">Hankintaehdotukset</a>
 </li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers && useDischarge %]
 [% IF dischargeview %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/discharge.pl?borrowernumber=[% patron.borrowernumber | uri %]">Velattomuusilmoitukset</a>
 </li>
 [% END %]
 [% IF Koha.Preference('HouseboundModule') %]
 [% IF houseboundview %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/housebound.pl?borrowernumber=[% patron.borrowernumber | uri %]">Kotipalvelu</a>
 </li>
 [% END %]
 [% IF Koha.Preference('ILLModule') && CAN_user_ill %]
 [% IF illview %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/ill-requests.pl?borrowernumber=[% patron.borrowernumber | uri %]">Kaukolainapyyntöhistoria</a>
 </li>
 [% END %]
 [% IF Koha.Preference('UseRecalls') && CAN_user_recalls %]
 [% IF recallsview %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/recallshistory.pl?borrowernumber=[% patron.borrowernumber | uri %]">Palautuspyyntöhistoria</a>
 </li>
 [% END %]
 [% IF ( CAN_user_serials && patron.alert_subscriptions.count ) %]
 [% IF alertsview %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/members/alert-subscriptions.pl?borrowernumber=[% patron.borrowernumber | uri %]">Kausijulkaisutilausten saapumisilmoitukset ([% patron.alert_subscriptions.count | html %])</a>
 </li>
 [% END %]
 </ul>
 </div>

 [% IF patronimages && CAN_user_tools_batch_upload_patron_images %]
 <!-- Modal -->
 <div class="modal" id="patronImageEdit" tabindex="-1" role="dialog" aria-labelledby="patronImageEditLabel">
 <div class="modal-dialog modal-lg">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="patronImageEditLabel">Asiakaskuva</h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div> <!-- /.modal-header -->
 <div class="modal-body">
 [% IF ( patron.cardnumber ) %]
 <div id="upload-patron-image" class="patroninfo-section">
 <h5>Lataa asiakaskuva</h5>
 <form method="post" id="picture-upload" action="/cgi-bin/koha/tools/picture-upload.pl"
                                    enctype="multipart/form-data">
 [% IF ( patron.image ) %]
 <div class="hint">
 Päivittääksesi asiakkaan [% patron.title | html %] [% patron.firstname | html %] [% patron.surname | html %] kuvan, valitse uusi kuvatiedosto ja paina 'Lataa'. <br />Klikkaa 'Poista' -nappia poistaaksesi nykyisen kuvan. </div>
 [% ELSE %]
 <div class="hint">
 [% patron.title | html %] [% patron.firstname | html %] [% patron.surname | html %] kuvaa ei tällä hetkellä ole saatavilla. Ladataksesi kuvan asiakkaalle [% patron.title | html %] [% patron.firstname | html %] [% patron.surname | html %], valitse ladattava kuvatiedosto. </div>
 [% END # /IF patron.image %]
 <p>Tuetut kuvaformaatit ovat PNG, GIF, JPEG ja XPM.</p>
 <label for="uploadfile">Valitse vietävä tiedosto: </label>
 <input type="file" id="uploadfile" name="uploadfile" required="required" />
 <div class="action">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" id="image" name="filetype" value="image" />
 <input type="hidden" id="cardnumber" name="cardnumber" value="[% patron.cardnumber | html %]" />
 <input type="hidden" id="borrowernumber" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <button type="submit" class="btn btn-default btn-xs" name="op" value="cud-Upload"><i class="fa fa-upload"></i> Lataa kuva</button>
 </div> <!-- /.action -->
 </form> <!-- /#picture-upload -->
 [% IF ( patron.image ) %]
 <form method="post" id="picture-delete" action="/cgi-bin/koha/tools/picture-upload.pl" enctype="multipart/form-data">
 <div class="action" style="padding-top:0px;">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" id="image" name="filetype" value="image" />
 <input type="hidden" id="cardnumber" name="cardnumber" value="[% patron.cardnumber | html %]" />
 <input type="hidden" id="borrowernumber" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <button id="delpicture" type="submit" class="btn btn-default btn-xs delete" name="op" value="cud-Delete"><i class="fa fa-trash-can"></i> Poista</button>
 </div> <!-- /.action -->
 </form> <!-- /#picture-delete -->
 [% END %]
 </div> <!-- /#upload-patron-image -->
 <div id="capture-patron-image" class="patroninfo-section">
 <h5>Ota asiakaskuva</h5>
 <form method="post" id="camera-upload" action="/cgi-bin/koha/tools/picture-upload.pl">
 <div class="btn-toolbar">
 <div class="btn-group">
 <button class="btn btn-default" id="takebutton"><i class="fa fa-camera"></i> Ota kuva</button>
 </div>
 <div class="btn-group">
 <button class="btn btn-default" id="retakebutton" style="display:none;"><i class="fa-solid fa-rotate"></i> Ota kuva uudelleen</button>
 </div>
 <div class="btn-group">
 <a id="downloadbutton" href="#" class="btn btn-default" style="display:none;"><i class="fa fa-download"></i> Lataa kuva</a>
 </div>
 <div class="btn-group">
 <button id="savebutton" type="submit" class="btn btn-default" style="display:none;"><i class="fa-solid fa-hard-drive"></i> Lataa</button>
 </div>
 </div> <!-- /.btn-toolbar -->
 <div id="camera">
 <video id="viewfinder">Videostriimaus ei ole käytössä.</video>
 </div>
 <canvas id="canvas" style="display:none"></canvas>
 <div id="output" style="display:none">
 <img alt="Kuvakaappaus näkyy tässä ruudussa." id="photo" style="width:100%;height:auto;">
 </div>
 <input type="hidden" name="uploadfilename" value="patron-photo.jpg" />
 <textarea id="uploadfiletext" name="uploadfiletext" style="display:none;"></textarea>
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="filetype" value="image" />
 <input type="hidden" name="cardnumber" value="[% patron.cardnumber | html %]" />
 <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <input name="op" type="hidden" value="cud-Upload" />
 </form> <!-- /#camera-upload -->
 </div> <!-- /#capture-patron-image -->
 <div class="alert alert-info" style="display:none" id="camera-error">
 <div>
 <span class="fa-stack fa-lg">
 <i class="fa fa-camera fa-stack-1x"></i>
 <i class="fa fa-ban fa-stack-2x text-danger"></i>
 </span>
 </div>
 <div>
 <strong>Asiakaskuvaa ei voi ottaa.</strong>
 <span id="camera-error-message"></span>
 </div>
 </div> <!-- /.dialog.message -->
 [% ELSE %]
 <div id="missing-cardnumber-picture-upload">
 <p>Asiakkaalla pitää olla kirjastokortin numero ennen kuin voidaan ladata asiakaskuva.</p>
 </div>
 [% END # /IF patron.cardnumber %]
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Peruuta</button>
 </div>
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
 </div> <!-- /#patronImageEdit.modal -->
 [% END # /IF patronimages %]

[% END # /IF patron.borrowernumber %]
