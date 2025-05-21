[% USE Branches %]
[% USE Registers %]
<div id="navmenu">
 <div id="navmenulist">
 [% IF ( CAN_user_cash_management_cashup || CAN_user_cash_management_anonymous_refund ) %]
 <h5>Kassan hallinta</h5>
 <ul>
 <li><a href="/cgi-bin/koha/pos/pay.pl">Myyntipiste</a></li>
 [% IF !(Registers.session_register_name == '') %]
 <li><a href="/cgi-bin/koha/pos/register.pl">Tapahtumahistoria [% Registers.session_register_name | html %]</a></li>
 [% END %]
 <li><a href="/cgi-bin/koha/pos/registers.pl">Tilitysten yhteenveto kirjastossa [% Branches.GetLoggedInBranchname | html %]</a></li>
 </ul>
 [% END %]
 [% IF ( CAN_user_parameters_manage_cash_registers || CAN_user_parameters_manage_accounts) %]
 <h5>Ylläpito</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_cash_registers ) %]
 <li><a href="/cgi-bin/koha/admin/cash_registers.pl">Määritä kassoja</a></li>
 [% END %]

 [% IF ( CAN_user_parameters_manage_accounts ) %]
 <li><a href="/cgi-bin/koha/admin/debit_types.pl">Määritä myytävät tuotteet</a></li>
 [% END %]
 </ul>
 [% END %]
 </div>
</div>
