
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>
#include <mbv2.h>
#include <type_traits>

static int DEFUALT_MODE_CONSTANT = MODE_3 | BG2_ON;

extern int currentMode;

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void)
{
//---------------------------------------------------------------------------------


	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	// since the default dispatcher handles the bios flags no vblank handler
	// is required
	irqInit();
	irqEnable(IRQ_VBLANK);
	consoleDemoInit();
	SetMode( currentMode );
	const auto MAX_COLOR_CONSTANT = 0xFF00;
	auto currentColor = 0x0000;

	while( true )
	{
		for( size_t i = 0; i < ( SCREEN_WIDTH * SCREEN_HEIGHT ); ( ( u16* ) VRAM )[ i++ ] = 
				( ( currentColor == MAX_COLOR_CONSTANT ) ? ( currentColor = 0x0000 ) : currentColor++ ) );
		VBlankIntrWait();
	}
}

int currentMode = DEFUALT_MODE_CONSTANT;
