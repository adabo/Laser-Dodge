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
    play_blue(100),
    main_text({ {"Laser Dodge", 320, 168, Text::FIXEDSYS, Text::GREY, Text::GREY},
                {"Play",        368, 308, Text::FIXEDSYS, Text::GREY, Text::PINK}})
{}

void StateMainMenu::Update(GameManager &Mgr)
{
    for (auto &el: main_text)
    {
        el.Update(Mgr.mouse);
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
    for (auto &el: main_text)
    {
        el.Draw(Gfx);
    }
}
