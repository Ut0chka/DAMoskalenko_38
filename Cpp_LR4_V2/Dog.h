#pragma once
#include <string>

class Dog
{
	std::string name;
	int age;
	int satiety = 100;
	int fatigue = 0;
public:
	Dog(std::string n, int a)
	{
		name = n;
		age = a;
	}
};