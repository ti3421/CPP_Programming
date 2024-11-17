#pragma once
class Mage :public Player
{
public:
	Mage();
	Mage(string name);
	~Mage();
	void SetMage(string name, int hp, int atk);

	bool HalfHp();

	virtual int Attack(shared_ptr<Creature> p)override;
};

