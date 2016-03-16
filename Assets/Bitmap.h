#pragma once
#include <d3d9.h>

struct BMP_Header
{
    // unsigned short int type;
    unsigned int size;
    unsigned short int reserved1, reserved2;
    unsigned int offset;
};

struct BMP_Info_Header
{
    unsigned int info_header_size;
    int width,height;
    unsigned short int planes;
    unsigned short int bits;
    unsigned int compression;
    unsigned int imagesize;
    int xresolution,yresolution;
    unsigned int ncolours;
    unsigned int importantcolours;
};

struct Pixel24
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
};

class Bitmap
{
public:
    void LoadBmp( const char* file_name,D3DCOLOR* surface );
};

