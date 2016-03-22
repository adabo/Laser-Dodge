#pragma once
#include "D3DGraphics.h"
#include "Bitmap.h"
#include <assert.h>

class Font
{
public:
    Font();
    void LoadFont(Font* font,D3DCOLOR* surface,const char* file_name,
                  int char_width,int char_height,int n_chars_per_row);
    void DrawChar( char c,int x,int y,Font* font,D3DCOLOR color, D3DGraphics &Gfx);
    void DrawString(const char* buffer,int x, int y, Font* font, D3DCOLOR color, D3DGraphics &Gfx);
    int char_width;
    int char_height;
    int n_chars_per_row;
    Bitmap bmp;
    D3DCOLOR* surface;
};
