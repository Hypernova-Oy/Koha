[% IF ( currency ) %]
 [% IF ( not hide ) %]
 <p><strong>Rahayksikkö = [% currency | html %]</strong></p>
 [% END %]
[% ELSE %]
 <div class="alert alert-warning">
 <h3>Ei aktiivista rahayksikköä</h3>
 [% IF CAN_user_acquisition_currencies_manage %]
 <p><a href="/cgi-bin/koha/admin/currency.pl">Määrittele aktiivinen rahayksikkö.</a></p>
 [% ELSE %]
 <p>Määrittele aktiiviset rahayksiköt.</p>
 [% END %]
 </div>
[% END %]
