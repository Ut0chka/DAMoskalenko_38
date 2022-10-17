#pragma once
#include <vector>
#include <string>
#include "Animal.h"

class Zoo
{
public:
	std::vector<Animal> animals;
	void fillZoo(const int N)
	{
		for (int i = 0; i < N; i++) {
			int n = rand() % names.size();
			std::string name = names[n];
			int age = rand() % 25;
			Animal animal;
			int type = rand() % 3;
			switch (type)
			{
			case Types::Cat_t:
				animal.type = Types::Cat_t;
				animal.animal = (void*)(new Cat(name, age));
				break;
			case Types::Dog_t:
				animal.type = Types::Dog_t;
				animal.animal = (void*)(new Dog(name, age));
				break;
			case Types::Wombat_t:
				animal.type = Types::Wombat_t;
				animal.animal = (void*)(new Wombat(name, age));
				break;
			}
			animals.push_back(animal);
		}
	}
	void printZoo(vector<Animal>& animals)
	{
		cout << endl;
		for (Animal& a : animals) {
			cout << a.animal << endl;
		}
	}
};