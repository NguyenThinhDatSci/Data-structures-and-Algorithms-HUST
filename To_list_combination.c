#include<stdio.h>
int n = 3;
int m = 4;
int arr[100];

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
	for (int v = arr[k - 1] + 1; v <= m - n + k; v++)
	{
		arr[k] = v;
		if (k == n) display_arr(arr);
		else
			TRY(k + 1);
	}
}

int main()
{
	arr[0] = 0;
	TRY(1);
	return 0;
}