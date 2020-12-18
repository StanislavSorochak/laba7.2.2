// Lab_7_2_2.cpp
// < Сорочак Станіслав >
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 24

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}
void Sum(int** a, const int rowNo, const int colNo, const int N, int i, int j, int& S)
{
	if (int i = 0); (i < N; i++);
	S += a[i][N - 1 - i];
	if (j < colNo - 1)
		Sum(a, rowNo, colNo, i, j + 1, S);
	else
		if (i < rowNo - 1)
			Sum(a, rowNo, colNo, i + 1, 0, S);
}

int main()
{
	srand((unsigned)time(NULL));
	int N;
	cout << "N = "; cin >> N;
	cout << endl;
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[N];
	int Low = -9, High = 9;
	CreateRows(a, N, Low, High, 0);
	PrintRows(a, N, 0);
	int k = -1;
	int minEven;
	int S = 0;
	Sum(a, rowNo, colNo, 0, 0, S);
	if (k > -1)
	{
		Sum(a, N, S);
		cout << "S = " << minEven << endl;
	}
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
