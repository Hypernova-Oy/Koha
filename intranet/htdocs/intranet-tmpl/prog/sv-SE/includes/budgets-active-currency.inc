[% IF ( currency ) %]
 [% IF ( not hide ) %]
 <p><strong>Valuta = [% currency | html %]</strong></p>
 [% END %]
[% ELSE %]
 <div class="alert alert-warning">
 <h3>Ingen aktiv valuta har definierats</h3>
 [% IF CAN_user_acquisition_currencies_manage %]
 <p><a href="/cgi-bin/koha/admin/currency.pl">Ange en aktiv valuta.</a></p>
 [% ELSE %]
 <p>Din administratör måste ange en aktiv valuta.</p>
 [% END %]
 </div>
[% END %]
