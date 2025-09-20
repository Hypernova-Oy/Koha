[%- BLOCK subtype_dropdowns -%]
 <select name="limit" class="subtype">
 [% IF ( limits.aud.size ) %]
 <option value="" class="menuheader">Kohdeyleisö</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Kohdeyleisö</option>
 [% END %]
 [% IF (limits.aud.0 == 'a' ) %]
 <option selected="selected" value="aud:a">Esikouluikäiset</option>
 [% ELSE %]
 <option value="aud:a">Esikouluikäiset</option>
 [% END %]
 [% IF (limits.aud.0 == 'b' ) %]
 <option value="aud:b" selected="selected">Ala-asteikäiset</option>
 [% ELSE %]
 <option value="aud:b">Ala-asteikäiset</option>
 [% END %]
 [% IF (limits.aud.0 == 'c' ) %]
 <option value="aud:c" selected="selected">Yläasteikäiset</option>
 [% ELSE %]
 <option value="aud:c">Yläasteikäiset</option>
 [% END %]
 [% IF (limits.aud.0 == 'd' ) %]
 <option value="aud:d" selected="selected">Lukioikäiset ja vastaavat</option>
 [% ELSE %]
 <option value="aud:d">Lukioikäiset ja vastaavat</option>
 [% END %]
 [% IF (limits.aud.0 == 'e' ) %]
 <option value="aud:e" selected="selected">Aikuinen</option>
 [% ELSE %]
 <option value="aud:e">Aikuinen</option>
 [% END %]
 [% IF (limits.aud.0 == 'f' ) %]
 <option value="aud:f" selected="selected">Erityisryhmä</option>
 [% ELSE %]
 <option value="aud:f">Erityisryhmä</option>
 [% END %]
 [% IF (limits.aud.0 == 'g' ) %]
 <option value="aud:g" selected="selected">Yleinen</option>
 [% ELSE %]
 <option value="aud:g">Yleinen</option>
 [% END %]
 [% IF (limits.aud.0 == 'j' ) %]
 <option value="aud:j" selected="selected">Lapset ja nuoret</option>
 [% ELSE %]
 <option value="aud:j">Lapset ja nuoret</option>
 [% END %]
 [% limits.delete( 'aud' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.fic.size OR limits.bio.size OR limits.mus.size ) %]
 <option value="" class="menuheader">Sisältö</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Sisältö</option>
 [% END %]
 [% IF (limits.fic.0 == '1' ) %]
 <option value="fic:1" selected="selected" >Kaunokirjallisuus</option>
 [% ELSE %]
 <option value="fic:1" >Kaunokirjallisuus</option>
 [% END %]
 [% IF (limits.fic.0 == '0' ) %]
 <option value="fic:0" selected="selected" >Tietokirjallisuus</option>
 [% ELSE %]
 <option value="fic:0" >Tietokirjallisuus</option>
 [% END %]
 [% IF (limits.bio.0 == 'b' ) %]
 <option value="bio:b" selected="selected" >Elämäkerta</option>
 [% ELSE %]
 <option value="bio:b" >Elämäkerta</option>
 [% END %]
 [% IF (limits.mus.0 == 'j' ) %]
 <option value="mus:j" selected="selected" >Musiikkiäänite</option>
 [% ELSE %]
 <option value="mus:j" >Musiikkiäänite</option>
 [% END %]
 [% IF (limits.mus.0 == 'i' ) %]
 <option value="mus:i" selected="selected" >Puheäänite</option>
 [% ELSE %]
 <option value="mus:i" >Puheäänite</option>
 [% END %]
 [% limits.delete( 'fic' ) %]
 [% limits.delete( 'bio' ) %]
 [% limits.delete( 'mus' ) %]
 </select>

 [% SET lformat = 'l-format' %]
 <select name="limit" class="subtype">
 [% IF ( limits.$lformat.size ) %]
 <option value="" class="menuheader">Materiaali</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Materiaali</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ta' ) %]
 <option value="l-format:ta" selected="selected" >Tekstiaineisto</option>
 [% ELSE %]
 <option value="l-format:ta" >Tekstiaineisto</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tb' ) %]
 <option value="l-format:tb" selected="selected" >Isoteksti</option>
 [% ELSE %]
 <option value="l-format:tb" >Isoteksti</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tc or fb' ) %]
 <option value="l-format:tc or fb" selected="selected" >Pistekirjoitus</option>
 [% ELSE %]
 <option value="l-format:tc or fb" >Pistekirjoitus</option>
 [% END %]
 <option value="" >-----------</option>
 [% IF (limits.$lformat.0 == 'sd' ) %]
 <option value="l-format:sd" selected="selected" >CD-äänilevy</option>
 [% ELSE %]
 <option value="l-format:sd" >CD-äänilevy</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ss' ) %]
 <option value="l-format:ss" selected="selected" >Kasettiäänite</option>
 [% ELSE %]
 <option value="l-format:ss" >Kasettiäänite</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vf' ) %]
 <option value="l-format:vf" selected="selected" >VHS / videokasetti</option>
 [% ELSE %]
 <option value="l-format:vf" >VHS / videokasetti</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vd' ) %]
 <option value="l-format:vd" selected="selected" >DVD-video</option>
 [% ELSE %]
 <option value="l-format:vd" >DVD-video</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'co' ) %]
 <option value="l-format:co" selected="selected" >CD-ROM</option>
 [% ELSE %]
 <option value="l-format:co" >CD-ROM</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'cr' ) %]
 <option value="l-format:cr" selected="selected" >Verkkosivut</option>
 [% ELSE %]
 <option value="l-format:cr" >Verkkosivut</option>
 [% END %]
 [% limits.delete( 'l-format' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.ctype.size ) %]
 <option value="" >Muut sisältötyypit</option>
 [% ELSE %]
 <option value="" selected="selected" >Muut sisältötyypit</option>
 [% END %]
 [% IF (limits.ctype.0 == 'a' ) %]
 <option value="ctype:a" selected="selected" >Tiivistelmät, lyhennelmät</option>
 [% ELSE %]
 <option value="ctype:a" >Tiivistelmät, lyhennelmät</option>
 [% END %]
 [% IF (limits.ctype.0 == 'b' ) %]
 <option value="ctype:b" selected="selected" >Bibliografiat</option>
 [% ELSE %]
 <option value="ctype:b" >Bibliografiat</option>
 [% END %]
 [% IF (limits.ctype.0 == 'c' ) %]
 <option value="ctype:c" selected="selected" >Luettelot, kuvastot</option>
 [% ELSE %]
 <option value="ctype:c" >Luettelot, kuvastot</option>
 [% END %]
 [% IF (limits.ctype.0 == 'e' ) %]
 <option value="ctype:e" selected="selected" >Tietosanakirjat, hakuteokset </option>
 [% ELSE %]
 <option value="ctype:e" >Tietosanakirjat, hakuteokset </option>
 [% END %]
 [% IF (limits.ctype.0 == 'f' ) %]
 <option value="ctype:f" selected="selected" >Käsikirjat</option>
 [% ELSE %]
 <option value="ctype:f" >Käsikirjat</option>
 [% END %]
 [% IF (limits.ctype.0 == 'g' ) %]
 <option value="ctype:g" selected="selected" >Artiklat, pykälät</option>
 [% ELSE %]
 <option value="ctype:g" >Artiklat, pykälät</option>
 [% END %]
 [% IF (limits.ctype.0 == 'i' ) %]
 <option value="ctype:i" selected="selected" >Hakemistot, indeksit</option>
 [% ELSE %]
 <option value="ctype:i" >Hakemistot, indeksit</option>
 [% END %]
 [% IF (limits.ctype.0 == 'j' ) %]
 <option value="ctype:j" selected="selected" >Patentit</option>
 [% ELSE %]
 <option value="ctype:j" >Patentit</option>
 [% END %]
 [% IF (limits.ctype.0 == 'k' ) %]
 <option value="ctype:k" selected="selected" >Diskografiat</option>
 [% ELSE %]
 <option value="ctype:k" >Diskografiat</option>
 [% END %]
 [% IF (limits.ctype.0 == 'l' ) %]
 <option value="ctype:l" selected="selected" >Lait, säädökset</option>
 [% ELSE %]
 <option value="ctype:l" >Lait, säädökset</option>
 [% END %]
 [% IF (limits.ctype.0 == 'm' ) %]
 <option value="ctype:m" selected="selected" >Väitöskirjat tai muut opinnäytteet</option>
 [% ELSE %]
 <option value="ctype:m" >Väitöskirjat tai muut opinnäytteet</option>
 [% END %]
 [% IF (limits.ctype.0 == 'n' ) %]
 <option value="ctype:n" selected="selected" >Kirjallisuuskatsaukset</option>
 [% ELSE %]
 <option value="ctype:n" >Kirjallisuuskatsaukset</option>
 [% END %]
 [% IF (limits.ctype.0 == 'o' ) %]
 <option value="ctype:o" selected="selected" >Arvostelut</option>
 [% ELSE %]
 <option value="ctype:o" >Arvostelut</option>
 [% END %]
 [% IF (limits.ctype.0 == 'p' ) %]
 <option value="ctype:p" selected="selected" >Ohjelmoidut tekstit</option>
 [% ELSE %]
 <option value="ctype:p" >Ohjelmoidut tekstit</option>
 [% END %]
 [% IF (limits.ctype.0 == 'q' ) %]
 <option value="ctype:q" selected="selected" >Filmografiat</option>
 [% ELSE %]
 <option value="ctype:q" >Filmografiat</option>
 [% END %]
 [% IF (limits.ctype.0 == 'r' ) %]
 <option value="ctype:r" selected="selected" >Henkilö- tai yhteisöhakemistot</option>
 [% ELSE %]
 <option value="ctype:r" >Henkilö- tai yhteisöhakemistot</option>
 [% END %]
 [% IF (limits.ctype.0 == 's' ) %]
 <option value="ctype:s" selected="selected" >Tilastot</option>
 [% ELSE %]
 <option value="ctype:s" >Tilastot</option>
 [% END %]
 [% IF (limits.ctype.0 == 't' ) %]
 <option value="ctype:t" selected="selected" >Tekniset raportit</option>
 [% ELSE %]
 <option value="ctype:t" >Tekniset raportit</option>
 [% END %]
 [% IF (limits.ctype.0 == 'v' ) %]
 <option value="ctype:v" selected="selected" >Oikeustapauskeskustelut</option>
 [% ELSE %]
 <option value="ctype:v" >Oikeustapauskeskustelut</option>
 [% END %]
 [% IF (limits.ctype.0 == 'w' ) %]
 <option value="ctype:w" selected="selected" >Tuomioistuinpäätökset</option>
 [% ELSE %]
 <option value="ctype:w" >Tuomioistuinpäätökset</option>
 [% END %]
 [% IF (limits.ctype.0 == 'z' ) %]
 <option value="ctype:z" selected="selected" >Sopimukset </option>
 [% ELSE %]
 <option value="ctype:z" >Sopimukset </option>
 [% END %]
 [% limits.delete( 'ctype' ) %]
 </select>
[%- END -%]
