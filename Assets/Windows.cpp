/****************************************************************************************** 
 *  Chili DirectX Framework Version 12.04.24                                              * 
 *  Windows.cpp                                                                           *
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
#include <Windows.h>
#include <wchar.h>
#include "Game.h"
#include "resource.h"
#include "Mouse.h"

// VK_OEM_S 0xC0 = `~
#define VK_A 0x41 
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A

static KeyboardServer kServ;
static MouseServer mServ;

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;

        // ************ KEYBOARD MESSAGES ************ //
        case WM_KEYDOWN:
            switch( wParam )
            {
            case VK_UP:
                kServ.OnUpPressed();
                break;
            case VK_DOWN:
                kServ.OnDownPressed();
                break;
            case VK_LEFT:
                kServ.OnLeftPressed();
                break;
            case VK_RIGHT:
                kServ.OnRightPressed();
                break;
            case VK_SPACE:
                kServ.OnSpacePressed();
                break;
            case VK_RETURN:
                kServ.OnEnterPressed();
                break;
            case VK_OEM_3:
                kServ.OnTildePressed();
                break;
            case VK_A:
                kServ.OnAPressed();
                break;
            case VK_B:
                kServ.OnBPressed();
                break;
            case VK_C:
                kServ.OnCPressed();
                break;
            case VK_D:
                kServ.OnDPressed();
                break;
            case VK_E:
                kServ.OnEPressed();
                break;
            case VK_F:
                kServ.OnFPressed();
                break;
            case VK_G:
                kServ.OnGPressed();
                break;
            case VK_H:
                kServ.OnHPressed();
                break;
            case VK_I:
                kServ.OnIPressed();
                break;
            case VK_J:
                kServ.OnJPressed();
                break;
            case VK_K:
                kServ.OnKPressed();
                break;
            case VK_L:
                kServ.OnLPressed();
                break;
            case VK_M:
                kServ.OnMPressed();
                break;
            case VK_N:
                kServ.OnNPressed();
                break;
            case VK_O:
                kServ.OnOPressed();
                break;
            case VK_P:
                kServ.OnPPressed();
                break;
            case VK_Q:
                kServ.OnQPressed();
                break;
            case VK_R:
                kServ.OnRPressed();
                break;
            case VK_S:
                kServ.OnSPressed();
                break;
            case VK_T:
                kServ.OnTPressed();
                break;
            case VK_U:
                kServ.OnUPressed();
                break;
            case VK_V:
                kServ.OnVPressed();
                break;
            case VK_W:
                kServ.OnWPressed();
                break;
            case VK_X:
                kServ.OnXPressed();
                break;
            case VK_Y:
                kServ.OnYPressed();
                break;
            case VK_Z:
                kServ.OnZPressed();
                break;
            }
            break;
        case WM_KEYUP:
            switch( wParam )
            {
            case VK_UP:
                kServ.OnUpReleased();
                break;
            case VK_DOWN:
                kServ.OnDownReleased();
                break;
            case VK_LEFT:
                kServ.OnLeftReleased();
                break;
            case VK_RIGHT:
                kServ.OnRightReleased();
                break;
            case VK_SPACE:
                kServ.OnSpaceReleased();
                break;
            case VK_RETURN:
                kServ.OnEnterReleased();
                break;
            case VK_OEM_3:
                kServ.OnTildeReleased();
                break;
            case VK_A:
                kServ.OnAReleased();
                break;
            case VK_B:
                kServ.OnBReleased();
                break;
            case VK_C:
                kServ.OnCReleased();
                break;
            case VK_D:
                kServ.OnDReleased();
                break;
            case VK_E:
                kServ.OnEReleased();
                break;
            case VK_F:
                kServ.OnFReleased();
                break;
            case VK_G:
                kServ.OnGReleased();
                break;
            case VK_H:
                kServ.OnHReleased();
                break;
            case VK_I:
                kServ.OnIReleased();
                break;
            case VK_J:
                kServ.OnJReleased();
                break;
            case VK_K:
                kServ.OnKReleased();
                break;
            case VK_L:
                kServ.OnLReleased();
                break;
            case VK_M:
                kServ.OnMReleased();
                break;
            case VK_N:
                kServ.OnNReleased();
                break;
            case VK_O:
                kServ.OnOReleased();
                break;
            case VK_P:
                kServ.OnPReleased();
                break;
            case VK_Q:
                kServ.OnQReleased();
                break;
            case VK_R:
                kServ.OnRReleased();
                break;
            case VK_S:
                kServ.OnSReleased();
                break;
            case VK_T:
                kServ.OnTReleased();
                break;
            case VK_U:
                kServ.OnUReleased();
                break;
            case VK_V:
                kServ.OnVReleased();
                break;
            case VK_W:
                kServ.OnWReleased();
                break;
            case VK_X:
                kServ.OnXReleased();
                break;
            case VK_Y:
                kServ.OnYReleased();
                break;
            case VK_Z:
                kServ.OnZReleased();
                break;
            }
            break;
        // ************ END KEYBOARD MESSAGES ************ //

        // ************ MOUSE MESSAGES ************ //
        case WM_MOUSEMOVE:
            {
                int x = (short)LOWORD( lParam );
                int y = (short)HIWORD( lParam );
                if( x > 0 && x < 800 && y > 0 && y < 600 )
                {
                    mServ.OnMouseMove( x,y );
                    if( !mServ.IsInWindow() )
                    {
                        SetCapture( hWnd );
                        mServ.OnMouseEnter();
                    }
                }
                else
                {
                    if( wParam & (MK_LBUTTON | MK_RBUTTON) )
                    {
                        x = max( 0,x );
                        x = min( 799,x );
                        y = max( 0,y );
                        y = min( 599,y );
                        mServ.OnMouseMove( x,y );
                    }
                    else
                    {
                        ReleaseCapture();
                        mServ.OnMouseLeave();
                        mServ.OnLeftReleased();
                        mServ.OnRightReleased();
                    }
                }
            }
            break;
        case WM_LBUTTONDOWN:
            mServ.OnLeftPressed();
            break;
        case WM_RBUTTONDOWN:
            mServ.OnRightPressed();
            break;
        case WM_LBUTTONUP:
            mServ.OnLeftReleased();
            break;
        case WM_RBUTTONUP:
            mServ.OnRightReleased();
            break;
        // ************ END MOUSE MESSAGES ************ //
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}


int WINAPI wWinMain( HINSTANCE hInst,HINSTANCE,LPWSTR,INT )
{
    WNDCLASSEX wc = { sizeof( WNDCLASSEX ),CS_CLASSDC,MsgProc,0,0,
                      GetModuleHandle( NULL ),NULL,NULL,NULL,NULL,
                      L"Chili DirectX Framework Window",NULL };
    wc.hIconSm = (HICON)LoadImage( hInst,MAKEINTRESOURCE( IDI_APPICON16 ),IMAGE_ICON,16,16,0 );
    wc.hIcon   = (HICON)LoadImage( hInst,MAKEINTRESOURCE( IDI_APPICON32 ),IMAGE_ICON,32,32,0 );
    wc.hCursor = LoadCursor( NULL,IDC_ARROW );
    RegisterClassEx( &wc );
    
    RECT wr;
    wr.left = 650;
    wr.right = 800 + wr.left;
    wr.top = 150;
    wr.bottom = 600 + wr.top;
    AdjustWindowRect( &wr,WS_OVERLAPPEDWINDOW,FALSE );
    HWND hWnd = CreateWindowW( L"Chili DirectX Framework Window",L"Chili DirectX Framework",
                              WS_OVERLAPPEDWINDOW,wr.left,wr.top,wr.right-wr.left,wr.bottom-wr.top,
                              NULL,NULL,wc.hInstance,NULL );

    ShowWindow( hWnd,SW_SHOWDEFAULT );
    UpdateWindow( hWnd );

    Game theGame( hWnd,kServ,mServ );
    
    MSG msg;
    ZeroMemory( &msg,sizeof( msg ) );
    while( msg.message != WM_QUIT )
    {
        if( PeekMessage( &msg,NULL,0,0,PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            theGame.Go();
        }
    }

    UnregisterClass( L"Chili DirectX Framework Window",wc.hInstance );
    return 0;
}