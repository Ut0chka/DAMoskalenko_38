#pragma once
#include "Animal.h"

class Wombat : public Animal {
public:

	/*
	* Constructor of the wombat's name and age
	* @param t - type
	* @param n - name
	* @param a - age
	* @param s - satiety
	* @param f - fatigue
	*/
	Wombat(std::string t, std::string n, int a, float s, float f) :
		Animal(t, n, a, s, f)
	{
		sleeping = 10.0;
		eating = 20.0;
		dec_sat = 30.0;
		inc_fat = 20.0;
	}

};