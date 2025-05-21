[% SWITCH error %]
[% CASE 'no_item' %]
 <span>Vastaavaa nidettä ei löytynyt</span>
[% CASE 'no_checkout' %]
 <span>Nide ei ole lainassa</span>
[% CASE 'too_soon' %]
 <span>Ei voida vielä uusia</span>
[% CASE 'too_many' %]
 <span>Lainan uusimiskerrat ovat tulleet täyteen</span>
[% CASE 'auto_too_soon' %]
 <span>Ajastettu automaattista uusintaa varten. Ei voida vielä uusia.</span>
[% CASE 'auto_too_late' %]
 <span>Ajastettu automaattista uusintaa varten. Ei voitu enää uusia</span>
[% CASE 'auto_account_expired' %]
 <span>Niteen uusinta on ajastettu, mutta sitä ei voi uusia, koska asiakkaan kirjastokortti on vanhentunut</span>
[% CASE 'auto_renew' %]
 <span>Ajastettu automaattista uusintaa varten</span>
[% CASE 'auto_too_much_oweing' %]
 <span>Niteen uusinta on ajastettu, mutta sitä ei voi uusia, koska asiakkaalla on liikaa maksamattomia maksuja</span>
[% CASE 'on_reserve' %]
 <span>Tämä aineisto varattu toiselle asiakkaalle</span>
[% CASE 'patron_restricted' %]
 <span>Asiakkaalla on rajoitus</span>
[% CASE 'item_denied_renewal' %]
 <span>Uusinta ei sallittu</span>
[% CASE 'onsite_checkout' %]
 <span>On-site-laina</span>
[% CASE 'has_fine' %]
 <span>Niteeseen kohdistuu maksamaton maksu</span>
[% CASE 'item_issued_to_other_patron'%]
 <span>Nide on jo lainattu toiselle asiakkaalle</span>
[% CASE %]
 <span>Tuntematon virhe</span>
[% END %]
