# RELEASE NOTES FOR KOHA 23.11.13
24 Mar 2025

Koha is the first free and open source software library automation
package (ILS). Development is sponsored by libraries of varying types
and sizes, volunteers, and support companies from around the world. The
website for the Koha project is:

- [Koha Community](https://koha-community.org)

Koha 23.11.13 can be downloaded from:

- [Download](https://download.koha-community.org/koha-23.11.13.tar.gz)

Installation instructions can be found at:

- [Koha Wiki](https://wiki.koha-community.org/wiki/Installation_Documentation)
- OR in the INSTALL files that come in the tarball

Koha 23.11.13 is a bugfix/maintenance release.

It includes 3 bugfixes and 2 security fixes.

**System requirements**

You can learn about the system components (like OS and database) needed for running Koha on the [community wiki](https://wiki.koha-community.org/wiki/System_requirements_and_recommendations).


#### Security bugs

- [31165](https://bugs.koha-community.org/bugzilla3/show_bug.cgi?id=31165) "Public note" field in course reserve should restrict HTML usage
- [37784](https://bugs.koha-community.org/bugzilla3/show_bug.cgi?id=37784) Patron password hash can be fetched using report dictionary

  **Sponsored by** *Reserve Bank of New Zealand*

## Bugfixes

### Authentication

#### Critical bugs fixed

- [38826](https://bugs.koha-community.org/bugzilla3/show_bug.cgi?id=38826) C4::Auth::check_api_auth sometimes returns $session and sometimes returns $sessionID
  >This fixes authentication checking so that the $sessionID is consistently returned (sometimes it was returning the session object). (Note: $sessionID is returned on a successful login, while $session is returned when there is a cookie for an authenticated session.)

### SIP2

#### Other bugs fixed

- [38486](https://bugs.koha-community.org/bugzilla3/show_bug.cgi?id=38486) No block checkouts are still blocked by fines, checkouts, and blocked item types
  >This fixes SIP so that it allows noblock checkouts, regardless of normal patron checkout blocks.
  >
  >Explanation: The purpose of no block checkouts in SIP is to indicate that the SIP machine has made an offline ("store and forward") transaction. The patron already has the item. As such, the item must be checked out to the patron or the library risks losing the item due to lack of tracking. As such, no block checkouts should not be blocked under any circumstances.

### Tools

#### Critical bugs fixed

- [31450](https://bugs.koha-community.org/bugzilla3/show_bug.cgi?id=31450) HTML customizations and news will not display on OPAC without a publication date
  >This fixes the display of news, HTML customizations, and pages on the OPAC - a publication date is now required for all types of additional content. Previously, news items and HTML customizations were not shown if they didn't have a publication date (this behavour was not obvious from the forms).

  **Sponsored by** *Athens County Public Libraries*

## Documentation

The Koha manual is maintained in Sphinx. The home page for Koha
documentation is

- [Koha Documentation](https://koha-community.org/documentation/)
As of the date of these release notes, the Koha manual is available in the following languages:

- [Armenian (hy_ARMN)](https://koha-community.org/manual/23.11//html/) (100%)
- [Chinese (Traditional)](https://koha-community.org/manual/23.11/zh_Hant/html/) (99%)
- [English](https://koha-community.org/manual/23.11//html/) (100%)
- [English (USA)](https://koha-community.org/manual/23.11/en/html/)
- [French](https://koha-community.org/manual/23.11/fr/html/) (63%)
- [German](https://koha-community.org/manual/23.11/de/html/) (99%)
- [Greek](https://koha-community.org/manual/23.11//html/) (97%)
- [Hindi](https://koha-community.org/manual/23.11/hi/html/) (71%)

The Git repository for the Koha manual can be found at

- [Koha Git Repository](https://gitlab.com/koha-community/koha-manual)

## Translations

Complete or near-complete translations of the OPAC and staff
interface are available in this release for the following languages:
<div style="column-count: 2;">

- Arabic (ar_ARAB) (99%)
- Armenian (hy_ARMN) (100%)
- Bulgarian (bg_CYRL) (100%)
- Chinese (Simplified) (89%)
- Chinese (Traditional) (99%)
- Czech (70%)
- Dutch (88%)
- English (100%)
- English (New Zealand) (64%)
- English (USA)
- Finnish (99%)
- French (100%)
- French (Canada) (99%)
- German (100%)
- German (Switzerland) (52%)
- Greek (69%)
- Hindi (99%)
- Italian (84%)
- Norwegian Bokmål (76%)
- Persian (fa_ARAB) (98%)
- Polish (99%)
- Portuguese (Brazil) (99%)
- Portuguese (Portugal) (88%)
- Russian (96%)
- Slovak (63%)
- Spanish (100%)
- Swedish (87%)
- Telugu (70%)
- Tetum (53%)
- Turkish (86%)
- Ukrainian (74%)
- hyw_ARMN (generated) (hyw_ARMN) (65%)
</div>

Partial translations are available for various other languages.

The Koha team welcomes additional translations; please see

- [Koha Translation Info](https://wiki.koha-community.org/wiki/Translating_Koha)

For information about translating Koha, and join the koha-translate 
list to volunteer:

- [Koha Translate List](https://lists.koha-community.org/cgi-bin/mailman/listinfo/koha-translate)

The most up-to-date translations can be found at:

- [Koha Translation](https://translate.koha-community.org/)

## Release Team

The release team for Koha 23.11.13 is


- Release Manager: Katrin Fischer

- Release Manager assistants:
  - Tomás Cohen Arazi
  - Martin Renvoize
  - Jonathan Druart

- QA Manager: Martin Renvoize

- QA Team:
  - Victor Grousset
  - Lisette Scheer
  - Emily Lamancusa
  - David Cook
  - Jonathan Druart
  - Julian Maurice
  - Baptiste Wojtowski
  - Paul Derscheid
  - Aleisha Amohia
  - Laura Escamilla
  - Tomás Cohen Arazi
  - Kyle M Hall
  - Nick Clemens
  - Lucas Gass
  - Marcel de Rooy
  - Matt Blenkinsop
  - Pedro Amorim
  - Brendan Lawlor
  - Thomas Klausner

- Security Manager: Tomás Cohen Arazi

- Topic Experts:
  - UI Design -- Owen Leonard
  - REST API -- Tomás Cohen Arazi
  - Zebra -- Fridolin Somers

- Bug Wranglers:
  - Michaela Sieber
  - Jacob O'Mara
  - Jake Deery

- Packaging Manager: Mason James

- Documentation Manager: Philip Orr

- Documentation Team:
  - Aude Charillon
  - David Nind
  - Caroline Cyr La Rose

- Wiki curators: 
  - George Williams
  - Thomas Dukleth
  - Jonathan Druart
  - Martin Renvoize

- Release Maintainers:
  - 24.11 -- Paul Derscheid
  - 24.05 -- Wainui Witika-Park
  - 23.11 -- Fridolin Somers
  - 22.11 -- Laura Escamilla

## Credits

We thank the following libraries, companies, and other institutions who are known to have sponsored
new features in Koha 23.11.13
<div style="column-count: 2;">

- Athens County Public Libraries
- Reserve Bank of New Zealand
</div>

We thank the following individuals who contributed patches to Koha 23.11.13
<div style="column-count: 2;">

- Aleisha Amohia (1)
- David Cook (2)
- Kyle M Hall (2)
- Owen Leonard (1)
- Marcel de Rooy (2)
- Fridolin Somers (1)
</div>

We thank the following libraries, companies, and other institutions who contributed
patches to Koha 23.11.13
<div style="column-count: 2;">

- Athens County Public Libraries (1)
- [BibLibre](https://www.biblibre.com) (1)
- [ByWater Solutions](https://bywatersolutions.com) (2)
- Catalyst Open Source Academy (1)
- [Prosentient Systems](https://www.prosentient.com.au) (2)
- Rijksmuseum, Netherlands (2)
</div>

We also especially thank the following individuals who tested patches
for Koha
<div style="column-count: 2;">

- Alex Buckley (8)
- Nick Clemens (1)
- David Cook (1)
- Paul Derscheid (2)
- Katrin Fischer (2)
- Jan Kissig (1)
- Brendan Lawlor (2)
- David Nind (2)
- Martin Renvoize (3)
- Marcel de Rooy (2)
- Fridolin Somers (8)
</div>





We regret any omissions.  If a contributor has been inadvertently missed,
please send a patch against these release notes to koha-devel@lists.koha-community.org.

## Revision control notes

The Koha project uses Git for version control.  The current development
version of Koha can be retrieved by checking out the main branch of:

- [Koha Git Repository](https://git.koha-community.org/koha-community/koha)

The branch for this version of Koha and future bugfixes in this release
line is 23.11.x.

## Bugs and feature requests

Bug reports and feature requests can be filed at the Koha bug
tracker at:

- [Koha Bugzilla](https://bugs.koha-community.org)

He rau ringa e oti ai.
(Many hands finish the work)

Autogenerated release notes updated last on 24 Mar 2025 10:24:14.
