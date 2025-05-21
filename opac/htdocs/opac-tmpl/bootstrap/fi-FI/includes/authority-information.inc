[% FOREACH info IN information %]
 [% SWITCH info_type %]
 [% CASE 'identifiers' %]
 <li class="identifier_[% info.source.lower | html %]">
 [% SWITCH info.source.lower %]
 [% CASE 'orcid' %]
 <span>ORCID: </span>
 <a href="https://orcid.org/[% info.number | url %]">[% info.number | html %]</a>
 [% CASE 'scopus' %]
 <span>ScopusID: </span>
 <a href="https://www.scopus.com/authid/detail.uri?authorId=[% info.number | url %]">[% info.number | html %]</a>
 [% CASE 'loop' %]
 <span>Loop ID: </span>
 <a href="https://loop.frontiersin.org/people/[% info.number | url %]">[% info.number | html %]</a>
 [% CASE 'rid' %]
 <span>Publons ID: </span>
 <a href="https://publons.com/researcher/[% info.number | url %]">[% info.number | html %]</a>
 [% CASE 'viaf' %]
 <span>VIAF ID: </span>
 <a href="https://viaf.org/viaf/[% info.number | url %]">[% info.number | html %]</a>
 [% END %]
 </li>
 [% CASE 'activity' %]
 [% IF info.field_of_activity %]
 <li>
 <span>
 Toiminta-ala: [% info.field_of_activity | html %] [% IF info.start_period || info.end_period %] ( [%~ IF info.start_period %] [% info.start_period | html %][% END %] [% IF info.end_period %]- [% info.end_period | html %][% END ~%] ) [% END %] </span>
 </li>
 [% END %]
 [% CASE 'address' %]
 [% IF info.address %]
 <li>
 <span>Osoite: [% info.address | html %] [% info.postal_code | html %] [% info.city | html %] [% info.country | html %]</span>
 </li>
 [% END %]
 [% CASE 'associated_group' %]
 [% IF info.associated_group %]
 <li>
 <span>
 Yhteys ryhmään: [% info.associated_group | html %] [% IF info.start_period || info.end_period %] ( [%~ IF info.start_period %] [% info.start_period | html %][% END %] [% IF info.end_period %]- [% info.end_period | html %][% END ~%] ) [% END %] [% IF info.uri %]<p style="margin-bottom: 0;">WWW-osoite: [% info.uri | html %]</p>[% END %]
 [% IF info.source_of_information %]<p style="margin-bottom: 0;">Tietojen lähde: [% info.source_of_information | html %]</p> [% END %]
 [% IF info.authority_record_number %]<p style="margin-bottom: 0;">Auktoriteettitietueen kontrollinumero tai standardinumero: [% info.authority_record_number | html %]</p>[% END %]
 </span>
 </li>
 [% END %]
 [% CASE 'email_address' %]
 [% IF info.email_address %]
 <li>
 <span>
 Sähköpostiosoite: [% info.email_address | html %] </span>
 </li>
 [% END %]
 [% CASE 'occupation' %]
 [% IF info.occupation %]
 <li>
 <span>
 Ammatti: [% info.occupation | html %] [% IF info.start_period || info.end_period %] ( [%~ IF info.start_period %] [% info.start_period | html %][% END %] [% IF info.end_period %]- [% info.end_period | html %][% END ~%] ) [% END %] [% IF info.uri %]<p style="margin-bottom: 0;">WWW-osoite: [% info.uri | html %]</p>[% END %]
 [% IF info.source_of_information %]<p style="margin-bottom: 0;">Tietojen lähde: [% info.source_of_information | html %]</p> [% END %]
 [% IF info.authority_record_number %]<p style="margin-bottom: 0;">Auktoriteettitietueen kontrollinumero tai standardinumero: [% info.authority_record_number | html %]</p>[% END %]
 </span>
 </li>
 [% END %]
 [% CASE 'place_of_birth' %]
 [% IF info.place_of_birth %]
 <li>
 <span>
 Syntymäpaikka: [% info.place_of_birth | html %] </span>
 </li>
 [% END %]
 [% CASE 'place_of_death' %]
 [% IF info.place_of_death %]
 <li>
 <span>
 Kuolinpaikka: [% info.place_of_death | html %] </span>
 </li>
 [% END %]
 [% CASE 'uri' %]
 [% IF info.uri %]
 <li>
 <span>
 WWW-osoite: [% info.uri | $raw | html %] </span>
 </li>
 [% END %]
 [% END %]
[% END %]
