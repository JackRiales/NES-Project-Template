#ifndef _NESDEV_H_
/*------------------------------------
-- Fancy that, a CC65 NES-Dev helping header!
-- Provides a lot of constants needed
-- to simplify the whole NES development
-- process. This thing is REALLY complex,
-- after all! Please enjoy.

-- * Your boy, Jack
-------------------------------------*/
#define _NESDEV_H_
#include <stdint.h>

// Funner to type typenames
typedef int16_t   s16;
typedef uint16_t  u16;
typedef int8_t    s8;
typedef uint8_t   u8;
typedef uintptr_t uptr;

// 8-bit integer limits
#define U16_MAX   65535
#define S16_MAX   32767
#define S16_MIN  -32767
#define UCHAR_MAX 255
#define U8_MAX    255
#define CHAR_MAX  128
#define S8_MAX    128
#define CHAR_MIN -128
#define S8_MIN   -128

// Array limit in bytes
#define ARRAY_BYTE_MAX 256

// PPU Addresses
#define PPU_CTRL    *((u8*)0x2000)
#define PPU_MASK    *((u8*)0x2001)
#define PPU_STATUS  *((u8*)0x2002)
#define PPU_SCROLL  *((u8*)0x2005)
#define PPU_ADDRESS *((u8*)0x2006)
#define PPU_DATA    *((u8*)0x2007)

// OAM Addresses
#define OAM_ADDRESS *((u8*)0x2003)
#define OAM_DMA     *((u8*)0x4014)

// PPU_CTRL flags
// see http://wiki.nesdev.com/w/index.php/PPU_registers#Controller_.28.242000.29_.3E_write
#define PPUCTRL_NAMETABLE_0 0x00 // use nametable 0
#define PPUCTRL_NAMETABLE_1 0x01 // use nametable 1
#define PPUCTRL_NAMETABLE_2 0x02 // use nametable 2
#define PPUCTRL_NAMETABLE_3 0x03 // use nametable 3
#define PPUCTRL_INC_1_HORIZ 0x00 // PPU_DATA increments 1 horizontally
#define PPUCTRL_INC_32_VERT 0x04 // PPU_DATA increments 32 vertically
#define PPUCTRL_SPATTERN_0  0x00 // sprite pattern table 0
#define PPUCTRL_SPATTERN_1  0x08 // sprite pattern table 1
#define PPUCTRL_BPATTERN_0  0x00 // background pattern table 0
#define PPUCTRL_BPATTERN_1  0x10 // background pattern table 1
#define PPUCTRL_SSIZE_8x8   0x00 // 8x8 sprite size
#define PPUCTRL_SSIZE_16x16 0x00 // 16x16 sprite size
#define PPUCTRL_NMI_OFF     0x00 // disable NMIs
#define PPUCTRL_NMI_ON      0x80 // enable NMIs

// PPU_MASK flags
// see http://wiki.nesdev.com/w/index.php/PPU_registers#Mask_.28.242001.29_.3E_write
#define PPUMASK_COLOR    0x00
#define PPUMASK_GRAY     0x01
#define PPUMASK_L8_BHIDE 0x00
#define PPUMASK_L8_BSHOW 0x02
#define PPUMASK_L8_SHIDE 0x00
#define PPUMASK_L8_SSHOW 0x04
#define PPUMASK_BHIDE    0x00
#define PPUMASK_BSHOW    0x08
#define PPUMASK_SHIDE    0x00
#define PPUMASK_SSHOW    0x10
#ifdef TV_NTSC
    #define PPUMASK_EM_RED   0x20
    #define PPUMASK_EM_GREEN 0x40
#else // TV_PAL
    #define PPUMASK_EM_RED   0x40
    #define PPUMASK_EM_GREEN 0x20
#endif
#define PPUMASK_EM_BLUE  0x80

// PPU memory addresses
// see http://wiki.nesdev.com/w/index.php/PPU_memory_map
// and http://wiki.nesdev.com/w/index.php/PPU_nametables
// and http://wiki.nesdev.com/w/index.php/PPU_attribute_tables
// and http://wiki.nesdev.com/w/index.php/PPU_palettes#Memory_Map
#define PPU_PATTERN_TABLE_0 0x0000 // pattern table 0
#define PPU_PATTERN_TABLE_1 0x1000 // pattern table 1
#define PPU_NAMETABLE_0     0x2000 // nametable 0
#define PPU_NAMETABLE_1     0x2400 // nametable 1
#define PPU_NAMETABLE_2     0x2800 // nametable 2
#define PPU_NAMETABLE_3     0x2c00 // nametable 3
#define PPU_ATTRIB_TABLE_0  0x23c0 // attribute table for nametable 0
#define PPU_ATTRIB_TABLE_1  0x27c0 // attribute table for nametable 1
#define PPU_ATTRIB_TABLE_2  0x2bc0 // attribute table for nametable 2
#define PPU_ATTRIB_TABLE_3  0x2fc0 // attribute table for nametable 3
#define PPU_PALETTE         0x3f00 // palette memory
#define PPU_PALLETE_BGC     0x3f00 // universal background color
#define PPU_PALETTE_BG_0    0x3f01 // background palette 0
#define PPU_PALETTE_BG_1    0x3f05 // background palette 1
#define PPU_PALETTE_BG_2    0x3f09 // background palette 2
#define PPU_PALETTE_BG_3    0x3f0d // background palette 3
#define PPU_PALETTE_SP_0    0x3f11 // sprite palette 0
#define PPU_PALETTE_SP_1    0x3f15 // sprite palette 1
#define PPU_PALETTE_SP_2    0x3f19 // sprite palette 2
#define PPU_PALETTE_SP_3    0x3f1d // sprite palette 3

// PPU palette colors
// see http://wiki.nesdev.com/w/index.php/PPU_palettes
#define COLOR_AQUA    0x1c
#define COLOR_BLACK   0x0f
#define COLOR_BLUE    0x12
#define COLOR_BROWN   0x17
#define COLOR_DGRAY   0x00
#define COLOR_GREEN   0x1a
#define COLOR_LIME    0x2a
#define COLOR_LGRAY   0x10
#define COLOR_MAGENTA 0x24
#define COLOR_MAROON  0x06
#define COLOR_NAVY    0x02
#define COLOR_OLIVE   0x18
#define COLOR_PURPLE  0x14
#define COLOR_RED     0x16
#define COLOR_TEAL    0x2c
#define COLOR_WHITE   0x20
#define COLOR_YELLOW  0x28

// PPU resolution in 8x8 pixel cells
// see http://wiki.nesdev.com/w/index.php/PPU_nametables
#define NUM_COLS 32
#define MIN_X 0
#define MAX_X 256

// NTSC and PAL specific configs
#ifdef TV_NTSC
  #define MIN_Y 8
  #define MAX_Y 231
  #define NUM_ROWS 28
  #define FIRST_ROW 1
  #define LAST_ROW 27
  #define FRAMES_PER_SEC 60
#else // TV_PAL
  #define MIN_Y 0
  #define MAX_Y 239
  #define NUM_ROWS 30
  #define FIRST_ROW 0
  #define LAST_ROW 29
  #define FRAMES_PER_SEC 50
#endif
#define PPU_NAMETABLE_OFFSET (NUM_COLS * FIRST_ROW)

// standard controller buttons
// see http://wiki.nesdev.com/w/index.php/Standard_controller
#define BUTTON_RIGHT  0x01
#define BUTTON_LEFT   0x02
#define BUTTON_DOWN   0x04
#define BUTTON_UP     0x08
#define BUTTON_START  0x10
#define BUTTON_SELECT 0x20
#define BUTTON_B      0x40
#define BUTTON_A      0x80

// Sprite mode is 8x8
#define SPRITE_WIDTH  8
#define SPRITE_HEIGHT 8

/* Ascii lettering in the chr */
#define ASCII_POSITION 0x0
#define ASCII_NUMBERSPOSITION 0x10
#define ASCII_OFFSET   ASCII_POSITION-0x20

// NESLIB Meta-sprite format
#define METASPR_EOB 128

// OAM sprite data
// see http://wiki.nesdev.com/w/index.php/PPU_OAM
// This one only supports a single, simple, 8x8 sprite
typedef struct sprite
{
	u8 y;
	u8 tile_index;
	u8 attributes;
	u8 x;
} sprite_t;

// OAM meta sprite
// Buffer should follow neslib metasprite format
typedef struct metasprite
{
  u8 x;
  u8 y;
  u8 *index_buffer;
} metasprite_t;

// Function pointer types
typedef void (*function)(void);
typedef void (*draw_function)(u8*);

// Defines a state that can be initialized, updated, and switched
typedef struct gamestate
{
  function      nt_init;
  function      init;
  function      update;
  draw_function draw;
  struct gamestate *next;
} gamestate_t;

// Generic rectangle definition
typedef struct rect
{
  u8 x;
  u8 y;
  u8 w;
  u8 h;
  u8 max_x; /* x + width */
  u8 max_y; /* y + height */
} rect_t;

// Used to represent numbers larger than 8-bit
// using only 8-bit numbers as digits
typedef struct digits
{
  u8 segments[8];
} digits_t;

// Draws a simple sprite and offsets the oam pointer
void __fastcall__ spr (const sprite_t *sprite, u8 *oam_ptr);

// Draws a metasprite and offsets the oam pointer
void __fastcall__ metaspr (const metasprite_t *metasprite, u8 *oam_ptr);

// Moves a rectangle while maintaining max_x and max_y values
void __fastcall__ move_rect (rect_t *rect, u8 x, u8 y);

// Determines if a point (x, y) is inside the given rect
u8 __fastcall__ point_in_rect (const rect_t *rect, u8 x, u8 y);

// Rectangle intersection function for two rects
u8 __fastcall__ rect_collides (const rect_t *first, const rect_t *second);

// Initializes a digits struct with a given number of digits
// Makes use of MALLOC
void __fastcall__ digit_init (digits_t *digits, u8 num);

// Updates a digit representation to ensure all digits
// are <= 9
void __fastcall__ digit_update(digits_t *digits);

// Increments the digit "number" by a certain amount
// and then updates it to keep it consistent
void __fastcall__ digit_increment(digits_t *digits, s8 amt);

// Prints some text to the given nametable address
// Make use of NTADR_*() macro to specify position
// Ensure that ascii offset is defined
void __fastcall__ nt_print(u16 adr, const u8 * str);

#endif