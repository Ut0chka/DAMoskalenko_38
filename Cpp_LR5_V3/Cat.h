#pragma once
#include "Animal.h"

class Cat : public Animal {
public:

	/*
	* Constructor of the cat's name and age
	* @param t - type
	* @param n - name
	* @param a - age
	* @param s - satiety
	* @param f - fatigue
	*/
	Cat(std::string t, std::string n, int a, float s, float f):
		Animal(t, n, a, s, f)
	{
		sleeping = 20.0;
		eating = 30.0;
		dec_sat = 50.0;
		inc_fat = 40.0;
	}

};