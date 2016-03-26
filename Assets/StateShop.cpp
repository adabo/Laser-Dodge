
#include "StateShop.h"
#include "GameManager.h"

StateShop::StateShop(GameManager &MGR)
:   mgr(MGR),
    tab_is_pressed(false),
    shop_state (MAIN),
    shop_main  ({   {"<=",                     80,  84 , Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"$",                      688, 28,  Text::FIXEDSYS, Text::GREEN, Text::GREEN},
                    {"SHOP",                   370, 88 , Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"UPGRADES",               338, 200, Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"SHIP",                   368, 280, Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"WEAPONS",                346, 308, Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"AMMO",                   368, 336, Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"SKILLS",                 354, 364, Text::FIXEDSYS, Text::GREY, Text::PINK}}),
    shop_ship  ({   {"<=",                     80,  84 , Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"$",                      688, 28,  Text::FIXEDSYS, Text::GREEN, Text::GREEN},
                    {"SHOP",                   370, 88 , Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"SHIP",                   368, 200, Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"SPEED",                  362, 256, Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"ACCELERATION",           306, 284, Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"SHIELD",                 354, 312, Text::FIXEDSYS, Text::GREY, Text::PINK}}),
    shop_weapon({   {"<=",                     80, 84  , Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"$",                      688, 28,  Text::FIXEDSYS, Text::GREEN, Text::GREEN},
                    {"SHOP",                   370, 88 , Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"WEAPONS",                344, 200, Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"DAMAGE",                 354, 284, Text::FIXEDSYS, Text::GREY, Text::PINK}}),
    shop_ammo  ({   {"<=",                     80, 84  , Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"$",                      688, 28,  Text::FIXEDSYS, Text::GREEN, Text::GREEN},
                    {"SHOP",                   370, 88 , Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"AMMO",                   370, 200, Text::FIXEDSYS, Text::GREY, Text::GREY}}),
    shop_skill ({   {"<=",                     80,  84,  Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"$",                      688, 28,  Text::FIXEDSYS, Text::GREEN, Text::GREEN},
                    {"SHOP",                   370, 88,  Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"SKILLS",                 352, 199, Text::FIXEDSYS, Text::GREY, Text::GREY},
                    {"MISSED ENEMIES PENALTY", 226, 284, Text::FIXEDSYS, Text::GREY, Text::PINK},
                    {"SHOTS MISSED PENALTY",   242, 312, Text::FIXEDSYS, Text::GREY, Text::PINK}})
{}

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
    for (auto &el : shop_main)
    {
        // Check mouse over
        if (el.Update(mgr.mouse))
        {
            if (el.GetStr() == "<=")
            {
                mgr.s_state.states = GAME;
            }
            else if (el.GetStr() == "SHIP")
            {
                shop_state = SHIP;
            }
            else if (el.GetStr() == "WEAPONS")
            {
                shop_state = WEAPON;
            }
            else if (el.GetStr() == "AMMO")
            {
                shop_state = AMMO;
            }
            else if (el.GetStr() == "SKILLS")
            {
                shop_state = SKILL;
            }
        }
    }
}

void StateShop::UpdateShopShip()
{
    for (auto &el : shop_ship)
    {
        if (el.Update(mgr.mouse))
        {
            if (el.GetStr() == "<=")
            {
                shop_state = MAIN;
            }
            else if (el.GetStr() == "SPEED")
            {
                UpgradeSpeed();
            }
            else if (el.GetStr() == "ACCELERATION")
            {
                UpgradeAccel();
            }
            else if (el.GetStr() == "SHIELD")
            {
                UpgradeShield();
            }
        }
    }
}

void StateShop::UpdateShopWeapon()
{
    for (auto &el : shop_weapon)
    {
        if (el.Update(mgr.mouse))
        {
            if (el.GetStr() == "<=")
            {
                shop_state = MAIN;
            }
            else if (el.GetStr() == "DAMAGE")
            {
                UpgradeDamage();
            }
        }
    } 
}

void StateShop::UpdateShopAmmo()
{
    for (auto &el : shop_ammo)
    {
        if (el.Update(mgr.mouse))
        {
            if (el.GetStr() == "<=")
            {
                shop_state = MAIN;
            }
        }
    }
}

void StateShop::UpdateShopSkill()
{
    for (auto &el : shop_skill)
    {
        if (el.Update(mgr.mouse))
        {
            if (el.GetStr() == "<=")
            {
                shop_state = MAIN;
            }
            else if (el.GetStr() == "ENEMYMISSSED")
            {
                UpgradeMissEnemy();
            }
            else if (el.GetStr() == "SHOTSMISSED")
            {
                UpgradeMissShot();
            }
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
    for (auto &el : shop_main)
    {
        el.Draw(mgr.gfx);
        el.SetColor(el.GetDC());
    }
}

void StateShop::DrawShipUpgrades()
{
    for (auto &el : shop_ship)
    {
        if (el.GetStr() == "<=" && el.GetR() != 100)
            el.GetR();
        el.Draw(mgr.gfx);
        el.SetColor(el.GetDC());
        el.GetR();
    }
}

void StateShop::DrawWeaponUpgrades()
{
    for (auto &el : shop_weapon)
    {
        el.Draw(mgr.gfx);
    }
}

void StateShop::DrawAmmoUpgrades()
{
    for (auto &el : shop_ammo)
    {
        el.Draw(mgr.gfx);
    }
}


void StateShop::DrawSkillUpgrades()
{
    for (auto &el : shop_skill)
    {
        el.Draw(mgr.gfx);
    }
}

bool StateShop::MouseHoverOver(int MX, int MY, int X, int Y, int W, int H)
{
    return (MX >= X && MX <= X + W &&
            MY >= Y && MY <= Y + H);
}
