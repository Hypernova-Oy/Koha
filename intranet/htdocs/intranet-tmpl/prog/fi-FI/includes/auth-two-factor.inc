[% BLOCK registration_form %]
 <div id="registration-form" style="display: none;">
 <div class="alert alert-info">
 <p>Suosittelemme pilvipalveluihin perustuvia mobiilitodennussovelluksia, kuten Authy, Duo Mobile ja LastPass. Ne voivat palauttaa pääsyn, jos hävität laitteesi.</p>
 <p>Koodia ei voi lukea?</p>
 <p>Jos haluat lisätä merkinnän manuaalisesti, anna seuraavat tiedot puhelimesi sovellukselle.</p>
 <p>Tili: "<span id="issuer">[% issuer | html %]</span>: <span id="key_id">[% key_id | html %]</span>"</p>
 <p>Avain: "<span id="key_secret">[% secret32 | html %]</span>"</p>
 <p>Aikaperusteinen: Kyllä</p>
 </div>

 <div id="errors" class="alert alert-error" style="display: none;"></div>

 <fieldset class="rows">
 <input type="hidden" id="secret32" name="secret32" value="[% secret32 | html %]" />
 <ol>
 <li>
 <label for="qr_code">QR-koodi: </label>
 <img id="qr_code" src="" />
 </li>
 <li>
 <label for="pin_code">PIN-koodi: </label>
 <input type="text" id="pin_code" name="pin_code" value="" />
 </li>
 </ol>
 </fieldset>
 <fieldset class="action">
 <input class="btn btn-primary" id="register-2FA" type="submit" value="Rekisteröidy kaksivaiheisella sovelluksella" />
 <a class="cancel" href="/cgi-bin/koha/members/two_factor_auth.pl">Peruuta</a>
 </fieldset>
 </div>
[% END %]
