#include <iostream>
#include <iomanip>

using namespace std;

/*
*Allocate memory for a two-dimensional N*N array
*
* @param N the size of the array that the user enters
*/
int** memAlloc(const int N);

/*
*function to fill an array with zeros
* 
* @param **a array N*N
* @param N the size of the array that the user enters
*/
void nullArr(int** a, const int N);

/*
*function to fill the array so that it has the property of symmetry with respect to the main diagonal
*
* @param **a array N*N
* @param N the size of the array that the user enters
*/
void symmetricMatrixMainDiagonal(int** a, const int N);

/*
*function to fill the array so that it has the property of symmetry with respect to the secondary diagonal
*
* @param **a array N*N
* @param N the size of the array that the user enters
*/
void symmetricMatrixSideDiagonal(int** a, const int N);

/*
*function to fill the array so that it is Pascal's triangle
*
* @param **a array N*N
* @param N the size of the array that the user enters
*/
void trianglePascal(int** a, const int N);

/*
*function to fill the array for playing sapper
*
* @param **a array N*N
* @param N the size of the array that the user enters
*/
void sapper(int** a, const int N);

/*
*function to display the resulting array on the console
*
* @param **a array N*N
* @param N the size of the array that the user enters
*/
void print(int** a, const int N);

/*
*main function for declaring variables and calling functions, as well as the implementation of the switch
*
* @return returns 0 if the program completed successfully
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите размер двумерного массива N*N:\n";
	cin >> N;
	cout << endl;
	int** arr = memAlloc(N);
	nullArr(arr, N);
	while (true) {
		cout << "Уважаемый пользователь, выберите действие:\n \
	1.Очистить массив и заполнить его 0.\n \
	2.Провести заполнение массива так, что бы он обладал свойством симметричности относительно главной диагонали.\n \
	3.Провести заполнение массива так, что бы он обладал свойством симметричности относительно побочной диагонали.\n \
	4.Провести заполнения массива так, что бы он являлся треугольником Паскаля.\n \
	5.Провести заполнения массива для игры в сапера.\n \
	6. Выход.\n";
		int action;
		cin >> action;
		switch (action)
		{
		case 1:
			nullArr(arr, N);
			break;
		case 2:
			symmetricMatrixMainDiagonal(arr, N);
			print(arr, N);
			break;
		case 3:
			symmetricMatrixSideDiagonal(arr, N);
			print(arr, N);
			break;
		case 4:
			trianglePascal(arr, N);
			print(arr, N);
			break;
		case 5:
			sapper(arr, N);
			print(arr, N);
			break;
		case 6:
			goto breakAll; //exit from while loop
			break;
		default:
			cout << "Вы не ввели верное число(от 1 до 5)\n";
			break;
		}
	}
breakAll:
	puts("До новых встреч!");
	cin.get();
	return 0;
}

int** memAlloc(const int N)
{
	int** a = new int* [N];
	for (int i = 0; i < N; i++) {
		a[i] = new int[N];
	}
	return a;
}

void nullArr(int** a, const int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = 0;
			cout << setw(3) << a[i][j] << " | "; //func setw - change the width of the next I/O
		}
		cout << endl;
	}
}

void symmetricMatrixMainDiagonal(int** a, const int N)
{
	for (int i = 0; i < N; i++) {
		a[i] = new int[N];
		for (int j = 0; j < N; j++) {
			if (i == j)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
}

void symmetricMatrixSideDiagonal(int** a, const int N)
{
	for (int i = N - 1; i >= 0; i--) {
		a[i] = new int[N];
		for (int j = N - 1; j >= 0; j--) {
			if (i + j == N - 1)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
}

void trianglePascal(int** a, const int N)
{
	a[0][0] = 1;
	a[1][0] = 1;
	a[1][1] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			if ((j == 0) || (j == N + 1))
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
}

void sapper(int** a, const int N)
{
	srand(time(0));
	int bombs = 0;
	int num_of_bombs_around_cell = 0;
	//depending on size of array, there will be a certain num of bombs
	if (N >= 3 && N <= 5)
		bombs = 5;
	else if (N > 5 && N <= 10)
		bombs = 10;
	else if (N > 10)
		bombs = 25;
	else
	{
		cout << "Ошибочка!";
		return;
	}
	//arrangement bomb
	for (int i = 0; i <= bombs; i++)
	{
		a[0 + rand() % N][0 + rand() % N] = -1;
	}
	//arrangement of nums on the field
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] != -1)//bombs don't count
			{
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int l = j - 1; l <= j + 1; l++)
					{
						if (k < 0 || k > N - 1 || l < 0 || l > N - 1)//bounds check
						{
							continue;
						}
						else
						{
							if (a[k][l] == -1)
							{
								num_of_bombs_around_cell++;
							}
						}
					}
				}
				a[i][j] = num_of_bombs_around_cell;
				num_of_bombs_around_cell = 0;
			}
		}
	}
}

void print(int** a, const int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(3) << a[i][j] << " | ";
		}
		cout << endl;
	}
}