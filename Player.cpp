#include "Player.h"
using namespace std;

int Player::GetMoney() 
{
	return money;
}

string Player::GetName() 
{
	return name;
}

Player::Player(){
	name = "Player";
}

Player::Player(std::string _nickname, int startMoney, int startHealth) : Player()
{
	nickname = _nickname;
	money = startMoney;
	health = startMoney;
	killcount = 0;
}
