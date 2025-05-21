[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="alert alert-info">
 [% IF report.deleted_itemnumbers.size %]
 <p>[% report.deleted_itemnumbers.size | html %] nide(ttä) poistettu.</p>
 [% IF report.deleted_biblionumbers.size %]
 <p>[% report.deleted_biblionumbers.size | html %] tietue(tta) poistettu.</p>
 [% END %]
 [% ELSE %]
 <p>Ei poistettuja niteitä.</p>
 [% END %]
 </div>

 [% IF report.not_deleted_itemnumbers.size %]
 <div class="alert alert-warning">
 [% report.not_deleted_itemnumbers.size | html %] niteitä ei voitu poistaa: [% FOREACH not_deleted_itemnumber IN report.not_deleted_itemnumbers %][% not_deleted_itemnumber | html %] [% END %] </div>
 [% END %]

 [% IF job.status == 'cancelled' %]
 <div class="alert alert-warning">
 <span>Ajo keskeytettiin ennen kuin se valmistui.</span>
 <a href="/cgi-bin/koha/tools/batchMod.pl" title="Uusi niteiden muokkaus eräajona">Uusi niteiden muokkaus eräajona</a>
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
 <span>Nidettä viivakoodilla [% item_link | $raw | $KohaSpan%] ei voitu poistaa:</span>
 [% SWITCH m.reason %]
 [% CASE "book_on_loan" %]<span>Nide on lainassa</span>
 [% CASE "not_same_branch" %]<span>Nide ei kuulu kirjastoosi</span>
 [% CASE "book_reserved" %]<span>Niteeseen on odottava varaus</span>
 [% CASE "linked_analytics" %]<span>Niteestä on analyyttisia tietoja</span>
 [% CASE "last_item_for_hold" %]<span>Viimeinen nide tietueelle, jossa on tietuetason varaus</span>
 [% CASE %]<span>Tuntematon syy '[% m.reason | html %]'</span>
 [% END %]
 [% CASE %]<span>Tuntematon viesti '[% m.code | html %]'</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
