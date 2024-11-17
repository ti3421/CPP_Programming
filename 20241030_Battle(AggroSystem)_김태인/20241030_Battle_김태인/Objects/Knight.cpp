#include "../framework.h"
#include "Knight.h"


Knight::Knight() : Player("", 0, 0, "Knight") {};
Knight::Knight(string name) : Player(name, 500+rand()%50, 25+rand()%10, "Knight") { _dex = rand() % 4 + 1; };
Knight::~Knight() {};
void Knight::SetKnight(string name, int hp, int atk) {
	auto self = dynamic_pointer_cast<Knight>(shared_from_this());
	self->SetCreatureName(name);
	self->SetCreatureHp(hp);
	self->SetCreatureAtk(atk);
}

bool Knight::HalfHp() {
	auto self = dynamic_pointer_cast<Knight>(shared_from_this());
	if (self->GetCreatureHp() > (self->GetCreatureMaxHp() / 2)) {
		return false;
	}
	else
		return true;
}

int Knight::Attack(shared_ptr<Creature> p) {
	auto self = dynamic_pointer_cast<Knight>(shared_from_this());
	if (HalfHp() == true) {
		cout << "Knights with less than 50% of their total Hp have their attack power doubled.";
		cout << "(current attack power:" << self->_atk * 2 << ")" << endl;
		int TotalDamage = (self->_atk * 2) + (rand() % (self->_dex));
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
