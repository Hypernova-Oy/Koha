[% USE KohaSpan %]
[% BLOCK report %]
 [% IF job.status == 'finished' %]
 <div class="alert alert-info">
 Statistik har pseudonymiserats. </div>
 [% ELSIF job.status == 'cancelled' %]
 <div class="alert alert-info">
 Pseudonymisering har avbrutits. </div>
 [% ELSE %]
 <div class="alert alert-info">
 Väntar på pseudonymisering. </div>
 [% END %]
[% END %]

[% BLOCK detail %]
 <div class="alert alert-info">
 Pseudonomysering. </div>
[% END %]

[% BLOCK js %]
[% END %]
