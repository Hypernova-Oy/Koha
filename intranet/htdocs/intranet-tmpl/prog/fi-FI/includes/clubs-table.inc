[% IF destination == 'holds' %]
 <table id="clubs-table" class="selections-table">
[% ELSE %]
 <table id="clubs-table">
[% END %]
 <thead>
 <tr>
 <th>Nimi</th>
 <th>Pohja</th>
 <th>Kuvaus</th>
 [% UNLESS destination == 'holds' %]
 <th>Julkinen ilmoittautuminen</th>
 <th>Sähköpostiosoite pakollinen</th>
 [% END %]
 <th>Kirjasto</th>
 <th>Alkupvm</th>
 <th>Loppumispvm</th>
 <th>Ilmoittautuneet asiakkaat</th>
 [% UNLESS destination == 'holds' %]
 <th>&nbsp;</th>
 [% END %]
 </tr>
 </thead>
 <tbody>
 [% FOREACH c IN clubs %]
 [% IF destination == 'holds' %]
 [% SET data_url = "/cgi-bin/koha/reserve/request.pl?club=" _ c.id %]
 [% FOREACH biblionumber IN biblionumbers %]
 [% SET data_url = data_url _ "&amp;biblionumber=" _ biblionumber %]
 [% END %]
 [% IF multi_hold %]
 [% SET data_url = data_url _ "&amp;multi_hold=1" %]
 [% END %]
 <tr class="clickable" data-url="[% data_url | html %]">
 <td><a href="[% data_url | url %]">[% c.name | html %]</a></td>
 [% ELSE %]
 <tr>
 <td>[% c.name | html %]</td>
 [% END %]
 <td>[% c.club_template.name | html %]</td>
 <td>[% c.description | html %]</td>
 [% UNLESS destination == 'holds' %]
 <td>
 [% IF c.club_template.is_enrollable_from_opac %]
 <span>Kyllä</span>
 [% ELSE %]
 <span>Ei</span>
 [% END %]
 </td>
 <td>
 [% IF c.club_template.is_email_required %]
 <span>Kyllä</span>
 [% ELSE %]
 <span>Ei</span>
 [% END %]
 </td>
 [% END %]
 <td>[% Branches.GetName( c.branchcode ) | html %]</td>
 <td>
 [% IF c.date_start %]
 [% c.date_start | $KohaDates %]
 [% END %]
 </td>
 <td>
 [% IF c.date_end %]
 [% c.date_end | $KohaDates %]
 [% END %]
 </td>
 <td>
 [% c.club_enrollments.count | html %]
 </td>
 [% UNLESS destination == 'holds' %]
 <td class="actions">
 <div class="btn-group dropup">
 <a class="btn btn-default btn-xs dropdown-toggle" id="clubactions[% c.id | html %]" role="button" data-bs-toggle="dropdown" href="#">
 Toiminnot </a>
 <ul class="dropdown-menu dropdown-menu-end" role="menu" aria-labelledby="clubactions[% c.id | html %]">
 [% IF ( c.club_enrollments.count ) %]
 <li>
 <a class="dropdown-item" href="club-enrollments.pl?id=[% c.id | uri %]">
 <i class="fa fa-list-ul"></i> Ilmoittautumiset </a>
 </li>
 [% ELSE %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Ei vielä ilmoittautuneita tälle kerholle">
 <a class="dropdown-item disabled" aria-disabled="true" href="#">
 <i class="fa fa-list-ul"></i> Ilmoittautumiset </a>
 </li>
 [% END %]
 [% IF CAN_user_clubs_edit_clubs %]
 <li>
 <a class="dropdown-item" href="clubs-add-modify.pl?id=[% c.id | uri %]">
 <i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa </a>
 </li>
 <li>
 <a class="dropdown-item delete_club" href="#" data-id="[% c.id | html %]" data-name="[% c.name | html %]">
 <i class="fa fa-trash-can"></i> Poista </a>
 </li>
 [% END %]
 [% IF ( c.club_enrollments.count ) %]
 <li>
 <a class="dropdown-item club_hold_search" href="#" data-id="[% c.id | html %]">
 <i class="fa fa-search"></i> Hae ja varaa </a>
 </li>
 [% END %]
 </ul>
 </div>
 </td>
 [% END %]
 </tr>
 [% END %]
 </tbody>
</table> <!-- /.clubs-table -->
