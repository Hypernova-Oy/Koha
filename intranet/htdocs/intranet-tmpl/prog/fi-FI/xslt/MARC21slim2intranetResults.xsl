<?xml version="1.0" encoding="UTF-8"?>
<!-- $Id: MARC21slim2DC.xsl,v 1.1 2003/01/06 08:20:27 adam Exp $ -->
<!DOCTYPE stylesheet>
<xsl:stylesheet version="1.0"
  xmlns:marc="http://www.loc.gov/MARC21/slim"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:str="http://exslt.org/strings"
  exclude-result-prefixes="marc str">
 <xsl:import href="MARC21slimUtils.xsl"/>
 <xsl:output method = "html" indent="yes" omit-xml-declaration = "yes" encoding="UTF-8"/>

 <xsl:template match="/">
 <xsl:apply-templates/>
 </xsl:template>
 <xsl:template match="marc:record">

 <!-- Option: Display Alternate Graphic Representation (MARC 880) -->
 <xsl:variable name="display880" select="boolean(marc:datafield[@tag=880])"/>
 <xsl:variable name="UseControlNumber" select="marc:sysprefs/marc:syspref[@name='UseControlNumber']"/>

 <xsl:variable name="URLLinkText" select="marc:sysprefs/marc:syspref[@name='URLLinkText']"/>
 <xsl:variable name="Show856uAsImage" select="marc:sysprefs/marc:syspref[@name='Display856uAsImage']"/>
 <xsl:variable name="AlternateHoldingsField" select="substring(marc:sysprefs/marc:syspref[@name='AlternateHoldingsField'], 1, 3)"/>
 <xsl:variable name="AlternateHoldingsSubfields" select="substring(marc:sysprefs/marc:syspref[@name='AlternateHoldingsField'], 4)"/>
 <xsl:variable name="AlternateHoldingsSeparator" select="marc:sysprefs/marc:syspref[@name='AlternateHoldingsSeparator']"/>
 <xsl:variable name="UseAuthoritiesForTracings" select="marc:sysprefs/marc:syspref[@name='UseAuthoritiesForTracings']"/>
 <xsl:variable name="AuthorLinkSortBy" select="marc:sysprefs/marc:syspref[@name='AuthorLinkSortBy']"/>
 <xsl:variable name="AuthorLinkSortOrder" select="marc:sysprefs/marc:syspref[@name='AuthorLinkSortOrder']"/>
 <xsl:variable name="DisplayIconsXSLT" select="marc:sysprefs/marc:syspref[@name='DisplayIconsXSLT']"/>
 <xsl:variable name="IntranetBiblioDefaultView" select="marc:sysprefs/marc:syspref[@name='IntranetBiblioDefaultView']"/>
 <xsl:variable name="OpacSuppression" select="marc:sysprefs/marc:syspref[@name='OpacSuppression']"/>
 <xsl:variable name="leader" select="marc:leader"/>
 <xsl:variable name="leader6" select="substring($leader,7,1)"/>
 <xsl:variable name="leader7" select="substring($leader,8,1)"/>
 <xsl:variable name="leader19" select="substring($leader,20,1)"/>
 <xsl:variable name="biblionumber" select="marc:datafield[@tag=999]/marc:subfield[@code='c']"/>
 <xsl:variable name="controlField008" select="marc:controlfield[@tag=008]"/>
 <xsl:variable name="typeOf008">
 <xsl:choose>
 <xsl:when test="$leader19='a'">ST</xsl:when>
 <xsl:when test="$leader6='a'">
 <xsl:choose>
 <xsl:when test="$leader7='a' or $leader7='c' or $leader7='d' or $leader7='m'">BK</xsl:when>
 <xsl:when test="$leader7='b' or $leader7='i' or $leader7='s'">CR</xsl:when>
 </xsl:choose>
 </xsl:when>
 <xsl:when test="$leader6='t'">BK</xsl:when>
 <xsl:when test="$leader6='o' or $leader6='p'">MX</xsl:when>
 <xsl:when test="$leader6='m'">CF</xsl:when>
 <xsl:when test="$leader6='e' or $leader6='f'">MP</xsl:when>
 <xsl:when test="$leader6='g' or $leader6='k' or $leader6='r'">VM</xsl:when>
 <xsl:when test="$leader6='i' or $leader6='j'">MU</xsl:when>
 <xsl:when test="$leader6='c' or $leader6='d'">PR</xsl:when>
 </xsl:choose>
 </xsl:variable>
 <xsl:variable name="controlField008-23" select="substring($controlField008,24,1)"/>
 <xsl:variable name="controlField008-21" select="substring($controlField008,22,1)"/>
 <xsl:variable name="controlField008-22" select="substring($controlField008,23,1)"/>
 <xsl:variable name="controlField008-24" select="substring($controlField008,25,4)"/>
 <xsl:variable name="controlField008-26" select="substring($controlField008,27,1)"/>
 <xsl:variable name="controlField008-29" select="substring($controlField008,30,1)"/>
 <xsl:variable name="controlField008-34" select="substring($controlField008,35,1)"/>
 <xsl:variable name="controlField008-33" select="substring($controlField008,34,1)"/>
 <xsl:variable name="controlField008-30-31" select="substring($controlField008,31,2)"/>

 <xsl:variable name="physicalDescription">
 <xsl:if test="$typeOf008='CF' and marc:controlfield[@tag=007][substring(.,12,1)='a']">
 digitoitu </xsl:if>
 <xsl:if test="$typeOf008='CF' and marc:controlfield[@tag=007][substring(.,12,1)='b']">
 digitoitu mikrotallenne </xsl:if>
 <xsl:if test="$typeOf008='CF' and marc:controlfield[@tag=007][substring(.,12,1)='d']">
 digitoitu aineisto </xsl:if>

 <xsl:variable name="check008-23">
 <xsl:if test="$typeOf008='BK' or $typeOf008='MU' or $typeOf008='CR' or $typeOf008='MX'">
 <xsl:value-of select="true()"></xsl:value-of>
 </xsl:if>
 </xsl:variable>
 <xsl:variable name="check008-29">
 <xsl:if test="$typeOf008='MP' or $typeOf008='VM'">
 <xsl:value-of select="true()"></xsl:value-of>
 </xsl:if>
 </xsl:variable>
 <xsl:choose>
 <xsl:when test="($check008-23 and $controlField008-23='f') or ($check008-29 and $controlField008-29='f')">
 pistekirjoitus </xsl:when>
 <xsl:when test="($controlField008-23=' ' and ($leader6='c' or $leader6='d')) or (($typeOf008='BK' or $typeOf008='CR') and ($controlField008-23=' ' or $controlField008='r'))">
 painotuote </xsl:when>
 <xsl:when test="$leader6 = 'm' or ($check008-23 and $controlField008-23='s') or ($check008-29 and $controlField008-29='s')">
 elektroninen </xsl:when>
 <xsl:when test="($check008-23 and $controlField008-23='b') or ($check008-29 and $controlField008-29='b')">
 mikrokortti </xsl:when>
 <xsl:when test="($check008-23 and $controlField008-23='a') or ($check008-29 and $controlField008-29='a')">
 mikrofilmi </xsl:when>
 <xsl:when test="($controlField008-23='d' and ($typeOf008='BK' or $typeOf008='CR'))">
 isotekstinen </xsl:when>
 </xsl:choose>

 <xsl:variable name="controlField007" select="marc:controlfield[@tag=007]"/>
 <xsl:variable name="cf007ss11" select="substring($controlField007,1,1)"/>
 <xsl:variable name="cf007ss21" select="substring($controlField007,2,1)"/>
 <xsl:if test="$cf007ss11 = 'c' and $cf007ss21 = 'b'">
 sirukasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'c' and $cf007ss21 = 'j'">
 levyke </xsl:if>
 <xsl:if test="$cf007ss11 = 'c' and $cf007ss21 = 'm'">
 magneetti-optinen levy </xsl:if>
 <xsl:if test="$cf007ss11 = 'c' and $cf007ss21 = 'r'">
 saatavana verkossa </xsl:if>
 <xsl:if test="$cf007ss11 = 'c' and $cf007ss21 = 'a'">
 nauhakasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'c' and $cf007ss21 = 'f'">
 nauhakasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'c' and $cf007ss21 = 'f'">
 nauhakela </xsl:if>

 <xsl:if test="$cf007ss11 = 'o' and $cf007ss21 = 'o'">
 moniviestin </xsl:if>

 <xsl:if test="$cf007ss11 = 'a' and $cf007ss21 = 'd'">
 kartasto, atlas </xsl:if>
 <xsl:if test="$cf007ss11 = 'a' and $cf007ss21 = 'g'">
 diagrammi </xsl:if>
 <xsl:if test="$cf007ss11 = 'a' and $cf007ss21 = 'j'">
 kartta </xsl:if>
 <xsl:if test="$cf007ss11 = 'a' and $cf007ss21 = 'q'">
 malli </xsl:if>
 <xsl:if test="$cf007ss11 = 'a' and $cf007ss21 = 'k'">
 profiili </xsl:if>
 <xsl:if test="$cf007ss11 = 'a' and $cf007ss21 = 'r'">
 kaukokartoituskuva </xsl:if>
 <xsl:if test="$cf007ss11 = 'a' and $cf007ss21 = 's'">
 leikkaus </xsl:if>
 <xsl:if test="$cf007ss11 = 'a' and $cf007ss21 = 'y'">
 näkymä </xsl:if>

 <xsl:if test="$cf007ss11 = 'h' and $cf007ss21 = 'a'">
 reikäkortti </xsl:if>
 <xsl:if test="$cf007ss11 = 'h' and $cf007ss21 = 'e'">
 mikrokortti </xsl:if>
 <xsl:if test="$cf007ss11 = 'h' and $cf007ss21 = 'f'">
 mikrokorttikasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'h' and $cf007ss21 = 'b'">
 mikrofilmikasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'h' and $cf007ss21 = 'c'">
 mikrofilmikasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'h' and $cf007ss21 = 'd'">
 mikrofilmikela </xsl:if>
 <xsl:if test="$cf007ss11 = 'h' and $cf007ss21 = 'g'">
 mikrokortti (läpinäkymätön) </xsl:if>
 <xsl:if test="$cf007ss11 = 'm' and $cf007ss21 = 'c'">
 filmisilmukkakasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'm' and $cf007ss21 = 'f'">
 filmikasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'm' and $cf007ss21 = 'r'">
 filmikela </xsl:if>
 <xsl:if test="$cf007ss11 = 'k' and $cf007ss21 = 'c'">
 kollaasi </xsl:if>
 <xsl:if test="$cf007ss11 = 'k' and $cf007ss21 = 'f'">
 fotomekaaninen painotuote </xsl:if>
 <xsl:if test="$cf007ss11 = 'k' and $cf007ss21 = 'g'">
 valokuvanegatiivi </xsl:if>
 <xsl:if test="$cf007ss11 = 'k' and $cf007ss21 = 'h'">
 valokuvatuloste </xsl:if>
 <xsl:if test="$cf007ss11 = 'k' and $cf007ss21 = 'j'">
 painotuote </xsl:if>
 <xsl:if test="$cf007ss11 = 'k' and $cf007ss21 = 'l'">
 tekninen piirustus </xsl:if>
 <xsl:if test="$cf007ss11 = 'g' and $cf007ss21 = 'd'">
 filminauha </xsl:if>
 <xsl:if test="$cf007ss11 = 'g' and $cf007ss21 = 'c'">
 rainakasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'g' and $cf007ss21 = 'o'">
 rainarulla </xsl:if>
 <xsl:if test="$cf007ss11 = 'g' and $cf007ss21 = 'f'">
 raina, määrittelemätön tyyppi </xsl:if>
 <xsl:if test="$cf007ss11 = 'g' and $cf007ss21 = 't'">
 kalvo </xsl:if>
 <xsl:if test="$cf007ss11 = 'r' and $cf007ss21 = 'r'">
 kaukokartoituskuva </xsl:if>
 <xsl:if test="$cf007ss11 = 's' and $cf007ss21 = 'e'">
 äänilieriö </xsl:if>
 <xsl:if test="$cf007ss11 = 's' and $cf007ss21 = 'q'">
 rulla </xsl:if>
 <xsl:if test="$cf007ss11 = 's' and $cf007ss21 = 'g'">
 äänikasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 's' and $cf007ss21 = 's'">
 äänikasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 's' and $cf007ss21 = 't'">
 ääninauhakela </xsl:if>
 <xsl:if test="$cf007ss11 = 's' and $cf007ss21 = 'i'">
 ääninauhafilmi </xsl:if>
 <xsl:if test="$cf007ss11 = 's' and $cf007ss21 = 'w'">
 lankaäänite </xsl:if>
 <xsl:if test="$cf007ss11 = 'f' and $cf007ss21 = 'c'">
 yhdistelmä </xsl:if>
 <xsl:if test="$cf007ss11 = 'f' and $cf007ss21 = 'b'">
 pistekirjoitus </xsl:if>
 <xsl:if test="$cf007ss11 = 'f' and $cf007ss21 = 'a'">
 kuu </xsl:if>
 <xsl:if test="$cf007ss11 = 'f' and $cf007ss21 = 'd'">
 kohokirjoitus, ei kirjoitusjärjestelmää </xsl:if>
 <xsl:if test="$cf007ss11 = 't' and $cf007ss21 = 'c'">
 pistekirjoitus </xsl:if>
 <xsl:if test="$cf007ss11 = 't' and $cf007ss21 = 'a'">
 tavanomainen painotuote </xsl:if>
 <xsl:if test="$cf007ss11 = 't' and $cf007ss21 = 'd'">
 teksti irtolehtikansiossa </xsl:if>
 <xsl:if test="$cf007ss11 = 'v' and $cf007ss21 = 'c'">
 videosilmukkakasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'v' and $cf007ss21 = 'f'">
 videokasetti </xsl:if>
 <xsl:if test="$cf007ss11 = 'v' and $cf007ss21 = 'r'">
 videokela </xsl:if>
<!--
 <xsl:for-each select="marc:datafield[@tag=856]/marc:subfield[@code='q'][string-length(.)>1]">
 <xsl:value-of select="."></xsl:value-of>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=300]">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abce</xsl:with-param>
 </xsl:call-template>
 </xsl:for-each>
-->
 </xsl:variable>

 <!-- Title Statement: Alternate Graphic Representation (MARC 880) -->
 <xsl:if test="$display880">
 <xsl:call-template name="m880Select">
 <xsl:with-param name="basetags">245</xsl:with-param>
 <xsl:with-param name="codes">abhfgknps</xsl:with-param>
 <xsl:with-param name="bibno"><xsl:value-of  select="$biblionumber"/></xsl:with-param>
 </xsl:call-template>
 </xsl:if>

 <a>
 <xsl:attribute name="href">
 <xsl:call-template name="buildBiblioDefaultViewURL">
 <xsl:with-param name="IntranetBiblioDefaultView">
 <xsl:value-of select="$IntranetBiblioDefaultView"/>
 </xsl:with-param>
 </xsl:call-template>
 <xsl:value-of select="str:encode-uri($biblionumber, true())"/>
 </xsl:attribute>
 <xsl:attribute name="class">nimeke</xsl:attribute>

 <xsl:if test="marc:datafield[@tag=245]">
 <xsl:for-each select="marc:datafield[@tag=245]">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">a</xsl:with-param>
 </xsl:call-template>
 <xsl:text> </xsl:text>
 <!-- 13381 add additional subfields-->
 <!-- bz 17625 adding subfields f and g -->
 <xsl:for-each select="marc:subfield[contains('bcfghknps', @code)]">
 <xsl:choose>
 <xsl:when test="@code='h'">
 <!-- 13381 Span class around subfield h so it can be suppressed via css -->
 <span class="title_medium"><xsl:apply-templates/> <xsl:text> </xsl:text> </span>
 </xsl:when>
 <xsl:when test="@code='c'">
 <!-- 13381 Span class around subfield c so it can be suppressed via css -->
 <span class="title_resp_stmt"><xsl:apply-templates/> <xsl:text> </xsl:text> </span>
 </xsl:when>
 <xsl:otherwise>
 <xsl:apply-templates/>
 <xsl:text> </xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:for-each>
 </xsl:for-each>
 </xsl:if>
 </a>

 <!-- Author Statement: Alternate Graphic Representation (MARC 880) -->
 <xsl:if test="$display880">
 <xsl:call-template name="m880Select">
 <xsl:with-param name="basetags">100,110,111,700,710,711</xsl:with-param>
 <xsl:with-param name="codes">abc</xsl:with-param>
 </xsl:call-template>
 </xsl:if>

 <xsl:choose>
 <xsl:when test="marc:datafield[@tag=100] or marc:datafield[@tag=110] or marc:datafield[@tag=111] or marc:datafield[@tag=700] or marc:datafield[@tag=710] or marc:datafield[@tag=711]">
 <p class="author"><span class="byAuthor">tekijä(t) </span>

 <xsl:for-each select="marc:datafield[(@tag=100 or @tag=700 or @tag=110 or @tag=710 or @tag=111 or @tag=711) and @ind1!='z']">
 <a>
 <xsl:choose>
 <xsl:when test="marc:subfield[@code=9] and $UseAuthoritiesForTracings='1'">
 <xsl:attribute name="href">
 <xsl:text>/cgi-bin/koha/catalogue/search.pl?q=an:</xsl:text>
 <xsl:value-of select="str:encode-uri(marc:subfield[@code=9], true())"/>
 <xsl:if test="$AuthorLinkSortBy!='default'">
 <xsl:text>&amp;sort_by=</xsl:text>
 <xsl:value-of select="$AuthorLinkSortBy"/>
 <xsl:text>_</xsl:text>
 <xsl:value-of select="$AuthorLinkSortOrder" />
 </xsl:if>
 </xsl:attribute>
 </xsl:when>
 <xsl:otherwise>
 <xsl:attribute name="href">
 <xsl:text>/cgi-bin/koha/catalogue/search.pl?q=au:"</xsl:text>
 <xsl:value-of select="str:encode-uri(marc:subfield[@code='a'], true())"/>
 <xsl:text>"</xsl:text>
 <xsl:if test="$AuthorLinkSortBy!='default'">
 <xsl:text>&amp;sort_by=</xsl:text>
 <xsl:value-of select="$AuthorLinkSortBy"/>
 <xsl:text>_</xsl:text>
 <xsl:value-of select="$AuthorLinkSortOrder" />
 </xsl:if>
 </xsl:attribute>
 </xsl:otherwise>
 </xsl:choose>
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">
 <xsl:choose>
 <!-- #13383 include subfield e for field 111 -->
 <xsl:when test="@tag=111 or @tag=711">aeq</xsl:when>
 <xsl:when test="@tag=110 or @tag=710">ab</xsl:when>
 <xsl:otherwise>abcjq</xsl:otherwise>
 </xsl:choose>
 </xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 <xsl:with-param name="punctuation">
 <xsl:text>:,;/ </xsl:text>
 </xsl:with-param>
 </xsl:call-template>
 <!-- Display title portion for 110 and 710 fields -->
 <xsl:if test="(@tag=110 or @tag=710) and boolean(marc:subfield[@code='c' or @code='d' or @code='n' or @code='t'])">
 <span class="titleportion">
 <xsl:choose>
 <xsl:when test="marc:subfield[@code='c' or @code='d' or @code='n'][not(marc:subfield[@code='t'])]"><xsl:text> </xsl:text></xsl:when>
 <xsl:otherwise><xsl:text>. </xsl:text></xsl:otherwise>
 </xsl:choose>
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">cdnt</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 </xsl:call-template>
 </span>
 </xsl:if>
 <!-- Display title portion for 111 and 711 fields -->
 <xsl:if test="(@tag=111 or @tag=711) and boolean(marc:subfield[@code='c' or @code='d' or @code='g' or @code='n' or @code='t'])">
 <span class="titleportion">
 <xsl:choose>
 <xsl:when test="marc:subfield[@code='c' or @code='d' or @code='g' or @code='n'][not(marc:subfield[@code='t'])]"><xsl:text> </xsl:text></xsl:when>
 <xsl:otherwise><xsl:text>. </xsl:text></xsl:otherwise>
 </xsl:choose>

 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">cdgnt</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 </xsl:call-template>
 </span>
 </xsl:if>
 <!-- Display dates for 100 and 700 fields -->
 <xsl:if test="(@tag=100 or @tag=700) and marc:subfield[@code='d']">
 <span class="authordates">
 <xsl:text>, </xsl:text>
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">d</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 </xsl:call-template>
 </span>
 </xsl:if>
 <!-- Display title portion for 100 and 700 fields -->
 <xsl:if test="@tag=700 and marc:subfield[@code='t']">
 <span class="titleportion">
 <xsl:text>. </xsl:text>
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">t</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 </xsl:call-template>
 </span>
 </xsl:if>
 </a>
 <!-- Display relators for 1XX and 7XX fields -->
 <xsl:if test="marc:subfield[@code='4' or @code='e'][not(parent::*[@tag=111])] or (self::*[@tag=111] and marc:subfield[@code='4' or @code='j'][. != ''])">
 <span class="relatorcode">
 <xsl:text> [</xsl:text>
 <xsl:choose>
 <xsl:when test="@tag=111 or @tag=711">
 <xsl:choose>
 <!-- Prefer j over 4 -->
 <xsl:when test="marc:subfield[@code='j']">
 <xsl:for-each select="marc:subfield[@code='j']">
 <xsl:value-of select="."/>
 <xsl:if test="position() != last()">, </xsl:if>
 </xsl:for-each>
 </xsl:when>
 <xsl:otherwise>
 <xsl:for-each select="marc:subfield[@code=4]">
 <xsl:value-of select="."/>
 <xsl:if test="position() != last()">, </xsl:if>
 </xsl:for-each>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:when>
 <!-- Prefer e over 4 -->
 <xsl:when test="marc:subfield[@code='e']">
 <xsl:for-each select="marc:subfield[@code='e'][not(@tag=111) or not(@tag=711)]">
 <xsl:value-of select="."/>
 <xsl:if test="position() != last()">, </xsl:if>
 </xsl:for-each>
 </xsl:when>
 <xsl:otherwise>
 <xsl:for-each select="marc:subfield[@code=4]">
 <xsl:value-of select="."/>
 <xsl:if test="position() != last()">, </xsl:if>
 </xsl:for-each>
 </xsl:otherwise>
 </xsl:choose>
 <xsl:text>]</xsl:text>
 </span>
 </xsl:if>
 <xsl:choose>
 <xsl:when test="position()=last()"><xsl:text>.</xsl:text></xsl:when><xsl:otherwise><span class="separator"><xsl:text> | </xsl:text></span></xsl:otherwise>
 </xsl:choose>
 </xsl:for-each>
 </p>
 </xsl:when>
 </xsl:choose>

<xsl:if test="$DisplayIconsXSLT!='0'">
 <span class="results_summary">
 <xsl:if test="$typeOf008!=''">
 <span class="results_material_type">
 <span class="label">Aineistotyyppi: </span>
 <xsl:choose>
 <xsl:when test="$leader19='a'"><img alt="kirja" class="materialtype" src="/intranet-tmpl/prog/img/famfamfam/silk/book_link.png" title="kirja" /> Moniosainen julkaisu</xsl:when>
 <xsl:when test="$leader6='a'">
 <xsl:choose>
 <xsl:when test="$leader7='c' or $leader7='d' or $leader7='m'"><img alt="kirja" class="materialtype mt_icon_BK" src="/intranet-tmpl/prog/img/famfamfam/silk/book.png" title="kirja" /> Teksti</xsl:when>
 <xsl:when test="$leader7='i' or $leader7='s'"><img alt="kausijulkaisu" class="materialtype mt_icon_CR" src="/intranet-tmpl/prog/img/famfamfam/silk/newspaper.png" title="kausijulkaisu" /> Jatkuva julkaisu</xsl:when>
 <xsl:when test="$leader7='a' or $leader7='b'"><img alt="artikkeli" class="materialtype mt_icon_AR" src="/intranet-tmpl/prog/img/famfamfam/silk/book_open.png" title="artikkeli" /> Artikkeli</xsl:when>
 </xsl:choose>
 </xsl:when>
 <xsl:when test="$leader6='t'"><img alt="kirja" class="materialtype mt_icon_BK" src="/intranet-tmpl/prog/img/famfamfam/silk/book.png" title="kirja" /> Teksti</xsl:when>
 <xsl:when test="$leader6='o'"><img alt="moniviestin" class="materialtype mt_icon_MX" src="/intranet-tmpl/prog/img/famfamfam/silk/report_disk.png" title="moniviestin" /> Moniviestin</xsl:when>
 <xsl:when test="$leader6='p'"><img alt="sekalainen aineisto" class="materialtype mt_icon_MX" src="/intranet-tmpl/prog/img/famfamfam/silk/report_disk.png" title="sekalainen aineisto" />Sekalaiset aineistot</xsl:when>
 <xsl:when test="$leader6='m'"><img alt="elektroninen aineisto" class="materialtype mt_icon_CF" src="/intranet-tmpl/prog/img/famfamfam/silk/computer_link.png" title="elektroninen aineisto" /> Elektroninen aineisto</xsl:when>
 <xsl:when test="$leader6='e' or $leader6='f'"><img alt="kartta" class="materialtype mt_icon_MP" src="/intranet-tmpl/prog/img/famfamfam/silk/map.png" title="kartta" /> Kartta</xsl:when>
 <xsl:when test="$leader6='g'"><img alt="Filmi" class="materialtype mt_icon_VM" src="/intranet-tmpl/prog/img/famfamfam/silk/film.png" /> Filmi</xsl:when>
 <xsl:when test="$leader6='k'"><img alt="Kuva" class="materialtype mt_icon_GR" src="/intranet-tmpl/prog/img/famfamfam/silk/picture.png" /> Kuva</xsl:when>
 <xsl:when test="$leader6='r'"><img alt="ID-tunnus" class="materialtype mt_icon_OB" src="/intranet-tmpl/prog/img/famfamfam/silk/object.png" title="ID-tunnus" /> ID-tunnus</xsl:when>
 <xsl:when test="$leader6='c' or $leader6='d'"><img alt="nuotti" class="materialtype mt_icon_PR" src="/intranet-tmpl/prog/img/famfamfam/silk/music.png" title="nuotti" /> Nuotti</xsl:when>
 <xsl:when test="$leader6='i'"><img alt="ääni" class="materialtype mt_icon_MU" src="/intranet-tmpl/prog/img/famfamfam/silk/sound.png" title="ääni" /> Ääni</xsl:when>
 <xsl:when test="$leader6='j'"><img alt="musiikki" class="materialtype mt_icon_MU" src="/intranet-tmpl/prog/img/famfamfam/silk/sound.png" title="musiikki" /> Musiikki</xsl:when>
 </xsl:choose>
 </span>
 </xsl:if>

 <xsl:if test="string-length(normalize-space($physicalDescription))">
 <span class="results_format">
 <span class="label">; Formaatti: </span><xsl:copy-of select="$physicalDescription"></xsl:copy-of>
 </span>
 </xsl:if>

 <xsl:if test="$controlField008-21 or $controlField008-22 or $controlField008-24 or $controlField008-26 or $controlField008-29 or $controlField008-34 or $controlField008-33 or $controlField008-30-31 or $controlField008-33">

 <xsl:if test="$typeOf008='CR'">
 <span class="results_typeofcontinueing">
 <xsl:if test="$controlField008-21 and $controlField008-21 !='|' and $controlField008-21 !=' '">
 <span class="label">; Jatkuvan julkaisun tyyppi: </span>
 </xsl:if>
 <xsl:choose>
 <xsl:when test="$controlField008-21='l'">
 irtolehtinen </xsl:when>
 <xsl:when test="$controlField008-21='m'">
 sarja </xsl:when>
 <xsl:when test="$controlField008-21='n'">
 sanomalehti </xsl:when>
 <xsl:when test="$controlField008-21='p'">
 aikakauslehti </xsl:when>
 </xsl:choose>
 </span>
 </xsl:if>
 <xsl:if test="$typeOf008='BK' or $typeOf008='CR'">
 <xsl:if test="contains($controlField008-24,'abcdefghijklmnopqrstvwxyz')">
 <span class="results_natureofcontents">
 <span class="label">; Sisältötyyppi: </span>
 <xsl:choose>
 <xsl:when test="contains($controlField008-24,'a')">
 tiivistelmä tai lyhennelmä </xsl:when>
 <xsl:when test="contains($controlField008-24,'b')">
 bibliografia </xsl:when>
 <xsl:when test="contains($controlField008-24,'c')">
 luettelo, kuvasto </xsl:when>
 <xsl:when test="contains($controlField008-24,'d')">
 sanakirja, sanasto </xsl:when>
 <xsl:when test="contains($controlField008-24,'e')">
 tietosanakirja </xsl:when>
 <xsl:when test="contains($controlField008-24,'f')">
 käsikirja </xsl:when>
 <xsl:when test="contains($controlField008-24,'g')">
 artikla, pykälä </xsl:when>
 <xsl:when test="contains($controlField008-24,'i')">
 hakemisto </xsl:when>
 <xsl:when test="contains($controlField008-24,'k')">
 diskografia </xsl:when>
 <xsl:when test="contains($controlField008-24,'l')">
 laki, säädös </xsl:when>
 <xsl:when test="contains($controlField008-24,'m')">
 väitöskirjat, tai muut opinnäytteet </xsl:when>
 <xsl:when test="contains($controlField008-24,'n')">
 kirjallisuuskatsaus </xsl:when>
 <xsl:when test="contains($controlField008-24,'o')">
 arvostelu </xsl:when>
 <xsl:when test="contains($controlField008-24,'p')">
 ohjelmoidut tekstit </xsl:when>
 <xsl:when test="contains($controlField008-24,'q')">
 filmografia </xsl:when>
 <xsl:when test="contains($controlField008-24,'r')">
 hakemisto </xsl:when>
 <xsl:when test="contains($controlField008-24,'s')">
 tilastot </xsl:when>
 <xsl:when test="contains($controlField008-24,'v')">
 oikeustapauskeskustelu </xsl:when>
 <xsl:when test="contains($controlField008-24,'w')">
 tuomioistuinpäätös </xsl:when>
 <xsl:when test="contains($controlField008-24,'z')">
 sopimus </xsl:when>
 </xsl:choose>
 <xsl:choose>
 <xsl:when test="$controlField008-29='1'">
 kokousjulkaisu </xsl:when>
 </xsl:choose>
 </span>
 </xsl:if>
 </xsl:if>
 <xsl:if test="$typeOf008='CF'">
 <span class="results_typeofcomp">
 <xsl:if test="$controlField008-26='a' or $controlField008-26='e' or $controlField008-26='f' or $controlField008-26='g'">
 <span class="label">; Elektronisen aineiston tyyppi: </span>
 </xsl:if>
 <xsl:choose>
 <xsl:when test="$controlField008-26='a'">
 numeerinen tieto </xsl:when>
 </xsl:choose>
 </span>
 </xsl:if>
 <xsl:if test="$typeOf008='BK'">
 <span class="results_contents_literary">
 <xsl:if test="(substring($controlField008,25,1)='j') or (substring($controlField008,25,1)='1') or ($controlField008-34='a' or $controlField008-34='b' or $controlField008-34='c' or $controlField008-34='d')">
 <span class="label">; Sisältötyyppi: </span>
 </xsl:if>
 <xsl:if test="substring($controlField008,25,1)='j'">
 patentti </xsl:if>
 <xsl:if test="substring($controlField008,31,1)='1'">
 juhlajulkaisu </xsl:if>

 <xsl:if test="$controlField008-33 and $controlField008-33!='|' and $controlField008-33!='u' and $controlField008-33!=' '">
 <span class="label">; Kirjallisuuslaji: </span>
 </xsl:if>
 <xsl:choose>
 <xsl:when test="$controlField008-33='0'">
 Tietokirjallisuus </xsl:when>
 <xsl:when test="$controlField008-33='1'">
 Kaunokirjallisuus </xsl:when>
 <xsl:when test="$controlField008-33='d'">
 Draamat </xsl:when>
 <xsl:when test="$controlField008-33='e'">
 Esseet </xsl:when>
 <xsl:when test="$controlField008-33='f'">
 Romaanit </xsl:when>
 <xsl:when test="$controlField008-33='h'">
 Huumori, satiirit jne. </xsl:when>
 <xsl:when test="$controlField008-33='i'">
 Kirjeet </xsl:when>
 <xsl:when test="$controlField008-33='j'">
 Novellit, kertomukset tai niiden kokoelmat </xsl:when>
 <xsl:when test="$controlField008-33='m'">
 Yhdistelmä </xsl:when>
 <xsl:when test="$controlField008-33='p'">
 Runo </xsl:when>
 <xsl:when test="$controlField008-33='s'">
 Puheet, esitelmät </xsl:when>
 </xsl:choose>
 </span>
 </xsl:if>
 <xsl:if test="$typeOf008='MU' and $controlField008-30-31 and $controlField008-30-31!='||' and $controlField008-30-31!='  '">
 <span class="results_literaryform">
 <span class="label">; Kirjallisuuslaji: </span> <!-- Literary text for sound recordings -->
 <xsl:if test="contains($controlField008-30-31,'b')">
 elämäkerta </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'c')">
 kokousjulkaisu </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'d')">
 draama </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'e')">
 essee </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'f')">
 kaunokirjallisuus </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'o')">
 kansantarina </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'h')">
 historiallinen </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'k')">
 huumori, satiiri </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'m')">
 muistelma </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'p')">
 runo </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'r')">
 harjoitus ilman musiikkia </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'g')">
 esittely, reportaasi </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'s')">
 ääni </xsl:if>
 <xsl:if test="contains($controlField008-30-31,'l')">
 puhe, esitelmä </xsl:if>
 </span>
 </xsl:if>
 <xsl:if test="$typeOf008='VM'">
 <span class="results_typeofvisual">
 <span class="label">; Visuaalisen aineiston tyyppi: </span>
 <xsl:choose>
 <xsl:when test="$controlField008-33='a'">
 taideteos, alkuperäinen </xsl:when>
 <xsl:when test="$controlField008-33='b'">
 moniviestin </xsl:when>
 <xsl:when test="$controlField008-33='c'">
 taidejäljennös </xsl:when>
 <xsl:when test="$controlField008-33='d'">
 dioraama </xsl:when>
 <xsl:when test="$controlField008-33='f'">
 raina </xsl:when>
 <xsl:when test="$controlField008-33='g'">
 peli </xsl:when>
 <xsl:when test="$controlField008-33='i'">
 kuva </xsl:when>
 <xsl:when test="$controlField008-33='k'">
 grafiikka </xsl:when>
 <xsl:when test="$controlField008-33='l'">
 tekninen piirustus </xsl:when>
 <xsl:when test="$controlField008-33='m'">
 elokuva </xsl:when>
 <xsl:when test="$controlField008-33='n'">
 kaavio </xsl:when>
 <xsl:when test="$controlField008-33='o'">
 sana- tai kuvakortti </xsl:when>
 <xsl:when test="$controlField008-33='p'">
 mikroskoopin preparaatti </xsl:when>
 <xsl:when test="$controlField008-33='q' or marc:controlfield[@tag=007][substring(text(),1,1)='a'][substring(text(),2,1)='q']">
 malli </xsl:when>
 <xsl:when test="$controlField008-33='r'">
 esine </xsl:when>
 <xsl:when test="$controlField008-33='s'">
 dia </xsl:when>
 <xsl:when test="$controlField008-33='t'">
 kalvo </xsl:when>
 <xsl:when test="$controlField008-33='v'">
 videotallenne </xsl:when>
 <xsl:when test="$controlField008-33='w'">
 lelu </xsl:when>
 </xsl:choose>
 </span>
 </xsl:if>
 </xsl:if>

 <xsl:if test="($typeOf008='BK' or $typeOf008='CF' or $typeOf008='MU' or $typeOf008='VM') and ($controlField008-22='a' or $controlField008-22='b' or $controlField008-22='c' or $controlField008-22='d' or $controlField008-22='e' or $controlField008-22='g' or $controlField008-22='j' or $controlField008-22='f')">
 <span class="results_audience">
 <span class="label">; Kohderyhmä: </span>
 <xsl:choose>
 <xsl:when test="$controlField008-22='a'">
 Esikouluikäiset; </xsl:when>
 <xsl:when test="$controlField008-22='b'">
 Ala-asteikäiset; </xsl:when>
 <xsl:when test="$controlField008-22='c'">
 Yläasteikäiset; </xsl:when>
 <xsl:when test="$controlField008-22='d'">
 Lukioikäiset ja vastaavat; </xsl:when>
 <xsl:when test="$controlField008-22='e'">
 Aikuinen; </xsl:when>
 <xsl:when test="$controlField008-22='g'">
 Yleinen; </xsl:when>
 <xsl:when test="$controlField008-22='j'">
 Lapset ja nuoret; </xsl:when>
 <xsl:when test="$controlField008-22='f'">
 Erityisryhmä; </xsl:when>
 </xsl:choose>
 </span>
 </xsl:if>
<xsl:text> </xsl:text> <!-- added blank space to fix font display problem, see Bug 3671 -->
 </span>
</xsl:if> <!-- DisplayIconsXSLT -->

 <xsl:call-template name="show-lang-041"/>

 <!-- Publisher Statement: Alternate Graphic Representation (MARC 880) -->
 <xsl:if test="$display880">
 <xsl:call-template name="m880Select">
 <xsl:with-param name="basetags">260</xsl:with-param>
 <xsl:with-param name="codes">abcg</xsl:with-param>
 <xsl:with-param name="class">results_summary publisher</xsl:with-param>
 <xsl:with-param name="label">Julkaisutiedot: </xsl:with-param>
 </xsl:call-template>
 </xsl:if>

 <xsl:call-template name="show-series">
 <xsl:with-param name="searchurl">/cgi-bin/koha/catalogue/search.pl</xsl:with-param>
 <xsl:with-param name="UseControlNumber" select="$UseControlNumber"/>
 <xsl:with-param name="UseAuthoritiesForTracings" select="$UseAuthoritiesForTracings"/>
 </xsl:call-template>

 <!-- Publisher info and RDA related info from tags 260, 264 -->
 <xsl:choose>
 <xsl:when test="marc:datafield[@tag=264]">
 <xsl:call-template name="showRDAtag264"/>
 </xsl:when>
 <xsl:when test="marc:datafield[@tag=260]">
 <span class="results_summary publisher"><span class="label">Julkaisutiedot: </span>
 <xsl:for-each select="marc:datafield[@tag=260]">
 <xsl:if test="marc:subfield[@code='a']">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">a</xsl:with-param>
 </xsl:call-template>
 </xsl:if>
 <xsl:text> </xsl:text>
 <xsl:if test="marc:subfield[@code='b']">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">b</xsl:with-param>
 </xsl:call-template>
 </xsl:if>
 <xsl:text> </xsl:text>
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">cg</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 </xsl:call-template>
 <xsl:choose><xsl:when test="position()=last()"><xsl:text></xsl:text></xsl:when><xsl:otherwise><xsl:text>; </xsl:text></xsl:otherwise></xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:when>
 </xsl:choose>

 <!-- Publisher or Distributor Number -->
 <xsl:if test="marc:datafield[@tag=028]">
 <span class="results_summary publisher_number ">
 <span class="label">Julkaisijan numero: </span>
 <xsl:for-each select="marc:datafield[@tag=028]">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abq</xsl:with-param>
 <xsl:with-param name="delimeter"><xsl:text> | </xsl:text></xsl:with-param>
 </xsl:call-template>
 </xsl:for-each>
 </span>
 </xsl:if>

 <!-- Dissertation note -->
 <xsl:if test="marc:datafield[@tag=502]">
 <span class="results_summary diss_note">
 <span class="label">Huomautus väitöskirjasta: </span>
 <xsl:for-each select="marc:datafield[@tag=502]">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdgo</xsl:with-param>
 </xsl:call-template>
 </xsl:for-each>
 <xsl:choose><xsl:when test="position()=last()"><xsl:text></xsl:text></xsl:when><xsl:otherwise><xsl:text> </xsl:text></xsl:otherwise></xsl:choose>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=300]">
 <span class="results_summary description"><span class="label">Kuvaus: </span>
 <xsl:for-each select="marc:datafield[@tag=300]">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcefg</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 </xsl:call-template>
 <xsl:choose><xsl:when test="position()=last()"><xsl:text>.</xsl:text></xsl:when><xsl:otherwise><xsl:text>; </xsl:text></xsl:otherwise></xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:call-template name="showISBNISSN"/>

 <xsl:if test="marc:datafield[@tag=250]">
 <span class="results_summary edition">
 <span class="label">Painos: </span>
 <xsl:for-each select="marc:datafield[@tag=250]">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">ab</xsl:with-param>
 </xsl:call-template>
 </xsl:for-each>
 </span>
 </xsl:if>

 <!-- Other Title Statement: Alternate Graphic Representation (MARC 880) -->
 <xsl:if test="$display880">
 <xsl:call-template name="m880Select">
 <xsl:with-param name="basetags">246</xsl:with-param>
 <xsl:with-param name="codes">ab</xsl:with-param>
 <xsl:with-param name="class">results_summary other_title</xsl:with-param>
 <xsl:with-param name="label">Muut nimekkeet: </xsl:with-param>
 </xsl:call-template>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=246]">
 <span class="results_summary other_title">
 <span class="label">Muut nimekkeet: </span>
 <xsl:for-each select="marc:datafield[@tag=246]">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">ab</xsl:with-param>
 </xsl:call-template>
 <!-- #13386 added separator | -->
 <xsl:choose><xsl:when test="position()=last()"><xsl:text>.</xsl:text></xsl:when><xsl:otherwise><span class="separator"><xsl:text> | </xsl:text></span></xsl:otherwise></xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:call-template name="host-item-entries">
 <xsl:with-param name="UseControlNumber" select="$UseControlNumber"/>
 </xsl:call-template>

 <xsl:if test="marc:datafield[@tag=856]">
 <xsl:if test="marc:datafield[@tag=856]/marc:subfield[@code='u']">
 <span class="results_summary online_resources">
 <span class="label">Linkit: </span>
 <xsl:for-each select="marc:datafield[@tag=856 and marc:subfield[@code='u']]">
 <xsl:variable name="SubqText"><xsl:value-of select="marc:subfield[@code='q']"/></xsl:variable>
 <a>
 <xsl:attribute name="href">
 <xsl:call-template name="AddMissingProtocol">
 <xsl:with-param name="resourceLocation" select="marc:subfield[@code='u']"/>
 <xsl:with-param name="indicator1" select="@ind1"/>
 <xsl:with-param name="accessMethod" select="marc:subfield[@code='2']"/>
 </xsl:call-template>
 <xsl:value-of select="marc:subfield[@code='u']"/>
 </xsl:attribute>
 <xsl:choose>
 <xsl:when test="($Show856uAsImage='Results' or $Show856uAsImage='Both') and (substring($SubqText,1,6)='image/' or $SubqText='img' or $SubqText='bmp' or $SubqText='cod' or $SubqText='gif' or $SubqText='ief' or $SubqText='jpe' or $SubqText='jpeg' or $SubqText='jpg' or $SubqText='jfif' or $SubqText='png' or $SubqText='svg' or $SubqText='tif' or $SubqText='tiff' or $SubqText='ras' or $SubqText='cmx' or $SubqText='ico' or $SubqText='pnm' or $SubqText='pbm' or $SubqText='pgm' or $SubqText='ppm' or $SubqText='rgb' or $SubqText='xbm' or $SubqText='xpm' or $SubqText='xwd')">
 <xsl:element name="img"><xsl:attribute name="src"><xsl:value-of select="marc:subfield[@code='u']"/></xsl:attribute><xsl:attribute name="alt"><xsl:value-of select="marc:subfield[@code='y']"/></xsl:attribute><xsl:attribute name="height">100</xsl:attribute></xsl:element><xsl:text></xsl:text>
 </xsl:when>
 <xsl:when test="marc:subfield[@code='y' or @code='3' or @code='z']">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">y3z</xsl:with-param>
 </xsl:call-template>
 </xsl:when>
 <xsl:when test="not(marc:subfield[@code='y']) and not(marc:subfield[@code='3']) and not(marc:subfield[@code='z'])">
 <xsl:choose>
 <xsl:when test="$URLLinkText!=''">
 <xsl:value-of select="$URLLinkText"/>
 </xsl:when>
 <xsl:otherwise>
 <xsl:text>Klikkaa tästä verkkosisältöön</xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:when>
 </xsl:choose>
 </a>
 <xsl:choose>
 <xsl:when test="position()=last()"><xsl:text> </xsl:text></xsl:when>
 <xsl:otherwise> | </xsl:otherwise>
 </xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>
 </xsl:if>

 <!-- Content Warning -->
 <xsl:variable name="ContentWarningField" select="marc:sysprefs/marc:syspref[@name='ContentWarningField']"/>
 <xsl:call-template name="content-warning">
 <xsl:with-param name="tag" select="$ContentWarningField" />
 </xsl:call-template>

 <!-- Indicate if record is suppressed in OPAC -->
 <xsl:if test="$OpacSuppression = 1">
 <xsl:if test="marc:datafield[@tag=942][marc:subfield[@code='n'] = '1']">
 <span class="results_summary suppressed_opac">Ei näytetä verkkokirjastossa</span>
 </xsl:if>
 </xsl:if>

</xsl:template>

 <xsl:template name="nameABCQ">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcq</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 <xsl:with-param name="punctuation">
 <xsl:text>:,;/ </xsl:text>
 </xsl:with-param>
 </xsl:call-template>
 </xsl:template>
 <xsl:template name="nameABCDN">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdn</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 <xsl:with-param name="punctuation">
 <xsl:text>:,;/ </xsl:text>
 </xsl:with-param>
 </xsl:call-template>
 </xsl:template>

 <xsl:template name="nameACDEQ">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">acdeq</xsl:with-param>
 </xsl:call-template>
 </xsl:template>

 <xsl:template name="nameDate">
 <xsl:for-each select="marc:subfield[@code='d']">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString" select="."/>
 </xsl:call-template>
 </xsl:for-each>
 </xsl:template>

 <xsl:template name="role">
 <xsl:for-each select="marc:subfield[@code='e']">
 <xsl:value-of select="."/>
 </xsl:for-each>
 <xsl:for-each select="marc:subfield[@code='4']">
 <xsl:value-of select="."/>
 </xsl:for-each>
 </xsl:template>

 <xsl:template name="specialSubfieldSelect">
 <xsl:param name="anyCodes"/>
 <xsl:param name="axis"/>
 <xsl:param name="beforeCodes"/>
 <xsl:param name="afterCodes"/>
 <xsl:variable name="str">
 <xsl:for-each select="marc:subfield">
 <xsl:if test="contains($anyCodes, @code) or (contains($beforeCodes,@code) and following-sibling::marc:subfield[@code=$axis]) or (contains($afterCodes,@code) and preceding-sibling::marc:subfield[@code=$axis])">
 <xsl:value-of select="text()"/>
 <xsl:text> </xsl:text>
 </xsl:if>
 </xsl:for-each>
 </xsl:variable>
 <xsl:value-of select="substring($str,1,string-length($str)-1)"/>
 </xsl:template>

 <xsl:template name="subtitle">
 <xsl:if test="marc:subfield[@code='b']">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:value-of select="marc:subfield[@code='b']"/>

 <!--<xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">b</xsl:with-param>
 </xsl:call-template>-->
 </xsl:with-param>
 </xsl:call-template>
 </xsl:if>
 </xsl:template>



 <xsl:template name="chopBrackets">
 <xsl:param name="chopString"></xsl:param>
 <xsl:variable name="string">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString" select="$chopString"></xsl:with-param>
 </xsl:call-template>
 </xsl:variable>
 <xsl:if test="substring($string, 1,1)='['">
 <xsl:value-of select="substring($string,2, string-length($string)-2)"></xsl:value-of>
 </xsl:if>
 <xsl:if test="substring($string, 1,1)!='['">
 <xsl:value-of select="$string"></xsl:value-of>
 </xsl:if>
 </xsl:template>

</xsl:stylesheet>
