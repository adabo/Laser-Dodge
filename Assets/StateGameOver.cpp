#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "StateGameOver.h"
#include "GameManager.h"

StateGameOver::StateGameOver()
:   yes_x(278),
    yes_y(232),
    yes_w(44),
    yes_h(18),
    no_x(486),
    no_y(232),
    no_w(28),
    no_h(18)
{
    fixedSys.LoadFont(&fixedSys, font_surf, "Fixedsys16x28.bmp", 16, 28, 32);
}


void StateGameOver::Update(GameManager &Mgr)
{
    Reset(Mgr);
    if (MouseClickedBox(Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY(), yes_x, yes_y, yes_w, yes_h))
    {
        y_red = 25;
        y_green = 150;
        y_blue = 25;
    }
    else
    {
        y_red = 100;
        y_green = 100;
        y_blue = 100;
    }
    if (MouseClickedBox(Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY(), no_x, no_y, no_w, no_h))
    {
        n_red = 150;
        n_green = 25;
        n_blue = 25;
    }
    else
    {
        n_red = 100;
        n_green = 100;
        n_blue = 100;
    }
    if (Mgr.mouse.LeftIsPressed())
    {
        // Check if yes
        if (MouseClickedBox(Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY(), yes_x, yes_y, yes_w, yes_h))
        {
            Mgr.s_state.states = GAME;
        }
        // Check if no
        else if (MouseClickedBox(Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY(), no_x, no_y, no_w, no_h))
        {
            Mgr.s_state.states = GAMEMAINMENU;
        }
    }
}

void StateGameOver::Reset(GameManager &Mgr)
{
    Mgr.player = Player();
    Mgr.enemy = Enemy();
    Mgr.laser = Laser();
    Mgr.enemies.clear();
    Mgr.lasers.clear();
    Mgr.score = Score();
    Mgr.spawner = Spawner();
}

bool StateGameOver::MouseClickedBox(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X && MX <= X + W &&
            MY >= Y && MY <= Y + H);
}

void StateGameOver::Draw(D3DGraphics &Gfx)
{
    // yes      x278 y232
    // no       x486 y232
    // continue x230 y182
    char buffer[64];
    sprintf(buffer, "Continue?");
    fixedSys.DrawString(buffer, 330, 182, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);

    sprintf(buffer, "Yes");
    fixedSys.DrawString(buffer, yes_x, yes_y - 4, &fixedSys, D3DCOLOR_XRGB(y_red, y_green, y_blue), Gfx);

    sprintf(buffer, "No");
    fixedSys.DrawString(buffer, no_x, no_y - 4, &fixedSys, D3DCOLOR_XRGB(n_red, n_green, n_blue), Gfx);
}