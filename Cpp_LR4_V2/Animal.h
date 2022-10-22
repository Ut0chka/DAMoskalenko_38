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
public:
	void* animal = nullptr;
	Types type;
	bool flag_e = false;
	bool flag_s = false;

	/*
	* function of getting type
	* @return type of animal
	*/
	std::string getType();

	/*
	* function of getting name
	* @return name of animal
	*/
	std::string getName();

	/*
	* function of getting age
	* @return age of animal
	*/
	int getAge();

	/*
	* function of getting satiety
	* @return satiety of animal
	*/
	float getSatiety();

	/*
	* function of getting fatigue
	* @return fatigue of animal
	*/
	float getFatigue();

	/*
	*function to decrease satiety
	* @param visit intensity of zoo visits
	*/
	void decreaseSatiety(float);

	/*
	*function to increase fatigue
	* @param visit intensity of zoo visits
	*/
	void increaseFatigue(float);

	/*
	*function to replenishing satiety
	*/
	void eatingRoom();

	/*
	*function to reduce fatigue
	*/
	void restRoom();
};