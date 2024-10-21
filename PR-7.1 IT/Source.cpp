// Lab_7_1.cpp
// < Кащук, Андрій >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 12
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Print(int** a, const int rowCount, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);
void Delete(int** a, int rowCount);
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int col1, const int col2, const int rowCount);
void rowmem(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int rC = 9;
	int	cC = 6;
	int low = -21;
	int high = 34;
	int S = 0;
	int k = 0;
	int** a = new int* [rC];

	rowmem(a,rC,cC);

	Create(a,rC,cC,low,high);

	Print(a, rC, cC);

	Calc(a, rC, cC, S, k);

	Print(a, rC, cC);

	Sort(a,rC,cC);

	Print(a, rC, cC);

	return 0;
}
void rowmem(int** a,const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
}
void Create(int** a, const int rowCount, const int colCount, const int Low,const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((a[0][i1] < a[0][i1 + 1])
				||
				(a[0][i1] == a[0][i1 + 1] &&
					a[1][i1] < a[1][i1 + 1])
				||
				(a[0][i1] == a[0][i1 + 1] &&
					a[1][i1] == a[1][i1 + 1] &&
					a[2][i1] > a[2][i1 + 1]))
				Change(a, i1, i1 + 1, rowCount);
}
void Change(int** a, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = a[j][col1];
		a[j][col1] = a[j][col2];
		a[j][col2] = tmp;
	}
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] % 3 == 0 && !(a[i][j]<0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
}

void Delete(int** a,int rowCount)
{
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
}

