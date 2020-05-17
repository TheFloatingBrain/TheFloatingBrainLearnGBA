#include <gba.h>
#include <stdio.h>
#include <type_traits>

static int DEFUALT_MODE_CONSTANT = MODE_3 | BG2_ON;

extern int currentMode;

int main( void )
{
    irqInit();
    irqEnable( IRQ_VBLANK );
    SetMode( currentMode );
    const auto MAX_COLOR_CONSTANT = 0xFF00;
    typename std::remove_const< decltype( MAX_COLOR_CONSTANT ) >::type currentColor = 0x0000;
    for( size_t i = 0; i < ( SCREEN_WIDTH * SCREEN_HEIGHT ); ++i )
        ( ( u16* ) VRAM )[ i ] = ( ( currentColor > MAX_COLOR_CONSTANT ) ? ( currentColor = 0x0000 ) : currentColor++ );
    while( true )
        SystemCall( 5 );
    return 0;
}


int currentMode = DEFUALT_MODE_CONSTANT;
