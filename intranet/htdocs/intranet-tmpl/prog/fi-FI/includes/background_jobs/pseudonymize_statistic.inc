[% USE KohaSpan %]
[% BLOCK report %]
 [% IF job.status == 'finished' %]
 <div class="alert alert-info">
 Tilasto on pseudonymisoitu. </div>
 [% ELSIF job.status == 'cancelled' %]
 <div class="alert alert-info">
 Pseudonymisointi on peruttu. </div>
 [% ELSE %]
 <div class="alert alert-info">
 Pseudonymisointi odottaa. </div>
 [% END %]
[% END %]

[% BLOCK detail %]
 <div class="alert alert-info">
 Pseudonymisointi. </div>
[% END %]

[% BLOCK js %]
[% END %]
