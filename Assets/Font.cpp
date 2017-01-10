#include "Font.h"

void Font::LoadFont( Font* font,D3DCOLOR* surface,const char* file_name,
        int char_width,int char_height,int n_chars_per_row)
{
    bmp.LoadBmp( file_name,surface );
    font->char_height = char_height;
    font->char_width = char_width;
    font->n_chars_per_row = n_chars_per_row;
    font->surface = surface;
}

void Font::DrawString( const char* buffer,int x_offset,int y_offset,Font* font,D3DCOLOR color, D3DGraphics &Gfx ){
    for( int index = 0; buffer[ index ] != '\0'; index++ )
    {
        int n = 0;
        n = x_offset + index * font->char_width;
        if (n > 799 )
        {
            assert( n > 799 );
        }
        DrawChar( buffer[ index ],x_offset + index * font->char_width,y_offset,font,color, Gfx );
    }
}

void Font::DrawChar( char c,int x_offset,int y_offset,Font* font,D3DCOLOR color, D3DGraphics &Gfx ){
    if( c < ' ' || c > '~' )
        return;

    const int sheet_index = c - ' ';
    const int sheet_col = sheet_index % font->n_chars_per_row;
    const int sheet_row = sheet_index / font->n_chars_per_row;
    const int x_start = sheet_col * font->char_width;
    const int y_start = sheet_row * font->char_height;
    const int x_end = x_start + font->char_width;
    const int y_end = y_start + font->char_height;
    const int surf_width = font->char_width * font->n_chars_per_row;

    for( int y = y_start; y < y_end; y++ )
    {
        for( int x = x_start; x < x_end; x++ )
        {
            if( font->surface[ x + y * surf_width ] == D3DCOLOR_XRGB( 0,0,0 ) )
            {
                int z = x + x_offset - x_start;
                if (z > 799)
                {
                    z = 799;
                }
                Gfx.PutPixel( z,y + y_offset - y_start,color );
            }
        }
    }
}
