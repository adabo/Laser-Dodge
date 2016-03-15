#include "Trigonometry.h"
#include "Keyboard.h"
#include "D3DGraphics.h"

class Subject
{
public:
    void AddObserver(){}
};

class Observer
{
public:
    void OnNotify(){}
};

class Entity
{
public:
    virtual void Update(KeyboardClient &Kbd, float Dt) = 0;
    virtual void Update(float Dt) = 0;
    virtual void Draw(D3DGraphics &Gfx) = 0;
protected:
    float x, y,
          velocity,
          hp,
          damage,
          shield;
    bool  is_alive;
    int   width, height
};

class Enemy : public Entity
{
public:
    friend Physics;
    Enemy(int X, int Y)
    {
        x        = X;
        y        = Y;
        is_alive = true;
        hp       = 50.0f;
        damage   = 5.0f;
        shield   = 5.0f;
    }
};

class Laser : public Entity
{
public:
    Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage)
    :   x        (X)
        y        (Y)
        velocity (900)
        cos_x    (Cos_X)
        sin_y    (Sin_Y)
        is_alive (true)
        damage   (Damage)
    {}

    void Update(float Dt)
    {
        if(lasers.size() != 0)
        {
            // Temporary use 0 to get global laser speed
            // since all lasers carry same speed
            frame_step = velocity * Dt;
            for (auto &laser : lasers)
            {
                lasers.x += frame_step * lasers.cos_x;
                lasers.y += frame_step * lasers.sin_y;
            }
        }
    }

    void Draw()
    {
        for (auto &laser : lasers)
        {
            Gfx.PutPixel(laser.x, laser.y, 255, 255, 255);
        }
    }

    void AddLaser(int MouseX, int MouseY)
    {
        float rise       = 9.0f;
        float hypotenuse       = trg.GetHypotenuse(x, y, MouseX, MouseY);
        float cos_x            = trg.GetCosX(x, MouseX, hypotenuse);
        float sin_y            = trg.GetSinY(y, MouseY, hypotenuse);
        laser.push_back(Laser(x, y, cos_x, sin_y));
    }
private:
    float cos_x, sin_y;
    std::vector<Laser> lasers;
};

class Player : public Entity
{
public:
    friend Physics;
    Player()
    {
        is_alive = true;
        width    = 20;
        height   = 20;
        x        = 400;
        y        = 300;
        hp       = 50.0f;
        damage   = 1.0f;
        shield   = 1.0f;
    }

    void Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
    {
        float frame_step = speed * Dt;
        if (Kbd.AIsPressed())
        {
            x -= frame_step;
        }
        if (Kbd.DIsPressed())
        {
            x += frame_step;
        }
        if (Kbd.WIsPressed())
        {
            y -= frame_step;
        }
        if (Kbd.SIsPressed())
        {
            y += frame_step;
        }

        if (Mouse.IsInWindow())
        {
            mouse_x = Mouse.GetMouseX();
            mouse_y = Mouse.GetMouseY();
            SetAimDirection(mouse_x, mouse_y);
            if(Mouse.LeftIsPressed())
            {
                if(!mouse_is_pressed)
                {
                    mouse_is_pressed = true;
                    // Why do I need Shoot()?
                    laser.AddLaser(mouse_x, mouse_y);
                }
            }
            else
            {
                mouse_is_pressed = false;
            }
        }

        laser.Update(MouseX, MouseY, Dt);
    }

    void UpdateLaser(x, y, cos_x, sin_y, float Frame_Step)
    {
        for (auto &laser : lasers)
        {
            Frame_Step = laser[0].speed * Dt;
            int size = laser.size();
            for(int i = 0; i < size; ++i)
            {
                laser[i].x += frame_step * laser[i].cos_x;
                laser[i].y += frame_step * laser[i].sin_y;
            }

        }
    }

    void SetAimDirection(int MouseX, int MouseY)
    {
        float hypotenuse  = trg.GetHypotenuse(x, y, MouseX, MouseY);
        float theta       = trg.ThetaFromSin(y - MouseY, hypotenuse);
        float adjacent   = 9.0f;
        float opposite   = 9.0f;

        if (MouseY > y)
        {
            opposite = -opposite;
            adjacent = -adjacent;
        }
        if (MouseX < x)
        {
            opposite = -opposite;
            adjacent = -adjacent;
        }

        if(theta > 44 && theta < 46)
            theta = theta;
        
        // top
        if (theta >= 45 && theta <= 90)
        {
            aim_displacement = trg.AdjacentFromOpposite(opposite, theta);
            aim_side = AIMTOP;
        }
        // right
        else if (theta <= 45 && theta >= -45 && MouseX >= x)
        {
            aim_displacement = trg.OppositeFromAdjacent(adjacent, theta);
            if (MouseY > y)
            {
                aim_displacement = -aim_displacement;
            }
            aim_side = AIMRIGHT;
        }
        // bottom
        else if (theta <= -45 && theta >= -90)
        {
            aim_displacement = trg.AdjacentFromOpposite(opposite, theta);
            aim_side = AIMBOTTOM;
        }
        // left
        else if (theta >= -45 && theta <= 45 && MouseY <= x)
        {
            aim_displacement = trg.OppositeFromAdjacent(adjacent, theta);
            if (MouseY > y)
            {
                aim_displacement = -aim_displacement;
            }
            aim_side = AIMLEFT;
        }
    }

    void Draw(D3DGraphics &Gfx)
    {
        Gfx.DrawRectOutline(x - (width / 2), y - (height / 2),
                            x + (width / 2), y + (height / 2),
                            D3DCOLOR_XRGB(255, 255, 255));
    }
private:
    std::vector<Laser> lasers;
    AIMSIDE aim_side;
    int mouse_x, mouse_y;
    float aim_displacement; 
    Trigonometry trg;
};

class Spawner
{
public:
    void Update(std::vector<Entity> &Entities)
    {
        CheckIsAlive(Entities)
    }

    void CheckIsAlive(std::vector<Entity> &Entities)
    {
        // Spawner doesn't care which entity it's
        // checking since the entities will hold
        // their own hp/dmg/shield
        for (auto &entity : Entities)
        {
            if (entity.hp <= 0)
            {
                entity.is_alive = false;
            }
        }
    }

    void SetPlayerAlive(Player &ThisPlayer)
    {
        if (!ThisPlayer.is_alive)
        {
            ThisPlayer.is_alive = true;
        }
    }
};

class Physics
{
public:
    Update(std::vector<Entity> &Entities)
    {
        CollisionCheck(Entities);
    }

    CollisionCheck(Player &ThisPlayer, Enemy &ThisEnemy, Laser &ThisLaser)
    {
        // Check player against enemies
        for (auto &enemy : ThisEnemy.enemies)
        {
           if ((int)ThisPlayer.x + ThisPlayer.width > enemy.x &&
               (int)ThisPlayer.x <(int) enemy.x + enemy.width &&
               (int)ThisPlayer.y + ThisPlayer.height > (int)enemy.y &&
               (int)ThisPlayer.y < (int)enemy.y + enemy.height)
           {}

        }
    }
};

class GameManager
{
private:
    GameManager()
    {
        entities.push_back(&player);
        entities.push_back(&enemies);
    }

    void Update(KeyboardClient &Kbd, float Dt)
    {
        player.Update(Kbd, Mouse, Dt);
        physics.Update(entities);
        spawner.Update(entities);
    }

    void Draw()
    {}
private:
    Player player;
    Enemy enemies;
    std::vector<Entity*> entities;
    Physics physics;
    Spawner spawner;
};