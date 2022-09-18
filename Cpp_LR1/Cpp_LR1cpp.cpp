#include <iostream>;


using namespace std;

int main() 
{
	int const A = 1001;
	int a[A];
	//fill array with integers
	for (int i = 0; i < A; i++) {
		a[i] = i;

	}

	a[0] = a[1] = 0; //0 and 1 aren't prime numbers

	for (int i = 2; i * i < A; i++)
		if (a[i]) {
			for (int j = i * i; j < A; j += i) //reset all the numbers that are multiples of the number "i"
				a[j] = 0;
		}

	//output array on console
	for (int i = 0; i < A; i++)
	{	
		if (a[i]) 
			cout << a[i] << " ";

	}
	cin.get();
}