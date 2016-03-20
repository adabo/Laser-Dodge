#include "Debug.h"
#include "GameManager.h"

Debug::Debug()
:   tilde_is_pressed(false),
    draw_debug(false),
    milli(0.0f),
    fps(0),
    n_frames(0)
{
    edges.LoadFont(&edges, font_surf, "Edges_5x10x32.bmp", 5, 10, 32);
}

void Debug::Update(GameManager &Mgr)
{
    if (Mgr.kbd.TildeIsPressed())
    {
        if (!tilde_is_pressed)
        {
            tilde_is_pressed = true;
        }
    }
    else
    {
        if (tilde_is_pressed)
        {
            tilde_is_pressed = false;
            draw_debug = !draw_debug;
            timer.StartWatch();
        }            
        if (draw_debug)
        {
            if (milli >= 1000.0f)
            {
                timer.StopWatch();
                timer.StartWatch();
                milli = 0.0f;
                fps = n_frames;
                n_frames = 0;
            }
            else
            {
                ++n_frames;
            }
            milli = timer.GetTimeMilli();
        }
    }
}

void Debug::Draw(D3DGraphics &Gfx, GameManager &Mgr)
{
    if (draw_debug)
    {
        
        sprintf(buffer, "FPS: %d", fps);
        edges.DrawString(buffer, 0, 0, &edges, D3DCOLOR_XRGB(215, 130, 215), Gfx);
    
        sprintf(buffer, "MouseXY: %dx%d", Mgr.mouse.GetMouseX(), Mgr.mouse.GetMouseY());
        edges.DrawString(buffer, 0, 10, &edges, D3DCOLOR_XRGB(215, 130, 215), Gfx);

        sprintf(buffer, "Lasers: %d", Mgr.lasers.size());
        edges.DrawString(buffer, 0, 20, &edges, D3DCOLOR_XRGB(215, 130, 215), Gfx);
    }
}
