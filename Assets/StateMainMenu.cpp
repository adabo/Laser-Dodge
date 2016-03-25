#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "StateMainMenu.h"
#include "GameManager.h"

StateMainMenu::StateMainMenu()
:   laser_dodge_x(314),
    laser_dodge_y(176),
    laser_dodge_w(172),
    laser_dodge_h(24),
    play_x(370),
    play_y(314),
    play_w(62),
    play_h(26),
    play_red(100),
    play_green(100),
    play_blue(100)  
{
    fixedSys.LoadFont(&fixedSys, font_surf, "Fixedsys16x28.bmp", 16, 28, 32);
}

void StateMainMenu::Update(GameManager &Mgr)
{
    // Check mouse hover
    if (MouseHoverOver(Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY(), play_x, play_y, play_w, play_h))
    {
        play_red = 25;
        play_green = 150;
        play_blue = 25;
    }
    else
    {
        play_red = 100;
        play_green = 100;
        play_blue = 100;
    }
    if (Mgr.mouse.LeftIsPressed())
    {
        if (MouseHoverOver(Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY(),
            play_x, play_y, play_w, play_h))
        {
            Mgr.s_state.states = GAME;
        }
    }
}

bool StateMainMenu::MouseHoverOver(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X && MX <= X + W &&
            MY >= Y && MY <= Y + H);
}

void StateMainMenu::Draw(D3DGraphics &Gfx)
{
    // Laser Dodge x314, y176
    // Play x370 y314
    char buffer[64];
    sprintf(buffer, "Laser Dodge");
    fixedSys.DrawString(buffer, laser_dodge_x, laser_dodge_y, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);

    sprintf(buffer, "Play");
    fixedSys.DrawString(buffer, play_x, play_y, &fixedSys, D3DCOLOR_XRGB(play_red, play_green, play_blue), Gfx);
}
