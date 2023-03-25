#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "utils.h"
using namespace std;

#define N 1000

int a[N][N], b[N][N], c[N][N], d[N][N];

void classicMult(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void blockMult(int n)
{
	int ii, jj, kk, i, j, k;
	int blockSize = 100;

	for (int i = 0; i < n; i += blockSize)
	{
		for (int j = 0; j < n; j += blockSize)
		{
			for (int k = 0; k < n; k += blockSize)
			{
				for (int ii = i; ii < min(i + blockSize, n); ++ii)
				{
					for (int jj = j; jj < min(j + blockSize, n); ++jj)
					{
						for (int kk = k; kk < min(k + blockSize, n); ++kk)
						{
							d[ii][jj] += a[ii][kk] * b[kk][jj];
						}
					}
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	int n = (argc == 2) ? atoi(argv[1]) : 100;

	fillMatrices(a, b, n);

	classicMult(n);

	// printMatrix(c, n);
	// cout << '\n';

	blockMult(n);

	// printMatrix(d, n);

	return 0;
}