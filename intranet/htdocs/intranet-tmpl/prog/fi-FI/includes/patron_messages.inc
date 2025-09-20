[% USE raw %]
[% USE Branches %]
[% USE Categories %]
[% SET ClaimReturnedWarningThreshold = Koha.Preference('ClaimReturnedWarningThreshold') %]
[% SET return_claims = patron.return_claims %]
[% SET logged_in_branchcode = Branches.GetLoggedInBranchcode() %]

[% IF ( has_modifications || warndeparture || returnbeforeexpiry || expired || patron.gonenoaddress || patron.lost || userdebarred || odues || ( return_claims.count > ClaimReturnedWarningThreshold ) || age_limitations || limited_category || charges || charges_guarantors_guarantees || charges_guarantees || credits || patron.account_locked ) %]
 <h3>Huomio</h3>
 <ul>
 [% IF ( has_modifications ) %]
 <li class="has_modifications">
 <span class="circ-hlt">Odottavat muutokset:</span>
 [% IF CAN_user_borrowers_edit_borrowers && ( !Koha.Preference('IndependentBranchesPatronModifications') || borrower.branch == branch ) %]
 <a href="/cgi-bin/koha/members/members-update.pl?active=[% patron.borrowernumber | uri %]">Tarkista odottavat muutospyynnöt</a>
 [% ELSE %]
 <span>Asiakkaalla on odottavia muutospyyntöjä</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( warndeparture ) %]
 <li class="warndeparture">
 <span class="circ-hlt">Vanhenee:</span>
 <span>Asiakkaan kortti vanhenee [% patron.dateexpiry | $KohaDates %].</span>
 [% IF ( moremember ) %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=member&amp;reregistration=y">Uusinta</a> tai <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=member&amp;borrowernumber=[% patron.borrowernumber | uri %]">Muokkaa tietoja</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=circ&amp;reregistration=y">Uusinta</a> tai <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | uri %]">Muokkaa tietoja</a>
 [% END %]
 </li>
 [% END %]

 [% IF ( returnbeforeexpiry ) %]
 <li class="returnbeforeexpiry">
 <span class="circ-hlt">Aseta eräpäivä:</span> Olet asettanut ReturnBeforeExpiry järjestelmäasetuksen käyttöön ja se tarkoittaa, että jos vanhenemispäivä on ennen eräpäivää, eräpäiväksi tulee vanhenemispäivä </li>
 [% END %]

 [% IF ( expired ) %]
 <li class="expired">
 <span class="circ-hlt">Vanhenee:</span>
 <span>Asiakkaan kortti on vanhentunut.</span>
 [% IF ( expiry ) %]
 <span>Asiakkaan kortti on vanhentunut [% expiry | $KohaDates %]</span>
 [% END %]
 [% IF ( moremember ) %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=member&amp;reregistration=y">Uusinta</a> tai <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=member&amp;borrowernumber=[% patron.borrowernumber | uri %]">Muokkaa tietoja</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=circ&amp;reregistration=y">Uusinta</a> tai <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | uri %]">Muokkaa tietoja</a>
 [% END %]
 </li>
 [% END %]

 [% IF patron.account_locked %]
 <li class="blocker [% patron.login_attempts < 0 ? 'account_admin_locked' : 'account_locked' | html %]">
 [% IF patron.login_attempts < 0 %]
 <span class="circ-hlt">Lukittu: </span><span> Tili on lukittu hallinnollisesti</span>
 [% ELSE %]
 <span class="circ-hlt">Lukittu: </span><span> Tili on lukittu (johtuen [% patron.login_attempts | html %] epäonnistuneesta kirjautumisyrityksestä)</span>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 <span>
 <a href="/cgi-bin/koha/members/member-password.pl?member=[% patron.borrowernumber | uri %]">Vaihda salasana</a>
 <span class="fa fa-info-circle" data-bs-placement="right" data-bs-toggle="tooltip" title="Salasanan vaihtaminen vapauttaa tilin"> </span>
 </span>
 [% END %]
 </li>
 [% END %]

 [% IF ( patron.gonenoaddress ) %]
 <li class="gonenoaddress blocker">
 <span title="Asiakastietoihin on asetettu 'tarkista osoite' -merkintä"><span class="circ-hlt">Osoite:</span> Tarkista osoite</span> <a class="btn btn-default btn-xs" href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3#memberentry_account_flags"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa</a>
 </li>
 [% END %]

 [% IF ( patron.lost ) %]
 <li class="lost blocker">
 <span title="asiakkaan kortti on merkitty kadonneeksi"><span class="circ-hlt">Kadonnut: </span> Asiakkaan kortti on merkitty kadonneeksi</span> <a class="btn btn-default btn-xs" href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3#memberentry_account_flags"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa</a>
 </li>
 [% END %]

 [% IF ( userdebarred ) %]
 <li class="userdebarred blocker">
 <span class="circ-hlt"> Rajoitettu lähtien [% debarredsince | $KohaDates %]:</span> Asiakkaan tilillä on rajoitus [% IF ( userdebarreddate ) %] [% userdebarreddate | $KohaDates %] asti [% END %] [% IF ( debarredcomment ) %] Selitys: <br/>
 <em>
 [% IF debarredcomment.search('OVERDUES_PROCESS') %] Rajoite tullut palautuskehoituksesta [% debarredcomment.remove('OVERDUES_PROCESS ') | $raw | html_line_break %] [% ELSE %] [% FOREACH restriction IN patron.restrictions %] <div class="[% restriction.type.code | lower | html %]_restriction">
 <span class="restriction_expiration">
 [% IF restriction.expiration %]
 [% restriction.expiration | $KohaDates %]
 [% ELSE %]
 <strong>Voimassa toistaiseksi</strong>
 [% END %]
 </span>
 <span class="restriction_detail">
 [%- restriction.type.display_text | html -%][%- IF restriction.comment -%]: [%- restriction.comment | html_line_break -%][%- END -%]
 </span>
 </div>
 [% END %]
 [% END %]
 </em><br/>
 [% END %]
 <a class="btn btn-xs btn-default" href="#reldebarments-tab" onclick="(new bootstrap.Tab($('#reldebarments-tab'))).show()"><i class="fa fa-ban"></i> Näytä rajoitukset</a>
 </li> <!-- /.blocker -->
 [% END # /IF userdebarred %]

 [% IF ( odues ) %]
 <li class="odues blocker">
 <span class="circ-hlt">Myöhässä olevat lainat:</span> Asiakkaalla on myöhässä olevia lainoja <a href="#checkouts_panel" onclick="$('#issues-table-load-immediately').click(); $('#issues-table-load-immediately').click();">Katso korostetut kohteet alla </a>
 </li>
 [% END %]

 [% IF return_claims.count > ClaimReturnedWarningThreshold %]
 <li class="return_claims blocker">
 <span class="circ-hlt return-claims">Palautusilmoitukset:</span> Asiakkaalla on [% return_claims.count | html %] palautusilmoitusta </li>
 [% END %]

 [% IF age_limitations %]
 <li class="invalid_age">
 <span class="circ-hlt">Asiakkaan ikä ei ole asiakastyypin sallituissa rajoissa.</span>
 Sallittu ikäväli on [% age_low | html %]-[% age_high | html %]. <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3" class="btn btn-default btn-xs">Vaihda luokka</a>
 </li>
 [% END %]

 [% IF limited_category %]
 <li class="limited_category">
 <span class="circ-hlt">Asiakkaan nykyinen asiakastyyppi ([% Categories.GetName(patron.categorycode) | html %]) ei ole käytössä tässä kirjastossa.</span>
 <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3" class="btn btn-default btn-xs">Vaihda luokka</a>
 </li>
 [% END %]

 [% IF ( charges ) %]
 [% INCLUDE 'blocked-fines.inc' NoIssuesCharge = chargesamount %]
 [% END %]

 [% IF ( charges_guarantors_guarantees ) %]
 <li class="charges_guarantors_guarantees">
 <span class="circ-hlt">Maksut:</span> Asiakkaan takaajilla ja heidän muilla taattavillaan on maksuja yhteensä [% charges_guarantors_guarantees | $Price %]. [% IF noissues %] <span class="circ-hlt">Lainaus on estetty, koska asiakkaalla on liikaa maksuja.</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( charges_guarantees ) %]
 <li class="charges_guarantees">
 <span class="circ-hlt">Maksut:</span> Asiakkaan taattavilla on yhteensä maksuja [% chargesamount_guarantees | $Price %] €. [% IF noissues %] <span class="circ-hlt">Lainaus on estetty, koska asiakkaalla on liikaa maksuja.</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( credits ) %]
 <li class="credits">
 <span class="circ-hlt">Hyvitykset:</span> Asiakkaan tilillä on hyvitys[% IF ( creditsamount ) %] suuruudeltaan <span class="credit"><strong>[% creditsamount | $Price %]</strong></span>[% END %]
 </li>
 [% END %]
 [% IF (noissues && CAN_user_circulate_force_checkout && !moremember) %]
 <li>
 <span class="override_debarment">
 <a href="/cgi-bin/koha/circ/circulation.pl?forceallow=1&amp;borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-xs btn-default">Ohita rajoitus tilapäisesti</a>
 </span>
 </li>
 [% END %]
 </ul>

[% END # /F ( has_modifications || warndeparture... %]

[% IF waiting_recalls.count %]
 <div id="recallswaiting" class="circmessage">
 [% SET waiting_here = 0 %]
 [% SET waiting_elsewhere = 0 %]
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id == logged_in_branchcode  ) %]
 [% waiting_here = waiting_here + 1 %]
 [% ELSE %]
 [% waiting_elsewhere = waiting_elsewhere + 1 %]
 [% END %]
 [% END %]

 [% IF ( waiting_here > 0 ) %]
 <h4>Odottavia palautuspyyntöjä ([% waiting_here | html %])</h4>
 <ul>
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id == logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% w.biblio_id | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] by [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Palautuspyyntö tehty niteeseen [% w.created_date | $KohaDates %].</span>
 <br />
 <strong class="waitinghere">
 [% SET expires_on = w.expiration_date %] Odottaa tässä kirjastossa [% IF expires_on %] saakka [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]

 [% IF ( waiting_elsewhere > 0 ) %]
 <h4>Palautuspyynnöt noudettavissa muista kirjastoista ([% waiting_elsewhere | html %])</h4>
 <ul>
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id != logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% w.biblio_id | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] by [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Palautuspyyntö tehty niteeseen [% w.created_date | $KohaDates %].</span>
 <br />
 <strong>
 [% SET expires_on = w.expiration_date %] Odottaa kirjastossa [% Branches.GetName( w.pickup_library_id ) | html %] [% IF expires_on %] saakka [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 </div>
[% END # /IF waiting_recalls.count %]

[% IF WaitingHolds.count %]
 <div id="holdswaiting" class="circmessage">
 [% SET waiting_here = 0 %]
 [% SET waiting_elsewhere = 0 %]
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode == logged_in_branchcode  ) %]
 [% waiting_here = waiting_here + 1 %]
 [% ELSE %]
 [% waiting_elsewhere = waiting_elsewhere + 1 %]
 [% END %]
 [% END %]

 [% IF ( waiting_here > 0 ) %]
 <h4>Odottavia varauksia ([% waiting_here | html %])</h4>
 <ul>
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode == logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% w.biblio.biblionumber | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] by [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span class="holddate">Varaus tehty niteeseen [% w.reservedate | $KohaDates %].</span>
 <br />
 <strong class="waitinghere">
 [% SET expires_on = w.expirationdate %] Odottaa tässä kirjastossa [% IF expires_on %] [% expires_on | $KohaDates %][% END %] saakka. </strong>
 <strong class="waitingsince">
 Odottanut tässä kirjastossa [% w.waitingdate | $KohaDates %] lähtien. </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]

 [% IF ( waiting_elsewhere > 0 ) %]
 <h4>Varaukset noudettavissa muista kirjastoista ([% waiting_elsewhere | html %])</h4>
 <ul>
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode != logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% w.biblio.biblionumber | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] by [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Varaus tehty niteeseen [% w.reservedate | $KohaDates %].</span>
 <br />
 <strong>
 [% SET expires_on = w.expirationdate %] Odottaa kirjastossa [% w.branch.branchname | html %] [% IF expires_on %] saakka [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 </div>
[% END # /IF WaitingHolds.count %]

[% IF Koha.Preference("CurbsidePickup") %]
 [% SET curbside_pickups = patron.curbside_pickups.search( branchcode => Branches.GetLoggedInBranchcode ) %]
 [% IF curbside_pickups.count %]
 <div id="curbside_pickups" class="circmessage">
 <h4>Kirjastoon ajastetut noudot</h4>
 <ul>
 [% FOR cp IN curbside_pickups %]
 <li>Pvm [% cp.scheduled_pickup_datetime | $KohaDates %]: [% SWITCH cp.status %] [% CASE 'to-be-staged' %] <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=to-be-staged">
 Valmisteltavat</a>
 [% CASE 'staged-and-ready' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=staged-and-ready">
 Valmiita odottamassa</a>
 [% CASE 'patron-is-outside' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=patron-is-outside">
 Asiakas odottaa ulkona!</a>
 [% CASE 'delivered' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=delivered-today">
 Toimitettu</a>
 [% CASE %]<span>Tuntematon tila "[% cp.status | html %]"</span>
 [% END %]
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
[% END %]

[% IF ( patron.borrowernotes ) %]
 <div id="circnotes" class="circmessage">
 <h4>Huomautukset</h4>
 <ul>
 <li>
 <span class="circ-hlt">
 [% patron.borrowernotes | $raw | html_line_break %]
 </span>
 </li>
 </ul>
 </div> <!-- /#circnotes -->
[% END # /IF patron.borrowernotes %]

[% IF ( patron_messages ) %]
 <div id="messages" class="circmessage">
 <h4>Viestit</h4>
 <ul>
 [% FOREACH patron_message IN patron_messages %]
 <li>
 [% IF(patron_message.message_type == "L") %]
 <span class="circ-hlt">
 [% ELSE %]
 <span>
 [% END %]
 [% patron_message.message_date | $KohaDates %]
 [% Branches.GetName( patron_message.branchcode ) | html %]
 [% IF patron_message.manager_id %]
 ( <a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% patron_message.manager_id | uri %]">[% patron_message.get_column('manager_firstname') | html %] [% patron_message.get_column('manager_surname') | html %]</a> )
 [% END %]
 <em>"[% patron_message.message | html | html_line_break %]"</em>
 [% IF patron_message.patron_read_date %] Lue: <em>[% patron_message.patron_read_date | $KohaDates %]</em>
 [% END %]
 </span>
 [% IF patron_message.branchcode == Branches.GetLoggedInBranchcode OR Koha.Preference('AllowAllMessageDeletion') %]
 [% IF moremember %]
 <a id="#edit_message_form_[% patron_message.message_id | html %]" class="btn btn-link edit_message" href="#edit_message_form_[% patron_message.message_id | uri %]" data-bs-target="#edit_message_form_[% patron_message.message_id | html %]" data-bs-toggle="modal"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa</a>
 <form action="/cgi-bin/koha/circ/del_message.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete">
 <input type="hidden" name="message_id" value="[% patron_message.message_id | html %]">
 <input type="hidden" name="borrowernumber" value="[% patron_message.borrowernumber | html %]">
 <input type="hidden" name="from" value="moremember">
 <button type="submit" class="btn btn-link delete_message"><i class="fa fa-trash-can"></i> Poista</button>
 </form>
 [% ELSE %]
 <a id="#edit_message_form_[% patron_message.message_id | html %]" class="btn btn-link edit_message" href="#edit_message_form_[% patron_message.message_id | uri %]" data-bs-target="#edit_message_form_[% patron_message.message_id | html %]" data-bs-toggle="modal"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa</a>
 <form action="/cgi-bin/koha/circ/del_message.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete">
 <input type="hidden" name="message_id" value="[% patron_message.message_id | html %]">
 <input type="hidden" name="borrowernumber" value="[% patron_message.borrowernumber | html %]">
 <button type="submit" class="btn btn-link delete_message"><i class="fa fa-trash-can"></i> Poista</button>
 </form>
 [% END %]
 [% END %]
 </li>
 [% END %]
 </ul>
 <a id="addnewmessageLabel" data-bs-target="#add_message_form" class="btn btn-link" data-bs-toggle="modal"><i class="fa fa-plus"></i> Lisää uusi viesti</a>
 </div> <!-- /#messages -->

 [% FOREACH pm IN patron_messages %]
 <div id="edit_message_form_[% pm.message_id | html %]" class="modal" tabindex="-1" aria-labelledby="#edit_message_form_[% patron_message.message_id | html %]" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <form method="post" action="/cgi-bin/koha/circ/add_message.pl" id="edit_message_form" name="message_f">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-edit_message">
 <input type="hidden" name="message_id" value="[% pm.message_id | html %]"/>
 <div class="modal-header">
 <h1 class="modal-title">Muokkaa viestiä</h1>
 </div>
 <div class="modal-body">
 <div class="form-group">
 <label for="edit_message_type">
 Viestintäkanava: <select name="message_type" id="edit_message_type" disabled>
 [% IF pm.message_type == "L" %]
 <option value="L" selected="selected">Virkailija - Sisäinen huomautus</option>
 [% ELSE %]
 <option value="L">Virkailija - Sisäinen huomautus</option>
 [% END %]

 [% IF pm.message_type == "B" %]
 <option value="B" selected="selected">Verkkokirjasto - [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% ELSE %]
 <option value="B">Verkkokirjasto - [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% END %]
 </select>
 </label>
 </div>
 <div class="form-group">
 <textarea rows="3" class="modal-textarea" name="borrower_message" id="edit_borrower_message" >[% pm.message | html %]</textarea>
 </div>
 </div>
 <div class="modal-footer">
 <button class="btn btn-default approve" type="submit"><i class="fa fa-check"></i> Tallenna</button>
 <button class="btn btn-default deny cancel" type="button" data-bs-dismiss="modal"><i class="fa fa-times"></i> Peruuta</button>
 </div>
 </form>
 </div>
 </div>
 </div>
 [% END %]
[% END # /IF patron_messages %]
