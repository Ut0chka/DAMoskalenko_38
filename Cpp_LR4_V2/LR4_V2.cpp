#include <iostream>
#include <ctime>
#include "Animal.h"
#include "Zoo.h"

using namespace std;

int main()
{
	srand(time(0));
	int N;
	cout << "¬ведите количество животных:\n\
-> ";
	cin >> N;
	Zoo zoo;
	vector<Animal> animals = zoo.fillZoo(N);
	zoo.printZoo(animals);
	return 0;
}