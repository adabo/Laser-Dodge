#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Score.h"
// Distributed percentage
// #define DISTPCT 3.921568627450980392156862745098

Score::Score()
:   i_score(0)
{}
Score::Score(int hp)
    : i_score(0),
    col_r(255),
    col_g(0),
    col_b(0),
    dist_pct(hp / (float)col_r)
{
    fixedSys.LoadFont( &fixedSys,font_surf,"Fixedsys16x28.bmp",16,28,32 );
}

void Score::Update()
{}

void Score::Draw(Player &ThisPlayer, D3DGraphics &Gfx, int Score)
{/*
    // Draw targets hit
    sprintf(buffer, "Targets hit: %d", Score);
    fixedSys.DrawString(buffer, 10, 506, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    // Draw targets missed
    sprintf(buffer, "Targets missed: %d", ThisPlayer.targets_missed);
    fixedSys.DrawString(buffer, 10, 534, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    // Draw missed shots
    sprintf(buffer, "Shots missed: %d", ThisPlayer.shots_missed);
    fixedSys.DrawString(buffer, 10, 562, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    // Draw hp
    int string_width = sprintf(buffer, "HP: %.2f", ThisPlayer.hp);
    string_width = string_width * fixedSys.char_width;
    fixedSys.DrawString(buffer, SCREENWIDTH - (string_width + 10), SCREENHEIGHT - 38, &fixedSys, D3DCOLOR_XRGB(col_r, (int)(ThisPlayer.hp / dist_pct), (int)(ThisPlayer.hp / dist_pct)), Gfx);
*/}