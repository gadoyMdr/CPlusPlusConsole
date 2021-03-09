#pragma once
#include "Item.h"
#include <string>

class MeleeWeapon : public Item
{

	public :
		float damage;
		float speed;
		float critOdds;

		MeleeWeapon();
		MeleeWeapon(std::string name, float weight, float damage, float speed, float critOdds);

		static MeleeWeapon* GetRandomWeapon();

		static MeleeWeapon* Stick();
		static MeleeWeapon* CrowBar();
		static MeleeWeapon* Wrench();
		static MeleeWeapon* Sword();
};

