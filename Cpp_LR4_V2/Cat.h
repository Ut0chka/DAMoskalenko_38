#pragma once
#include <string>

class Cat
{
	std::string name;
	int age;
	int satiety = 100;
	int fatigue = 0;
public:
	Cat(std::string n, int a)
	{
		name = n;
		age = a;
	}
};