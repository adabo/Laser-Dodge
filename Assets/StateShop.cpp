#include "StateShop.h"
#include "GameManager.h"

StateShop::StateShop()
:   shop_state (MAIN),
    shop_main  (370, 88,   /*Shop*/
                80,  84,   /*Back*/
                338, 200,  /*Category*/
                270, 285,  /*Upgrade1*/
                346, 312,  /*Upgrade2*/
                354, 368), /*Upgrade3*/
    shop_ship  (370, 88,
                80,  84,
                367, 200,
                362, 256,
                306, 284,
                354, 312),
    shop_weapon(370, 88,
                80,  84,
                344, 200,
                354, 284),
    shop_ammo  (370, 88,
                80,  84,
                370, 200),
    shop_skill (370, 88,
                80,  84,
                352, 199,
                226, 284,
                242, 312)
{}

void StateShop::Update(GameManager &Mgr)
{
    switch(shop_state)
    {
        case MAIN:
            UpdateShopMain(Mgr.s_state, Mgr.player, Mgr.mouse);
        case SHIP:
            UpdateShopShip(Mgr.player, Mgr.mouse);
        break;
        case WEAPON:
            UpdateShopWeapon(Mgr.player, Mgr.mouse);
        break;
        case AMMO:
            UpdateShopAmmo(Mgr.player, Mgr.mouse);
        break;
        case SKILL:
            UpdateShopSkill(Mgr.player, Mgr.mouse);
        break;
    }
}

void StateShop::Draw(GameManager &Mgr)
{
    switch(shop_state)
    {
        case MAIN:
            DrawMain(Mgr.gfx);
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

void StateShop::UpdateShopMain(ScreenState SState, Player &ThisPlayer, MouseClient &Mouse)
{
    // Check main
    int mx = Mouse.GetMouseX();
    int my = Mouse.GetMouseY();
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            SState.states = GAME;
        }
    }
    // Check ship
    else if (MouseHoverOver(mx, my, 370, 285, 64, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            shop_state = SHIP;
            UpdateShopShip(ThisPlayer, Mouse);
        }
    }
    // Check weapon
    else if (MouseHoverOver(mx, my, 346, 312, 108, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            shop_state = WEAPON;
            UpdateShopWeapon(ThisPlayer, Mouse);
        }
    }
    // Check ammo
    else if (MouseHoverOver(mx, my, 368, 336, 64, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            shop_state = AMMO;
            UpdateShopAmmo(ThisPlayer, Mouse);
        }
    }
    // Check skill
    else if (MouseHoverOver(mx, my, 354, 368, 64, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            shop_state = SKILL;
            UpdateShopSkill(ThisPlayer, Mouse);
        }
    }
}

void StateShop::UpdateShopShip(Player &ThisPlayer, MouseClient &Mouse)
{
    int mx = Mouse.GetMouseX();
    int my = Mouse.GetMouseY();
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            shop_state = MAIN;
        }
    }
    // Check speed
    if (MouseHoverOver(mx, my, 362, 256, 76, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            UpgradeSpeed(ThisPlayer);
        }
    }
    // Check acceleration
    if (MouseHoverOver(mx, my, 306, 284, 188, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            UpgradeAccel(ThisPlayer);
        }
    }
    // Check shield 
    if (MouseHoverOver(mx, my, 354, 312, 96, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            UpgradeShield(ThisPlayer);
        }
    }
}

void StateShop::UpdateShopWeapon(Player &ThisPlayer, MouseClient &Mouse)
{
    int mx = Mouse.GetMouseX();
    int my = Mouse.GetMouseY();
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            shop_state = MAIN;
        }
    }
    // Check damage
    if (MouseHoverOver(mx, my, 362, 256, 76, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            UpgradeDamage(ThisPlayer);
        }
    }
}

void StateShop::UpdateShopAmmo(Player &ThisPlayer, MouseClient &Mouse)
{}

void StateShop::UpdateShopSkill(Player &ThisPlayer, MouseClient &Mouse)
{
    int mx = Mouse.GetMouseX();
    int my = Mouse.GetMouseY();
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            shop_state = MAIN;
        }
    }
    // Check miss enemy
    if (MouseHoverOver(mx, my, 362, 256, 76, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            UpgradeMissEnemy(ThisPlayer);
        }
    }
    // Check miss Shot
    if (MouseHoverOver(mx, my, 362, 256, 76, 28))
    {
        if (Mouse.LeftIsPressed())
        {
            UpgradeMissShot(ThisPlayer);
        }
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

void StateShop::UpgradeMissEnemy(Player &ThisPlayer)
{
    ThisPlayer.money -= 20;
}

void StateShop::UpgradeMissShot(Player &ThisPlayer)
{
    ThisPlayer.money -= 20;
}

void StateShop::DrawMain(D3DGraphics &Gfx)
{

    sprintf(buffer, "<=");
    fixedSys.DrawString(buffer, 80, 84, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    sprintf(buffer, "SHOP");
    fixedSys.DrawString(buffer, 370, 88, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    sprintf(buffer, "UPGRADES");
    fixedSys.DrawString(buffer, 338, 200, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    sprintf(buffer, "SHIP");
    fixedSys.DrawString(buffer, 370, 285, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    sprintf(buffer, "WEAPONS");
    fixedSys.DrawString(buffer, 346, 312, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    sprintf(buffer, "AMMO");
    fixedSys.DrawString(buffer, 368, 336, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
    sprintf(buffer, "SKILLS");
    fixedSys.DrawString(buffer, 354, 368, &fixedSys, D3DCOLOR_XRGB(100, 100, 100), Gfx);
}

void StateShop::DrawShipUpgrades(D3DGraphics &Gfx)
{}

void StateShop::DrawWeaponUpgrades(D3DGraphics &Gfx)
{}

void StateShop::DrawAmmoUpgrades(D3DGraphics &Gfx)
{}

void StateShop::DrawSkillUpgrades(D3DGraphics &Gfx)
{}

bool StateShop::MouseHoverOver(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X && MX <= X + W &&
            MY >= Y && MY <= Y + H);
}
