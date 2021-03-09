#pragma once
#include <string>
#include "GameObject.h";

class Player : GameObject
{
	public :

		int GetMoney();
		std::string GetName();

		Player();
		Player(std::string nickname, int startMoney, int startHealth);


	private :

		std::string nickname;
		int money;
		int health;
		int killcount;
};

