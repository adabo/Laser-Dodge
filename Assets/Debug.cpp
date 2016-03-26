#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Debug.h"
#include "GameManager.h"

Debug::Debug()
:   tilde_is_pressed(false),
    draw_debug(false),
    milli(0.0f),
    fps(0),
    n_frames(0),
    debug_text({{"FPS:", 1, 0, Text::EDGES, Text::PINK, Text::PINK},
                {"MouseXY:", 1, 9, Text::EDGES, Text::PINK, Text::PINK},
                {"Lasers:", 1, 18, Text::EDGES, Text::PINK, Text::PINK}})
{}

void Debug::Update(GameManager &Mgr)
{
    for (auto &el: debug_text)
    {
        el.Update(Mgr.mouse);
    }
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
            // DEBUG ONLY
            if (Mgr.kbd.KIsPressed())
            {
                Mgr.player.hp = 0;
            }
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
        for (auto &el: debug_text)
        {
            el.Draw(Gfx);
        }
    }
}
