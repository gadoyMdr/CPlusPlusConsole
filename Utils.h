#pragma once
#include <string>
#include <windows.h>
#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <random>

class Utils
{
	public :
		static bool CheckString(int min, int max, std::string str) {
			return str.size() >= min && str.size() <= max;
		}

		static int RandomRange(int min, int max) {
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
			int i = dist6(rng) - 1;
			if (i < 0) i = 0;
			return i;
		}

		static bool CheckIfRoomAt(Vector2 pos, Map* map) {
			return pos.x >= 0
				&& pos.x < map->size.x
				&& pos.y >= 0
				&& pos.y < map->size.y;
		}
};

