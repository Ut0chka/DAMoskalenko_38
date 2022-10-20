#pragma once
#include <string>

class Cat
{
	std::string _name;
	int _age;
	int _satiety = 100;
	int _fatigue = 0;
	int dec_sat = 50;
	int inc_fat = 50;
	int rest = 20;
	int eating = 30;
public:
	Cat(std::string n, int a)
	{
		_name = n;
		_age = a;
	}
	std::string getName()
	{
		return _name;
	}
	int getAge()
	{
		return _age;
	}
	int getSatiety()
	{
		return _satiety;
	}
	int getFatigue()
	{
		return _fatigue;
	}
	void decreaseSatiety(float visit)
	{
		_satiety -= (dec_sat * visit);

		if (_satiety < 0)
			_satiety = 0;

	}
	void increaseFatigue(float visit)
	{
		_fatigue += (inc_fat * visit);
		if (_fatigue > 100)
			_fatigue = 100;
	}
	void eatingRoom()
	{
		_satiety += eating;
		if (_satiety > 100)
			_satiety = 100;
	}
	void restRoom()
	{
		_fatigue -= rest;
		if (_fatigue < 0)
			_fatigue = 0;
	}
};