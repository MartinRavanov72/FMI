<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:template match="/">
        <xsl:param name="enumerated" select="'Enumerated:'" />
        <html>
            <body>
                <ul>
                    <xsl:value-of select="$enumerated" />
                    <xsl:for-each select="//track">
                        <xsl:sort select="." />
                        <li>
                            <xsl:value-of select="text()" />_<xsl:number value="position()" />
                        </li>
                    </xsl:for-each>
                </ul>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>

<!-- аналогично на 4. зад, но тук задаваме параметъра с xsl:param с име enumerated и стойност Enumerated: (чрез select="''") по-нагоре в документа. Използваме го пак с $ + името на параметъра-->