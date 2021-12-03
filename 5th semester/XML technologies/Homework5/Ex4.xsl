<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:template match="/">
        <html>
            <body>
                <ul>
                    <xsl:variable name="enumerated">Enumerated:</xsl:variable>
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

<!-- чрез xsl:variable с име enumerated и стойност Enumerated: създаваме променлива, която използваме и взимаме стойността ѝ ($ + името на променливата) чрез xsl:value-of  -->