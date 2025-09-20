<!-- circ-nav.inc -->
[% USE Koha %]
[% USE Branches %]
<div id="navmenu">
 <div id="navmenulist">
 <div class="row">
 <div class="col-sm-6 col-md-12">
 <h5>Lainaus ja palautus</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/circulation.pl">Lainaus</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/returns.pl">Palautus</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/renew.pl">Uusinta</a>
 </li>
 [% IF ( CAN_user_superlibrarian || CAN_user_loggedinlibrary ) %]
 <li>
 [% IF Koha.Preference('UseCirculationDesks') %]
 <a href="/cgi-bin/koha/circ/set-library.pl">Aseta kirjasto ja tiski</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/circ/set-library.pl">Aseta kirjasto</a>
 [% END %]
 </li>
 [% ELSIF Koha.Preference('UseCirculationDesks') %]
 <li>
 <a href="/cgi-bin/koha/circ/set-library.pl">Aseta tiski</a>
 </li>
 [% END %]
 [% IF ( fast_cataloging && CAN_user_editcatalogue_fast_cataloging ) %]
 <li>
 <a href="/cgi-bin/koha/cataloguing/addbiblio.pl?frameworkcode=FA"> Pikakuvailu</a>
 </li>
 [% END %]
 [% IF ( Koha.Preference('AllowCheckoutNotes') && CAN_user_circulate_manage_checkout_notes ) %]
 <li>
 <a href="/cgi-bin/koha/circ/checkout-notes.pl">Lainahuomautukset</a>
 </li>
 [% END %]
 [% IF Koha.Preference('OnSiteCheckouts') %]
 <li>
 <a href="/cgi-bin/koha/circ/on-site_checkouts.pl">Odottavat on-site -lainat</a>
 </li>
 [% END %]
 </ul>

 <h5>Varaukset</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/view_holdsqueue.pl">Varausjono</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/pendingreserves.pl">Hyllyvaraukset</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/waitingreserves.pl">Noudettavissa olevat varaukset</a>
 </li>
 [% IF ( Koha.Preference('CurbsidePickup') && CAN_user_circulate_manage_curbside_pickups ) %]
 <li>
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl">Noutopalvelu</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/reserveratios.pl">Varauksia per nide</a>
 </li>
 </ul>
 </div>


 <div class="col-sm-6 col-md-12">
 [% IF Koha.Preference('UseRecalls') and CAN_user_recalls %]
 <h5>Palautuspyynnöt</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_queue.pl" title="Kaikki aktiiviset palautuspyynnöt">Palautuspyyntöjono</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_to_pull.pl" title="Palautuspyynnöt, jotka voitaisiin täyttää, mutta ei ole asetettu odottamaan">Palautuspyynnöt</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_overdue.pl" title="Myöhässä olevat niteet, joihin on palautuspyyntö">Myöhässä olevat palautuspyynnöt</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_waiting.pl" title="Noudettavissa olevat palautuspyynnöt">Noudettavissa olevat palautuspyynnöt</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_old_queue.pl" title="Ei voimassa olevat palautuspyynnöt">Vanhat palautuspyynnöt</a>
 </li>
 </ul>
 [% END %]

 [% IF Koha.Preference('ArticleRequests') %]
 <h5>Asiakkaan pyyntö</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/article-requests.pl">Artikkelipyynnöt</a>
 </li>
 </ul>
 [% END %]

 <h5>Kuljetukset ja siirrot</h5>
 <ul>
 [% IF !Koha.Preference('IndependentBranchesTransfers') || CAN_user_superlibrarian %]
 <li>
 <a href="/cgi-bin/koha/circ/branchtransfers.pl">Siirrä</a>
 </li>
 [% END %]
 [% IF Koha.Preference('StockRotation') %]
 <li>
 <a href="/cgi-bin/koha/circ/transfers_to_send.pl">Lähetettävät kuljetukset</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/transferstoreceive.pl">Vastaanotettavat kuljetukset</a>
 </li>
 </ul>

 [% IF ( CAN_user_circulate_overdues_report ) %]
 <h5>Myöhässä olevat</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/overdue.pl" title="Varoitus: Tämä raportti vaatii paljon järjestelmäresursseja, jos tietokannassa on paljon myöhässä olevia lainoja.">Myöhässä olevat</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/branchoverdues.pl" title="Rajattu omaan kirjastoosi. Katso raportin ohjeista lisätietoja.">Myöhässä ja maksuja</a>
 </li>
 </ul>
 [% END %]
 </div>
 </div>
 </div>
</div>
<!-- /circ-nav.inc -->
