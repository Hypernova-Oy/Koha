[% USE Branches %]
<div id="recalls">
[% IF recalls.count %]
 <table id="recalls-table">
 <thead>
 <tr>
 [% IF checkboxes %]<th class="recall-checkbox nosort">&nbsp;</th>[% END %]
 <th class="recall-title anti-the">Nimeke</th>
 [% UNLESS specific_patron %]<th class="recall-patron">Palautuspyynnön tekijä</th>[% END %]
 <th class="recall-date">Tilattu</th>
 <th class="recall-expiry">Vanhenee</th>
 <th class="recall-branch">Noutopiste</th>
 <th class="recall-status">Tila</th>
 [% UNLESS viewing_old %]<th class="recall-duedate">Eräpäivä</th>[% END %]
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
 [% INCLUDE 'biblio-title.inc' biblio=recall.biblio link=1 %] [% IF recall.biblio.author %] / [% recall.biblio.author | html %][% END %] [% recall.item.enumchron | html %] [% IF ( recall.item ) %]<br><em>Viivakoodi: [% recall.item.barcode | html %]</em>[% END %]
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
 <span>Ei vanhene koskaan</span>
 [% ELSE %]
 -
 [% END %]
 </td>

 <td class="recall-branch">
 [% recall.library.branchname | html %]
 </td>

 <td class="recall-status">
 [% IF ( recall.in_transit ) %]
 <span>Kuljetettavana kirjastoon [% recall.library.branchname | html %]</span>
 [% ELSIF ( recall.waiting ) %]
 <span>Odottaa noutoa</span>
 [% ELSIF ( recall.expired ) %]
 <span>Vanhenee [% recall.expiration_date | $KohaDates %]</span>
 [% ELSIF ( recall.cancelled ) %]
 <span>Peruutettu [% recall.completed_date | $KohaDates %]</span>
 [% ELSIF ( recall.overdue ) %]
 <span>Myöhässä oleva</span>
 [% ELSIF ( recall.fulfilled ) %]
 <span>Täytetty</span>
 [% ELSE %]
 <span>Pyydetty</span>
 [% END %]
 </td>

 [% UNLESS viewing_old %]
 <td class="recall-duedate">
 [% IF recall.requested and recall.checkout %]
 <span>Palautettava [% recall.checkout.date_due | $KohaDates %] mennessä</span>
 [% ELSIF recall.waiting and RECALL.expiration_date %]
 <span>Nouto [% RECALL.expiration_date | $KohaDates %] mennessä</span>
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
 Toiminnot </button>
 <ul class="dropdown-menu dropdown-menu-end">
 [% IF ( recall.requested or recall.overdue ) %]
 <li><a class="cancel_recall dropdown-item" data-id="[% recall.id | html %]"><i class="fa fa-times"></i> Peruuta</a></li>
 [% IF ( recall.should_be_overdue ) %]
 <li><a class="overdue_recall" data-id="[% recall.id | html %]"><i class="fa fa-hourglass-end"></i> Merkitse myöhästyneeksi</a></li>
 [% END %]
 [% ELSIF ( recall.waiting ) %]
 <li><a class="revert_recall dropdown-item" data-id="[% recall.id | html %]"><i class="fa fa-undo"></i> Peruuta odottava-tila</a></li>
 <li><a class="expire_recall dropdown-item" data-id="[% recall.id | html %]"><i class="fa fa-times"></i> Umpeutuu</a></li>
 [% ELSIF ( recall.in_transit ) %]
 <li><a class="transit_recall dropdown-item" data-id="[% recall.id | html %]"><i class="fa fa-times"></i> Peruuta palautuspyyntö ja palauta kirjastoon: [% Branches.GetName(recall.item.homebranch) | html %]</a></li>
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
 <div class="alert alert-info">Asiakkaalla ei ole palautuspyyntöjä.</div>
 [% ELSE %]
 <div class="alert alert-info">Ei näytettäviä palautuspyyntöjä.</div>
 [% END %]
 [% END %]
</div>
