[% PROCESS 'html_helpers.inc' %]
<ol>
 <li>
 [% IF field %]
 <span class="label">Namn: </span>
 [% field.name | html %]
 <input type="hidden" name="name" value="[% field.name | html %]">
 [% ELSE %]
 <label class="required" for="name">Namn: </label>
 <input type="text" name="name" id="name" class="required" required="required" />
 <span class="required">Obligatoriskt</span>
 [% END %]
 </li>
 <li>
 <label class="required" for="label">Etikett: </label>
 <input type="text" name="label" id="label" value="[% field.label | html %]" class="required" required="required" />
 <span class="required">Obligatoriskt</span>
 </li>
 <li>
 <label class="required" for="tagfield">MARC-fält: </label>
 <input type="text" id="tagfield" name="tagfield" maxlength="3" size="3" class="required" pattern="[a-zA-Z0-9]+" required="required" value="[% field.tagfield | html %]" />
 <span class="required">Obligatoriskt</span>
 </li>
 <li>
 <label for="tagsubfield">MARC-delfält: </label>
 <input type="text" id="tagsubfield" name="tagsubfield" pattern="[a-zA-Z0-9]+" maxlength="1" size="1" value="[% field.tagsubfield | html %]" />
 </li>
 <li>
 <label for="authorised_values_category">Kategori för auktoriserat värde: </label>
 <select id="authorised_values_category" name="authorised_values_category">
 <option value="">- Ingen -</option>
 [% PROCESS options_for_authorised_value_categories authorised_value_categories => AuthorisedValues.GetCategories( selected => field.authorised_values_category ) %]
 </select>
 </li>
</ol>
