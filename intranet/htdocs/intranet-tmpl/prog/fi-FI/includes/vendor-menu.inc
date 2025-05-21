[% IF ( booksellerid ) %]
<div id="menu">
 <ul>
 [% IF ( CAN_user_acquisition_order_manage ) %]<li><a href="/cgi-bin/koha/acqui/booksellers.pl?booksellerid=[% booksellerid | uri %]">Tilauskorit</a></li>[% END %]
 [% IF ( CAN_user_acquisition_group_manage ) %]<li><a href="/cgi-bin/koha/acqui/basketgroup.pl?booksellerid=[% booksellerid | uri %]">Tilausryhmät</a></li>[% END %]
 [% IF ( CAN_user_acquisition_contracts_manage ) %]<li><a href="/cgi-bin/koha/admin/aqcontract.pl?booksellerid=[% booksellerid | uri %]">Sopimukset</a></li>[% END %]
 [% IF ( CAN_user_acquisition_issue_manage ) %]<li><a href="/cgi-bin/koha/acqui/vendor_issues.pl?booksellerid=[% booksellerid | uri %]">Toimittajan ongelmat</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/invoices.pl?supplierid=[% booksellerid | uri %]&amp;op=do_search">Laskut</a></li>
 [% IF ( CAN_user_acquisition_order_manage ) %][% IF ( basketno ) %]
 <li><a href="/cgi-bin/koha/acqui/uncertainprice.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]&amp;owner=1">Vahvistamattomat hinnat</a></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/acqui/uncertainprice.pl?booksellerid=[% booksellerid | uri %]&amp;owner=1">Vahvistamattomat hinnat</a></li>
 [% END %] [% END %]
 </ul>
</div>
[% END %]
