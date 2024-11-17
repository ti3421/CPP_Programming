#include "../framework.h"
#include "Mage.h"


Mage::Mage() : Player("", 0, 0, "Mage") {};
Mage::Mage(string name) : Player(name, 450+rand()%50, 30+rand()%10, "Mage") { _dex = rand() % 20 + 1; };
Mage::~Mage() {};
void Mage::SetMage(string name, int hp, int atk) {
	auto self = dynamic_pointer_cast<Mage>(shared_from_this());
	self->_name = name;
	self->_hp = hp;
	self->_atk = atk;
}

bool Mage::HalfHp() {
	auto self = dynamic_pointer_cast<Mage>(shared_from_this());
	if (self->GetCreatureHp() > (self->GetCreatureMaxHp() / 2)) {
		return false;
	}
	else
		return true;
}

int Mage::Attack(shared_ptr<Creature> p) {
	auto self = dynamic_pointer_cast<Mage>(shared_from_this());
	if (HalfHp() == false) {
		cout << "Mage with more than 50% of their total Hp have their attack power doubled.";
		cout << "(current attack power:" << self->_atk * 2 << ")" << endl;
		int TotalDamage = self->_atk * 2 + (rand() % (self->_dex));
		p->TakeDamage(TotalDamage);
		cout << p->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
		return TotalDamage;
	}
	else {
		int TotalDamage = self->_atk + (rand() % (self->_dex));
		p->TakeDamage(TotalDamage);
		cout << p->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
		return TotalDamage;
	}

}
