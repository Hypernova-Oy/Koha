<option value="relevance">Relevans</option>
<optgroup label="Popularitet">
 [% IF ( sort_by == "popularity_dsc" ) %]
 <option value="popularity_dsc" selected="selected">Popularitet (mest till minst)</option>
 [% ELSE %]
 <option value="popularity_dsc">Popularitet (mest till minst)</option>
 [% END %]
 [% IF ( sort_by == "popularity_asc" ) %]
 <option value="popularity_asc" selected="selected">Popularitet (minst till mest)</option>
 [% ELSE %]
 <option value="popularity_asc">Popularitet (minst till mest)</option>
 [% END %]
</optgroup>
<optgroup label="Författare">
 [% IF ( sort_by == "author_az" || sort_by == "author_asc" ) %]
 <option value="author_az" selected="selected">Författare (A-Ö)</option>
 [% ELSE %]
 <option value="author_az">Författare (A-Ö)</option>
 [% END %]
 [% IF ( sort_by == "author_za" || sort_by == "author_dsc" ) %]
 <option value="author_za" selected="selected">Författare (Ö-A)</option>
 [% ELSE %]
 <option value="author_za">Författare (Ö-A)</option>
 [% END %]
</optgroup>
<optgroup label="Hyllsignatur">
 [% IF ( sort_by == "call_number_asc" ) %]
 <option value="call_number_asc" selected="selected">Hyllsignatur (0-9 till A-Ö)</option>
 [% ELSE %]
 <option value="call_number_asc">Hyllsignatur (0-9 till A-Ö)</option>
 [% END %]
 [% IF ( sort_by == "call_number_dsc" ) %]
 <option value="call_number_dsc" selected="selected">Hyllsignatur (Ö-A till 9-0)</option>
 [% ELSE %]
 <option value="call_number_dsc">Hyllsignatur (Ö-A till 9-0)</option>
 [% END %]
</optgroup>
<optgroup label="Datum">
 [% IF ( sort_by == "pubdate_dsc" ) %]
 <option value="pubdate_dsc" selected="selected">Datum för utgivning/copyright: nyast till äldst</option>
 [% ELSE %]
 <option value="pubdate_dsc">Datum för utgivning/copyright: nyast till äldst</option>
 [% END %]
 [% IF ( sort_by == "pubdate_asc" ) %]
 <option value="pubdate_asc" selected="selected">Datum för utgivning/copyright: äldst till nyast</option>
 [% ELSE %]
 <option value="pubdate_asc">Datum för utgivning/copyright: äldst till nyast</option>
 [% END %]
 [% IF ( sort_by == "acqdate_dsc" ) %]
 <option value="acqdate_dsc" selected="selected">Förvärvsdatum: nyaste till äldsta</option>
 [% ELSE %]
 <option value="acqdate_dsc">Förvärvsdatum: nyaste till äldsta</option>
 [% END %]
 [% IF ( sort_by == "acqdate_asc" ) %]
 <option value="acqdate_asc" selected="selected">Förvärvsdatum: äldsta till nyaste</option>
 [% ELSE %]
 <option value="acqdate_asc">Förvärvsdatum: äldsta till nyaste</option>
 [% END %]
</optgroup>
<optgroup label="Titel">
 [% IF ( sort_by == "title_az" || sort_by == "title_asc" ) %]
 <option value="title_az" selected="selected">Titel (A-Z)</option>
 [% ELSE %]
 <option value="title_az">Titel (A-Z)</option>
 [% END %]
 [% IF ( sort_by == "title_za" || sort_by == "title_dsc" ) %]
 <option value="title_za" selected="selected">Titel (Z-A)</option>
 [% ELSE %]
 <option value="title_za">Titel (Z-A)</option>
 [% END %]
</optgroup>
