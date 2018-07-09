#pragma once
class Player
{
private:
	int strength = KAI;
public:
	Player();
	~Player();

	virtual void Init();

	virtual int GetCondition();
	virtual void SetDamage(int dm);
	virtual JANKEN Attack();
};

