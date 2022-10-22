#include <iostream>
#include <iomanip>
#include "Zoo.h"

void Zoo::fillZoo(const int N)
{
	for (int i = 0; i < N; i++) {
		int n = rand() % _names.size();
		std::string name = _names[n];
		int age = rand() % 25;
		Animal animal;
		int type = (i < 3) ? i : rand() % 3;
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

void Zoo::addAnimal()
{
	Animal animal;
	std::string add_type = " ";
	std::string add_name = " ";
	int add_age = 0;
	std::cout << "Input type of animal (Cat, Dog or Wombat):\n\
-> ";
	std::cin >> add_type;
	if (add_type != "Cat" && add_type != "Dog" && add_type != "Wombat") {
		errors("The wrong type of animal was entered!");
		return;
	}
	std::cout << "Input name of animal:\n\
-> ";
	std::cin >> add_name;
	std::cout << "Input age of animal (0-25):\n\
-> ";
	std::cin >> add_age;
	if (std::cin.fail() || add_age < 0 || add_age > 25) {
		errors("Wrong age!");
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

void Zoo::printZoo()
{
	std::cout << "................." << std::endl;
	for (Animal& a : animals) {
		std::cout << "\nType: " << a.getType()
			<< "\nName: " << a.getName()
			<< "\nAge: " << a.getAge()
			<< std::setprecision(4) << "\nSatiety: " << a.getSatiety()
			<< std::setprecision(4) << "\nFatigue: " << a.getFatigue()
			<< std::endl;
	}
}

void Zoo::liveAnimal()
{
	for (int i = 0; i < 12; i++)
	{
		float visitors = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		std::cout << "\n" << i + 1 << " hours have passed" << std::endl;
		std::printf("%.2f visition\n", visitors);
		for (Animal& animal : animals) {
			if (animal.getSatiety() < 30.0) {
				std::cout << animal.getType() << " " << animal.getName() 
					<< " is hungry! fat: " << std::setprecision(4) << animal.getFatigue()
					<< " sat: " << std::setprecision(4) << animal.getSatiety() << std::endl;
				animal.flag_e = true;
			}
			else if (animal.getFatigue() > 80.0) {
				std::cout << animal.getType() << " " << animal.getName() 
					<< " is tired! fat: " << std::setprecision(4) << animal.getFatigue() 
					<< " sat: " << std::setprecision(4) << animal.getSatiety() << std::endl;
				animal.flag_s = true;
			}
			else if (animal.getSatiety() == 100.0 || animal.getFatigue() == 0.0)
			{
				animal.flag_e = animal.flag_s = false;
			}
			if (animal.flag_e)
			{
				animal.eatingRoom();
				std::cout << animal.getType() << " " << animal.getName() 
					<< " is eating! fat: " << std::setprecision(4) << animal.getFatigue()
					<< " sat: " << std::setprecision(4) << animal.getSatiety() << std::endl;
			}
			else if (animal.flag_s)
			{
				animal.restRoom();
				std::cout << animal.getType() << " " << animal.getName() 
					<< " is sleeping! fat: " << std::setprecision(4) << animal.getFatigue() 
					<< " sat: " << std::setprecision(4) << animal.getSatiety() << std::endl;
			}
			else if (!animal.flag_e && !animal.flag_s)
			{
				std::cout << animal.getType() << " "
					<< animal.getName() << " is well-food and restless! fat:"
					<< std::setprecision(4) << animal.getFatigue() 
					<< " sat: " << std::setprecision(4) << animal.getSatiety() << std::endl;
				animal.decreaseSatiety(visitors);
				animal.increaseFatigue(visitors);
			}
		}
	}
}

void Zoo::errors(const std::string err)
{
	std::cout << "Error: " << err << std::endl;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}