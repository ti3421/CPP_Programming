#pragma once

class Player :public Creature
{
public:
	Player();
	Player(string name, int hp, int atk, string job);
	void SetPlayer(string name, int hp, int atk);
	~Player();

	void SetPlayerJob(string name);
	string GetPlayerJob();

protected:
	string _job;
};