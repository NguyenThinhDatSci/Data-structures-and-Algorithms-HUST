#include<stdio.h>
int n;
int x[1];
int arr[1];
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void show_oneDimenArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%3d", arr[i]);
	}
	puts("");
}

void show_2DimenArr(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d", arr[i][j]);
	}
	puts("");
}

void sort_arr()
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (x[j] < x[i]) swap(&x[i], &x[j]);
}

void main()
{

}