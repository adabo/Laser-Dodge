#include "Score.h"

Score::Score()
    : i_score(0)
{
    fixedSys.LoadFont( &fixedSys,font_surf,"Fixedsys16x28.bmp",16,28,32 );
}

void Score::Update()
{}

void Score::Draw(D3DGraphics &Gfx, int Score)
{
    sprintf(s_score, "Score: %d", Score);
    fixedSys.DrawString(s_score, 400, 400, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
}