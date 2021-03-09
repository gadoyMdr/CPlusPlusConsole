#pragma once
#include "GameObject.h"
class Entity : public GameObject
{
	private :
		Entity(std::string name, float speed, int creditReward, int health, MeleeWeapon* weapon, Tag tag);

	public :
		float speed;
		int creditReward;

		static Entity* GetRandomTrashMod();

		static Entity* Rat();
		static Entity* Zombie();
		static Entity* Skeleton();
		static Entity* Knight();
		static Entity* Player(std::string nickname);
};

