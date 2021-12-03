<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:template match="/">
        <html>
            <body>
                <ul>
                    <xsl:for-each select="//track">
                        <xsl:if test="@length='4:04'">
                            <li>
                                <xsl:value-of select="text()" />
                            </li>
                        </xsl:if>
                    </xsl:for-each>
                </ul>
                <ul>
                    <xsl:for-each select="//track">
                        <xsl:if test="string-length(.) &lt; 15">
                            <li>
                                <xsl:value-of select="text()" />
                            </li>
                            <li>
                                <xsl:value-of select="string-length(.)" />
                            </li>
                        </xsl:if>
                    </xsl:for-each>
                </ul>
                <ul>
                    <xsl:for-each select="//track">
                        <xsl:if test="position() mod 2 = 0">
                            <li>
                                <xsl:value-of select="text()" />
                            </li>
                        </xsl:if>
                    </xsl:for-each>
                </ul>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>

<!-- Имаме проста html структура като за всяко едно от 3те подусловия имаме ul
1. за всеки елемент track (с xsl:for-each), проверяваме дали атрибута му с има length е равен на '4:04' (с xsl:if) и ако е така, добавяме елемент li със стойността на елемента track
2. за всеки елемент track (с xsl:for-each), проверяваме дали дължината му е по-малка от 15 (използваме &lt;, защото < не е позволен символ) (с xsl:if) и ако е така, добавяме 2 елемента li - със стойността на елемента track и дължината и
3. за всеки елемент track (с xsl:for-each), проверяваме дали позицията му се дели на 2 с остатък 0 (четна) и ако е така, добавяме елемент li със стойност стойността на елемента track
-->