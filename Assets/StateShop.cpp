#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "StateShop.h"
#include "GameManager.h"

StateShop::StateShop(GameManager &MGR)
:   main("MAIN", fixedSys, &MGR.D3DGraphics, ),
    dflt(100, 100, 100),
    back(100, 100, 100),
    ship(100, 100, 100),
    weap(100, 100, 100),
    ammo(100, 100, 100),
    skll(100, 100, 100),
    mgr(MGR),
    tab_is_pressed(false),
    left_is_pressed(false),
    shop_state (MAIN),
    shop_main  (370, 88,   /*Shop*/
                80,  84,   /*Back*/
                338, 200,  /*Category*/
                270, 280,  /*Upgrade1*/
                346, 336,  /*Upgrade2*/
                354, 364), /*Upgrade3*/
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
{
    fixedSys.LoadFont(&fixedSys, font_surf, "Fixedsys16x28.bmp", 16, 28, 32);
}

void StateShop::Update()
{
    if (mgr.kbd.TabIsPressed())
    {
        if (!tab_is_pressed)
        {
            tab_is_pressed = true;
        }
    }
    else
    {
        if (tab_is_pressed)
        {
            tab_is_pressed = false;
            mgr.s_state.states = GAME;
        }
    }

    switch(shop_state)
    {
        case MAIN:
            UpdateShopMain();
        break;
        case SHIP:
            UpdateShopShip();
        break;
        case WEAPON:
            UpdateShopWeapon();
        break;
        case AMMO:
            UpdateShopAmmo();
        break;
        case SKILL:
            UpdateShopSkill();
        break;
    }
}

void StateShop::Draw()
{
    switch(shop_state)
    {
        case MAIN:
            DrawMain();
        break;
        case SHIP:
            DrawShipUpgrades();
        break;
        case WEAPON:
            DrawWeaponUpgrades();
        break;
        case AMMO:
            DrawAmmoUpgrades();
        break;
        case SKILL:
            DrawSkillUpgrades();
        break;
    }
}

void StateShop::UpdateShopMain()
{
    // Check main
    int mx = mgr.mouse.GetMouseX();
    int my = mgr.mouse.GetMouseY();
    // col_r = 100, col_g = 100, col_b = 100;
    back = {100, 100, 100};
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        // col_r = 30, col_g = 99, col_b = 20;
        back = { 30, 99, 20 };
        if (mgr.mouse.LeftIsPressed())
        {
            if (!left_is_pressed)
            {
                left_is_pressed = true;
            }
        }
        else
        {
            if (left_is_pressed)
            {
                left_is_pressed = false;
                mgr.s_state.states = GAME;
            }
        }
    }
    // Check ship
    if (MouseHoverOver(mx, my, 370, 280, 64, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            shop_state = SHIP;
            UpdateShopShip();
        }
    }
    // Check weapon
    else if (MouseHoverOver(mx, my, 346, 308, 108, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            shop_state = WEAPON;
            UpdateShopWeapon();
        }
    }
    // Check ammo
    else if (MouseHoverOver(mx, my, 368, 336, 64, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            shop_state = AMMO;
            UpdateShopAmmo();
        }
    }
    // Check skill
    else if (MouseHoverOver(mx, my, 354, 364, 64, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            shop_state = SKILL;
            UpdateShopSkill();
        }
    }
}

void StateShop::UpdateShopShip()
{
    int mx = mgr.mouse.GetMouseX();
    int my = mgr.mouse.GetMouseY();
    col_r = 100, col_g = 100, col_b = 100;
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        col_r = 30, col_g = 99, col_b = 20;
        if (mgr.mouse.LeftIsPressed())
        {
            if (!left_is_pressed)
            {
                left_is_pressed = true;
            }
        }
        else
        {
            if (left_is_pressed)
            {
                left_is_pressed = false;
                shop_state = MAIN;
            }
        }
    }
    // Check speed
    else if (MouseHoverOver(mx, my, 362, 256, 76, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            UpgradeSpeed();
        }
    }
    // Check acceleration
    else if (MouseHoverOver(mx, my, 306, 284, 188, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            UpgradeAccel();
        }
    }
    // Check shield 
    else if (MouseHoverOver(mx, my, 354, 312, 96, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            UpgradeShield();
        }
    }
}

void StateShop::UpdateShopWeapon()
{
    int mx = mgr.mouse.GetMouseX();
    int my = mgr.mouse.GetMouseY();
    col_r = 100, col_g = 100, col_b = 100;
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        col_r = 30, col_g = 99, col_b = 20;
        if (mgr.mouse.LeftIsPressed())
        {
            if (!left_is_pressed)
            {
                left_is_pressed = true;
            }
        }
        else
        {
            if (left_is_pressed)
            {
                left_is_pressed = false;
                shop_state = MAIN;
            }
        }
    }
    // Check damage
    else if (MouseHoverOver(mx, my, 362, 256, 76, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            UpgradeDamage();
        }
    }
}

void StateShop::UpdateShopAmmo()
{
    int mx = mgr.mouse.GetMouseX();
    int my = mgr.mouse.GetMouseY();
    col_r = 100, col_g = 100, col_b = 100;
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        col_r = 30, col_g = 99, col_b = 20;
        if (mgr.mouse.LeftIsPressed())
        {
            if (!left_is_pressed)
            {
                left_is_pressed = true;
            }
        }
        else
        {
            if (left_is_pressed)
            {
                left_is_pressed = false;
                shop_state = MAIN;
            }
        }
    }
}

void StateShop::UpdateShopSkill()
{
    int mx = mgr.mouse.GetMouseX();
    int my = mgr.mouse.GetMouseY();
    col_r = 100, col_g = 100, col_b = 100;
    // Check back
    if (MouseHoverOver(mx, my, 80, 84, 32, 28))
    {
        col_r = 30, col_g = 99, col_b = 20;
        if (mgr.mouse.LeftIsPressed())
        {
            if (!left_is_pressed)
            {
                left_is_pressed = true;
            }
        }
        else
        {
            if (left_is_pressed)
            {
                left_is_pressed = false;
                shop_state = MAIN;
            }
        }
    }
    // Check miss enemy
    else if (MouseHoverOver(mx, my, 362, 256, 76, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            UpgradeMissEnemy();
        }
    }
    // Check miss Shot
    else if (MouseHoverOver(mx, my, 362, 256, 76, 28))
    {
        if (mgr.mouse.LeftIsPressed())
        {
            UpgradeMissShot();
        }
    }
}

void StateShop::UpgradeSpeed()
{
    mgr.player.money -= 20;
}

void StateShop::UpgradeDamage()
{
    mgr.player.money -= 20;
}

void StateShop::UpgradeAccel()
{
    mgr.player.money -= 20;
}

void StateShop::UpgradeShield()
{
    mgr.player.money -= 20;
}

void StateShop::UpgradeMissEnemy()
{
    mgr.player.money -= 20;
}

void StateShop::UpgradeMissShot()
{
    mgr.player.money -= 20;
}

// You should make a function that will take any text you put
// and automatically position it wherever you want.
// Middle aligned. Left justafied. Right justified. You can do it.
// Use the same code that you used for the HP text. sprintf will give you
// the number of chars, then just multiply by 16pixels. Then use screenwidth
// and BAM!
void StateShop::DrawMain()
{
    // sprintf(buffer, "<=");
    // fixedSys.DrawString(buffer, 80, 84, &fixedSys, D3DCOLOR_XRGB(back.r, back.g, back.b), mgr.gfx);
    // sprintf(buffer, "SHOP");
    // fixedSys.DrawString(buffer, 370, 88, &fixedSys, D3DCOLOR_XRGB(dflt.r, dflt.g, dflt.b), mgr.gfx);
    // sprintf(buffer, "UPGRADES");
    // fixedSys.DrawString(buffer, 338, 200, &fixedSys, D3DCOLOR_XRGB(dflt.r, dflt.g, dflt.b), mgr.gfx);
    // sprintf(buffer, "SHIP");
    // fixedSys.DrawString(buffer, 370, 280, &fixedSys, D3DCOLOR_XRGB(ship.r, ship.g, ship.b), mgr.gfx);
    // sprintf(buffer, "WEAPONS");
    // fixedSys.DrawString(buffer, 346, 308, &fixedSys, D3DCOLOR_XRGB(weap.r, weap.g, weap.b), mgr.gfx);
    // sprintf(buffer, "AMMO");
    // fixedSys.DrawString(buffer, 368, 336, &fixedSys, D3DCOLOR_XRGB(ammo.r, ammo.r, ammo.r), mgr.gfx);
    // sprintf(buffer, "SKILLS");
    // fixedSys.DrawString(buffer, 354, 364, &fixedSys, D3DCOLOR_XRGB(skll.r, skll.r, skll.r), mgr.gfx);

}

void StateShop::DrawShipUpgrades()
{
    sprintf(buffer, "<=");
    fixedSys.DrawString(buffer, 80, 84, &fixedSys, D3DCOLOR_XRGB(col_r, col_g, col_b), mgr.gfx);
    sprintf(buffer, "SHOP");
    fixedSys.DrawString(buffer, 370, 88, &fixedSys, D3DCOLOR_XRGB(col_r, col_g, col_b), mgr.gfx);
}

void StateShop::DrawWeaponUpgrades()
{
    sprintf(buffer, "<=");
    fixedSys.DrawString(buffer, 80, 84, &fixedSys, D3DCOLOR_XRGB(col_r, col_g, col_b), mgr.gfx);
    sprintf(buffer, "SHOP");
    fixedSys.DrawString(buffer, 370, 88, &fixedSys, D3DCOLOR_XRGB(col_r, col_g, col_b), mgr.gfx);
}

void StateShop::DrawAmmoUpgrades()
{
    sprintf(buffer, "<=");
    fixedSys.DrawString(buffer, 80, 84, &fixedSys, D3DCOLOR_XRGB(col_r, col_g, col_b), mgr.gfx);
    sprintf(buffer, "SHOP");
    fixedSys.DrawString(buffer, 370, 88, &fixedSys, D3DCOLOR_XRGB(col_r, col_g, col_b), mgr.gfx);
}

void StateShop::DrawSkillUpgrades()
{
    sprintf(buffer, "<=");
    fixedSys.DrawString(buffer, 80, 84, &fixedSys, D3DCOLOR_XRGB(col_r, col_g, col_b), mgr.gfx);
    sprintf(buffer, "SHOP");
    fixedSys.DrawString(buffer, 370, 88, &fixedSys, D3DCOLOR_XRGB(col_r, col_g, col_b), mgr.gfx);
}

bool StateShop::MouseHoverOver(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X && MX <= X + W &&
            MY >= Y && MY <= Y + H);
}
