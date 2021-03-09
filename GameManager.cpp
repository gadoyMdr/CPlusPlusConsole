#include "GameManager.h"
#include "Utils.h"
#include "Move.h"
#include "Entity.h"
#include "Log.h"
#include "Color.h"
#include "Credit.h"

#include <conio.h>
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

GameManager* GameManager::m_pInstance = NULL;


GameManager* GameManager::Instance(){
	
	if (!m_pInstance)  
		m_pInstance = new GameManager;
	
	return m_pInstance;
	
}

GameManager::GameManager() : player(Entity::Player("null")){}

Map* GameManager::GetCurrentMap() { return &map; }

void GameManager::StartNewGame() {
	EnterNickname();
	EnterMap();
	InitializeGame();
}

void GameManager::InitializeGame() {
	
	player->GetComponent<Move>()->MoveDirection(Vector2::Zero());
	GameLoop();
}

void GameManager::EnterNickname() {
	system("cls");
	string nickname;

	cout << "Oh hey! Down for a game? Type in your nickname below!" << endl;
	cin >> nickname;
	if (Utils::CheckString(3, 10, nickname)) {
		player->name = nickname;
	}
	else {
		
		EnterNickname();
	}
		
}

void GameManager::EnterMap() {
	system("cls");
	int x;
	int y;

	cout << "Okay " + player->name + ", now how large you want the map to be?" << endl;
	cin >> x; cin.ignore();

	cout << "Okay, " << x << ", not bad. Now the height?" << endl;
	cin >> y; cin.ignore();

	CreateMap(x, y);
}

void GameManager::GameLoop() {
	
	while (1) {
		DisplayManager::Instance()->Display(&map, map.GetRoomAt(player->GetPosition()), player, &logs);
		PromptBasicInput();
	}
	
}

void GameManager::CreateMap(int x, int y) {
	map = Map(x, y);
}

void GameManager::PromptBasicInput() {


	bool roomLeft = Utils::CheckIfRoomAt(player->GetPosition() + Vector2::Left(), &map);
	bool roomRight = Utils::CheckIfRoomAt(player->GetPosition() + Vector2::Right(), &map);
	bool roomBottom = Utils::CheckIfRoomAt(player->GetPosition() + Vector2::Down(), &map);
	bool roomTop = Utils::CheckIfRoomAt(player->GetPosition() + Vector2::Up(), &map);
	bool rummage = map.GetRoomAt(player->GetPosition())->discoveryPercentage < 100;

	cout << "What do you want to do? " << endl << endl;

	if (roomLeft)
		cout << "'q' to go left" << endl;
	if (roomRight)
		cout << "'d' to go right" << endl;
	if (roomTop)
		cout << "'z' to go up" << endl;
	if(roomBottom)
		cout << "'s' to go down" << endl;
	if(rummage)
		cout << "'r' to rummage the room" << endl;

	cout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::LightGreen());
	cout << "Input ->";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::LightGrey());

	auto playerMove = player->GetComponent<Move>();
	vector<GameObject*> discoveredGos;

	int keyId = _getch();

	if (keyId == 113 && roomLeft) {
		logs.insert(logs.begin(), Log("> Going left ..", Color::White()));
		playerMove->MoveDirection(Vector2::Left());
	}if (keyId == 100 && roomRight) {
		logs.insert(logs.begin(),  Log("> Going right ..", Color::White()));
		playerMove->MoveDirection(Vector2::Right());
	}if (keyId == 115 && roomBottom) {
		logs.insert(logs.begin(),  Log("> Going down ..", Color::White()));
		playerMove->MoveDirection(Vector2::Down());
	}if (keyId == 122 && roomTop) {
		logs.insert(logs.begin(),  Log("> Going up ..", Color::White()));
		playerMove->MoveDirection(Vector2::Up());
	}if (keyId == 114 && rummage) {
		discoveredGos = map.GetRoomAt(player->GetPosition())->DiscoverRoom();
		logs.insert(logs.begin(), Log("> Rummaged " + to_string(map.GetRoomAt(player->GetPosition())->discoveryPercentage) + " % of the room", Color::White()));
	}
	

	if (discoveredGos.size() != 0) {
		ProcessFoundThings(discoveredGos);
	}
}

void GameManager::PromptKeepWeaponInput(MeleeWeapon* weaponFound) {
	auto playerAttack = player->GetComponent<Attack>();

	cout << endl;
	cout << "Do you want to keep the " + weaponFound->GetItemName() + " you just found?" << endl;
	cout << "Knowing that right now, you have a " + playerAttack->GetWeapon()->GetItemName() + " ?" << endl << endl;
	cout << "'y' to keep" << endl;
	cout << "'n' to throw away" << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::LightGreen());
	cout << "Input ->";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::LightGrey());

	int keyId = _getch();

	if (keyId == 110) { //n
		logs.insert(logs.begin(), Log("Threw away " + weaponFound->GetItemName(), Color::Red()));
	}if (keyId == 121) { //y
		logs.insert(logs.begin(), Log("Threw away " + playerAttack->GetWeapon()->GetItemName(), Color::Red()));
		logs.insert(logs.begin(), Log(weaponFound->GetItemName() + " picked !", Color::LightGreen()));

		playerAttack->SetWeapon(weaponFound);
	}
}

void GameManager::ProcessFoundThings(vector<GameObject*> objs) {
	vector<GameObject*> enemiesFound;

	for (GameObject* go : objs) {
		if (go->tag == Tag::Weapon)
			PromptKeepWeaponInput((MeleeWeapon*)go);
		if (go->tag == Tag::Money) {
			auto moneyBag = go->GetComponent<Credit>();
			logs.insert(logs.begin(), Log("You found " + to_string(moneyBag->money) + " money on the ground !", Color::Yellow()));
			player->GetComponent<Credit>()->money += moneyBag->money;
		}if (go->tag == Tag::Enemy) {
			enemiesFound.push_back(go);
		}
	}

	if (enemiesFound.size() != 0)
		StartFight(new Team(player), new Team(enemiesFound));
}

void GameManager::StartFight(Team* team1, Team* team2) {

	while (team1->IsTeamAlive() && team2->IsTeamAlive()) {
		for (GameObject* member : team1->team) {
			cout << "What do you want to do?" << endl << endl;
			cout << "'a' to attack" << endl;
			cout << "'f' to try to flee" << endl;
		}
	}

}
