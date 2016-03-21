#pragma once
#include "Common.h"
#include "D3DGraphics.h"
#include "Font.h"

class GameManager;

class StateShop
{
public:
    enum ShopStates
    {
        MAIN, SHIP, WEAPON, AMMO, SKILL
    };
    StateShop();
    class Screen
    {
    public:
        Screen() {}
        Screen(int X1, int Y1)
        :   title(X1, Y1)
        {}
        Screen(int X1, int Y1,
               int X2, int Y2)
        :   title(X1, Y1),
            category(X2, Y2)
        {}
        Screen(int X1, int Y1,
               int X2, int Y2,
               int X3, int Y3)
        :   title(X1, Y1),
            category(X2, Y2),
            upgrade1(X3, Y3)
        {}
        Screen(int X1, int Y1,
               int X2, int Y2,
               int X3, int Y3,
               int X4, int Y4)
        :   title(X1, Y1),
            category(X2, Y2),
            upgrade1(X3, Y3),
            upgrade2(X4, Y4)
        {}
        Screen(int X1, int Y1,
               int X2, int Y2,
               int X3, int Y3,
               int X4, int Y4,
               int X5, int Y5)
        :   title(X1, Y1),
            category(X2, Y2),
            upgrade1(X3, Y3),
            upgrade2(X4, Y4),
            upgrade3(X5, Y5)
        {}
        Screen(int X1, int Y1,
               int X2, int Y2,
               int X3, int Y3,
               int X4, int Y4,
               int X5, int Y5,
               int X6, int Y6)
        :   title(X1, Y1),
            category(X2, Y2),
            upgrade1(X3, Y3),
            upgrade2(X4, Y4),
            upgrade3(X5, Y5),
            upgrade4(X6, X6)
        {}
        class Element
        {
        public:
            Element() {}
            Element(int X, int Y)
            :   x(X),
                y(Y)
            {}
        private:
            int x, y;
        };
    private:
        Element title;
        Element category;
        Element upgrade1;
        Element upgrade2;
        Element upgrade3;
    };
public:
    UpdateShopMain(Mgr);
    UpdateShopShip(Mgr);
    UpdateShopWeapon(Mgr);
    UpdateShopAmmo(Mgr;
    UpdateShopSkill(Mgr);
private:
    ShopStates shop_state
    Screen shop_main;
    Screen shop_ship;
    Screen shop_weapon;
    Screen shop_ammo;
    Screen shop_skill;
    int col_r,col_g,col_b;
    D3DCOLOR font_surf[512 * 84];
    Font fixedSys;
    char buffer[64];

};
