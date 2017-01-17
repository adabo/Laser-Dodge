#pragma once
#include "Text.h"
#include <vector>

class GameManager;

class StateGame
{
public:
    StateGame();
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr);
    void UpdateAll(GameManager &Mgr);
    std::vector<Text> GetVecText();
private:
    std::vector<Text> game_text;
    bool space_is_pressed;
    bool tab_is_pressed;
};
