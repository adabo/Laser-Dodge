#pragma once
#include "D3DGraphics.h"

class GameManager;

class StateGamePause
{
public:
    StateGamePause();
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr);
private:
    bool space_is_pressed;
};