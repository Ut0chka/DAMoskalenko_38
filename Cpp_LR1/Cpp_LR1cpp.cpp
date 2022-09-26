#include <iostream>;


using namespace std;

/*
*fill array with integers
* 
* @param a array with integers
* @param N max number up to which need to find all prime numbers
*/
void fill(int* a, const int N);

/*
*Eratosthenes algorithm
* 
* @param a array with integers
* @param N max number up to which need to find all prime numbers
*/
void funcEratosthenes(int* a, const int N);

/*
*output array on console
*
* @param a array with prime numbers
* @param N max number up to which need to find all prime numbers
*/
void print(int* a, const int N);

/*
*main function for declaring variables and calling functions
* 
* @return returns 0 if the program completed successfully
*/
int main() 
{
	const int N = 30;
	int* a = new int[N];
	fill(a, N);
	funcEratosthenes(a, N);
	print(a, N);
	delete[] a;

	cin.get();
	return 0;
}
void fill(int* a, const int N) {
	//fill array with integers
	for (int i = 0; i < N; i++)
		a[i] = i;
}
void funcEratosthenes(int* a, const int N)
{
	//0 and 1 aren't prime numbers
	a[0] = a[1] = 0;
	for (int i = 2; i * i < N; i++)
	{
		if (a[i])
		{
			//reset all the numbers that are multiples of the number "i"
			for (int j = i * i; j < N; j += i)
				a[j] = 0;
		}
	}
}

void print(int* a, const int N)
{
	//output array on console
	for (int i = 0; i < N; i++)
	{
		if (a[i])
			cout << a[i] << " ";
	}
}