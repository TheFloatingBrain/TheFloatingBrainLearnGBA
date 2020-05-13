#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <stdio.h>

static const auto DEFUALT_MODE_CONSTANT = MODE_3 | BG2_ON;

extern auto currentMode = DEFUALT_MODE_CONSTANT;

int main()
{
    irqInit();
    irqEnable( IRQ_VBLANK );
    SetMode( currentMode );
    for( size_t i = 0; i < ( SCREEN_WIDTH * SCREEN_HEIGHT ); ++i )
        ( ( u16* ) VRAM )[ i ] = 0xA600;
    while( true )
        SystemCall( 5 );
}
