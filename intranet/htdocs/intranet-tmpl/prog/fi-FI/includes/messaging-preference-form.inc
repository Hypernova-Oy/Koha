[% USE Koha %]
<!-- snippet for form to set borrower and patron category messaging preferences -->

<input type="hidden" name="modify" value="yes" />
<input type="hidden" name="borrowernumber" value="[% borrowernumber | html %]" />
 <table>
 <thead>
 <tr><th></th>
 <th>Päivää etukäteen</th>
 [% IF Koha.Preference('SMSSendDriver') %]<th>Tekstiviesti</th>[% END %]
 [% IF Koha.Preference('TalkingTechItivaPhoneNotification') || Koha.Preference('PhoneNotification') %]<th>Puhelin</th>[% END %]
 <th>Sähköposti</th>
 <th>Vain koosteilmoitus <i class="fa fa-info-circle" data-bs-placement="right" data-bs-toggle="tooltip" id="info_digests" title="Koosteviestin valinta vähentää viestien määrää. Viestit tallennetaan ja lähetetään yhtenä viestinä."></i></th>
 <!-- <th>RSS</th> -->
 </tr>
 </thead>
 <tbody>
 [% FOREACH messaging_preference IN messaging_preferences %]
 [% NEXT IF !Koha.Preference( 'ILLModule' ) && messaging_preference.message_name.match('^Ill_') %]
 [% NEXT IF messaging_preference.Auto_Renewals && Koha.Preference('AutoRenewalNotices') != 'preferences' %]
 [% NEXT IF !Koha.Preference('UseRecalls') && messaging_preference.message_name.match('^Recall_') %]
 <tr id="[% messaging_preference.message_name _ "_message" | lower | html %]">
 <td>[% IF ( messaging_preference.Item_Due ) %]<span>Ilmoitus eräpäivänä</span>
 [% ELSIF ( messaging_preference.Advance_Notice ) %]<span>Ennakkoilmoitus</span>
 [% ELSIF ( messaging_preference.Hold_Filled ) %]<span>Saapumisilmoitus</span>
 [% ELSIF ( messaging_preference.Hold_Reminder ) %]<span>Varauksen noutomuistutus</span>
 [% ELSIF ( messaging_preference.Item_Check_in ) %]<span>Palautuskuitti</span>
 [% ELSIF ( messaging_preference.Item_Checkout ) %]
 [% IF Koha.Preference( 'RenewalSendNotice' ) %]
 <span>Lainaus ja uusinta</span>
 [% ELSE %]
 <span>Lainauskuitti</span>
 [% END %]
 [% ELSIF ( messaging_preference.Ill_ready ) %]<span>Kaukolainan saapumisilmoitus</span>
 [% ELSIF ( messaging_preference.Ill_unavailable ) %]<span>Kaukolaina ei saatavilla</span>
 [% ELSIF ( messaging_preference.Ill_update ) %]<span>Kaukolaina on päivitetty</span>
 [% ELSIF ( messaging_preference.Auto_Renewals ) %]<span>Automaattinen uusinta</span>
 [% ELSIF ( messaging_preference.Recall_Waiting ) %]<span>Noudettavissa oleva takaisinkutsuttu</span>
 [% ELSIF ( messaging_preference.Recall_Requested ) %]<span>Palauta takaisinkutsuttu nide</span>
 [% ELSE %]<span>Tuntematon</span>
 [% END %]
 </td>
 [% IF ( messaging_preference.takes_days ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 <select name="[% messaging_preference.message_attribute_id | html %]-DAYS" disabled="disabled">
 [% ELSE %]
 <select name="[% messaging_preference.message_attribute_id | html %]-DAYS">
 [% END %]
 [% FOREACH select_day IN messaging_preference.select_days %]
 [% IF ( select_day.selected ) %]<option value="[% select_day.day | html %]" selected="selected">[% select_day.day | html %]</option>[% ELSE %]
 <option value="[% select_day.day | html %]">[% select_day.day | html %]</option>
 [% END %]
 [% END %]
 </select>
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]

 [% IF Koha.Preference('SMSSendDriver') %]
 [% IF ( messaging_preference.transport_sms ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.transports_sms ) %]
 <input type="checkbox"
                 id="sms[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="sms" class="pmp_sms" checked="checked" disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
                 id="sms[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="sms" class="pmp_sms" disabled="disabled" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.transports_sms ) %]
 <input type="checkbox"
                 id="sms[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="sms" checked="checked" class="pmp_sms active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input type="checkbox"
                 id="sms[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="sms" class="pmp_sms active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]
 [% END %]

 [% IF Koha.Preference('TalkingTechItivaPhoneNotification') %]
 [% IF ( messaging_preference.transport_itiva ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.transports_itiva ) %]
 <input type="checkbox"
                 id="itiva[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="itiva" checked="checked" disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
                 id="itiva[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="itiva" disabled="disabled" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.transports_itiva ) %]
 <input type="checkbox"
                 id="itiva[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="itiva" checked="checked" class="pmp_phone active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input type="checkbox"
                 id="itiva[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="itiva" class="pmp_phone active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]
 [% ELSIF Koha.Preference('PhoneNotification') %]
 [% IF ( messaging_preference.transport_phone ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.transports_phone ) %]
 <input type="checkbox"
                 id="phone[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="phone" checked="checked" disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
                 id="phone[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="phone" disabled="disabled" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.transports_phone ) %]
 <input type="checkbox"
                 id="phone[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="phone" checked="checked" class="pmp_phone active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input type="checkbox"
                 id="phone[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="phone" class="pmp_phone active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]
 [% END %]

 [% IF ( messaging_preference.transport_email ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.transports_email ) %]
 <input type="checkbox"
                   id="email[% messaging_preference.message_attribute_id | html %]"
                   name="[% messaging_preference.message_attribute_id | html %]"
                   value="email" class="pmp_email" checked="checked" disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
                   id="email[% messaging_preference.message_attribute_id | html %]"
                   name="[% messaging_preference.message_attribute_id | html %]"
                   value="email" class="pmp_email" disabled="disabled" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.transports_email ) %]
 <input type="checkbox"
                 id="email[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="email" checked="checked" class="pmp_email active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input type="checkbox"
                 id="email[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="email" class="pmp_email active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]

 [% IF ( messaging_preference.has_digest ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.digest ) %]
 <input checked="checked" class="pmp_digest" data-bs-toggle="tooltip" disabled="disabled" id="digest[% messaging_preference.message_attribute_id | html %]" name="digest" title="Koosteen voi valita vain kooste-yhteensopivalle viestityypille" type="checkbox" value="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input class="pmp_digest" data-bs-toggle="tooltip" disabled="disabled" id="digest[% messaging_preference.message_attribute_id | html %]" name="digest" title="Koosteen voi valita vain kooste-yhteensopivalle viestityypille" type="checkbox" value="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.digest ) %]
 <input checked="checked" class="pmp_digest active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" data-bs-toggle="tooltip" id="digest[% messaging_preference.message_attribute_id | html %]" name="digest" title="Koosteen voi valita vain kooste-yhteensopivalle viestityypille" type="checkbox" value="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input class="pmp_digest active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" data-bs-toggle="tooltip" id="digest[% messaging_preference.message_attribute_id | html %]" name="digest" title="Koosteen voi valita vain kooste-yhteensopivalle viestityypille" type="checkbox" value="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]

<!-- [% IF ( messaging_preference.transport_rss ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 <input type="checkbox"
 id="rss[% messaging_preference.message_attribute_id | html %]"
 name="[% messaging_preference.message_attribute_id | html %]"
 value="rss" [% messaging_preference.transport_rss | html %] disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
 id="rss[% messaging_preference.message_attribute_id | html %]"
 name="[% messaging_preference.message_attribute_id | html %]"
 value="rss" [% messaging_preference.transport_rss | html %] class="active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %] -->

 </tr>
 [% END %]
 </tbody>
 </table>
