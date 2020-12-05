#include<stdio.h>
int arr[100][100];

int C(int n, int k)
{
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;
	if (arr[n][k] == 0)
	{
		arr[n][k] = C(n - 1, k) + C(n - 1, k - 1);
	}
	return arr[n][k];
}
int main()
{
	printf("%d", C(6, 3));
	return 0;
}