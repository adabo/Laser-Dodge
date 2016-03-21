#pragma once
#include "D3DGraphics.h"
#include "Font.h"

class GameManager;

class State
{
public:
    class Element;
    State(float X1, float Y1,
          float X2, float Y2,
          float X3, float Y3,
          float X4, float Y4);
    class Element
    {
    public:
        Element(float X, float Y);
    private:
        float x, y;
    };
    Element title;
    Element category;
    Element upgrade1;
    Element upgrade2;
};