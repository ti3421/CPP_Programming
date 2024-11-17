#pragma once

class Creature : public enable_shared_from_this<Creature>
{
public:
	Creature();
	Creature(string name, int hp, int atk);
	~Creature();

	void SetCreature(string name, int hp, int atk);

	string GetCreatureName();
	void SetCreatureName(string name);

	int GetCreatureHp();
	void SetCreatureHp(int hp);

	int GetCreatureAtk();
	void SetCreatureAtk(int atk);

	int GetCreatureMaxHp();

	void TakeDamage(int amount);

	virtual int Attack(shared_ptr<Creature> p) abstract;

	bool IsDead();

	void PrintInfo();

protected:
	string _name;
	int _hp;
	int _atk;
	int _maxHp;
	int _dex;
};
