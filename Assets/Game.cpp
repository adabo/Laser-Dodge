/****************************************************************************************** 
 *  Chili DirectX Framework Version 12.04.24                                              * 
 *  Game.cpp                                                                              *
 *  Copyright 2012 PlanetChili.net                                                        *
 *                                                                                        *
 *  This file is part of The Chili DirectX Framework.                                     *
 *                                                                                        *
 *  The Chili DirectX Framework is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by                  *
 *  the Free Software Foundation, either version 3 of the License, or                     *
 *  (at your option) any later version.                                                   *
 *                                                                                        *
 *  The Chili DirectX Framework is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         *
 *  GNU General Public License for more details.                                          *
 *                                                                                        *
 *  You should have received a copy of the GNU General Public License                     *
 *  along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"

Game::Game( HWND hWnd,const KeyboardServer& kServer,const MouseServer& mServer )
:   gfx( hWnd ),
    kbd( kServer ),
    mouse( mServer ),
    mgr(hWnd, gfx, kServer, mServer)
{}

Game::~Game() {}

void Game::Go()
{
    timer.StopWatch();
    float dt = timer.GetTimeMilli() * 0.001f;
    timer.StartWatch();

    mgr.Update(dt);
    
    gfx.BeginFrame();
    ComposeFrame();
    gfx.EndFrame();
}

void Game::ComposeFrame()
{
    mgr.Draw();
    for (int x = 0; x < 800; ++x)
    {
        gfx.PutPixel(x, 0, D3DCOLOR_XRGB(255, 0, 255));
        gfx.PutPixel(x, 599, D3DCOLOR_XRGB(255, 0, 255));
    }
    for (int y = 0; y < 600; ++y)
    {
        gfx.PutPixel(0, y, D3DCOLOR_XRGB(255, 0, 255));
        gfx.PutPixel(799, y, D3DCOLOR_XRGB(255, 0, 255));
    }
}
