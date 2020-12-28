#include<stdio.h>
int N = 5;
int sum = 0;
int x[100];

void displayarr(int n)
{
	for (int j = 1; j <= n; j++)
		printf("%2d", x[j]);
	puts("");
}

int check(int v, int n)
{
	if (v > N - n + 1) return 0;
	return 1;
}

void TRY(int k, int n)
{
	for (int v = x[k - 1]; v <= N - sum; v++)
	{
		if (check(v, n))
		{
			x[k] = v;
			sum += v;
			if (k == n && sum == N) displayarr(n);
			else
				TRY(k + 1, n);
			sum -= v;
		}
	}
}

int main()
{
	x[0] = 1;
	for (int n = 2; n <= N; n++)
		TRY(1, n);
	return 0;
}