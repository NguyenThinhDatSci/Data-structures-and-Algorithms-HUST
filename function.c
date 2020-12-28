#include<stdio.h>
int n;
int x[1];
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
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