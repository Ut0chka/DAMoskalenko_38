#include <iostream>;


using namespace std;


void fill(int* a, const int N);
void func_for_prime(int* a, const int N);
void print(int* a, const int N);

int main() 
{
	const int N = 10;
	int* a = new int[N];
	fill(a, N);
	func_for_prime(a, N);
	print(a, N);
	delete[] a;

	
	cin.get();
}
void fill(int* a, const int N) {
	//fill array with integers
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
		//cout << a[i] << " ";
	}
}
void func_for_prime(int* a, const int N)
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