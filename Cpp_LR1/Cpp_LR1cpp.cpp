#include <iostream>;


using namespace std;

int main() 
{
	int const A = 1001;
	int a[A];
	//заполняем массив целыми числами
	for (int i = 0; i < A; i++) {
		a[i] = i;

	}

	a[0] = a[1] = 0; //ноль и единица не являются простыми числами

	for (int i = 2; i * i < A; i++)
		if (a[i]) {
			for (int j = i * i; j < A; j += i) //обнуляем все числа, кратные числу i
				a[j] = 0;
		}

	//выводим массив
	for (int i = 0; i < A; i++)
	{	
		if (a[i]) 
			cout << a[i] << " ";

	}
	cin.get();
}