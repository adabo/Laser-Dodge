#pragma once
#include <vector>
#include "Text.h"

class GameManager;

class ScoreText
{
public:
    ScoreText(GameManager &Mgr);
    void Update();
    void Draw();
private:
    std::vector<Text> score_text;
    GameManager &mgr;
    int x,y,hp;
};