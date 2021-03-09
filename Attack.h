#pragma once
#include "Component.h"
#include "MeleeWeapon.h"
#include "Health.h"

class Attack : public Component
{
	private :
		MeleeWeapon* weapon;

	public :
		Attack();
		Attack(MeleeWeapon* weapon);
		~Attack();

		MeleeWeapon* GetWeapon();
		void SetWeapon(MeleeWeapon* weapon);
		void AttackEnemy(Health &enemy);
};

