#pragma once
#include <string>
#include "GameObject.h"

class Item : public GameObject
{
	private : 
		std::string itemName;
		float weight;
	public :
		Item();
		Item(std::string name);
		Item(std::string name, float weight);
		~Item();

		std::string GetItemName();
		void SetItemName(std::string name);
		float GetItemWeight();
		void SetItemWeight(float weight);
};

