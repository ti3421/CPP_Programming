#include "../framework.h"
#include "Player.h"


Player::Player() : Creature("", 0, 0), _job("") {};
Player::Player(string name, int hp, int atk, string job) : Creature(name, hp, atk), _job(job) {};
void Player::SetPlayer(string name, int hp, int atk) {
	
	auto self = dynamic_pointer_cast<Player>(shared_from_this());
	self->SetCreatureName(name);
	self->SetCreatureHp(hp);
	self->SetCreatureAtk(atk);
}
Player::~Player() {};

void Player::SetPlayerJob(string name) { 
	auto self = dynamic_pointer_cast<Player>(shared_from_this());
	self->_job = name; };
string Player::GetPlayerJob() { 
	auto self = dynamic_pointer_cast<Player>(shared_from_this());
	return self->_job; };


