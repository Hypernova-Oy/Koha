[% IF ( no_add ) %]
 <div class="alert alert-warning">
 <h3>Asiakkaan lisääminen ei onnistu</h3>
 [% IF ( no_branches ) %]
 <p><strong>Kirjastoja ei ole määritelty. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/branches.pl">Lisää kirjasto</a>.[% ELSE %]Ylläpidon täytyy määritellä järjestelmään ainakin yksi kirjasto.[% END %]</p>
 [% END %]
 [% IF ( no_categories ) %]
 <p><strong>Asiakaslajeja ei ole määritelty. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/categories.pl">Lisää asiakasluokka</a>.[% ELSE %]Ylläpidon täytyy määritellä ainakin yksi asiakastyyppi.[% END %]</p>
 [% END %]
 </div>
[% END %]
