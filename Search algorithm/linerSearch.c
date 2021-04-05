#include "Search.h"

int main()
{
	int n; // is the number of elements in the array
	scanf("%d", &n);
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	inputArray(a, n);
	int x; // is the value to look for
	scanf("%d", &x);
	printf("%d", linerSearch(x, n, a));
	return 0;
}