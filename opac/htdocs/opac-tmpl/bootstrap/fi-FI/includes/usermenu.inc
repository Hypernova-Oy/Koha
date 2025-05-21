[% USE Koha %]
[% USE KohaPlugins %]
[% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && loggedinusername ) %]
 <div id="menu">
 <ul>
 [% IF ( userview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-user.pl">Yhteenveto</a></li>
 [% IF ( OPACFinesTab ) %]
 [% IF ( accountview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-account.pl">Maksut</a></li>
 [% END %]

 [% IF ( userupdateview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-memberentry.pl">Käyttäjätiedot</a></li>

 [% IF Koha.Preference('PrivacyPolicyConsent') || KohaPlugins.feature_enabled('patron_consent_type') %]
 [% IF consentview %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/opac-patron-consent.pl">Suostumukset</a>
 </li>
 [% END %]

 [% IF Koha.Preference( 'TagsEnabled' ) == 1 %]
 [% IF ( tagsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-tags.pl?mine=1">Tagit</a></li>
 [% END %]

 [% IF logged_in_user.category.effective_change_password %]
 [% IF ( passwdview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-passwd.pl">Vaihda salasana</a></li>
 [% END %]

 [% IF EnableOpacSearchHistory %]
 [% IF ( searchhistoryview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-search-history.pl">Hakuhistoria</a></li>
 [% END %]

 [% IF ( opacreadinghistory ) %]
 [% IF ( readingrecview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-readingrecord.pl">Lainahistoria</a></li>
 [% IF ( OPACPrivacy ) %]
 [% IF ( privacyview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-privacy.pl">Yksityisyys</a></li>
 [% END %]
 [% END # / opacreadinghistory %]

 [% IF Koha.Preference('OPACHoldsHistory') == 1 %]
 [% IF ( holdshistoryview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-holdshistory.pl">Varaushistoria</a></li>
 [% END %]

 [% IF Koha.Preference('UseRecalls') %]
 [% IF ( recallsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-recalls.pl">Palautuspyyntöhistoria</a>
 [% END %]

 [% IF ( suggestion ) %]
 [% IF ( suggestionsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-suggestions.pl">Hankintaehdotukset</a></li>
 [% END %]

 [% IF ( EnhancedMessagingPreferences ) %]
 [% IF Koha.Preference( 'EnhancedMessagingPreferencesOPAC' ) || Koha.Preference('TranslateNotices') %]
 [% IF ( messagingview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-messaging.pl">Viestitys</a></li>
 [% END %]
 [% END %]

 [% IF Koha.Preference( 'virtualshelves' ) == 1 %]
 [% IF ( listsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-shelves.pl?op=list">Listat</a></li>
 [% END %]

 [% IF Koha.Preference( 'RoutingSerials' ) && logged_in_user && logged_in_user.get_routing_lists.count %]
 [% IF ( routinglistsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-routing-lists.pl">Kiertolistat</a></li>
 [% END %]

 [% IF Koha.Preference( 'useDischarge' ) == 1 %]
 [% IF ( dischargeview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-discharge.pl">Pyydä vapautusta</a></li>
 [% END %]

 [% IF Koha.Preference( 'ILLModule' ) == 1 %]
 [% IF ( illrequestsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-illrequests.pl">Kaukolainapyynnöt</a></li>
 [% END %]

 [% IF Koha.Preference( 'CurbsidePickup' ) %]
 [% IF ( curbside_pickups_view ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-curbside-pickups.pl">Noutopalvelu</a></li>
 [% END %]

 [% IF logged_in_user.alert_subscriptions.count %]
 [% IF ( alertsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-alert-subscriptions.pl">Kausijulkaisutilausten saapumisilmoitukset ([% logged_in_user.alert_subscriptions.count | html %])</a></li>
 [% END %]

 [% IF Koha.Preference( 'OPACVirtualCard' ) %]
 [% IF ( virtualcardview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-virtual-card.pl">Sähköinen kirjastokortti</a></li>
 [% END %]
 </ul>
 </div>
[% END %]
