[% USE raw %]
[% USE Branches %]
[% USE Desks %]
[% USE Registers %]
[% USE Koha %]
[% PROCESS 'i18n.inc' %]
[% IF Koha.Preference( 'CookieConsent' ) %]
 [% USE JSConsents %]
[% END %]
<nav class="navbar navbar-expand navbar-dark bg-dark">
 <div class="container-fluid">
 <a id="logo" class="navbar-brand" href="/cgi-bin/koha/mainpage.pl"><img src="[% interface | html %]/[% theme | html %]/img/picto-koha.svg" alt="Koha"></a>

 <div class="collapse navbar-collapse" id="header">
 <ul id="toplevelmenu" class="navbar-nav me-auto">
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li class="nav-item"><a class="nav-link" href="/cgi-bin/koha/circ/circulation-home.pl"><span class="nav-link-icon"><i class="fa fa-fw fa-exchange" title="Cirkulation"></i></span> <span class="nav-link-text">Cirkulation</span></a></li>
 [% END %]
 [% IF CAN_user_borrowers_edit_borrowers || CAN_user_borrowers_list_borrowers %]
 <li class="nav-item"><a class="nav-link" href="/cgi-bin/koha/members/members-home.pl"><span class="nav-link-icon"><i class="fa fa-fw fa-id-card" title="Låntagare"></i></span> <span class="nav-link-text">Låntagare</span></a></li>
 [% END %]
 <li class="nav-item" id="catalog-search-link">
 <a class="nav-link" href="/cgi-bin/koha/catalogue/search.pl"><span class="nav-link-icon"><i class="fa fa-fw fa-search" title="Sök"></i></span> <span class="nav-link-text">Sök</span></a>
 </li>
 [% IF ( CAN_user_catalogue ) %]
 <li class="nav-item dropdown" id="catalog-search-dropdown">
 <a href="/cgi-bin/koha/catalogue/search.pl" class="nav-link dropdown-toggle" role="button" data-bs-toggle="dropdown" aria-expanded="false"></a>
 <ul class="dropdown-menu dropdown-menu-dark dropdown-menu-end">
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/search.pl">Avancerad sökning</a></li>
 <li><a class="dropdown-item" href="/cgi-bin/koha/catalogue/itemsearch.pl">Exemplarsökning</a></li>
 </ul>
 </li>
 [% END %]
 [% Koha.Preference('IntranetNav') | $raw %]
 <li class="nav-item dropdown">
 <a href="/cgi-bin/koha/mainpage.pl" class="nav-link dropdown-toggle" role="button" data-bs-toggle="dropdown" aria-expanded="false"><span class="nav-link-icon"><i class="fa fa-fw fa-bars" title="Mer"></i></span> <span class="nav-link-text">Mer</span></a>
 <ul class="dropdown-menu dropdown-menu-dark dropdown-menu-end">
 <li><a class="dropdown-item" href="/cgi-bin/koha/virtualshelves/shelves.pl">Listor</a></li>
 [% IF ( CAN_user_editcatalogue_edit_catalogue || CAN_user_editcatalogue_edit_items || can_see_cataloguing_module  ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/cataloguing/cataloging-home.pl">Katalogisering</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/acqui/acqui-home.pl">Inköp</a></li>
 [% END %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/authorities/authorities-home.pl">Auktoriteter</a></li>
 [% IF Koha.Preference('ILLModule') && CAN_user_ill %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/ill/ill-requests.pl">Fjärrlånebeställningar</a></li>
 [% END %]
 [% IF ( CAN_user_serials ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/serials/serials-home.pl">Periodika</a></li>
 [% END %]
 [% IF Koha.Preference('ERMModule') && CAN_user_erm %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/erm/erm.pl">E-resurshantering</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCourseReserves') ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/course_reserves/course-reserves.pl">Kurslistor</a></li>
 [% END %]
 [% IF Koha.Preference('PreservationModule') && CAN_user_preservation %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/preservation/home.pl">p- Arkivkvalitet för långtidslagring</a></li>
 [% END %]
 [% IF ( CAN_user_reports ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/reports/reports-home.pl">Rapporter</a></li>
 [% END %]
 [% IF ( CAN_user_suggestions_suggestions_manage ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/suggestion/suggestion.pl">Förslag</a></li>
 [% END %]
 [% IF ( CAN_user_tools || CAN_user_clubs ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/tools/tools-home.pl">Verktyg</a></li>
 [% END %]
 [% IF ( Koha.Preference('EnablePointOfSale') && Koha.Preference('UseCashRegisters') && CAN_user_cash_management_takepayment ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/pos/pay.pl">Försäljningsställe</a></li>
 [% END %]
 [% IF ( CAN_user_parameters ) %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/admin/admin-home.pl">Administration</a></li>
 [% END %]
 <li><a class="dropdown-item" href="/cgi-bin/koha/about.pl">Om Koha</a></li>
 </ul>
 </li>
 [% IF ( Koha.Preference('intranetbookbag') ) %]
 <li class="nav-item">
 <a class="nav-link" href="#" id="cartmenulink"><i class="fa fa-shopping-cart" title="Minneslista"></i><span id="basketcount"></span></a>
 </li>
 [% END %]
 </ul>


 <ul id="user-menu" class="nav navbar-nav">
 [% IF ( loggedinusername ) %]
 <li class="nav-item dropdown" id="logged-in-dropdown">
 <a id="logged-in-menu" href="/cgi-bin/koha/mainpage.pl" class="nav-link dropdown-toggle" role="button" data-bs-toggle="dropdown" aria-expanded="false">
 <span id="logged-in-info-brief">
 <i class="fa fa-user"></i>
 </span>
 <span id="logged-in-info-full">
 [% SET is_superlibrarian = CAN_user_superlibrarian ? 'is_superlibrarian' : '' %]
 <span class="loggedinusername [% is_superlibrarian | html %]">[% logged_in_user.userid | html %]</span>
 <span class="loggedincategorycode content_hidden">[% logged_in_user.categorycode | html %]</span>
 [% IF ( StaffLoginRestrictLibraryByIP ) %]
 <brand>
 [% Branches.GetLoggedInBranchname | html %]
 </brand>
 [% ELSE %]
 <strong>
 <span class="logged-in-branch-name">[% Branches.GetLoggedInBranchname | html %]</span>
 <span class="logged-in-branch-code content_hidden">[% Branches.GetLoggedInBranchcode | html %]</span>
 </strong>
 [% END %]
 [% IF Koha.Preference('UseCirculationDesks') && Desks.ListForLibrary.count %]
 <span class="separator">|</span>
 <strong>
 [% IF ( Desks.GetLoggedInDeskName == '' ) %]
 <span class="logged-in-desk-name">INGEN INFORMATIONSDISK VALD</span>
 [% ELSE %]
 <span class="logged-in-desk-name">[% Desks.GetLoggedInDeskName | html %]</span>
 <span class="logged-in-desk-id content_hidden">[% Desks.GetLoggedInDeskId | html %]</span>
 [% END %]
 </strong>
 [% END %]
 [% IF Koha.Preference('UseCashRegisters') && !(Registers.session_register_name == '') %]
 <span class="separator">|</span>
 <strong>
 <span class="logged-in-register-name">[% Registers.session_register_name | html %]</span>
 <span class="logged-in-register-id content_hidden">[% Registers.session_register_id | html %]</span>
 </strong>
 [% END %]
 </span>
 <b class="caret"></b>
 </a>

 <ul class="dropdown-menu dropdown-menu-dark dropdown-menu-end" role="menu" aria-labelledby="logged-in-menu">
 <li class="loggedin-menu-label">
 Inloggad som:<br />
 <span class="loggedinusername">[% logged_in_user.userid | html %]</span>
 </li>
 <li class="loggedin-menu-label">
 [% IF ( StaffLoginRestrictLibraryByIP ) %]
 <brand>
 [% Branches.GetLoggedInBranchname | html %]
 </brand>
 [% ELSE %] Plats: <br />
 <span class="logged-in-branch-name">[% Branches.GetLoggedInBranchname | html %]</span>
 <span class="logged-in-branch-code content_hidden">[% Branches.GetLoggedInBranchcode | html %]</span>
 [% END %]
 </li>

 [% IF Koha.Preference('UseCirculationDesks') && Desks.ListForLibrary.count %]
 <li class="loggedin-menu-label">
 Disk: <br />
 [% IF ( Desks.GetLoggedInDeskName == '' ) %]
 <span class="logged-in-desk-name">INGEN INFORMATIONSDISK VALD</span>
 [% ELSE %]
 <span class="logged-in-desk-name">[% Desks.GetLoggedInDeskName | html %]</span>
 <span class="logged-in-desk-id content_hidden">[% Desks.GetLoggedInDeskId | html %]</span>
 [% END %]
 </li>
 [% END %]

 [% IF Koha.Preference('UseCashRegisters') && !(Registers.session_register_name == '') %]
 <li class="loggedin-menu-label">
 Register: <br />
 <span class="logged-in-register-name">[% Registers.session_register_name | html %]</span>
 <span class="logged-in-register-id content_hidden">[% Registers.session_register_id | html %]</span>
 </li>
 [% END %]

 [% IF ( CAN_user_superlibrarian || CAN_user_loggedinlibrary || Koha.Preference('UseCirculationDesks') || Koha.Preference('UseCashRegisters') ) %]
 <li><hr class="dropdown-divider"></li>
 <li>
 <div id="set_library_controls">
 <div>
 <a class="dropdown-item" href="/cgi-bin/koha/circ/set-library.pl">
 [% IF ( CAN_user_superlibrarian || CAN_user_loggedinlibrary ) %]
 [% IF ( Koha.Preference('UseCirculationDesks') && Koha.Preference('UseCashRegisters') ) %]
 [% t("Set library, desk, and register") | html %]
 [% ELSIF ( Koha.Preference('UseCirculationDesks') ) %]
 [% t("Set library and desk") | html %]
 [% ELSIF ( Koha.Preference('UseCashRegisters') ) %]
 [% t("Set library and cash register") | html %]
 [% ELSE %]
 [% t("Set library") | html %]
 [% END %]
 [% ELSIF ( Koha.Preference('UseCirculationDesks') && Koha.Preference('UseCashRegisters') ) %]
 [% t("Set desk and cash register") | html %]
 [% ELSIF ( Koha.Preference('UseCashRegisters') ) %]
 [% t("Set cash register") | html %]
 [% ELSIF ( Koha.Preference('UseCirculationDesks') ) %]
 [% t("Set desk") | html %]
 [% END %]
 </a>
 </div>
 [% IF ( CAN_user_superlibrarian || CAN_user_loggedinlibrary || Koha.Preference('UseCirculationDesks') || Koha.Preference('UseCashRegisters') ) %]
 <div>
 <a id="branch_select_cog" class="dropdown-item" href="#"><i class="fa fa-cog" aria-label="Toggle panel for login settings"></i></a>
 </div>
 [% END %]
 </div>
 </li>

 <li id="setlibrary_panel" style="display:none"></li>
 [% ELSIF Koha.Preference('UseCirculationDesks') && Koha.Preference('UseCashRegisters') %]
 <li><hr class="dropdown-divider"></li>
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/circ/set-library.pl">Ange informationsdisk och kassaregister</a>
 </li>
 [% ELSIF Koha.Preference('UseCirculationDesks') %]
 <li><hr class="dropdown-divider"></li>
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/circ/set-library.pl">Ställ in informationsdisk</a>
 </li>
 [% ELSIF Koha.Preference('UseCashRegisters') %]
 <li><hr class="dropdown-divider"></li>
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/circ/set-library.pl">Ställ in kassaregister</a>
 </li>
 [% END %]
 [% IF EnableSearchHistory %]
 <li>
 <a class="dropdown-item" href="/cgi-bin/koha/catalogue/search-history.pl">Sökhistorik</a>
 </li>
 [% END %]

 [% IF loggedinusernumber %]
 <li class="nav-item toplinks-myaccount">
 <a class="dropdown-item" href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% loggedinusernumber | html %]">Mitt konto</a>
 </li>
 <li class="nav-item toplinks-mycheckouts">
 <a class="dropdown-item" href="/cgi-bin/koha/circ/circulation.pl?borrowernumber=[% loggedinusernumber | html %]">Mina lån</a>
 </li>
 [% END %]

 [% IF Koha.Preference( 'CookieConsent' ) && JSConsents.all('staffConsent').size %]
 <li class="nav-item toplinks-myconsents">
 <a id="viewCookieConsents" href="#" class="toplinks dropdown-item">Mina medgivanden</a>
 </li>
 [% END %]
 <li class="nav-item">
 <a id="logout" class="toplinks dropdown-item" href="/cgi-bin/koha/mainpage.pl?logout.x=1">Logga ut</a>
 </li>
 </ul>
 </li>
 [% INCLUDE 'langmenu-staff-top.inc' %]

 [% ELSE %]
 <li class="nav-item loggedout">
 <a href="/cgi-bin/koha/mainpage.pl" id="login">Logga in</a>
 </li>
 [% END %]
 </ul>
 </div>
 </div>

 [% IF ( Koha.Preference('intranetbookbag') ) %]<div id="cartDetails">Din minneslista är tom.</div>[% END %]

</nav>

[% content | $raw %]
