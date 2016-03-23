#pragma once
#include "Font.h"
#include <stdio.h>
#include "Mouse.h"

class Text
{
public:
    enum WhichFont
    {
        FIXEDSYS, EDGES
    };
    
    class FontColorChange
    {
    public:
        FontColorChange(int R, int G, int B)
        :   r(R),
            g(G),
            b(B)
        {}
        ~FontColorChange(){}
        int r, g, b;
    };
    
    Text(const char* Str, WhichFont Type, D3DGraphics* Gfx,
        int X, int Y, int DR, int DG, int DB,
        int MR, int MG, int MB);
    void Draw();
    void Update(MouseClient &Mouse);
    bool MouseHoverOver(int MX, int MY, int X, int Y, int W, int H);
private:
    int x, y, w, h;
    int r, g, b;
    char buff[64];
    const char *str;
    D3DGraphics *gfx;
    D3DCOLOR fixedSys_surf[512 * 84]; // fixedSys
    D3DCOLOR edges_surf[160 * 29];    // edges
    Font fixedSys;
    Font edges;
    Font font;
    WhichFont type;
    FontColorChange dfault;
    FontColorChange mouseover;
    bool left_is_pressed;
};
