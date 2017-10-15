
#include "nesdev.h"

/* Zero-page Globals (commonly used vars) */
#pragma bss-name(push, "ZEROPAGE")
/* Often used vars */
u8 i;               /* Iterator */
u8 j;               /* Iterator */
u8 frame;           /* Frame counter */

/* Input state */
u8 pad1;

/* Current sprite oam offset */
u8 oam_ptr;

/* Brightness values */
u8 bg_bright = 4;
u8 spr_bright = 4;
u8 flash_time = 0;

/* Scrolls */
s8 scroll_x = 0;
s8 scroll_y = 0;
u8 shake_time = 0;
u8 shake_force = 10;

/* Our sprite data */
metasprite_t player;
sprite_t stick;

/* Colliders */
rect_t world_bounds;
rect_t player_col;
rect_t stick_col;
u8 touching;

/* Some fun gameplay stuff */
u8 player_speed;
digits_t points;
#pragma bss-name(pop)

/* Palettes */
const u8 BG_PALETTES[16] =
{
	0x0f,0x21,0x10,0x30,
	0x0f,0x14,0x21,0x31,
	0x0f,0x29,0x16,0x26,
	0x0f,0x09,0x19,0x29
};

const u8 BG_PALETTES_FLASH[4] =
{
	0x30, 0x00, 0x10, 0x20
};

const u8 SPRITE_PALETTES[16] =
{
	0x0f,0x17,0x27,0x37,
	0x0f,0x11,0x21,0x31,
	0x0f,0x15,0x25,0x35,
	0x0f,0x19,0x29,0x39
};

/* Meta sprite buffer format */
/* X-offset | Y-offset | TILE_INDEX | Attribute */
const u8 META_PersonSprite[] =
{
	0, 0, 0x60, 0,
	0, 8, 0x70, 0,
	METASPR_EOB /* End of buffer */
};

/* Points text buffer */
#define TEXTBUFSIZE_Points 3+8+1
#define TEXTBUF_Index(i) (i+3)
u8 TEXTBUF_Points[TEXTBUFSIZE_Points];

const u8 TEXTBUFINIT_Points[TEXTBUFSIZE_Points] =
{
	MSB(NTADR_A(23, 1))|NT_UPD_HORZ, 
	LSB(NTADR_A(23, 1)), 
	8, 
	ASCII_NUMBERSPOSITION,
	ASCII_NUMBERSPOSITION,
	ASCII_NUMBERSPOSITION,
	ASCII_NUMBERSPOSITION,
	ASCII_NUMBERSPOSITION,
	ASCII_NUMBERSPOSITION,
	ASCII_NUMBERSPOSITION,
	ASCII_NUMBERSPOSITION,
	NT_UPD_EOF
};

#define INITIAL_SPEED 2

#define SPRITE_STICK 0x61