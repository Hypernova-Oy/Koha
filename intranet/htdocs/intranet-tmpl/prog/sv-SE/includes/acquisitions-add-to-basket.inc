<fieldset class="acqui_basket_add">
 <legend class="sr-only">Lägg till beställning till korg</legend>
 [% IF has_budgets %]
 <ul>
 <li>
 <form action="/cgi-bin/koha/catalogue/search.pl" method="get">
 <label>Från en befintlig post: <input type="text" name="q" size="25" />
 </label>
 <input class="submit" data-basketno="[% basketno | html %]" data-booksellerid="[% booksellerid | html %]" id="searchtoorder" type="submit" value="Skicka" />
 </form>
 </li>
 <li><a href="/cgi-bin/koha/acqui/newordersuggestion.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Från ett förslag</a></li>
 <li><a href="/cgi-bin/koha/acqui/newordersubscription.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Från en prenumeration</a></li>
 <li><a href="/cgi-bin/koha/acqui/neworderempty.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Beställ från en ny (tom) post</a></li>
 <li><a href="/cgi-bin/koha/acqui/duplicate_orders.pl?basketno=[% basketno | uri %]">Från befintliga beställningar (kopia)</a></li>
 <li><a href="/cgi-bin/koha/acqui/z3950_search.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Från en extern källa</a></li>
 [% IF ( CAN_user_tools_stage_marc_import ) %]<li><a href="/cgi-bin/koha/tools/stage-marc-import.pl?basketno=[% basketno | uri %]&amp;booksellerid=[% booksellerid | uri %]"> Från ny fil</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/addorderiso2709.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]"> Från en förberedd fil</a></li>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/reserveratios.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Från titlar med flest reservationer</a></li>[% END %]
 </ul>
 [% ELSE %]
 <div class="alert alert-warning">
 <p>Du kan inte skapa beställningar om du inte först <a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">definiera en budget och ett budgetställe</a>.</p>
 </div>
 [% END %]
</fieldset>
