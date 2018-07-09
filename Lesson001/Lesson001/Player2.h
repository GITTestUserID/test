#pragma once
#include "Player.h"

class Player2 :	public Player
{
private:
	bool aliveChek = true;
	int strength;

public:
	Player2();
	~Player2();

	void Init();
	bool isAlive() { return aliveChek; };
	int GetCondition();
	void SetDamage(int dm);
	JANKEN Attack();
};

