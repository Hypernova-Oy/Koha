[% USE raw %]
[% USE Koha %]
[% USE Branches %]
[% USE Categories %]
[% USE AuthClient %]
[% USE AdditionalContents %]
[% PROCESS 'i18n.inc' %]
[% PROCESS 'html_helpers.inc' %]
[% IF Koha.Preference( 'CookieConsent' ) %]
 [% USE JSConsents %]
[% END %]
[% SET OpacLangSelectorMode = Koha.Preference('OpacLangSelectorMode') %]
[% SET OpacHeader = AdditionalContents.get( location => "opacheader", lang => lang, library => logged_in_user.branchcode || default_branch, blocktitle => 0 ) %]
[% SET OpacCustomSearch = AdditionalContents.get( location => "OpacCustomSearch", lang => lang, library => logged_in_user.branchcode || default_branch, blocktitle => 0 ) %]
[% SET OpacLoginInstructions = AdditionalContents.get( location => "OpacLoginInstructions", lang => lang, library => branchcode || default_branch ) %]
[% SET OpacMoreSearches = AdditionalContents.get( location => "OpacMoreSearches", lang => lang, library => branchcode || default_branch ) %]
[% SET CookieConsentBar = AdditionalContents.get( location => "CookieConsentBar", lang => lang, library => branchcode || default_branch ) %]
[% SET CookieConsentPopup = AdditionalContents.get( location => "CookieConsentPopup", lang => lang, library => branchcode || default_branch ) %]
[% SET AllPublicBranches = Branches.all(  search_params => { public => 1 }, selected => opac_name ) %]

<button id="scrolltocontent">Gå till huvudinnehåll</button>
<div id="wrapper">
 <div id="header-region" class="noprint">
 <nav class="navbar navbar-expand">
 <div id="logo">
 <a class="navbar-brand" href="/cgi-bin/koha/opac-main.pl">
 [% IF ( LibraryNameTitle ) %] [% LibraryNameTitle | html %] [% ELSE %] Koha online [% END %] </a>
 </div>
 [% IF ( OpacPublic ) %]
 [% IF ( Koha.Preference( 'opacbookbag' ) == 1 ) %]
 <div id="cartDetails" class="cart-message">Din minneslista är tom.</div>
 [% END %]
 <ul id="cart-list-nav" class="navbar-nav">
 [% IF ( Koha.Preference( 'opacbookbag' ) == 1 ) %]
 <li class="nav-item js-show">
 <a aria-label="Minneslista" class="nav-link" href="#" id="cartmenulink" role="button" title="Samla exemplar du är intresserad av">
 <i id="carticon" class="fa fa-shopping-cart fa-fw fa-icon-black" aria-hidden="true"></i> <span class="cartlabel">Minneslista</span> <span id="basketcount"></span>
 </a>
 </li>
 [% END %]
 <li class="divider-vertical"></li>
 [% IF ( Koha.Preference( 'virtualshelves' ) == 1 ) %]
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 || some_public_shelves.count > 0 %]
 <li class="nav-item dropdown">
 <a aria-expanded="false" aria-haspopup="true" aria-label="Visa rullgardinsmeny med detaljerad listinformation" class="nav-link dropdown-toggle" data-bs-toggle="dropdown" href="/cgi-bin/koha/opac-shelves.pl" id="listsmenu" role="button" title="Visa listor"><i class="fa fa-list fa-fw fa-icon-black" aria-hidden="true"></i> <span class="listslabel">Listor</span>
 </a>
 <div aria-labelledby="listsmenu" role="menu" class="dropdown-menu">
 [% IF some_public_shelves.count %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=list&amp;public=1" tabindex="-1" role="menuitem"><strong>Offentliga listor</strong></a>
 [% SET number_of_public_shelves = 0 %]
 [% FOREACH s IN some_public_shelves %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=view&amp;shelfnumber=[% s.shelfnumber | uri %]&amp;sortfield=[% s.sortfield | uri %]" tabindex="-1" role="menuitem">[% s.shelfname | html %]</a>
 [% SET number_of_public_shelves = number_of_public_shelves + 1 %]
 [% IF number_of_public_shelves >= 10 %][% LAST %][% END %]
 [% END %]
 [% IF some_public_shelves > 10 %]
 <a class="dropdown-item listmenulink" href="/cgi-bin/koha/opac-shelves.pl?op=list&amp;public=1" tabindex="-1" role="menuitem">Visa alla</a>
 [% END %]
 [% END %]
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 && some_public_shelves.count > 0 %]
 <div class="dropdown-divider"></div>
 [% END %]
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=list&amp;public=0" tabindex="-1" role="menuitem"><strong>Dina listor</strong></a>
 [% IF loggedinusername %]
 [% IF some_private_shelves.count %]
 [% SET number_of_private_shelves = 0 %]
 [% FOREACH s IN some_private_shelves %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=view&amp;shelfnumber=[% s.shelfnumber | uri %]&amp;sortfield=[% s.sortfield | uri %]" tabindex="-1" role="menuitem">[% s.shelfname | html %]</a>
 [% SET number_of_private_shelves = number_of_private_shelves + 1 %]
 [% IF number_of_private_shelves >= 10 %][% LAST %][% END %]
 [% END %]
 [% IF some_private_shelves > 10 %]
 <a class="dropdown-item listmenulink" href="/cgi-bin/koha/opac-shelves.pl?op=list&amp;public=0" tabindex="-1" role="menuitem">Visa alla</a>
 [% END %]
 [% ELSE %]
 <a class="dropdown-item disabled" aria-disabled="true" href="#" tabindex="-1" role="menuitem">Inga privata listor</a>
 [% END %]
 <a class="dropdown-item listmenulink" href="/cgi-bin/koha/opac-shelves.pl?op=add_form" tabindex="-1" role="menuitem">Ny lista</a>
 [% ELSE %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-shelves.pl?op=add_form" tabindex="-1" role="menuitem">Logga in för att skapa egna listor</a>
 [% END # / IF loggedinusername %]
 [% END # / IF opacuserlogin %]
 </div> <!-- / .dropdown-menu -->
 </li> <!-- / .nav-item.dropdown -->
 [% END # / IF opacuserlogin || some_public_shelves < 1 %]
 [% END # / IF virtualshelves %]
 [% IF Koha.Preference( 'OpacTrustedCheckout' ) %]
 <li class="nav-item">
 <a class="nav-link" data-bs-target="#checkoutModal" data-bs-toggle="modal" href="#" id="comenulink" role="button" title="Självutlåning">
 <i id="checkout-icon" class="fa fa-barcode fa-icon-black" aria-hidden="true"></i> <span class="checkout-label">Självutlåning</span>
 </a>
 </li>
 [% END %]

 </ul> <!-- / .navbar-nav -->
 [% END # /IF OpacPublic %]
 [% IF Koha.Preference( 'opacuserlogin' ) == 1 ||  Koha.Preference( 'EnableOpacSearchHistory') || Koha.Preference( 'opaclanguagesdisplay' ) %]
 [%# Following on one line for translatability %]
 [% IF ( ( opaclanguagesdisplay ) && ( ! one_language_enabled ) && ( languages_loop ) && ( OpacLangSelectorMode == 'both' || OpacLangSelectorMode == 'top') ) %]
 [% context = "header" %]
 [% INCLUDE 'langmenu.inc' %]
 [% END %]
 <ul id="members" class="navbar-nav">
 <li class="nav-item dropdown dropdown-menu-end">
 [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 ) %]
 [% IF ( loggedinusername ) %]
 <a href="/cgi-bin/koha/opac-user.pl" class="nav-link dropdown-toggle" id="user-menu" data-bs-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
 <i class="fa fa-user fa-icon-black fa-fw" aria-hidden="true"></i>
 <span class="userlabel">Välkommen, [% INCLUDE 'patron-title.inc' patron = logged_in_user no_html = 1 %]</span>
 </a>
 <a tabindex="-1" role="menuitem" class="logout js-hide" href="/cgi-bin/koha/opac-main.pl?logout.x=1"><i class="fa fa-fw fa-sign-out" aria-hidden="true"></i> Logga ut</a>
 [% ELSE %]
 [% IF Koha.Preference('casAuthentication') %]
 [%# CAS authentication is too complicated for modal window %]
 <a aria-label="Logga in på ditt konto" class="nav-link login-link" href="/cgi-bin/koha/opac-user.pl"><i class="fa fa-user fa-icon-black fa-fw" aria-hidden="true"></i> <span class="userlabel">Logga in på ditt konto</span></a>
 [% ELSIF ( Koha.Preference('GoogleOpenIDConnect') == 1 ) %]
 <a aria-label="Logga in på ditt konto" class="nav-link login-link loginModal-trigger" href="/cgi-bin/koha/svc/auth/googleopenidconnect"><i class="fa fa-user fa-icon-black fa-fw" aria-hidden="true"></i> <span class="userlabel">Logga in på ditt konto</span></a>
 [% ELSE %]
 <a aria-label="Logga in på ditt konto" class="nav-link login-link loginModal-trigger" href="/cgi-bin/koha/opac-user.pl"><i class="fa fa-user fa-fw fa-icon-black fa-fw" aria-hidden="true"></i> <span class="userlabel">Logga in på ditt konto</span></a>
 [% END %]
 [% END %]
 [% END %]

 [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 && loggedinusername ) %]
 <div aria-labelledby="user-menu" role="menu" class="dropdown-menu dropdown-menu-end">
 <div id="loggedinuser-menu">
 <p>
 <a class="login-link" href="/cgi-bin/koha/opac-user.pl"><span class="loggedinusername" data-borrowernumber="[% logged_in_user.borrowernumber | html %]" data-branchcode="[% logged_in_user.branchcode | html %]" data-categorycode="[% logged_in_user.categorycode | html %]">Ditt konto</span></a>
 </p>
 [% IF Koha.Preference( 'EnableOpacSearchHistory' ) %]
 <p>
 <a class="login-link" href="/cgi-bin/koha/opac-search-history.pl" role="menuitem" tabindex="-1" title="Visa din sökhistorik">Sökhistorik</a>
 <span class="divider-vertical"></span>
 <a class="clearsh" href="/cgi-bin/koha/opac-search-history.pl?action=delete" title="Ta bort din sökhistorik"><i class="fa fa-trash-can" aria-hidden="true"></i> Rensa</a>
 </p>
 [% END %]
 <a tabindex="-1" role="menuitem" class="logout" id="logout" href="/cgi-bin/koha/opac-main.pl?logout.x=1">Logga ut</a>
 </div>
 </div>
 [% END %]
 </li>
 <!-- Cookie consent button for non logged-in users -->
 [% IF !loggedinusername %]
 <li style="display:none" id="cookieConsentDivider" class="divider-vertical" aria-hidden="true"></li>
 <li style="display:none" id="cookieConsentLi" class="nav-item" aria-hidden="true">
 <a class="nav-link" href="#" id="cookieConsentButton" name="Your cookies" role="button" title="Se och ändra cookies som du har samtyckt till">
 <i class="fa fa-cookie-bite fa-fw fa-icon-black" aria-hidden="true"></i>
 <span class="cookieconsentlabel">Dina kakor</span>
 </a>
 </li>
 [% END %]
 [% IF OpacPublic && ( !Koha.Preference( 'opacuserlogin') || !loggedinusername ) %]
 [% IF Koha.Preference( 'EnableOpacSearchHistory' ) %]
 <li class="divider-vertical"></li>
 <li class="nav-item search_history">
 <a class="nav-link" href="/cgi-bin/koha/opac-search-history.pl" title="Visa din sökhistorik">
 <i class="fa fa-calendar-days fa-fw fa-icon-black" aria-hidden="true"></i>
 <span class="search_history_label">Sökhistorik</span>
 </a>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END # IF opacuserlogin || EnableOpacSearchHistory || opaclanguagesdisplay %]
 </nav> <!-- /navbar -->

 [% IF ( OpacHeader ) %]
 <div class="container-fluid">
 <div class="row">
 <div class="col">
 [% PROCESS koha_news_block news => OpacHeader %]
 </div>
 </div>
 </div>
 [% END %]

 </div> <!-- / header-region -->

 [% IF ( OpacPublic ) %]
 <div class="container-fluid">
 [% UNLESS ( advsearch ) %]
 <div class="row">
 <div class="col">
 <div id="opac-main-search" class="mastheadsearch">
 [% IF ( OpacCustomSearch ) %]
 [% PROCESS koha_news_block news => OpacCustomSearch %]
 [% ELSE %]
 <form name="searchform" method="get" action="/cgi-bin/koha/opac-search.pl" id="searchform">
 <div class="row gx-2">
 <div class="col-sm-auto order-2 order-sm-2">
 <label for="masthead_search" class="visually-hidden">Sök i katalogen efter:</label>
 <select name="idx" id="masthead_search" class="form-select">
 [% IF ( ms_kw ) %]
 <option selected="selected" value="" data-placeholder="[% t("Search the catalog by keyword") | html %]">Bibliotekskatalog</option>
 [% ELSE %]
 <option value="" data-placeholder="[% t("Search the catalog by keyword") | html %]">Bibliotekskatalog</option>
 [% END # /ms_kw %]
 [% IF ( ms_ti ) %]
 <option selected="selected" value="ti" data-placeholder="[% t("Search the catalog by title") | html %]">Titel</option>
 [% ELSE %]
 <option value="ti" data-placeholder="[% t("Search the catalog by title") | html %]">Titel</option>
 [% END # /ms_ti %]
 [% IF ( ms_au ) %]
 <option selected="selected" value="au" data-placeholder="[% t("Search the catalog by author") | html %]">Författare</option>
 [% ELSE %]
 <option value="au" data-placeholder="[% t("Search the catalog by author") | html %]">Författare</option>
 [% END # /ms_au%]
 [% IF ( ms_su ) %]
 <option selected="selected" value="su" data-placeholder="[% t("Search the catalog by subject") | html %]">Ämne</option>
 [% ELSE %]
 <option value="su" data-placeholder="[% t("Search the catalog by subject") | html %]">Ämne</option>
 [% END # /ms_su %]
 [% IF ( ms_nb ) %]
 <option selected="selected" value="nb" data-placeholder="[% t("Search the catalog by ISBN") | html %]">ISBN</option>
 [% ELSE %]
 <option value="nb" data-placeholder="[% t("Search the catalog by ISBN") | html %]">ISBN</option>
 [% END # /ms_nb%]
 [% IF ( ms_ns ) %]
 <option selected="selected" value="ns" data-placeholder="[% t("Search the catalog by ISSN") | html %]">ISSN</option>
 [% ELSE %]
 <option value="ns" data-placeholder="[% t("Search the catalog by ISSN") | html %]">ISSN</option>
 [% END # /ms_ns%]
 [% IF ( ms_se ) %]
 <option selected="selected" value="se" data-placeholder="[% t("Search the catalog by series") | html %]">Serie</option>
 [% ELSE %]
 <option value="se" data-placeholder="[% t("Search the catalog by series") | html %]">Serie</option>
 [% END # /ms_se %]
 [% IF ( Koha.Preference('OPACNumbersPreferPhrase') ) %]
 [% IF ( ms_callnumcommaphr ) %]
 <option selected="selected" value="callnum,phr" data-placeholder="[% t("Search the catalog by call number") | html %]">Hyllsignatur</option>
 [% ELSE %]
 <option value="callnum,phr" data-placeholder="[% t("Search the catalog by call number") | html %]">Hyllsignatur</option>
 [% END #/ms_callnumcommaphr %]
 [% ELSE %]
 [% IF ( ms_callnum ) %]
 <option selected="selected" value="callnum" data-placeholder="[% t("Search the catalog by call number") | html %]">Hyllsignatur</option>
 [% ELSE %]
 <option value="callnum" data-placeholder="[% t("Search the catalog by call number") | html %]">Hyllsignatur</option>
 [% END # /ms_callnum %]
 [% END # /IF OPACNumbersPreferPhrase %]
 </select>
 </div> <!-- /.col-sm-auto -->

 <div class="col order-4 order-sm-3">
 [% IF ( !Koha.Preference( 'OpacAddMastheadLibraryPulldown' ) == 1 && mylibraryfirst ) %]
 <label for="translControl1" class="visually-hidden">Sök i katalogen efter nyckelord i [% Branches.GetName( mylibraryfirst ) | html %]</label>
 <input class="transl1 form-control form-control-filtered" data-bs-placement="top" data-bs-toggle="tooltip" id="translControl1" name="q" placeholder="Sök på nyckelord i katalogen" title="Sök enbart på [% Branches.GetName( mylibraryfirst ) | html %]" type="text" value="[% ms_value | html %]" /><span id="translControl"></span>
 [% ELSE %]
 <label for="translControl1" class="visually-hidden">Sök på nyckelord i katalogen</label>
 <input class="transl1 form-control" id="translControl1" name="q" placeholder="Sök på nyckelord i katalogen" type="text" value="[% ms_value | html %]" /><span id="translControl"></span>
 [% END # /ms_value %]
 </div> <!-- /.col -->

 [% IF ( Koha.Preference( 'OpacAddMastheadLibraryPulldown' ) == 1 && AllPublicBranches.size > 1 ) %]
 <div class="col-sm col-md-3 col-lg-2 order-3 order-sm-4">
 <select name="limit" id="select_library" class="form-select">
 <option value="">Alla bibliotek</option>

 [% IF LibrarySearchGroups %]<optgroup label="Bibliotek">[% END %]

 [% FOREACH library IN AllPublicBranches %]
 [% IF library.selected %]
 <option selected="selected" value="branch:[% library.branchcode | html %]">[% library.branchname | html %]</option>
 [% ELSE %]
 <option value="branch:[% library.branchcode | html %]">[% library.branchname | html %]</option>
 [% END %]
 [% END %]

 [% IF LibrarySearchGroups %]
 </optgroup>
 <optgroup label="Grupper">
 [% FOREACH lsg IN LibrarySearchGroups %]
 [% IF 'multibranchlimit-' _ lsg.id == opac_name || lsg.id == opac_name %]
 <option selected="selected" value="multibranchlimit:[% lsg.id | html %]">[% lsg.title | html %]</option>
 [% ELSE %]
 <option value="multibranchlimit:[% lsg.id | html %]">[% lsg.title | html %]</option>
 [% END # / bc.selected %]
 [% END %]
 </optgroup>
 [% END # / BranchCategoriesLoop %]
 </select> <!-- /#select_library -->
 </div> <!-- /.col-sm-auto -->
 [% ELSE %]
 [% IF ( opac_limit_override ) %]
 [% IF ( opac_search_limit ) %]
 [% IF ( multibranchlimit = opac_search_limit.match( 'branch:multibranchlimit-(\d+)' ) ) %]
 <input name="limit" value="multibranchlimit:[% multibranchlimit.0 | html %]" type="hidden" />
 [% ELSE %]
 <input name="limit" value="[% opac_search_limit | html %]" type="hidden" />
 [% END %]
 [% END %]
 [% ELSE %]
 [% IF ( mylibraryfirst ) %]
 <input name="limit" value="branch:[% mylibraryfirst | html %]" type="hidden" />
 [% END %]
 [% END # / opac_limit_override %]
 [% END # / OpacAddMastheadLibraryPulldown %]

 <div class="order-5 col-sm-auto">
 <button aria-label="Sök" class="btn btn-primary" id="searchsubmit" title="Sök" type="submit">
 <i class="fa fa-search" aria-hidden="true"></i>
 </button>
 </div>

 </div> <!-- /.form-row -->
 <input type="hidden" name="weight_search" value="1">
 </form>
 [% END # / ( OpacCustomSearch ) %]
 </div><!-- /#opac-main-search -->
 </div> <!-- /.col -->
 </div> <!-- /.row -->
 [% END # / UNLESS advsearch %]

 <div class="row">
 <ul class="nav" id="moresearches">
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-search.pl">Avancerad sökning</a>
 </li>
 [% IF ( Koha.Preference( 'UseCourseReserves' ) == 1 ) %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-course-reserves.pl">Kurslistor</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'OpacBrowser' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-browser.pl">Bläddra per hierarki</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'OpacAuthorities' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-authorities-home.pl">Auktoritetssök</a>
 </li>
 [% END %]
 [% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && ( Koha.Preference( 'OPACComments' ) == 1 ) && ( Koha.Preference( 'OpacShowRecentComments' ) == 1 ) ) %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-showreviews.pl">Nya kommentarer</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'TagsEnabled' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-tags.pl">Taggmoln</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'OpacCloud' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-tags_subject.pl">Ämnesmoln</a>
 </li>
 [% END %]
 [% IF Koha.Preference( 'OpacTopissue' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-topissues.pl">Populärast</a>
 </li>
 [% END %]
 [% IF Koha.Preference('SearchEngine') == 'Elasticsearch' && Koha.Preference( 'OpacBrowseSearch' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-browse.pl">Bläddersök</a>
 </li>
 [% END %]
 [% IF suggestion %]
 [% IF Koha.Preference( 'AnonSuggestions' ) == 1 || Koha.Preference( 'OPACViewOthersSuggestions' ) == 1 %]
 <li class="nav-item">
 <a href="/cgi-bin/koha/opac-suggestions.pl?suggested_by_anyone=1">Inköpsförslag</a>
 </li>
 [% END %]
 [% END %]
 [% IF ( Koha.Preference('OPACShowLibraries') && AllPublicBranches.size > 0 ) %]
 <li class="nav-item">
 <a id="library_page" href="/cgi-bin/koha/opac-library.pl">
 [% IF ( singleBranchMode || AllPublicBranches.size == 1 ) %]
 <span>Bibliotek</span>
 [% ELSE %]
 <span>Bibliotek</span>
 [% END %]
 </a>
 </li>
 [% END %]
 [% PROCESS koha_news_block news => OpacMoreSearches %]
 </ul> <!-- /.nav#moresearches -->
 </div> <!-- /.row -->
 </div> <!-- /.container-fluid -->
 [% END # / OpacPublic %]

 [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 ) %]
 <!-- Login form hidden by default, used for modal window -->
 <div id="loginModal" class="modal" tabindex="-1" role="dialog" aria-labelledby="modalLoginLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="modalLoginLabel">Logga in på ditt konto</h1>
 <button aria-label="Stäng" class="btn-close" data-bs-dismiss="modal" type="button"></button>
 </div>
 <form action="/cgi-bin/koha/opac-user.pl" method="post" name="auth" id="modalAuth">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="has-search-query" id="has-search-query" value="" />
 <div class="modal-body">
 [% IF ( Koha.Preference('GoogleOpenIDConnect') == 1 ) %]
 <a href="/cgi-bin/koha/svc/auth/googleopenidconnect" class="btn btn-light" id="openid_connect"><i class="fa-brands fa-google" aria-hidden="true"></i> Logga in med Google</a>
 <p>Om du inte har ett Google-konto, men har ett lokalt konto, kan du ändå logga in: </p>
 [% END # /IF GoogleOpenIDConnect %]
 [% IF ( shibbolethAuthentication ) %]
 [% IF ( invalidShibLogin ) %]
 <!-- This is what is displayed if shibboleth login has failed to match a koha user -->
 <div class="alert alert-info">
 <p>Din Shibboleth-identitet överensstämmer inte med en giltig biblioteksidentitet. Om du har ett lokalt inloggningsnamn kan du använda det nedan.</p>
 </div>
 [% ELSE %]
 <h3 class="shib_title">Shibboleth-inloggning</h3>
 <p><a id="shib_url" class="shib_url" href="[% shibbolethLoginUrl | $raw %]">Logga in med ett Shibboleth-konto</a>.</p>
 [% UNLESS Koha.Preference('opacShibOnly') %]
 <h3 class="shib_local_title">Lokal inloggning</h3>
 [% END %]
 [% END %]
 [% END %]
 [% UNLESS Koha.Preference('opacShibOnly') %]
 [% SET identity_providers = AuthClient.get_providers('opac') %]
 [% IF ( ! identity_providers.empty ) %]
 [% FOREACH provider IN identity_providers %]
 <p class="clearfix">
 <a href="[% provider.url | url %]" class="btn btn-light col-md-12" id="provider_[% provider.code | html %]">
 [% IF provider.icon_url %]
 <img src="[% provider.icon_url | url %]" />
 [% ELSE %]
 <i class="fa fa-user" aria-hidden="true"></i>
 [% END %] Logga in med [% provider.description | html %] </a>
 </p>
 [% END %]
 <hr/>
 <p>Om du inte har ett externt konto, men har ett lokalt konto, kan du ändå logga in: </p>
 [% END # /IF  identity_providers.size %]
 <input type="hidden" name="koha_login_context" value="opac" />
 <fieldset class="brief">
 <div class="local-login">
 [% PROCESS login_label for="muserid" %]<input type="text" id="muserid" name="login_userid" autocomplete="off" />
 <label for="mpassword">Lösenord:</label><input type="password" id="mpassword" name="login_password" autocomplete="off" />
 <fieldset class="action">
 <input type="hidden" name="op" value="cud-login" />
 <input class="btn btn-primary" type="submit" value="Logga in" />
 </fieldset>
 </div>
 [% IF OpacLoginInstructions %]
 <div id="nologininstructions-modal" class="nologininstructions">
 [% PROCESS koha_news_block news => OpacLoginInstructions %]
 </div>
 [% END %]
 [% IF Koha.Preference('OpacPasswordChange') && Categories.can_any_reset_password %]
 <div id="forgotpassword-modal" class="forgotpassword">
 <p><a href="/cgi-bin/koha/opac-password-recovery.pl">Har du glömt lösenordet?</a></p>
 </div>
 [% END %]
 [% IF Koha.Preference('PatronSelfRegistration') && Categories.all( categorycode => Koha.Preference('PatronSelfRegistrationDefaultCategory') ).count %]
 <div id="patronregistration-modal" class="patronregistration">
 <p><a href="/cgi-bin/koha/opac-memberentry.pl">Registrera ett nytt konto</a></p>
 </div>
 [% END %]
 </fieldset>
 [% END %]
 </div>
 </form> <!-- /#auth -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
 </div> <!-- /#modalAuth -->
 [% END # / IF opacuserlogin %]

 [% IF Koha.Preference( 'CookieConsent' ) %]
 <!-- Cookie consent bar -->
 <div id="cookieConsentBar" aria-hidden="true">
 [% IF ( CookieConsentBar ) %]
 <div id="cookieConsentBar_content">
 [% PROCESS koha_news_block news => CookieConsentBar %]
 </div>
 [% END %]
 <div class="consentButtons">
 [% IF ( JSConsents.all('opacConsent').size ) %]
 <button type="button" class="btn btn-primary consentAcceptAll">Acceptera alla cookies</button>
 [% END %]
 <button type="button" class="btn btn-primary consentAcceptEssential">Acceptera nödvändiga cookies</button>
 <button aria-label="Klicka för att se mer information om dina medgivanden till cookies" class="btn btn-info" id="consentMoreInfo" type="button">Mer information</button>
 </div>
 </div> <!-- /#cookieConsentBar -->
 <!-- Cookie consent modal -->
 <div id="cookieConsentModal" class="modal" tabindex="-1" role="dialog" aria-labelledby="cookieConsentModalLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h1 class="modal-title" id="cookieConsentModalLabel">Kakpolicy</h1>
 </div>
 <div class="modal-body">
 [% IF ( CookieConsentPopup ) %]
 <div id="cookieConsentPopupText">
 [% PROCESS koha_news_block news => CookieConsentPopup %]
 </div>
 [% END %]
 <div id="consentCookieList">
 [% consents = JSConsents.all('opacConsent') %]
 [% FOREACH consent IN consents %]
 <div class="consentModalItem">
 <div class="consentItemCheckbox">
 <input aria-label="Samtycke till cookie" class="consentCheckbox" name="consentCheckbox" type="checkbox" value="[% consent.id | html %]">
 </div>
 <div class="consentItemMeta">
 <div class="consentItemName">[% consent.name | html %]</div>
 <div class="consentItemDescription">[% consent.description | html %]</div>
 </div>
 </div>
 [% END %]
 </div>
 </div>
 <div class="modal-footer">
 <div class="consentButtons">
 <button type="button" class="btn btn-primary consentAcceptEssential">Acceptera nödvändiga cookies</button>
 [% IF ( JSConsents.all('opacConsent').size ) %]
 <button type="button" class="btn btn-primary consentAcceptAll">Acceptera alla cookies</button>
 <button type="button" class="btn btn-warning" id="consentAcceptSelected">Acceptera utvalda icke-nödvändiga cookies</button>
 [% END %]
 <a type="button" href="#" class="btn btn-secondary consentCloseModal">Avbryt</a>
 </div>
 </div>
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
 </div> <!-- /#cookieConsentModal -->
 [% END %]
