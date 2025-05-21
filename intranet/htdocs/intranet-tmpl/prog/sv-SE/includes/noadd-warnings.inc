[% IF ( no_add ) %]
 <div class="alert alert-warning">
 <h3>Kan inte lägga till låntagare</h3>
 [% IF ( no_branches ) %]
 <p><strong>Inga bibliotek är definierade. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/branches.pl">Lägg till ett bibliotek</a>.[% ELSE %]En administratör måste definiera minst ett bibliotek.[% END %]</p>
 [% END %]
 [% IF ( no_categories ) %]
 <p><strong>Inga låntagarkategorier har definierats. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/categories.pl">Lägg till en låntagarkategori</a>.[% ELSE %]En administratör måste definiera minst en låntagarkategori.[% END %]</p>
 [% END %]
 </div>
[% END %]
