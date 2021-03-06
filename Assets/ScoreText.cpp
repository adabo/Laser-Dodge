#include "ScoreText.h"
#include "GameManager.h"

ScoreText::ScoreText(GameManager &Mgr)
// Make 2 vectors: 1 string and 1 int or floats. Loop each one
// and just make Text.cpp set the text for each and every text element.
// This way you can add large amounts of text and only have to do 3 loops.
// Loop 1: The static texts
// Loop 2: The dynamic strings
// Loop 3: The dynamic ints/floats
:   mgr(Mgr)
{
    hp = 0;
    x  = 0;
    y  = 0;
    score_text = {  {"Targets hit:",             16,  504, Text::FIXEDSYS, Text::GREY,  Text::GREY},
                    {&mgr.score.targets_hit,         224, 504, Text::FIXEDSYS, Text::GREY,  Text::GREY, Text::INT},
                    {"Targets missed:",          16,  532, Text::FIXEDSYS, Text::GREY,  Text::GREY},
                    {&mgr.player.targets_missed, 272, 532, Text::FIXEDSYS, Text::GREY,  Text::GREY, Text::INT},
                    {"Shots missed:",            16,  560, Text::FIXEDSYS, Text::GREY,  Text::GREY},
                    {&mgr.player.shots_missed,   240, 560, Text::FIXEDSYS, Text::GREY,  Text::GREY, Text::INT},
                    {"HP:",                      624, 560, Text::FIXEDSYS, Text::GREY,  Text::GREY},
                    {&mgr.player.hp,             688, 560, Text::FIXEDSYS, Text::GREY,  Text::GREY, Text::FLOAT},
                    {&hp,                         &x,  &y, Text::EDGES,    Text::BLACK, Text::RED,  Text::INT}};
}

void ScoreText::Update()
{
    hp = (int)mgr.enemies[0].GetHP();
    x  = (int)mgr.enemies[0].GetX() + mgr.enemies[0].GetWidth() / 2;
    y  = (int)mgr.enemies[0].GetY() + mgr.enemies[0].GetHeight() / 2;
    for (auto &el: score_text)
    {
        el.Update(mgr.mouse);
    }
}

void ScoreText::Draw()
{
    for (auto &el: score_text)
    {
       el.Draw(mgr.gfx);
    }
}
