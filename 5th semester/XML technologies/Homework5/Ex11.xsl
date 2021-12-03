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
            <xsl:apply-templates select="//track" mode="withoutAttributes" />
        </ul>
        <ul>
            <xsl:apply-templates select="//track" mode="withAttributes" />
        </ul>
    </xsl:template>
    <xsl:template match="track" mode="withoutAttributes">
        <li>
            <xsl:apply-templates select="text()" />
        </li>
    </xsl:template>
    <xsl:template match="track" mode="withAttributes">
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

<!-- Като зад. 10, но имаме изивкване на xsl:apply-templates с mode="withoutAttributes", което извиква шаблона по-долу с конкретния mode.  -->