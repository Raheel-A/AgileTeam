#pragma once


class Player;
class LevelData;
class Pathfinder;

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

    void UpdatePathfinder();

    Player* player = nullptr;
    LevelData* level = nullptr;
    Pathfinder* pathfinder = nullptr;
};

