
#include "neslib.h"
#include "nesdev.h"
#include <stdlib.h>

/*
    Draw functions
*/
void __fastcall__ spr (const sprite_t *sprite, u8 *oam_ptr)
{
    *oam_ptr = oam_spr(sprite->x, 
                       sprite->y, 
                       sprite->tile_index, 
                       0, 
                       *oam_ptr);
}

void __fastcall__ metaspr (const metasprite_t *metasprite, u8 *oam_ptr)
{
    *oam_ptr = oam_meta_spr(metasprite->x, 
                            metasprite->y, 
                            *oam_ptr, 
                            metasprite->index_buffer);
}

/*
    Rectangle functions
*/
void __fastcall__ move_rect (rect_t *rect, u8 x, u8 y)
{
  rect->x = x;
  rect->y = y;
  rect->max_x = rect->x + rect->w;
  rect->max_y = rect->y + rect->h;
}

u8 __fastcall__ point_in_rect (const rect_t *rect, u8 x, u8 y)
{
  return (x > rect->x && y > rect->y && x < rect->max_x && y < rect->max_y);
}

u8 __fastcall__ rect_collides(const rect_t *first, const rect_t *second)
{
    return (first->x < second->max_x && 
            first->max_x > second->x &&
            first->y < second->max_y && 
            first->max_y > second->y);
}

/*
    Digit system
*/
void __fastcall__ digit_update(digits_t *digits)
{
  static u8 i = 0;
  
  // If a digit is over 9, ground it and set the next one up
  for (i = 0; i < 6; ++i)
  {
    if (digits->segments[i] > 9)
    {
      digits->segments[i]    = 0;
      digits->segments[i+1] += 1;
    }
  }

  // Cap last digit at 9
  if (digits->segments[7] > 9)
    digits->segments[7] = 9;
}

void __fastcall__ digit_increment(digits_t *digits, s8 amt)
{
  digits->segments[0] += amt;
  digit_update(digits);
}

void __fastcall__ nt_print(u16 adr, const u8* str)
{
	vram_adr(adr);
	while(1)
	{
		if (!(*str)) break;
		vram_put((*str++)+ASCII_OFFSET);
	}
}