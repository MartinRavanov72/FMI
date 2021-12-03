<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:template match="/">
        <html>
            <body>
                <xsl:apply-templates select="catalog" />
            </body>
        </html>
    </xsl:template>
    <xsl:template match="cd">
        <ul>
            <li>
                <xsl:apply-templates select="title" />
            </li>
            <xsl:for-each select="title/@*">
                <p>
                    Attribute name: <xsl:value-of select="name()" />; Attribute value: <xsl:value-of select="." />
                </p>
            </xsl:for-each>
        </ul>
        <ul>
            <li>
                <xsl:apply-templates select="year" />
            </li>
            <xsl:for-each select="year/@*">
                <p>
                    Attribute name: <xsl:value-of select="name()" />; Attribute value: <xsl:value-of select="." />
                </p>
            </xsl:for-each>
        </ul>
        <ul>
            <xsl:apply-templates select="//track" />
        </ul>
    </xsl:template>
    <xsl:template match="track">
        <li>
            <xsl:apply-templates select="text()" />
            <xsl:for-each select="@*">
                <p>
                    Attribute name: <xsl:value-of select="name()" />; Attribute value: <xsl:value-of select="." />
                </p>
            </xsl:for-each>
        </li>
    </xsl:template>
</xsl:stylesheet>

<!-- Започваме с простa html структура и изивкваме xsl:apply-templates с catalog.
Имаме шаблон за всяко cd, където за title и year имаме ul с li - стойността на title или year съответно. За всеки техен атрибут имаме елемент p - името на атрибута и стойността му (ако съществуват такива)
Имаме и ul, в който имаме xsl:apply-templates с track. Долу имаме шаблон за track, който съдържа li с текстовата стойност на елемента track и както имаме по-горе: атрибутите му  -->