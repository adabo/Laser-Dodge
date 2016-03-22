#pragma once

class GameManager;

class StateGame
{
public:
    StateGame();
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr);
    void UpdateAll(GameManager &Mgr);
private:
    bool space_is_pressed;
    bool tab_is_pressed;
};
