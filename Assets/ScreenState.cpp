#include "ScreenState.h"
#include "GameManager.h"


void ScreenState::Update(GameManager &Mgr)
{
    // During each state it will set the next state
    // the game should be in. ie:
    // if game is active and player pauses the game
    // then game sets states = GAMEPAUSE
    // If the game is paused and the player unpauses
    // then the gamepuase stat will set states = GAME
    switch (states)
    {
        case GAME:
            UpdateGame(Mgr);
        break;
        case GAMEOVER:
            UpdateGameOver(Mgr);
        break;
        case GAMEMAINMENU:
            UpdateMainMenu(Mgr);
        break;
        case GAMEPAUSE:
            UpdateGamePause(Mgr);
        break;
        default:
        break;
    }
}

void ScreenState::Draw(GameManager &Mgr)
{
    switch (states)
    {
        case GAME:
            DrawGame(Mgr);
        break;
        case GAMEOVER:
            DrawGameOver(Mgr);
        break;
        case GAMEMAINMENU:
            DrawMainMenu(Mgr);
        break;
        case GAMEPAUSE:
            DrawGamePause(Mgr);
        break;
        default:
        break;
    }
}
void ScreenState::UpdateGame(GameManager &Mgr)
{
    if (Mgr.kbd.SpaceIsPressed())
    {
        states = GAMEPAUSE;
    }
}

void ScreenState::UpdateMainMenu(GameManager &Mgr)
{
}

void ScreenState::UpdateGameOver(GameManager &Mgr)
{
    if (Mgr.mouse.LeftIsPressed)
    {
        // yes      x278 y232
        // no       x486 y232
        // continue x230 y182
        if (YesClicked(Mgr.GetMouseX(), Mgr.GetMouseY()))
        {}
        if (NoClicked(Mgr.GetMouseX(), Mgr.GetMouseY()))
        {}
    }
}

void ScreenState::ScreenState::UpdateGamePause(GameManager &Mgr)
{}

bool ScreenState::YesClicked(int MouseX, int MouseY)
{
    if(MouseClickedBox(MouseX, MouseY, yes_x, yes_y, yes_w, yes_h)) 
    {
        states = GAME;
    }
}

bool ScreenState::NoClicked()
{
    if(MouseClickedBox(MouseX, MouseY, no_x, no_y, no_w, no_h)) 
    {
        states = GAMEMAINMENU;
    }
}

bool ScreenState::MouseClickedBox(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X || MX <= X + W ||
            MX >= Y || MX <= Y + H);
}
