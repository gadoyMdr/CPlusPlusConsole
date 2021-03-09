#include "Map.h"
#include "Room.h"
#include <vector>
#include <iostream>

using namespace std;

Map::Map() : rooms(NULL){}

Map::Map(int w, int h) {
	vector<vector<Room*>> _rooms(h, vector<Room*>(w, 0));

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			_rooms[y][x] = Room::GetRandomRoom();
			_rooms[y][x]->position = Vector2(x, y);
		}
	}

	rooms = _rooms;
	size = Vector2(w, h);
}

Map::~Map(){}

Room* Map::GetRoomAt(Vector2 pos) { return rooms[pos.y][pos.x]; }

void Map::EnterRoomAt(Vector2 from, Vector2 pos, GameObject* go) {

	GetRoomAt(from)->isInRoom = false; //We exit the current one
	rooms[pos.y][pos.x]->EnterInRoom(go);
}

std::vector<std::vector<Room*>> Map::GetRooms() {
	return rooms;
}
