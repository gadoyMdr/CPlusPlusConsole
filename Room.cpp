#include "Room.h"
#include "Utils.h"
#include "GameObject.h"
#include "Entity.h"
#include "MeleeWeapon.h"
#include "Color.h"

#include <windows.h>
#include <iostream>
#include <map>
#include <vector>



using namespace std;

Room::Room(string _name, int _color) : roomName(_name), color(_color), hasBeenVisited(false), isInRoom(false), discoveryPercentage(0){}

Room::Room(const Room& room) {
    roomName = room.roomName;
    color = room.color;
    hasBeenVisited = room.hasBeenVisited;
    isInRoom = room.isInRoom;
    position = room.position;
}

Room::~Room(){}

int Room::GetRoomColor() { return color; }

Room* Room::GetRandomRoom() {

    int random = Utils::RandomRange(0, 10); //((double)rand() / (RAND_MAX));

    if (random < 2) {
        return Room::EnemyRoom();
    }
    else if (random < 4) {
        return Room::TreasureRoom();
    }
    else if (random <= 10) {
        return Room::NormalRoom();
    }

    return nullptr;
}

string Room::GetRoomName() { return roomName; }



void Room::EnterInRoom(GameObject* go) {
    if (go->tag == Tag::Player) {
        if (!hasBeenVisited) hasBeenVisited = true;
        isInRoom = true;
    }
    
    discoveredObjects.push_back(go);
}

void Room::ExitRoom(GameObject* go) {
    if (go->tag == Tag::Player) {
        isInRoom = false;
    }
    
    remove(discoveredObjects.begin(), discoveredObjects.end(), go);
}

vector<GameObject*> Room::DiscoverRoom() {

    vector<GameObject*> discoveredObjects;

    if (discoveryPercentage > 100) {
        discoveryPercentage = 100;
        return discoveredObjects;
    }

    int max = (35 < 101 - discoveryPercentage) ? 35 : 101 - discoveryPercentage;
    int min = (15 > max) ? max : 15;

    int discovery = Utils::RandomRange(min, max);
    discoveryPercentage += discovery;
    
    int amountToDiscover = ((float)undiscoveredObjectsInRoom.size() / 100.f) * discovery;

    for (int i = 0; i < amountToDiscover; i++) {
        int randomItem = Utils::RandomRange(0, undiscoveredObjectsInRoom.size());
        discoveredObjects.push_back(undiscoveredObjectsInRoom[randomItem]);
        undiscoveredObjectsInRoom.erase(undiscoveredObjectsInRoom.begin() + randomItem);
    }

    return discoveredObjects;
}

void Room::GenerateItemsAndEnemies(int minEnemy, int maxEnemy, int minWeapon, int maxWeapon, int moneyStacks) {

    //Generate enemies
    int rndEn = Utils::RandomRange(minEnemy, maxEnemy);
    for (int i = 0; i < rndEn; i++) {
        undiscoveredObjectsInRoom.push_back(Entity::GetRandomTrashMod());
    }

    //Generate enemies
    int rndWe = Utils::RandomRange(minWeapon, maxWeapon);
    for (int i = 0; i < rndWe; i++) {
        undiscoveredObjectsInRoom.push_back(MeleeWeapon::GetRandomWeapon());
    }
    
    //Generate money
    for (int i = 0; i < moneyStacks; i++) {
        undiscoveredObjectsInRoom.push_back(GameObject::MoneyBag());
    }
}


Room* Room::EnemyRoom()
{ 
    Room* room = new Room("Enemy Room", Color::Red()); 
    room->GenerateItemsAndEnemies(3, 6, 2, 4, 4);
    return room;
}

Room* Room::TreasureRoom() 
{ 
    Room* room = new Room("Treasure Room", Color::Yellow()); 
    room->GenerateItemsAndEnemies(1, 2, 3, 4, 5);
    return room;
}

Room* Room::NormalRoom() 
{ 
    Room* room = new Room("Normal Room", Color::White());
    room->GenerateItemsAndEnemies(2, 3, 1, 2, 2);
    return room;
}

