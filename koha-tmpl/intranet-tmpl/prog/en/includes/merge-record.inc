[% BLOCK sourcetab %]
    <div class="record">
        <ul id="ulrecord[% record.recordid | html %]">
            [% FOREACH field IN record.display %]
                [% IF field.tag != biblionumbertag %]
                    <li id="k[% field.key | html %]">
                        [% IF (tabrecord.reference) %]
                            <input type="checkbox" checked="checked" class="fieldpick" id="rec_[% record.recordid | html %]_[% field.key | html %]" />
                        [% ELSE %]
                            <input type="checkbox" class="fieldpick" id="rec_[% record.recordid | html %]_[% field.key | html %]" />
                        [% END %]
                        <label for="rec_[% record.recordid | html %]_[% field.key | html %]"><span class="field">[% field.tag | html %]</span></label>

                        <input type="hidden" name="tag_[% field.tag | html %]_indicator1_[% field.key | html %]" value="[% field.indicator1 | html %]" />
                        <input type="hidden" name="tag_[% field.tag | html %]_indicator2_[% field.key | html %]" value="[% field.indicator2 | html %]" />
                        [% IF ( field.value ) %]
                            / [% field.value | html %]
                            <input type="hidden" name="tag_[% field.tag | html %]_code_00_[% field.key | html %]" value="00" />
                            <input type="hidden" name="tag_[% field.tag | html %]_subfield_00_[% field.key | html %]" value="[% field.value | html %]" />
                        [% END %]

                        [% IF ( field.subfield.size ) %]
                            <ul>
                                [% FOREACH subfield IN field.subfield %]
                                    <li id="k[% subfield.subkey | html %]">
                                        [% IF (tabrecord.reference) %]
                                            <input type="checkbox" checked="checked" class="subfieldpick" id="rec_[% record.recordid | html %]_[% subfield.subkey | html %]" />
                                        [% ELSE %]
                                            <input type="checkbox" class="subfieldpick" id="rec_[% record.recordid | html %]_[% subfield.subkey | html %]" />
                                        [% END %]
                                        <label for="rec_[% record.recordid | html %]_[% subfield.subkey | html %]"><span class="subfield">[% subfield.subtag | html %]</span> / [% subfield.value | html %]</label>
                                        <input type="hidden" name="tag_[% field.tag | html %]_code_[% subfield.subtag | html %]_[% field.key | html %]_[% subfield.subkey | html %]" value="[% subfield.subtag | html %]" />
                                        <input type="hidden" name="tag_[% field.tag | html %]_subfield_[% subfield.subtag | html %]_[% subfield.key | html %]_[% subfield.subkey | html %]" value="[% subfield.value | html %]" />
                                    </li>
                                [% END %]
                            </ul>
                        [% END %]
                    </li>
                [% END %]
            [% END %]
        </ul> </div
    ><!-- /div.record -->
[% END %]

[% BLOCK mergesource %]

    [% WRAPPER tabs id= "tabs" %]
        <h2>Source records</h2>
        [% WRAPPER tabs_nav %]
            [% FOREACH record IN sourcerecords %]
                [% WRAPPER tab_item tabname= "tabrecord${record.recordid}" %]
                    [% record.recordid | html %]
                    [% IF record.reference %]<span>(ref)</span>[% END %]
                    <span>([% record.frameworktext | html %])</span>
                [% END %]
            [% END %]
        [% END # /WRAPPER tabs_nav %]

        [% WRAPPER tab_panels %]
            [% IF ( sourcerecords.size ) %]
                [% FOREACH record IN sourcerecords %]
                    [% WRAPPER tab_panel tabname="tabrecord${record.recordid}" %]
                        [% PROCESS sourcetab tabrecord=record %]
                    [% END %]
                [% END %]
            [% END %]
        [% END # /WRAPPER tab_panels %]
    [% END # /WRAPPER tabs %]
[% END %]

[% BLOCK mergetarget %]
    <h2>Destination record ([% authtypetext | html %])</h2>
    <div id="result" class="page-section">
        <ul id="resultul"></ul>
    </div>
    <!-- // #result -->
[% END %]
