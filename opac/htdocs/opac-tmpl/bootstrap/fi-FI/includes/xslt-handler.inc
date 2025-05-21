[% SWITCH code %]
 [% CASE 'XSLTH_ERR_NO_FILE' %]
 <span>Ei yhtään läpäissyttä XSLT-tiedostoa.</span>
 [% CASE 'XSLTH_ERR_FILE_NOT_FOUND' %]
 <span>XSLT tiedostoa ei löytynyt.</span>
 [% CASE 'XSLTH_ERR_LOADING' %]
 <span>Virhe ladattaessa tyylitiedostoa.</span>
 [% CASE 'XSLTH_ERR_PARSING_CODE' %]
 <span>Virhe jäsennettäessä tyylitiedostoa.</span>
 [% CASE 'XSLTH_ERR_PARSING_DATA' %]
 <span>Virhe jäsennettäessä syötettä.</span>
 [% CASE 'XSLTH_ERR_TRANSFORMING' %]
 <span>Virhe muunnettaessa syötettä.</span>
 [% CASE 'XSLTH_NO_STRING_PASSED' %]
 <span>Ei muunnettavaa merkkijonoa.</span>
[% END %]
