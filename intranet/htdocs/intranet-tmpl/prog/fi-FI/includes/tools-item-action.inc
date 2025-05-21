[% IF action == 'ignore' AND num_items == 0 %] Haulla ei löytynyt niteitä <input type ="hidden" name="item_action" value="ignore">
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
 [% END %] Lisää kohteet aina</option>
 [% IF ( action == 'add_only_for_matches' ) %]
 <option value="add_only_for_matches" selected="selected">
 [% ELSE %]
 <option value="add_only_for_matches">
 [% END %] Lisää niteitä vain, jos vastaava tietue löytyy</option>
 [% IF ( action == 'add_only_for_new' ) %]
 <option value="add_only_for_new" selected="selected">
 [% ELSE %]
 <option value="add_only_for_new">
 [% END %] Lisää niteitä vain, jos vastaavaa tietuetta ei löydy</option>
 [% IF ( action == 'replace' ) %]
 <option value="replace" selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] Korvaa niteet, jos vastaava tietue löytyy</option>
 [% IF ( action == 'ignore' ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] Hylkää kohteet</option>
 </select>
[% END %]
