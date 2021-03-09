#pragma once
#include "Map.h"
#include "GameObject.h"

class Log;

class DisplayManager
{
	public:
		static DisplayManager* Instance();
		void Display(Map* map, Room* room, GameObject* player, std::vector<Log>* logs);
	private :
		static DisplayManager* m_pInstance;
		DisplayManager();

		void DisplayLogs(std::vector<Log>* logs);
		void DisplayMap(Map* map, Room* room);
		void DisplayRoom(Room* room);
		void DisplayPlayer(GameObject* player);
		void DisplayFight(GameObject* player, std::vector<GameObject*> team);
		void SetCursorPos(int x, int y);
};

