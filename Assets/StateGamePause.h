#pragma once
#include "D3DGraphics.h"

class GameManager;

class StateGamePause
{
public:
    void Update(GameManager &Mgr);
    void Draw(D3DGraphics &Gfx);
};