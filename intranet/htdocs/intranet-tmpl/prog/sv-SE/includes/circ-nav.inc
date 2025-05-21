<!-- circ-nav.inc -->
[% USE Koha %]
[% USE Branches %]
<div id="navmenu">
 <div id="navmenulist">
 <div class="row">
 <div class="col-sm-6 col-md-12">
 <h5>Cirkulation</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/circulation.pl">Låna ut</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/returns.pl">Återlämna</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/renew.pl">Låna om</a>
 </li>
 [% IF ( CAN_user_superlibrarian || CAN_user_loggedinlibrary ) %]
 <li>
 [% IF Koha.Preference('UseCirculationDesks') %]
 <a href="/cgi-bin/koha/circ/set-library.pl">Ange bibliotek och informationsdisk</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/circ/set-library.pl">Ange bibliotek</a>
 [% END %]
 </li>
 [% ELSIF Koha.Preference('UseCirculationDesks') %]
 <li>
 <a href="/cgi-bin/koha/circ/set-library.pl">Ställ in informationsdisk</a>
 </li>
 [% END %]
 [% IF ( fast_cataloging && CAN_user_editcatalogue_fast_cataloging ) %]
 <li>
 <a href="/cgi-bin/koha/cataloguing/addbiblio.pl?frameworkcode=FA"> Snabb katalogisering</a>
 </li>
 [% END %]
 [% IF ( Koha.Preference('AllowCheckoutNotes') && CAN_user_circulate_manage_checkout_notes ) %]
 <li>
 <a href="/cgi-bin/koha/circ/checkout-notes.pl">Utlåningsmeddelanden</a>
 </li>
 [% END %]
 [% IF Koha.Preference('OnSiteCheckouts') %]
 <li>
 <a href="/cgi-bin/koha/circ/on-site_checkouts.pl">Pågående utlån på plats</a>
 </li>
 [% END %]
 </ul>

 <h5>Reservationer</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/view_holdsqueue.pl">Reservationskö</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/pendingreserves.pl">Plocklista reservationer</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/waitingreserves.pl">Reservationer som väntar på hämtning</a>
 </li>
 [% IF ( Koha.Preference('CurbsidePickup') && CAN_user_circulate_manage_curbside_pickups ) %]
 <li>
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl">Upphämtningar</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/reserveratios.pl">Reservationsförhållanden</a>
 </li>
 </ul>
 </div>


 <div class="col-sm-6 col-md-12">
 [% IF Koha.Preference('UseRecalls') and CAN_user_recalls %]
 <h5>Återkrav</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_queue.pl" title="Alla aktiva återkrav">Återkravskö</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_to_pull.pl" title="Återkrav som kan uppfyllas (plocklista)">Plocklista återkrav</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_overdue.pl" title="Återkrävda exemplar som är försenade">Försenade återkrav</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_waiting.pl" title="Återkrävda exemplar väntar på hämtning">Återkrav väntar på hämtning</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_old_queue.pl" title="Inaktiva återkrav">Gamla återkrav</a>
 </li>
 </ul>
 [% END %]

 [% IF Koha.Preference('ArticleRequests') %]
 <h5>Låntagarbegäran</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/article-requests.pl">Artikelbeställningar</a>
 </li>
 </ul>
 [% END %]

 <h5>Överföringar</h5>
 <ul>
 [% IF !Koha.Preference('IndependentBranchesTransfers') || CAN_user_superlibrarian %]
 <li>
 <a href="/cgi-bin/koha/circ/branchtransfers.pl">Överför</a>
 </li>
 [% END %]
 [% IF Koha.Preference('StockRotation') %]
 <li>
 <a href="/cgi-bin/koha/circ/transfers_to_send.pl">Överföringar att skicka</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/transferstoreceive.pl">Överföringar att ta emot</a>
 </li>
 </ul>

 [% IF ( CAN_user_circulate_overdues_report ) %]
 <h5>Försenade</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/overdue.pl" title="Varning: Denna rapport är mycket resurskrävande i system med ett stort antal försenade exemplar.">Försenade</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/branchoverdues.pl" title="Begränsat till ditt bibliotek. Se rapporthjälp för mer information.">Försenade med avgifter</a>
 </li>
 </ul>
 [% END %]
 </div>
 </div>
 </div>
</div>
<!-- /circ-nav.inc -->
