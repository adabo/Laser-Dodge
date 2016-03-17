#pragma once

class Font
{
public:
    void LoadFont(Font* font,D3DCOLOR* surface,const char* file_name,
                  int char_width,int char_height,int n_chars_per_row);
    int char_width;
    int char_height;
    int n_chars_per_row;
    D3DCOLOR* surface;
};
