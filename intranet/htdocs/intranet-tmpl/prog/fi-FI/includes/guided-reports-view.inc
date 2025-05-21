[% USE Koha %]
<div id="navmenu">
<div id="navmenulist">

<h5>Aja raportteja</h5>
<ul>
 [% IF ( CAN_user_reports_execute_reports ) %]<li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=list">Tallennetut raportit</a></li>[% END %]
</ul>
<h5>Raporttisanasto</h5>
<ul>
<li><a href="/cgi-bin/koha/reports/dictionary.pl">Katso sanastoa</a></li>
</ul>
<h5>Muut tiedot</h5>
<ul>
<li><a href="http://wiki.koha-community.org/wiki/SQL_Reports_Library" target="blank">Kohan raporttikirjasto</a></li>
[% SET koha_version = Koha.Version %]
[% IF koha_version.development %]
 <li><a href="http://schema.koha-community.org/main" target="blank">Kohan tietokantarakenne</a></li>
[% ELSE %]
 <li><a href="http://schema.koha-community.org/[% koha_version.major | uri %]_[% koha_version.minor | uri %]" target="blank">Kohan tietokantarakenne</a></li>
[% END %]
</ul>
</div>
</div>
