#include "StateShop.h"

StateShop::StateShop()
{
    tx_st_upgrades.upgrades(338, 200);
    tx_st_upgrades.ship(370, 285);
    tx_st_upgrades.weapons(346, 312);
    tx_st_upgrades.skills(354, 368);
}

void StateShop::Update(GameManager &Mgr)
{
    if (player clicks up speed)
    {
        Upgrade();
    }
    if (player clicks up speed)
    {
        Upgrade();
    }
    if (player clicks up speed)
    {
        Upgrade();
    }
    if (player clicks up speed)
    {
        Upgrade();
    }
    if (player clicks up speed)
    {
        Upgrade();
    }
    if (player clicks up speed)
    {
        Upgrade();
    }
}

void StateShop::UpgradeSpeed(Player &ThisPlayer)
{
    ThisPlayer.money -= 20;
}

void StateShop::UpgradeDamage(Player &ThisPlayer)
{
    ThisPlayer.money -= 20;
}

void StateShop::UpgradeAccel(Player &ThisPlayer)
{
    ThisPlayer.money -= 20;
}

void StateShop::UpgradeShield(Player &ThisPlayer)
{
    ThisPlayer.money -= 20;
}

void StateShop::UpgradeMiss_enemy(Player &ThisPlayer)
{
    ThisPlayer.money -= 20;
}

void StateShop::UpgradeMiss_shot(Player &ThisPlayer)
{
    ThisPlayer.money -= 20;
}

void StateShop::Draw(GameManager &Mgr)
{
    switch(Selection)
    {
        case SHIP:
            DrawShipUpgrades(Mgr.gfx);
        break;
        case WEAPON:
            DrawWeaponUpgrades(Mgr.gfx);
        break;
        case AMMO:
            DrawAmmoUpgrades(Mgr.gfx);
        break;
        case SKILL:
            DrawSkillUpgrades(Mgr.gfx);
        break;
    }
}
void StateShop::DrawShipUpgrades(D3DGraphics &Gfx)
{}

void StateShop::DrawWeaponUpgrades(D3DGraphics &Gfx)
{}

void StateShop::DrawAmmoUpgrades(D3DGraphics &Gfx)
{}

void StateShop::DrawSkillUpgrades(D3DGraphics &Gfx)
{}

bool StateShop::MouseClickedBox(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X && MX <= X + W &&
            MY >= Y && MY <= Y + H);
}
