[% USE raw %]
[% BLOCK showreference %]
[%# Parameters: %]
[%# heading: the heading itself %]
[%# linkType: currently 'seefrom' or 'seealso', controls the label for the entry type: %]
[%# authid: if it is a linked authority, its authid %]

 [% SET authidurl = '/cgi-bin/koha/authorities/detail.pl?authid=' %]
 [% SET searchurl = '/cgi-bin/koha/authorities/authorities-home.pl?op=do_search&type=intranet&marclist=any&operator=contains&orderby=HeadingAsc&value=' %]

 [% IF marcflavour == 'UNIMARC' %]
 [% IF authid %]
 [% link = BLOCK %]<a href="[% authidurl _ authid | url %]">[% heading | html %]</a>[% END %]
 [% ELSE %]
 [% link = BLOCK %][% heading | html %][% END %]
 [% END %]
 [% SWITCH type %]
 [% CASE 'broader' %]
 <span class="BT"><abbr title="Laajempi termi">BT</abbr>: [% link | $raw %]</span>
 [% CASE 'narrower' %]
 <span class="NT"><abbr title="Suppeampi termi">ST</abbr>: [% link | $raw %]</span>
 [% CASE 'seefrom' %]
 <span class="UF"><abbr title="Käytetään">UF</abbr>: [% link | $raw %]</span>
 [% CASE 'seealso' %]
 <span class="RT"><abbr title="Liittyvä termi">RT</abbr>: [% link | $raw %]</span>
 [% END %]
 [% ELSE %]
 <span class="heading">
 [% IF ( linkType=='seealso' ) %]
 [% IF ( authid ) %]
 <a href="[% authidurl | url %][% authid | uri %]">[% heading | html %]</a>
 [% ELSE %]
 <a href="[% searchurl | url %][% heading | uri %]">[% heading | html %]</a>
 [% END %]
 [% ELSE %]
 [% heading | html %]
 [% END %]
 </span>
 [% UNLESS ( type=='seefrom' || type=='seealso' ) %]
 <span class="type">
 [% SWITCH type %]
 [% CASE 'earlier' %]<span>(Aiempi otsikko)</span>
 [% CASE 'later' %]<span>(Myöhempi otsikko)</span>
 [% CASE 'acronym' %]<span>(Akronyymi)</span>
 [% CASE 'musical' %]<span>(Sävellys)</span>
 [% CASE 'broader' %]<span>(Laajempi otsikko)</span>
 [% CASE 'narrower' %]<span>(Suppeampi otsikko)</span>
 [% CASE 'parent' %]<span>(Isäntäyhteisö)</span>
 [% CASE %][% IF type %]([% type | html %])
 [% END %]
 [% END %]
 </span>
 [% END %]
 [% END %]
[% END %]

[% BLOCK authresult %]
 [% IF ( summary.label ) %][% summary.label | html %]:[% END %]
 [% IF summary.summary %]
 <div class="authority-summary">
 [% summary.summary | html %]
 </div>
 [% END %]
 [% UNLESS ( summary.summaryonly ) %]
 <div class="authorizedheading">
 [% FOREACH authorize IN summary.authorized %]
 <span class="authorizedheading [% IF auth_preview %]authority_preview[% END %]">
 <a data-authid="[% authid | html %]" href="/cgi-bin/koha/authorities/detail.pl?authid=[% authid | uri %]">[% authorize.heading | html %]</a>
 </span>
 [% UNLESS loop.last %] | [% END %]
 [% END %]
 </div>
 [% IF summary.equalterm.size %]
 [% FOREACH term IN summary.equalterm %]
 <div class="equivalentheading">
 <span class="label">=</span>
 <span class="authorizedheading">[% term.heading | html %]</span>
 </div>
 [% END %]
 [% END %]
 [% IF ( marcflavour == 'UNIMARC' ) %]
 [% IF summary.notes %]
 <div class="authres_notes">
 [% FOREACH note IN summary.notes %]
 <span>[% note.note | html %]</span>
 [% END %]
 </div>
 [% END %]
 [% IF summary.seefrom %]
 <div class="authres_seefrom">
 [% FOREACH see IN summary.seefrom %]
 [% PROCESS showreference heading=see.heading linkType="" type=see.type authid=see.authid %]
 [% IF ! loop.last %] ; [% END %]
 [% END %]
 </div>
 [% END %]
 [% IF summary.seealso %]
 <div class="authres_seealso">
 [% FOREACH see IN summary.seealso %]
 [% PROCESS showreference heading=see.heading linkType="" type=see.type authid=see.authid %]
 [% IF ! loop.last %] ; [% END %]
 [% END %]
 </div>
 [% END %]
 [% IF summary.otherscript %]
 <div class="authres_otherscript">
 [% FOREACH other IN summary.otherscript %]
 [% PROCESS language lang=other.lang | trim %]:
 [% other.term | html %]
 [% IF ! loop.last %] ; [% END %]
 [% END %]
 </div>
 [% END %]
 [% ELSE %]
 [% IF summary.notes.size %]
 <div class="authres_notes">
 <span><a href="#" data-bs-toggle="modal" data-bs-target="#notesModal_[% authid | html %]">Huomautukset</a></span>
 </div>
 [% PROCESS notesmodal notes=summary.notes authid=authid %]
 [% END %]
 [% IF ( summary.seefrom.size >= 1 ) %]
 <div class="seefrom">
 <span class="seefrom">katso lähde:</span>
 [% FOREACH seefro IN summary.seefrom %]
 <div class="authref">
 [%# Following on one line for translatability %]
 [% PROCESS showreference heading=seefro.heading linkType='seefrom' type=seefro.type authid=seefro.authid %]
 </div>
 [% END %]
 </div>
 [% END %]
 [% IF ( summary.seealso.size >= 1 ) %]
 <div class="seealso">
 <span class="seealso">katso myös:</span>
 [% FOREACH seeals IN summary.seealso %]
 <div class="authref">
 [%# Following on one line for translatability %]
 [% PROCESS showreference heading=seeals.heading linkType='seealso' type=seeals.type authid=seeals.authid %]
 </div>
 [% END %]
 </div>
 [% END %]
 [% END %]
 [% END %]
[% END %]

[% BLOCK language %]
 [% SWITCH lang %]
 [% CASE ['en', 'eng'] %]<span>englanti</span>
 [% CASE ['fr', 'fre'] %]<span>ranska</span>
 [% CASE ['it', 'ita'] %]<span>italia</span>
 [% CASE ['de', 'ger', 'deu'] %]<span>saksa</span>
 [% CASE ['es', 'spa'] %]<span>espanja</span>
 [% CASE ['heb'] %]<span>heprea</span>
 [% CASE ['ara'] %]<span>arabia</span>
 [% CASE ['gre'] %]<span>nykykreikka</span>
 [% CASE ['grc'] %]<span>muinaiskreikka (-1453)</span>
 [% CASE %]<span>[% lang | html %]</span>
 [% END %]
[% END %]

[% BLOCK notesmodal %]
<!-- notes modal -->
<div class="modal notesModal" id="notesModal_[% authid | html %]" tabindex="-1" role="dialog" aria-labelledby="notesModalLabel_[% authid | html %]">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="notesModalLabel_[% authid | html %]">Huomautukset</h1>
 <button aria-label="Sulje" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <div class="modal-body">
 <ul>
 [% FOREACH note IN notes %]
 <li>[% note.note | html %]</li>
 [% END %]
 </ul>
 </div>
 <div class="modal-footer">
 <button type="button" class="btn btn-default" data-bs-dismiss="modal">Sulje</button>
 </div>
 </div>
 </div>
</div>
[% END %]
