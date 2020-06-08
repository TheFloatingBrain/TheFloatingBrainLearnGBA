import trick
import strformat
import strutils

#proc toString( fromm: seq[ GfxColor ] ): string =
#    result = newStringOfCap( len( fromm ) )
#    for color in fromm:
#        add( result, color )


var conf = GfxInfo(
        pal: @[clrEmpty],   # initial palette
        bpp: gfx4bpp,       # bit depth
        layout: gfxTiles,   # arrange into 8x8 tiles
)

let data = pngToBin( "../assets/Cross.png", conf, buildPal = true )


let imgStringLit = makeCString( data )
let palStringLit = makeCString( conf.pal.join( "" ) )

writeFile("gfxdata.c", fmt"""
        const char* CrossImage = {imgStringLit};
        const char* CrossPalette = {palStringLit};
        """)


