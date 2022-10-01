#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

/*
*Allocate memory for a two-dimensional N*N array
*
* @param N the size of the array that the user enters
* @return pointer to pointer to 2d array
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
*function to fill the array for playing minesweeper
*
* @param **a array N*N
* @param N the size of the array that the user enters
*/
void minesweeper(int** a, const int N);

/*
*function to display the resulting array on the console
*
* @param **a array N*N
* @param N the size of the array that the user enters
*/
void print(int** a, const int N);

/*
*function for output of a string with an error
*
* @param string err string with an error
*/
void errors(const string err);

/*
*main function for declaring variables and calling functions, as well as the implementation of the switch
*
* @return returns 0 if the program completed successfully
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Enter the size of the two-dimensional array N*N:\n\
-> ";
	std::cin >> N;
	if (std::cin.fail() || N <= 0) {
		errors("Wrong array size!");
		return 0;
	}
	cout << endl;
	int** arr = memAlloc(N);
	nullArr(arr, N);
	bool flag = true;
	while (flag) {
		cout << "Dear User, choose an action:\n \
	1.Clear the array and fill it with 0.\n \
	2.Fill the array so that it has the property of symmetry with respect to the main diagonal.\n \
	3.Fill the array so that it has the property of symmetry with respect to the side diagonal.\n \
	4.To fill the array so that it is a Pascal triangle.\n \
	5.To carry out the filling of the array for the minesweeper game.\n\
	6. Output.\n \
-> ";
		int action;
		std::cin >> action;
		if (std::cin.fail()) {
			errors("Enter a number from 1 to 6!");
		}
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
			minesweeper(arr, N);
			print(arr, N);
			break;
		case 6:
			flag = false; //exit from while loop
			break;
		default:
			cout << "Enter a number from 1 to 6!\n";
			break;
		}
	}
	cout << "See you later!";
	std::cin.get();
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
	cout << endl;
}

void symmetricMatrixMainDiagonal(int** a, const int N)
{
	srand(time(0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				a[i][j] = 1;
			else
				a[i][j] = a[j][i];
		}
	}
}

void symmetricMatrixSideDiagonal(int** a, const int N)
{
	srand(time(0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = rand() % 10;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (i + j == N - 1)
				a[i][j] = 1;
			else
				a[i][j] = a[N-1-j][N-1-i];
		}
	}
}

void trianglePascal(int** a, const int N)
{
	a[0][0] = 1;
	if (N == 1) return;
	a[1][0] = 1;
	a[1][1] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			if ((j == 0))
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
}

void minesweeper(int** a, const int N)
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
	cout << endl;
}

void errors(const string err)
{
	cout << "Error: " << err << endl;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}