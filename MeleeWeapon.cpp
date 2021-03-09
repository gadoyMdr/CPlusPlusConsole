#include "MeleeWeapon.h"

#include <string>
#include "Utils.h"

using namespace std;

MeleeWeapon::MeleeWeapon() : Item("Fists", 3), damage(10), speed(5), critOdds(0.2){ tag = Tag::Weapon; }

MeleeWeapon::MeleeWeapon(string weaponName, float _weight, float _damage, float _speed, float _critOdds) :
    Item(weaponName, _weight), damage(_damage), speed(_speed), critOdds(_critOdds) {
    tag = Tag::Weapon;
}

MeleeWeapon* MeleeWeapon::GetRandomWeapon() {
    float random = Utils::RandomRange(0, 100);

    if (random < 35) {
        return MeleeWeapon::Stick();
    }
    else if (random < 60) {
        return MeleeWeapon::Wrench();
    }
    else if (random < 85) {
        return MeleeWeapon::CrowBar();
    }
    else if (random <= 100) {
        return MeleeWeapon::Sword();
    }

    return nullptr;
}

MeleeWeapon* MeleeWeapon::Stick() {
	return new MeleeWeapon("Stick", 1, 10, 20, 0.2f);
}

MeleeWeapon* MeleeWeapon::Wrench() {
	return new MeleeWeapon("Wrench", 5, 40, 5, 0.4f);
}

MeleeWeapon* MeleeWeapon::CrowBar() {
	return new MeleeWeapon("Crowbar", 4, 30, 8, 0.2f);
}

MeleeWeapon* MeleeWeapon::Sword() {
	return new MeleeWeapon("Sword", 4, 65, 12, 0.2f);
}
