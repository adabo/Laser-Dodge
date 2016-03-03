#include "Trigonometry.h"

float GetHypotenuse(float start_x, float start_y,
                    float end_x, float end_y)
{
    float x_sqr         = (start_x - end_x) * (start_x - end_x);
    float y_sqr         = (start_y - end_y) * (start_y - end_y);
    float hypotenuse = sqrt(x_sqr + y_sqr); 
    return hypotenuse;
}

float GetCosX(float start_x, float end_x, float hypotenuse)
{
    // cos = adjacent / hypotenuse
    float cosine = -(start_x - end_x) / hypotenuse;
    return cosine;
}

float GetSinY(float start_y, float end_y, float hypotenuse)
{
    // sin = opposite / hypotenuse
    float sine = -(start_y - end_y) / hypotenuse;
    return sine;
}

float GetRise(float theta, float hypotenuse)
{
    float rise = sin(theta) * hypotenuse;
    return rise;
}

float GetRun(float a = 0, float c = 0)
{
    float r;
    bool neg_a = a < 0;
    a *= a;
    c *= c;
    if (neg_a)
    {
        r = -sqrt(c - a);
    }
    else
    {
        r = sqrt(c - a);
    }
    return r;
}

float GetTan(float start_x, float end_x,
             float start_y, float end_y)
{
    float tan = (start_y - end_y) / (start_x - end_x);
    return tan;
}

float GetSinFromHypotenuse(float hypotenuse, float theta)
{
    float sine = sin(theta) * hypotenuse;
    return sine;
}

float GetCosFromHypotenuse(float hypotenuse, float theta)
{
    float cosine = cos(theta) * hypotenuse;
    return cosine;
}