#include "GameObjectTemplate.h"
#include "Credit.h"
#include "Health.h"
#include "Attack.h"
#include "MeleeWeapon.h"


GameObject GameObjectTemplate::Rat() {
	GameObject rat = GameObject("Rat", 20, 30, 50, MeleeWeapon("Claws", 0.2, 5, 20, 0.2));
}

GameObject GameObjectTemplate::Zombie() {
	GameObject rat = GameObject("Zombie", 5, 30, 130, MeleeWeapon("Fists", 2, 15, 10, 0.3));
}
