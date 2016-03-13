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
    void Update()
    {
        CheckHP();
        Move();
    } 

    void Draw(D3DGraphics &Gfx)
    {
        if (is_alive)
        {
            /*Draw code here*/
        }
    }

    void CheckHP()
    {
        if (hp <= 0)
        {
            SetIsAlive(false);
        }
    }
};

class Spawner
{
public:
    SetPlayerAlive(Player &ThisPlayer)
    {
        if (!ThisPlayer.is_alive)
        {
            ThisPlayer.SetIsAlive(true);
        }
    }
};