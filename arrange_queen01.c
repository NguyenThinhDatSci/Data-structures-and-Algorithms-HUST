#include<stdio.h>

int n = 4;
int x[100];

void display_arr(int* arr)
{
	for (int i = 1; i <= n; i++)
	{
		printf("%d", arr[i]);
	}
	puts("");
}

int check(int k, int v)
{
	for (int i = 1; i < k; i++)
	{
		if ((v == x[i]) || (v + k == x[i] + i) || (v - k == x[i] - i)) return 0;
	}
	return 1;
}

void TRY(int k)
{
	for (int v = 1; v <= n; v++)
	{
		if (check(k,v))
		{
			x[k] = v;
			if (k == n) display_arr(x);
			else
				TRY(k + 1);
		}
	}
}

int main()
{
	for (int i = 1; i <= n; i++)
	{
		x[i] = 0;
	}
	TRY(1);
	return 0;
}