//Liệt kê tất cả các xâu nhị phân độ dài n trong đó không có 3 bit 1 nào đứng cạnh nhau
#include<stdio.h>
int n = 4;
int x[100];
int sum = 0;

void displayarr(int* arr)
{
	for (int j = 0; j < n; j++)
		printf("%2d", arr[j]);
	puts("");
}

void TRY(int k)
{
	for (int v = 0; v <= 1; v++)
	{
		if (sum + v < 3)
		{
			x[k] = v;
			sum += v;
			if (k == n - 1) displayarr(x);
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