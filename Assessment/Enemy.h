#pragma once
#include <string>
using namespace std;
class Enemy
{
public:
	//data
	string m_enemyType;

	//stats
	unsigned int m_healthPoints{ 100 };
	unsigned int m_attackPoints{ 100 };
	float m_movementSpeed{ 3.5f };

	//methods
	void loseHealth(int healthAmount);

	void attackPlayer();

	void enemyDeath();
private:

};

