<div id="navmenu">
 <div id="navmenulist">
 <h5>Periodika</h5>
 <ul>
 [% IF ( subscriptionid ) %]
 <li><a href="/cgi-bin/koha/serials/serials-collection.pl?subscriptionid=[% subscriptionid | uri %]">Periodikasamling</a></li>
 [% UNLESS closed %]
 [% IF ( routing && CAN_user_serials_routing ) %]
 [% IF ( hasRouting ) %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]">Redigera mottagarlista</a></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]&amp;op=new">Skapa mottagarlista</a></li>
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF ( CAN_user_serials_claim_serials ) %]
 <li><a href="/cgi-bin/koha/serials/claims.pl">Reklamationer</a></li>
 [% END %]
 [% IF ( CAN_user_serials_check_expiration ) %]
 <li><a href="/cgi-bin/koha/serials/checkexpiration.pl">Kontrollera utgångsdatum</a></li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/serials/subscription-frequencies.pl">
 Hantera frekvenser </a>
 </li>
 <li>
 <a href="/cgi-bin/koha/serials/subscription-numberpatterns.pl">
 Hantera numreringsmönster </a>
 </li>
 [% IF Koha.Preference('Mana') == 1 %]
 <li><a href="/cgi-bin/koha/serials/serials-search.pl?mana=1">Sök i Mana</a></li>
 [% END %]
 [% IF CAN_user_serials_edit_subscription && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=subscription">Hantera prenumerationsfält</a>
 </li>
 [% END %]
 </ul>

 [% IF ( CAN_user_reports ) %]
 <h5>Rapporter</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">Periodikastatistik</a></li>
 </ul>
 [% END %]

 </div>
</div>
