<p>
 <a id="show_coded_fields" class="toggle_element" data-element="#Coded_Fields,#show_coded_fields,#hide_coded_fields" href="#"><i class="fa-solid fa-square-plus"></i> Visa kodade informationsfilter</a>
 <a id="hide_coded_fields" class="toggle_element" data-element="#Coded_Fields,#show_coded_fields,#hide_coded_fields" href="#" style="display:none;"><i class="fa-solid fa-square-minus"></i> Dölj kodade informationsfilter</a>
</p>
<div style="display:none;" id="Coded_Fields">
<!-- SUBTYPE LIMITS -->
 <fieldset>
 <legend>Kodade fält</legend>
 <p>
 <label for="audience">Målgrupp: </label>
 <select id="audience" name="limit" class="subtype">
 <option value="" selected="selected" >Alla</option>
 <option value="ta:a">ungdom, generell</option>
 <option value="ta:b">förskoleålder (0-5)</option>
 <option value="ta:c">lågstadieålder (5-8)</option>
 <option value="ta:d">barn (9-14)</option>
 <option value="ta:e">ung vuxen</option>
 <option value="ta:k">vuxen, facklitteratur</option>
 <option value="ta:m">vuxen, allmän</option>
 <option value="ta:u">okänd</option>
 </select>
 </p>
 <p>
 <label for="physical_presentation">Fysisk presentation: </label>
 <select id="physical_presentation" name="limit" class="subtype">
 <option value="" selected="selected" >Alla</option>
 <option value="ff8-23:r">vanligt tryck</option>
 <option value="ff8-23:d">storstil</option>
 <option value="ff8-23:e">tidningsformat</option>
 <option value="ff8-23:f">Braille- eller Moon-tecken</option>
 <option value="ff8-23:g">mikrotryck</option>
 <option value="ff8-23:h">handskrift</option>
 <option value="ff8-23:i">multimedia</option>
 <option value="ff8-23:j">mini-tryck</option>
 <option value="ff8-23:s">elektronisk resurs</option>
 <option value="ff8-23:t">mikroform</option>
 <option value="ff8-23:z">annan form av textmaterial</option>
 </select>
 </p>
 <p>
 <label for="literary_genre">Litterär genre: </label>
 <select id="literary_genre" name="limit" class="subtype">
 <option value="" selected="selected" >Alla</option>
 <option value="lf:a">skönlitteratur</option>
 <option value="lf:b">drama</option>
 <option value="lf:c">essäer</option>
 <option value="lf:d">humor, satir</option>
 <option value="lf:e">brev</option>
 <option value="lf:f">noveller</option>
 <option value="lf:g">poesi</option>
 <option value="lf:h">tal, retorik</option>
 <option value="lf:i">libretto</option>
 <option value="lf:y">inte en litterär text</option>
 <option value="lf:z">flera/andra litterära former</option>
 </select>
 </p>
 <p>
 <label for="biography">Biografi: </label>
 <select id="biography" name="limit" class="subtype">
 <option value="">Alla</option>
 <option value="bio:y">inte en biografi</option>
 <option value="bio:a">självbiografi</option>
 <option value="bio:b">individuell biografi</option>
 <option value="bio:c">kollektivbiografi</option>
 <option value="bio:d">innehåller biografiska data</option>
 </select>
 </p>
 <p>
 <label for="illustration">Illustration:</label>
 <select id="illustration" name="limit" class="subtype">
 <option value="">Alla</option>
 <option value="ff8-18-21:a">illustrationer</option>
 <option value="ff8-18-21:b">kartor</option>
 <option value="ff8-18-21:c">porträtt</option>
 <option value="ff8-18-21:d">charts</option>
 <option value="ff8-18-21:e">plans</option>
 <option value="ff8-18-21:f">plates</option>
 <option value="ff8-18-21:g">musik</option>
 <option value="ff8-18-21:h">faksimiler</option>
 <option value="ff8-18-21:i">heraldiska vapen</option>
 <option value="ff8-18-21:j">genealogitabeller</option>
 <option value="ff8-18-21:k">forms</option>
 <option value="ff8-18-21:l">samples</option>
 <option value="ff8-18-21:m">ljudinspelningar</option>
 <option value="ff8-18-21:n">transparencies</option>
 <option value="ff8-18-21:o">illuminations</option>
 <option value="ff8-18-21:y">inga illustrationer</option>
 </select>
 </p>
 <p>
 <label for="content">Innehåll: </label>
 <select id="content" name="limit" class="subtype">
 <option value="" >Alla</option>
 <option value="ctype:a" >bibliografi </option>
 <option value="ctype:b" >katalog</option>
 <option value="ctype:c" >register</option>
 <option value="ctype:d" >sammanfattning</option>
 <option value="ctype:e" >ordbok</option>
 <option value="ctype:f" >encyclopaedia</option>
 <option value="ctype:g" >directory</option>
 <option value="ctype:h" >projektbeskrivning</option>
 <option value="ctype:i" >statistik</option>
 <option value="ctype:j" >programmed text books</option>
 <option value="ctype:k" >patent </option>
 <option value="ctype:l" >standard </option>
 <option value="ctype:m" >dissertation or thesis</option>
 <option value="ctype:n" >laws and legislation</option>
 <option value="ctype:o" >numerisk tabell</option>
 <option value="ctype:p" >teknisk rapport</option>
 <option value="ctype:q" >examination paper</option>
 <option value="ctype:r" >literature surveys/reviews</option>
 <option value="ctype:s" >fördrag</option>
 <option value="ctype:t" >cartoons or comic strips</option>
 <option value="ctype:v" >dissertation or thesis (revised)</option>
 <option value="ctype:w" >religiös text</option>
 <option value="ctype:z" >other</option>
 </select>
 </p>
 <p>
 <label for="video_types">Videotyper: </label>
 <select id="video_types" name="limit" class="subtype">
 <option value="">Alla</option>
 <option value="Video-mt:a">film</option>
 <option value="Video-mt:b">visual projection</option>
 <option value="Video-mt:c">videoinspelning</option>
 </select>
 </p>
 </fieldset>

 <fieldset>
 <legend>Periodika</legend>
 <p>
 <label for="serial_type">Serietyp: </label>
 <select id="serial_type" name="limit" class="subtype">
 <option value="">Alla typer</option>
 <option value="ff8-21:a">Periodika</option>
 <option value="ff8-21:b">Monografiserie </option>
 <option value="ff8-21:c">Tidning</option>
 <option value="ff8-21:e">Uppdaterar lösblad </option>
 <option value="ff8-21:f">Databas</option>
 <option value="ff8-21:g">Uppdaterar webbplats </option>
 <option value="ff8-21:z">Annat</option>
 </select>
 </p>
 <p>
 <label for="periodicity">Periodicitet:</label>
 <select id="periodicity" name="limit" class="subtype">
 <option value="">Alla</option>
 <option value="ff8-18:a">Dagligen</option>
 <option value="ff8-18:b">Två gånger i veckan </option>
 <option value="ff8-18:c">Veckovis </option>
 <option value="ff8-18:d">Varannan vecka </option>
 <option value="ff8-18:e">Två gånger i månaden </option>
 <option value="ff8-18:f">Månadsvis </option>
 <option value="ff8-18:g">Varannan månad </option>
 <option value="ff8-18:h">Kvartalsvis </option>
 <option value="ff8-18:i">Tre gånger om året </option>
 <option value="ff8-18:j">Två gånger om året </option>
 <option value="ff8-18:k">Årlig </option>
 <option value="ff8-18:l">Biennial</option>
 <option value="ff8-18:m">Triennial</option>
 <option value="ff8-18:n">Tre gånger i veckan </option>
 <option value="ff8-18:o">Tre gånger i månaden </option>
 <option value="ff8-18:y">Utan periodicitet </option>
 <option value="ff8-18:u">Okänd</option>
 <option value="ff8-18:z">Annat</option>
 </select>
 </p>
 <p>
 <label for="regularity">Regelbundenhet:</label>
 <select id="regularity" name="limit" class="subtype">
 <option value="">All periodicitet</option>
 <option value="ff8-19:a">regular</option>
 <option value="ff8-19:b">normalised irregular</option>
 <option value="ff8-19:y">oregelbunden</option>
 <option value="ff8-19:u">okänd</option>
 </select>
 </p>
 </fieldset>

 <fieldset>
 <legend>Bild </legend>
 <p>
 <select name="limit" class="subtype">
 <option value="">Alla</option>
 <option value="Graphics-type:a">kollage</option>
 <option value="Graphics-type:b">drawing</option>
 <option value="Graphics-type:c">painting</option>
 <option value="Graphics-type:d">photomechanical reproduction</option>
 <option value="Graphics-type:e">fotonegativ</option>
 <option value="Graphics-type:f">photoprint</option>
 <option value="Graphics-type:h">bild</option>
 <option value="Graphics-type:i">print</option>
 <option value="Graphics-type:k">technical drawing</option>
 <option value="Graphics-type:z">other non-projected graphic type</option>
 </select>
 <select name="limit" class="subtype">
 <option value="">Alla</option>
 <option value="Graphics-support:a">canvas</option>
 <option value="Graphics-support:b">bristol board</option>
 <option value="Graphics-support:c">cardboard/illustration board</option>
 <option value="Graphics-support:d">glas</option>
 <option value="Graphics-support:j">plaster</option>
 <option value="Graphics-support:k">hardboard</option>
 <option value="Graphics-support:l">porslin</option>
 <option value="Graphics-support:m">stone</option>
 <option value="Graphics-support:n">wood</option>
 <option value="Graphics-support:v">mixed collection</option>
 <option value="Graphics-support:e">synthetics</option>
 <option value="Graphics-support:f">skin</option>
 <option value="Graphics-support:g">textile</option>
 <option value="Graphics-support:h">metall</option>
 <option value="Graphics-support:i">paper</option>
 <option value="Graphics-support:z">others</option>
 <option value="Graphics-support:u">okänd</option>
 </select>
 </p>
</fieldset>
</div>
