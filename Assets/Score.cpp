#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Score.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

Score::Score()
    : i_score(0)
{
    fixedSys.LoadFont( &fixedSys,font_surf,"Fixedsys16x28.bmp",16,28,32 );
}

void Score::Update()
{}

void Score::Draw(Player &ThisPlayer, D3DGraphics &Gfx, int Score)
{
    // Draw scoref
    sprintf(s_score, "Score: %d", Score);
    fixedSys.DrawString(s_score, 10, 562, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    // Draw missed targets
    sprintf(missed, "Targets missed: %d", ThisPlayer.targets_missed);
    fixedSys.DrawString(missed, 10, 534, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
}