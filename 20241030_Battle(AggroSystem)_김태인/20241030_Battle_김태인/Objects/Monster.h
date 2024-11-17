#pragma once
class Monster :public Creature
{
public:
	Monster();
	Monster(string name, int hp, int atk, string tribe);
	~Monster();

	void SetMonster(string name, int hp, int atk);

	void SetMonsterTribe(string name);
	string GetMonsterTribe();

protected:
	string _tribe;
};

