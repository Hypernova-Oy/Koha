<div id="editor-widget-templates" style="display:none">
 <div id="widget-leader">
 Nimiö:&nbsp;<span title="Tietueen pituus (automaattisesti luotu)">#####</span>
 <select name="f5" title="Tietueen tila">
 <option value="a">a - Koodaustason korotus</option>
 <option value="c">c - Korjattu</option>
 <option value="d">d - Poistettu</option>
 <option value="n">n - Uusi</option>
 <option value="p">p - Päivitetty ennakkotieto</option>
 </select>
 <select name="f6" title="Tietueen tyyppi. Hallitsee kentän 008 oletustyyppiä.">
 <option value="a">a - Tekstiaineisto</option>
 <option value="c">c - Nuottijulkaisu</option>
 <option value="d">d - Nuottikäsikirjoitus</option>
 <option value="e">e - Kartografinen aineisto</option>
 <option value="f">f- Karttakäsikirjoitus</option>
 <option value="g">g- Heijastettava kuva tai viestin</option>
 <option value="i">i- Puheäänite</option>
 <option value="j">j - Musiikkiäänite</option>
 <option value="k">k- Kuva</option>
 <option value="m">m - Elektroninen aineisto</option>
 <option value="o">o- Moniviestin</option>
 <option value="p">p- Sekalainen aineisto</option>
 <option value="r">r- Esine</option>
 <option value="t">t - Tekstikäsikirjoitus</option>
 </select>
 <select name="f7" title="Bibliografinen taso">
 <option value="a">a - Monografinen osakohde</option>
 <option value="b">b - Sarjamainen osakohde</option>
 <option value="c">c - Kokoelma</option>
 <option value="d">d - Osakohde kokoelmassa</option>
 <option value="i">i - Päivittyvä julkaisu</option>
 <option value="m">m - Monografia</option>
 <option value="s">s - Kausijulkaisu</option>
 </select>
 <select name="f8" title="Kontrollityyppi">
 <option value=" ">_ - Ei kontrolloida</option>
 <option value="a">a - Arkistointi</option>
 </select>
 <span title="Koodaus (pakotettu Unicode)">a</span>
 <span title="Indikaattori/osakenttien pituudet">22</span>
 <span title="Tietokantaosoite (automaattisesti luotu)">#####</span>
 <select name="f17" title="Koodaustaso">
 <option value=" ">_ - Kattava taso</option>
 <option value="1">1 - Kattava taso, kuvailun kohde ei ole ollut käsillä</option>
 <option value="2">2 - Kattavaa tasoa niukempi, kuvailun kohde ei ole ollut käsillä</option>
 <option value="3">3 - Ydintasoa niukempi</option>
 <option value="4">4 - Perustaso</option>
 <option value="5">5 - Osittainen (alustava) taso</option>
 <option value="7">7 - Ydintaso</option>
 <option value="8">8 - Ennakkotieto</option>
 [% IF Koha.Preference('UseOCLCEncodingLevels') %]
 <option value="I">I- OCLCn osallistujien täysitasoinen panos</option>
 <option value="J">J- Poistettu tietue</option>
 <option value="K">K- OCLCn osallistujien täysitasoista panosta vähäisempi panos</option>
 <option value="M">M- Lisätty eräprosessista</option>
 [% END %]
 <option value="u">u- Tuntematon</option>
 <option value="z">z - Soveltumaton</option>
 </select>
 <select name="f18" title="Luettelointisäännöt">
 <option value=" ">_ - Ei-ISBD</option>
 <option value="a">a - AACR 2 / Suomalaiset luettelointisäännöt</option>
 <option value="c">c - Ei ISBD-välimerkitystä</option>
 <option value="i">i - ISBD-välimerkitys</option>
 <option value="n">n - Ei-ISBD, ei ISBD-välimerkitystä</option>
 <option value="u">u- Tuntematon</option>
 </select>
 <select name="f19" title="Moniosaisen julkaisun tietueen taso">
 <option value=" ">_ - Ei eritelty tai soveltumaton</option>
 <option value="a">a - Moniosainen julkaisu</option>
 <option value="b">b - Osa, jolla itsenäinen nimeke</option>
 <option value="c">c - Osa, jolla on epäitsenäinen nimeke</option>
 </select>
 <span title="Hakemiston elementtien pituus">4500</span>
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
                    + _("Kontrollinumero: ")
                    + '<span class="control-number-widget-contents"></span>'
                    + '<button class="control-number-widget-assign">' + _("Anna seuraava") + '</button>'
                    + '<select class="control-number-widget-sequence"></select>'
                    + '<button class="control-number-widget-override">' + _("Ohita") + '</button>'
                    + '</span>'
                );

                return $result[0];
            },
            setControlNumber: function( text ) {
                if ( text ) this.setText( text );
                $( this.node ).find('.control-number-widget-contents')
                    .html( text == '<empty>' ? ( '<span class="hint">' + _("peru asetus") + '</span>' ) : text );
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
                        var result = prompt( _("Syötä uusi kontrollinumero") );

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
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Päivitetty: ") + '</span>' );

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
                $( this.node ).append( '<span class="hint">' + _("peru asetus") + '</span>' );
            }
        }
    } );

    Widget.Register( '006@', {
        makeTemplate: function() {
            return "a                 ";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Kiinteämittainen tieto:") + '<span class="hint widget-loading">' + _("Ladataan...") + '</span></span>' );

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
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Kiinteämittainen tieto:") + '<span class="hint widget-loading">' + _("Ladataan...") + '</span></span>' );

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
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Kiinteämittainen tieto:") + '<span class="hint widget-loading">' + _("Ladataan...") + '</span></span>' );

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
