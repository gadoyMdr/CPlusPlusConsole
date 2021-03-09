#include "Attack.h"
#include <iostream>
#include "MeleeWeapon.h"
#include "GameObject.h"

using namespace std;

Attack::Attack() : weapon(new MeleeWeapon("Hands", 3, 10, 0.7, 0.2)){}

Attack::Attack(MeleeWeapon* _weapon) : weapon(_weapon){}


Attack::~Attack(){}

MeleeWeapon* Attack::GetWeapon() { return weapon; }

void Attack::SetWeapon(MeleeWeapon* _weapon) { weapon = _weapon; }

void Attack::AttackEnemy(Health &enemy) {
	cout << "\"" << parentGO->name << "\"" << " attacked " << "\"" << enemy.GetAttachedGameObject()->name << "\"" << endl;
	enemy.RemoveHealth(weapon->damage);
}
