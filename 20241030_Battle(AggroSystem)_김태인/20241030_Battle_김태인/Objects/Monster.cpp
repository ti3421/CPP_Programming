#include "../framework.h"
#include "Monster.h"


Monster::Monster() : Creature("", 0, 0), _tribe("") {};
Monster::Monster(string name, int hp, int atk, string tribe) : Creature(name, hp, atk), _tribe(tribe) {};
Monster::~Monster() {};

void Monster::SetMonster(string name, int hp, int atk) {
	SetCreatureName(name);
	SetCreatureHp(hp);
	SetCreatureAtk(atk);
}

void Monster::SetMonsterTribe(string name) { 
	auto self = dynamic_pointer_cast<Monster>(shared_from_this());
	self->_tribe = name; };

string Monster::GetMonsterTribe() {
	auto self = dynamic_pointer_cast<Monster>(shared_from_this());
	return self->_tribe; };

