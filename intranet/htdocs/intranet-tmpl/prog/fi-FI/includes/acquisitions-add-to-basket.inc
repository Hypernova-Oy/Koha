<fieldset class="acqui_basket_add">
 <legend class="sr-only">Lisää tilaus tilauskoriin</legend>
 [% IF has_budgets %]
 <ul>
 <li>
 <form action="/cgi-bin/koha/catalogue/search.pl" method="get">
 <label>Olemassa olevasta tietueesta: <input type="text" name="q" size="25" />
 </label>
 <input class="submit" data-basketno="[% basketno | html %]" data-booksellerid="[% booksellerid | html %]" id="searchtoorder" type="submit" value="OK" />
 </form>
 </li>
 <li><a href="/cgi-bin/koha/acqui/newordersuggestion.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Hankintaehdotuksesta</a></li>
 <li><a href="/cgi-bin/koha/acqui/newordersubscription.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Kausijulkaisutilauksesta</a></li>
 <li><a href="/cgi-bin/koha/acqui/neworderempty.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Uudesta (tyhjästä) tietueesta</a></li>
 <li><a href="/cgi-bin/koha/acqui/duplicate_orders.pl?basketno=[% basketno | uri %]">Olemassa olevista tilauksista (kopio)</a></li>
 <li><a href="/cgi-bin/koha/acqui/z3950_search.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Ulkoisesta lähteestä</a></li>
 [% IF ( CAN_user_tools_stage_marc_import ) %]<li><a href="/cgi-bin/koha/tools/stage-marc-import.pl?basketno=[% basketno | uri %]&amp;booksellerid=[% booksellerid | uri %]"> Uudesta tiedostosta</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/addorderiso2709.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]"> Väliaikaistiedostosta</a></li>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/reserveratios.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Varatuimpien nimekkeiden listalta</a></li>[% END %]
 </ul>
 [% ELSE %]
 <div class="alert alert-warning">
 <p>Ennen tilausten tekemistä <a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">määritellä budjetti ja tili</a>.</p>
 </div>
 [% END %]
</fieldset>
