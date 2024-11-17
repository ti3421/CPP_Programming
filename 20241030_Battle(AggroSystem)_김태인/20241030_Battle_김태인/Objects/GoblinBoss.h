#pragma once

class GoblinBoss :public Goblin
{
public:
	GoblinBoss(string name);
	~GoblinBoss();

	virtual int Attack(shared_ptr<Creature> p) override;

	void Recording(string name, int deal);

	void RangeAttack(vector<shared_ptr<Creature>>& v);

	void PrintDealRecord();
private:
	vector<pair<string, int>> DealRecording;
};

