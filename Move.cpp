#include "Move.h"
#include "GameManager.h"
#include "Utils.h"
#include <iostream>

using namespace std;

Move::Move(){}

Move::~Move(){}

void Move::MoveDirection(Vector2 direction) {
	GameObject* parent = GetAttachedGameObject();
	Vector2 finalPos = parent->GetPosition() + direction;
	Vector2 basePos = parent->GetPosition();
	Map* map = GameManager::Instance()->GetCurrentMap();

	if (Utils::CheckIfRoomAt(finalPos, map))
	{
		parent->SetPosition(finalPos);

		map->EnterRoomAt(basePos, finalPos, GetAttachedGameObject());
	}

	
}
