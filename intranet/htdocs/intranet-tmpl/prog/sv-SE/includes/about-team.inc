[%- BLOCK role -%]
 [% matches = role.key.match('(\w+):?(.*)?') %]
 [% ro = matches.0 %]
 [% ex = matches.1 %]
 [%- SWITCH ro -%]

 [%- CASE 'manager' -%]
 <span>Versionsansvarig</span>
 [%- CASE 'manager_assistant' -%]
 <span>Versionsansvariges assistent</span>
 [%- CASE 'manager_assistants' -%]
 <span>Release manager assistants</span>
 [%- CASE 'manager_mentor' -%]
 <span>Versionsansvariges mentor</span>
 [%- CASE 'qa_manager' -%]
 <span>Chef för kvalitetssäkring</span>
 [%- CASE 'qa' -%]
 <span>Grupp för kvalitetssäkring</span>
 [%- CASE 'documentation' -%]
 <span>Dokumentationsansvarig</span>
 [%- CASE 'documentation_team' -%]
 <span>Dokumentationsteam</span>
 [%- CASE 'translation' -%]
 <span>Översättningsansvarig</span>
 [%- CASE 'translations' -%]
 <span>Översättningsansvariga</span>
 [%- CASE 'translation_assistant' -%]
 <span>Assistent till översättningsansvarig</span>
 [%- CASE 'te' -%]
 <span>Ämnesexpert</span>
 [%- CASE 'bugwrangler' -%]
 <span>Bugghanterare</span>
 [%- CASE 'maintainer' -%]
 <span>Versionsansvariga</span>
 [%- CASE 'maintainer_assistant' -%]
 <span>Versionsansvariges assistent</span>
 [%- CASE 'maintainer_assistants' -%]
 <span>Release maintainer assistants</span>
 [%- CASE 'maintainer_mentor' -%]
 <span>Versionsansvariges mentor</span>
 [%- CASE 'maintainer_mentors' -%]
 <span>Release maintainer mentors</span>
 [%- CASE 'wiki' -%]
 <span>Wiki-ansvarig</span>
 [%- CASE 'ci' -%]
 <span>CI-ansvarig</span>
 [%- CASE 'packaging' -%]
 <span>Förpackningsansvarig</span>
 [%- CASE 'packaging_assistant' -%]
 <span>Assistent till paketeringsansvarig</span>
 [%- CASE 'chairperson' -%]
 <span>Mötesordförande</span>
 [%- CASE 'newsletter' -%]
 <span>Redaktör för nyhetsbrev</span>
 [%- CASE 'mm' -%]
 <span>Modulansvarig</span>
 [%- CASE 'vm' -%]
 <span>Ansvarig för virtuella maskiner</span>
 [%- CASE 'database' -%]
 <span>Dokumentationsspecialist</span>
 [%- CASE 'live_cd' -%]
 <span>Ansvarig för Live-CD</span>
 [%- CASE 'accessibility_advocate' -%]
 <span>Tillgänglighetsförespråkare</span>
 [%- CASE 'accessibility_advocates' -%]
 <span>Accessibility advocates</span>
 [%- CASE 'meeting_facilitator' -%]
 <span>Mötesspecialist</span>
 [%- CASE 'ktd' -%]
 <span>Utvecklarverktyg</span>
 [%- CASE 'website' -%]
 <span>Hemsidans administratör</span>
 [%- CASE 'social_media' -%]
 <span>Social media manager</span>
 [%- CASE 'security_manager' -%]
 <span>Säkerhetsreleasehanterare</span>
 [%- CASE -%]
 <span>SAKNAD MAPPNING FÖR ROLL: [% role.key | html %]</span>
 [%- END -%]
 [%- IF ex %]- [% ex | html %][% END -%]
[%- END -%]

[%- BLOCK person -%]
 [% IF p.openhub %]<a href="[% p.openhub | url %]">[% p.name | html %]</a>[% ELSE %][% p.name | html %][% END %]
[%- END -%]

[%- BLOCK contributions -%]
 [%- IF p.roles || p.notes -%]
 <ul>
 [% FOREACH r IN p.roles %]
 [% SET sorted_versions = r.value.sort.reverse %]
 <li>
 [% INCLUDE role role=r %]
 ([% IF sorted_versions.size <= 2 %]
 [% sorted_versions.join(', ') | html %]
 [% ELSE %]
 [% sorted_versions.slice(0,1).join(', ') | html %]<span class="version-ellipsis" data-bs-toggle="tooltip" title="[% sorted_versions.slice(2, -1).join(', ') | html %]">, ...</span>
 [% END %])
 </li>
 [% END %]
 [% IF p.notes %]<li>[% p.notes | html %]</li>[% END %]
 </ul>
 [%- END -%]
[%- END -%]

[%- BLOCK team -%]
 <ul>
 [% IF v == 'release' %]
 <p>Det här är den grupp som var ansvarig för den första utgåvan av den Koha-version du har installerad.</p>

 <li
                ><strong>Versionsansvarig:</strong>
 [% INCLUDE person p=t.manager %]
 </li>

 [% IF t.manager_assistants %]
 <li
                    ><strong>Release manager assistant:</strong>
 <ul>
 [% FOREACH a IN t.manager_assistants %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.manager_assistant %]
 <li
                    ><strong>Release manager assistent:</strong>
 [% INCLUDE person p=t.manager_assistant %]
 </li>
 [% END %]
 [% ELSE %]
 <p
                >Det här är den grupp som är ansvarig för nästa version av Koha och det löpande underhållet av den Koha-version du har installerad. De kommer att ha dessa roller till <strong>[% t.release_date | $KohaDates %]</strong>, när nästa team kommer väljas.</p
            >

 [% FOREACH s IN t.security_manager %]
 <li
                    ><strong>Säkerhetsreleasehanterare:</strong>
 [% INCLUDE person p=s %]
 </li>
 [% END %]

 [% FOREACH m IN t.maintainer %]
 [% IF m.version == ( v ) %]
 <li
                        ><strong>Versionsansvariga:</strong>
 [% INCLUDE person p=m %]
 </li>
 [% END %]
 [% END %]

 [% IF t.maintainer_assistants %]
 [% FOREACH m IN t.maintainer_assistants %]
 [% IF m.version == ( v ) %]
 <ul
                            ><li><strong>Assistent:</strong> [% INCLUDE person p=m %]</li></ul
                        >
 [% END %]
 [% END %]
 [% END %]

 [% IF t.maintainer_mentors %]
 [% FOREACH m IN t.maintainer_mentors %]
 [% IF m.version == ( v ) %]
 <ul
                            ><li><strong>Mentor:</strong> [% INCLUDE person p=m %]</li></ul
                        >
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF t.qa_manager %]
 <li
                ><strong>Chef för kvalitetssäkring:</strong>
 [% INCLUDE person p=t.qa_manager %]
 </li>
 [% END %]

 [% IF t.qa %]
 <li
                ><strong>Grupp för kvalitetssäkring:</strong>
 <ul>
 [% FOREACH qa IN t.qa %]
 <li>[% INCLUDE person p=qa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.documentation %]
 [%- IF t.documentation.list.size == 1 %]
 <li
                    ><strong>Dokumentationschef:</strong>
 [% INCLUDE person p=t.documentation %]
 </li>
 [% ELSE %]
 <li
                    ><strong>Dokumentationschef(er):</strong>
 <ul>
 [% FOREACH doc_manager IN t.documentation %]
 <li>[% INCLUDE person p=doc_manager %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.documentation_team %]
 <li
                ><strong>Dokumentationsteam:</strong>
 <ul>
 [% FOREACH doc_member IN t.documentation_team %]
 <li>[% INCLUDE person p=doc_member %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.translation %]
 <li
                ><strong>Översättningsansvarig:</strong>
 [% INCLUDE person p=t.translation %]
 </li>
 [% END %]

 [% IF t.translations %]
 <li
                ><strong>Översättningsansvariga:</strong>
 <ul>
 [% FOREACH translation_manager IN t.translations %]
 <li>[% INCLUDE person p=translation_manager %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.packaging %]
 [% IF t.packaging.size / 2 == 1 %]
 <li
                    ><strong>Förpackningsansvarig:</strong>
 [% INCLUDE person p=t.packaging %]
 </li>
 [% ELSE %]
 <li
                    ><strong>Förpackningsansvarig:</strong>
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
 <li
                    ><strong>Assistent till paketeringsansvarig:</strong>
 [% INCLUDE person p=t.packaging_assistant %]
 </li>
 [% ELSE %]
 <li
                    ><strong>Assistent till paketeringsansvarig:</strong>
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
 <li
                    ><strong>CI-ansvarig:</strong>
 [% INCLUDE person p=t.ci.0 %]
 </li>
 [% ELSE %]
 <li
                    ><strong>CI-ansvarig:</strong>
 <ul>
 [% FOREACH j IN t.ci %]
 <li>[% INCLUDE person p=j %] </li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.ktd %]
 [% IF t.ktd.size == 1 %]
 <li
                    ><strong><a href="https://gitlab.com/koha-community/koha-testing-docker">KTD</a> underhållsansvarig:</strong>
 [% INCLUDE person p=t.ktd.0 %]
 </li>
 [% ELSE %]
 <li
                    ><strong><a href="https://gitlab.com/koha-community/koha-testing-docker">KTD</a> Versionsansvariga:</strong>
 <ul>
 [% FOREACH j IN t.ktd %]
 <li>[% INCLUDE person p=j %] </li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.bugwrangler %]
 <li
                ><strong>Bugghanterare:</strong>
 <ul>
 [% FOREACH bugwrangler IN t.bugwrangler %]
 <li>[% INCLUDE person p=bugwrangler %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.accessibility_advocates %]
 <li
                ><strong>Tillgänglighetsförespråkare:</strong>
 <ul>
 [% FOREACH a IN t.accessibility_advocates %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.accessibility_advocate %]
 <li
                ><strong>Tillgänglighetsförespråkare:</strong>
 [% INCLUDE person p=t.accessibility_advocate %]
 </li>
 [% END %]

 [% IF t.newsletter %]
 <li
                ><strong>Redaktör för nyhetsbrev:</strong>
 [% INCLUDE person p=t.newsletter %]
 </li>
 [% END %]

 [% IF t.website %]
 <li
                ><strong>Webansvarig:</strong>
 [% INCLUDE person p=t.website %]
 </li>
 [% END %]

 [% IF t.social_media %]
 <li
                ><strong>Social media manager:</strong>
 [% INCLUDE person p=t.social_media %]
 </li>
 [% END %]

 [% IF t.wiki %]
 [% IF t.wiki.size == 1 %]
 <li
                    ><strong>Wiki-ansvarig:</strong>
 [% INCLUDE person p=t.wiki %]
 </li>
 [% ELSE %]
 <li
                    ><strong>Wiki-team:</strong>
 <ul>
 [% FOREACH wi IN t.wiki %]
 <li>[% INCLUDE person p = wi %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.meeting_facilitator %]
 <li
                ><strong>Meeting facilitator:</strong>
 [% INCLUDE person p=t.meeting_facilitator %]
 </li>
 [% END %]

 [% IF t.chairperson %]
 <li
                ><strong>Meetings chairperson:</strong>
 [% INCLUDE person p=t.chairperson %]
 </li>
 [% END %]

 [% IF t.database %]
 <li
                ><strong>Documentation specialist:</strong>
 [% INCLUDE person p=t.database %]
 </li>
 [% END %]

 [% IF t.live_cd %]
 <li
                ><strong>Live CD maintainer:</strong>
 [% INCLUDE person p=t.live_cd %]
 </li>
 [% END %]

 [% IF t.vm %]
 <li
                ><strong>Virtual machine maintainer:</strong>
 [% INCLUDE person p=t.vm %]
 </li>
 [% END %]

 [% IF t.translation_assistant %]
 <li
                ><strong>Translation manager assistant:</strong>
 [% INCLUDE person p=t.translation_assistant %]
 </li>
 [% END %]

 [% IF v != 'release' %]
 <li
                ><strong>Versionsansvarig:</strong>
 [% INCLUDE person p=t.manager %]
 </li>

 [% IF t.manager_assistants %]
 <li
                    ><strong>Release manager assistant:</strong>
 <ul>
 [% FOREACH a IN t.manager_assistants %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.manager_assistant %]
 <li
                    ><strong>Release manager assistent:</strong>
 [% INCLUDE person p=t.manager_assistant %]
 </li>
 [% END %]
 [% ELSE %]
 <li
                ><strong>Versionsansvariga:</strong>
 <ul>
 [% FOREACH m IN t.maintainer %]
 <li>[% m.version | html %] - [% INCLUDE person p=m %]</li>
 [% IF t.maintainer_assistants %]
 [% FOREACH ma IN t.maintainer_assistants %]
 [% IF ma.version == ( m.version ) %]
 <ul
                                        ><li><strong>Assistent:</strong> [% INCLUDE person p=ma %]</li></ul
                                    >
 [% END %]
 [% END %]
 [% END %]

 [% IF t.maintainer_mentors %]
 [% FOREACH mm IN t.maintainer_mentors %]
 [% IF m.version == ( mm.version ) %]
 <ul
                                        ><li><strong>Mentor:</strong> [% INCLUDE person p=mm %]</li></ul
                                    >
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 </ul>
 </li>
 [% END %]
 </ul>
[%- END -%]
