#include "SearchAlgorithm.h"

int main()
{
	int n;
	scanf("%d", &n);
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	inputArray(a, n);
	int sum;
	scanf("%d", &sum);
	if (!sumOfConsecutiveArrElements(a, n, sum)) printf("-1");
	return 0;
}