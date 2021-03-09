#pragma once
#include "Component.h"

class Health : public Component
{
	private : 
		int currentHealth;
		int startHealth;

	public :
		Health(int startHealth);
		Health();
		~Health();

		int GetHealth();
		void AddHealth(int amountToAdd);
		void RemoveHealth(int amountToRemove);
		void SetHealth(int amountToSet);
		void Die();
};

