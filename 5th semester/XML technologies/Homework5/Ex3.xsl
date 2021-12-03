<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:template match="/">
        <html>
            <body>
                <ul>
                    <xsl:for-each select="//track">
                        <xsl:sort select="." />
                        <li>
                            <xsl:value-of select="text()" />
                        </li>
                    </xsl:for-each>
                </ul>
                <ul>
                    <xsl:for-each select="//track">
                        <xsl:sort select="." order="descending" />
                        <li>
                            <xsl:value-of select="text()" />
                        </li>
                    </xsl:for-each>
                </ul>
                <ul>
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

<!-- 1. за всеки елемент track, ги сортираме (чрез xsl:sort) и добавяме стойността му в елемент li 
2. в xsl:sort слагаме order="descending" и така сортирането е в намаляващ ред
3. аналогично на 1., но добавяме и _ и позицията на елемента (1......n) чрез xsl:number   -->