#include<stdio.h>
int N = 10;
int n = 4;
int sum = 0;
int x[100];

void displayarr(int* arr)
{
	for (int j = 0; j < n; j++)
		printf("%2d", arr[j]);
	puts("");
}

int check(int v)
{
	if (v > N - n + 1) return 0;
	return 1;
}

void TRY(int k)
{
	for (int v = 1; v <= N - sum; v++)
	{
		if (check(v))
		{
			x[k] = v;
			sum += v;
			if (k == n - 1 && sum == N) displayarr(x);
			else
				TRY(k + 1);
			sum -= v;
		}
	}
}

int main()
{
	TRY(0);
	return 0;
}