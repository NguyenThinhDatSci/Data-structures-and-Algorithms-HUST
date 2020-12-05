#include<stdio.h>
int n = 3;
int arr[3];

void display_arr(int *arr)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
	puts("");
}

void TRY(int k)
{
	for (int v = 0; v <= 1; v++)
	{
		arr[k] = v;
		if (k == n - 1) display_arr(arr);
		else
			TRY(k + 1);
	}
}

int main()
{
	TRY(0);
	return 0;
}