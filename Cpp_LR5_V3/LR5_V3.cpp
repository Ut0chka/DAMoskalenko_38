#include <iostream>
#include <ctime>
#include "Zoo.h"

/*
*function for output of a string with an error
*
* @param string err string with an error
*/
void errors(const std::string err);

/*
*main function for declaring variables and calling functions
*
* @return returns 1 if fail
* @return returns 0 if the program completed successfully
*/
int main()
{
	srand(time(0));

	bool flag = true;
	int day = 1;
	int N;
	std::cout << "Input numbers of animals(8-25)\n\
-> ";
	std::cin >> N;
	if (std::cin.fail() || N < 8 || N > 25) {
		errors("Wrong numbers of animals!");
		return 1;
	}
	Zoo zoo;
	zoo.fillZoo(N);
	zoo.printZoo();
	std::cout << "\n" << day << "rd November " << std::endl;
	zoo.liveAnimal(N);
	while (flag)
	{
		char next = ' ';
		std::cout << "\nDo you want to move to the next day?(y/n)\n\
-> ";
		std::cin >> next;
		switch (next)
		{
		case 'y':
			if (day < 31)
			{
				day++;
				std::cout << "\n" << day << "rd of November " << std::endl;
				zoo.liveAnimal(N);
			}
			else
				std::cout << "Zoo is closed for renovations";
			break;
		case 'n':
			std::cout << "Come back to our zoo!" << std::endl;
			flag = false;
			break;
		default:
			std::cout << "Invalid character entered" << std::endl;
			break;
		}
	}
	return 0;
}

void errors(const std::string err)
{
	std::cout << "Error: " << err << std::endl;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}