<p>
 <a id="show_coded_fields" class="toggle_element" data-element="#Coded_Fields,#show_coded_fields,#hide_coded_fields" href="#"><i class="fa-solid fa-square-plus"></i> Näytä koodatut tietosuodattimet</a>
 <a id="hide_coded_fields" class="toggle_element" data-element="#Coded_Fields,#show_coded_fields,#hide_coded_fields" href="#" style="display:none;"><i class="fa-solid fa-square-minus"></i> Piilota koodatut tietosuodattimet</a>
</p>
<div style="display:none;" id="Coded_Fields">
<!-- SUBTYPE LIMITS -->
 <fieldset>
 <legend>Koodikentät</legend>
 <p>
 <label for="audience">Kohderyhmä: </label>
 <select id="audience" name="limit" class="subtype">
 <option value="" selected="selected" >Kaikki</option>
 <option value="ta:a">lapset ja nuoret, yleinen</option>
 <option value="ta:b">pre-primary (0-5)</option>
 <option value="ta:c">ala-asteikäiset</option>
 <option value="ta:d">lapset (9-14)</option>
 <option value="ta:e">nuoret aikuiset</option>
 <option value="ta:k">aikuiset, vakava</option>
 <option value="ta:m">aikuiset, Yleinen</option>
 <option value="ta:u">tuntematon</option>
 </select>
 </p>
 <p>
 <label for="physical_presentation">Fyysinen kuvailu: </label>
 <select id="physical_presentation" name="limit" class="subtype">
 <option value="" selected="selected" >Kaikki</option>
 <option value="ff8-23:r">tavanomainen painotuote</option>
 <option value="ff8-23:d">isoteksti</option>
 <option value="ff8-23:e">newspaper format</option>
 <option value="ff8-23:f">Moonin tai Braillen kirjoitus</option>
 <option value="ff8-23:g">microprint</option>
 <option value="ff8-23:h">käsin kirjoitettu</option>
 <option value="ff8-23:i">multimedia</option>
 <option value="ff8-23:j">mini-print</option>
 <option value="ff8-23:s">elektroninen aineisto</option>
 <option value="ff8-23:t">microform</option>
 <option value="ff8-23:z">other form of textual material</option>
 </select>
 </p>
 <p>
 <label for="literary_genre">Kirjallisuuden genre: </label>
 <select id="literary_genre" name="limit" class="subtype">
 <option value="" selected="selected" >Kaikki</option>
 <option value="lf:a">kaunokirjallisuus</option>
 <option value="lf:b">draama</option>
 <option value="lf:c">esseet</option>
 <option value="lf:d">huumori, satiiri</option>
 <option value="lf:e">kirjeet</option>
 <option value="lf:f">novellit</option>
 <option value="lf:g">runo</option>
 <option value="lf:h">luennot, puheet</option>
 <option value="lf:i">libretto</option>
 <option value="lf:y">Ei tekstiä</option>
 <option value="lf:z">multiple/other literary forms</option>
 </select>
 </p>
 <p>
 <label for="biography">Biografia: </label>
 <select id="biography" name="limit" class="subtype">
 <option value="">Kaikki</option>
 <option value="bio:y">not a biography</option>
 <option value="bio:a">Omaelämäkerta</option>
 <option value="bio:b">elämäkerta</option>
 <option value="bio:c">kokoomaelämäkerta</option>
 <option value="bio:d">Sisältää elämäkertatietoja</option>
 </select>
 </p>
 <p>
 <label for="illustration">Kuvitus: </label>
 <select id="illustration" name="limit" class="subtype">
 <option value="">Kaikki</option>
 <option value="ff8-18-21:a">kuvitettu</option>
 <option value="ff8-18-21:b">kartat</option>
 <option value="ff8-18-21:c">portraits</option>
 <option value="ff8-18-21:d">kaaviot</option>
 <option value="ff8-18-21:e">plans</option>
 <option value="ff8-18-21:f">plates</option>
 <option value="ff8-18-21:g">musiikki</option>
 <option value="ff8-18-21:h">Näköispainos</option>
 <option value="ff8-18-21:i">vaakuna</option>
 <option value="ff8-18-21:j">Sukutaulut</option>
 <option value="ff8-18-21:k">muodostaa</option>
 <option value="ff8-18-21:l">näytteet</option>
 <option value="ff8-18-21:m">äänitteet</option>
 <option value="ff8-18-21:n">kalvot</option>
 <option value="ff8-18-21:o">kuvitus</option>
 <option value="ff8-18-21:y">no illustrations</option>
 </select>
 </p>
 <p>
 <label for="content">Sisältö: </label>
 <select id="content" name="limit" class="subtype">
 <option value="" >Kaikki</option>
 <option value="ctype:a" >bibliografia</option>
 <option value="ctype:b" >kokoelma</option>
 <option value="ctype:c" >hakemisto</option>
 <option value="ctype:d" >tiivistelmä</option>
 <option value="ctype:e" >sanakirja, sanasto</option>
 <option value="ctype:f" >tietosanakirja</option>
 <option value="ctype:g" >hakemisto</option>
 <option value="ctype:h" >Volyymin kuvaus:</option>
 <option value="ctype:i" >tilastot</option>
 <option value="ctype:j" >programmed text books</option>
 <option value="ctype:k" >patentti</option>
 <option value="ctype:l" >standard</option>
 <option value="ctype:m" >väitöskirja tai opinnäytetyö</option>
 <option value="ctype:n" >laws and legislation</option>
 <option value="ctype:o" >numeric table</option>
 <option value="ctype:p" >tekninen raportti</option>
 <option value="ctype:q" >Tutkintotodistus</option>
 <option value="ctype:r" >kirjallisuuskatsaukset, arvostelut</option>
 <option value="ctype:s" >sopimukset</option>
 <option value="ctype:t" >sarjakuvat</option>
 <option value="ctype:v" >väitöskirja tai opinnäytetyö (tarkistettu)</option>
 <option value="ctype:w" >uskonnollinen teksti</option>
 <option value="ctype:z" >muu</option>
 </select>
 </p>
 <p>
 <label for="video_types">Videotyypit: </label>
 <select id="video_types" name="limit" class="subtype">
 <option value="">Kaikki</option>
 <option value="Video-mt:a">elokuva</option>
 <option value="Video-mt:b">projektio</option>
 <option value="Video-mt:c">Videotallenne</option>
 </select>
 </p>
 </fieldset>

 <fieldset>
 <legend>Kausijulkaisut</legend>
 <p>
 <label for="serial_type">Kausijulkaisun tyyppi: </label>
 <select id="serial_type" name="limit" class="subtype">
 <option value="">Kaikki</option>
 <option value="ff8-21:a">Aikakauslehti</option>
 <option value="ff8-21:b">Monografiasarja</option>
 <option value="ff8-21:c">Sanomalehti</option>
 <option value="ff8-21:e">Päivittyvä irtolehtijulkaisu</option>
 <option value="ff8-21:f">Tietokanta</option>
 <option value="ff8-21:g">Päivittyvä verkkosivusto</option>
 <option value="ff8-21:z">Muu</option>
 </select>
 </p>
 <p>
 <label for="periodicity">Jaksollisuus: </label>
 <select id="periodicity" name="limit" class="subtype">
 <option value="">Kaikki</option>
 <option value="ff8-18:a">Päivittäin</option>
 <option value="ff8-18:b">Kaksi kertaa viikossa</option>
 <option value="ff8-18:c">Kerran viikossa</option>
 <option value="ff8-18:d">Kerran kahdessa viikossa</option>
 <option value="ff8-18:e">Kaksi kertaa kuukaudessa</option>
 <option value="ff8-18:f">Kerran kuukaudessa</option>
 <option value="ff8-18:g">Joka toinen kuukausi</option>
 <option value="ff8-18:h">Neljäsosavuosittain</option>
 <option value="ff8-18:i">Kolme kertaa vuodessa</option>
 <option value="ff8-18:j">Puolivuosittain</option>
 <option value="ff8-18:k">Kerran vuodessa</option>
 <option value="ff8-18:l">Kerran kahdessa vuodessa</option>
 <option value="ff8-18:m">Kerran kolmessa vuodessa</option>
 <option value="ff8-18:n">Kolme kertaa viikossa</option>
 <option value="ff8-18:o">Kolme kertaa kuukaudessa</option>
 <option value="ff8-18:y">Epäsäännöllinen</option>
 <option value="ff8-18:u">Tuntematon</option>
 <option value="ff8-18:z">Muu</option>
 </select>
 </p>
 <p>
 <label for="regularity">Säännöllisyys: </label>
 <select id="regularity" name="limit" class="subtype">
 <option value="">Mikä tahansa säännöllisyys</option>
 <option value="ff8-19:a">regular</option>
 <option value="ff8-19:b">normalised irregular</option>
 <option value="ff8-19:y">Epäsäännöllinen</option>
 <option value="ff8-19:u">tuntematon</option>
 </select>
 </p>
 </fieldset>

 <fieldset>
 <legend>Kuva</legend>
 <p>
 <select name="limit" class="subtype">
 <option value="">Kaikki</option>
 <option value="Graphics-type:a">kollaasi</option>
 <option value="Graphics-type:b">piirustus</option>
 <option value="Graphics-type:c">maalaus</option>
 <option value="Graphics-type:d">fotomekaaninen jäljennös</option>
 <option value="Graphics-type:e">valokuvanegatiivi</option>
 <option value="Graphics-type:f">valokuvatuloste</option>
 <option value="Graphics-type:h">kuva</option>
 <option value="Graphics-type:i">painotuote</option>
 <option value="Graphics-type:k">tekninen piirustus</option>
 <option value="Graphics-type:z">other non-projected graphic type</option>
 </select>
 <select name="limit" class="subtype">
 <option value="">Kaikki</option>
 <option value="Graphics-support:a">maalauskangas</option>
 <option value="Graphics-support:b">Bristol-taulu</option>
 <option value="Graphics-support:c">kortti/kuvataulu</option>
 <option value="Graphics-support:d">lasi</option>
 <option value="Graphics-support:j">Kipsi</option>
 <option value="Graphics-support:k">kovalevy</option>
 <option value="Graphics-support:l">porcelaine</option>
 <option value="Graphics-support:m">kivi</option>
 <option value="Graphics-support:n">puu</option>
 <option value="Graphics-support:v">kokoelma</option>
 <option value="Graphics-support:e">Synteettinen</option>
 <option value="Graphics-support:f">in</option>
 <option value="Graphics-support:g">Tekstiili</option>
 <option value="Graphics-support:h">metal</option>
 <option value="Graphics-support:i">paper</option>
 <option value="Graphics-support:z">muut</option>
 <option value="Graphics-support:u">tuntematon</option>
 </select>
 </p>
</fieldset>
</div>
