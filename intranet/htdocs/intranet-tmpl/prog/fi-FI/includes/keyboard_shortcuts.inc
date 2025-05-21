[%- BLOCK keyboard_shortcut_descriptions -%]
 [% SWITCH shortcut_name %]
 [%- CASE 'insert_copyright' -%]<span>Lisää copyright-symboli (©)</span>
 [%- CASE 'insert_copyright_sound' -%]<span>Lisää copyright-symboli (℗) (äänitteet)</span>
 [%- CASE 'insert_delimiter' -%]<span>Lisää erotin (‡)</span>
 [%- CASE 'subfield_help' -%]<span>Hae ohje nykyiseen osakenttään</span>
 [%- CASE 'link_authorities' -%]<span>Linkitä kenttä auktoriteetteihin</span>
 [%- CASE 'delete_field' -%]<span>Poista kenttä ja kopioi se leikepöydälle</span>
 [%- CASE 'delete_subfield' -%]<span>Poista nykyinen osakenttä ja kopioi se leikepöydälle</span>
 [%- CASE 'new_line' -%]<span>Uusi kenttä seuraavalla rivillä</span>
 [%- CASE 'line_break' -%]<span>Lisää rivinvaihto</span>
 [%- CASE 'next_position' -%]<span>Siirrä seuraavaan paikkaan</span>
 [%- CASE 'prev_position' -%]<span>Palaa edelliseen paikkaan</span>
 [%- CASE 'toggle_keyboard' -%]<span>Tilanvaihtonäppäimet</span>
 [%- CASE 'copy_line' -%]<span>Kopioi tämä kenttä</span>
 [%- CASE 'copy_subfield' -%]<span>Kopioi tämä osakenttä</span>
 [%- CASE 'paste_line' -%]<span>Liitä valinta 'leikepöydältä'</span>
 [%- CASE 'insert_line' -%]<span>Kopioi tämä kenttä seuraavalle riville</span>
 [%- END -%]
[%- END -%]
