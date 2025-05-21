[% USE Koha %]
[% USE Branches %]
[% PROCESS 'html_helpers.inc' %]
[% IF context == "main" %]
 <div class="row">
 <div class="col-sm-6">
[% END %]
<ol>
 <li><label for="title">Nimeke: </label> <input type="text" name="title" id="title" value="[% filters.title | html %]" /></li>
 <li><label for="author">Tekijä: </label> <input type="text" name="author" id="author" value="[% filters.author | html %]" /></li>
 <li><label for="isbn">ISBN: </label> <input type="text" name="isbn" id="isbn" value="[% filters.isbn | html %]" /></li>
 <li><label for="isbn">ISSN: </label> <input type="text" name="issn" id="issn" value="[% filters.issn | html %]" /></li>
 [% IF Koha.Preference('marcflavour') == 'UNIMARC' %]
 <li><label for="ean">EAN: </label> <input type="text" name="ean" id="ean" value="[% filters.ean | html %]" /></li>
 [% END %]
 <li><label for="name">Toimittaja: </label> <input type="text" name="name" id="name" value="[% filters.name | html %]" /></li>
 <li><label for="basket">Tilauskori: </label> <input type="text" name="basket" id="basket" value="[% filters.basket | html %]" /></li>
 <li><label for="internalnote">Sisäinen huomautus: </label> <input type="text" name="internalnote" id="internalnote" value="[% filters.internalnote | html %]" /></li>
 <li><label for="vendornote">Huomautus toimittajalle: </label> <input type="text" name="vendornote" id="vendornote" value="[% filters.vendornote | html %]" /></li>
 <li><label for="basket_creators">Tilauskorin luoja: </label>
 <input autocomplete="off" id="find_patron" type="text" class="noEnterSubmit" />
 <div>
 <div id="basket_creators" style="float:left;"></div>
 </div>
 </li>
 <li>
 <label for="managing_library">Käsittelevä kirjasto: </label>
 <select name="managing_library" id="managing_library">
 <option value="">Kaikki kirjastot</option>
 [% PROCESS options_for_libraries libraries => Branches.all(selected => '') %]
 </select>
 </li>
[% IF context == "main" %]
 </ol>
 </div>
 <div class="col-sm-6">
 <ol>
[% END %]
 <li><label for="booksellerinvoicenumber ">Toimittajan laskun numero: </label> <input type="text" name="booksellerinvoicenumber" id="booksellerinvoicenumber" value="[% filters.booksellerinvoicenumber | html %]" /></li>
 <li>
 <label for="basketgroupname">Tilausryhmä:</label>
 <input type="text" name="basketgroupname" id="basketgroupname" value="[% filters.basketgroupname | html %]" />
 </li>
 [% INCLUDE 'additional-fields-entry.inc' available=available_additional_fields values=additional_field_filters wrap_fieldset=0 search_form=1 %]
 <li>
 <label for="ordernumber">Tilausrivi:</label>
 <input type="text" name="ordernumber" id="ordernumber" value="[% filters.ordernumber | html %]" />
 </li>
 <li class="radio">
 <label for="search_children_too">
 [% IF filters.search_children_too %]
 <input type="checkbox" name="search_children_too" id="search_children_too" value="1" checked="checked" />
 [% ELSE %]
 <input type="checkbox" name="search_children_too" id="search_children_too" value="1" />
 [% END %] Näytä myös osakohteet </label>
 </li>

 <li>
 <label for="orderstatus">Hankinnan tila: </label>
 <select name="orderstatus" id="orderstatus">
 [% IF filters.orderstatus == "" %]
 <option value="">Kaikki muu paitsi peruutetut</option>
 [% ELSE %]
 <option value="" selected="selected">Kaikki muu paitsi peruutetut</option>
 [% END %]
 [% IF filters.orderstatus == "any" %]
 <option value="any" selected="selected">Kaikki tilat</option>
 [% ELSE %]
 <option value="any">Kaikki tilat</option>
 [% END %]
 [% IF filters.orderstatus == "new" %]
 <option value="new" selected="selected">Uusi</option>
 [% ELSE %]
 <option value="new">Uusi</option>
 [% END %]
 [% IF filters.orderstatus == "ordered" %]
 <option value="ordered" selected="selected">Tilattu</option>
 [% ELSE %]
 <option value="ordered">Tilattu</option>
 [% END %]
 [% IF filters.orderstatus == "partial" %]
 <option value="partial" selected="selected">Osittain vastaanotettu</option>
 [% ELSE %]
 <option value="partial">Osittain vastaanotettu</option>
 [% END %]
 [% IF filters.orderstatus == "complete" %]
 <option value="complete" selected="selected">Vastaanotettu</option>
 [% ELSE %]
 <option value="complete">Vastaanotettu</option>
 [% END %]
 [% IF filters.orderstatus == "cancelled" %]
 <option value="cancelled" selected="selected">Peruutettu</option>
 [% ELSE %]
 <option value="cancelled">Peruutettu</option>
 [% END %]
 </select>
 </li>
 <li class="radio">
 <label class="yesno" for="is_standing">
 [% IF filters.is_standing %]
 <input type="checkbox" name="is_standing" id="is_standing" value="1" checked="checked" />
 [% ELSE %]
 <input type="checkbox" name="is_standing" id="is_standing" value="1" />
 [% END %] Kestotilaus </label>
 </li>
 <li>
 <label for="fund">Tili: </label>
 <select name="budget" id="fund">
 <option value="">Kaikki tilit</option>
 [% FOREACH bp_loo IN bp_loop %]
 <optgroup label="[% bp_loo.budget_period_description | html %]">
 [% FOREACH h_loo IN bp_loo.hierarchy %]
 [% IF h_loo.budget_id == filters.budget %]
 <option type="text" value="[% h_loo.budget_id | html %]" branchcode="[% h_loo.budget_branchcode | html %]" selected="selected">
 [% ELSE %]
 <option type="text" value="[% h_loo.budget_id | html %]" branchcode="[% h_loo.budget_branchcode | html %]">
 [% END %]
 [% h_loo.budget_display_name | html %]
 </option>
 [% END %]
 </optgroup>
 [% END %]
 </select>
 </li>

 <li><label for="from">Alkaen: </label>
 <input type="text" size="10" id="from" name="from" value="[% filters.from_placed_on | html %]" class="flatpickr" data-date_to="to" />
 <div class="hint">[% INCLUDE 'date-format.inc' %]</div>
 </li>
 <li><label for="to">Saakka: </label>
 <input type="text" size="10" id="to" name="to" value="[% filters.to_placed_on | html %]" class="flatpickr" />
 <div class="hint">[% INCLUDE 'date-format.inc' %]</div>
 </li>
</ol>
[% IF context == "main" %]
 </div>
 </div>
[% END %]
