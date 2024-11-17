#include "../framework.h"
#include "Archer.h"


Archer::Archer() : Player("", 0, 0, "Archer"),_criticalpercent(0) {};
Archer::Archer(string name, int criticalpercent) : Player(name, 400 + rand() % 50, 25 + rand() % 10, "Archer"), _criticalpercent(criticalpercent) { 
	_dex = rand() % 10+1; 
};
Archer::~Archer() {};

void Archer::SetArcher(string name, int hp, int atk) {
	auto self = dynamic_pointer_cast<Archer>(shared_from_this());
	self->_name = name;
	self->_hp = hp;
	self->_atk = atk;
}

int Archer::Attack(shared_ptr<Creature> p) {
	auto self = dynamic_pointer_cast<Archer>(shared_from_this());
	if (self->isCritical()) {
		cout << "Critical Shot!(Crictical rate: " << self->_criticalpercent << "%)" << endl;
		int TotalDamage = self->_atk * 2 + rand() % (self->_dex);
		p->TakeDamage(TotalDamage);
		cout << p->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
		return TotalDamage;
	}
	else {
		int TotalDamage = self->_atk + rand() % (self->_dex);
		p->TakeDamage(TotalDamage);
		cout << p->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
		return TotalDamage;
	}
}

bool Archer::isCritical()
{
	auto self = dynamic_pointer_cast<Archer>(shared_from_this());
	if (rand() % 100 + 1 <= self->_criticalpercent)return true;
	else return false;
}
