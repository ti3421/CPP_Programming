#include "../framework.h"
#include "Creature.h"

Creature::Creature() : _name(""), _hp(0), _atk(0), _maxHp(0),_dex(0) {};
Creature::Creature(string name, int hp, int atk) : _name(name), _hp(hp), _atk(atk), _maxHp(hp) {};
Creature::~Creature() {};

void Creature::SetCreature(string name, int hp, int atk) {
	auto self = shared_from_this();
	self->_name = name;
	self->_hp = hp;
	self->_atk = atk;
	self->_maxHp = hp;
}

string Creature::GetCreatureName() { return _name; };
void Creature::SetCreatureName(string name) { shared_from_this()->_name = name; };

int Creature::GetCreatureHp() { return _hp; };
void Creature::SetCreatureHp(int hp) { shared_from_this()->_hp = hp; };

int Creature::GetCreatureAtk() { return _atk; };
void Creature::SetCreatureAtk(int atk) { shared_from_this()->_atk = atk; };

int Creature::GetCreatureMaxHp() { return _maxHp; };

void Creature::TakeDamage(int amount) {
	_hp -= amount;
	if (_hp < 0)
		_hp = 0;
	return;
}

int Creature::Attack(shared_ptr<Creature> p) {
	p->TakeDamage(_atk);
	cout << p->GetCreatureName() << " took " << shared_from_this()->_atk << " damages." << endl;
	return _atk;
}

bool Creature::IsDead() {
	if (_hp <= 0) {
		return true;
	}
	return false;
}

void Creature::PrintInfo() {
	if (shared_from_this()->_hp < 0) { cout << "Name: " << shared_from_this()->_name << ", Hp: 0" << endl; }
	else { cout << "Name: " << shared_from_this()->_name << ", Hp: " << shared_from_this()->_hp << endl; }
}
