[%- BLOCK role -%]
 [% matches = role.key.match('(\w+):?(.*)?') %]
 [% ro = matches.0 %]
 [% ex = matches.1 %]
 [%- SWITCH ro -%]
 [%- CASE 'manager'               -%]<span>Julkaisun ylläpitäjä</span>
 [%- CASE 'manager_assistant'     -%]<span>Julkaisun ylläpitäjän avustaja</span>
 [%- CASE 'manager_mentor'        -%]<span>Julkaisun ylläpitäjän ohjaaja</span>
 [%- CASE 'qa_manager'            -%]<span>Laadunvarmistuspäällikkö</span>
 [%- CASE 'qa'                    -%]<span>Laadunvarmistustiimi</span>
 [%- CASE 'documentation'         -%]<span>Asiakirjojen hallinta</span>
 [%- CASE 'documentation_team'    -%]<span>Dokumentaatiotiimi</span>
 [%- CASE 'translation'           -%]<span>Käännöksen ylläpitäjä</span>
 [%- CASE 'translations'          -%]<span>Käännöksen ylläpitäjät</span>
 [%- CASE 'translation_assistant' -%]<span>Käännöksen ylläpitäjän avustaja</span>
 [%- CASE 'te'                    -%]<span>Aiheen asiantuntija</span>
 [%- CASE 'bugwrangler'           -%]<span>Virhevastaava</span>
 [%- CASE 'maintainer'            -%]<span>Julkaisun ylläpitäjä</span>
 [%- CASE 'maintainer_assistant'  -%]<span>Julkaisun ylläpitäjän avustaja</span>
 [%- CASE 'maintainer_mentor'     -%]<span>Julkaisun ylläpitäjän ohjaaja</span>
 [%- CASE 'wiki'                  -%]<span>Wikin hoitaja</span>
 [%- CASE 'ci'                    -%]<span>Jatkuvan integraation hallinta</span>
 [%- CASE 'packaging'             -%]<span>Paketointipäällikkö</span>
 [%- CASE 'packaging_assistant'   -%]<span>Paketointipäällikön avustaja</span>
 [%- CASE 'chairperson'           -%]<span>Kokouksen puheenjohtaja</span>
 [%- CASE 'newsletter'            -%]<span>Uutiskirjeen toimittaja</span>
 [%- CASE 'mm'                    -%]<span>Moduulin ylläpitäjä</span>
 [%- CASE 'vm'                    -%]<span>Virtuaalikoneen ylläpitäjä</span>
 [%- CASE 'database'              -%]<span>Dokumentaatioasiantuntija</span>
 [%- CASE 'live_cd'               -%]<span>Live-CD:n ylläpitäjä</span>
 [%- CASE 'accessibility_advocate'-%]<span>Saavutettavuusasiantuntija</span>
 [%- CASE 'meeting_facilitator'   -%]<span>Kokouksen ohjaaja</span>
 [%- CASE 'ktd'                   -%]<span>Kehittäjätyökalut</span>
 [%- CASE 'website'               -%]<span>Sivuston ylläpitäjä</span>
 [%- CASE 'security_manager'      -%]<span>Tietoturvajulkaisun ylläpitäjä</span>
 [%- CASE -%]<span>Roolilta [% role.key | html %] puuttuu määritys</span>
 [%- END -%]
 [%- IF ex %] - [% ex | html %][% END -%]
[%- END -%]

[%- BLOCK person -%]
[% IF p.openhub %]<a href="[% p.openhub | url %]">[% p.name | html %]</a>[% ELSE %][% p.name | html %][% END %]
[%- END -%]

[%- BLOCK contributions -%]
[%- IF p.roles || p.notes -%]
<ul>
 [% FOREACH r IN p.roles %]<li>[% INCLUDE role role=r %] ([% r.value.join(', ') | html %])</li>[% END %]
 [% IF p.notes %]<li>[% p.notes | html %]</li>[% END %]
</ul>
[%- END -%]
[%- END -%]

[%- BLOCK team -%]
 <ul>

 [% IF v == 'release' %]
 <p>Tämä tiimi oli vastuussa nyt käyttämäsi Koha-version ensijulkaisusta.</p>

 <li><strong>Release manager:</strong>
 [% INCLUDE person p=t.manager %]
 </li>

 [% IF t.manager_assistants %]
 <li><strong>Julkaisun ylläpitäjän avustajat:</strong>
 <ul>
 [% FOREACH a IN t.manager_assistants %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.manager_assistant %]
 <li><strong>Julkaisun ylläpitäjän avustaja:</strong>
 [% INCLUDE person p=t.manager_assistant %]
 </li>
 [% END %]

 [% ELSE %]
 <p>Tämä tiimi on vastuussa Kohan seuraavasta versiosta ja nykyisen asennetun Koha-versiosi ylläpidosta. Sama tiimi on toimii tehtävässä päivään <strong>[% t.release_date | $KohaDates %]</strong>, jolloin seuraava tiimi valitaan.</p>

 [% FOREACH s IN t.security_manager %]
 <li><strong>Tietoturvajulkaisun ylläpitäjä:</strong>
 [% INCLUDE person p=s %]
 </li>
 [% END %]

 [% FOREACH m IN t.maintainer %]
 [% IF m.version == ( v ) %]
 <li><strong>Julkaisun ylläpitäjä:</strong>
 [% INCLUDE person p=m %]
 </li>
 [% END %]
 [% END %]
 
 [% IF t.maintainer_assistants %]
 [% FOREACH m IN t.maintainer_assistants %]
 [% IF m.version == ( v ) %]
 <ul><li><strong>Assistentti:</strong> [% INCLUDE person p=m %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 
 [% IF t.maintainer_mentors %]
 [% FOREACH m IN t.maintainer_mentors %]
 [% IF m.version == ( v ) %]
 <ul><li><strong>Mentori:</strong> [% INCLUDE person p=m %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF t.qa_manager %]
 <li><strong>Laadunvarmistusmanageri:</strong>
 [% INCLUDE person p=t.qa_manager %]
 </li>
 [% END %]

 [% IF t.qa %]
 <li><strong>Laadunvarmistusteam:</strong>
 <ul>
 [% FOREACH qa IN t.qa %]
 <li>[% INCLUDE person p=qa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.documentation %]
 [%- IF t.documentation.list.size == 1 %]
 <li><strong>Dokumentaatio-manageri:</strong>
 [% INCLUDE person p=t.documentation %]
 </li>
 [% ELSE %]
 <li><strong>Dokumentaatio-managerit:</strong>
 <ul>
 [% FOREACH doc_manager IN t.documentation %]
 <li>[% INCLUDE person p=doc_manager %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.documentation_team %]
 <li><strong>Dokumentaatio-tiimi:</strong>
 <ul>
 [% FOREACH doc_member IN t.documentation_team %]
 <li>[% INCLUDE person p=doc_member %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.translation %]
 <li><strong>Käännöksen ylläpitäjä:</strong>
 [% INCLUDE person p=t.translation %]
 </li>
 [% END %]

 [% IF t.translations %]
 <li><strong>Käännöksen hallinnointi:</strong>
 <ul>
 [% FOREACH translation_manager IN t.translations %]
 <li>[% INCLUDE person p=translation_manager %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.packaging %]
 [% IF t.packaging.size / 2 == 1 %]
 <li><strong>Paketointipäällikkö:</strong>
 [% INCLUDE person p=t.packaging %]
 </li>
 [% ELSE %]
 <li><strong>Paketointitiimi:</strong>
 <ul>
 [% FOREACH pa IN t.packaging %]
 <li>[% INCLUDE person p = pa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.packaging_assistant %]
 [% IF t.packaging_assistant.size / 2 == 1 %]
 <li><strong>Paketointipäällikön avustaja:</strong>
 [% INCLUDE person p=t.packaging_assistant %]
 </li>
 [% ELSE %]
 <li><strong>Paketointipäällikön avustajat:</strong>
 <ul>
 [% FOREACH pa IN t.packaging_assistant %]
 <li>[% INCLUDE person p = pa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.ci %]
 [% IF t.ci.size == 1 %]
 <li><strong>Jatkuvan integraation ylläpitäjä:</strong>
 [% INCLUDE person p=t.ci.0 %]
 </li>
 [% ELSE %]
 <li><strong>Jatkuvan integraation ylläpitäjät:</strong>
 <ul>
 [% FOREACH j IN t.ci %]
 <li>[% INCLUDE person p=j %]
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.ktd %]
 [% IF t.ktd.size == 1 %]
 <li><strong><a href="https://gitlab.com/koha-community/koha-testing-docker">KTD</a> ylläpitäjä:</strong>
 [% INCLUDE person p=t.ktd.0 %]
 </li>
 [% ELSE %]
 <li><strong><a href="https://gitlab.com/koha-community/koha-testing-docker">KTD</a> ylläpitäjät:</strong>
 <ul>
 [% FOREACH j IN t.ktd %]
 <li>[% INCLUDE person p=j %]
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.bugwrangler %]
 <li><strong>Buginhäätäjät:</strong>
 <ul>
 [% FOREACH bugwrangler IN t.bugwrangler %]
 <li>[% INCLUDE person p=bugwrangler %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.accessibility_advocates %]
 <li><strong>Saavutettavuusasiantuntijat:</strong>
 <ul>
 [% FOREACH a IN t.accessibility_advocates %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.accessibility_advocate %]
 <li><strong>Saavutettavuusasiantuntija:</strong>
 [% INCLUDE person p=t.accessibility_advocate %]
 </li>
 [% END %]

 [% IF t.newsletter %]
 <li><strong>Uutiskirjeen toimittaja:</strong>
 [% INCLUDE person p=t.newsletter %]
 </li>
 [% END %]

 [% IF t.website %]
 <li><strong>Verkkosivuston ylläpitäjä:</strong>
 [% INCLUDE person p=t.website %]
 </li>
 [% END %]

 [% IF t.wiki %]
 [% IF t.wiki.size == 1 %]
 <li><strong>Wikin ylläpitäjä:</strong>
 [% INCLUDE person p=t.wiki %]
 </li>
 [% ELSE %]
 <li><strong>Wiki-tiimi:</strong>
 <ul>
 [% FOREACH wi IN t.wiki %]
 <li>[% INCLUDE person p = wi %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF v != 'release' %]

 <li><strong>Release manager:</strong>
 [% INCLUDE person p=t.manager %]
 </li>

 [% IF t.manager_assistants %]
 <li><strong>Julkaisun ylläpitäjän avustajat:</strong>
 <ul>
 [% FOREACH a IN t.manager_assistants %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.manager_assistant %]
 <li><strong>Julkaisun ylläpitäjän avustaja:</strong>
 [% INCLUDE person p=t.manager_assistant %]
 </li>
 [% END %]

 [% ELSE %]
 <li><strong>Version ylläpitäjät:</strong>
 <ul>
 [% FOREACH m IN t.maintainer %]
 <li>[% m.version | html %] - [% INCLUDE person p=m %]</li>
 [% IF t.maintainer_assistants %]
 [% FOREACH ma IN t.maintainer_assistants %]
 [% IF ma.version == ( m.version ) %]
 <ul><li><strong>Assistentti:</strong> [% INCLUDE person p=ma %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 
 [% IF t.maintainer_mentors %]
 [% FOREACH mm IN t.maintainer_mentors %]
 [% IF m.version == ( mm.version ) %]
 <ul><li><strong>Mentori:</strong> [% INCLUDE person p=mm %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 </ul>
 </li>
 [% END %]
 </ul>
[%- END -%]
