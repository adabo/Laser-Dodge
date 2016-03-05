#pragma once
#include <math.h>

class Trigonometry
{
public:
    Trigonometry();
    ~Trigonometry();
    float RadiansToDegrees(float radians);
    float GetHypotenuse(float start_x, float start_y,
                        float end_x, float end_y);
    float GetCosX(float start_x, float end_x, float hypotenuse);
    float GetSinY(float start_y, float end_y, float hypotenuse);
    float GetRise(float theta, float hypotenuse);
    float GetRun(float a, float c);
    float GetTan(float start_x, float end_x,
                 float start_y, float end_y);
    float GetSinFromHypotenuse(float hypotenuse, float theta);
    float GetCosFromHypotenuse(float hypotenuse, float theta);
    float AdjacentFromOpposite(float Opposite, float theta);
    float OppositeFromAdjacent(float Adjacent, float theta);
    float ThetaFromSin(float opposite, float hypotenuse);
};
