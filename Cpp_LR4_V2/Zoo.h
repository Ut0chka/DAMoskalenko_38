#pragma once
#include <vector>
#include <string>
#include "Animal.h"

class Zoo
{
	std::vector<std::string> _names = { "Barsik", "Tolik", "Petya", "Nix", "Pupa", "Terry", "Lolik", "Rouse", "Fenix" };
public:
	std::vector<Animal> animals;
	void fillZoo(const int N);
	
	void addAnimal();
	void printZoo();
	void liveAnimal();

	void errors(const std::string err);
};