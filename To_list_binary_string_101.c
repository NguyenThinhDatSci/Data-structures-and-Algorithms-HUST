#include<stdio.h>
int arr[4];
int n = 4;


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
	for (int v = 0; v <= 1; v++)
	{
		//if (arr[k - 1] == 0 || (arr[k - 1] == 1 && v != 1))
		if (arr[k - 1] + v < 2)
		{
			arr[k] = v;
			if (k == n) display_arr(arr);
			else
				TRY(k + 1);
		}
	}
}

int main()
{
	arr[0] = 0;
	TRY(1);
	return 0;
}