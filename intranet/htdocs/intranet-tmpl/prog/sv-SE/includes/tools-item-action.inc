[% IF action == 'ignore' AND num_items == 0 %] Inga exemplar hittades under förberedning <input type ="hidden" name="item_action" value="ignore">
[% ELSE %]
 [% IF ( class_name ) %]
 <select name="item_action" id="item_action" class="[% class_name | html %]">
 [% ELSE %]
 <select name="item_action" id="item_action">
 [% END %]
 [% IF ( action == 'always_add' ) %]
 <option value="always_add" selected="selected">
 [% ELSE %]
 <option value="always_add">
 [% END %] Lägg alltid till exemplar</option>
 [% IF ( action == 'add_only_for_matches' ) %]
 <option value="add_only_for_matches" selected="selected">
 [% ELSE %]
 <option value="add_only_for_matches">
 [% END %] Lägg till exemplar endast om matchande bibliografisk information hittades</option>
 [% IF ( action == 'add_only_for_new' ) %]
 <option value="add_only_for_new" selected="selected">
 [% ELSE %]
 <option value="add_only_for_new">
 [% END %] Lägg till exemplar endast om ingen matchande bibliografisk information hittades</option>
 [% IF ( action == 'replace' ) %]
 <option value="replace" selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] Ersätt exemplar om matchande bib hittades (endast för befintliga exemplar)</option>
 [% IF ( action == 'ignore' ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] Ignorera exemplar</option>
 </select>
[% END %]
