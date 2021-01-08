#include<stdio.h>
int n = 10000, a[] = { 2, 0, 1, 0, 3, 8, 7, 5, 4, 12 };

void showArr()
{
	for (int i = 0; i < n; i++)
	{
		printf("%3d", a[i]);
	}
	puts("");
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void quicksort(int L, int N) 
{
	if (L != N)
	{
		int count = 0;
		for (int i = L + 1; i < N; i++)
		{
			if (a[i] < a[L]) count++;
		}
		if (count)
		{
			swap(&a[count + L], &a[L]);
			int j = 0;
			for (int i = 0; j != count; i++)
			{
				if (a[i] < a[count + L])
				{
					swap(&a[i], &a[j]);
					j++;
				}
			}
			quicksort(L, L + count);
		}
		quicksort(L + count + 1, N);
	}
}

int main()
{
	quicksort(0, n);
	showArr();
	return 0;
}