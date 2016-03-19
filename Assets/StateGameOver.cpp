#include "StateGameOver.h"

StateGameOver()
:   yes_x(278),
    yes_y(232),
    yes_w(44),
    yes_h(18),
    no_x(486),
    no_y(232),
    no_w(22),
    no_h(18)
{}


void StateGameOver::Update(GameManager &Mgr)
{
    if (Mgr.mouse.LeftIsPressed)
    {
        // Check if yes
        if (MouseClickedBox(Mgr.GetMouseX(), Mgr.GetMouseY(), yes_x, yes_y, yes_w, yes_h))
        {
            Mgr.s_state.states = GAME;
        }
        // Check if no
        else if (MouseClickedBox(Mgr.GetMouseX(), Mgr.GetMouseY(), no_x, no_y, no_w, no_h))
        {
            Mgr.s_state.states = GAMEMAINMENU;
        }
    }
}

bool StateGameOver::MouseClickedBox(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X || MX <= X + W ||
            MX >= Y || MX <= Y + H);
}

void StateGameOver::Draw(D3DGraphics &Gfx)
{
    // yes      x278 y232
    // no       x486 y232
    // continue x230 y182
    char buffer[64];
    sprintf(buffer, "Continue?");
    fixedSys.DrawString(buffer, 330, 182, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx)

    sprintf(buffer, "Yes");
    fixedSys.DrawString(buffer, yes_x, yes_y, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx)

    sprintf(buffer, "No");
    fixedSys.DrawString(buffer, no_x, no_y, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx)
}