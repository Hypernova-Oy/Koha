[% USE AuthorisedValues %]
[% USE Branches %]
[% USE Koha %]
[% USE KohaDates %]

[% SET itemavailable = 1 %]

[% IF ( item.itemlost ) %]
 [% SET itemavailable = 0 %]
 [% itemlost_description = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.itemlost', authorised_value => item.itemlost ) %]
 [% IF ( itemlost_description ) %]
 <span class="item-status lost">[% itemlost_description | html %]</span>
 [% ELSE %]
 <span class="item-status lost">Kadonnut</span>
 [% END %]
[% END %]

[% checkout = item.checkout %]
[% IF ( checkout ) %]
 [% SET itemavailable = 0 %]
 [% IF checkout.onsite_checkout %]
 <span class="item-status checkedout">Tällä hetkellä paikalliskäytössä asiakkaalla [% INCLUDE 'patron-title.inc' patron=checkout.patron hide_patron_infos_if_needed=1 %]</span>
 [% ELSE %]
 <span class="item-status checkedout">Lainattu asiakkaalle [% INCLUDE 'patron-title.inc' patron=checkout.patron hide_patron_infos_if_needed=1 %]</span>
 [% END %]
 <span class="item-status due">Eräpäivä: [% checkout.date_due | $KohaDates %]</span>
[% END %]

[% transfer = item.get_transfer %]
[% IF ( transfer.in_transit ) %]
 [% SET itemavailable = 0 %]
 <span class="item-status intransit">Kuljetettavana kirjastosta [% Branches.GetName( transfer.frombranch ) | html %] kirjastoon [% Branches.GetName( transfer.tobranch ) | html %] [% transfer.datesent | $KohaDates %]</span>
[% END %]

[% IF ( item.withdrawn ) %]
 [% SET itemavailable = 0 %]
 [% withdrawn_description = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.withdrawn', authorised_value => item.withdrawn ) %]
 [% IF withdrawn_description %]
 <span class="item-status withdrawn">[% withdrawn_description | html %]</span>
 [% ELSE %]
 <span class="item-status withdrawn">Pois kierrosta</span>
 [% END %]
[% END %]

[% IF ( item.effective_not_for_loan_status ) %]
 [% SET itemavailable = 0 %]
 [% notforloan_description = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.notforloan', authorised_value => item.effective_not_for_loan_status ) %]
 [% IF notforloan_description %]
 <span class="item-status notforloan">[% notforloan_description | html %]</span>
 [% ELSE %]
 <span class="item-status notforloan">Ei lainattavissa</span>
 [% END %]
[% END %]

[% IF ( item.damaged ) %]
 [% SET itemavailable = 0 %]
 [% damaged_description = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.damaged', authorised_value => item.damaged ) %]
 [% IF damaged_description %]
 <span class="item-status damaged">[% damaged_description | html %]</span>
 [% ELSE %]
 <span class="item-status damaged">Vahingoittunut</span>
 [% END %]
[% END %]

[% IF item.has_pending_hold %]
 [% SET itemavailable = 0 %]
 <span class="item-status pendinghold">Varaus</span>
[% END %]

[% hold = item.holds.next %]
[% IF hold %]
 [% IF hold.waitingdate %]
 [% SET itemavailable = 0 %]
 <span class="item-status holdwaiting">Odottaa kirjastossa [% Branches.GetName(hold.get_column('branchcode')) | html %] [% hold.waitingdate | $KohaDates %] lähtien.</span>
 [% ELSE %]
 <span class="item-status itemhold">Nidevaraus (tehty [% hold.reservedate | $KohaDates %]) on kuljetettava kirjastoon [% Branches.GetName(hold.get_column('branchcode')) | html %].</span>
 [% END %]
 [% IF Koha.Preference('canreservefromotherbranches') %]
 <span class="item-status holdfor">Varaus: [% INCLUDE 'patron-title.inc' patron=hold.borrower hide_patron_infos_if_needed=1 %]</span>
 [% END %]
 </span>
[% END %]

[% IF ( itemavailable ) %]
 <span class="item-status available">Saatavana</span>
[% END %]

[% IF ( item.restricted ) %]
 [% restricted_description = AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.restricted', authorised_value => item.restricted ) %]
 [% IF restricted_description %]
 <span class="item-status restricted">[% restricted_description | html %]</span>
 [% ELSE %]
 <span class="item-status restricted">Rajoitettu</span>
 [% END %]
[% END %]
