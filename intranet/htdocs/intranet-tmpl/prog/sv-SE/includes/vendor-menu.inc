[% IF ( booksellerid ) %]
<div id="menu">
 <ul>
 [% IF ( CAN_user_acquisition_order_manage ) %]<li><a href="/cgi-bin/koha/acqui/booksellers.pl?booksellerid=[% booksellerid | uri %]">Korgar</a></li>[% END %]
 [% IF ( CAN_user_acquisition_group_manage ) %]<li><a href="/cgi-bin/koha/acqui/basketgroup.pl?booksellerid=[% booksellerid | uri %]">Korggrupper</a></li>[% END %]
 [% IF ( CAN_user_acquisition_contracts_manage ) %]<li><a href="/cgi-bin/koha/admin/aqcontract.pl?booksellerid=[% booksellerid | uri %]">Avtal</a></li>[% END %]
 [% IF ( CAN_user_acquisition_issue_manage ) %]<li><a href="/cgi-bin/koha/acqui/vendor_issues.pl?booksellerid=[% booksellerid | uri %]">Leverantörsärenden</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/invoices.pl?supplierid=[% booksellerid | uri %]&amp;op=do_search">Fakturor</a></li>
 [% IF ( CAN_user_acquisition_order_manage ) %][% IF ( basketno ) %]
 <li><a href="/cgi-bin/koha/acqui/uncertainprice.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]&amp;owner=1">Osäkra priser</a></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/acqui/uncertainprice.pl?booksellerid=[% booksellerid | uri %]&amp;owner=1">Osäkra priser</a></li>
 [% END %] [% END %]
 </ul>
</div>
[% END %]
