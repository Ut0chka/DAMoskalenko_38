#pragma once
#include <string>

class Wombat
{
	std::string name;
	int age;
	int satiety = 100;
	int fatigue = 0;
public:
	Wombat(std::string n, int a)
	{
		name = n;
		age = a;
	}
};