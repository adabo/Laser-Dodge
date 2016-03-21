#pragma once
#include "D3DGraphics.h"
#include "Font.h"

class GameManager;

class StateShop
{
public:
    StateShop();
    class TextXY
    {
    public:
        TextXY(int X, int Y);
        int x;
        int y;
    };
    enum Selection
    {
       SHIP,WEAPON,AMMO,SKILL 
    };
public:
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr);
    void UpgradeSpeed();
    void UpgradeDamage();
    void UpgradeAccel();
    void UpgradeShield();
    void UpgradeMiss_enemy();
    void UpgradeMiss_shot();
private:
    // Upgrades
    int up_screen_upgrades_x, up_screen_upgrades_y,
        up_screen)
    float up_speed,
          up_damage,
          up_accel,
          up_shield,
          up_miss_enemy,
          up_miss_shot;

    int col_r,col_g,col_b;
    D3DCOLOR font_surf[512 * 84];
    Font fixedSys;
    char buffer[64];
    TextXY up_screen;
};
