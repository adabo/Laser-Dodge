class Subject
{
public:
    void AddObserver(){}
};

class Observer
{
public:
    OnNotify(){}
};

class Player
{
public:
    Player() : is_alive(true){}

    void Update()
    {
        CheckHP();
        Move();
    }

    void Move(KeyboardClient &Kbd, float Dt)
    {
        /*Movement code here*/
    }

    void Draw(D3DGraphics &Gfx)
    {
        if (is_alive)
        {
            /*Draw code here*/
        }
    }

    float GetHP()
    {
        return hp;
    }

    bool GetIsAlive()
    {
        return is_alive;
    }

    void CheckIsAlive()
    {
        if (hp <= 0)
        {
            SetIsAlive(false);
        }
    }

    void SetHP(float Hp)
    {
        hp = Hp;
    }

    void SetIsAlive(bool State)
    {
        is_alive = State;
    }
private:
    float x, y,
          velocity,
          hp;
    bool  is_alive;
};

class Spawner
{
public:
    void SetPlayerAlive(Player &ThisPlayer)
    {
        if (!ThisPlayer.is_alive)
        {
            ThisPlayer.SetIsAlive(true);
        }
    }
};