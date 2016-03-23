#include "Text.h"

Text::Text(const char* Str, WhichFont Type, D3DGraphics* Gfx,
           int X, int Y, int DR, int DG, int DB,
           int MR, int MG, int MB)
:   str(Str),
    gfx(Gfx),
    x(X),
    y(Y),
    type(Type),
    dfault(DR, DG, DB),
    mouseover(MR, MG, MB)
{
    
    switch(type)
    {
        case FIXEDSYS:
        {
            fixedSys.LoadFont(&fixedSys, fixedSys_surf, "Fixedsys16x28.bmp", 16, 28, 32);
            // Assign reference to 'font' so that you can use it for the rest of the program
            font = fixedSys;
            w = sprintf(buff, "%s", str) * fixedSys.char_width;
            h = fixedSys.char_height;
        }
            break;
        case EDGES:
        {
            edges.LoadFont(&edges, edges_surf, "Edges_5x9x32.bmp", 5, 9, 32);
            font = edges;
            w = sprintf(buff, "%s", str) * edges.char_width;
            h = edges.char_height; 
        }
            break;
        default:
            break;
    }
}

void Text::Update(MouseClient& Mouse)
{
    int mx = Mouse.GetMouseX();
    int my = Mouse.GetMouseY();
    
    r = dfault.r;
    g = dfault.g;
    b = dfault.b;

    if (Mouse.IsInWindow())
    {
        if (MouseHoverOver(mx, my, x, y, w, h))
        {
            r = mouseover.r;
            g = mouseover.g;
            b = mouseover.b;
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
                    left_is_pressed = false;
                    // shop_state = MAIN;
                }
            }
        }
    }
}

void Text::Draw()
{
    font.DrawString(buff, x, y, &font, D3DCOLOR_XRGB(r, g, b), *gfx);
}

bool Text::MouseHoverOver(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X && MX <= X + W &&
            MY >= Y && MY <= Y + H);
}