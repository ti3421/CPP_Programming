#include "../framework.h"
#include "GoblinBoss.h"

GoblinBoss::GoblinBoss(string name) : Goblin(name)
{
	_hp = 5000 + rand() % 500;
	_atk = 100 + rand() % 5;
	_maxHp = _hp;
	_dex = rand() % 5 + 1;
}

GoblinBoss::~GoblinBoss()
{
}



int GoblinBoss::Attack(shared_ptr<Creature> p)
{
	auto self = dynamic_pointer_cast<GoblinBoss>(shared_from_this());
	int TotalDamage = _atk + (rand() % (self->_dex));
	p->TakeDamage(TotalDamage);
	cout << p->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
	return TotalDamage;
}

void GoblinBoss::Recording(string name, int deal)
{
	int flag = 0;
	for (auto& elem : DealRecording) {
		if (elem.first == name) {
			elem.second += deal;
			flag = 1;
		}
	}
	if (flag == 0) {
		DealRecording.push_back({ name, deal });
	}

	sort(DealRecording.begin(), DealRecording.end(), [](pair<string, int>& a, pair<string, int>& b)->bool {return a.second > b.second; });
}

void GoblinBoss::RangeAttack(vector<shared_ptr<Creature>> &v)
{
	auto self = dynamic_pointer_cast<GoblinBoss>(shared_from_this());
	if (self->HalfHp()) {
		cout << "GoblinBoss Rages! (Attacking all)" << endl;
		for (auto& creature : v) {
			if (creature->IsDead()) continue;
			int TotalDamage = self->_atk + (rand() % self->_dex);
			creature->TakeDamage(TotalDamage);
			cout << creature->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
		}
	}
	else {
		int i = 0;
		int t = 0;
		while (i < 4) {
			int flag = 0;
			for (auto& creature : v) {
				if (DealRecording[t].first == creature->GetCreatureName()) {
					if (creature->IsDead()) {
						t++;
						break;
					}
					int TotalDamage = self->_atk + (rand() % self->_dex);
					creature->TakeDamage(TotalDamage);
					cout << creature->GetCreatureName() << " took " << TotalDamage << " damages." << endl;
					flag = 1;
					break;
				}
			}
			
			if (t >=DealRecording.size())break;
			if (flag == 1) {
				i++;
				t++;
			}
		}
	}
}

void GoblinBoss::PrintDealRecord()
{
	cout << "-----------Damage Ranking----------" << endl;
	for (int i = 0; i < DealRecording.size(); i++) {
		cout << i + 1 << ". " << DealRecording[i].first << ", " << DealRecording[i].second << endl;
	}
	cout << "-----------------------------------" <<endl;
}
