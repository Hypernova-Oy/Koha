<!-- validator-strings.inc -->
<script>
    $(document).ready(function(){
        jQuery.extend(jQuery.validator.messages, {
            required: _("Tämä kenttä on pakollinen."),
            remote: _("Korjaa tämä kenttä."),
            email: _("Syötä sähköpostiosoite oikeassa muodossa."),
            url: _("Syötä verkko-osoite."),
            date: _("Syötä sallittu päivämäärä."),
            dateISO: _("Syötä päivämäärä ISO-muodossa."),
            number: _("Syötä numero."),
            digits: _("Syötä vain numeroita."),
            equalTo: _("Syötä sama arvo uudelleen."),
            number: _("Syötä määrä oikeassa muodossa: 0.00"),
            maxlength: $.validator.format(_("Syötä enintään {0} merkkiä.")),
            minlength: $.validator.format(_("Syötä vähintään {0} merkkiä.")),
            rangelength: $.validator.format(_("Syötä arvo, joka on pituudeltaan {0}-{1} merkkiä.")),
            range: $.validator.format(_("Syötä numero välillä {0}-{1}.")),
            max: $.validator.format(_("Syötä numero, joka on pienempi tai yhtäsuuri kuin {0}.")),
            min: $.validator.format(_("Syötä numero, joka on suurempi tai yhtäsuuri kuin {0}.")),
            phone: $.validator.format(_("Syötä kelvollinen puhelinnumero."))
        });
    });
</script>
<!-- / validator-strings.inc -->
