[%- BLOCK subtype_dropdowns -%]
 <select name="limit" class="subtype">
 [% IF ( limits.aud.size ) %]
 <option value="" class="menuheader">Alla målgrupper</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Alla målgrupper</option>
 [% END %]
 [% IF (limits.aud.0 == 'a' ) %]
 <option selected="selected" value="aud:a">Förskola</option>
 [% ELSE %]
 <option value="aud:a">Förskola</option>
 [% END %]
 [% IF (limits.aud.0 == 'b' ) %]
 <option value="aud:b" selected="selected">Primär</option>
 [% ELSE %]
 <option value="aud:b">Primär</option>
 [% END %]
 [% IF (limits.aud.0 == 'c' ) %]
 <option value="aud:c" selected="selected">Barn och ungdom</option>
 [% ELSE %]
 <option value="aud:c">Barn och ungdom</option>
 [% END %]
 [% IF (limits.aud.0 == 'd' ) %]
 <option value="aud:d" selected="selected">Ungdom</option>
 [% ELSE %]
 <option value="aud:d">Ungdom</option>
 [% END %]
 [% IF (limits.aud.0 == 'e' ) %]
 <option value="aud:e" selected="selected">Vuxen</option>
 [% ELSE %]
 <option value="aud:e">Vuxen</option>
 [% END %]
 [% IF (limits.aud.0 == 'f' ) %]
 <option value="aud:f" selected="selected">Specialiserad</option>
 [% ELSE %]
 <option value="aud:f">Specialiserad</option>
 [% END %]
 [% IF (limits.aud.0 == 'g' ) %]
 <option value="aud:g" selected="selected">Allmänt</option>
 [% ELSE %]
 <option value="aud:g">Allmänt</option>
 [% END %]
 [% IF (limits.aud.0 == 'j' ) %]
 <option value="aud:j" selected="selected">Ungdom</option>
 [% ELSE %]
 <option value="aud:j">Ungdom</option>
 [% END %]
 [% limits.delete( 'aud' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.fic.size OR limits.bio.size OR limits.mus.size ) %]
 <option value="" class="menuheader">Alla innehåll</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Alla innehåll</option>
 [% END %]
 [% IF (limits.fic.0 == '1' ) %]
 <option value="fic:1" selected="selected" >Skönlitteratur</option>
 [% ELSE %]
 <option value="fic:1" >Skönlitteratur</option>
 [% END %]
 [% IF (limits.fic.0 == '0' ) %]
 <option value="fic:0" selected="selected" >Ej fiktion</option>
 [% ELSE %]
 <option value="fic:0" >Ej fiktion</option>
 [% END %]
 [% IF (limits.bio.0 == 'b' ) %]
 <option value="bio:b" selected="selected" >Biografi</option>
 [% ELSE %]
 <option value="bio:b" >Biografi</option>
 [% END %]
 [% IF (limits.mus.0 == 'j' ) %]
 <option value="mus:j" selected="selected" >Musikinspelning</option>
 [% ELSE %]
 <option value="mus:j" >Musikinspelning</option>
 [% END %]
 [% IF (limits.mus.0 == 'i' ) %]
 <option value="mus:i" selected="selected" >Ej musikalisk inspelning</option>
 [% ELSE %]
 <option value="mus:i" >Ej musikalisk inspelning</option>
 [% END %]
 [% limits.delete( 'fic' ) %]
 [% limits.delete( 'bio' ) %]
 [% limits.delete( 'mus' ) %]
 </select>

 [% SET lformat = 'l-format' %]
 <select name="limit" class="subtype">
 [% IF ( limits.$lformat.size ) %]
 <option value="" class="menuheader">Alla format</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Alla format</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ta' ) %]
 <option value="l-format:ta" selected="selected" >Regelbunden utskrift</option>
 [% ELSE %]
 <option value="l-format:ta" >Regelbunden utskrift</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tb' ) %]
 <option value="l-format:tb" selected="selected" >Storstil</option>
 [% ELSE %]
 <option value="l-format:tb" >Storstil</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tc or fb' ) %]
 <option value="l-format:tc or fb" selected="selected" >Punktskrift</option>
 [% ELSE %]
 <option value="l-format:tc or fb" >Punktskrift</option>
 [% END %]
 <option value="" >-----------</option>
 [% IF (limits.$lformat.0 == 'sd' ) %]
 <option value="l-format:sd" selected="selected" >CD-ljud</option>
 [% ELSE %]
 <option value="l-format:sd" >CD-ljud</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ss' ) %]
 <option value="l-format:ss" selected="selected" >Kassettinspelning</option>
 [% ELSE %]
 <option value="l-format:ss" >Kassettinspelning</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vf' ) %]
 <option value="l-format:vf" selected="selected" >VHS-band / videokassett</option>
 [% ELSE %]
 <option value="l-format:vf" >VHS-band / videokassett</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vd' ) %]
 <option value="l-format:vd" selected="selected" >DVD</option>
 [% ELSE %]
 <option value="l-format:vd" >DVD</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'co' ) %]
 <option value="l-format:co" selected="selected" >CD-programvara</option>
 [% ELSE %]
 <option value="l-format:co" >CD-programvara</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'cr' ) %]
 <option value="l-format:cr" selected="selected" >Webbplats</option>
 [% ELSE %]
 <option value="l-format:cr" >Webbplats</option>
 [% END %]
 [% limits.delete( 'l-format' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.ctype.size ) %]
 <option value="" >Fler innehållstyper</option>
 [% ELSE %]
 <option value="" selected="selected" >Fler innehållstyper</option>
 [% END %]
 [% IF (limits.ctype.0 == 'a' ) %]
 <option value="ctype:a" selected="selected" >Utdrag / sammanfattningar</option>
 [% ELSE %]
 <option value="ctype:a" >Utdrag / sammanfattningar</option>
 [% END %]
 [% IF (limits.ctype.0 == 'b' ) %]
 <option value="ctype:b" selected="selected" >Bibliografier</option>
 [% ELSE %]
 <option value="ctype:b" >Bibliografier</option>
 [% END %]
 [% IF (limits.ctype.0 == 'c' ) %]
 <option value="ctype:c" selected="selected" >Kataloger</option>
 [% ELSE %]
 <option value="ctype:c" >Kataloger</option>
 [% END %]
 [% IF (limits.ctype.0 == 'e' ) %]
 <option value="ctype:e" selected="selected" >Uppslagsverk </option>
 [% ELSE %]
 <option value="ctype:e" >Uppslagsverk </option>
 [% END %]
 [% IF (limits.ctype.0 == 'f' ) %]
 <option value="ctype:f" selected="selected" >Handböcker</option>
 [% ELSE %]
 <option value="ctype:f" >Handböcker</option>
 [% END %]
 [% IF (limits.ctype.0 == 'g' ) %]
 <option value="ctype:g" selected="selected" >Juridiska artiklar</option>
 [% ELSE %]
 <option value="ctype:g" >Juridiska artiklar</option>
 [% END %]
 [% IF (limits.ctype.0 == 'i' ) %]
 <option value="ctype:i" selected="selected" >Index</option>
 [% ELSE %]
 <option value="ctype:i" >Index</option>
 [% END %]
 [% IF (limits.ctype.0 == 'j' ) %]
 <option value="ctype:j" selected="selected" >Patentdokument</option>
 [% ELSE %]
 <option value="ctype:j" >Patentdokument</option>
 [% END %]
 [% IF (limits.ctype.0 == 'k' ) %]
 <option value="ctype:k" selected="selected" >Diskografier</option>
 [% ELSE %]
 <option value="ctype:k" >Diskografier</option>
 [% END %]
 [% IF (limits.ctype.0 == 'l' ) %]
 <option value="ctype:l" selected="selected" >Lagstiftning</option>
 [% ELSE %]
 <option value="ctype:l" >Lagstiftning</option>
 [% END %]
 [% IF (limits.ctype.0 == 'm' ) %]
 <option value="ctype:m" selected="selected" >Avhandlingar</option>
 [% ELSE %]
 <option value="ctype:m" >Avhandlingar</option>
 [% END %]
 [% IF (limits.ctype.0 == 'n' ) %]
 <option value="ctype:n" selected="selected" >Översikter</option>
 [% ELSE %]
 <option value="ctype:n" >Översikter</option>
 [% END %]
 [% IF (limits.ctype.0 == 'o' ) %]
 <option value="ctype:o" selected="selected" >Recensioner</option>
 [% ELSE %]
 <option value="ctype:o" >Recensioner</option>
 [% END %]
 [% IF (limits.ctype.0 == 'p' ) %]
 <option value="ctype:p" selected="selected" >Programmerade texter</option>
 [% ELSE %]
 <option value="ctype:p" >Programmerade texter</option>
 [% END %]
 [% IF (limits.ctype.0 == 'q' ) %]
 <option value="ctype:q" selected="selected" >Filmografier</option>
 [% ELSE %]
 <option value="ctype:q" >Filmografier</option>
 [% END %]
 [% IF (limits.ctype.0 == 'r' ) %]
 <option value="ctype:r" selected="selected" >Kataloger</option>
 [% ELSE %]
 <option value="ctype:r" >Kataloger</option>
 [% END %]
 [% IF (limits.ctype.0 == 's' ) %]
 <option value="ctype:s" selected="selected" >Statistik</option>
 [% ELSE %]
 <option value="ctype:s" >Statistik</option>
 [% END %]
 [% IF (limits.ctype.0 == 't' ) %]
 <option value="ctype:t" selected="selected" >Tekniska rapporter</option>
 [% ELSE %]
 <option value="ctype:t" >Tekniska rapporter</option>
 [% END %]
 [% IF (limits.ctype.0 == 'v' ) %]
 <option value="ctype:v" selected="selected" >Rättsfall och ärendeanteckningar</option>
 [% ELSE %]
 <option value="ctype:v" >Rättsfall och ärendeanteckningar</option>
 [% END %]
 [% IF (limits.ctype.0 == 'w' ) %]
 <option value="ctype:w" selected="selected" >Lagrapporter och sammanfattningar</option>
 [% ELSE %]
 <option value="ctype:w" >Lagrapporter och sammanfattningar</option>
 [% END %]
 [% IF (limits.ctype.0 == 'z' ) %]
 <option value="ctype:z" selected="selected" >Fördrag </option>
 [% ELSE %]
 <option value="ctype:z" >Fördrag </option>
 [% END %]
 [% limits.delete( 'ctype' ) %]
 </select>
[%- END -%]
