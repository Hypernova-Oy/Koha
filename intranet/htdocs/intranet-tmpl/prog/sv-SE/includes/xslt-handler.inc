[% SWITCH code %]
 [% CASE 'XSLTH_ERR_NO_FILE' %]
 <span>Ingen XSLT-fil angiven.</span>
 [% CASE 'XSLTH_ERR_FILE_NOT_FOUND' %]
 <span>XSLT-filen hittades inte.</span>
 [% CASE 'XSLTH_ERR_LOADING' %]
 <span>Fel vid laddning av formatmall.</span>
 [% CASE 'XSLTH_ERR_PARSING_CODE' %]
 <span>Fel vid parsning av formatmall.</span>
 [% CASE 'XSLTH_ERR_PARSING_DATA' %]
 <span>Fel vid parsning av indata.</span>
 [% CASE 'XSLTH_ERR_TRANSFORMING' %]
 <span>Fel vid transformering av indata.</span>
 [% CASE 'XSLTH_NO_STRING_PASSED' %]
 <span>Ingen sträng att transformera.</span>
[% END %]
