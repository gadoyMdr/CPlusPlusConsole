#include "Health.h"
#include <iostream>
#include "GameObject.h"

using namespace std;

Health::Health() : currentHealth(0), startHealth(0){}

Health::Health(int startHealth) : startHealth(startHealth), currentHealth(startHealth) {}

Health::~Health(){}

void Health::AddHealth(int amountToAdd) {
	currentHealth += amountToAdd;
}

void Health::RemoveHealth(int amountToRemove) {
	currentHealth -= amountToRemove;
	std::cout << "\"" + parentGO->name + "\"" + " has lost " << amountToRemove << " hit points" << std::endl;
	if (currentHealth <= 0) {
		currentHealth = 0;
	}
}

void Health::SetHealth(int amountToSet) {
	currentHealth = amountToSet;
}

void Health::Die() {
	cout << "\"" + parentGO->name + "\" Died." << endl;
}

int Health::GetHealth() {
	return currentHealth;
}