<option value="relevance">Osuvuuden mukaan</option>

<optgroup label="Suosio">
 
 [% IF ( sort_by == "popularity_dsc" ) %]
<option value="popularity_dsc" selected="selected">Suosion mukaan (eniten lainatut ensin)</option>
[% ELSE %]
 <option value="popularity_dsc">Suosion mukaan (eniten lainatut ensin)</option>
 [% END %]
[% IF ( sort_by == "popularity_asc" ) %]
<option value="popularity_asc" selected="selected">Suosion mukaan (vähiten lainatut ensin)</option>
[% ELSE %]
 <option value="popularity_asc">Suosion mukaan (vähiten lainatut ensin)</option>
 [% END %]

</optgroup>

<optgroup label="Tekijä">
 
 [% IF ( sort_by == "author_az" || sort_by == "author_asc" ) %]
<option value="author_az" selected="selected">Tekijän mukaan (nouseva)</option> 
[% ELSE %]
<option value="author_az">Tekijän mukaan (nouseva)</option>
 [% END %]
[% IF ( sort_by == "author_za" || sort_by == "author_dsc" ) %]
<option value="author_za" selected="selected">Tekijän mukaan (laskeva)</option>
[% ELSE %]
<option value="author_za">Tekijän mukaan (laskeva)</option>
 [% END %]

</optgroup>

<optgroup label="Luokka">
 
 [% IF ( sort_by == "call_number_asc" ) %]
<option value="call_number_asc" selected="selected">Luokka (nouseva)</option>
[% ELSE %]
 <option value="call_number_asc">Luokka (nouseva)</option>
[% END %]

[% IF ( sort_by == "call_number_dsc" ) %]
<option value="call_number_dsc" selected="selected">Luokka (laskeva)</option>
[% ELSE %]
 <option value="call_number_dsc">Luokka (laskeva)</option>
[% END %]

</optgroup>

<optgroup label="Päivämäärät">
 [% IF ( sort_by == "pubdate_dsc" ) %]
<option value="pubdate_dsc" selected="selected" >Julkaisuvuosi: uusimmasta vanhimpaan</option>
 [% ELSE %]
<option value="pubdate_dsc">Julkaisuvuosi: uusimmasta vanhimpaan</option>
[% END %]

[% IF ( sort_by == "pubdate_asc" ) %]
<option value="pubdate_asc" selected="selected" >Julkaisuvuosi: vanhimmasta uusimpaan</option>
[% ELSE %]
<option value="pubdate_asc">Julkaisuvuosi: vanhimmasta uusimpaan</option>
[% END %]

[% IF ( sort_by == "acqdate_dsc" ) %]
<option value="acqdate_dsc" selected="selected">Hankintapäivä: uusimmasta vanhimpaan</option>
[% ELSE %]
<option value="acqdate_dsc">Hankintapäivä: uusimmasta vanhimpaan</option>
 [% END %]

 [% IF ( sort_by == "acqdate_asc" ) %]
<option value="acqdate_asc" selected="selected">Hankintapäivä: vanhimmasta uusimpaan</option>
[% ELSE %]
<option value="acqdate_asc">Hankintapäivä: vanhimmasta uusimpaan</option>
 [% END %]
</optgroup>

<optgroup label="Nimeke">
 [% IF ( sort_by == "title_az" || sort_by == "title_asc" ) %]
<option value="title_az" selected="selected">Nimeke (A-Z)</option>
 [% ELSE %]
<option value="title_az">Nimeke (A-Z)</option>
 [% END %]
 [% IF ( sort_by == "title_za" || sort_by == "title_dsc" ) %]
<option value="title_za" selected="selected">Nimeke (Z-A)</option> 
 [% ELSE %]
<option value="title_za">Nimeke (Z-A)</option>
[% END %]
</optgroup>
