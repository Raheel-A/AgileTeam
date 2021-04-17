#pragma once
class Player
{
public: 
	//stats
	unsigned int m_healthPoints{ 100 };
	unsigned int m_attackPoints{ 50 };
	float m_movementSpeed{ 3.5f };

	//checks
	bool hasDied;

	//methods
	void loseHealth(int healthAmount);
	void gainHealth(int healthAmount);

	void playerAttack();

	void playerDeath();
private:

};

