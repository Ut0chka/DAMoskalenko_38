#pragma once
#include <vector>
#include "Cat.h"
#include "Dog.h"
#include "Wombat.h"

enum Types
{
	Cat_t, Dog_t, Wombat_t
};

std::vector<std::string> names = {"Barsik", "Tolik", "Petya", "Nix", "Pupa", "Terry", "Lolik", "Rouse", "Fenix"};

class Animal
{
public:
	void* animal = nullptr;
	Types type;
};