#include "Entity.h"
#include "Move.h"
#include "Credit.h"
#include "MeleeWeapon.h"
#include "Health.h"
#include "Attack.h"
#include "Utils.h"

#include <string>

using namespace std;

Entity::Entity(std::string _name, float _speed, int _creditReward, int health, MeleeWeapon* weapon, Tag _tag) {
    name = _name;
    speed = _speed;
    tag = _tag;
    creditReward = _creditReward;

    AddComponent(new Health(health));
    AddComponent(new Attack(weapon));
}

Entity* Entity::GetRandomTrashMod() {
    float random = Utils::RandomRange(0, 100);

    if (random < 35) {
        return Entity::Rat();
    }
    else if (random < 60) {
        return Entity::Zombie();
    }
    else if (random < 85) {
        return Entity::Skeleton();
    }
    else if (random <= 100) {
        return Entity::Knight();
    }

    return nullptr;
}

Entity* Entity::Rat() { return new Entity("Rat", 20, 30, 50, new MeleeWeapon("Claws", 0.2, 5, 20, 0.2), Tag::Enemy); }

Entity* Entity::Zombie() { return new Entity("Zombie", 5, 30, 130, new MeleeWeapon("Fists", 2, 15, 10, 0.3), Tag::Enemy); }

Entity* Entity::Skeleton() { return new Entity("Skeleton", 6, 60, 130, new MeleeWeapon("Bone", 4, 22, 7, 0.25), Tag::Enemy); }

Entity* Entity::Knight() { return new Entity("Knight", 5, 80, 200, new MeleeWeapon("Sword", 4, 35, 7, 0.1), Tag::Enemy); }

Entity* Entity::Player(string nickname)
{
    Entity* player = new Entity(nickname, 6, 90, 100, new MeleeWeapon("Fists", 0, 5, 30, 0.25), Tag::Player);
    player->AddComponent(new Move());
    player->AddComponent(new Credit(500));
    return player;
}
