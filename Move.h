#pragma once
#include "Component.h"
#include "Vector.h"

class Move : public Component
{
	public :
		Move();
		~Move();

		void MoveDirection(Vector2 direction);
};

