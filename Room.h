#pragma once
#include <string>
#include <vector>
#include "Vector.h"
#include "GameObject.h"

class Room
{
	private:
		std::string roomName;
		std::vector<GameObject*> undiscoveredObjectsInRoom;
		std::vector<GameObject*> discoveredObjects;

		int color;

		Room(std::string name, int color);

	public :

		bool hasBeenVisited;
		bool isInRoom;
		Vector2 position;
		int discoveryPercentage;

		~Room();
		Room(const Room &room);

		void EnterInRoom(GameObject* go);
		void ExitRoom(GameObject* go);
		std::vector<GameObject*> DiscoverRoom();	//return discovered GOs during the search
		int GetRoomColor();
		std::string GetRoomName();
		void GenerateItemsAndEnemies(int minEnemy, int maxEnemy, int minWeapon, int maxWeapon, int moneyStacks);

		static Room* NormalRoom();
		static Room* TreasureRoom();
		static Room* EnemyRoom();

		static Room* GetRandomRoom();
};

