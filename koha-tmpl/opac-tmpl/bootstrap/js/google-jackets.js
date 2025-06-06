/* global __ */
if (typeof KOHA == "undefined" || !KOHA) {
    var KOHA = {};
}

/**
 * A namespace for Google related functions.
 */
KOHA.Google = {
    /**
     * Search all:
     *    <div title="biblionumber" id="isbn" class="gbs-thumbnail"></div>
     * or
     *    <div title="biblionumber" id="isbn" class="gbs-thumbnail-preview"></div>
     * and run a search with all collected isbns to Google Book Search.
     * The result is asynchronously returned by Google and caught by
     * gbsCallBack().
     */
    GetCoverFromIsbn: function (newWindow) {
        var bibkeys = [];
        $("[id^=gbs-thumbnail]").each(function () {
            bibkeys.push($(this).attr("class")); // id=isbn
        });
        bibkeys = bibkeys.join(",");
        var scriptElement = document.createElement("script");
        this.openInNewWindow = newWindow;
        scriptElement.setAttribute("id", "jsonScript");
        scriptElement.setAttribute(
            "src",
            "https://books.google.com/books?bibkeys=" +
                escape(bibkeys) +
                "&jscmd=viewapi&callback=KOHA.Google.gbsCallBack"
        );
        scriptElement.setAttribute("type", "text/javascript");
        document.documentElement.firstChild.appendChild(scriptElement);
    },

    /**
     * Add cover pages <div
     * and link to preview if div id is gbs-thumbnail-preview
     */
    gbsCallBack: function (booksInfo) {
        var target = "";
        if (this.openInNewWindow) {
            target = 'target="_blank" rel="noreferrer" ';
        }
        for (var id in booksInfo) {
            var book = booksInfo[id];
            $("[id^=gbs-thumbnail]." + book.bib_key).each(function () {
                if (typeof book.thumbnail_url != "undefined") {
                    var img;
                    if ($(this).data("use-data-link")) {
                        var a = document.createElement("a");
                        a.href = book.thumbnail_url;
                        img = document.createElement("img");
                        img.src = book.thumbnail_url;
                        img.setAttribute("data-link", book.info_url);
                        a.append(img);
                        $(this).empty().append(a);
                    } else {
                        img = document.createElement("img");
                        img.src = book.thumbnail_url;
                        $(this).empty().append(img);
                        var re = /^gbs-thumbnail-preview/;
                        if (re.exec($(this).attr("id"))) {
                            $(this).append(
                                '<div class="google-books-preview">' +
                                    "<a " +
                                    target +
                                    'href="' +
                                    book.info_url +
                                    '"><img src="' +
                                    "https://books.google.com/intl/en/googlebooks/images/gbs_preview_sticker1.gif" +
                                    '"></a></div>'
                            );
                        }
                    }
                } else {
                    var message = document.createElement("span");
                    $(message).attr("class", "no-image");
                    $(message).html(__("No cover image available"));
                    $(this).empty().append(message);
                }
            });
        }
        this.done = 1;
    },
};
