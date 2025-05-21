<div class="actions-menu noprint">
 [% IF ( HoldsEnabled ) %]
 [% UNLESS ( items.norequests ) %]
 [% IF ( shelf AND op == 'view' ) # Lists view has more granular checking of hold availability %]
 [% IF ( items.allow_onshelf_holds ) %]
 <span class="actions"><a aria-label="Varaa [% items.title | html %]" class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> Varaa</a></span>
 [% ELSE %]
 [% IF ( items.itemsissued ) %]
 <span class="actions"><a aria-label="Varaa [% items.title | html %]" class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> Varaa</a></span>
 [% END %]
 [% END %]
 [% ELSE %]
 <span class="actions"><a aria-label="Varaa [% items.title | html %]" class="btn btn-link btn-sm" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark" aria-hidden="true"></i> Varaa</a></span>
 [% END %]
 [% END # / UNLESS items.norequests %]
 [% END # / OPACHoldRequests %]

 [% IF ( RecallsEnabled ) %]
 <span class="actions"><a class="btn btn-link btn-sm recall" href="/cgi-bin/koha/opac-recall.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa-fw fa-solid fa-book-bookmark" aria-hidden="true"></i> Tee palautuspyyntö</a></span>
 [% END %]

 [% IF ( LoginEnabled ) %]
 [% IF items.artreqpossible %]
 <span class="actions"><a href="/cgi-bin/koha/opac-request-article.pl?biblionumber=[% items.biblionumber | uri %]" class="btn btn-link btn-sm"><i class="fa-fw fa-solid fa-file-lines" aria-hidden="true"></i> Pyydä artikkelia</a></span>
 [% END %]
 [% END %]

 [% IF ( TagsInputEnabled ) %]
 [% IF ( loggedinusername ) %]
 <span class="actions"><a id="tag_add[% items.biblionumber | html %]" href="#" class="tag_add btn btn-link btn-sm"><i class="fa fa-fw fa-tag" aria-hidden="true"></i> Lisää tagi</a></span>
 <div id="tagform[% items.biblionumber | html %]" class="tag_results_input form-inline" style="display:none;">
 <label for="newtag[% items.biblionumber | html %]">Lisää tageja, pilkulla eroteltuna:</label>
 <input type="text" name="newtag[% items.biblionumber | html %]" id="newtag[% items.biblionumber | html %]" class="form-control form-control-sm newtag" maxlength="100" />
 <input class="btn btn-sm btn-primary tagbutton" name="tagbutton" title="[% items.biblionumber | html %]" type="submit" value="Lisää" />
 <a class="cancel_tag_add" id="cancel[% items.biblionumber | html %]" href="#">(valmis)</a>
 </div>
 <span id="newtag[% items.biblionumber | html %]_status" class="tagstatus" style="display:none;">
 Tagin tila </span>
 [% ELSE %]
 <span class="actions">
 <span class="login4tags">
 <a class="btn btn-link btn-sm loginModal-trigger" href="/cgi-bin/koha/opac-user.pl"><i class="fa fa-fw fa-tag" aria-hidden="true"></i> Kirjaudu lisääksesi tageja</a>
 </span>
 </span>
 [% END # IF loggedinusername %]
 [% END # if TagsInputEnabled %]

 [% IF ( ListsEnabled ) %]
 [% IF ( shelf AND op == 'view' ) %]
 <span class="actions"><a href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | uri %]" class="addtoshelf btn btn-link btn-sm"><i class="fa fa-fw fa-list" aria-hidden="true"></i> Vie toiseen listaan</a></span>
 [% IF can_remove_biblios %]
 <span class="actions"><a class="btn btn-link btn-sm removeitems" data-biblionumber="[% items.biblionumber | html %]" href="#"><i class="fa fa-fw fa-remove" aria-hidden="true"></i> Poista listalta</a></span>
 [% END %]
 [% ELSE %]
 <span class="actions"><a class="addtoshelf btn btn-link btn-sm" href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-list" aria-hidden="true"></i> Lisää listalle</a></span>
 [% END # /IF ( shelf AND op == 'view' ) %]
 [% END # /IF Koha.Preference( 'opacuserlogin' ) %]

 [% IF ( CartEnabled ) %]
 [% IF ( items.incart ) %]
 <span class="actions cart-actions"><a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm addtocart cart[% items.biblionumber | html %]" href="#"><i class="fa fa-fw fa-shopping-cart" aria-hidden="true"></i> Korissa</a> <a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm remove cartRemove cartR[% items.biblionumber | html %]" href="#">(poista)</a></span>
 [% ELSE %]
 <span class="actions cart-actions"><a aria-label="Lisää [% items.title | html %] koriin" class="btn btn-link btn-sm addtocart cart cart[% items.biblionumber | html %]" data-biblionumber="[% items.biblionumber | html %]" href="#"><i class="fa fa-fw fa-shopping-cart" aria-hidden="true"></i> Lisää koriin</a> <a style="display:none;" data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link btn-sm remove cartRemove cartR[% items.biblionumber | html %]" href="#">(poista)</a></span>
 [% END %]
 [% END # / IF opacbookbag %]
</div>
