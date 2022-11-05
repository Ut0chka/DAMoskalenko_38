#include <iostream>
#include <iomanip>
#include "Zoo.h"

void Zoo::fillZoo(const int N)
{
	for (int i = 0; i < N; i++)
	{
		int n = rand() % _names.size();
		std::string name = _names[n];
		int age = rand() % 25;
		float satyety = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 100);
		float fatigue = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 100);
		int type = (i < 4) ? i : (i < 8) ? i - 4 : rand() % 3;
		switch (type)
		{
		case 0:
			animals.push_back(Cat("Cat", name, age, satyety, fatigue));
			break;
		case 1:
			animals.push_back(Dog("Dog", name, age, satyety, fatigue));
			break;
		case 2:
			animals.push_back(Wombat("Wombat", name, age, satyety, fatigue));
			break;
		case 3:
			animals.push_back(Rat("Rat", name, age, satyety, fatigue));
			break;
		}
	}
}

void Zoo::printZoo()
{
	for (Animal& a : animals)
	{
		std::cout << "................." << std::endl;
		std::cout << "\nType: " << a.type
			<< "\nName: " << a.name
			<< "\nAge: " << a.age
			<< "\nSatiety: " << std::setprecision(4) << a.satiety
			<< "\nFatigue: " << std::setprecision(4) << a.fatigue << std::endl;
	}
}

void Zoo::liveAnimal(const int N)
{
	for (int h = 0; h < 16; h++)
	{
		float visitors = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		std::cout << "\n" << h + 1 << " hours have passed" << std::endl;
		std::printf("%.2f visition\n\n", visitors);
		for (int i = 0; i < animals.size(); i++)
		{
			if (animals[i].satiety < 30)
			{
				std::cout << animals[i].type << " " << animals[i].name
					<< " is hungry! fat: " << std::setprecision(4) << animals[i].fatigue
					<< " sat: " << std::setprecision(4) << animals[i].satiety << std::endl;
				animals[i].flag_e = true;
			}
			else if (animals[i].fatigue > 80 && !animals[i].flag_e)
			{
				std::cout << animals[i].type << " " << animals[i].name
					<< " is tired! fat: " << std::setprecision(4) << animals[i].fatigue
					<< " sat: " << std::setprecision(4) << animals[i].satiety << std::endl;
				animals[i].flag_s = true;
			}
			else if (!animals[i].flag_e && !animals[i].flag_s)
			{
				int action = rand() % 3;
				switch (action)
				{
				case 0: //plays with animal
					for (int k = 0; k < animals.size(); k++)
					{
						int count = rand() % N;
						if (i != count)
						{
							if (animals[i].type == animals[count].type) {
								animals[i].decreaseSatiety(visitors);
								animals[i].increaseFatigue(visitors);
								animals[i].playA(animals[count]);
								break;
							}
						}
					}
					break;
				case 1: //plays with visitor
					animals[i].decreaseSatiety(visitors + 1);
					animals[i].increaseFatigue(visitors + 1);
					animals[i].playV();
					break;
				case 2:
					animals[i].vFeeds();
					break;
				case 3: //nothing
					std::cout << animals[i].type << " " << animals[i].name
						<< " is well-food and restless! fat:"
						<< std::setprecision(4) << animals[i].fatigue
						<< " sat: " << std::setprecision(4) 
						<< animals[i].satiety << std::endl;
					animals[i].decreaseSatiety(visitors);
					animals[i].increaseFatigue(visitors);
					break;
				}
			}
			if (animals[i].flag_e)
			{
				animals[i].eatingRoom();
				std::cout << animals[i].type << " " << animals[i].name
					<< " is eating! fat: " << std::setprecision(4) << animals[i].fatigue
					<< " sat: " << std::setprecision(4) << animals[i].satiety << std::endl;
			}
			else if (animals[i].flag_s)
			{
				animals[i].sleepingRoom();
				std::cout << animals[i].type << " " << animals[i].name
					<< " is sleeping! fat: " << std::setprecision(4) << animals[i].fatigue
					<< " sat: " << std::setprecision(4) << animals[i].satiety << std::endl;
			}
		}
	}
}