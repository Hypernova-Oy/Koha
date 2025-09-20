[% USE Koha %]
[% UNLESS index %]
 [% SET index = 0 %]
[% END %]
[% IF refiner %]
 <select class="advsearch" name="idx" id="refiner_idx_[% index | html %]">
[% ELSE %]
 <select class="advsearch" name="idx" id="idx_[% index | html %]">
[% END %]
 [% IF ms_kw %]
 <option selected="selected" value="kw">Hakusana</option>
 [% ELSE %]
 <option value="kw">Hakusana</option>
 [% END %]
 [% IF ms_kwcommaphr %]
 <option selected="selected" value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; Fraasihaku</option>
 [% ELSE %]
 <option value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; Fraasihaku</option>
 [% END %]
 [% IF ms_au %]
 <option selected="selected" value="au">Tekijä</option>
 [% ELSE %]
 <option value="au">Tekijä</option>
 [% END %]
 [% IF ms_aucommaphr %]
 <option selected="selected" value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; Tekijä fraasina</option>
 [% ELSE %]
 <option value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; Tekijä fraasina</option>
 [% END %]
 [% IF ms_cpn %]
 <option selected="selected" value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; Yhteisön nimi</option>
 [% ELSE %]
 <option value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; Yhteisön nimi</option>
 [% END %]
 [% IF ms_cfn %]
 <option selected="selected" value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; Kokouksen nimi</option>
 [% ELSE %]
 <option value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; Kokouksen nimi</option>
 [% END %]
 [% IF ms_cpncommaphr %]
 <option selected="selected" value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Yhteisön nimi fraasina</option>
 [% ELSE %]
 <option value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Yhteisön nimi fraasina</option>
 [% END %]
 [% IF ms_cfncommaphr %]
 <option selected="selected" value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Kokouksen nimi fraasina</option>
 [% ELSE %]
 <option value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Kokouksen nimi fraasina</option>
 [% END %]
 [% IF ms_pn %]
 <option selected="selected" value="pn">&nbsp;&nbsp;&nbsp;&nbsp; Henkilönnimi</option>
 [% ELSE %]
 <option value="pn">&nbsp;&nbsp;&nbsp;&nbsp; Henkilönnimi</option>
 [% END %]
 [% IF ms_pncommaphr %]
 <option selected="selected" value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Henkilönnimi fraasina</option>
 [% ELSE %]
 <option value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Henkilönnimi fraasina</option>
 [% END %]
 [% IF ms_ti %]
 <option selected="selected" value="ti">Nimeke</option>
 [% ELSE %]
 <option value="ti">Nimeke</option>
 [% END %]
 [% IF ms_ticommaphr %]
 <option selected="selected" value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; Nimeke fraasina</option>
 [% ELSE %]
 <option value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; Nimeke fraasina</option>
 [% END %]
 [% IF ms_se %]
 <option selected="seleced" value="se">&nbsp;&nbsp;&nbsp;&nbsp; Sarjan nimeke</option>
 [% ELSE %]
 <option value="se">&nbsp;&nbsp;&nbsp;&nbsp; Sarjan nimeke</option>
 [% END %]
 [% IF ms_su %]
 <option selected="selected" value="su">Asiasana</option>
 [% ELSE %]
 <option value="su">Asiasana</option>
 [% END %]
 [% IF ms_sucommaphr %]
 <option selected="selected" value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; Asiasana fraasina</option>
 [% ELSE %]
 <option value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; Asiasana fraasina</option>
 [% END %]
 [% IF ( expanded_options ) %]
 [% IF ms_sudashbr %]
 <option selected="selected" value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; Asiasana ja laajemmat termit</option>
 [% ELSE %]
 <option value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; Asiasana ja laajemmat termit</option>
 [% END %]
 [% IF ms_sudashna %]
 <option selected="selected" value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; Asiasana ja suppeammat termit</option>
 [% ELSE %]
 <option value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; Asiasana ja suppeammat termit</option>
 [% END %]
 [% IF ms_sudashrl %]
 <option selected="selected" value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; Asiasana ja liittyvät termit</option>
 [% ELSE %]
 <option value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; Asiasana ja liittyvät termit</option>
 [% END %]
 [% END %]
 [% IF ms_bc %]
 <option selected="selected" value="bc">Viivakoodi</option>
 [% ELSE %]
 <option value="bc">Viivakoodi</option>
 [% END %]
 [% IF ms_locationcommawrdl %]
 <option selected="selected" title="Hae hyllypaikan lyhenteellä" value="location,wrdl">Hyllypaikka (koodi)</option>
 [% ELSE %]
 <option title="Hae hyllypaikan lyhenteellä" value="location,wrdl">Hyllypaikka (koodi)</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_identcommaphr %]
 <option selected="selected" value="ident,phr">Standardinumero</option>
 [% ELSE %]
 <option value="ident,phr">Standardinumero</option>
 [% END %]
 [% ELSE %]
 [% IF ms_ident %]
 <option selected="selected" value="ident">Standardinumero</option>
 [% ELSE %]
 <option value="ident">Standardinumero</option>
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
 <option selected="selected" value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; Luokka</option>
 [% ELSE %]
 <option value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; Luokka</option>
 [% END %]
 [% ELSE %]
 [% IF ms_callnum %]
 <option selected="selected" value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; Luokka</option>
 [% ELSE %]
 <option value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; Luokka</option>
 [% END %]
 [% END %]
 [% IF ms_lncommartrn %]
 <option selected="selected" value="ln,rtrn">Kieli</option>
 [% ELSE %]
 <option value="ln,rtrn">Kieli</option>
 [% END %]
 [% IF ms_nt %]
 <option selected="selected" value="nt">Huomautukset</option>
 [% ELSE %]
 <option value="nt">Huomautukset</option>
 [% END %]
 [% IF (marcflavour != 'UNIMARC' ) %]
 [% IF ms_curriculum %]
 <option selected="selected" value="curriculum">Opinto-ohjelma</option>
 [% ELSE %]
 <option value="curriculum">Opinto-ohjelma</option>
 [% END %]
 [% END %]
 [% IF ms_pb %]
 <option selected="selected" value="pb">Julkaisija</option>
 [% ELSE %]
 <option value="pb">Julkaisija</option>
 [% END %]
 [% IF ms_pl %]
 <option selected="selected" value="pl">Julkaisupaikka</option>
 [% ELSE %]
 <option value="pl">Julkaisupaikka</option>
 [% END %]

 [%# Use non-normalized st-year instead of st-numeric, %]
 [%# since pubdate can include 'u' to signify unknown %]
 [%# dates. See "Legal Characters" at: %]
 [%# http://www.loc.gov/marc/bibliographic/bd008a.html %]
 [%# This search is also for date ranges due to the %]
 [%# special Zebra r=r CCL mapping for 'yr' %]
 [% IF ms_yrcommastdashyear %]
 <option selected="selected" value="yr,st-year">Julkaisuvuosi (vvvv-vvvv)</option>
 [% ELSE %]
 <option value="yr,st-year">Julkaisuvuosi (vvvv-vvvv)</option>
 [% END %]
 [% IF ms_acqdatecommastdashdatedashnormalized %]
 <option selected="selected" value="acqdate,st-date-normalized">Hankintapäivä (vvvv-kk-pp)</option>
 [% ELSE %]
 <option value="acqdate,st-date-normalized">Hankintapäivä (vvvv-kk-pp)</option>
 [% END %]
</select>
