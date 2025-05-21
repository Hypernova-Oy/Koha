[% USE Koha %]
[% USE Branches %]
[% PROCESS 'html_helpers.inc' %]
[% SET AllPublicBranches = Branches.all(  search_params => { public => 1 }, selected => branch ) %]

<div id="search-facets">
 <form method="get" action="/cgi-bin/koha/opac-topissues.pl">
 <h2><a href="#" class="menu-collapse-toggle">Förfina din sökning</a></h2>
 <ul class="menu-collapse">
 <li><label for="limit">Visa de översta </label>
 <select name="limit" id="limit">
 [% IF ( limit == 10 ) %]<option value ="10" selected="selected">10 titlar</option>[% ELSE %]<option value="10">10 titlar</option>[% END %]
 [% IF ( limit == 15 ) %]<option value ="15" selected="selected">15 titlar</option>[% ELSE %]<option value="15">15 titlar</option>[% END %]
 [% IF ( limit == 20 ) %]<option value ="20" selected="selected">20 titlar</option>[% ELSE %]<option value="20">20 titlar</option>[% END %]
 [% IF ( limit == 30 ) %]<option value ="30" selected="selected">30 titlar</option>[% ELSE %]<option value="30">30 titlar</option>[% END %]
 [% IF ( limit == 40 ) %]<option value ="40" selected="selected">40 titlar</option>[% ELSE %]<option value="40">40 titlar</option>[% END %]
 [% IF ( limit == 50 ) %]<option value ="50" selected="selected">50 titlar</option>[% ELSE %]<option value="50">50 titlar</option>[% END %]
 [% IF ( limit == 100 ) %]<option value ="100" selected="selected">100 titlar</option>[% ELSE %]<option value="100">100 titlar</option>[% END %]
 </select></li>

 [% IF AllPublicBranches.size > 1 %]
 <li>
 <label for="branch">Från: </label>
 <select name="branch" id="branch">
 <option value="">Alla bibliotek</option>
 [% PROCESS options_for_libraries libraries => AllPublicBranches %]
 </select>
 </li>
 [% END %]

 [% OpacAdvancedSearchTypes = Koha.Preference('OpacAdvancedSearchTypes').split('\|') %]
 [% IF OpacAdvancedSearchTypes.grep('^itemtypes$').size %]
 <li>
 <label for="itemtype">Begränsa till: </label>
 <select name="itemtype" id="itemtype">
 <option value="">Alla exemplartyper</option>
 [% FOREACH itemtype IN ItemTypes.Get() %]
 [% IF itemtype.itemtype == selected_itemtype %]
 <option value="[% itemtype.itemtype | html %]" selected="selected">
 [% ELSE %]
 <option value="[% itemtype.itemtype | html %]">
 [% END %]
 [% itemtype.translated_description | html %]
 </option>
 [% END %]
 </select>
 </li>
 [% END %]

 [% IF OpacAdvancedSearchTypes.grep('^ccode$').size %]
 <li>
 <label for="ccode">Begränsa till:</label>
 <select name="ccode" id="ccode">
 <option value="">Alla avdelningar</option>
 [% FOREACH ccode IN AuthorisedValues.Get('CCODE', 1) %]
 [% IF ccode.authorised_value == selected_ccode %]
 <option value="[% ccode.authorised_value | html %]" selected="selected">
 [% ELSE %]
 <option value="[% ccode.authorised_value | html %]">
 [% END %]
 [% ccode.lib | html %]
 </option>
 [% END %]
 </select>
 </li>
 [% END %]

 <li><label for="timeLimit">Förvärvad under senaste:</label>
 <select name="timeLimit" id="timeLimit">
 [% IF ( timeLimit == 3 ) %]
 <option value="3" selected="selected">3 månader</option>
 [% ELSE %]
 <option value="3">3 månader</option>
 [% END %]
 [% IF ( timeLimit == 6 ) %]
 <option value="6" selected="selected">6 månader</option>
 [% ELSE %]
 <option value="6">6 månader</option>
 [% END %]
 [% IF ( timeLimit == 12 ) %]
 <option value="12" selected="selected">12 månader</option>
 [% ELSE %]
 <option value="12">12 månader</option>
 [% END %]
 [% IF ( timeLimit == 999 ) %]
 <option value="999" selected="selected">Ingen begränsning</option>
 [% ELSE %]
 <option value="999">Ingen begränsning</option>
 [% END %]
 </select></li>
 <li>
 <input type="hidden" name="do_it" value="1" />
 <input class="btn btn-primary" type="submit" value="Skicka" />
 </li>
 </ul>
 </form>
</div>
