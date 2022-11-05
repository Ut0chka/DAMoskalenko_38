#pragma once
#include "Animal.h"

class Dog : public Animal {
public:

	/*
	* Constructor of the dog's name and age
	* @param t - type
	* @param n - name
	* @param a - age
	* @param s - satiety
	* @param f - fatigue
	*/
	Dog(std::string t, std::string n, int a, float s, float f) :
		Animal(t, n, a, s, f)
	{
		sleeping = 30.0;
		eating = 40.0;
		dec_sat = 40.0;
		inc_fat = 30.0;
	}

};