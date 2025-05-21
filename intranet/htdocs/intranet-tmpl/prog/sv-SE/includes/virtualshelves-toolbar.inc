<div id="toolbar" class="btn-toolbar">
 <div class="btn-group"><a id="newshelf" class="btn btn-default" href="/cgi-bin/koha/virtualshelves/shelves.pl?op=add_form&amp;referer=[% op | html %]"><i class="fa fa-plus"></i> Ny lista</a></div>

 [% IF ( can_add_biblios ) %]
 <div class="btn-group">
 <button type="button" class="btn btn-default" data-bs-toggle="modal" data-bs-target="#addToList">
 <i class="fa fa-plus"></i> Lägg till poster </button>
 </div>
 [% END %]

 [% IF shelf AND op == 'view' %]
 [% IF can_manage_shelf %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa-solid fa-pencil" aria-hidden="true"></i> Redigera</button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" href="/cgi-bin/koha/virtualshelves/shelves.pl?op=edit_form&amp;shelfnumber=[% shelf.shelfnumber | uri %]&amp;referer=[% op | uri %]">Redigera lista</a></li>
 <li>
 [% INCLUDE 'csrf-token.inc' %]
 <a class="submit-form-link dropdown-item" href="#" data-shelfnumber="[% shelf.shelfnumber | html %]" data-method="post" data-action="shelves.pl" data-op="cud-delete" data-confirmation-msg="[% t('Are you sure you want to delete this list?') | html %]">Ta bort lista</a>
 </li>
 </ul>
 </div>
 [% END %]

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-bs-toggle="dropdown" aria-expanded="false"><i class="fa fa-download"></i> Ladda ner lista</button>
 <ul class="dropdown-menu">
 <li><a class="dropdown-item" href="/cgi-bin/koha/virtualshelves/downloadshelf.pl?format=iso2709&amp;shelfid=[% shelf.shelfnumber | uri %]">iso2709</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/virtualshelves/downloadshelf.pl?format=ris&amp;shelfid=[% shelf.shelfnumber | uri %]">RIS</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/virtualshelves/downloadshelf.pl?format=bibtex&amp;shelfid=[% shelf.shelfnumber | uri %]">BibTex</a></li>
 [% FOREACH csv_profile IN csv_profiles %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/virtualshelves/downloadshelf.pl?format=[% csv_profile.export_format_id | uri %]&amp;shelfid=[% shelf.shelfnumber | uri %]">CSV - [% csv_profile.profile | html %]</a></li>
 [% END %]
 </ul>
 </div>
 <div class="btn-group"><a class="btn btn-default" href="#" id="sendlist"><i class="fa-solid fa-envelope"></i> Skicka lista</a></div>
 <div class="btn-group"><a class="btn btn-default" id="printlist" target="_blank" href="/cgi-bin/koha/virtualshelves/shelves.pl?op=view&amp;shelfnumber=[% shelf.shelfnumber | html %]&amp;print=1"><i class="fa fa-print"></i> Skriv ut lista</a></div>
 [% END %]
</div>
