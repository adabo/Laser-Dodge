#pragma once

class GameManager;

class StateGame
{
public:
    void Update(GameManager &Mgr);
    void Draw(D3DGraphics &Gfx);
};
