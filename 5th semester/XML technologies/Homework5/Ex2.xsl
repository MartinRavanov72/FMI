<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:template match="/">
        <html>
            <body>
                <ul>
                    <xsl:for-each select="//track">
                        <li>
                            <xsl:choose>
                                <xsl:when test="string-length(.) &gt; 15">
                                    A big string: <xsl:value-of select="text()" />
                                </xsl:when>
                                <xsl:when test="string-length(.) &lt; 15">
                                    A small string: <xsl:value-of select="text()" />
                                </xsl:when>
                                <xsl:otherwise>
                                    A medium string: <xsl:value-of select="text()" />
                                </xsl:otherwise>
                            </xsl:choose>
                        </li>
                    </xsl:for-each>
                </ul>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>

<!--  за всеки елемент track, имаме елемент li, в който проверяваме чрез xsl:choose дали дължината му е повече от 15(имаме стойност на li - big string и стойността). Ако дължината е по-малко от 15(имаме стойност на li - small string и стойността),
а ако не отговаря на горните условия - имаме стойност на li - medium string и стойността --> 