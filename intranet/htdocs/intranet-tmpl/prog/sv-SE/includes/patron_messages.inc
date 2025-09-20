[% USE raw %]
[% USE Branches %]
[% USE Categories %]
[% SET ClaimReturnedWarningThreshold = Koha.Preference('ClaimReturnedWarningThreshold') %]
[% SET return_claims = patron.return_claims %]
[% SET logged_in_branchcode = Branches.GetLoggedInBranchcode() %]

[% IF ( has_modifications || warndeparture || returnbeforeexpiry || expired || patron.gonenoaddress || patron.lost || userdebarred || odues || ( return_claims.count > ClaimReturnedWarningThreshold ) || age_limitations || limited_category || charges || charges_guarantors_guarantees || charges_guarantees || credits || patron.account_locked ) %]
 <h3>Observera</h3>
 <ul>
 [% IF ( has_modifications ) %]
 <li class="has_modifications">
 <span class="circ-hlt">Väntande ändringar:</span>
 [% IF CAN_user_borrowers_edit_borrowers && ( !Koha.Preference('IndependentBranchesPatronModifications') || borrower.branch == branch ) %]
 <a href="/cgi-bin/koha/members/members-update.pl?active=[% patron.borrowernumber | uri %]">Granska väntande ändringar</a>
 [% ELSE %]
 <span>Låntagaren har väntande ändringar</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( warndeparture ) %]
 <li class="warndeparture">
 <span class="circ-hlt">Utgång:</span>
 <span>Låntagarens kort går ut den [% patron.dateexpiry | $KohaDates %].</span>
 [% IF ( moremember ) %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=member&amp;reregistration=y">Låna om</a> eller <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=member&amp;borrowernumber=[% patron.borrowernumber | uri %]">Redigera detaljer</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=circ&amp;reregistration=y">Låna om</a> eller <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | uri %]">Redigera detaljer</a>
 [% END %]
 </li>
 [% END %]

 [% IF ( returnbeforeexpiry ) %]
 <li class="returnbeforeexpiry">
 <span class="circ-hlt">Ställ in datum till utgångsdatum:</span> Inställningen ReturnBeforeExpiry är aktiverad, det innebär att om förfallodatumet är före återlämningsdatumet så ändras återlämningsdatumet till förfallodatumet </li>
 [% END %]

 [% IF ( expired ) %]
 <li class="expired">
 <span class="circ-hlt">Utgång:</span>
 <span>Låntagarens kort har gått ut.</span>
 [% IF ( expiry ) %]
 <span>Låntagarens kort gick ut den [% expiry | $KohaDates %]</span>
 [% END %]
 [% IF ( moremember ) %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=member&amp;reregistration=y">Låna om</a> eller <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=member&amp;borrowernumber=[% patron.borrowernumber | uri %]">Redigera detaljer</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=circ&amp;reregistration=y">Låna om</a> eller <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | uri %]">Redigera detaljer</a>
 [% END %]
 </li>
 [% END %]

 [% IF patron.account_locked %]
 <li class="blocker [% patron.login_attempts < 0 ? 'account_admin_locked' : 'account_locked' | html %]">
 [% IF patron.login_attempts < 0 %]
 <span class="circ-hlt">Locked: </span><span> Patron's account has been administratively locked</span>
 [% ELSE %]
 <span class="circ-hlt">Locked: </span><span> Patron's account has been locked (due to [% patron.login_attempts | html %] failed login attempts)</span>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers %]
 <span>
 <a href="/cgi-bin/koha/members/member-password.pl?member=[% patron.borrowernumber | uri %]">Byt lösenord</a>
 <span data-bs-toggle="tooltip" title="Resetting password will remove lock on account" data-bs-placement="right" class="fa fa-info-circle"> </span>
 </span>
 [% END %]
 </li>
 [% END %]

 [% IF ( patron.gonenoaddress ) %]
 <li class="gonenoaddress blocker">
 <span title="ogiltig adress-flagga är satt i låntagarposten"><span class="circ-hlt">Adress:</span> Låntagarens adress är möjligen ogiltig</span> <a class="btn btn-default btn-xs" href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3#memberentry_account_flags"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Redigera</a>
 </li>
 [% END %]

 [% IF ( patron.lost ) %]
 <li class="lost blocker">
 <span title="förlorad-flagga är satt i låntagarposten"><span class="circ-hlt">Förlorad: </span> Låntagarens kort har förlorats</span> <a class="btn btn-default btn-xs" href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3#memberentry_account_flags"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Redigera</a>
 </li>
 [% END %]

 [% IF ( userdebarred ) %]
 <li class="userdebarred blocker">
 <span class="circ-hlt"> Begränsad sedan [% debarredsince | $KohaDates %]:</span> Låntagarens konto är begränsat [% IF ( userdebarreddate ) %] till [% userdebarreddate | $KohaDates %] [% END %] [% IF ( debarredcomment ) %] med förklaringen: <br/>
 <em>
 [% IF debarredcomment.search('OVERDUES_PROCESS') %] Spärr lagd pga försenat material [% debarredcomment.remove('OVERDUES_PROCESS ') | $raw | html_line_break %] [% ELSE %] [% FOREACH restriction IN patron.restrictions %] <div class="[% restriction.type.code | lower | html %]_restriction">
 <span class="restriction_expiration">
 [% IF restriction.expiration %]
 [% restriction.expiration | $KohaDates %]
 [% ELSE %]
 <strong>Obestämd tid</strong>
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
 <a class="btn btn-xs btn-default" href="#reldebarments-tab" onclick="(new bootstrap.Tab($('#reldebarments-tab'))).show()"><i class="fa fa-ban"></i> Visa begränsningar</a>
 </li> <!-- /.blocker -->
 [% END # /IF userdebarred %]

 [% IF ( odues ) %]
 <li class="odues blocker">
 <span class="circ-hlt">Försenade:</span> Låntagaren har SENA LÅN <a href="#checkouts_panel" onclick="$('#issues-table-load-immediately').click(); $('#issues-table-load-immediately').click();">Se markerade exemplar nedan </a>
 </li>
 [% END %]

 [% IF return_claims.count > ClaimReturnedWarningThreshold %]
 <li class="return_claims blocker">
 <span class="circ-hlt return-claims">Påstås återlämnad:</span> Låntagaren har [% return_claims.count | html %] PÅSTÅS ÅTERLÄMNAD </li>
 [% END %]

 [% IF age_limitations %]
 <li class="invalid_age">
 <span class="circ-hlt">Låntagarens ålder är felaktig för kategorin.</span>
 Åldrar tillåtna är [% age_low | html %]-[% age_high | html %]. <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3" class="btn btn-default btn-xs">Ändra kategori</a>
 </li>
 [% END %]

 [% IF limited_category %]
 <li class="limited_category">
 <span class="circ-hlt">Låntagarens nuvarande kategori ([% Categories.GetName(patron.categorycode) | html %]) är begränsad för andra bibliotek.</span>
 <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3" class="btn btn-default btn-xs">Ändra kategori</a>
 </li>
 [% END %]

 [% IF ( charges ) %]
 [% INCLUDE 'blocked-fines.inc' NoIssuesCharge = chargesamount %]
 [% END %]

 [% IF ( charges_guarantors_guarantees ) %]
 <li class="charges_guarantors_guarantees">
 <span class="circ-hlt">Avgifter:</span> Låntagarens vårdnadshavare och de som de är vårdnadshavare till är tillsammans skyldiga [% charges_guarantors_guarantees | $Price %]. [% IF noissues %] <span class="circ-hlt">Utlån ej tillåtet på grund av för höga avgifter.</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( charges_guarantees ) %]
 <li class="charges_guarantees">
 <span class="circ-hlt">Avgifter:</span> De låntagaren är ansvarig för är tillsammans skyldiga [% chargesamount_guarantees | $Price %]. [% IF noissues %] <span class="circ-hlt">Utlån ej tillåtet på grund av för höga avgifter.</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( credits ) %]
 <li class="credits">
 <span class="circ-hlt">Krediter:</span> Låntagare har en kredit[% IF ( creditsamount ) %] på <span class="credit"><strong>[% creditsamount | $Price %]</strong></span>[% END %]
 </li>
 [% END %]
 [% IF (noissues && CAN_user_circulate_force_checkout && !moremember) %]
 <li>
 <span class="override_debarment">
 <a href="/cgi-bin/koha/circ/circulation.pl?forceallow=1&amp;borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-xs btn-default">Ignorera begränsning tillfälligt</a>
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
 <h4>Väntande återkrav här ([% waiting_here | html %])</h4>
 <ul>
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id == logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% w.biblio_id | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] by [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Återkrävd den [% w.created_date | $KohaDates %].</span>
 <br />
 <strong class="waitinghere">
 [% SET expires_on = w.expiration_date %] Väntar här [% IF expires_on %] t.o.m. [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]

 [% IF ( waiting_elsewhere > 0 ) %]
 <h4>Återkrav som väntar på andra bibliotek ([% waiting_elsewhere | html %])</h4>
 <ul>
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id != logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% w.biblio_id | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] by [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Återkrävd den [% w.created_date | $KohaDates %].</span>
 <br />
 <strong>
 [% SET expires_on = w.expiration_date %] Väntar på [% Branches.GetName( w.pickup_library_id ) | html %] [% IF expires_on %] tills [% expires_on | $KohaDates %] [% END %] </strong>
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
 <h4>Väntande reservationer: ([% waiting_here | html %])</h4>
 <ul>
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode == logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% w.biblio.biblionumber | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] by [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span class="holddate">Reservation lagd på [% w.reservedate | $KohaDates %].</span>
 <br />
 <strong class="waitinghere">
 [% SET expires_on = w.expirationdate %] Väntar här [% IF expires_on %] t.o.m. [% expires_on | $KohaDates %] [% END %]. </strong>
 <strong class="waitingsince">
 Väntar här sedan [% w.waitingdate | $KohaDates %]. </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]

 [% IF ( waiting_elsewhere > 0 ) %]
 <h4>Reservationer som väntar på andra bibliotek ([% waiting_elsewhere | html %])</h4>
 <ul>
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode != logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% w.biblio.biblionumber | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] by [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>Reservation lagd på [% w.reservedate | $KohaDates %].</span>
 <br />
 <strong>
 [% SET expires_on = w.expirationdate %] Väntar på [% w.branch.branchname | html %] [% IF expires_on %] tills [% expires_on | $KohaDates %] [% END %] </strong>
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
 <h4>Upphämtningar schemalagd här</h4>
 <ul>
 [% FOR cp IN curbside_pickups %]
 <li>Den: [% cp.scheduled_pickup_datetime | $KohaDates %] [% SWITCH cp.status %] [% CASE 'to-be-staged' %] <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=to-be-staged">
 Att hantera</a>
 [% CASE 'staged-and-ready' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=staged-and-ready">
 Hanterad och klar</a>
 [% CASE 'patron-is-outside' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=patron-is-outside">
 Låntagaren är på utsidan!</a>
 [% CASE 'delivered' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=delivered-today">
 Levererad</a>
 [% CASE %]<span>Okänd status "[% cp.status | html %]"</span>
 [% END %]
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
[% END %]

[% IF ( patron.borrowernotes ) %]
 <div id="circnotes" class="circmessage">
 <h4>Kommentarer</h4>
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
 <h4>Meddelanden</h4>
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
 [% IF patron_message.patron_read_date %] Läst: <em>[% patron_message.patron_read_date | $KohaDates %]</em>
 [% END %]
 </span>
 [% IF patron_message.branchcode == Branches.GetLoggedInBranchcode OR Koha.Preference('AllowAllMessageDeletion') %]
 [% IF moremember %]
 <a id="#edit_message_form_[% patron_message.message_id | html %]" class="btn btn-link edit_message" href="#edit_message_form_[% patron_message.message_id | uri %]" data-bs-target="#edit_message_form_[% patron_message.message_id | html %]" data-bs-toggle="modal"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Redigera</a>
 <form action="/cgi-bin/koha/circ/del_message.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete">
 <input type="hidden" name="message_id" value="[% patron_message.message_id | html %]">
 <input type="hidden" name="borrowernumber" value="[% patron_message.borrowernumber | html %]">
 <input type="hidden" name="from" value="moremember">
 <button type="submit" class="btn btn-link delete_message"><i class="fa fa-trash-can"></i> Ta bort</button>
 </form>
 [% ELSE %]
 <a id="#edit_message_form_[% patron_message.message_id | html %]" class="btn btn-link edit_message" href="#edit_message_form_[% patron_message.message_id | uri %]" data-bs-target="#edit_message_form_[% patron_message.message_id | html %]" data-bs-toggle="modal"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Redigera</a>
 <form action="/cgi-bin/koha/circ/del_message.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete">
 <input type="hidden" name="message_id" value="[% patron_message.message_id | html %]">
 <input type="hidden" name="borrowernumber" value="[% patron_message.borrowernumber | html %]">
 <button type="submit" class="btn btn-link delete_message"><i class="fa fa-trash-can"></i> Ta bort</button>
 </form>
 [% END %]
 [% END %]
 </li>
 [% END %]
 </ul>
 <a id="addnewmessageLabel" data-bs-target="#add_message_form" class="btn btn-link" data-bs-toggle="modal"><i class="fa fa-plus"></i> Lägg till ett nytt meddelande</a>
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
 <h1 class="modal-title">Redigera meddelande</h1>
 </div>
 <div class="modal-body">
 <div class="form-group">
 <label for="edit_message_type">
 Meddelande gäller: <select name="message_type" id="edit_message_type" disabled>
 [% IF pm.message_type == "L" %]
 <option value="L" selected="selected">Personal - Intern kommentar</option>
 [% ELSE %]
 <option value="L">Personal - Intern kommentar</option>
 [% END %]

 [% IF pm.message_type == "B" %]
 <option value="B" selected="selected">OPAC - [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% ELSE %]
 <option value="B">OPAC - [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% END %]
 </select>
 </label>
 </div>
 <div class="form-group">
 <textarea rows="3" class="modal-textarea" name="borrower_message" id="edit_borrower_message" >[% pm.message | html %]</textarea>
 </div>
 </div>
 <div class="modal-footer">
 <button class="btn btn-default approve" type="submit"><i class="fa fa-check"></i> Spara</button>
 <button class="btn btn-default deny cancel" type="button" data-bs-dismiss="modal"><i class="fa fa-times"></i> Avbryt</button>
 </div>
 </form>
 </div>
 </div>
 </div>
 [% END %]
[% END # /IF patron_messages %]
