[% USE Koha %]
[% PROCESS 'form-blocks.inc' %]

<div id="toolbar" class="btn-toolbar">
 <div class="btn-group"><a href="#" id="clear" class="btn btn-default btn-sm"><i class="fa fa-trash-can"></i> Rensa fält</a></div>
 <div class="btn-group"><a href="#" id="createnew" class="btn btn-default btn-sm"><i class="fa fa-plus"></i> Skapa ny auktoritet</a></div>
</div>
<form name="f" method="get" action="auth_finder.pl" class="clearfix">
 <input type="hidden" name="source" value="[% source | html %]" />
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="index" value="[% index | html %]" />
 <fieldset class="rows"><legend>Sökalternativ</legend>
 <ol><li>
 <span class="label">Auktoritetstyp: </span>
 [% authtypecode | html %]
 <input type="hidden" name="authtypecode" value="[% authtypecode | html %]" />
 </li>
 <li>
 <label for="mainmainentry">Sök huvudrubrik (endast $a): </label>
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainmainentry">
 [% IF ( operator_mainstr == 'contains' ) %]
 <option value="contains" selected="selected">innehåller</option>
 [% ELSE %]
 <option value="contains">innehåller</option>
 [% END %]
 [% IF ( operator_mainstr == 'start' ) %]
 <option value="start" selected="selected">börjar med</option>
 [% ELSE %]
 <option value="start">börjar med</option>
 [% END %]
 [% IF ( operator_mainstr == 'exact' ) %]
 <option value="exact" selected="selected">är exakt</option>
 [% ELSE %]
 <option value="exact">är exakt</option>
 [% END %]
 </select>
 <input id="value_mainstr" style="width:400px;" type="text" name="value_mainstr" value="[% value_mainstr | html %]" />
 <div id="yvaluecontainermainmainentry"></div>
 </li>

 <li>
 <label for="mainentry">Sök huvudrubrik: </label>
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainentry">
 [% IF ( operator_main == 'contains' ) %]
 <option value="contains" selected="selected">innehåller</option>
 [% ELSE %]
 <option value="contains">innehåller</option>
 [% END %]
 [% IF ( operator_main == 'start' ) %]
 <option value="start" selected="selected">börjar med</option>
 [% ELSE %]
 <option value="start">börjar med</option>
 [% END %]
 [% IF ( operator_main == 'exact' ) %]
 <option value="exact" selected="selected">är exakt</option>
 [% ELSE %]
 <option value="exact">är exakt</option>
 [% END %]
 </select>
 <input id="value_main" style="width:400px;" type="text" name="value_main" value="[% value_main | html %]" />
 <div id="yvaluecontainermainentry"></div>
 </li>
 <li>
 <label for="marclistheading">Sök alla rubriker: </label>
 <input type="hidden" name="marclist" value="match" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistheading">
 [% IF ( operator_match == 'contains' ) %]
 <option value="contains" selected="selected">innehåller</option>
 [% ELSE %]
 <option value="contains">innehåller</option>
 [% END %]
 [% IF ( operator_match == 'start' ) %]
 <option value="start" selected="selected">börjar med</option>
 [% ELSE %]
 <option value="start">börjar med</option>
 [% END %]
 [% IF ( operator_match == 'exact' ) %]
 <option value="exact" selected="selected">är exakt</option>
 [% ELSE %]
 <option value="exact">är exakt</option>
 [% END %]
 </select>
 <input id="value_match" style="width:400px;" type="text" name="value_match" value="[% value_match | html %]" />
 <div id="yvaluecontainermarclistheading"></div>
 </li>
 <li>
 <label for="marclistanywhere">Sök hela posten: </label>
 <input type="hidden" name="marclist" value="all" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistanywhere">
 [% IF ( operator_any == 'contains' ) %]
 <option value="contains" selected="selected">innehåller</option>
 [% ELSE %]
 <option value="contains">innehåller</option>
 [% END %]
 [% IF ( operator_any == 'start' ) %]
 <option value="start" selected="selected">börjar med</option>
 [% ELSE %]
 <option value="start">börjar med</option>
 [% END %]
 [% IF ( operator_any == 'exact' ) %]
 <option value="exact" selected="selected">är exakt</option>
 [% ELSE %]
 <option value="exact">är exakt</option>
 [% END %]
 </select>
 <input id="value_any" style="width:400px;" type="text" name="value_any" value="[% value_any | html %]" />
 <div id="yvaluecontainermarclist"></div>
 </li>
 <li>
 <label for="orderby">Sortera efter: </label>
 <select name="orderby" id="orderby">
 [% IF ( orderby == 'HeadingAsc' ) %]
 <option value="HeadingAsc" selected="selected">Rubrik A-Z</option>
 [% ELSE %]
 <option value="HeadingAsc">Rubrik A-Z</option>
 [% END %]
 [% IF ( orderby == 'HeadingDsc' ) %]
 <option value="HeadingDsc" selected="selected">Rubrik Z-A</option>
 [% ELSE %]
 <option value="HeadingDsc">Rubrik Z-A</option>
 [% END %]
 [% IF ( orderby == '' && op ) %]
 <option value="" selected="selected">Ingen</option>
 [% ELSE %]
 <option value="">Ingen</option>
 [% END %]
 </select>
 </li></ol></fieldset>
 [% IF source == 'auth' %]
 <fieldset class="rows"><legend>Information om förhållanden</legend>
 <ol>
 <li>
 <label for="special_relationship">Särskilt förhållande: </label>
 <select name="relationship" id="special_relationship">
 [% selected=relationship | html %] [% PROCESS selectoptionopen value='' %]Inget angivet</option>
 [% IF Koha.Preference('marcflavour') == 'MARC21' %] [% PROCESS selectoptionopen value='a' %]a - Tidigare rubrik</option>
 [% PROCESS selectoptionopen value='b' %]b - Senare rubrik</option>
 [% PROCESS selectoptionopen value='d' %]d - Akronym</option>
 [% PROCESS selectoptionopen value='f' %]f - Musikalisk komposition</option>
 [% PROCESS selectoptionopen value='g' %]g - Bredare term</option>
 [% PROCESS selectoptionopen value='h' %]h - Smalare term</option>
 [% PROCESS selectoptionopen value='i' %]i - Instruktionsfrasreferens i delfältet $i</option>
 [% PROCESS selectoptionopen value='n' %]n - Ej tillämpligt</option>
 [% PROCESS selectoptionopen value='r' %]r - Definition av förhållande i $i eller $4</option>
 [% PROCESS selectoptionopen value='t' %]t - Intilliggande överliggande fält</option>
 [% ELSIF Koha.Preference('marcflavour') == 'UNIMARC' %] [% PROCESS selectoptionopen value='a' %]a = tidigare namn</option>
 [% PROCESS selectoptionopen value='b' %]b = senare namn</option>
 [% PROCESS selectoptionopen value='c' %]c = officiellt namn</option>
 [% PROCESS selectoptionopen value='d' %]d = akronym / initial / förkortning</option>
 [% PROCESS selectoptionopen value='e' %]e = pseudonym</option>
 [% PROCESS selectoptionopen value='f' %]f = riktigt namn</option>
 [% PROCESS selectoptionopen value='g' %]g = bredare term eller namn</option>
 [% PROCESS selectoptionopen value='h' %]h = smalare term eller namn</option>
 [% PROCESS selectoptionopen value='i' %]i = religiöst namn</option>
 [% PROCESS selectoptionopen value='j' %]j = namn som gift</option>
 [% PROCESS selectoptionopen value='k' %]k = namn som ogift</option>
 [% PROCESS selectoptionopen value='l' %]l = delad pseudonym</option>
 [% PROCESS selectoptionopen value='m' %]m = sekulärt namn</option>
 [% PROCESS selectoptionopen value='n' %]n = annan regelform av ett namn</option>
 [% PROCESS selectoptionopen value='o' %]o = tillskrivet namn / vedertagen titel på ett verk</option>
 [% PROCESS selectoptionopen value='x' %]x = ej tillämpligt</option>
 [% PROCESS selectoptionopen value='z' %]z = annan</option>
 [% END %]
 </select>
 </li>
 </ol>
 </fieldset>
 [% END %]

 <nav class="navbar navbar-default fixed-bottom">
 <div class="container-fluid">
 <fieldset class="action">
 <input class="btn btn-primary" id="search" type="submit" value="Sök" />
 <input class="btn btn-default" id="clear-form" type="reset" value="Rensa formulär" />
 <button type="button" class="btn btn-default close_window">Stäng fönster</button>
 </fieldset>
 </div>
 </nav>
</form>
