<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format" >
    <xsl:template match="/">
        <catalog>
            <xsl:for-each select="//cd">
               <xsl:element name="cd">      
                  <xsl:element name="title">      
                     <xsl:value-of select="title/text()"/>
                  </xsl:element>
                  <xsl:element name="tracklist">
                     <xsl:attribute name="num">
                        <xsl:value-of select="tracklist/@num"/>
                     </xsl:attribute>
                     <xsl:for-each select="//track">
                        <xsl:element name="track">
                           <xsl:attribute name="length">
                              <xsl:value-of select="@length"/>
                           </xsl:attribute>
                           <xsl:value-of select="text()"/>  
                        </xsl:element>
                     </xsl:for-each>
                  </xsl:element>
               </xsl:element>      
            </xsl:for-each>
         </catalog>
    </xsl:template>
</xsl:stylesheet>

<!-- Ефектът е същия като в зад. 8, но използваме xsl:attribute и xsl:element (пресъздаваме цялата структура с всичките елементи и техните атрибути на елемента tracklist (атрибут num) - track (атрибут length))  -->