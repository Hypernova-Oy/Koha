<div id="editor-widget-templates" style="display:none">
 <div id="widget-leader">
 Ledare:&nbsp;<span title="Postlängd (automatiskt genererad)">#####</span>
 <select name="f5" title="Poststatus">
 <option value="a">a - Ökning av kodningsnivå</option>
 <option value="c">c - Korrigerad eller reviderad</option>
 <option value="d">d - Borttagen</option>
 <option value="n">n - Ny</option>
 <option value="p">p - Ökning i kodningsnivå från förpublikation</option>
 </select>
 <select name="f6" title="Type of record. Controls default type of 008 field.">
 <option value="a">a - Språkmaterial</option>
 <option value="c">c - Notskrift</option>
 <option value="d">d - Manuskript med notskrift</option>
 <option value="e">e - Kartografiskt material</option>
 <option value="f">f - Manuscript cartographic material</option>
 <option value="g">g - Projected medium</option>
 <option value="i">i - Nonmusical sound recording</option>
 <option value="j">j - Musikinspelning</option>
 <option value="k">k - Two-dimensional nonprojectable graphic</option>
 <option value="m">m - Datorfil</option>
 <option value="o">o - Kit</option>
 <option value="p">p - Mixed materials</option>
 <option value="r">r - Three-dimensional artifact or naturally occurring object</option>
 <option value="t">t - Manuscript language material</option>
 </select>
 <select name="f7" title="Bibliografisk nivå">
 <option value="a">a - Monografisk komponent</option>
 <option value="b">b - Seriekomponentdel</option>
 <option value="c">c- Avdelning</option>
 <option value="d">d - Underenhet</option>
 <option value="i">i - Integrerande resurs</option>
 <option value="m">m - Monograf/exemplar</option>
 <option value="s">s - Serie</option>
 </select>
 <select name="f8" title="Kontrolltyp">
 <option value=" ">_ - Ingen specifik typ</option>
 <option value="a">a - Arkiv</option>
 </select>
 <span title="Kodning (tvingad Unicode)">a</span>
 <span title="Längder indikator/delfält">22</span>
 <span title="Databasadress (automatiskt genererad)">#####</span>
 <select name="f17" title="Kodningsnivå">
 <option value=" ">_ - Full nivå</option>
 <option value="1">1 - Full nivå, material inte undersökt</option>
 <option value="2">2 - Less-than-full level, material not examined</option>
 <option value="3">3 - Förkortad nivå</option>
 <option value="4">4 - Kärnnivå</option>
 <option value="5">5 - Delnivå (preliminär)</option>
 <option value="7">7 - Lägsta nivå</option>
 <option value="8">8 - Förpubliceringsnivå</option>
 [% IF Koha.Preference('UseOCLCEncodingLevels') %]
 <option value="I">I- Full-level input by OCLC participants</option>
 <option value="J">J- Raderad post</option>
 <option value="K">K- Less-than-full input by OCLC participants</option>
 <option value="M">M- Added from a batch process</option>
 [% END %]
 <option value="u">u - Okänd</option>
 <option value="z">z - Ej tillämplig</option>
 </select>
 <select name="f18" title="Beskrivande katalogiseringsform">
 <option value=" ">_ - Ej-ISBD</option>
 <option value="a">a - AACR 2</option>
 <option value="c">c - ISBD-punktuation utelämnad</option>
 <option value="i">i - ISBD-punktuation medtagen</option>
 <option value="n">n - Non-ISBD punctuation omitted</option>
 <option value="u">u - Okänd</option>
 </select>
 <select name="f19" title="Resursnivå för post med flera delar">
 <option value=" ">_ - Ej specificerad eller ej tillämplig</option>
 <option value="a">a - Set</option>
 <option value="b">b - Del med oberoende titel</option>
 <option value="c">c - Del med avhängig titel</option>
 </select>
 <span title="Längd på katalogelement">4500</span>
 </div>
</div>
<!-- cateditor-widgets-marc21.inc -->
<script>

/**
 * Each widget should provide one to three methods:
 *   init( text ): Returns the DOM node for this widget.
 *   postCreate( node, mark ): Optional, called once the mark has been created
 *                             and the node shown. Bind event handlers here.
 *   makeTemplate(): Optional, should return some sane default contents for a
 *                   newly created field/subfield. '<empty>' will be used if this
 *                   method is unset.
 *
 * Following the Koha convention, control fields are defined as tags with a
 * single subfield, '@'.
 */

require( [ 'koha-backend', 'widget', 'text-marc' ], function( KohaBackend, Widget, TextMarc ) {
    Widget.Register( '000@', {
        makeTemplate: function() {
            return '     nam a22     7a 4500';
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget"></span>' );

            return $result[0];
        },
        postCreate: function() {
            // Clear the length and directory start fields; these are unnecessary for MARCXML and will be filled in upon USMARC export
            this.setFixed( 0, 5, '     ' );
            this.setFixed( 9, 17, 'a22     ' );
            this.setFixed( 20, 24, '4500' );

            this.insertTemplate( '#widget-leader' );

            this.bindFixed( '[name=f5]', 5, 6 );
            this.bindFixed( '[name=f6]', 6, 7 );
            this.bindFixed( '[name=f7]', 7, 8 );
            this.bindFixed( '[name=f8]', 8, 9 );
            this.bindFixed( '[name=f17]', 17, 18 );
            this.bindFixed( '[name=f18]', 18, 19 );
            this.bindFixed( '[name=f19]', 19, 20 );
        },
    } );

    /* Check to see if there are any Control Number entries
     *  in the authorised values table.
     * If not, let's not show the widget
     */
    var reg001 = KohaBackend.GetAuthorisedValues( 'CONTROL_NUM_SEQUENCE');
    if(reg001) {

        Widget.Register( '001@', {
            init: function() {
                var $result = $(
                    '<span class="subfield-widget">'
                    + _("Kontrollnummer: ")
                    + '<span class="control-number-widget-contents"></span>'
                    + '<button class="control-number-widget-assign">' + _("Assign next") + '</button>'
                    + '<select class="control-number-widget-sequence"></select>'
                    + '<button class="control-number-widget-override">' + _("Åsidosätt") + '</button>'
                    + '</span>'
                );

                return $result[0];
            },
            setControlNumber: function( text ) {
                if ( text ) this.setText( text );
                $( this.node ).find('.control-number-widget-contents')
                    .html( text == '<empty>' ? ( '<span class="hint">' + _("ta bort") + '</span>' ) : text );
                this.mark.changed();
            },
            postCreate: function( node, mark ) {
                var widget = this;
                this.setControlNumber( this.text );
                $( this.node )
                    .find('.control-number-widget-assign').click( function() {
                        var sequence = $( widget.node ).find('.control-number-widget-sequence').val();
                        const csrf_token = document.querySelector('meta[name="csrf-token"]').getAttribute('content');
                        $.post(
                            '/cgi-bin/koha/svc/cataloguing/control_num_sequences/' + sequence,
                            { csrf_token: csrf_token }
                        ).done( function( result ) {
                            if ( result.next_value ) widget.setControlNumber( result.next_value );
                        } );
                    } ).end()
                    .find('.control-number-widget-override').click( function() {
                        var result = prompt( _("Ange nytt kontrollnummer") );

                        if ( result ) widget.setControlNumber( result );
                    } ).end();

                var sequence_list = $.map( reg001 , function( authval ) {
                    return authval.lib;
                } );
                sequence_list.sort();

                $.each( sequence_list, function( undef, sequence ) {
                    $( widget.node ).find('.control-number-widget-sequence').append( '<option>' + sequence + '</option>' );
                } );

                // TODO: Make Enter on select click "Assign"
            }
        } );
        };

    Widget.Register( '005@', {
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Uppdaterad: ") + '</span>' );

            return $result[0];
        },
        postCreate: function( node, mark ) {
            var parts = this.text.match( /(\d{4})(\d{2})(\d{2})(\d{2})(\d{2})(\d{2})\.(\d)/ );

            if ( parts ) {
                var dateVal = new Date(
                    parseInt( parts[1] ), // Year
                    parseInt( parts[2] ) - 1, // Month (0-11)
                    parseInt( parts[3] ), // Day
                    parseInt( parts[4] ), // Hour
                    parseInt( parts[5] ), // Minute
                    parseInt( parts[6] ), // Second
                    parseInt( parts[7] ) * 100 // Millisecond
                );

                $( this.node ).append( dateVal.toLocaleString() );
            } else {
                $( this.node ).append( '<span class="hint">' + _("ta bort") + '</span>' );
            }
        }
    } );

    Widget.Register( '006@', {
        makeTemplate: function() {
            return "a                 ";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Fasta data:") + '<span class="hint widget-loading">' + _("Laddar...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: 'BKS',
            c: 'MU',
            d: 'MU',
            e: 'MPS',
            f: 'MPS',
            g: 'VM',
            i: 'MU',
            j: 'MU',
            k: 'VM',
            m: 'CF',
            o: 'VM',
            p: 'MX',
            r: 'VM',
            s: 'CR',
            t: 'BKS',
        },
        getMaterial: function () {
            return this.materialTypeMapping[this.text.substring(0, 1)];
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/006' );
        }
    } );

    Widget.Register( '007@', {
        makeTemplate: function() {
            return "a       ";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Fasta data:") + '<span class="hint widget-loading">' + _("Laddar...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: 'MPS',
            c: 'ER',
            d: 'GL',
            f: 'TM',
            g: 'PG',
            h: 'MF',
            k: 'NG',
            m: 'MP',
            o: 'KT',
            q: 'NM',
            r: 'RI',
            s: 'SR',
            t: 'TC',
            v: 'VR',
            z: 'UN'
        },
        getMaterial: function () {
            return this.materialTypeMapping[this.text.substring(0, 1)];
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/007' ).then(() => {
                $(this.node).find('.material-select').on('change', (e) => {
                    const keys = Object.keys(this.materialTypeMapping);
                    const k = keys.filter(k => this.materialTypeMapping[k] === $(e.target).val());
                    this.setFixed(0, 1, k, '+input');

                    // FIXME There must be a better way to update display
                    const n = $(this.node).find('[name="f00"]');
                    n.triggerHandler('focus');
                    n.triggerHandler('blur');
                });
            });
        }
    } );

    Widget.Register( '008@', {
        makeTemplate: function() {
            var now = new Date();
            return Widget.PadNum( now.getYear() % 100, 2 ) + Widget.PadNum( now.getMonth() + 1, 2 ) + Widget.PadNum( now.getDate(), 2 ) + "b        [% DefaultCountryField008 | html %]||||| |||| 00| 0 [% DefaultLanguageField008 | html %] d";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Fasta data:") + '<span class="hint widget-loading">' + _("Laddar...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: {
                a: 'BKS', c: 'BKS', d: 'BKS', m: 'BKS',
                b: 'CR', i: 'CR', s: 'CR',
            },
            t: 'BKS',
            c: 'MU', d: 'MU', i: 'MU', j: 'MU',
            e: 'MP', f: 'MP',
            g: 'VM', k: 'VM', o: 'VM', r: 'VM',
            m: 'CF',
            p: 'MX',
        },
        getMaterial: function () {
            const record = TextMarc.TextToRecord(this.editor.cm.getValue());

            const leader = record.leader();
            const leader6 = leader.substring(6, 7);
            let materialType = this.materialTypeMapping[leader6];
            if (typeof materialType === 'object') {
                const leader7 = leader.substring(7, 8);
                materialType = materialType[leader7];
            }

            return materialType;
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/008' );
        }
    } );
} );

</script>
<!-- / cateditor-widgets-marc21.inc -->
