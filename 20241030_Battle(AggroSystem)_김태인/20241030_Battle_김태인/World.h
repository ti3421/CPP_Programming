#pragma once
class World
{
public:
	World();
	~World();

	void Init();

	void Update();
	bool End();

private:
	bool CheckCreatureArr(vector<shared_ptr<Creature>> arr);

	vector<shared_ptr<Creature>> _players;
	shared_ptr<Creature> _Bossmonster;
};

