#pragma once
#include <string>
#include <vector>
#include <iomanip>

class Animal
{
public:
	std::string type;
	std::string name;
	int age;
	float satiety;
	float fatigue;
	bool flag_e = false;
	bool flag_s = false;
	float sleeping = 0;
	float eating = 0;
	float dec_sat = 0.0;
	float inc_fat = 0.0;

	/*
	* Constructor of the animal's name and age
	* @param t - type
	* @param n - name
	* @param a - age
	* @param s - satiety
	* @param f - fatigue
	*/
	Animal(std::string t, std::string n, int a, float s, float f) :
		type(t),
		name(n),
		age(a),
		satiety(s),
		fatigue(f)
	{}

	/*
	*function to decrease satiety
	* @param visit intensity of zoo visits
	*/
	void decreaseSatiety(float visit)
	{
		satiety -= (dec_sat * visit);

		if (satiety < 0.0)
			satiety = 0.0;
	}

	/*
	*function to increase fatigue
	* @param visit intensity of zoo visits
	*/
	void increaseFatigue(float visit)
	{
		fatigue += (inc_fat * visit);
		if (fatigue > 100.0)
			fatigue = 100.0;
	}

	/*
	*function to play between animals
	* @param another_animal - second animal to play
	*/
	void playA(Animal & another_animal) {
			std::cout << type << " " << name << " plays with "
				<< another_animal.type << " " << another_animal.name
				<< " fat: " << std::setprecision(4) << fatigue 
				<< " sat: " << std::setprecision(4) << satiety << std::endl;
	}

	/*
	*function to play animal with visitor
	*/
	void playV() {
		std::cout << type << " " << name << " plays with visitor. fat: " 
			<< std::setprecision(4) << fatigue 
			<< " sat: " << std::setprecision(4) << satiety << std::endl;
	}

	/*
	*function to feed animal by visitor
	*/
	void vFeeds()
	{
		satiety += 5;
		if (satiety > 100.0)
			satiety = 100.0;
		std::cout << type << " " << name << " was fed by visitor. fat:"
			<< std::setprecision(4) << fatigue
			<< " sat: " << std::setprecision(4) << satiety << std::endl;
	}

	/*
	*function to replenishing satiety
	*/
	void eatingRoom()
	{
		satiety += eating;
		if (satiety > 100.0) {
			satiety = 100.0;
			flag_e = false;
		}
	}

	/*
	*function to reduce fatigue
	*/
	void sleepingRoom()
	{
		fatigue -= sleeping;
		if (fatigue < 0.0) {
			fatigue = 0.0;
			flag_s = false;
		}
	}

};