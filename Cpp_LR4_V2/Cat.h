#pragma once
#include <string>

class Cat
{
	std::string name;
	int age;
	int satiety;
	int fatigue;
public:
	Cat(std::string n, int a, int s, int f)
	{
		name = n;
		age = a;
		satiety = s;
		fatigue = f;
	}

};