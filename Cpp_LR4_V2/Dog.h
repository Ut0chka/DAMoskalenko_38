#pragma once
#include <string>

class Dog
{
	std::string _name;
	int _age;
	float _satiety = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 100);
	float _fatigue = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 100);
	float dec_sat = 40;
	float inc_fat = 30;
	float eating = 40;
	float rest = 30;
public:
	/*
	* Constructor of the cat's name and age
	* @param n name
	* @param a age
	*/
	Dog(std::string n, int a)
	{
		_name = n;
		_age = a;
	}

	/*
	* function of getting a name
	* @return name of animal
	*/
	std::string getName()
	{
		return _name;
	}

	/*
	* function of getting age
	* @return age of animal
	*/
	int getAge()
	{
		return _age;
	}

	/*
	* function of getting a satiety
	* @return satiety of animal
	*/
	float getSatiety()
	{
		return _satiety;
	}

	/*
	* function of getting a fatigue
	* @return fatigue of animal
	*/
	float getFatigue()
	{
		return _fatigue;
	}

	/*
	*function to decrease satiety
	* @param visit intensity of zoo visits
	*/
	void decreaseSatiety(float visit)
	{
		_satiety -= (dec_sat * visit);

		if (_satiety < 0.0)
			_satiety = 0.0;
	}

	/*
	*function to increase fatigue
	* @param visit intensity of zoo visits
	*/
	void increaseFatigue(float visit)
	{
		_fatigue += (inc_fat * visit);
		if (_fatigue > 100.0)
			_fatigue = 100.0;
	}

	/*
	*function to replenishing satiety
	*/
	void eatingRoom()
	{
		_satiety += eating;
		if (_satiety > 100.0)
			_satiety = 100.0;
	}

	/*
	*function to reduce fatigue
	*/
	void restRoom()
	{
		_fatigue -= rest;
		if (_fatigue < 0.0)
			_fatigue = 0.0;
	}
};