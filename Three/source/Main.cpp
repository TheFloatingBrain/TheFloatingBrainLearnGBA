
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <gba_sprites.h>
#include <stdio.h>
#include <stdlib.h>
#include "mgba.h"
#include <type_traits>
#include <stdio.h>
#include <string.h>
#include "CrossPillow.h"

//#include <keypad.hpp>
//#include <gba.hpp>
#include "mgba.h"

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

//typedef gba::color MODE_2_LINE_TYPE[ 240 ];
/*

const u16 cross_palette[] = {
        0x7fff,0x7680,0x7773,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,0x0,0x0,
};

const u16 cross[] = {
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xa200,0xe8,0xe8a2,0xd999,0xffea,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xa200,0xe8,0xe8a2,0xd999,0xffea,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xa200,
        0xe8,0xe8a2,0xd999,0xffea,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xff,0xe8a2,
        0xa200,0xe8,0xe8a2,0xa200,0xe8,0xe8a2,0xa200,0xe8,0xe8a2,0xa200,
        0x99e8,0xead9,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xff,0xe8a2,0xa200,0xe8,0xe8a2,0xa200,0xe8,0xe8a2,
        0xa200,0xe8,0xe8a2,0xa200,0x99e8,0xead9,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xa200,0xe8,0xe8a2,0xd999,0xffea,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xa200,0xe8,0xe8a2,0xd999,0xffea,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xa200,
        0xe8,0xe8a2,0xd999,0xffea,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xa200,0xe8,0xe8a2,0xd999,0xffea,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xa200,0xe8,0xe8a2,
        0xd999,0xffea,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xa200,0xe8,0xe8a2,0xd999,0xffea,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xa200,0xe8,0xe8a2,0xd999,0xffea,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,
        0xffff,0xffff,0xffff,0xffff,
};
*/

static int DEFUALT_MODE_CONSTANT = MODE_3 | BG2_ON;

extern int currentMode;

void Start();

int main()
{
	const auto MAX_COLOR_CONSTANT = 0xFF00;
	auto currentColor = 0x0000;
	Start();
	DEBUG_CONSOLE_INITIALIZE_MACRO();
	for( size_t i = 0; i < 256; ++i )
		*( ( volatile uint8_t* ) 0x5000200 + i ) = cross_palette[ i ];

	for( size_t i = 0; i < 384; ++i )
		*( ( volatile uint8_t* ) 0x6014000 + i ) = cross[ i ];
	*( ( volatile uint8_t* ) 0x7000000 ) = OBJ_16_COLOR | OBJ_SQUARE | ( ( s16 ) 0xF );
	*( ( volatile uint8_t* ) 0x7000000 + 1 ) = ( uint8_t ) OBJ_SIZE( 16 ) | ( ( s16 ) 0xF );
	*( ( volatile uint8_t* ) 0x7000000 + 2 ) = 0;
	
//	while( true )
	//{
		dprintf( "Hello GBA!\n" );
		//for( size_t i = 0; i < ( SCREEN_WIDTH * SCREEN_HEIGHT ); ( ( u16* ) VRAM )[ i++ ] = 
		//		( ( currentColor == MAX_COLOR_CONSTANT ) ? ( currentColor = 0x0000 ) : currentColor++ ) );
		//VBlankIntrWait();
	//}
}

int currentMode = DEFUALT_MODE_CONSTANT;

void Start()
{
	irqInit();
	irqEnable(IRQ_VBLANK);
	//consoleDemoInit();
	SetMode( currentMode );
}
