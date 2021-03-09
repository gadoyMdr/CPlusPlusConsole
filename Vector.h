#pragma once
#include <string>

struct Vector2
{
	int x;
	int y;

	Vector2() {
		x = 0;
		y = 0;
	}

	Vector2(const Vector2& a) {
		x = a.x;
		y = a.y;
	}

	Vector2(int _x, int _y) {
		x = _x;
		y = _y;
	}

	static Vector2 Right() {
		return Vector2(1, 0);
	}

	static Vector2 Left() {
		return Vector2(-1, 0);
	}

	static Vector2 Up() {
		return Vector2(0, -1);
	}

	static Vector2 Down() {
		return Vector2(0, 1);
	}

	static Vector2 Zero() {
		return Vector2(0, 0);
	}

	Vector2 operator+ (const Vector2& first) const
	{
		return Vector2(x + first.x, y + first.y);
	}

	std::string ToString() {
		return "x : " + std::to_string(x) + " y : " + std::to_string(y);
	}
};

