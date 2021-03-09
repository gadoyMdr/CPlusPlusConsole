#pragma once
#include "Component.h"

class Credit : public Component
{
	public :
		int money;

		Credit(int credit);
		~Credit();
};

