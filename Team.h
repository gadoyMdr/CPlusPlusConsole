#pragma once
#include <vector>
#include "GameObject.h"
#include "Health.h"

class Team {
public :
	std::vector<GameObject*> team;

	Team(std::vector<GameObject*> _team) {
		team = _team;
	}

	Team(GameObject* member) {
		std::vector<GameObject*> team;
		team.push_back(member);
	}

	bool IsTeamAlive() {
		bool isAlive = false;
		for (GameObject* member : team) {
			if (member->GetComponent<Health>()->GetHealth() > 0)
				isAlive = true;
		}
		return isAlive;
	}
};

