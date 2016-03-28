#pragma once
#include "Font.h"
#include <stdio.h>
#include "Mouse.h"
#include <string>
#include "D3DGraphics.h"

class Text
{
public:
    enum StrType
    {
        STRING, INT, FLOAT
    };

    enum Color
    {
        GREY, PINK, GREEN, BLACK, RED
    };

    enum WhichFont
    {
        FIXEDSYS, EDGES
    };
public:
    Text();
    Text(std::string Str,  int X, int Y, WhichFont Type, Color DC, Color MC, StrType SType = STRING);
    Text(int*         IStr, int X, int Y, WhichFont Type, Color DC, Color MC, StrType SType = STRING);
    Text(float*       FStr, int X, int Y, WhichFont Type, Color DC, Color MC, StrType SType = STRING);
    // Text(float*       FStr, int* X, int* Y, WhichFont Type, Color DC, Color MC, StrType SType = STRING);

    void Draw(D3DGraphics &Gfx);
    bool Update(MouseClient& Mouse);

    bool MouseHoverOver(int MX, int MY, int X, int Y, int W, int H);
    void ToString();

    Color       GetDC();
    Color       GetMC();
    int         GetR();
    int         GetG();
    int         GetB();
    std::string GetStr();

    void SetIToA(int* IStr);
    void SetFToA(float* FStr);
    void SetColor(Color Cl);
    void SetBuff();
    void SetStr(std::string Str);
    void SetX(int X);
    void SetY(int Y);

private:
    StrType s_type;
    int x, y, w, h;
    int *px, *py;
    int r, g, b;
    char buff[64];
    std::string str;
    int* i_str;
    float* f_str;
    WhichFont type;
    Color dc;
    Color mc;
    static D3DCOLOR fixedSys_surf[512 * 84]; // fixedSys
    static D3DCOLOR edges_surf[160 * 29];    // edges
    static Font fixedSys;
    static Font edges;
    Font font;
    bool left_is_pressed;
};
