#pragma once
class Knight :public Player
{
public:
	Knight();
	Knight(string name);
	~Knight();
	void SetKnight(string name, int hp, int atk);
	bool HalfHp();

	virtual int Attack(shared_ptr<Creature> p)override;
};

