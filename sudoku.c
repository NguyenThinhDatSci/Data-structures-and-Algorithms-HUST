#include<stdio.h>
int x[9][9];

int check(int h, int k, int v)
{
	int i;
	// xet hang ngang
	for (i = 0; i < h; i++)
	{
		if (v == x[i][k]) return 0;
	}
	// xet hang doc
	for (i = 0; i < k; i++)
	{
		if (v == x[h][i]) return 0;
	}
	// diem nhan cua bai
	int I = h / 3, J = k / 3;
	i = h - 3 * I;
	// xet o 3x3
	int i1;
	for (i1 = 0; i1 <= i - 1; i1++)
		for (int j1 = 0; j1 <= 2; j1++)
			if (x[3 * I + i1][3 * J + j1] == v)
				return 0;
	return 1;
}

void displayarr(int arr[][9])
{
	int i;
	for (i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%2d", arr[i][j]);
		puts("");
	}
	puts("");
}

void TRY(int h, int k)
{
	for (int v = 1; v <= 9; v++)
	{
		// x[8][8] == 0 la dk de chi in ra 1 sudoku thoa man
		// bo di de in ra tat ca
		if (check(h, k, v) && x[8][8] == 0)
		{
			x[h][k] = v;
			if (h == 8 && k == 8)
			{
				displayarr(x);
			}
			else
				if (k == 8) TRY(h + 1, 0);
				else
					TRY(h, k + 1);;
		}
	}
}

int main()
{
	TRY(0, 0);
	return 0;
}