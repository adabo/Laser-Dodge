#include "Trigonometry.h"
#define PI 3.1415926535897932384626433832795

Trigonometry::Trigonometry()
{}
Trigonometry::~Trigonometry()
{}

float Trigonometry::RadiansToDegrees(float radians)
{
    float degrees = (radians * 180);
    return degrees;
}

float Trigonometry::GetHypotenuse(float start_x, float start_y,
                    float end_x, float end_y)
{
    float x_sqr      = (start_x - end_x) * (start_x - end_x);
    float y_sqr      = (start_y - end_y) * (start_y - end_y);
    float hypotenuse = (float)sqrt(x_sqr + y_sqr); 
    return hypotenuse;
}

float Trigonometry::GetCosX(float start_x, float end_x, float hypotenuse)
{
    // cos = adjacent / hypotenuse
    float cosine = -(start_x - end_x) / hypotenuse;
    return cosine;
}

float Trigonometry::GetSinY(float start_y, float end_y, float hypotenuse)
{
    // sin = opposite / hypotenuse
    float sine = -(start_y - end_y) / hypotenuse;
    return sine;
}

float Trigonometry::AdjacentFromOpposite(float opposite, float theta)
{
    // tan() wants radians. Convert theta
    // to radians inside function call
    theta = (float)tan(theta * PI / 180);
    float adjacent = opposite / theta;
    return adjacent;
}

float Trigonometry::OppositeFromAdjacent(float adjacent, float theta)
{
    theta = (float)tan(theta * PI / 180);
    float opposite = adjacent * theta;
    return opposite;
}

float Trigonometry::ThetaFromSin(float opposite, float hypotenuse)
{
    float sine = opposite / hypotenuse;
    float theta = (float)asin(sine) * 180 / (float)PI;
    //theta = theta * (180 / PI);
    return theta;
}

float Trigonometry::GetTan(float start_x, float end_x,
             float start_y, float end_y)
{
    float tan = (start_y - end_y) / (start_x - end_x);
    return tan;
}

float Trigonometry::GetSinFromHypotenuse(float hypotenuse, float theta)
{
    float sine = (float)sin(theta) * hypotenuse;
    return sine;
}

float Trigonometry::GetCosFromHypotenuse(float hypotenuse, float theta)
{
    float cosine = (float)cos(theta) * hypotenuse;
    return cosine;
}
