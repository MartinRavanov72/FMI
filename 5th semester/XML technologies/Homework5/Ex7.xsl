<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:template match="/">
        <html>
            <body>
                <ul>
                    <xsl:for-each select="//cd">
                        <xsl:call-template name="year">
                            <xsl:with-param name="yearName" select="year/text()"/>
                        </xsl:call-template>
                    </xsl:for-each>
                </ul>
                <ul>
                    <xsl:for-each select="//cd">
                        <xsl:call-template name="title">
                            <xsl:with-param name="titleName" select="title/text()"/>
                        </xsl:call-template>
                    </xsl:for-each>
                </ul>
                <ul>
                    <xsl:for-each select="//cd">
                        <xsl:call-template name="artist">
                            <xsl:with-param name="artistName" select="artist/text()"/>
                        </xsl:call-template>
                    </xsl:for-each>
                </ul>
            </body>
        </html>
    </xsl:template>
    <xsl:template name="year">
        <xsl:param name="yearName"/>
        <li>
            <xsl:value-of select="$yearName"/>
        </li>
    </xsl:template>
    <xsl:template name="title">
        <xsl:param name="titleName"/>
        <li>
            <xsl:value-of select="$titleName"/>
        </li>
    </xsl:template>
    <xsl:template name="artist">
        <xsl:param name="artistName"/>
        <li>
            <xsl:value-of select="$artistName"/>
        </li>
    </xsl:template>
</xsl:stylesheet>

<!-- Подобно на зад. 6, но тук викаме темплейтите с параметър - xsl:with-param и подаваме като стойност на параметъра текста на съответния елемент - year, title или artist.
По-долу в шаблоните, използваме стойността на параметъра, като го добавяме в елемент li-->