#include "framework.h"
#include "World.h"

World::World()
{
	Init();
}

World::~World()
{
}

void World::Init()
{
	
	_Bossmonster = make_shared<GoblinBoss>("GoblinBoss");
	_players.reserve(10);

	for (int i = 0; i < 10; i++) {
		int ClassNum = rand() % 3;
		switch (ClassNum)
		{
		case 0:
			_players.push_back(make_shared<Knight>("Knight" + to_string(i)));
			break;
		case 1:
			_players.push_back(make_shared<Mage>("Mage" + to_string(i)));
			break;
		case 2:
			_players.push_back(make_shared<Archer>("Archer" + to_string(i),rand()%50+1));
			break;
		default:
			break;
		}
	}
	
	for (int i = 0; i < _players.size(); i++) {
		_players[i]->PrintInfo();
	}
}

void World::Update()
{
	for (int i = 0; i < _players.size(); i++) {
		if (_players[i]->IsDead())continue;
		if (_Bossmonster->IsDead())break;
		int deal = _players[i]->Attack(_Bossmonster);
		dynamic_pointer_cast<GoblinBoss>(_Bossmonster)->Recording(_players[i]->GetCreatureName(), deal);
		(_Bossmonster)->PrintInfo();
	}
	
	dynamic_pointer_cast<GoblinBoss>(_Bossmonster)->PrintDealRecord();

	if(!_Bossmonster->IsDead())dynamic_pointer_cast<GoblinBoss>(_Bossmonster)->RangeAttack(_players);

	for (int i = 0; i < _players.size(); i++) {
		_players[i]->PrintInfo();
	}

}

bool World::End()
{
	if (_Bossmonster->IsDead())
	{
		cout << "GoblinBoss has been killed!" << endl;
		return true;
	}


	if (CheckCreatureArr(_players))
	{
		cout << "All Players dead!" << endl;
		return true;
	}

	return false;
}

bool World::CheckCreatureArr(vector<shared_ptr<Creature>> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->IsDead() == false)
			return false;
	}

	return true;
}

