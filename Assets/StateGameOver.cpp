#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "StateGameOver.h"
#include "GameManager.h"

StateGameOver::StateGameOver(std::vector<Text> &GameText)
:   gameover_text({{"Play Again?", 336, 196, Text::FIXEDSYS, Text::GREY, Text::GREY},
                   {"Yes", 272, 224, Text::FIXEDSYS, Text::GREY, Text::GREEN},
                   {"No", 496, 224, Text::FIXEDSYS, Text::GREY, Text::RED}}),
    game_text(GameText)
{}


void StateGameOver::Update(GameManager &Mgr)
{
    for (auto &el: gameover_text)
    {
        if (el.Update(Mgr.mouse))
        {
            if (el.GetStr() == "Yes")
            {
                Mgr.s_state.states = GAME;
                Reset(Mgr);
            }
            else if (el.GetStr() == "No")
            {
                Mgr.s_state.states = GAMEMAINMENU;
                Reset(Mgr);
            }
        }
    }

    // Loop through Game text to display stats
    for (auto &el: game_text)
    {
        el.Update(Mgr.mouse);
    }

/*    if (MouseClickedBox(Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY(), yes_x, yes_y, yes_w, yes_h))
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
            Reset(Mgr);
        }
        // Check if no
        else if (MouseClickedBox(Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY(), no_x, no_y, no_w, no_h))
        {
            Mgr.s_state.states = GAMEMAINMENU;
            Reset(Mgr);
        }
    }*/
}

void StateGameOver::Reset(GameManager &Mgr)
{
    Mgr.player = Player();
    Mgr.enemies.clear();
    Mgr.lasers.clear();
    Mgr.score = Score((int)Mgr.player.hp);
    Mgr.spawner = Spawner();
}

void StateGameOver::Draw(GameManager &Mgr, D3DGraphics &Gfx)
{
    for (auto &el: gameover_text)
    {
        el.Draw(Mgr.gfx);
    }
}