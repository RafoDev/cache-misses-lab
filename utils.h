#include <iostream>
#include <cstdlib>
using namespace std;

#define _N 1000

void fillMatrices(int a[][_N], int b[][_N], int n)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
			b[i][j] = rand() % 100;
		}
	}
}

void printMatrix(int m[][_N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << m[i][j] << ' ';
		}
		cout << '\n';
	}
}
