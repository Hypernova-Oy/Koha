[% USE HtmlId %]
<div id="menu">
 <ul>
 [% IF ( accounting ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=accounting" title="Avgifter">Avgifter</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=accounting" title="Avgifter">Avgifter</a>
 [% END %]
 [% IF ( acquisitions ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="Inköp">Inköp</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="Inköp">Inköp</a>
 [% END %]
 </li>

 [% IF ( admin ) %]
 <li class="active">
 <a title="Administration" href="/cgi-bin/koha/admin/preferences.pl?tab=admin">Administration</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a title="Administration" href="/cgi-bin/koha/admin/preferences.pl?tab=admin">Administration</a>
 [% END %]
 </li>

 [% IF ( authorities ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=authorities" title="Auktoritetsstyrning">Auktoriteter</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=authorities" title="Auktoritetsstyrning">Auktoriteter</a>
 [% END %]
 </li>

 [% IF ( cataloguing ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing" title="Katalogisering">Katalogisering</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing" title="Katalogisering">Katalogisering</a>
 [% END %]
 </li>

 [% IF ( circulation ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="Cirkulation">Cirkulation</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="Cirkulation">Cirkulation</a>
 [% END %]
 </li>

 [% IF ( enhanced_content ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="Inställningar för utökat innehåll">Utökat innehåll</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="Inställningar för utökat innehåll">Utökat innehåll</a>
 [% END %]
 </li>

 [% IF ( erm ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=erm" title="E-resurshantering">E-resurshantering</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=erm" title="E-resurshantering">E-resurshantering</a>
 [% END %]
 </li>

 [% IF ( i18n_l10n ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="Internationalisering och lokalisering">I18N/L10N</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="Internationalisering och lokalisering">I18N/L10N</a>
 [% END %]
 </li>

 [% IF ( interlibrary_loans ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans" title="Fjärrlån">Fjärrlån</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans" title="Fjärrlån">Fjärrlån</a>
 [% END %]
 </li>

 [% IF ( local_use ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/systempreferences.pl">Lokal användning</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/systempreferences.pl">Lokal användning</a>
 [% END %]
 </li>

 [% IF ( logs ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="Transaktionsloggar">Loggar</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="Transaktionsloggar">Loggar</a>
 [% END %]
 </li>

 [% IF ( opac ) %]
 <li class="active">
 <a title="Online Public Access Catalog" href="/cgi-bin/koha/admin/preferences.pl?tab=opac">OPAC</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a title="Online Public Access Catalog" href="/cgi-bin/koha/admin/preferences.pl?tab=opac">OPAC</a>
 [% END %]
 </li>

 [% IF ( patrons ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="Låntagare">Låntagare</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="Låntagare">Låntagare</a>
 [% END %]
 </li>

 [% IF ( preservation ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=preservation" title="Bokvård">Bokvård</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=preservation" title="Bokvård">Bokvård</a>
 [% END %]
 </li>

 [% IF ( searching ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="Sökning">Sökning</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="Sökning">Sökning</a>
 [% END %]
 </li>

 [% IF ( serials ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="Periodika">Periodika</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="Periodika">Periodika</a>
 [% END %]
 </li>

 [% IF ( staff_interface ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface" title="Personalgränssnitt">Personalgränssnitt</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface" title="Personalgränssnitt">Personalgränssnitt</a>
 [% END %]
 </li>

 [% IF ( tools ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="Verktyg">Verktyg</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="Verktyg">Verktyg</a>
 [% END %]
 </li>

 [% IF ( web_services ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=web_services" title="Webbtjänster">Webbtjänster</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=web_services" title="Webbtjänster">Webbtjänster</a>
 [% END %]
 </li>
 </ul>
</div>

[% BLOCK subtabs %]
 [% UNLESS ( searchfield ) %]
 [% FOREACH TAB IN TABS %]
 <ul>
 [% FOREACH LINE IN TAB.LINES %]
 [% IF ( LINE.is_group_title ) %]
 <li><a class="pref_sublink" href="#[% TAB.tab_id | html %]_[% LINE.title | $HtmlId %]">[% LINE.title | html %]</a></li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 [% END %]
[% END %]
