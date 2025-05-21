[% IF ( class_name ) %]
 <select name="overlay_action" id="overlay_action" class="[% class_name | html %]">
[% ELSE %]
 <select name="overlay_action" id="overlay_action">
[% END %]
 [% IF ( action == 'replace' ) %]
 <option value="replace"  selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] Ersätt befintlig post med inkommande post</option>
 [% IF ( action == 'create_new' ) %]
 <option value="create_new" selected="selected">
 [% ELSE %]
 <option value="create_new">
 [% END %] Lägg till inkommande post</option>
 [% IF ( action == 'ignore' ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] Ignorera inkommande poster (dess exemplar kan bearbetas)</option>
</select>
