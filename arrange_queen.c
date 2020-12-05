#include<stdio.h>
int n = 5;
int arr[50][50];
int x[100];

void display_arr(int* arr)
{
	for (int i = 1; i <= n; i++)
	{
		printf("%d", arr[i]);
	}
	puts("");
}

void TRY(int k)
{
	for (int v = 1; v <= n; v++)
	{
		if (arr[v][k])
		{
			x[k] = v;
			for (int i = k; i <= n; i++)
			{
				if (arr[v][i]) arr[v][i] = 0;
			}
			for (int i = 0; v + i <= n || v - i >= 0; i++)
			{
				if (arr[v + i][k + i]) arr[v + i][k + i] = 0;
				if (v - i > 0 && arr[v - i][k + i]) arr[v - i][k + i] = 0;
			}
			if (k == n) display_arr(x);
			else
				TRY(k + 1);
			for (int i = k; i <= n; i++)
			{
				arr[v][i] = 1;
			}
			for (int i = 0; v + i <= n; i++)
			{
				if (arr[v + i][k + i] == 0)
				{
					arr[v + i][k + i] = 1;
					if (v - i > 0)
						arr[v - i][k + i] = 1;
				}
			}
		}
	}
}

int main()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) arr[i][j] = 1;
	}
	TRY(1);
	return 0;
}