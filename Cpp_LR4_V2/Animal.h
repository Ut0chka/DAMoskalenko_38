#pragma once
#include <vector>
#include "Cat.h"
#include "Dog.h"
#include "Wombat.h"

enum Types
{
	Cat_t, Dog_t, Wombat_t
};


class Animal
{
	bool _flag_e;
	bool _flag_s;
public:
	void* animal = nullptr;
	Types type;

	std::string getType();
	std::string getName();
	int getAge();
	int getSatiety();
	int getFatigue();
	void decreaseSatiety(float);
	void increaseFatigue(float);
	void eatingRoom();
	void restRoom();
};