#include "DisplayManager.h"
#include "Color.h"
#include "Health.h"
#include "Credit.h"
#include "Log.h"
#include "Attack.h"

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <vector>


using namespace std;

DisplayManager* DisplayManager::m_pInstance = NULL;

DisplayManager* DisplayManager::Instance() {

	if (!m_pInstance)
		m_pInstance = new DisplayManager;

	return m_pInstance;

}

DisplayManager::DisplayManager(){}

void DisplayManager::Display(Map* map, Room* room, GameObject* player, vector<Log>* logs) {
	system("cls");
	
	
	DisplayPlayer(player);
	DisplayLogs(logs);
	DisplayMap(map, room);
	
}

void DisplayManager::DisplayMap(Map* map, Room* currentRoom) {

	int y = 4;
	SetCursorPos(0, 0);
	cout << " ---------------------------------------------" << endl;
	cout << "          CURRENT ROOM : " + currentRoom->GetRoomName() << endl;


	for (vector<Room*> vec : map->GetRooms())
	{
		cout << endl;
		SetCursorPos(25 - map->size.x / 2, y);
		for (Room* room : vec) {
			DisplayRoom(room);
		}
		y++;
	}
	cout << endl << endl;

	//draw left bar
	for (int i = 0; i < map->size.y + 7; i++) {
		SetCursorPos(0, 1 + i);
		cout << "|";
	}

	//draw right bar
	for (int i = 0; i < map->size.y + 7; i++) {
		SetCursorPos(46, 1 + i);
		cout << "|";
	}

	//draw discovery bar
	SetCursorPos(16, map->size.y + 6);
	cout << "Room discovery :";
	SetCursorPos(2, map->size.y + 7);
	int red = (44.f / 100.f) * currentRoom->discoveryPercentage;

	for (int i = 0; i < 43; i++) {
		if(i < red)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::Red());
		else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::DrakGrey());

		cout << "#";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::LightGrey());

	SetCursorPos(0, map->size.y + 8);
	//draw bottom bar
	cout << " ---------------------------------------------" << endl << endl << endl;
}

void DisplayManager::DisplayRoom(Room* room) {
	if (!room->hasBeenVisited) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}
	else {
		if (room->isInRoom)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47);
		else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), room->GetRoomColor());
	}

	cout << "#";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
}

void DisplayManager::DisplayPlayer(GameObject* player) {
	int x = 50;
	int y = 0;
	SetCursorPos(x, y);
	cout << "##################" << endl;
	SetCursorPos(x, y+1);
	cout << "   Player Stats   " << endl << endl << endl;
	SetCursorPos(x, y + 3);
	cout << "Health : " << player->GetComponent<Health>()->GetHealth() << endl;
	SetCursorPos(x, y + 5);
	cout << "Money : " << player->GetComponent<Credit>()->money << endl;
	SetCursorPos(x, y + 7);
	cout << "Weapon : " << player->GetComponent<Attack>()->GetWeapon()->GetItemName() << endl;

	//draw left bar
	for (int i = 0; i < 10; i++) {
		SetCursorPos(x-1, y+i);
		cout << "#";
	}

	//draw right bar
	for (int i = 0; i < 10; i++) {
		SetCursorPos(x + 19, y + i);
		cout << "#";
	}

	//draw bottom bar
	for (int i = 0; i < 18; i++) {
		SetCursorPos(x + i, y + 10);
		cout << "#";
	}
}

void DisplayManager::DisplayLogs(vector<Log>* logs) {
	int x = 50;
	int y = 12;
	SetCursorPos(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::LightGreen());
	cout << "Logs : " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::LightGrey());
	y++;
	for (const Log log : *logs) {
		SetCursorPos(x, y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), log.color);
		cout << log.text;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::LightGrey());

		y++;
	}

	cout << endl;
}

void DisplayManager::DisplayFight(GameObject* player, vector<GameObject*> team) {

}

void DisplayManager::SetCursorPos(int x, int y) {
	COORD c;

	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
