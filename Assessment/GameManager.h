#pragma once


class Player;

class GameManager
{
private:
    GameManager() {};
    ~GameManager() {};

public:
    static GameManager& instance()
    {
        static GameManager INSTANCE;
        return INSTANCE;
    }

    Player* player = nullptr;
};

