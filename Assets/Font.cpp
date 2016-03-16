#include "Font.h"

void Font::LoadFont( Font* font,D3DCOLOR* surface,const char* file_name,
        int char_width,int char_height,int n_chars_per_row)
{
    LoadBmp( file_name,surface );
    font->char_height = char_height;
    font->char_width = char_width;
    font->n_chars_per_row = n_chars_per_row;
    font->surface = surface;
}