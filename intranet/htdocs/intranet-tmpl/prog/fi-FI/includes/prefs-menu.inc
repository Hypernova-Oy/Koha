[% USE HtmlId %]
<div id="menu">
 <ul>
 [% IF ( accounting ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=accounting" title="Maksut">Maksut</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=accounting" title="Maksut">Maksut</a>
 [% END %]
 [% IF ( acquisitions ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="Hankinnat">Hankinnat</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="Hankinnat">Hankinnat</a>
 [% END %]
 </li>

 [% IF ( admin ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=admin" title="Ylläpito">Ylläpito</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=admin" title="Ylläpito">Ylläpito</a>
 [% END %]
 </li>

 [% IF ( authorities ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=authorities" title="Auktoriteettien hallinta">Auktoriteetit</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=authorities" title="Auktoriteettien hallinta">Auktoriteetit</a>
 [% END %]
 </li>

 [% IF ( cataloguing ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing" title="Kuvailu">Kuvailu</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing" title="Kuvailu">Kuvailu</a>
 [% END %]
 </li>

 [% IF ( circulation ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="Lainaus ja palautus">Lainaus ja palautus</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="Lainaus ja palautus">Lainaus ja palautus</a>
 [% END %]
 </li>

 [% IF ( enhanced_content ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="Muun sisällön asetukset">Sisältölaajennukset</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="Muun sisällön asetukset">Sisältölaajennukset</a>
 [% END %]
 </li>

 [% IF ( erm ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=erm" title="Elektronisten aineistojen hallinta">Elektronisten aineistojen hallinta</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=erm" title="Elektronisten aineistojen hallinta">Elektronisten aineistojen hallinta</a>
 [% END %]
 </li>

 [% IF ( i18n_l10n ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="Kansainvälisyys ja lokalisointi">I18N/L10N</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="Kansainvälisyys ja lokalisointi">I18N/L10N</a>
 [% END %]
 </li>

 [% IF ( interlibrary_loans ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans" title="Kaukolainat">Kaukolainat</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans" title="Kaukolainat">Kaukolainat</a>
 [% END %]
 </li>

 [% IF ( local_use ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/systempreferences.pl">Paikalliset tiedot</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/systempreferences.pl">Paikalliset tiedot</a>
 [% END %]
 </li>

 [% IF ( logs ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="Tapahtumaloki">Lokitiedostot</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="Tapahtumaloki">Lokitiedostot</a>
 [% END %]
 </li>

 [% IF ( opac ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=opac" title="Verkkokirjasto">OPAC</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=opac" title="Verkkokirjasto">OPAC</a>
 [% END %]
 </li>

 [% IF ( patrons ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="Asiakkaat">Asiakkaat</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="Asiakkaat">Asiakkaat</a>
 [% END %]
 </li>

 [% IF ( preservation ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=preservation" title="Käsittelyerät">Käsittelyerät</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=preservation" title="Käsittelyerät">Käsittelyerät</a>
 [% END %]
 </li>

 [% IF ( searching ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="Haku">Haku</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="Haku">Haku</a>
 [% END %]
 </li>

 [% IF ( serials ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="Kausijulkaisut">Kausijulkaisut</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="Kausijulkaisut">Kausijulkaisut</a>
 [% END %]
 </li>

 [% IF ( staff_interface ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface" title="Virkailijaliittymä">Virkailijaliittymä</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface" title="Virkailijaliittymä">Virkailijaliittymä</a>
 [% END %]
 </li>

 [% IF ( tools ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="Työkalut">Työkalut</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="Työkalut">Työkalut</a>
 [% END %]
 </li>

 [% IF ( web_services ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=web_services" title="Verkkopalvelut">Verkkopalvelut</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=web_services" title="Verkkopalvelut">Verkkopalvelut</a>
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
