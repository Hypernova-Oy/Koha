[% USE Price %]
[% USE Categories %]
[% IF NoIssuesCharge and NoIssuesCharge > 0 %]
 <li>
 <span class="circ-hlt">Avgifter:</span>
 <span>Låntagaren har obetalda avgifter på [% NoIssuesCharge | $Price %].</span>
 [% IF !Koha.Preference('AllowFineOverride') && NoIssuesCharge.limit && NoIssuesCharge.overlimit %]
 <span class="circ-hlt">Utlån ej tillåtet på grund av för höga avgifter.</span>
 [% END %]
 [% IF CAN_user_updatecharges_remaining_permissions %]
 <a href="/cgi-bin/koha/members/pay.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-default btn-xs" >Betala</a>
 <a href="/cgi-bin/koha/members/paycollect.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-default btn-xs" >Betala alla avgifter</a>
 [% END %]
 </li>
[% END %]
