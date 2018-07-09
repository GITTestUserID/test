#pragma once
#include "Player.h"

class Player1 :	public Player
{
private:
	bool aliveChek=true;
	int strength;

public:
	Player1();
	~Player1();

	void Init();
	bool isAlive() { return aliveChek; };
	int GetCondition();
	void SetDamage(int dm);
	JANKEN Attack();
};

