#include <iostream>;


using namespace std;

int main() 
{
	int const A = 1001;
	int a[A];
	//��������� ������ ������ �������
	for (int i = 0; i < A; i++) {
		a[i] = i;

	}

	a[0] = a[1] = 0; //���� � ������� �� �������� �������� �������

	for (int i = 2; i * i < A; i++)
		if (a[i]) {
			for (int j = i * i; j < A; j += i) //�������� ��� �����, ������� ����� i
				a[j] = 0;
		}

	//������� ������
	for (int i = 0; i < A; i++)
	{	
		if (a[i]) 
			cout << a[i] << " ";

	}
	cin.get();
}