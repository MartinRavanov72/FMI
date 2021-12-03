<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format" >
   <xsl:template match="/">
        <catalog>
            <xsl:for-each select="//cd">
                <cd>
                    <title>
                        <xsl:value-of select="title/text()"/>
                    </title>
                    <xsl:copy-of select="tracklist" />
                </cd>
            </xsl:for-each>
        </catalog>
   </xsl:template>
</xsl:stylesheet>

<!-- генерираме xml документ с root елемент catalog, като за всеки елемент cd, имаме xml елемент cd, с под-елемент title със стойността на елемента title. Друг под-елемент на cd е 
целият елемент tracklist (и неговите под-елементи) (чрез xsl:copy-of) -->