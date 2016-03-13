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
    Laser::Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage)
    {
        x        = X;
        y        = Y;
        velocity = 900;
        cos_x    = Cos_X;
        sin_y    = Sin_Y;
        is_alive = true;
        damage   = Damage;
    }

    void Update()
    {
        /*Update code here*/
    }

    void Draw()
    {
        /*Draw code here*/
    }
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
                    SetLaserDirection(mouse_x, mouse_y);
                }
            }
            else
            {
                mouse_is_pressed = false;
            }

            if(laser.size() != 0)
            {
                // Temporary use 0 to get global laser speed
                // since all lasers carry same speed
                frame_step = laser[0].speed * Dt;
                int size = laser.size();
                for(int i = 0; i < size; ++i)
                {
                    laser[i].x += frame_step * laser[i].cos_x;
                    laser[i].y += frame_step * laser[i].sin_y;
                    UpdateLaser
                }
            }
        }

        UpdateLaser(Dt);
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

    void Draw(D3DGraphics &Gfx)
    {
        /*Draw code here*/
    }
private:
    std::vector<Laser> lasers;
};

class Spawner
{
public:
    void CheckIsAlive()
    {
        // Spawner doesn't care which entity it's
        // checking since the entities will hold
        // their own hp/dmg/shield
        for (auto &entity : entities)
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
private:
    std::vector<Entity
};

class Physics
{
public:
    Update(Player &ThisPlayer, Enemy &ThisEnemy, Laser &ThisLaser)
    {
        CollisionCheck(ThisPlayer, ThisEnemy, ThisLaser);
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
    void Update()
    {}
    void Spawn()
    {}
    void Draw()
    {

    }
private:
    Player player;
    Spawner spawner;
};