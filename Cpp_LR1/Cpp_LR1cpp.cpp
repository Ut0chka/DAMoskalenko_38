#include <iostream>;


using namespace std;

int main() 
{
	int const A = 1001;
	int prime[A];
	//fill array with integers
	for (int i = 0; i < A; i++) {
		prime[i] = i;

	}

	prime[0] = prime[1] = 0; //0 and 1 aren't prime numbers

	for (int i = 2; i * i < A; i++)
		if (prime[i]) {
			for (int j = i * i; j < A; j += i) //reset all the numbers that are multiples of the number "i"
				prime[j] = 0;
		}

	//output array on console
	for (int i = 0; i < A; i++)
	{	
		if (prime[i])
			cout << prime[i] << " ";
	}
	cin.get();
}