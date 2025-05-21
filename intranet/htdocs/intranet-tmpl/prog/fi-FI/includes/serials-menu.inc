<div id="navmenu">
 <div id="navmenulist">
 <h5>Kausijulkaisut</h5>
 <ul>
 [% IF ( subscriptionid ) %]
 <li><a href="/cgi-bin/koha/serials/serials-collection.pl?subscriptionid=[% subscriptionid | uri %]">Kausijulkaisukokoelma</a></li>
 [% UNLESS closed %]
 [% IF ( routing && CAN_user_serials_routing ) %]
 [% IF ( hasRouting ) %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]">Muokkaa kiertolistaa</a></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]&amp;op=new">Luo kiertolista</a></li>
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF ( CAN_user_serials_claim_serials ) %]
 <li><a href="/cgi-bin/koha/serials/claims.pl">Reklamaatiot</a></li>
 [% END %]
 [% IF ( CAN_user_serials_check_expiration ) %]
 <li><a href="/cgi-bin/koha/serials/checkexpiration.pl">Tarkista lehtitilauksen päättyminen</a></li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/serials/subscription-frequencies.pl">
 Ilmestymistiheys </a>
 </li>
 <li>
 <a href="/cgi-bin/koha/serials/subscription-numberpatterns.pl">
 Numerointikaavat </a>
 </li>
 [% IF Koha.Preference('Mana') == 1 %]
 <li><a href="/cgi-bin/koha/serials/serials-search.pl?mana=1">Hae Manasta</a></li>
 [% END %]
 [% IF CAN_user_serials_edit_subscription && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=subscription">Hallinnoi kausijulkaisutilausten kenttiä</a>
 </li>
 [% END %]
 </ul>

 [% IF ( CAN_user_reports ) %]
 <h5>Raportit</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">Kausijulkaisujen tilastovelho</a></li>
 </ul>
 [% END %]

 </div>
</div>
