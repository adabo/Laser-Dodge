#include "Bitmap.h"
#include <stdio.h>
#include <assert.h>



void Bitmap::LoadBmp( const char* file_name, D3DCOLOR* surface)
{
    FILE* bmpFile = fopen( file_name,"rb" );

    fseek( bmpFile,2,SEEK_SET );

    BMP_Header bmp_header;
    fread( &bmp_header,sizeof( bmp_header ),1,bmpFile );

    BMP_Info_Header bmp_info_header;
    fread( &bmp_info_header,sizeof( bmp_info_header ),1,bmpFile );

    fseek( bmpFile,bmp_header.offset,SEEK_SET );
    // Assume 24 bits
    int n_padding_bytes_per_row = ( 4 - ( ( bmp_info_header.width * 3 ) % 4 ) ) % 4;
    Pixel24 pixel;
    for( int y = bmp_info_header.height - 1; y >= 0 ; y-- )
    {
        for( int x = 0; x < bmp_info_header.width; x++ )
        {
            fread( &pixel,sizeof( pixel ),1,bmpFile );
            surface[ x + y * bmp_info_header.width ] = D3DCOLOR_XRGB( pixel.red,pixel.green,pixel.blue );
        }
        fseek( bmpFile,n_padding_bytes_per_row,SEEK_CUR );
    }

    fclose( bmpFile );
}

