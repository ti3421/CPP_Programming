#pragma once
class Archer :public Player
{
public:
	Archer();
	Archer(string name,int criticalpercent);
	~Archer();
	void SetArcher(string name, int hp, int atk);

	virtual int Attack(shared_ptr<Creature> p)override;

	bool isCritical();


private:
	int _criticalpercent;
};

