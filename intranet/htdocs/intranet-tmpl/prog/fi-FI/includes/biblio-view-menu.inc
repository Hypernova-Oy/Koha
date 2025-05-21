[% USE Koha %]
[% USE Biblio %]
[% SET biblio_object_id = biblio.biblionumber %]

<div id="menu">
 <ul>
 [%- IF ( detailview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% biblio_object_id | url  %]">Perustiedot</a>
 </li>

 [%- IF Koha.Preference('viewMARC') -%]
 [%- IF ( marcview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/catalogue/MARCdetail.pl?biblionumber=[% biblio_object_id | url  %]">MARC</a>
 </li>
 [%- END -%]

 [%- IF Koha.Preference('viewLabeledMARC') -%]
 [%- IF ( labeledmarcview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/catalogue/labeledMARCdetail.pl?biblionumber=[% biblio_object_id | url  %]">Otsikoitu MARC</a>
 </li>
 [%- END -%]

 [%- IF Koha.Preference('viewISBD') -%]
 [%- IF ( isbdview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/catalogue/ISBDdetail.pl?biblionumber=[% biblio_object_id | url  %]">ISBD</a>
 </li>
 [%- END -%]

 [%- IF ( moredetailview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% biblio_object_id | url  %]">Niteet</a>
 </li>

 [% IF ( CAN_user_circulate_manage_bookings && biblio.items.filter_by_bookable.count ) %]
 [%- IF ( bookingsview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/bookings/list.pl?biblionumber=[% biblio_object_id | url  %]">Käyttövaraukset (<span class="bookings_count">[% biblio.bookings.filter_by_active.count | html %]</span>)</a>
 </li>
 [% END %]

 [%- IF ( CAN_user_reserveforothers ) -%]
 [%- IF ( holdsview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% biblio_object_id | url  %]">Varaukset ([% biblio.holds.count | html %])</a>
 </li>
 [%- END -%]

 [%- IF ( EasyAnalyticalRecords ) -%]
 [%- IF ( analyze ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% biblio_object_id | url  %]&amp;analyze=1">Kausijulkaisut</a>
 </li>
 [%- END -%]

 [%- IF Koha.Preference('ArticleRequests') -%]
 [%- IF ( article_requests_view ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/circ/request-article.pl?biblionumber=[% IF ( object ) %][% object | uri %][% ELSE %][% biblionumber | uri %][% END %]">Artikkelipyynnöt ([% biblio.article_requests.filter_by_current.count | html %])</a>
 </li>
 [%- END -%]

 [%- IF ( subscriptionsnumber ) -%]
 <li>
 <a href="/cgi-bin/koha/serials/serials-search.pl?searched=1&amp;biblionumber=[% biblio_object_id | url  %]">Kausijulkaisutilaukset ([% subscriptionsnumber | html %])</a>
 </li>
 [%- END -%]

 [%- IF ( issuehistoryview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/catalogue/issuehistory.pl?biblionumber=[% biblio_object_id | url  %]" >Lainahistoria</a>
 </li>

 [%- IF ( CAN_user_tools_view_system_logs ) -%]
 [%- IF ( logview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/tools/viewlog.pl?do_it=1&amp;modules=CATALOGUING&amp;action=MODIFY&amp;object=[% biblio_object_id | url  %]&amp;object_type=biblio">Muutosloki</a>
 </li>
 [%- END -%]

 [%- IF ( CAN_user_stockrotation_manage_rota_items && Koha.Preference('StockRotation') ) -%]
 [%- IF ( stockrotationview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/catalogue/stockrotation.pl?biblionumber=[% biblio_object_id | uri %]">Kierto</a>
 </li>
 [%- END -%]

 [%- IF ( Koha.Preference('UseRecalls') && CAN_user_recalls ) -%]
 [%- IF ( recallsview ) -%]
 <li class="active">
 [%- ELSE -%]
 <li>
 [%- END -%]
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% biblio_object_id | url %]">Palautuspyynnöt ([% biblio.recalls.search( completed => 0 ).count | html %])</a>
 </li>
 [%- END -%]
 </ul>
</div>
