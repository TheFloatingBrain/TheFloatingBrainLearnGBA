#include <gba.h>
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <stdio.h>
#include <type_traits>

static const char DEFUALT_MODE_CONSTANT = MODE_3 | BG2_ON;

extern char currentMode;

int main()
{
    irqInit();
    irqEnable( IRQ_VBLANK );
    SetMode( currentMode );
    const auto MAX_COLOR_CONSTANT = 0xFF00;
    typename std::remove_const< decltype( MAX_COLOR_CONSTANT ) >::type currentColor = 0x0000;
    for( size_t i = 0; i < ( SCREEN_WIDTH * SCREEN_HEIGHT ); ++i )
        ( ( u16* ) VRAM )[ i ] = currentColor > MAX_COLOR_CONSTANT ? 0x0000 : currentColor++;
    while( true )
        SystemCall( 5 );
    return 0;
}


char currentMode = DEFAULT_MODE_CONSTANT;