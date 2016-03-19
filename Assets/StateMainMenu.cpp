#include "StateMainMenu.h"

StateMainMenu()
:   laser_dodge_x(314),
    laser_dodge_y(176),
    laser_dodge_w(172),
    laser_dodge_h(24),
    play_x(370),
    play_y(314),
    play_w(60),
    play_h(24)
{}

void StateMainMenu::Update(GameManager &Mgr)
{
    if (Mgr.mouse.LeftIsPressed)
    {
        // Check if yes
        if (MouseClickedBox(Mgr.GetMouseX(), Mgr.GetMouseY(),
            play_x, play_y, play_w, play_h))
        {
            Mgr.s_state.states = GAME;
        }
    }
}

bool StateMainMenu::MouseClickedBox(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X || MX <= X + W ||
            MX >= Y || MX <= Y + H);
}

void StateMaineMenu::Draw(D3DGraphics &Gfx)
{
    // Laser Dodge x314, y176
    // Play x370 y314
    char buffer[64];
    sprintf(buffer, "Laser Dodge?");
    fixedSys.DrawString(buffer, laser_dodge_x, laser_dodge_y, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx)

    sprintf(buffer, "Play");
    fixedSys.DrawString(buffer, play_x, play_y, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx)
}
