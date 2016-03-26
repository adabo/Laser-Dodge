#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Text.h"

//Text::Color Text::dc = GREY;
D3DCOLOR Text::fixedSys_surf[512 * 84]; 
D3DCOLOR Text::edges_surf[160 * 29];
Font Text::fixedSys;
Font Text::edges;
// Font Text::font;

Text::Text(){}
Text::Text(std::string Str, int X, int Y, WhichFont Type, Color DC, Color MC)
:   str(Str),
    x(X),
    y(Y),
    type(Type),
    mc(MC),
    dc(DC),
    left_is_pressed(false)
{
    // Set font
    switch(type)
    {
        case FIXEDSYS:
        {
            fixedSys.LoadFont(&fixedSys, fixedSys_surf, "Fixedsys16x28.bmp", 16, 28, 32);
            // Assign reference to 'font' so that you can use it for the rest of the program
            font = fixedSys;
            w = sprintf(buff, "%s", str.c_str()) * fixedSys.char_width;
            h = fixedSys.char_height;
        }
            break;
        case EDGES:
        {
            edges.LoadFont(&edges, edges_surf, "Edges_5x9x32.bmp", 5, 9, 32);
            font = edges;
            w = sprintf(buff, "%s", str.c_str()) * edges.char_width;
            h = edges.char_height; 
        }
            break;
        default:
            break;
    }
    // Set default color
    SetColor(dc);
}

bool Text::Update(MouseClient& Mouse)
{
    int mx = Mouse.GetMouseX();
    int my = Mouse.GetMouseY();
    
    SetColor(dc);
    if (Mouse.IsInWindow())
    {
        if (MouseHoverOver(mx, my, x, y, w, h))
        {
            SetColor(mc);
            if (Mouse.LeftIsPressed())
            {
                if (!left_is_pressed)
                {
                    left_is_pressed = true;
                }
            }
            else
            {
                if (left_is_pressed)
                {
                    // For some reason, if you don't set the color back to
                    // default here, then it will flash it's old color when
                    // switch back to that screen. "<=" is a different object
                    // on every shop_screen. So you have to account for that
                    // when you are assigning colors.
                    SetColor(dc);
                    left_is_pressed = false;
                    return true;
                }
            }
        }
    }
    return false;
}

void Text::Draw(D3DGraphics &Gfx)
{
    font.DrawString(buff, x, y, &font, D3DCOLOR_XRGB(r, g, b), Gfx);
}

bool Text::MouseHoverOver(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X && MX <= X + W &&
            MY >= Y && MY <= Y + H);
}

void Text::SetColor(Color Cl)
{
    switch (Cl)
    {
    case GREY:
        r = g = b = 100;
        break;
    case PINK:
        r = 255, g = 0, b = 255;
        break;
    case GREEN:
        r = 0, g = 255, b = 0;
        break;
    case BLACK:
        r = g = b = 0;
        break;
    default:
    break;
    }
}

int Text::GetR()
{
    return r;
}

int Text::GetG()
{
    return g;
}

int Text::GetB()
{
    return b;
}

Text::Color Text::GetDC()
{
    return dc;
}

Text::Color Text::GetMC()
{
    return mc;
}

std::string Text::GetStr()
{
    return str;
}

void Text::SetStr(std::string Str)
{
    str = Str;
}

void Text::SetX(int X)
{
    x = X;
}

void Text::SetY(int Y)
{
    y = Y;
}