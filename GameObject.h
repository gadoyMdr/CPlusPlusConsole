#pragma once
#include <string>
#include <vector>
#include <memory>

//#include "Component.h"
#include "Vector.h"

class Component;

class MeleeWeapon;

enum class Tag {
	Player,
	Enemy,
	Weapon,
	Money,
	Other
};

class GameObject
{
	private : 

		std::vector<Component*> components;
		Vector2 position;

	public :

		Tag tag;
		std::string name;

		GameObject();
		GameObject(std::string name, Tag tag);

		Vector2 GetPosition();
		void SetPosition(Vector2 pos);

		void AddComponent(Component* c);


		template<class T>
		T* GetComponent() {

			for (Component* c : components)
			{
				if (typeid(*c).name() == typeid(T).name())
					return dynamic_cast<T*>(c);
			}

			return nullptr;
		}

		static GameObject* MoneyBag();
};

