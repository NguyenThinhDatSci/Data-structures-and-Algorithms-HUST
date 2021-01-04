#include<stdio.h>
int x[9][9];
int y[81];

void displayArr()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%3d", x[i][j]);
		puts("");
	}
	puts("");
}

void readfile()
{
	FILE* f = fopen("C:/Users/Nguyen Thinh/Desktop/NguyenThinhDatSci/Data-structures-and-Algorithms-HUST/Backtracking/sudokuAdvanced.txt", "r");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			fscanf(f, "%d", &x[i][j]);
	}
	fclose(f);
	displayArr();
}

void show_y_array()
{
	for (int i = 0; i < 81; i++)
	{
		printf("%3d", y[i]);
	}
	puts("");
}

void save_existing_location()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			if (x[i][j] != 0) y[9 * i + j] = 1;
	}
	show_y_array();
}

int check(int r, int c, int v)
{
	for (int i = 0; i < 9; i++)
	{
		if (v == x[i][c] && i != r) return 0;
	}
	for (int i = 0; i < 9; i++)
	{
		if (v == x[r][i] && i != c) return 0;
	}
	int I = r / 3, J = c / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <= 2; j++)
			if (((i + 3 * I != r) || (j + 3 * J != c)) && v == x[i + 3 * I][j + 3 * J]) return 0;
	}
	return 1;
}

void TRY(int r, int c)
{
	int a;
	displayArr();
	scanf("%d", &a);
	puts("");
	for (int v = 1; v <= 9; v++)
	{
		if (y[9 * r + c])
			if (r == 8 && c == 8) displayArr();
			else
				if (c == 8) TRY(r + 1, 0);
				else
					TRY(r, c + 1);
		else
			if (check(r, c, v) && x[8][8] == 0)
			{
				x[r][c] = v;
				if (r == 8 && c == 8) displayArr();
				else
					if (c == 8) TRY(r + 1, 0);
					else
						TRY(r, c + 1);
			}
	}
}

int main()
{
	readfile();
	save_existing_location();
	TRY(0, 0);
	return 0;
}