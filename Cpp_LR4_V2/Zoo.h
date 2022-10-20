#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <thread>
#include "Animal.h"

class Zoo
{
	std::vector<std::string> _names = { "Barsik", "Tolik", "Petya", "Nix", "Pupa", "Terry", "Lolik", "Rouse", "Fenix" };
public:
	std::vector<Animal> animals;
	void fillZoo(const int N)
	{
		for (int i = 0; i < N; i++) {
			int n = rand() % _names.size();
			std::string name = _names[n];
			int age = rand() % 25;
			Animal animal;
			int type = (i < 3)? i : rand() % 3;
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
	void addAnimal()
	{
		Animal animal;
		std::string add_type = " ";
		std::string add_name = " ";
		int add_age = 0;
		std::cout << "Input type of animal:\n\
-> ";
		std::cin >> add_type;
		if (add_type != "Cat" && add_type != "Dog" && add_type != "Wombat") {
			errors("The wrong type of animal was entered!");
			return;
		}
		std::cout << "Input name of animal:\n\
-> ";
		std::cin >> add_name;
		std::cout << "Input age of animal:\n\
-> ";
		std::cin >> add_age;
		if (std::cin.fail() || add_age < 0 || add_age > 25) {
			errors("A?");
			return;
		}
		if (add_type == "Cat")
		{
			animal.type = Types::Cat_t;
			animal.animal = (void*)(new Cat(add_name, add_age));
		}
		else if (add_type == "Dog")
		{
			animal.type = Types::Dog_t;
			animal.animal = (void*)(new Dog(add_name, add_age));
		}
		else if (add_type == "Wombat")
		{
			animal.type = Types::Wombat_t;
			animal.animal = (void*)(new Wombat(add_name, add_age));
		}
		animals.push_back(animal);
	}
	void printZoo()
	{
		std::cout << "................." << std::endl;
		for (Animal& a : animals) {
			std::cout << "\nType: " << a.getType()
				<< "\nName: " << a.getName()
				<< "\nAge: " << a.getAge() 
				<< "\nSatiety: " << a.getSatiety()
				<< "\nFatigue: " << a.getFatigue()
				<< std::endl;
		}
	}
	void liveAnimal()
	{
		bool flag_e = false;
		bool flag_s = false;
		for (int i = 0; i < 12; i++)
		{
			float visitors = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			std::cout << i + 1 << " hours have passed" << std::endl;
			std::printf("%.2f visition\n", visitors);
			for (Animal& animal : animals) {
				if (animal.getSatiety() < 30) {
					//std::cout << animal.getType() << " "
						//<< animal.getName() << " is hungry! fat: " << animal.getFatigue()
						//<< " sat: "
						//<< animal.getSatiety() << std::endl;
					flag_e = true;
				}
				else if (animal.getFatigue() > 80) {
					//std::cout << animal.getType() << " "
						//<< animal.getName() << " is tired! fat: " 
						//<< animal.getFatigue() << " sat: " << animal.getSatiety() << std::endl;
					flag_s = true;
				}
				else if (animal.getSatiety() == 100 || animal.getFatigue() == 0)
					{
						flag_e = flag_s = false;
					}
					//std::cout << animal.getType() << " "
						//<< animal.getName() << " is well-food and restless! fat:" 
						//<< animal.getFatigue() << " sat: " << animal.getSatiety() << std::endl;
				if (flag_e)
				{
					animal.eatingRoom();
				}
				if (flag_s)
				{
					animal.restRoom();
				}
				if (!flag_e && !flag_s)
				{
					animal.decreaseSatiety(visitors);
					animal.increaseFatigue(visitors);
				}
				std::cout << animal.getType() << " "
					<< animal.getName() << " fat:"
					<< animal.getFatigue() << " sat: " << animal.getSatiety() << std::endl;
			}
		}
	}

	void errors(const std::string err)
	{
		std::cout << "Error: " << err << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
};