#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "StateMainMenu.h"
#include "GameManager.h"

StateMainMenu::StateMainMenu()
:    main_text({ {"Laser Dodge", 320, 168, Text::FIXEDSYS, Text::GREY, Text::GREY},
                 {"Play",        368, 308, Text::FIXEDSYS, Text::GREY, Text::PINK}})
{}

void StateMainMenu::Update(GameManager &Mgr)
{
    for (auto &el: main_text)
    {
        if (el.Update(Mgr.mouse))
        {
            if (el.GetStr() == "Play")
            {
                Mgr.s_state.states = GAME;
            }
        }
    }
}

void StateMainMenu::Draw(D3DGraphics &Gfx)
{
    for (auto &el: main_text)
    {
        el.Draw(Gfx);
    }
}
