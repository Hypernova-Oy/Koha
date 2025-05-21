<div id="toolbar" class="btn-toolbar">
 [% IF ( budget_period_id ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa fa-plus"></i> Uusi</button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form">Uusi budjetti</a></li>
 [% IF ( budget_period_locked || !CAN_user_acquisition_budget_add_del ) %]
 <li data-bs-placement="left" data-bs-toggle="tooltip" title="Budjetti on lukittu">
 <a class="dropdown-item disabled" aria-disabled="true" href="#">Uusi tili kohteelle [% budget_period_description | html %]</a>
 </li>
 [% ELSE %]
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/admin/aqbudgets.pl?op=add_form&amp;budget_period_id=[% budget_period_id | uri %]">Uusi tili kohteelle [% budget_period_description | html %]</a>
 </li>
 [% END %]
 </ul>
 </div>

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Muokkaa</button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form&amp;budget_period_id=[% budget_period_id | uri %]">Muokkaa budjettia [% budget_period_description | html %]</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=duplicate_form&amp;budget_period_id=[% budget_period_id | uri %]">Kopioi budjetti [% budget_period_description | html %]</a></li>
 </ul>
 </div>

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Suunnittelu</button>
 <ul class="dropdown-menu">
 <li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <a class="dropdown-item" href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=MONTHS">Suunnittele kuukausittain</a>
 [% ELSE %]
 <a class="dropdown-item disabled" aria-disabled="true" href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=MONTHS">Suunnittele kuukausittain</a>
 [% END %]
 </li>
 <li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <a class="dropdown-item" href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=BRANCHES">Suunnittele kirjastoittain</a>
 [% ELSE %]
 <a class="dropdown-item disabled" aria-disabled="true" href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=BRANCHES">Suunnittele kirjastoittain</a>
 [% END %]
 </li>
 <li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <a class="dropdown-item" href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=ITEMTYPES">Suunnittele aineistoittain</a></li>
 [% ELSE %]
 <a class="dropdown-item disabled" aria-disabled="true" href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=ITEMTYPES">Suunnittele aineistoittain</a>
 [% END %]
 </li>
 [% FOREACH auth_cats_loo IN auth_cats_loop %]
 <li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <a class="dropdown-item" href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=[% auth_cats_loo | uri %]">Suunnittele [% auth_cats_loo | html %]</a>
 [% ELSE %]
 <a class="dropdown-item disabled" aria-disabled="true" href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=[% auth_cats_loo | uri %]">Suunnittele [% auth_cats_loo | html %]</a>
 [% END %]
 </li>
 [% END %]
 </ul>
 </div>

 [% ELSE %]
 <div class="btn-group"><a class="btn btn-default" id="newrootbudget" href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form"><i class="fa fa-plus"></i> Uusi budjetti</a></div>
 [% END %]

</div>
