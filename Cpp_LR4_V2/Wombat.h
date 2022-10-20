#pragma once
#include <string>

class Wombat
{
	std::string _name;
	int _age;
	int _satiety = 100;
	int _fatigue = 0;
	int dec_sat = 30;
	int inc_fat = 30;
	int eating = 20;
	int rest = 20;
public:
	Wombat(std::string n, int a)
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
		if (_satiety < 0)
			_satiety = 0;
		else
			_satiety -= (dec_sat * visit);
	}
	void increaseFatigue(float visit)
	{
		if (_fatigue > 100)
			_fatigue = 100;
		else
			_fatigue += (inc_fat * visit);
	}
	void eatingRoom()
	{
		if (_satiety > 100)
			_satiety = 100;
		else
			_satiety += eating;
	}
	void restRoom()
	{
		if (_fatigue < 0)
			_fatigue = 0;
		else
			_fatigue -= rest;
	}
};