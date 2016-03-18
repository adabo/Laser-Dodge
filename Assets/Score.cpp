#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Score.h"

Score::Score()
    : i_score(0)
{
    fixedSys.LoadFont( &fixedSys,font_surf,"Fixedsys16x28.bmp",16,28,32 );
}

void Score::Update()
{}

void Score::Draw(Player &ThisPlayer, D3DGraphics &Gfx, int Score)
{
    // Draw targets hit
    sprintf(buffer, "Targets hit: %d", Score);
    fixedSys.DrawString(buffer, 10, 506, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    // Draw targets missed
    sprintf(buffer, "Targets missed: %d", ThisPlayer.targets_missed);
    fixedSys.DrawString(buffer, 10, 534, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    // Draw missed shots
    sprintf(buffer, "Shots missed: %d", ThisPlayer.shots_missed);
    fixedSys.DrawString(buffer, 10, 562, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
}