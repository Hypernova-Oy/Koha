[%- BLOCK keyboard_shortcut_descriptions -%]
 [% SWITCH shortcut_name %]
 [%- CASE 'insert_copyright' -%]<span>Lägg till copyrightsymbol (©)</span>
 [%- CASE 'insert_copyright_sound' -%]<span>Lägg till copyrightsymbol (℗) (ljudinspelningar)</span>
 [%- CASE 'insert_delimiter' -%]<span>Infoga avgränsare (‡)</span>
 [%- CASE 'subfield_help' -%]<span>Hjälp om aktuellt delfält</span>
 [%- CASE 'link_authorities' -%]<span>Länkfält till auktoriteter</span>
 [%- CASE 'delete_field' -%]<span>Ta bort aktuellt fält och kopiera till urklipp</span>
 [%- CASE 'delete_subfield' -%]<span>Ta bort aktuellt delfält och kopiera till urklipp</span>
 [%- CASE 'new_line' -%]<span>Nytt fält på nästa rad</span>
 [%- CASE 'line_break' -%]<span>Infoga radbrytning</span>
 [%- CASE 'next_position' -%]<span>Flytta till nästa position</span>
 [%- CASE 'prev_position' -%]<span>Flytta till föregående position</span>
 [%- CASE 'toggle_keyboard' -%]<span>Växla tangentbord</span>
 [%- CASE 'copy_line' -%]<span>Kopiera aktuellt fält</span>
 [%- CASE 'copy_subfield' -%]<span>Kopiera aktuellt delfält</span>
 [%- CASE 'paste_line' -%]<span>Klistra in objekt från 'urklipp'</span>
 [%- CASE 'insert_line' -%]<span>Kopiera aktuellt fält på nästa rad</span>
 [%- END -%]
[%- END -%]
