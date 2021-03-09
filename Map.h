#pragma once
#include <vector>
#include "Room.h"

class Map
{
	private :
		std::vector<std::vector<Room*>> rooms;
	public :
		Map(int w, int h);
		Map();
		~Map();

		Vector2 size;

		Room* GetRoomAt(Vector2 pos);
		void EnterRoomAt(Vector2 from, Vector2 pos, GameObject* go);
		std::vector<std::vector<Room*>> GetRooms();
};

