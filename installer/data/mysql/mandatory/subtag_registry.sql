-- http://www.w3.org/International/articles/language-tags/

-- BIDI Stuff, Arabic and Hebrew
INSERT INTO language_script_bidi(rfc4646_subtag,bidi)
VALUES ( 'Arab', 'rtl');
INSERT INTO language_script_bidi(rfc4646_subtag,bidi)
VALUES ( 'Hebr', 'rtl');

-- Default mappings between script and language subcodes
INSERT INTO language_script_mapping(language_subtag,script_subtag)
VALUES ( 'ar', 'Arab');
INSERT INTO language_script_mapping(language_subtag,script_subtag)
VALUES ( 'he', 'Hebr');

-- EXTENSIONS
-- Interface (i)
-- SELECT * FROM language_subtag_registry WHERE type='i';
-- OPAC
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'opac', 'i', 'OPAC','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'opac', 'i', 'en', 'OPAC');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'opac', 'i', 'fr', 'OPAC');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'opac', 'i', 'de', 'OPAC');

-- Staff Client
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'intranet', 'i', 'Staff Client','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'intranet', 'i', 'en', 'Staff Client');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'intranet', 'i', 'fr', 'Client personnel');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'intranet', 'i', 'de', 'Dienstoberfläche');

-- Theme (t)
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'prog', 't', 'Prog','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'prog', 't', 'en', 'Prog');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'prog', 't', 'fr', 'Prog');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'prog', 't', 'de', 'Prog');

-- LANGUAGES

-- Amharic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'am', 'language', 'Amharic','2014-10-29');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'am','amh');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'am', 'language', 'am', 'አማርኛ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'am', 'language', 'en', 'Amharic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'am', 'language', 'de', 'Amharisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'am', 'language', 'pl', 'Amharski');

-- Arabic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ar', 'language', 'Arabic','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ar','ara');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ar', 'language', 'ar', 'العربية');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ar', 'language', 'en', 'Arabic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ar', 'language', 'fr', 'Arabe');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ar', 'language', 'de', 'Arabisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ar', 'language', 'pl', 'Arabski');

-- Azerbaijani
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'az', 'language', 'Azerbaijani','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'az','aze');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'az', 'language', 'az', 'Azərbaycan dili');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'az', 'language', 'en', 'Azerbaijani');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'az', 'language', 'de', 'Aserbaidschanisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'az', 'language', 'pl', 'Azerbejdżański');

-- Byelorussian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'be', 'language', 'Byelorussian','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'be','bel');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'be', 'language', 'be', 'Беларуская мова');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'be', 'language', 'en', 'Byelorussian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'be', 'language', 'de', 'Belarussisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'be', 'language', 'pl', 'Białoruski');

-- Bengali
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'bn', 'language', 'Bengali','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'bn','ben');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bn', 'language', 'bn', 'বাংলা');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bn', 'language', 'en', 'Bengali');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bn', 'language', 'de', 'Bengalisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bn', 'language', 'pl', 'Bengalski');

-- Bulgarian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'bg', 'language', 'Bulgarian','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'bg','bul');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bg', 'language', 'bg', 'Български');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bg', 'language', 'en', 'Bulgarian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bg', 'language', 'fr', 'Bulgare');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bg', 'language', 'de', 'Bulgarisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bg', 'language', 'pl', 'Bułgarski');

-- Catalan
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ca', 'language', 'Catalan','2013-01-12' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ca','cat');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ca', 'language', 'es', 'Catalán');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ca', 'language', 'en', 'Catalan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ca', 'language', 'fr', 'Catalan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ca', 'language', 'ca', 'Català');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ca', 'language', 'de', 'Katalanisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ca', 'language', 'pl', 'Kataloński');

-- Czech
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'cs', 'language', 'Czech','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'cs','cze');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cs', 'language', 'cs', 'Čeština');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cs', 'language', 'en', 'Czech');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cs', 'language', 'fr', 'Tchèque');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cs', 'language', 'de', 'Tschechisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cs', 'language', 'pl', 'Czeski');

-- Danish
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'da', 'language', 'Danish','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'da','dan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'da', 'language', 'da', 'Dansk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'da', 'language', 'en', 'Danish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'da', 'language', 'fr', 'Danois');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'da', 'language', 'de', 'Dänisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'da', 'language', 'pl', 'Duński');

-- German
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'de', 'language', 'German','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'de','ger');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'de', 'language', 'de', 'Deutsch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'de', 'language', 'en', 'German');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'de', 'language', 'fr', 'Allemand');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'de', 'language', 'pl', 'Niemiecki');

-- Greek
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'el', 'language', 'Greek, Modern [1453- ]','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'el','gre');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'el', 'language', 'el', 'Eλληνικά');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'el', 'language', 'en', 'Greek, Modern [1453- ]');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'el', 'language', 'fr', 'Grec Moderne (Après 1453)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'el', 'language', 'de', 'Griechisch (Modern 1453-)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'el', 'language', 'pl', 'Grecki nowożytny (po 1453)');

-- English
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'en', 'language', 'English','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'en','eng');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'en', 'language', 'en', 'English');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'en', 'language', 'fr', 'Anglais');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'en', 'language', 'de', 'Englisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'en', 'language', 'pl', 'Angielski');

-- Spanish, Castilian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'es', 'language', 'Spanish','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'es','spa');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'es', 'language', 'es', 'Español');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'es', 'language', 'en', 'Spanish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'es', 'language', 'fr', 'Espagnol');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'es', 'language', 'de', 'Spanisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'es', 'language', 'pl', 'Hiszpański');

-- Basque
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'eu', 'language', 'Basque','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'eu','baq');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'eu', 'language', 'eu', 'Euskera');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'eu', 'language', 'en', 'Basque');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'eu', 'language', 'de', 'Baskisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'eu', 'language', 'pl', 'Baskijski');

-- Persian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'fa', 'language', 'Persian','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'fa','per');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fa', 'language', 'fa', 'فارسى');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fa', 'language', 'en', 'Persian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fa', 'language', 'fr', 'Persan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fa', 'language', 'de', 'Persisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fa', 'language', 'pl', 'Perski');

-- Finnish
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'fi', 'language', 'Finnish','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'fi','fin');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fi', 'language', 'fi', 'Suomi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fi', 'language', 'en', 'Finnish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fi', 'language', 'de', 'Finnisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fi', 'language', 'pl', 'Fiński');

-- Faroese
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'fo', 'language', 'Faroese','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'fo','fao');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fo', 'language', 'fo', 'Føroyskt');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fo', 'language', 'en', 'Faroese');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fo', 'language', 'de', 'Färöisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fo', 'language', 'pl', 'Farerski');

-- French
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'fr', 'language', 'French','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'fr','fre');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fr', 'language', 'en', 'French');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fr', 'language', 'fr', 'Français');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fr', 'language', 'de', 'Französisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fr', 'language', 'pl', 'Francuski');

-- Scottish Gaelic

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'gd', 'language', 'Scottish Gaelic', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'gd','gla');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gd', 'language', 'en', 'Scottish Gaelic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gd', 'language', 'en_GB', 'Scottish Gaelic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gd', 'language', 'gd', 'Gàidhlig');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gd', 'language', 'fr', 'Gaélique écossais');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gd', 'language', 'de', 'Schottisch-Gälisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gd', 'language', 'pl', 'Język szkocki gaelicki');

-- Galician
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'gl', 'language', 'Galician','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'gl','glg');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gl', 'language', 'gl', 'Galego');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gl', 'language', 'en', 'Galician');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gl', 'language', 'fr', 'Galicien');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gl', 'language', 'de', 'Galicisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gl', 'language', 'pl', 'Galicyjski');

-- Hebrew
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'he', 'language', 'Hebrew','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'he','heb');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'he', 'language', 'he', 'עִבְרִית');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'he', 'language', 'en', 'Hebrew');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'he', 'language', 'fr', 'Hébreu');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'he', 'language', 'de', 'Hebräisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'he', 'language', 'pl', 'Hebrajski');

-- Hindi
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'hi', 'language', 'Hindi','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'hi','hin');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hi', 'language', 'hi', 'हिन्दी');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hi', 'language', 'en', 'Hindi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hi', 'language', 'fr', 'Hindi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hi', 'language', 'de', 'Hindi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hi', 'language', 'pl', 'Indoaryjskie (inne)');

-- Croatian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'hr', 'language', 'Croatian','2014-07-24' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'hr','hrv');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hr', 'language', 'hr', 'Hrvatski');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hr', 'language', 'en', 'Croatian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hr', 'language', 'fr', 'Croate');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hr', 'language', 'de', 'Kroatisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hr', 'language', 'pl', 'Chorwacki');

-- Hungarian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'hu', 'language', 'Hungarian','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'hu','hun');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hu', 'language', 'hu', 'Magyar');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hu', 'language', 'en', 'Hungarian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hu', 'language', 'fr', 'Hongrois');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hu', 'language', 'de', 'Ungarisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hu', 'language', 'pl', 'Wegierski');

-- Armenian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'hy', 'language', 'Armenian','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'hy','arm');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hy', 'language', 'hy', 'Հայերեն');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hy', 'language', 'en', 'Armenian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hy', 'language', 'fr', 'Armenian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hy', 'language', 'de', 'Armenisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hy', 'language', 'pl', 'Ormiański');

-- Indonesian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'id', 'language', 'Indonesian','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'id','ind');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'id', 'language', 'id', 'Bahasa Indonesia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'id', 'language', 'en', 'Indonesian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'id', 'language', 'fr', 'Indonésien');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'id', 'language', 'de', 'Indonesisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'id', 'language', 'pl', 'Indonezyjski');

-- Icelandic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'is', 'language', 'Icelandic','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'is','ice');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'is', 'language', 'is', 'Íslenska');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'is', 'language', 'en', 'Icelandic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'is', 'language', 'de', 'Isländisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'is', 'language', 'pl', 'Islandzki');

-- Italian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'it', 'language', 'Italian','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'it','ita');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'it', 'language', 'it', 'Italiano');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'it', 'language', 'en', 'Italian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'it', 'language', 'fr', 'Italien');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'it', 'language', 'de', 'Italienisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'it', 'language', 'pl', 'Włoski');

-- Japanese
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ja', 'language', 'Japanese','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ja','jpn');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ja', 'language', 'ja', '日本語');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ja', 'language', 'en', 'Japanese');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ja', 'language', 'fr', 'Japonais');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ja', 'language', 'de', 'Japanisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ja', 'language', 'pl', 'Japoński');

-- Georgian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ka', 'language', 'Georgian','2015-04-20');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ka', 'geo');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ka', 'language', 'ka', 'ქართული');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ka', 'language', 'en', 'Georgian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ka', 'language', 'fr', 'Géorgien');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ka', 'language', 'de', 'Georgisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ka', 'language', 'es', 'Georgiano');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ka', 'language', 'pl', 'Gruziński');

-- Greenlandic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'kl', 'language', 'Greenlandic', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'kl', 'kal');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kl', 'language', 'en', 'Greenlandic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kl', 'language', 'kl', 'Kalaallisut');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kl', 'language', 'de', 'Grönländisch');

-- Kannada
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'kn', 'language', 'Kannada','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'kn', 'kan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kn', 'language', 'kn', 'ಕನ್ನಡ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kn', 'language', 'en', 'Kannada');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kn', 'language', 'pl', 'Kannada');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kn', 'language', 'de', 'Kannada');

-- Khmer
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'km', 'language', 'Khmer','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES( 'km','khm');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'km', 'language', 'km', 'ភាសាខ្មែរ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'km', 'language', 'en', 'Khmer');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'km', 'language', 'de', 'Khmer');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'km', 'language', 'pl', 'Khmerski');

-- Korean
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ko', 'language', 'Korean','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ko','kor');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ko', 'language', 'ko', '한국어');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ko', 'language', 'en', 'Korean');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ko', 'language', 'fr', 'Coréen');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ko', 'language', 'de', 'Koreanisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ko', 'language', 'pl', 'Koreański');

-- Karelian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'krl', 'language', 'Karelian', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'krl', 'krl');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'krl', 'language', 'en', 'Karelian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'krl', 'language', 'krl', 'Karjala');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'krl', 'language', 'de', 'Karelisch');

-- Kurdish
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ku', 'language', 'Kurdish','2014-05-13');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ku','kur');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ku', 'language', 'ku', 'کوردی');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ku', 'language', 'en', 'Kurdish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ku', 'language', 'fr', 'Kurde');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ku', 'language', 'de', 'Kurdisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ku', 'language', 'es', 'Kurdo');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ku', 'language', 'pl', 'Kurdyjski');

-- Cornish
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'kw', 'language', 'Cornish', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'kw', 'cor');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kw', 'language', 'en', 'Cornish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kw', 'language', 'kw', 'Kernowek');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kw', 'language', 'de', 'Kornisch');

-- Latin
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'la', 'language', 'Latin','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'la','lat');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'la', 'language', 'la', 'Latina');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'la', 'language', 'en', 'Latin');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'la', 'language', 'fr', 'Latin');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'la', 'language', 'de', 'Lateinisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'la', 'language', 'pl', 'Łaciński');

-- Lao
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'lo', 'language', 'Lao','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'lo','lao');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'lo', 'language', 'lo', 'ພາສາລາວ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'lo', 'language', 'en', 'Lao');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'lo', 'language', 'fr', 'Laotien');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'lo', 'language', 'de', 'Laotisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'lo', 'language', 'pl', 'Laotański');

-- Maori
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mi', 'language', 'Maori','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mi','mao');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mi', 'language', 'mi', 'Te Reo Māori');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mi', 'language', 'en', 'Maori');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mi', 'language', 'de', 'Maorisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mi', 'language', 'pl', 'Maoryjski');

-- Mongolian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mn', 'language', 'Mongolian','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mn','mon');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mn', 'language', 'mn', 'Mонгол');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mn', 'language', 'en', 'Mongolian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mn', 'language', 'de', 'Mongolisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mn', 'language', 'pl', 'Mongolski');

-- Marathi
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mr', 'language', 'Marathi','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mr','mar');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mr', 'language', 'mr', 'मराठी');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mr', 'language', 'en', 'Marathi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mr', 'language', 'de', 'Marathi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mr', 'language', 'pl', 'Marathi');

-- Malay
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ms', 'language', 'Malay','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ms','may');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ms', 'language', 'ms', 'Bahasa melayu');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ms', 'language', 'en', 'Malay');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ms', 'language', 'de', 'Malaiisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ms', 'language', 'pl', 'Malajski');

-- Burmese
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'my', 'language', 'Burmese', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'my', 'bur');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'my', 'language', 'en', 'Burmese');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'my', 'language', 'my', 'မြန်မာစာ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'my', 'language', 'de', 'Burmesisch');

-- Norwegian (bokmål)
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'nb', 'language', 'Norwegian bokmål','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'nb','nob');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nb', 'language', 'nb', 'Norsk bokmål');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nb', 'language', 'no', 'Norsk bokmål');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nb', 'language', 'en', 'Norwegian bokmål');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nb', 'language', 'fr', 'Norvégien bokmål');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nb', 'language', 'de', 'Norwegisch bokmål');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nb', 'language', 'pl', 'Norweski bokmål');

-- Nepali
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ne', 'language', 'Nepali','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ne','nep');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ne', 'language', 'ne', 'नेपाली');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ne', 'language', 'en', 'Nepali');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ne', 'language', 'de', 'Nepali');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ne', 'language', 'pl', 'Nepalski');

-- Dutch
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'nl', 'language', 'Dutch','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'nl','dut');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nl', 'language', 'nl', 'Nederlands');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nl', 'language', 'en', 'Dutch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nl', 'language', 'fr', 'Néerlandais');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nl', 'language', 'de', 'Niederländisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nl', 'language', 'pl', 'Niderlandzki');

-- Norwegian (nynorsk)
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'nn', 'language', 'Norwegian nynorsk','2011-02-14' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'nn','nno');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nn', 'language', 'nb', 'Norsk nynorsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nn', 'language', 'nn', 'Norsk nynorsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nn', 'language', 'no', 'Norsk nynorsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nn', 'language', 'en', 'Norwegian nynorsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nn', 'language', 'fr', 'Norvégien nynorsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nn', 'language', 'de', 'Norwegisch nynorsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nn', 'language', 'pl', 'Norweski nynorsk');

-- Norwegian (inclusive)
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'no', 'language', 'Norwegian','2024-09-19' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'no','nor');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'no', 'language', 'nb', 'Norsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'no', 'language', 'nn', 'Norsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'no', 'language', 'no', 'Norsk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'no', 'language', 'en', 'Norwegian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'no', 'language', 'fr', 'Norvégien');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'no', 'language', 'de', 'Norwegisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'no', 'language', 'pl', 'Norweski');

-- Punjabi
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'pa', 'language', 'Punjabi', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'pa', 'pan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pa', 'language', 'en', 'Punjabi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pa', 'language', 'pa', 'پنجابی');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pa', 'language', 'de', 'Panjabi');

-- Pangwa
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'pbr', 'language', 'Pangwa','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'pbr','pbr');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pbr', 'language', 'pbr', 'Ekipangwa');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pbr', 'language', 'en', 'Pangwa');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pbr', 'language', 'de', 'Pangwa');

-- Polish
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'pl', 'language', 'Polish','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'pl','pol');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pl', 'language', 'pl', 'Polski');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pl', 'language', 'en', 'Polish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pl', 'language', 'fr', 'Polonais');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pl', 'language', 'de', 'Polnisch');

-- Dari
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'prs', 'language', 'Dari','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'prs','prs');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'prs', 'language', 'prs', 'درى');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'prs', 'language', 'en', 'Dari');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'prs', 'language', 'de', 'Dari');

-- Pashto
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ps', 'language', 'Pashto', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ps', 'pus');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ps', 'language', 'en', 'Pashto');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ps', 'language', 'ps', 'پښتو');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ps', 'language', 'de', 'Paschtu');

-- Portuguese
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'pt', 'language', 'Portuguese','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'pt','por');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pt', 'language', 'pt', 'Português');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pt', 'language', 'en', 'Portuguese');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pt', 'language', 'fr', 'Portugais');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pt', 'language', 'de', 'Portugiesisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pt', 'language', 'pl', 'Portugalski');

-- Finnish Kalo
INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES( 'rmf', 'rmf');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'rmf', 'language', 'en', 'Finnish Kalo');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'rmf', 'language', 'fi', 'Suomen romanikieli');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'rmf', 'language', 'rmf', 'Fíntika Rómma');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'rmf', 'language', 'de', 'Finnisch Kalo');

-- Romanian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ro', 'language', 'Romanian','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ro','rum');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ro', 'language', 'ro', 'Română');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ro', 'language', 'en', 'Romanian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ro', 'language', 'fr', 'Roumain');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ro', 'language', 'de', 'Rumänisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ro', 'language', 'pl', 'Rumuński');

-- Russian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ru', 'language', 'Russian','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ru','rus');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ru', 'language', 'ru', 'Русский');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ru', 'language', 'en', 'Russian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ru', 'language', 'fr', 'Russe');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ru', 'language', 'de', 'Russisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ru', 'language', 'pl', 'Rosyjski');

-- Kinyarwanda
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'rw', 'language', 'Kinyarwanda','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'rw','kin');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'rw', 'language', 'rw', 'Ikinyarwanda');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'rw', 'language', 'en', 'Kinyarwanda');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'rw', 'language', 'de', 'Kinyarwanda');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'rw', 'language', 'pl', 'Kinyarwanda');

-- Sindhi
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sd', 'language', 'Sindhi','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sd','snd');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sd', 'language', 'sd', 'سنڌي');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sd', 'language', 'en', 'Sindhi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sd', 'language', 'de', 'Sindhi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sd', 'language', 'pl', 'Sindhi');

-- Slovak
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sk', 'language', 'Slovak','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sk','slo');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sk', 'language', 'sk', 'Slovenčina');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sk', 'language', 'en', 'Slovak');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sk', 'language', 'de', 'Slowakisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sk', 'language', 'pl', 'Słowacki');

-- Slovene
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sl', 'language', 'Slovene','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sl','slv');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sl', 'language', 'sl', 'Slovenščina');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sl', 'language', 'en', 'Slovene');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sl', 'language', 'de', 'Slowenisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sl', 'language', 'pl', 'Słoweński');

-- Akkala Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sia', 'language', 'Akkala Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sia', 'sia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sia', 'language', 'en', 'Akkala Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sia', 'language', 'sia', 'ču´kksuâlis');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sia', 'language', 'de', 'Akkalasamisch');

-- Kildin Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sjd', 'language', 'Kildin Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sjd', 'sjd');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjd', 'language', 'en', 'Kildin Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjd', 'language', 'sjd', 'Кӣллт са̄мь кӣлл');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjd', 'language', 'de', 'Kildinsamisch');

-- Ter Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sjt', 'language', 'Ter Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sjt', 'sjt');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjt', 'language', 'en', 'Ter Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjt', 'language', 'sjt', 'saa´mekiill');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjt', 'language', 'de', 'Tersamisch');

-- Pite Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sje', 'language', 'Pite Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sje', 'sje');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sje', 'language', 'en', 'Pite Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sje', 'language', 'sje', 'Bidumsámegiella');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sje', 'language', 'de', 'Pitesamisch');

-- Kemi Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sjk', 'language', 'Kemi Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sjk', 'sjk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjk', 'language', 'en', 'Kemi Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjk', 'language', 'sjk', 'samääškiela');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sjk', 'language', 'de', 'Kemisamisch');

-- Ume Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sju', 'language', 'Ume Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sju', 'sju');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sju', 'language', 'en', 'Ume Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sju', 'language', 'sju', 'Ubmejensámien giella');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sju', 'language', 'de', 'Umesamisch');

-- Southern Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sma', 'language', 'Southern Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sma', 'sma');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sma', 'language', 'en', 'Southern Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sma', 'language', 'sma', 'Åarjelsaemien gïele');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sma', 'language', 'de', 'Südsamisch');

-- Northern Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sme', 'language', 'Northern Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sme', 'sme');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sme', 'language', 'en', 'Northern Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sme', 'language', 'fi', 'pohjoissaame');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sme', 'language', 'sv', 'Nordsamiska');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sme', 'language', 'sme', 'davvisámegiella');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sme', 'language', 'de', 'Nordsamisch');

-- Sami languages
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'smi', 'language', 'Sami languages', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'smi', 'smi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smi', 'language', 'en', 'Sami languages');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smi', 'language', 'fi', 'saamelaiskielet');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smi', 'language', 'sv', 'Samiska');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smi', 'language', 'smi', 'Saami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smi', 'language', 'de', 'Samische Sprachen');

-- Lule Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'smj', 'language', 'Lule Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'smj', 'smj');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smj', 'language', 'en', 'Lule Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smj', 'language', 'smj', 'julevsámegiella');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smj', 'language', 'de', 'Lulesamisch');

-- Inari Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'smn', 'language', 'Inari Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'smn', 'smn');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smn', 'language', 'en', 'Inari Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smn', 'language', 'smn', 'anarâškielâ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'smn', 'language', 'de', 'Inarisamisch');

-- Skolt Sami
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sms', 'language', 'Skolt Sami', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sms', 'sms');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sms', 'language', 'en', 'Skolt Sami');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sms', 'language', 'sms', 'sääʹmǩiõll');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sms', 'language', 'de', 'Skoltsamisch');

-- Somali
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'so', 'language', 'Somali', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'so', 'som');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'so', 'language', 'en', 'Somali');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'so', 'language', 'so', 'Af-Soomaali');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'so', 'language', 'de', 'Somali');

-- Albanian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sq', 'language', 'Albanian','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sq','alb');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sq', 'language', 'sq', 'Shqip');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sq', 'language', 'en', 'Albanian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sq', 'language', 'de', 'Albanisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sq', 'language', 'pl', 'Albański');

-- Serbian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sr', 'language', 'Serbian','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sr','srp');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sr', 'language', 'sr', 'Cрпски');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sr', 'language', 'en', 'Serbian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sr', 'language', 'fr', 'Serbe');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sr', 'language', 'de', 'Serbisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sr', 'language', 'pl', 'Serbski');

-- Sotho
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'st', 'language', 'Sotho', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'st', 'sot');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'st', 'language', 'en', 'Sotho');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'st', 'language', 'st', 'Sesotho');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'st', 'language', 'de', 'Sotho');

-- Swedish
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sv', 'language', 'Swedish','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sv','swe');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sv', 'language', 'sv', 'Svenska');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sv', 'language', 'en', 'Swedish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sv', 'language', 'fr', 'Suédois');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sv', 'language', 'de', 'Schwedisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sv', 'language', 'pl', 'Szwedzki');

-- Swahili
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sw', 'language', 'Swahili','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sw','swa');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sw', 'language', 'sw', 'Kiswahili');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sw', 'language', 'en', 'Swahili');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sw', 'language', 'de', 'Swahili');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sw', 'language', 'pl', 'Suahili');

-- Tamil
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ta', 'language', 'Tamil','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ta','tam');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ta', 'language', 'ta', 'தமிழ்');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ta', 'language', 'en', 'Tamil');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ta', 'language', 'de', 'Tamil');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ta', 'language', 'pl', 'Tamilski');

-- Tetum
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'tet', 'language', 'Tetum','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'tet','tet');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tet', 'language', 'tet', 'Tetun');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tet', 'language', 'en', 'Tetum');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tet', 'language', 'fr', 'Tétoum');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tet', 'language', 'de', 'Tetum');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tet', 'language', 'pl', 'Tetum');

-- Thai
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'th', 'language', 'Thai','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'th','tha');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'th', 'language', 'th', 'ภาษาไทย');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'th', 'language', 'en', 'Thai');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'th', 'language', 'fr', 'Thaï');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'th', 'language', 'de', 'Thailändisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'th', 'language', 'pl', 'Tajski (syjamski)');

-- Tagalog
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'tl', 'language', 'Tagalog','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'tl','tgl');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tl', 'language', 'tl', 'Tagalog');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tl', 'language', 'en', 'Tagalog');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tl', 'language', 'de', 'Tagalog');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tl', 'language', 'pl', 'Tagalog (tagalski)');

-- Turkish
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'tr', 'language', 'Turkish','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'tr','tur');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tr', 'language', 'tr', 'Türkçe');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tr', 'language', 'en', 'Turkish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tr', 'language', 'fr', 'Turc');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tr', 'language', 'de', 'Türkisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tr', 'language', 'pl', 'Turecki');

-- Ukrainian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'uk', 'language', 'Ukrainian','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'uk','ukr');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uk', 'language', 'uk', 'Українська');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uk', 'language', 'en', 'Ukrainian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uk', 'language', 'fr', 'Ukrainien');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uk', 'language', 'de', 'Ukrainisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uk', 'language', 'pl', 'Ukraiński');

-- Urdu
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ur', 'language', 'Urdu','2005-10-16' );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ur','urd');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ur', 'language', 'en', 'Urdu');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ur', 'language', 'ur', 'اردو');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ur', 'language', 'fr', 'Ourdou');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ur', 'language', 'de', 'Urdu');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ur', 'language', 'pl', 'Urdu');

-- Vietnamese
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'vi', 'language', 'Vietnamese','2014-10-30');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'vi','vie');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'vi', 'language', 'vi', 'Tiếng Việt');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'vi', 'language', 'en', 'Vietnamese');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'vi', 'language', 'de', 'Vietnamesisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'vi', 'language', 'pl', 'Wietnamski');

-- Votic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'vot', 'language', 'Votic', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'vot', 'vot');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'vot', 'language', 'en', 'Votic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'vot', 'language', 'vot', 'vađđa ceeli');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'vot', 'language', 'de', 'Wotisch');

-- Chinese
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'zh', 'language', 'Chinese','2005-10-16');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'zh','chi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zh', 'language', 'zh', '中文');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zh', 'language', 'en', 'Chinese');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zh', 'language', 'fr', 'Chinois');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zh', 'language', 'de', 'Chinesisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zh', 'language', 'pl', 'Chiński (mandaryński)');

-- SCRIPTS
-- Arabic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Arab', 'script', 'Arabic','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Arab','script', 'Arab', 'العربية');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Arab', 'script','en', 'Arabic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Arab', 'script','fr', 'Arabic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Arab', 'script', 'de', 'Arabisch');

-- Armenian
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Armn', 'script', 'Armenian','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Armn', 'script', 'Armn', 'Հայոց այբուբեն');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Armn', 'script', 'en', 'Armenian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Armn', 'script', 'de', 'Armenisch');

-- Cyrillic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Cyrl', 'script', 'Cyrillic','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Cyrl', 'script', 'Cyrl', 'Кирилица');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Cyrl', 'script', 'en', 'Cyrillic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Cyrl', 'script', 'fr', 'Cyrillic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Cyrl', 'script', 'de', 'Kyrillisch');

-- Ethiopic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Ethi', 'script', 'Ethiopic','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Ethi', 'script', 'Ethi', 'ግዕዝ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Ethi', 'script', 'en', 'Ethiopic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Ethi', 'script', 'de', 'Äthiopisch');

-- Greek
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Grek', 'script', 'Greek','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Grek', 'script', 'Grek', 'Ελληνικό αλφάβητο');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Grek', 'script', 'en', 'Greek');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Grek', 'script', 'fr', 'Greek');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Grek', 'script', 'de', 'Griechisch');


-- Han - Simplified
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Hans', 'script', 'Han (Simplified variant)','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hans', 'script', 'Hans', '简体字');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hans', 'script', 'en', 'Han (Simplified variant)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hans', 'script', 'fr', 'Han (Simplified variant)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hans', 'script', 'de', 'Han (Vereinfachte Variante)');


-- Han - Traditional
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Hant', 'script', 'Han (Traditional variant)','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hant', 'script', 'Hant', '繁體字');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hant', 'script', 'en', 'Han (Traditional variant)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hant', 'script', 'de', 'Han (Traditionelle Variante)');

-- Hebrew
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Hebr', 'script', 'Hebrew','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hebr', 'script', 'Hebr', 'אָלֶף־בֵּית עִבְרִי');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hebr', 'script', 'en', 'Hebrew');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Hebr', 'script', 'de', 'Hebräisch');

-- Japanese
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Jpan', 'script', 'Japanese','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Jpan', 'script', 'Jpan', '漢字');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Jpan', 'script', 'en', 'Japanese');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Jpan', 'script', 'de', 'Japanisch');

-- Kannada
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Knda', 'script', 'Kannada','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Knda', 'script', 'Knda', 'ಕನ್ನಡ ಲಿಪಿ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Knda', 'script', 'en', 'Kannada');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Knda', 'script', 'de', 'Kannada');

-- Korean
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Kore', 'script', 'Korean','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Kore', 'script', 'Kore', '한글');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Kore', 'script', 'en', 'Korean');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES( 'Kore', 'script', 'de', 'Koreanisch');

-- Lao
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'Laoo', 'script', 'Lao','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Laoo', 'script', 'Laoo', 'ອັກສອນລາວ');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Laoo', 'script', 'en', 'Lao');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'Laoo', 'script', 'de', 'Laotisch');


-- REGIONS - Order by country code
-- Albania
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'AL', 'region', 'Albania','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'AL', 'region', 'en', 'Albania');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'AL', 'region', 'sq', 'Shqipërisë');

-- Azerbaijan
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'AZ', 'region', 'Azerbaijan','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'AZ', 'region', 'en', 'Azerbaijan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'AZ', 'region', 'az', 'Azərbaycan');

-- Belgium
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'BE', 'region', 'Belgium','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'BE', 'region', 'en', 'Belgium');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'BE', 'region', 'nl', 'België');

-- Brazil
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'BR', 'region', 'Brazil','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'BR', 'region', 'en', 'Brazil');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'BR', 'region', 'pt', 'Brasil');

-- Belarus
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'BY', 'region', 'Belarus','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'BY', 'region', 'en', 'Belarus');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'BY', 'region', 'be', 'Беларусь');

-- Canada
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'CA', 'region', 'Canada','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'CA', 'region', 'en', 'Canada');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'CA', 'region', 'fr', 'Canada');

-- Switzerland
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'CH', 'region', 'Switzerland','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'CH', 'region', 'en', 'Switzerland');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'CH', 'region', 'de', 'Schweiz');

-- China
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'CN', 'region', 'China','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'CN', 'region', 'en', 'China');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'CN', 'region', 'zh', '中国');

-- Czech Republic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'CZ', 'region', 'Czech Republic','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'CZ', 'region', 'en', 'Czech Republic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'CZ', 'region', 'cs', 'Česká republika');

-- Germany
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'DE', 'region', 'Germany','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'DE', 'region', 'en', 'Germany');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'DE', 'region', 'de', 'Deutschland');

-- Denmark
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'DK', 'region', 'Denmark','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'DK', 'region', 'en', 'Denmark');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'DK', 'region', 'dk', 'Danmark');

-- Spain
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ES', 'region', 'Spain','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ES', 'region', 'en', 'Spain');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ES', 'region', 'es', 'España');

-- Finland
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'FI', 'region', 'Finland','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'FI', 'region', 'en', 'Finland');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'FI', 'region', 'fi', 'Suomi');

-- Faroe Islands
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'FO', 'region', 'Faroe Islands','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'FO', 'region', 'en', 'Faroe Islands');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'FO', 'region', 'fo', 'Føroyar');

-- France
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'FR', 'region', 'France','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'FR', 'region', 'en', 'France');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'FR', 'region', 'fr', 'France');

-- United Kingdom
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'GB', 'region', 'United Kingdom','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'GB', 'region', 'en', 'United Kingdom');

-- Greece
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'GR', 'region', 'Greece','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'GR', 'region', 'en', 'Greece');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'GR', 'region', 'el', 'Ελλάδα');

-- Croatia
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'HR', 'region', 'Croatia','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'HR', 'region', 'en', 'Croatia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'HR', 'region', 'hr', 'Hrvatska');

-- Hungary
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'HU', 'region', 'Hungary','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'HU', 'region', 'en', 'Hungary');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'HU', 'region', 'hu', 'Magyarország');

-- Indonesia
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ID', 'region', 'Indonesia','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ID', 'region', 'en', 'Indonesia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ID', 'region', 'id', 'Indonesia');

-- India
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'IN', 'region', 'India','2015-05-28');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'IN', 'region', 'en', 'India');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'IN', 'region', 'bn', 'ভারত');

-- Iceland
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'IS', 'region', 'Iceland','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'IS', 'region', 'en', 'Iceland');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'IS', 'region', 'is', 'Ísland');

-- Italy
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'IT', 'region', 'Italy','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'IT', 'region', 'en', 'Italy');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'IT', 'region', 'it', 'Italia');

-- Japan
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'JP', 'region', 'Japan','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'JP', 'region', 'en', 'Japan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'JP', 'region', 'ja', '日本');

-- Kenya
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'KE', 'region', 'Kenya','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'KE', 'region', 'en', 'Kenya');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'KE', 'region', 'rw', 'Kenya');

-- Cambodia
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'KH', 'region', 'Cambodia','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'KH', 'region', 'en', 'Cambodia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'KH', 'region', 'km', 'កម្ពុជា');

-- North Korea
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'KP', 'region', 'North Korea','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'KP', 'region', 'en', 'North Korea');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'KP', 'region', 'ko', '조선민주주의인민공화국');

-- Sri Lanka
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'LK', 'region', 'Sri Lanka','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'LK', 'region', 'en', 'Sri Lanka');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'LK', 'region', 'ta', 'இலங்கை');

-- Malaysia
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'MY', 'region', 'Malaysia','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'MY', 'region', 'en', 'Malaysia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'MY', 'region', 'ms', 'Malaysia');

-- Niger
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'NE', 'region', 'Niger','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NE', 'region', 'en', 'Niger');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NE', 'region', 'ne', 'Niger');

-- Netherlands
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'NL', 'region', 'Netherlands','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NL', 'region', 'en', 'Netherlands');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NL', 'region', 'nl', 'Nederland');

-- Norway
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'NO', 'region', 'Norway','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NO', 'region', 'en', 'Norway');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NO', 'region', 'ne', 'Noreg');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NO', 'region', 'nn', 'Noreg');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NO', 'region', 'no', 'Noreg');

-- New Zealand
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'NZ', 'region', 'New Zealand','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'NZ', 'region', 'en', 'New Zealand');

-- Philippines
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'PH', 'region', 'Philippines','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'PH', 'region', 'en', 'Philippines');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'PH', 'region', 'tl', 'Pilipinas');

-- Pakistan
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'PK', 'region', 'Pakistan','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'PK', 'region', 'en', 'Pakistan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'PK', 'region', 'sd', 'پاكستان');

-- Poland
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'PL', 'region', 'Poland','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'PL', 'region', 'en', 'Poland');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'PL', 'region', 'pl', 'Polska');

-- Portugal
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'PT', 'region', 'Portugal','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'PT', 'region', 'en', 'Portugal');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'PT', 'region', 'pt', 'Portugal');

-- Romania
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'RO', 'region', 'Romania','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'RO', 'region', 'en', 'Romania');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'RO', 'region', 'ro', 'România');

-- Russia
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'RU', 'region', 'Russia','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'RU', 'region', 'en', 'Russia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'RU', 'region', 'ru', 'Россия');

-- Rwanda
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'RW', 'region', 'Rwanda','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'RW', 'region', 'en', 'Rwanda');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'RW', 'region', 'rw', 'Rwanda');

-- Sweden
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'SE', 'region', 'Sweden','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'SE', 'region', 'en', 'Sweden');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'SE', 'region', 'sv', 'Sverige');

-- Slovenia
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'SI', 'region', 'Slovenia','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'SI', 'region', 'en', 'Slovenia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'SI', 'region', 'sl', 'Slovenija');

-- Slovakia
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'SK', 'region', 'Slovakia','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'SK', 'region', 'en', 'Slovakia');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'SK', 'region', 'sk', 'Slovensko');

-- Thailand
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'TH', 'region', 'Thailand','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'TH', 'region', 'en', 'Thailand');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'TH', 'region', 'th', 'ประเทศไทย');

-- Turkey
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'TR', 'region', 'Turkey','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'TR', 'region', 'en', 'Turkey');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'TR', 'region', 'tr', 'Türkiye');

-- Taiwan
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'TW', 'region', 'Taiwan','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'TW', 'region', 'en', 'Taiwan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'TW', 'region', 'zh', '台灣');

-- Ukraine
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'UA', 'region', 'Ukraine','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'UA', 'region', 'en', 'Ukraine');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'UA', 'region', 'uk', 'Україна');

-- United States
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'US', 'region', 'United States','2005-10-16');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'US', 'region', 'en', 'United States');

-- Vietnam
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'VN', 'region', 'Vietnam','2014-10-30');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'VN', 'region', 'en', 'Vietnam');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'VN', 'region', 'vi', 'Việt Nam');

-- Estonian

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('et', 'language', 'en', 'Estonian');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('et', 'language', 'et', 'Eesti');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('et', 'language', 'de', 'Estnisch');

INSERT INTO language_subtag_registry (subtag, type, description, added)
VALUES ('et', 'language', 'Estonian', NOW() );

INSERT INTO language_rfc4646_to_iso639 (rfc4646_subtag, iso639_2_code)
VALUES ('et', 'est');

-- Latvian

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('lv', 'language', 'en', 'Latvian');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ( 'lv', 'language', 'lv', 'Latviešu valoda');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('lv', 'language', 'de', 'Lettisch');

INSERT INTO language_subtag_registry (subtag, type, description, added)
VALUES ('lv', 'language', 'Latvian', now());

INSERT INTO language_rfc4646_to_iso639 (rfc4646_subtag, iso639_2_code)
VALUES ('lv', 'lav');

-- Lithuanian

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('lt', 'language', 'en', 'Lithuanian');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('lt', 'language', 'lt', 'Lietuvių kalba');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('lt', 'language', 'de', 'Litauisch');

INSERT INTO language_subtag_registry (subtag, type, description, added)
VALUES ('lt', 'language', 'Lithuanian', now());

INSERT INTO language_rfc4646_to_iso639 (rfc4646_subtag, iso639_2_code)
VALUES ('lt', 'lit');

-- Inuktitut

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('iu', 'language', 'en', 'Inuktitut');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('iu', 'language', 'iu', 'ᐃᓄᒃᑎᑐᑦ');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('iu', 'language', 'de', 'Inuktitut');

INSERT INTO language_subtag_registry (subtag, type, description, added)
VALUES ('iu', 'language', 'Inuktitut', now());

INSERT INTO language_rfc4646_to_iso639 (rfc4646_subtag, iso639_2_code)
VALUES ('iu', 'iku');

-- Inupiaq

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('ik', 'language', 'en', 'Inupiaq');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('ik', 'language', 'ik', 'Iñupiaq');

INSERT INTO language_descriptions (subtag, type, lang, description)
VALUES ('ik', 'language', 'de', 'Inupiaq');

INSERT INTO language_subtag_registry (subtag, type, description, added)
VALUES ('ik', 'language', 'Inupiaq', now());

INSERT INTO language_rfc4646_to_iso639 (rfc4646_subtag, iso639_2_code)
VALUES ('ik', 'ipk');

-- Yiddish

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'yi', 'language', 'Yiddish', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'yi', 'yid');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'yi', 'language', 'en', 'Yiddish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'yi', 'language', 'yi', 'יידיש');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'yi', 'language', 'de', 'Jiddisch');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'yi', 'language', 'es', 'Yidis');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'yi', 'language', 'fr', 'Yiddish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'yi', 'language', 'pl', 'Jidysz');

INSERT INTO language_script_mapping(language_subtag,script_subtag)
VALUES ( 'yi', 'Hebr');

-- Cree

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'cr', 'language', 'Cree', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'cr','cre');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cr', 'language', 'en', 'Cree');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cr', 'language', 'fr', 'Cree');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cr', 'language', 'de', 'Cree');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cr', 'language', 'pl', 'Kri');

-- Afrikaans

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'af', 'language', 'Afrikaans', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'af','afr');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'af', 'language', 'en', 'Afrikaans');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'af', 'language', 'fr', 'Afrikaans');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'af', 'language', 'de', 'Afrikaans');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'af', 'language', 'pl', 'Afrikaans');

-- Multiple languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mul', 'language', 'Multiple languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mul','mul');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mul', 'language', 'en', 'Multiple languages');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mul', 'language', 'fr', 'Multilingue');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mul', 'language', 'de', 'Mehrsprachig');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mul', 'language', 'pl', 'Wiele języków');

-- Undetermined

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'und', 'language', 'Undetermined', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'und','und');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'und', 'language', 'en', 'Undetermined');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'und', 'language', 'fr', 'Indéterminée');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'und', 'language', 'de', 'Unbestimmt');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'und', 'language', 'pl', 'Nieokreślony');

-- No linguistic content

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'zxx', 'language', 'No linguistic content', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'zxx','zxx');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zxx', 'language', 'en', 'No linguistic content');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zxx', 'language', 'fr', 'Pas de contenu linguistique');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zxx', 'language', 'de', 'Kein sprachlicher Inhalt');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'zxx', 'language', 'pl', 'Dokument nietekstowy');

-- Ancient Greek (to 1453)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'grc', 'language', 'Ancient Greek (to 1453)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'grc','grc');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'grc', 'language', 'en', 'Ancient Greek (to 1453)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'grc', 'language', 'grc', 'Ἑλληνική');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'grc', 'language', 'pl', 'Grecki starożytny (do 1453)');

-- Syriac

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'syr', 'language', 'Syriac', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'syr','syr');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'syr', 'language', 'en', 'Syriac, Modern');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'syr', 'language', 'pl', 'Syryjski');

-- Church Slavic

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'cu', 'language', 'Church Slavic', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'cu','chu');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cu', 'language', 'en', 'Church Slavic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cu', 'language', 'pl', 'Staro-cerkiewno-słowiański');

-- Coptic

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'cop', 'language', 'Coptic', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'cop','cop');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cop', 'language', 'en', 'Coptic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cop', 'language', 'pl', 'Koptyjski');

-- Official Aramaic (700-300 BCE)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'arc', 'language', 'Official Aramaic (700-300 BCE)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'arc','arc');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'arc', 'language', 'en', 'Aramaic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'arc', 'language', 'pl', 'Aramejski');

-- Old English (ca. 450-1100)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ang', 'language', 'Old English (ca. 450-1100)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ang','ang');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ang', 'language', 'en', 'English, Old (ca. 450-1100)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ang', 'language', 'pl', 'Staroangielski (ok. 450-1100)');

-- Esperanto
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'eo', 'language', 'Esperanto', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'eo','epo');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'eo', 'language', 'en', 'Esperanto');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'eo', 'language', 'eo', 'Esperanto');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'eo', 'language', 'pl', 'Esperanto');

-- Classical Syriac

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'syc', 'language', 'Classical Syriac', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'syc','syc');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'syc', 'language', 'en', 'Syriac');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'syc', 'language', 'pl', 'Syryjski klasyczny');

-- Geez

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'gez', 'language', 'Geez', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'gez','gez');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gez', 'language', 'en', 'Ethiopic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gez', 'language', 'pl', 'Ge''ez (gyyz)');

-- Slavic languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sla', 'language', 'Slavic languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sla','sla');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sla', 'language', 'en', 'Slavic (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sla', 'language', 'pl', 'Słowiańskie (inne)');

-- Sanskrit
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sa', 'language', 'Sanskrit', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sa', 'san');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sa', 'language', 'en', 'Sanskrit');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sa', 'language', 'sa', 'saṃskṛtam');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sa', 'language', 'pl', 'Sanskryt');

-- Kashubian

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'csb', 'language', 'Kashubian', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'csb','csb');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'csb', 'language', 'en', 'Kashubian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'csb', 'language', 'pl', 'Kaszubski');

-- Akkadian

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'akk', 'language', 'Akkadian', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'akk','akk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'akk', 'language', 'en', 'Akkadian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'akk', 'language', 'pl', 'Akadyjski');

-- Middle High German (ca. 1050-1500)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'gmh', 'language', 'Middle High German (ca. 1050-1500)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'gmh','gmh');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gmh', 'language', 'en', 'German, Middle High (ca. 1050-1500)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gmh', 'language', 'pl', 'Średnio-wysoko-niemiecki (ok. 1050-1500)');

-- Egyptian (Ancient)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'egy', 'language', 'Egyptian (Ancient)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'egy','egy');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'egy', 'language', 'en', 'Egyptian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'egy', 'language', 'pl', 'Egipski starożytny');

-- Sorbian languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'wen', 'language', 'Sorbian languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'wen','wen');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'wen', 'language', 'en', 'Sorbian (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'wen', 'language', 'pl', 'Łużyckie (inne)');

-- Irish Gaelic
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ga', 'language', 'Irish', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ga','gle');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ga', 'language', 'en', 'Irish');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ga', 'language', 'ga', 'Gaeilge');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ga', 'language', 'pl', 'Irlandzki');

-- Old French (842-ca. 1400)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'fro', 'language', 'Old French (842-ca. 1400)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'fro','fro');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fro', 'language', 'en', 'French, Old (ca. 842-1300)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fro', 'language', 'pl', 'Starofrancuski (ok. 842-1300)');

-- Romany

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'rom', 'language', 'Romany', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'rom','rom');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'rom', 'language', 'en', 'Romani');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'rom', 'language', 'pl', 'Romani (cygański)');

-- Macedonian

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mk', 'language', 'Macedonian', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mk','mac');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mk', 'language', 'en', 'Macedonian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mk', 'language', 'pl', 'Macedoński');

-- Malayalam

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ml', 'language', 'Malayalam', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ml','mal');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ml', 'language', 'en', 'Malayalam');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ml', 'language', 'pl', 'Malajalam');

-- Ugaritic

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'uga', 'language', 'Ugaritic', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'uga','uga');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uga', 'language', 'en', 'Ugaritic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uga', 'language', 'pl', 'Ugarycki');

-- Uncoded languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mis', 'language', 'Uncoded languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mis','mis');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mis', 'language', 'en', 'Miscellaneous languages');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mis', 'language', 'pl', 'Różne języki');

-- Semitic languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sem', 'language', 'Semitic languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sem','sem');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sem', 'language', 'en', 'Semitic (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sem', 'language', 'pl', 'Semickie (inne)');

-- Sumerian

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sux', 'language', 'Sumerian', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sux','sux');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sux', 'language', 'en', 'Sumerian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sux', 'language', 'pl', 'Sumeryjski');

-- Pali

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'pi', 'language', 'Pali', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'pi','pli');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pi', 'language', 'en', 'Pali');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pi', 'language', 'pl', 'Pali');

-- Bosnian

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'bs', 'language', 'Bosnian', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'bs','bos');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bs', 'language', 'en', 'Bosnian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bs', 'language', 'bn', 'Bosanski');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bs', 'language', 'pl', 'Bośniacki');

-- Chechen

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ce', 'language', 'Chechen', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ce','che');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ce', 'language', 'en', 'Chechen');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ce', 'language', 'pl', 'Czeczeński');

-- Middle Dutch (ca. 1050-1350)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'dum', 'language', 'Middle Dutch (ca. 1050-1350)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'dum','dum');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'dum', 'language', 'en', 'Dutch, Middle (ca. 1050-1350)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'dum', 'language', 'pl', 'Średnioniderlandzki (ok. 1050-1350)');

-- Kazakh

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'kk', 'language', 'Kazakh', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'kk','kaz');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kk', 'language', 'en', 'Kazakh');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kk', 'language', 'kk', 'қазақ тілі');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'kk', 'language', 'pl', 'Kazachski');

-- Standard Tibetan
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'bo', 'language', 'Standard Tibetan', '2017-04-21');

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'bo','tib');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bo', 'language', 'en', 'Standard Tibetan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bo', 'language', 'bo', 'ལྷ་སའི་སྐད་');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bo', 'language', 'pl', 'Tybetański');

-- Middle English (1100-1500)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'enm', 'language', 'Middle English (1100-1500)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'enm','enm');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'enm', 'language', 'en', 'English, Middle (1100-1500)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'enm', 'language', 'pl', 'Średnioangielski (1100-1500)');

-- Middle French (ca. 1400-1600)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'frm', 'language', 'Middle French (ca. 1400-1600)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'frm','frm');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'frm', 'language', 'en', 'French, Middle (ca. 1300-1600)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'frm', 'language', 'pl', 'Średniofrancuski (ok. 1300-1600)');

-- Maltese

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mt', 'language', 'Maltese', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mt','mlt');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mt', 'language', 'en', 'Maltese');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mt', 'language', 'pl', 'Maltański');

-- Gothic

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'got', 'language', 'Gothic', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'got','got');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'got', 'language', 'en', 'Gothic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'got', 'language', 'pl', 'Gocki');

-- Low German

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'nds', 'language', 'Low German', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'nds','nds');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nds', 'language', 'en', 'Low German');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nds', 'language', 'pl', 'Dolnoniemiecki');

-- Iranian languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ira', 'language', 'Iranian languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ira','ira');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ira', 'language', 'en', 'Iranian (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ira', 'language', 'pl', 'Irańskie (inne)');

-- Lingala

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ln', 'language', 'Lingala', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ln','lin');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ln', 'language', 'en', 'Lingala');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ln', 'language', 'pl', 'Lingala');

-- Uzbek

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'uz', 'language', 'Uzbek', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'uz','uzb');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uz', 'language', 'en', 'Uzbek');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'uz', 'language', 'pl', 'Uzbecki');

-- Avestan

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ae', 'language', 'Avestan', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ae','ave');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ae', 'language', 'en', 'Avestan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ae', 'language', 'pl', 'Awestyjski');

-- Choctaw

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'cho', 'language', 'Choctaw', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'cho','cho');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cho', 'language', 'en', 'Choctaw');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cho', 'language', 'pl', 'Choctaw');

-- Judeo-Arabic

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'jrb', 'language', 'Judeo-Arabic', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'jrb','jrb');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'jrb', 'language', 'en', 'Judeo-Arabic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'jrb', 'language', 'pl', 'Judeo-arabski');

-- Bantu languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'bnt', 'language', 'Bantu languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'bnt','bnt');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bnt', 'language', 'en', 'Bantu (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bnt', 'language', 'pl', 'Bantu (inne)');

-- Pahlavi

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'pal', 'language', 'Pahlavi', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'pal','pal');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pal', 'language', 'en', 'Pahlavi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pal', 'language', 'pl', 'Pahlawi');

-- Altaic languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'tut', 'language', 'Altaic languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'tut','tut');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tut', 'language', 'en', 'Altaic (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tut', 'language', 'pl', 'Ałtajskie (inne)');

-- Old High German (ca. 750-1050)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'goh', 'language', 'Old High German (ca. 750-1050)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'goh','goh');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'goh', 'language', 'en', 'German, Old High (ca. 750-1050)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'goh', 'language', 'pl', 'Staro-wysoko-niemiecki (ok.750-1050)');

-- Upper Sorbian

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'hsb', 'language', 'Upper Sorbian', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'hsb','hsb');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hsb', 'language', 'en', 'Upper Sorbian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hsb', 'language', 'pl', 'Górnołużycki');

-- Indic languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'inc', 'language', 'Indic languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'inc','inc');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'inc', 'language', 'en', 'Indic (Other)');

-- Malagasy

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mg', 'language', 'Malagasy', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mg','mlg');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mg', 'language', 'en', 'Malagasy');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mg', 'language', 'pl', 'Malgaski');

-- Romance languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'roa', 'language', 'Romance languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'roa','roa');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'roa', 'language', 'en', 'Romance (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'roa', 'language', 'pl', 'Romańskie (inne)');

-- Celtic languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'cel', 'language', 'Celtic languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'cel','cel');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cel', 'language', 'en', 'Celtic (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cel', 'language', 'pl', 'Celtyckie (inne)');

-- Samaritan Aramaic

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'sam', 'language', 'Samaritan Aramaic', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'sam','sam');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sam', 'language', 'en', 'Samaritan Aramaic');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'sam', 'language', 'pl', 'Samarytański');

-- Bemba (Zambia)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'bem', 'language', 'Bemba (Zambia)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'bem','bem');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bem', 'language', 'en', 'Bemba');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bem', 'language', 'pl', 'Bemba');

-- Friulian

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'fur', 'language', 'Friulian', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'fur','fur');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fur', 'language', 'en', 'Friulian');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'fur', 'language', 'pl', 'Friulski');

-- Germanic languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'gem', 'language', 'Germanic languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'gem','gem');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gem', 'language', 'en', 'Germanic (Other)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gem', 'language', 'pl', 'Germańskie (inne)');

-- Hittite

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'hit', 'language', 'Hittite', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'hit','hit');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hit', 'language', 'en', 'Hittite');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hit', 'language', 'pl', 'Hetycki');

-- Ladino

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'lad', 'language', 'Ladino', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'lad','lad');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'lad', 'language', 'en', 'Ladino');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'lad', 'language', 'pl', 'Ladino');

-- Nahuatl languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'nah', 'language', 'Nahuatl languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'nah','nah');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nah', 'language', 'en', 'Nahuatl');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'nah', 'language', 'pl', 'Nahuatl');

-- Ottoman Turkish (1500-1928)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ota', 'language', 'Ottoman Turkish (1500-1928)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ota','ota');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ota', 'language', 'en', 'Turkish, Ottoman');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ota', 'language', 'pl', 'Turecko-osmański (1500-1928)');

-- Old Persian (ca. 600-400 B.C.)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'peo', 'language', 'Old Persian (ca. 600-400 B.C.)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'peo','peo');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'peo', 'language', 'en', 'Old Persian (ca. 600-400 B.C.)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'peo', 'language', 'pl', 'Staroperski (ok. 600-400 p.n.e.)');

-- Old Provençal (to 1500)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'pro', 'language', 'Old Provençal (to 1500)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'pro','pro');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pro', 'language', 'en', 'Provençal (to 1500)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pro', 'language', 'pl', 'Staroprowansalski (do1500)');

-- Tatar

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'tt', 'language', 'Tatar', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'tt','tat');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tt', 'language', 'en', 'Tatar');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tt', 'language', 'pl', 'Tatarski');

-- Welsh
INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'cy', 'language', 'Welsh', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'cy','wel');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cy', 'language', 'en', 'Welsh');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cy', 'language', 'cy', 'Cymraeg');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'cy', 'language', 'pl', 'Walijski');

-- Yoruba

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'yo', 'language', 'Yoruba', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'yo','yor');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'yo', 'language', 'en', 'Yoruba');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'yo', 'language', 'pl', 'Joruba');

-- Braj

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'bra', 'language', 'Braj', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'bra','bra');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bra', 'language', 'en', 'Braj');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'bra', 'language', 'pl', 'Bradź');

-- Slave (Athapascan)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'den', 'language', 'Slave (Athapascan)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'den','den');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'den', 'language', 'en', 'Slavey');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'den', 'language', 'pl', 'Niewolnicze (atapaskańskie)');

-- Hausa

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ha', 'language', 'Hausa', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ha','hau');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ha', 'language', 'en', 'Hausa');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ha', 'language', 'pl', 'Hausa');

-- Herero

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'hz', 'language', 'Herero', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'hz','her');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hz', 'language', 'en', 'Herero');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'hz', 'language', 'pl', 'Herero');

-- Kashmiri

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ks', 'language', 'Kashmiri', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ks','kas');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ks', 'language', 'en', 'Kashmiri');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ks', 'language', 'pl', 'Kaszmirski');

-- Middle Irish (900-1200)

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'mga', 'language', 'Middle Irish (900-1200)', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'mga','mga');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mga', 'language', 'en', 'Irish, Middle (ca. 1100-1550)');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'mga', 'language', 'pl', 'Średnioirlandzki (1100-1550)');

-- Mayan languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'myn', 'language', 'Mayan languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'myn','myn');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'myn', 'language', 'en', 'Mayan languages');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'myn', 'language', 'pl', 'Majańskie');

-- Nyanja

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ny', 'language', 'Nyanja', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ny','nya');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ny', 'language', 'en', 'Nyanja');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ny', 'language', 'pl', 'Nyanja');

-- Prakrit languages

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'pra', 'language', 'Prakrit languages', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'pra','pra');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pra', 'language', 'en', 'Prakrit languages');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'pra', 'language', 'pl', 'Prakryty');

-- Quechua

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'qu', 'language', 'Quechua', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'qu','que');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'qu', 'language', 'en', 'Quechua');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'qu', 'language', 'pl', 'Keczua');

-- Tigrinya

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'ti', 'language', 'Tigrinya', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'ti','tir');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ti', 'language', 'en', 'Tigrinya');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'ti', 'language', 'pl', 'Tigrinia');

-- Turkmen

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'tk', 'language', 'Turkmen', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'tk','tuk');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tk', 'language', 'en', 'Turkmen');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'tk', 'language', 'pl', 'Turkmeński');

-- Gwich'in

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'gwi', 'language', 'Gwichʼin', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'gwi','gwi');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gwi', 'language', 'en', 'Gwichʼin');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'gwi', 'language', 'pl', 'Gwichʼin');

-- Dogrib

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'dgr', 'language', 'Dogrib', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'dgr','dgr');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'dgr', 'language', 'en', 'Dogrib');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'dgr', 'language', 'pl', 'Dogrib');

-- Chipewyan

INSERT INTO language_subtag_registry( subtag, type, description, added)
VALUES ( 'chp', 'language', 'Chipewyan', NOW() );

INSERT INTO language_rfc4646_to_iso639(rfc4646_subtag,iso639_2_code)
VALUES ( 'chp','chp');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'chp', 'language', 'en', 'Chipewyan');

INSERT INTO language_descriptions(subtag, type, lang, description)
VALUES ( 'chp', 'language', 'pl', 'Chipewyan');
