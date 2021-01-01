#include<stdio.h>
#include<math.h>
int n = 9;
int k = 5;
int x[100];
int arr[100];

void displayarr(int* arr)
{
	for (int j = 1; j <= k; j++)
		printf("%2d", arr[j]);
	puts("");
}

int check(int v, int h)
{
	if (abs(v - x[h - 1]) > 1 && arr[v] == 0) return 1;
	return 0;
}

void TRY(int h)
{
	for (int v = 1; v <= n; v++)
	{
		if (check(v, h))
		{
			x[h] = v;
			arr[v] = 1;
			if (h == k) displayarr(x);
			else
				TRY(h + 1);
			arr[v] = 0;
		}
	}
}

int main()
{
	x[0] = -1;
	TRY(1);
	return 0;
}