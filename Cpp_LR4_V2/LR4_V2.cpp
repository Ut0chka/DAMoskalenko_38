#include <iostream>
#include <ctime>
#include "Zoo.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	srand(time(0));
	int N;
	bool flag = true;
	cout << "Input numbers of animals:\n\
-> ";
	cin >> N;
	Zoo zoo;
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