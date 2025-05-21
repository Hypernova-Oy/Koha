[% USE Branches %]
<div id="recalls">
[% IF recalls.count %]
 <table id="recalls-table">
 <thead>
 <tr>
 [% IF checkboxes %]<th class="recall-checkbox nosort">&nbsp;</th>[% END %]
 <th class="recall-title anti-the">Titel</th>
 [% UNLESS specific_patron %]<th class="recall-patron">Reserverad av</th>[% END %]
 <th class="recall-date">Lades den</th>
 <th class="recall-expiry">Utgår den</th>
 <th class="recall-branch">Avhämtningsbibliotek</th>
 <th class="recall-status">Status</th>
 [% UNLESS viewing_old %]<th class="recall-duedate">Återlämningsdatum</th>[% END %]
 [% UNLESS viewing_old %]<th class="recall-actions nosort">&nbsp;</th>[% END %]
 </tr>
 </thead>

 <tbody>
 [% FOREACH recall IN recalls %]
 [% IF recall.completed %]<tr class="old">[% ELSE %]<tr>[% END %]

 [% IF checkboxes %]
 <td class="recall-checkbox">
 [% IF recall.completed %]
 &nbsp;
 [% ELSE %]
 <input type="checkbox" value="[% recall.id | html %]" name="recall_ids">
 [% END %]
 </td>
 [% END %]

 <td class="recall-title">
 [% INCLUDE 'biblio-title.inc' biblio=recall.biblio link=1 %] [% IF recall.biblio.author %] av [% recall.biblio.author | html %][% END %] [% recall.item.enumchron | html %] [% IF ( recall.item ) %]<br><em>Streckkod: [% recall.item.barcode | html %]</em>[% END %]
 </td>

 [% UNLESS specific_patron %]
 <td class="recall-patron">
 [% INCLUDE 'patron-title.inc' patron=recall.patron hide_patron_infos_if_needed=1 link_to="circulation_recalls" %]
 </td>
 [% END %]

 <td class="recall-date">
 [% recall.created_date | $KohaDates %]
 </td>

 <td class="recall-expiry">
 [% IF ( recall.expiration_date ) %]
 [% recall.expiration_date | $KohaDates %]
 [% ELSIF ( !recall.completed ) %]
 <span>Upphör aldrig</span>
 [% ELSE %]
 -
 [% END %]
 </td>

 <td class="recall-branch">
 [% recall.library.branchname | html %]
 </td>

 <td class="recall-status">
 [% IF ( recall.in_transit ) %]
 <span>Under transport till [% recall.library.branchname | html %]</span>
 [% ELSIF ( recall.waiting ) %]
 <span>Att hämta</span>
 [% ELSIF ( recall.expired ) %]
 <span>Gick ut den [% recall.expiration_date | $KohaDates %]</span>
 [% ELSIF ( recall.cancelled ) %]
 <span>Annullerad den [% recall.completed_date | $KohaDates %]</span>
 [% ELSIF ( recall.overdue ) %]
 <span>Försenade exemplar som ska återlämnas</span>
 [% ELSIF ( recall.fulfilled ) %]
 <span>Genomförd</span>
 [% ELSE %]
 <span>Begärd</span>
 [% END %]
 </td>

 [% UNLESS viewing_old %]
 <td class="recall-duedate">
 [% IF recall.requested and recall.checkout %]
 <span>Ska återlämnas av [% recall.checkout.date_due | $KohaDates %]</span>
 [% ELSIF recall.waiting and RECALL.expiration_date %]
 <span>Hämta senast [% RECALL.expiration_date | $KohaDates %]</span>
 [% ELSE %]
 -
 [% END %]
 </td>
 [% END %]

 [% UNLESS viewing_old %]
 <td class="recall-cancel actions">
 [% IF recall.completed %]
 &nbsp;
 [% ELSE %]
 <div class="btn-group">
 <button type="button" class="btn btn-sm btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
 Åtgärder </button>
 <ul class="dropdown-menu dropdown-menu-end">
 [% IF ( recall.requested or recall.overdue ) %]
 <li><a class="cancel_recall dropdown-item" data-id="[% recall.id | html %]"><i class="fa fa-times"></i> Avbryt</a></li>
 [% IF ( recall.should_be_overdue ) %]
 <li><a class="overdue_recall" data-id="[% recall.id | html %]"><i class="fa fa-hourglass-end"></i> Markera som försenad</a></li>
 [% END %]
 [% ELSIF ( recall.waiting ) %]
 <li><a class="revert_recall dropdown-item" data-id="[% recall.id | html %]"><i class="fa fa-undo"></i> Ångra väntestatus</a></li>
 <li><a class="expire_recall dropdown-item" data-id="[% recall.id | html %]"><i class="fa fa-times"></i> Utgår</a></li>
 [% ELSIF ( recall.in_transit ) %]
 <li><a class="transit_recall dropdown-item" data-id="[% recall.id | html %]"><i class="fa fa-times"></i> Avbryt återkrav och skicka till: [% Branches.GetName(recall.item.homebranch) | html %]</a></li>
 [% END %]
 </ul>
 </div>
 [% END %]
 </td>
 [% END %]

 </tr>
 [% END %]
 </tbody>
 </table>
 [% ELSE %]
 [% IF patron.borrowernumber %]
 <div class="alert alert-info">Låntagare har inga återkrav.</div>
 [% ELSE %]
 <div class="alert alert-info">Det finns inga återkrav att visa.</div>
 [% END %]
 [% END %]
</div>
