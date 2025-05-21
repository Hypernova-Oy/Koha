[%- BLOCK transfer_reason -%]
 [%- SWITCH transfer.reason -%]
 [%- CASE 'Manual'                    -%]<span>Käsin lisätty</span>
 [%- CASE 'StockrotationAdvance'      -%]<span>Siirretään kiertoon</span>
 [%- CASE 'StockrotationRepatriation' -%]<span>Palautetaan kierrosta</span>
 [%- CASE 'ReturnToHome'              -%]<span>Automaattinen palautus kotikirjastoon</span>
 [%- CASE 'ReturnToHolding'           -%]<span>Automaattinen palautus varaustilaan</span>
 [%- CASE 'RotatingCollection'        -%]<span>Siirtokokoelma</span>
 [%- CASE 'Reserve'                   -%]<span>Varaus</span>
 [%- CASE 'LostReserve'               -%]<span>Varaus kadonnut</span>
 [%- CASE 'CancelReserve'             -%]<span>Varaus peruutettu</span>
 [%- CASE                             -%]<span>[% transfer.reason | html %]</span>
 [%- END -%]
[%- END -%]
