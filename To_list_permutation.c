#include<stdio.h>
int n = 3;
int arr[100];
int sign[100];


void display_arr(int* arr)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
	puts("");
}

void TRY(int k)
{
	for (int v = 1; v <= n; v++)
	{
		if (sign[v])
		{
			sign[v] = 0;
			arr[k] = v;
			if (k == n - 1) display_arr(arr);
			else
				TRY(k + 1);
			sign[v] = 1;
		}
	}
}

int main()
{
	for (int i = 1; i <= n; i++)
	{
		sign[i] = 1;
	}
	TRY(0);
	return 0;
}