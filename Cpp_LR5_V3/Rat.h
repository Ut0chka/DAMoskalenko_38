#pragma once
#include "Animal.h"

class Rat : public Animal {
public:

	/*
	* Constructor of the rat's name and age
	* @param t - type
	* @param n - name
	* @param a - age
	* @param s - satiety
	* @param f - fatigue
	*/
	Rat(std::string t, std::string n, int a, float s, float f) :
		Animal(t, n, a, s, f)
	{
		sleeping = 5.0;
		eating = 15.0;
		dec_sat = 20.0;
		inc_fat = 10.0;
	}
};