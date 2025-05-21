[% BLOCK registration_form %]
 <div id="registration-form" style="display: none;">
 <div class="alert alert-info">
 <p>Vi rekommenderar molnbaserade autentiseringsappar som t.ex. Authy, Duo Mobile och LastPass. Med dem kan du få tillbaka åtkomsten om du blir av med din mobila enhet.</p>
 <p>Kan inte skanna koden?</p>
 <p>Du kan lägga till informationen för hand genom att ange följande i mobilappen.</p>
 <p>Konto: "<span id="issuer">[% issuer | html %]</span>: <span id="key_id">[% key_id | html %]</span>"</p>
 <p>Nyckel: "<span id="key_secret">[% secret32 | html %]</span>"</p>
 <p>Tidsbaserad: Ja</p>
 </div>

 <div id="errors" class="alert alert-error" style="display: none;"></div>

 <fieldset class="rows">
 <input type="hidden" id="secret32" name="secret32" value="[% secret32 | html %]" />
 <ol>
 <li>
 <label for="qr_code">QR-kod: </label>
 <img id="qr_code" src="" />
 </li>
 <li>
 <label for="pin_code">PIN-kod: </label>
 <input type="text" id="pin_code" name="pin_code" value="" />
 </li>
 </ol>
 </fieldset>
 <fieldset class="action">
 <input class="btn btn-primary" id="register-2FA" type="submit" value="Registrera med tvåfaktorsapp" />
 <a class="cancel" href="/cgi-bin/koha/members/two_factor_auth.pl">Avbryt</a>
 </fieldset>
 </div>
[% END %]
