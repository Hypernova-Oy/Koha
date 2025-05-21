[% USE Koha %]
[% USE Branches %]
[% USE Categories %]
[% USE Notices %]
[% USE AuthorisedValues %]
[% USE NoticeTemplates %]
[% USE scalar %]
<div id="toolbar" class="btn-toolbar">
 [% IF CAN_user_borrowers_edit_borrowers %]
 <a id="editpatron" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | html %]"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa</a>
 [% END %]
 [% SET guarantee_categories = Categories.limited( can_be_guarantee => 1 ).unblessed  %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF patron.is_adult AND Koha.Preference("borrowerRelationship") %]
 [% IF guarantee_categories.size > 1 %]
 <div id="addchild" class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa fa-plus"></i> Lisää taattava</button>
 <ul class="dropdown-menu">
 [% FOREACH cat IN guarantee_categories %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/members/memberentry.pl?op=add_form&amp;guarantor_id=[% patron.borrowernumber | html %]&categorycode=[%  cat.categorycode | html %]">[% cat.description | html%]</a></li>
 [% END %]
 </ul>
 </div>
 [% ELSE %]
 <a id="addchild" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=add_form&amp;guarantor_id=[% patron.borrowernumber | html %]"><i class="fa fa-plus"></i> Lisää taattava</a>
 [% END %]
 [% END %]
 <a id="changepassword" class="btn btn-default" href="/cgi-bin/koha/members/member-password.pl?member=[% patron.borrowernumber | html %]"><i class="fa fa-lock"></i> Vaihda salasana</a>
 <a id="duplicate" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=duplicate&amp;borrowernumber=[% patron.borrowernumber | html %]"><i class="fa fa-copy"></i> Kopioi</a>
 [% END %]

 [% IF CAN_user_circulate_circulate_remaining_permissions %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa fa-print"></i> Tulosta</button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item printslip" data-code="printsummary" href="#">Asiakastietojen yhteenveto</a></li>
 <li><a class="dropdown-item printslip" data-code="issueslip" href="#">Tulosta kuitti</a></li>
 <li><a class="dropdown-item printslip" data-code="issueqslip" href="#">Tänään lainatut</a></li>
 [% IF patron.account_balance != 0 %]
 <li><a class="dropdown-item" id="printfineslip" target="_blank" href="/cgi-bin/koha/members/printnotice.pl?notice=ACCOUNTS_SUMMARY&borrowernumber=[% patron.borrowernumber | uri %]">Tulosta asiakkaan maksut</a></li>
 [% END %]
 [% IF patron.has_overdues %]
 <li><a class="dropdown-item" id="print_overdues" href="#">Tulosta erääntyneet</a></li>
 [% END %]
 [% IF patron.privacy < 2 %] [%# 2 is the privacy rule "Never" (Delete my history immediately) %]
 <li><a class="dropdown-item printslip" data-code="checkinslip" href="#">Tulosta palautuskuitti</a></li>
 [% END %]
 [% FOREACH notice IN Notices.GetTemplates( 'patron_slip' ) %]
 <li><a class="dropdown-item printslip" data-code="[% notice.code | html %]" href="#">Tulosta [% notice.name | html %]</a></li>
 [% END %]
 </ul>
 </div>
 [% END %]

 [% IF ( CAN_user_reserveforothers ) %]
 <a id="searchtohold" class="btn btn-default" href="#"><i class="fa fa-search"></i> Hae ja varaa</a>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <a id="toolbar_addnewmessageLabel" href="#add_message_form" data-bs-toggle="modal" class="btn btn-default"><i class="fa-solid fa-comment"></i> Lisää viesti</a>
 [% END %]

 [% IF Koha.Preference('CurbsidePickup') %]
 <a id="curbsidePickupLabel" href="/cgi-bin/koha/circ/curbside_pickups.pl?op=find-patron&borrowernumber=[% patron.borrowernumber | html %]" class="btn btn-default"><i class="fa-solid fa-rotate"></i> Ajasta nouto</a>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown">Muita toimintoja <span class="caret"></span></button>
 <ul class="dropdown-menu dropdown-menu-end">
 [% IF CAN_user_borrowers_edit_borrowers %]
 <li>
 <a class="dropdown-item" id="renewpatron" href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | html %]&amp;destination=[% destination | html %]&amp;reregistration=y">Asiakkaan käyttöoikeuden jatkaminen</a>
 </li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Sinulla ei ole oikeuksia uusia asiakasta">
 <a class="dropdown-item disabled" aria-disabled="true" id="renewpatron" href="#">Asiakkaan käyttöoikeuden jatkaminen</a>
 </li>
 [% END %]
 [% IF ( CAN_user_permissions ) %]
 <li>
 <a class="dropdown-item" id="patronflags" href="/cgi-bin/koha/members/member-flags.pl?member=[% patron.borrowernumber | html %]">Aseta virkailijaoikeuksia</a>
 </li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Sinulla ei ole oikeuksia asettaa oikeuksia">
 <a class="dropdown-item disabled" aria-disabled="true" id="patronflags" href="#">Aseta virkailijaoikeuksia</a>
 </li>
 [% END %]
 [% IF ( Koha.Preference('TwoFactorAuthentication') == 'enforced' || Koha.Preference('TwoFactorAuthentication') == 'enabled' ) && logged_in_user.borrowernumber == patron.borrowernumber %]
 <li><a class="dropdown-item" id="twofa" href="/cgi-bin/koha/members/two_factor_auth.pl">Hallinnoi kaksivaiheista tunnistautumista</a></li>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers && useDischarge %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/members/discharge.pl?borrowernumber=[% patron.borrowernumber | uri %]">Velattomuusilmoitus</a></li>
 [% END %]

 [% IF Koha.Preference('RESTOAuth2ClientCredentials') %]
 [% IF CAN_user_superlibrarian OR loggedinusernumber == patron.borrowernumber %]
 <li>
 <a class="dropdown-item" id="apikeys" href="/cgi-bin/koha/members/apikeys.pl?patron_id=[% patron.borrowernumber | html %]">Hallinnoi API-avaimia</a>
 </li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Sinulla ei ole oikeuksia hallinnoida API-avaimia">
 <a class="dropdown-item disabled" aria-disabled="true" id="apikeys" href="#">Hallinnoi API-avaimia</a>
 </li>
 [% END %]
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <li>
 <a class="dropdown-item" id="sendwelcome" href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]&op=send_welcome">Lähetä tervetulosähköposti</a>
 </li>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers && patron.category.effective_reset_password %]
 <li><a class="dropdown-item" id="resetpassword" href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]&op=send_password_reset">Lähetä salasanan nollaus</a></li>
 [% END %]

 [% IF CAN_user_borrowers_delete_borrowers %]
 [% IF ( patron.protected == 1 ) %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Asiakas on suojattu">
 <a class="dropdown-item disabled" aria-disabled="true" id="deletepatron" href="#">Poista</a>
 </li>
 [% ELSE %]
 <li>
 <a class="dropdown-item" id="deletepatron" href="#">Poista</a>
 </li>
 [% END %]
 [% ELSE %]
 <li aria-disabled="true" data-bs-placement="left" data-bs-toggle="tooltip" title="Sinulla ei ole oikeuksia poistaa asiakasta">
 <a class="dropdown-item disabled" id="deletepatron" href="#">Poista</a>
 </li>
 [% END %]

 [% SET adult_categories = Categories.scalar.all(category_type => 'A') %]
 [% IF adult_categories.count > 0 %]
 [% IF patron.is_child %]
 <li>
 <a class="dropdown-item" id="updatechild" href="#">Päivitä lapsi aikuiseksi</a>
 </li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Asiakas on aikuinen">
 <a href="#" class="dropdown-item disabled" aria-disabled="true" id="updatechild">Päivitä lapsi aikuiseksi</a>
 </li>
 [% END %]
 [% END %]
 [% IF Koha.Preference('intranetreadinghistory') %]
 [% IF ( patron.privacy == 2 ) %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Asiakkaan yksityisyysasetukset estävät">
 <a class="dropdown-item disabled" aria-disabled="true" id="exportbarcodes" href="#">Vie tänään palautettujen lainojen viivakoodit tiedostoon</a>
 </li>
 [% ELSE %]
 <li>
 <a class="dropdown-item" id="exportcheckins" href="#">Vie tänään palautettujen lainojen viivakoodit tiedostoon</a>
 </li>
 [% END %]
 [% END %]
 </ul>
 </div>
 [% END %]
</div>

<!-- Modal -->
<div id="add_message_form" class="modal" tabindex="-1" role="dialog" aria-labelledby="addnewmessageLabel toolbar_addnewmessageLabel" aria-hidden="true">
 <div class="modal-dialog modal-lg">
 <div class="modal-content modal-lg">
 <form method="post" action="/cgi-bin/koha/circ/add_message.pl" id="message_form" name="message_f">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-add_message">
 <div class="modal-header">
 <h1 class="modal-title">Jätä viesti</h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <fieldset id="message_fieldset">
 <ol>
 <li class="form-group form-row">
 <label for="message_type" class="col-form-label">Lisää viesti kohteelle:</label>
 <select name="message_type" id="message_type" class="form-select">
 <option value="L">Virkailija - Sisäinen huomautus</option>
 <option value="B">Verkkokirjasto - [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% IF CAN_user_borrowers_send_messages_to_borrowers %]
 <option value="E">Sähköposti - asiakkaan sähköpostiosoitteet</option>
 [% END %]
 </select>
 </li>

 [% bor_notes = AuthorisedValues.Get( 'BOR_NOTES' ) %]
 [% IF bor_notes %]
 <li class="form-group form-row">
 <label for="select_patron_messages" class="col-form-label">Esimääritellyt viestit: </label>
 <select name="type" id="select_patron_messages" class="form-select">
 <option value="">Valitse viesti</option>
 [% FOREACH bor_note IN bor_notes %]
 <option value="[% bor_note.lib | html %]">[% bor_note.lib | html %]</option>
 [% END %]
 </select>
 </li>
 [% END %]

 [% patron_letters = NoticeTemplates.GetByModule( 'add_message' ) %]
 [% IF patron_letters %]
 <li class="form-group form-row">
 <label for="select_patron_notice" class="col-form-lable" style="display:none;">Asiakasviesti: </label>
 <select name="select_patron_notice" id="select_patron_notice" class="form-select" style="display:none;">
 <option value="">Valitse asiakasviesti</option>
 [% FOREACH letter IN patron_letters %]
 <option value="[% letter.code | html %]">[% letter.name | html %]</option>
 [% END %]
 </select>
 </li>
 [% END %]

 <li class="form-group form-row" id="subject_form" style="display: none;">
 <label for="borrower_subject" class="col-form-label">Aihe:</label>
 <input type="text" size="60" name="borrower_subject" class="form-control" id="borrower_subject"/>
 </li>
 <li class="form-group form-row">
 <label for="borrower_message" class="col-form-label" style="display: none;">Viesti:</label>
 <textarea cols="65" rows="5" name="borrower_message" class="form-control" id="borrower_message" ></textarea>
 </li>
 </ol>
 </fieldset>
 <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <input type="hidden" name="batch" value="[% batch | html %]" />
 <input type="hidden" name="branchcode" value="[% Branches.GetLoggedInBranchcode | html %]" />
 </div>
 <div class="modal-footer">
 <button class="btn btn-default approve" type="submit"><i class="fa fa-check"></i> Tallenna</button>
 <button class="btn btn-default deny cancel" type="button" data-bs-dismiss="modal"><i class="fa fa-times"></i> Peruuta</button>
 </div>
 </form>
 </div>
 </div>
</div>
