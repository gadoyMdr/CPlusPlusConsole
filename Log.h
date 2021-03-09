#pragma once
#include <string>

class Log
{
	public:
		std::string text;
		int color;
		Log(std::string _text, int _color) {
			text = _text;
			color = _color;
		}
};