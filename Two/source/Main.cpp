
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>
#include "mgba.h"
#include <type_traits>
#include <stdio.h>
#include <string.h>

#define MGBA_DEBUG_MACRO 1
//#define OTHER_DEBUG_MACRO 0
#ifdef MGBA_DEBUG_MACRO
	#define DEBUG_CONSOLE_INITIALIZE_MACRO mgba_console_open
	#define dprintf( MESSAGE_PARAMETER, ... ) mgba_printf( MGBA_LOG_INFO, MESSAGE_PARAMETER, ##__VA_ARGS__ )
#else
	#ifndef OTHER_DEBUG_MACRO
		#define DEBUG_CONSOLE_INITIALIZE_MACRO
		#define dprintf( NO_PRINT_DEFINED, ... )
	#endif
#endif

static int DEFUALT_MODE_CONSTANT = MODE_3 | BG2_ON;

extern int currentMode;

void Start();

int main()
{
	const auto MAX_COLOR_CONSTANT = 0xFF00;
	auto currentColor = 0x0000;
	Start();
	DEBUG_CONSOLE_INITIALIZE_MACRO();
	while( true )
	{
		dprintf( "Hello GBA!\n" );
		for( size_t i = 0; i < ( SCREEN_WIDTH * SCREEN_HEIGHT ); ( ( u16* ) VRAM )[ i++ ] = 
				( ( currentColor == MAX_COLOR_CONSTANT ) ? ( currentColor = 0x0000 ) : currentColor++ ) );
		VBlankIntrWait();
	}
}

int currentMode = DEFUALT_MODE_CONSTANT;

void Start()
{
	irqInit();
	irqEnable(IRQ_VBLANK);
	//consoleDemoInit();
	SetMode( currentMode );
}
