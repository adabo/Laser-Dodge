/****************************************************************************************** 
 *  Chili DirectX Framework Version 12.04.24                                              * 
 *  D3DGraphics.cpp                                                                       *
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
#include "D3DGraphics.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "Bitmap.h"

UINT D3DGraphics::scrWidth = 800;
UINT D3DGraphics::scrHeight = 600;

D3DGraphics::D3DGraphics( HWND hWnd )
{
    HRESULT result;

    backRect.pBits = NULL;
    
    pDirect3D = Direct3DCreate9( D3D_SDK_VERSION );
    assert( pDirect3D != NULL );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
    d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

    result = pDirect3D->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
        D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );
    assert( !FAILED( result ) );

    result = pDevice->GetBackBuffer( 0,0,D3DBACKBUFFER_TYPE_MONO,&pBackBuffer );
    assert( !FAILED( result ) );
}

D3DGraphics::~D3DGraphics()
{
    if( pDevice )
    {
        pDevice->Release();
        pDevice = NULL;
    }
    if( pDirect3D )
    {
        pDirect3D->Release();
        pDirect3D = NULL;
    }
    if( pBackBuffer )
    {
        pBackBuffer->Release();
        pBackBuffer = NULL;
    }
}

void D3DGraphics::PutPixel( int x,int y,int r,int g,int b )
{   
    assert( x >= 0 );
    assert( y >= 0 );
    assert( x < 800 );
    assert( y < 600 );
    ((D3DCOLOR*)backRect.pBits)[ x + (backRect.Pitch >> 2) * y ] = D3DCOLOR_XRGB( r,g,b );
}
void D3DGraphics::PutPixel( int x,int y,D3DCOLOR c )
{   
    assert( x >= 0 );
    assert( y >= 0 );
    assert( x < 800 );
    assert( y < 600 );
    ((D3DCOLOR*)backRect.pBits)[ x + (backRect.Pitch >> 2) * y ] = c;
}

void D3DGraphics::BeginFrame()
{
    HRESULT result;

    result = pDevice->Clear( 0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),0.0f,0 );
    assert( !FAILED( result ) );

    result = pBackBuffer->LockRect( &backRect,NULL,NULL );
    assert( !FAILED( result ) );
}

void D3DGraphics::EndFrame()
{
    HRESULT result;

    result = pBackBuffer->UnlockRect();
    assert( !FAILED( result ) );

    result = pDevice->Present( NULL,NULL,NULL,NULL );
    assert( !FAILED( result ) );
}

void D3DGraphics::DrawDisc( int cx,int cy,int r,int rd,int g,int b )
{
    for( int x = cx - r; x < cx + r; x++ )
    {
        for( int y = cy - r; y < cy + r; y++ )
        {
            if( sqrt( (float)( (x - cx)*(x - cx) + (y - cy)*(y - cy) ) ) < r )
            {
                PutPixel( x,y,rd,g,b );
            }
        }
    }
}

void Swap( int* x1,int* x2 ){
    int temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

void D3DGraphics::DrawLine( int x1,int y1,int x2,int y2,int r,int g,int blu )
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    if( dy == 0 && dx == 0 )
    {
        PutPixel( x1,y1,r,g,blu );
    }
    else if( abs( dy ) > abs( dx ) )
    {
        if( dy < 0 )
        {
            Swap( &x1,&x2 );
            Swap( &y1,&y2 );
        }
        float m = (float)dx / (float)dy;
        float b = x1 - m*y1;
        for( int y = y1; y <= y2; y = y + 1 )
        {
            int x = (int)(m*y + b + 0.5f);
            PutPixel( x,y,r,g,blu );
        }
    }
    else
    {
        if( dx < 0 )
        {
            Swap( &x1,&x2 );
            Swap( &y1,&y2 );
        }
        float m = (float)dy / (float)dx;
        float b = y1 - m*x1;
        for( int x = x1; x <= x2; x = x + 1 )
        {
            int y = (int)(m*x + b + 0.5f);
            PutPixel( x,y,r,g,blu );
        }
    }
}

void D3DGraphics::DrawCircle( int centerX,int centerY,int radius,int r,int g,int b )
{
    int rSquared = radius*radius;
    int xPivot = (int)(radius * 0.707107f + 0.5f);
    for( int x = 0; x <= xPivot; x++ )
    {
        int y = (int)(sqrt( (float)( rSquared - x*x ) ) + 0.5f);
        PutPixel( centerX + x,centerY + y,r,g,b );
        PutPixel( centerX - x,centerY + y,r,g,b );
        PutPixel( centerX + x,centerY - y,r,g,b );
        PutPixel( centerX - x,centerY - y,r,g,b );
        PutPixel( centerX + y,centerY + x,r,g,b );
        PutPixel( centerX - y,centerY + x,r,g,b );
        PutPixel( centerX + y,centerY - x,r,g,b );
        PutPixel( centerX - y,centerY - x,r,g,b );
    }
}

void D3DGraphics::DrawLine(int StartX, int StartY, int EndX, int EndY,
    D3DCOLOR Color)
{
    StartX = max(0, min(scrWidth, StartX));
    EndX = max(0, min(scrWidth, EndX));
    StartY = max(0, min(scrHeight, StartY));
    EndY = max(0, min(scrHeight, EndY));

    int dx = EndX - StartX;
    int dy = EndY - StartY;

    if (dy == 0 && dx == 0)
    {
        PutPixel(StartX, StartY, Color);
    }
    else if (abs(dy) > abs(dx))
    {
        if (dy < 0)
        {
            int temp = StartX;
            StartX = EndX;
            EndX = temp;
            temp = StartY;
            StartY = EndY;
            EndY = temp;
        }
        float m = (float)dx / (float)dy;
        float b = StartX - m*StartY;
        for (int y = StartY; y <= EndY; y = y + 1)
        {
            int x = (int)(m*y + b + 0.5f);
            PutPixel(x, y, Color);
        }
    }
    else
    {
        if (dx < 0)
        {
            int temp = StartX;
            StartX = EndX;
            EndX = temp;
            temp = StartY;
            StartY = EndY;
            EndY = temp;
        }
        float m = (float)dy / (float)dx;
        float b = StartY - m*StartX;
        for (int x = StartX; x <= EndX; x = x + 1)
        {
            int y = (int)(m*x + b + 0.5f);
            PutPixel(x, y, Color);
        }
    }
}

void D3DGraphics::DrawFilledRect(int Left, int Top, int Right, int Bottom, D3DCOLOR Color)
{
    for (int y = Top; y < Bottom; ++y)
    {
        DrawLine(Left, y, Right, y, Color);
    }
}

void D3DGraphics::DrawRectOutline(int Left, int Top, int Right, int Bottom, D3DCOLOR Color)
{
    DrawLine(Left, Top, Right, Top, Color);       // Top line
    DrawLine(Left, Bottom, Right, Bottom, Color); // Bottom line
    DrawLine(Left, Top, Left, Bottom, Color);     // Left line
    DrawLine(Right, Top, Right, Bottom, Color);   // Right line
}
