[% USE Koha %]
[% IF refiner %]
 <select class="advsearch" name="idx" id="refiner_idx_[% index | html %]">
[% ELSE %]
 <select class="advsearch" name="idx" id="idx_[% index | html %]">
[% END %]
 [% IF ms_kw %]
 <option selected="selected" value="kw">Nyckelord</option>
 [% ELSE %]
 <option value="kw">Nyckelord</option>
 [% END %]
 [% IF ms_kwcommaphr %]
 <option selected="selected" value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; Nyckelord som fras</option>
 [% ELSE %]
 <option value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; Nyckelord som fras</option>
 [% END %]
 [% IF ms_au %]
 <option selected="selected" value="au">Författare</option>
 [% ELSE %]
 <option value="au">Författare</option>
 [% END %]
 [% IF ms_aucommaphr %]
 <option selected="selected" value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; Författare som fras</option>
 [% ELSE %]
 <option value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; Författare som fras</option>
 [% END %]
 [% IF ms_cpn %]
 <option selected="selected" value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; Företagsnamn</option>
 [% ELSE %]
 <option value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; Företagsnamn</option>
 [% END %]
 [% IF ms_cfn %]
 <option selected="selected" value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; Konferensnamn</option>
 [% ELSE %]
 <option value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; Konferensnamn</option>
 [% END %]
 [% IF ms_cpncommaphr %]
 <option selected="selected" value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Företagsnamn som fras</option>
 [% ELSE %]
 <option value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Företagsnamn som fras</option>
 [% END %]
 [% IF ms_cfncommaphr %]
 <option selected="selected" value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Konferensnamn som fras</option>
 [% ELSE %]
 <option value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Konferensnamn som fras</option>
 [% END %]
 [% IF ms_pn %]
 <option selected="selected" value="pn">&nbsp;&nbsp;&nbsp;&nbsp; Personnamn</option>
 [% ELSE %]
 <option value="pn">&nbsp;&nbsp;&nbsp;&nbsp; Personnamn</option>
 [% END %]
 [% IF ms_pncommaphr %]
 <option selected="selected" value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Personnamn som fras</option>
 [% ELSE %]
 <option value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Personnamn som fras</option>
 [% END %]
 [% IF ms_ti %]
 <option selected="selected" value="ti">Titel</option>
 [% ELSE %]
 <option value="ti">Titel</option>
 [% END %]
 [% IF ms_ticommaphr %]
 <option selected="selected" value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; Titel som fras</option>
 [% ELSE %]
 <option value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; Titel som fras</option>
 [% END %]
 [% IF ms_se %]
 <option selected="seleced" value="se">&nbsp;&nbsp;&nbsp;&nbsp; Serietitel</option>
 [% ELSE %]
 <option value="se">&nbsp;&nbsp;&nbsp;&nbsp; Serietitel</option>
 [% END %]
 [% IF ms_su %]
 <option selected="selected" value="su">Ämne</option>
 [% ELSE %]
 <option value="su">Ämne</option>
 [% END %]
 [% IF ms_sucommaphr %]
 <option selected="selected" value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; Ämne som fras</option>
 [% ELSE %]
 <option value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; Ämne som fras</option>
 [% END %]
 [% IF ( expanded_options ) %]
 [% IF ms_sudashbr %]
 <option selected="selected" value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; Ämne och bredare termer</option>
 [% ELSE %]
 <option value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; Ämne och bredare termer</option>
 [% END %]
 [% IF ms_sudashna %]
 <option selected="selected" value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; Ämne och smalare termer</option>
 [% ELSE %]
 <option value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; Ämne och smalare termer</option>
 [% END %]
 [% IF ms_sudashrl %]
 <option selected="selected" value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; Ämne och tillhörande termer</option>
 [% ELSE %]
 <option value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; Ämne och tillhörande termer</option>
 [% END %]
 [% END %]
 [% IF ms_bc %]
 <option selected="selected" value="bc">Streckkod</option>
 [% ELSE %]
 <option value="bc">Streckkod</option>
 [% END %]
 [% IF ms_locationcommawrdl %]
 <option selected="selected" title="Ange värde för placering att söka på" value="location,wrdl">Placering (kod)</option>
 [% ELSE %]
 <option title="Ange värde för placering att söka på" value="location,wrdl">Placering (kod)</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_identcommaphr %]
 <option selected="selected" value="ident,phr">Standardnummer</option>
 [% ELSE %]
 <option value="ident,phr">Standardnummer</option>
 [% END %]
 [% ELSE %]
 [% IF ms_ident %]
 <option selected="selected" value="ident">Standardnummer</option>
 [% ELSE %]
 <option value="ident">Standardnummer</option>
 [% END %]
 [% END %]
 [% IF ms_nb %]
 <option selected="selected" value="nb">&nbsp;&nbsp;&nbsp;&nbsp; ISBN</option>
 [% ELSE %]
 <option value="nb">&nbsp;&nbsp;&nbsp;&nbsp; ISBN</option>
 [% END %]
 [% IF ms_ns %]
 <option selected="selected" value="ns">&nbsp;&nbsp;&nbsp;&nbsp; ISSN</option>
 [% ELSE %]
 <option value="ns">&nbsp;&nbsp;&nbsp;&nbsp; ISSN</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_callnumcommaphr %]
 <option selected="selected" value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; Hyllsignatur</option>
 [% ELSE %]
 <option value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; Hyllsignatur</option>
 [% END %]
 [% ELSE %]
 [% IF ms_callnum %]
 <option selected="selected" value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; Hyllsignatur</option>
 [% ELSE %]
 <option value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; Hyllsignatur</option>
 [% END %]
 [% END %]
 [% IF ms_lncommartrn %]
 <option selected="selected" value="ln,rtrn">Språk</option>
 [% ELSE %]
 <option value="ln,rtrn">Språk</option>
 [% END %]
 [% IF ms_nt %]
 <option selected="selected" value="nt">Anteckningar/kommentarer</option>
 [% ELSE %]
 <option value="nt">Anteckningar/kommentarer</option>
 [% END %]
 [% IF (marcflavour != 'UNIMARC' ) %]
 [% IF ms_curriculum %]
 <option selected="selected" value="curriculum">Läroplan</option>
 [% ELSE %]
 <option value="curriculum">Läroplan</option>
 [% END %]
 [% END %]
 [% IF ms_pb %]
 <option selected="selected" value="pb">Förlag</option>
 [% ELSE %]
 <option value="pb">Förlag</option>
 [% END %]
 [% IF ms_pl %]
 <option selected="selected" value="pl">Förlagsort</option>
 [% ELSE %]
 <option value="pl">Förlagsort</option>
 [% END %]

 [%# Use non-normalized st-year instead of st-numeric, %]
 [%# since pubdate can include 'u' to signify unknown %]
 [%# dates. See "Legal Characters" at: %]
 [%# http://www.loc.gov/marc/bibliographic/bd008a.html %]
 [%# This search is also for date ranges due to the %]
 [%# special Zebra r=r CCL mapping for 'yr' %]
 [% IF ms_yrcommastdashyear %]
 <option selected="selected" value="yr,st-year">Utgivningsdatum (åååå-åååå)</option>
 [% ELSE %]
 <option value="yr,st-year">Utgivningsdatum (åååå-åååå)</option>
 [% END %]
 [% IF ms_acqdatecommastdashdatedashnormalized %]
 <option selected="selected" value="acqdate,st-date-normalized">Inköpsdatum (åååå-mm-dd)</option>
 [% ELSE %]
 <option value="acqdate,st-date-normalized">Inköpsdatum (åååå-mm-dd)</option>
 [% END %]
</select>
