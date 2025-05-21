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
 <a href="/cgi-bin/koha/opac-user.pl">Sammanfattning</a></li>
 [% IF ( OPACFinesTab ) %]
 [% IF ( accountview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-account.pl">Avgifter</a></li>
 [% END %]

 [% IF ( userupdateview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-memberentry.pl">Dina personuppgifter</a></li>

 [% IF Koha.Preference('PrivacyPolicyConsent') || KohaPlugins.feature_enabled('patron_consent_type') %]
 [% IF consentview %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/opac-patron-consent.pl">Samtycker</a>
 </li>
 [% END %]

 [% IF Koha.Preference( 'TagsEnabled' ) == 1 %]
 [% IF ( tagsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-tags.pl?mine=1">Taggar</a></li>
 [% END %]

 [% IF logged_in_user.category.effective_change_password %]
 [% IF ( passwdview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-passwd.pl">Byt lösenord</a></li>
 [% END %]

 [% IF EnableOpacSearchHistory %]
 [% IF ( searchhistoryview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-search-history.pl">Sökhistorik</a></li>
 [% END %]

 [% IF ( opacreadinghistory ) %]
 [% IF ( readingrecview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-readingrecord.pl">Utlåningshistorik</a></li>
 [% IF ( OPACPrivacy ) %]
 [% IF ( privacyview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-privacy.pl">Integritet</a></li>
 [% END %]
 [% END # / opacreadinghistory %]

 [% IF Koha.Preference('OPACHoldsHistory') == 1 %]
 [% IF ( holdshistoryview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-holdshistory.pl">Reservationshistorik</a></li>
 [% END %]

 [% IF Koha.Preference('UseRecalls') %]
 [% IF ( recallsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-recalls.pl">Historik över återkrav</a>
 [% END %]

 [% IF ( suggestion ) %]
 [% IF ( suggestionsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-suggestions.pl">Inköpsförslag</a></li>
 [% END %]

 [% IF ( EnhancedMessagingPreferences ) %]
 [% IF Koha.Preference( 'EnhancedMessagingPreferencesOPAC' ) || Koha.Preference('TranslateNotices') %]
 [% IF ( messagingview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-messaging.pl">Meddelanden</a></li>
 [% END %]
 [% END %]

 [% IF Koha.Preference( 'virtualshelves' ) == 1 %]
 [% IF ( listsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-shelves.pl?op=list">Listor</a></li>
 [% END %]

 [% IF Koha.Preference( 'RoutingSerials' ) && logged_in_user && logged_in_user.get_routing_lists.count %]
 [% IF ( routinglistsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-routing-lists.pl">Mottagarlistor</a></li>
 [% END %]

 [% IF Koha.Preference( 'useDischarge' ) == 1 %]
 [% IF ( dischargeview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-discharge.pl">Begär borttagning</a></li>
 [% END %]

 [% IF Koha.Preference( 'ILLModule' ) == 1 %]
 [% IF ( illrequestsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-illrequests.pl">Fjärrlånebeställningar</a></li>
 [% END %]

 [% IF Koha.Preference( 'CurbsidePickup' ) %]
 [% IF ( curbside_pickups_view ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-curbside-pickups.pl">Upphämtningar</a></li>
 [% END %]

 [% IF logged_in_user.alert_subscriptions.count %]
 [% IF ( alertsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-alert-subscriptions.pl">Notifieringar ([% logged_in_user.alert_subscriptions.count | html %])</a></li>
 [% END %]

 [% IF Koha.Preference( 'OPACVirtualCard' ) %]
 [% IF ( virtualcardview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-virtual-card.pl">Mitt virtuella kort</a></li>
 [% END %]
 </ul>
 </div>
[% END %]
