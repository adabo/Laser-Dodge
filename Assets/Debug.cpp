#include "Debug.h"

Debug::Debug()
:   tild_is_pressed(false),
    draw_debug(false)
{
    edges.LoadFont(&edges, font_surf, "Edges_5x10x32.bmp", 5, 10, 32);
}

void Debug::Update(GameManager &Mgr)
{
    if (Mgr.mouse.TildeIsPressed())
    {
        if (!tilde_is_pressed)
        {

        }
    }
    else
    {
        if (tild_is_pressed)
        {
            tilde_is_pressed = false;
            draw_debug = true;
        }
    }
}

void Debug::Draw(D3DGraphics &Gfx)
{
    if ()
    // D3DCOLOR font_surf[160 * 29];
    // Font edges;
    // char buffer[64]
    sprintf(buffer, "FPS: %d", fps);
    edges.DrawString(buffer, 0, 0, &edges, D3DCOLOR_XRGB(215, 130, 215), Gfx);
    
    sprintf(buffer, "MouseXY: %dx%d", Mgr.mouse.GetMouseX, Mgr.mouse.GetMouseY);
    edges.DrawString(buffer, 0, 25, &edges, D3DCOLOR_XRGB(215, 130, 215), Gfx);

    sprintf(buffer, ": %d", fps);
    edges.DrawString(buffer, 0, 25, &edges, D3DCOLOR_XRGB(215, 130, 215), Gfx);

}
