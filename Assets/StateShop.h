#pragma once
#include "Common.h"
#include "D3DGraphics.h"
#include "Font.h"
#include "Mouse.h"

class Player;
class ScreenState;
class GameManager;

class StateShop
{
public:
    enum ShopStates
    {
        MAIN, SHIP, WEAPON, AMMO, SKILL
    };
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
        Element upgrade4;
    };
public:
    StateShop();
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr);
    void UpdateShopMain(ScreenState SState, Player &ThisPlayer, MouseClient &Mouse);
    void UpdateShopShip(Player &ThisPlayer, MouseClient &Mouse);
    void UpdateShopWeapon(Player &ThisPlayer, MouseClient &Mouse);
    void UpdateShopAmmo(Player &ThisPlayer, MouseClient &Mouse);
    void UpdateShopSkill(Player &ThisPlayer, MouseClient &Mouse);
    void UpgradeSpeed(Player &ThisPlayer);
    void UpgradeDamage(Player &ThisPlayer);
    void UpgradeAccel(Player &ThisPlayer);
    void UpgradeShield(Player &ThisPlayer);
    void UpgradeMissEnemy(Player &ThisPlayer);
    void UpgradeMissShot(Player &ThisPlayer);
    void DrawMain(D3DGraphics &Gfx);
    void DrawShipUpgrades(D3DGraphics &Gfx);
    void DrawWeaponUpgrades(D3DGraphics &Gfx);
    void DrawAmmoUpgrades(D3DGraphics &Gfx);
    void DrawSkillUpgrades(D3DGraphics &Gfx);
    bool MouseHoverOver(int MX, int MY, int X, int Y, int W, int H);
private:
    ShopStates shop_state;
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
