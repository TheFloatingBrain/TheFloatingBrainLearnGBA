#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <keypad.hpp>
#include <gba.hpp>
#include "mgba.h"
extern "C" {
	#include "Cross.h"
}

#define MGBA_DEBUG_MACRO 1
#ifdef MGBA_DEBUG_MACRO
	#define DEBUG_CONSOLE_INITIALIZE_MACRO mgba_console_open
	#define dprintf( MESSAGE_PARAMETER, ... ) mgba_printf( MGBA_LOG_INFO, MESSAGE_PARAMETER, ##__VA_ARGS__ )
#else
	#ifndef OTHER_DEBUG_MACRO
		#define DEBUG_CONSOLE_INITIALIZE_MACRO
		#define dprintf( NO_PRINT_DEFINED, ... )
	#endif
#endif

typedef gba::color MODE_2_LINE_TYPE[ 240 ];

int main()
{
	while ( true ) {
		VBlankIntrWait();
	}
}


