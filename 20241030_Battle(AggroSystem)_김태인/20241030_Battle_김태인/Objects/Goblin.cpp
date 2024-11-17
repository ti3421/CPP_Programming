#include "../framework.h"
#include "Goblin.h"


Goblin::Goblin(string name) : Monster(name, 50 + rand() % 5, 4 + rand() % 2, "Goblin") { 
	_dex = rand() % 2 + 1; 
};
Goblin::~Goblin() {};

void Goblin::SetGoblin(string name, int hp, int atk) {
	auto self = dynamic_pointer_cast<Goblin>(shared_from_this());
	self->_name = name;
	self->_hp = hp;
	self->_atk = atk;
}

bool Goblin::HalfHp() {
	auto self = dynamic_pointer_cast<Goblin>(shared_from_this());
	if (self->GetCreatureHp() > (self->GetCreatureMaxHp() / 2)) {
		return false;
	}
	else
		return true;
}

int Goblin::Attack(shared_ptr<Creature> p)
{
	auto self = dynamic_pointer_cast<Goblin>(shared_from_this());
	if (HalfHp() == true) {
		cout << "Golin gets half attack power when lower than half Hp." << endl;
		int TotalDamage = (_atk / 2) + (rand() % (self->_dex));
		p->TakeDamage(TotalDamage);
		cout << p->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
		return TotalDamage;
	}
	else {
		int TotalDamage = _atk + (rand() % (self->_dex));
		p->TakeDamage(TotalDamage);
		cout << p->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
		return TotalDamage;
	}
}
