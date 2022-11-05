#pragma once
#include <vector>
#include "Cat.h"
#include "Dog.h"
#include "Rat.h"
#include "Wombat.h"

class Zoo
{
	std::vector<std::string> _names = { "Barsik", "Tolik", "Petya", "Vasya", "Nix", "Pupa", "Terry", "Lolik", "Rouse", "Fenix", "Rediska", "Biba", "Boba", "Lupa" };
public:
	std::vector<Animal> animals;

	/*
	*function to fill zoo with random animals
	* @param N - numbers of animals
	*/
	void fillZoo(const int N);

	/*
	* function for displaying animals with their parameters to the console
	*/
	void printZoo();

	/*
	* function that implements the life of animals in the zoo for 16 hours
	* @param N - numbers of animals
	*/
	void liveAnimal(const int N);
};