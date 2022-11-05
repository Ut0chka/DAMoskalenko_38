#include <iostream>
#include <ctime>
#include "Zoo.h"

using std::cout;
using std::cin;
using std::endl;

/*
*main function for declaring variables and calling functions
*
* @return returns 1 if fail
* @return returns 0 if the program completed successfully
*/
int main()
{
	srand(time(0));
	int N;
	bool flag = true;
	Zoo zoo;
	cout << "Input numbers of animals (1-25):\n\
-> ";
	cin >> N;
	if (std::cin.fail() || N < 1 || N > 25) {
		zoo.errors("Wrong numbers of animals!");
		return 1;
	}
	zoo.fillZoo(N);
	zoo.printZoo();
	while (flag)
	{
		cout << "Do you want to add another animal?(y/n)\n\
-> ";
		char choise = ' ';
		cin >> choise;
		switch (choise)
		{
		case 'y':
			zoo.addAnimal();
			zoo.printZoo();
			break;
		case 'n':
			zoo.liveAnimal();
			flag = false;
			break;
		default:
			cout << "Invalid character entered" << endl;
			break;
		}
	}
	return 0;
}