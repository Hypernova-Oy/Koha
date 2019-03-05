$(document).ready(function() {
    $("#hosting-offer-form").on('submit', function(e) {
        e.preventDefault();

        $("#kohaGenerateButton").attr("disabled", "disabled");
        $("#kohaAnnualCost").html("");
        $("#loading-price").css("display", "block");


        $.ajax({
            url: "/api/v1/hypernova/hosting/price",
            data: $("#hosting-offer-form").serialize(),
            method: "GET"
        }).done(function(data, textStatus, jqXHR) {
            if (data.price_formatted) {
                $("#kohaAnnualCost").html(data.price_formatted);
            }
        }).fail(function(data, textStatus, jqXHR) {
            $("#kohaAnnualCost").html(MSG_ERROR_GETTING_PRICE + "<br /><pre>"+JSON.stringify(data, null, 4)+"</pre>");
        }).always(function() {
            $("#loading-price").css("display", "");
            $("#kohaGenerateButton").removeAttr("disabled");
        });
    });
});
