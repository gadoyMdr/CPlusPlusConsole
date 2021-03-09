#pragma once
#include "Attack.h"
#include "Room.h"
#include "GameObject.h"
#include "Map.h"
#include "DisplayManager.h"
#include "Team.h"

class Log;

class GameManager
{
	public :
		static GameManager* Instance();

		void StartNewGame();
		Map* GetCurrentMap();

	private:
		static GameManager* m_pInstance;
		GameManager& operator=(GameManager const&) {};
		GameManager();

		std::vector<Log> logs;

		Map map;
		GameObject* player;

		void EnterNickname();
		void EnterMap();
		void InitializeGame();
		void ProcessFoundThings(std::vector<GameObject*> objs);
		void GameLoop();
		void CreateMap(int x, int y);
		void PromptBasicInput();
		void PromptKeepWeaponInput(MeleeWeapon* itemFound);
		void StartFight(Team* team1, Team* team2);
};

