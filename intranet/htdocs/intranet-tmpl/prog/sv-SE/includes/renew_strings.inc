[% SWITCH error %]
[% CASE 'no_item' %]
 <span>Inget matchande exemplar hittades</span>
[% CASE 'no_checkout' %]
 <span>Exemplaret är inte utlånat</span>
[% CASE 'too_soon' %]
 <span>Exemplar kan inte lånas om ännu</span>
[% CASE 'too_many' %]
 <span>Du har nått gränsen för max antal omlån för detta exemplar</span>
[% CASE 'auto_too_soon' %]
 <span>Detta exemplar är schemalagt för automatiskt omlån och kan inte lånas om</span>
[% CASE 'auto_too_late' %]
 <span>Har schemalagts för automatiskt omlån och kan inte längre lånas om</span>
[% CASE 'auto_account_expired' %]
 <span>Har schemalagts för automatiskt omlån och kan inte lånas om, eftersom giltighetstiden för låntagarkontot har gått ut</span>
[% CASE 'auto_renew' %]
 <span>Schemalagd för automatiskt omlån</span>
[% CASE 'auto_too_much_oweing' %]
 <span>Har schemalagts för automatiskt omlån och kan inte lånas om, eftersom låntagaren har för många obetalda avgifter</span>
[% CASE 'on_reserve' %]
 <span>Exemplaret är reserverat för en annan låntagare</span>
[% CASE 'patron_restricted' %]
 <span>Låntagaren har begränsningar just nu</span>
[% CASE 'item_denied_renewal' %]
 <span>Omlån är ej tillåtet för detta exemplar</span>
[% CASE 'onsite_checkout' %]
 <span>Exemplaret är utlånat på plats</span>
[% CASE 'has_fine' %]
 <span>Låntagare har obetalda avgifter</span>
[% CASE 'item_issued_to_other_patron'%]
 <span>Exemplaret är redan utlånat till annan låntagare</span>
[% CASE %]
 <span>Okänt fel</span>
[% END %]
