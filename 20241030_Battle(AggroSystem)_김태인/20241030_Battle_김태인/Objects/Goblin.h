#pragma once
class Goblin :public Monster
{
public:
	Goblin(string name);
	~Goblin();

	void SetGoblin(string name, int hp, int atk);

	virtual int Attack(shared_ptr<Creature> p) override;

	bool HalfHp();
};

