[% USE Price %]
[% USE Categories %]
[% IF NoIssuesCharge and NoIssuesCharge > 0 %]
 <li>
 <span class="circ-hlt">Maksut:</span>
 <span>Asiakkaalla on lainauskieltoon vaikuttavia maksuja [% NoIssuesCharge | $Price %].</span>
 [% IF !Koha.Preference('AllowFineOverride') && NoIssuesCharge.limit && NoIssuesCharge.overlimit %]
 <span class="circ-hlt">Lainaus on estetty, koska asiakkaalla on liikaa maksuja.</span>
 [% END %]
 [% IF CAN_user_updatecharges_remaining_permissions %]
 <a href="/cgi-bin/koha/members/pay.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-default btn-xs" >Maksa</a>
 <a href="/cgi-bin/koha/members/paycollect.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-default btn-xs" >Maksa kaikki maksut</a>
 [% END %]
 </li>
[% END %]
