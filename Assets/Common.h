#pragma once
#include "Font.h"
#include "D3DGraphics.h"

#define SCREENWIDTH 800
#define SCREENHEIGHT 600
#define SCREENCENTERX 400
#define SCREENCENTERY 300

enum States
{
    GAME, GAMEOVER, GAMEMAINMENU, GAMEPAUSE, GAMESHOP
};

class Text
{
public:
    Text();
    void DrawText(x);

private:
    int x, y, w, h;
    int r, g, b;
    char buff[64];
    char str[64];
    Font &font;
    D3DGraphics &gfx;
};

Text::Text(char* Str, char* Buff, Font& Fn, D3DGraphics& Gfx,
              int X, int Y, int H, int W, int R, int G, int B)
:   buff(Buff),
    font(Fn),
    gfx(Gfx),
    x(X),
    y(Y),
    w(W),
    h(H),
    r(R),
    g(G),
    b(B)
{}

void Text::DrawText()
{
    sprintf(buff, "%s", str);
    fixedSys.DrawString(buff, x, y, &font, D3DCOLOR_XRGB(r, g, b), gfx);
}