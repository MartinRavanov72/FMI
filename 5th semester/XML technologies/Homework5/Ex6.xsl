<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:template match="/">
        <html>
            <body>
                <ul>
                    <xsl:for-each select="//cd">
                        <xsl:call-template name="year" />
                    </xsl:for-each>
                </ul>
                <ul>
                    <xsl:for-each select="//cd">
                        <xsl:call-template name="title" />
                    </xsl:for-each>
                </ul>
                <ul>
                    <xsl:for-each select="//cd">
                        <xsl:call-template name="artist" />
                    </xsl:for-each>
                </ul>
            </body>
        </html>
    </xsl:template>
    <xsl:template name="year">
        <li>
            <xsl:value-of select="year/text()" />
        </li>
    </xsl:template>
    <xsl:template name="title">
        <li>
            <xsl:value-of select="title/text()" />
        </li>
    </xsl:template>
    <xsl:template name="artist">
        <li>
            <xsl:value-of select="artist/text()" />
        </li>
    </xsl:template>
</xsl:stylesheet>

<!-- чрез xsl:template задаваме шаблон с име (в нашия случай year, title, artist аналогично). Вътре добавяме елемент li със стойността на конкретния елемент.
По-нагоре в документа за всяко условие (1, 2, 3) имаме ul, където за всеки елемент year, title или artist, викаме шаблона със съответното име (чрез xsl:call-template) -->