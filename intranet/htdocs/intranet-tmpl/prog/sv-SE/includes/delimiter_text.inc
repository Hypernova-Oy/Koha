[% SWITCH Koha.Preference('CSVDelimiter') %]
 [% CASE '#' %]<span>Text separerad med nummertecknet # (.csv)</span>
 [% CASE ',' %]<span>Kommaseparerad text (.csv)</span>
 [% CASE '/' %]<span>Text separerad av snedstreck (.csv)</span>
 [% CASE ';' %]<span>Semikolonseparerad text (.csv)</span>
 [% CASE '\\' %]<span>Text separerad med omvänt snedstreck (.csv)</span>
 [% CASE 'tabulation' %]<span>Tabbseparerad text (.csv)</span>
[% END %]
