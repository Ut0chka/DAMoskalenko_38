#pragma once
#include <vector>
#include <string>
#include "Animal.h"

class Zoo
{
	std::vector<std::string> _names = { "Barsik", "Tolik", "Petya", "Vasya", "Nix", "Pupa", "Terry", "Lolik", "Rouse", "Fenix", "Rediska", "Biba", "Boba", "Lupa"};
public:
	std::vector<Animal> animals;

	/*
	*function to fill zoo with random animals
	* @param N numbers of animals
	*/
	void fillZoo(const int N);
	
	/*
	* function to add new animal in zoo
	*/
	void addAnimal();

	/*
	* function for displaying animals with their parameters to the console
	*/
	void printZoo();

	/*
	* function that implements the life of animals in the zoo for 12 hours
	*/
	void liveAnimal();

	/*
	*function for output of a string with an error
	*
	* @param string err string with an error
	*/
	void errors(const std::string err);
};