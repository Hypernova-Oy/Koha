[% USE Koha %]
[% PROCESS 'form-blocks.inc' %]

<div id="toolbar" class="btn-toolbar">
 <div class="btn-group"><a href="#" id="clear" class="btn btn-default btn-sm"><i class="fa fa-trash-can"></i> Tyhjennä kenttä</a></div>
 <div class="btn-group"><a href="#" id="createnew" class="btn btn-default btn-sm"><i class="fa fa-plus"></i> Luo uusi auktoriteetti</a></div>
</div>
<form name="f" method="get" action="auth_finder.pl" class="clearfix">
 <input type="hidden" name="source" value="[% source | html %]" />
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="index" value="[% index | html %]" />
 <fieldset class="rows"><legend>Haun asetukset</legend>
 <ol><li>
 <span class="label">Auktoriteettityyppi: </span>
 [% authtypecode | html %]
 <input type="hidden" name="authtypecode" value="[% authtypecode | html %]" />
 </li>
 <li>
 <label for="mainmainentry">Hae pääotsikosta (vain $a): </label>
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainmainentry">
 [% IF ( operator_mainstr == 'contains' ) %]
 <option value="contains" selected="selected">sisältää</option>
 [% ELSE %]
 <option value="contains">sisältää</option>
 [% END %]
 [% IF ( operator_mainstr == 'start' ) %]
 <option value="start" selected="selected">alkaa sanalla</option>
 [% ELSE %]
 <option value="start">alkaa sanalla</option>
 [% END %]
 [% IF ( operator_mainstr == 'exact' ) %]
 <option value="exact" selected="selected">on</option>
 [% ELSE %]
 <option value="exact">on</option>
 [% END %]
 </select>
 <input id="value_mainstr" style="width:400px;" type="text" name="value_mainstr" value="[% value_mainstr | html %]" />
 <div id="yvaluecontainermainmainentry"></div>
 </li>

 <li>
 <label for="mainentry">Hae pääotsikosta: </label>
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainentry">
 [% IF ( operator_main == 'contains' ) %]
 <option value="contains" selected="selected">sisältää</option>
 [% ELSE %]
 <option value="contains">sisältää</option>
 [% END %]
 [% IF ( operator_main == 'start' ) %]
 <option value="start" selected="selected">alkaa sanalla</option>
 [% ELSE %]
 <option value="start">alkaa sanalla</option>
 [% END %]
 [% IF ( operator_main == 'exact' ) %]
 <option value="exact" selected="selected">on</option>
 [% ELSE %]
 <option value="exact">on</option>
 [% END %]
 </select>
 <input id="value_main" style="width:400px;" type="text" name="value_main" value="[% value_main | html %]" />
 <div id="yvaluecontainermainentry"></div>
 </li>
 <li>
 <label for="marclistheading">Hae kaikista otsikoista: </label>
 <input type="hidden" name="marclist" value="match" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistheading">
 [% IF ( operator_match == 'contains' ) %]
 <option value="contains" selected="selected">sisältää</option>
 [% ELSE %]
 <option value="contains">sisältää</option>
 [% END %]
 [% IF ( operator_match == 'start' ) %]
 <option value="start" selected="selected">alkaa sanalla</option>
 [% ELSE %]
 <option value="start">alkaa sanalla</option>
 [% END %]
 [% IF ( operator_match == 'exact' ) %]
 <option value="exact" selected="selected">on</option>
 [% ELSE %]
 <option value="exact">on</option>
 [% END %]
 </select>
 <input id="value_match" style="width:400px;" type="text" name="value_match" value="[% value_match | html %]" />
 <div id="yvaluecontainermarclistheading"></div>
 </li>
 <li>
 <label for="marclistanywhere">Hae koko tietue: </label>
 <input type="hidden" name="marclist" value="all" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistanywhere">
 [% IF ( operator_any == 'contains' ) %]
 <option value="contains" selected="selected">sisältää</option>
 [% ELSE %]
 <option value="contains">sisältää</option>
 [% END %]
 [% IF ( operator_any == 'start' ) %]
 <option value="start" selected="selected">alkaa sanalla</option>
 [% ELSE %]
 <option value="start">alkaa sanalla</option>
 [% END %]
 [% IF ( operator_any == 'exact' ) %]
 <option value="exact" selected="selected">on</option>
 [% ELSE %]
 <option value="exact">on</option>
 [% END %]
 </select>
 <input id="value_any" style="width:400px;" type="text" name="value_any" value="[% value_any | html %]" />
 <div id="yvaluecontainermarclist"></div>
 </li>
 <li>
 <label for="orderby">Järjestä </label>
 <select name="orderby" id="orderby">
 [% IF ( orderby == 'HeadingAsc' ) %]
 <option value="HeadingAsc" selected="selected">Otsikko A-Z</option>
 [% ELSE %]
 <option value="HeadingAsc">Otsikko A-Z</option>
 [% END %]
 [% IF ( orderby == 'HeadingDsc' ) %]
 <option value="HeadingDsc" selected="selected">Otsikko Z-A</option>
 [% ELSE %]
 <option value="HeadingDsc">Otsikko Z-A</option>
 [% END %]
 [% IF ( orderby == '' && op ) %]
 <option value="" selected="selected">Ei mitään</option>
 [% ELSE %]
 <option value="">Ei mitään</option>
 [% END %]
 </select>
 </li></ol></fieldset>
 [% IF source == 'auth' %]
 <fieldset class="rows"><legend>Suhdetiedot</legend>
 <ol>
 <li>
 <label for="special_relationship">Erityissuhde: </label>
 <select name="relationship" id="special_relationship">
 [% selected=relationship | html %] [% PROCESS selectoptionopen value='' %]Ei määritelty</option>
 [% IF Koha.Preference('marcflavour') == 'MARC21' %] [% PROCESS selectoptionopen value='a' %]a - Aiempi otsikko</option>
 [% PROCESS selectoptionopen value='b' %]b - Myöhempi otsikko</option>
 [% PROCESS selectoptionopen value='d' %]d - Akronyymi</option>
 [% PROCESS selectoptionopen value='f' %]f - Musiikkiteos</option>
 [% PROCESS selectoptionopen value='g' %]g - Laajempi termi</option>
 [% PROCESS selectoptionopen value='h' %]h - Suppeampi termi</option>
 [% PROCESS selectoptionopen value='i' %]i - Viittauksen ohjefraasi osakentässä $i</option>
 [% PROCESS selectoptionopen value='n' %]n - Soveltumaton</option>
 [% PROCESS selectoptionopen value='r' %]r - Suhteen nimitys osakentässä $i tai $4</option>
 [% PROCESS selectoptionopen value='t' %]t - Isäntäyhteisö</option>
 [% ELSIF Koha.Preference('marcflavour') == 'UNIMARC' %] [% PROCESS selectoptionopen value='a' %]a = aiempi nimi</option>
 [% PROCESS selectoptionopen value='b' %]b = myöhempi nimi</option>
 [% PROCESS selectoptionopen value='c' %]c = virallinen nimi</option>
 [% PROCESS selectoptionopen value='d' %]d = akronyymi / alkukirjain / lyhenne</option>
 [% PROCESS selectoptionopen value='e' %]e = salanimi</option>
 [% PROCESS selectoptionopen value='f' %]f = oikea nimi</option>
 [% PROCESS selectoptionopen value='g' %]g = laajempi termi tai nimi</option>
 [% PROCESS selectoptionopen value='h' %]h = suppeampi termi tai nimi</option>
 [% PROCESS selectoptionopen value='i' %]i = nimi uskonnossa</option>
 [% PROCESS selectoptionopen value='j' %]j = avionimi</option>
 [% PROCESS selectoptionopen value='k' %]k = nimi ennen avioliittoa</option>
 [% PROCESS selectoptionopen value='l' %]l = jaettu salanimi</option>
 [% PROCESS selectoptionopen value='m' %]m = maallinen nimi</option>
 [% PROCESS selectoptionopen value='n' %]n = nimen eri sääntömuoto</option>
 [% PROCESS selectoptionopen value='o' %]o = oletettu/väitetty tekijä / vakiintunut nimeke</option>
 [% PROCESS selectoptionopen value='x' %]x = ei voi soveltaa</option>
 [% PROCESS selectoptionopen value='z' %]z = muu</option>
 [% END %]
 </select>
 </li>
 </ol>
 </fieldset>
 [% END %]

 <nav class="navbar navbar-default fixed-bottom">
 <div class="container-fluid">
 <fieldset class="action">
 <input class="btn btn-primary" id="search" type="submit" value="Haku" />
 <input class="btn btn-default" id="clear-form" type="reset" value="Tyhjennä lomake" />
 <button type="button" class="btn btn-default close_window">Sulje ikkuna</button>
 </fieldset>
 </div>
 </nav>
</form>
