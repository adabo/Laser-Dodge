#pragma once
// #include "Common.h"
// #include "D3DGraphics.h"
#include <vector>
// #include "Font.h"
// #include "Mouse.h"
#include "Text.h"

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

    enum Upgrades
    {
        SPEED, ACCELERATION, SHIELD,
        DAMAGE,
        ENEMYMISSED, SHOTSMISSED
    };

public:
    StateShop(GameManager &MGR);
    void Update();
    void Draw();
    void UpdateShopMain();
    void UpdateShopShip();
    void UpdateShopWeapon();
    void UpdateShopAmmo();
    void UpdateShopSkill();
    void UpgradeSpeed();
    void UpgradeDamage();
    void UpgradeAccel();
    void UpgradeShield();
    void UpgradeMissEnemy();
    void UpgradeMissShot();
    void DrawMain();
    void DrawShipUpgrades();
    void DrawWeaponUpgrades();
    void DrawAmmoUpgrades();
    void DrawSkillUpgrades();
    bool MouseHoverOver(int MX, int MY, int X, int Y, int W, int H);
private:
    GameManager &mgr;
    ShopStates shop_state;
    std::vector<Text> shop_main;
    std::vector<Text> shop_ship;
    std::vector<Text> shop_weapon;
    std::vector<Text> shop_ammo;
    std::vector<Text> shop_skill;
    bool tab_is_pressed;
};
