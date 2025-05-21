<!-- validator-strings.inc -->
<script>
    $(document).ready(function(){
        jQuery.extend(jQuery.validator.messages, {
            required: _("Detta fält är obligatoriskt."),
            remote: _("Korrigera detta fält."),
            email: _("Ange en giltig e-postadress."),
            url: _("Ange en giltig URL."),
            date: _("Ange ett giltigt datum."),
            dateISO: _("Ange ett giltigt datum (ISO)."),
            number: _("Ange ett giltigt nummer."),
            digits: _("Ange bara siffror."),
            equalTo: _("Ange samma värde igen."),
            maxlength: $.validator.format(_("Ange inte mer än {0} tecken.")),
            minlength: $.validator.format(_("Du måste ange minst {0} tecken.")),
            rangelength: $.validator.format(_("Ange ett värde med mellan {0} och {1} tecken.")),
            range: $.validator.format(_("Ange ett värde mellan {0} och {1}.")),
            max: $.validator.format(_("Ange ett värde som är lägre eller lika med {0}.")),
            min: $.validator.format(_("Ange ett värde som är högre eller lika med {0}.")),
            phone: $.validator.format(_("Ange ett giltigt telefonnummer."))
        });
    });
</script>
<!-- / validator-strings.inc -->
