[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="alert alert-info">
 [% IF report.deleted_itemnumbers.size %]
 <p>[% report.deleted_itemnumbers.size | html %] exemplar har tagits bort.</p>
 [% IF report.deleted_biblionumbers.size %]
 <p>[% report.deleted_biblionumbers.size | html %] post(er) har tagits bort.</p>
 [% END %]
 [% ELSE %]
 <p>Inga exemplar borttagna.</p>
 [% END %]
 </div>

 [% IF report.not_deleted_itemnumbers.size %]
 <div class="alert alert-warning">
 [% report.not_deleted_itemnumbers.size | html %] exemplar kunde inte tas bort: [% FOREACH not_deleted_itemnumber IN report.not_deleted_itemnumbers %][% not_deleted_itemnumber | html %][% END %] </div>
 [% END %]

 [% IF job.status == 'cancelled' %]
 <div class="alert alert-warning">
 <span>Jobbet har avbrutits innan det var klart.</span>
 <a href="/cgi-bin/koha/tools/batchMod.pl" title="Ny satsvis redigering av exemplar">Ny satsvis redigering av exemplar</a>
 </div>
 [% END %]
 [% END %]
[% END %]

[% BLOCK detail %]
 [% FOR m IN job.messages %]
 <div class="alert alert-info">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa-solid fa-triangle-exclamation warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% SWITCH m.code %]
 [% CASE 'item_not_deleted' %]
 [% item_link = BLOCK %]<a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% m.biblionumber | uri %]&itemnumber=[% m.itemnumber | uri %]">[% m.barcode | html %]</a>[% END %]
 <span>Exemplar med streckkod [% item_link | $raw | $KohaSpan%] kan inte tas bort:</span>
 [% SWITCH m.reason %]
 [% CASE "book_on_loan" %]<span>Exemplaret är utlånat</span>
 [% CASE "not_same_branch" %]<span>Exemplaret tillhör inte ditt bibliotek</span>
 [% CASE "book_reserved" %]<span>Exemplaret har en väntande reservation</span>
 [% CASE "linked_analytics" %]<span>Exemplaret har länkade analysdata</span>
 [% CASE "last_item_for_hold" %]<span>Sista exemplaret för en bibliografisk post med reservation på postnivå</span>
 [% CASE %]<span>Okänd anledning '[% m.reason | html %]'</span>
 [% END %]
 [% CASE %]<span>Okänt meddelande '[% m.code | html %]'</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
