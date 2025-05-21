[% SWITCH Koha.Preference('CSVDelimiter') %]
 [% CASE '#' %]<span>#-merkillä erotettua tekstiä (.csv)</span>
 [% CASE ',' %]<span>Pilkulla erotettua tekstiä (.csv)</span>
 [% CASE '/' %]<span>Kauttaviivoin eroteltu teksti (.csv)</span>
 [% CASE ';' %]<span>Puolipisteellä erotettua tekstiä (.csv)</span>
 [% CASE '\\' %]<span>Kenoviivoin eroteltu teksti (.csv)</span>
 [% CASE 'tabulation' %]<span>Tabulaattorein eroteltu teksti (.csv)</span>
[% END %]
