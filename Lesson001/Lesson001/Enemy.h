#pragma once
class Enemy
{
private:
	int strength = 100;

public:
	Enemy();
	~Enemy();

	void Init();
	void Update();

	int GetCondition();
	void SetDamage(int dm);
};

