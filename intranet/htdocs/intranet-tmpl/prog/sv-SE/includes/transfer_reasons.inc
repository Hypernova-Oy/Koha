[%- BLOCK transfer_reason -%]
 [%- SWITCH transfer.reason -%]
 [%- CASE 'Manual'                    -%]<span>Manuell</span>
 [%- CASE 'StockrotationAdvance'      -%]<span>Beståndsrotation - nästa steg</span>
 [%- CASE 'StockrotationRepatriation' -%]<span>Specifikation av roterande samling</span>
 [%- CASE 'ReturnToHome'              -%]<span>Returneras automatiskt till hembiblioteket</span>
 [%- CASE 'ReturnToHolding'           -%]<span>Returneras automatiskt till aktuellt bibliotek</span>
 [%- CASE 'RotatingCollection'        -%]<span>Roterande samling</span>
 [%- CASE 'Reserve'                   -%]<span>Reservation</span>
 [%- CASE 'LostReserve'               -%]<span>Reservation förlorad</span>
 [%- CASE 'CancelReserve'             -%]<span>Reservation borttagen</span>
 [%- CASE                             -%]<span>[% transfer.reason | html %]</span>
 [%- END -%]
[%- END -%]
