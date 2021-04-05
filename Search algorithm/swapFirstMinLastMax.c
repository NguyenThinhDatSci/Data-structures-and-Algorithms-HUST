// Hãy hoán đổi phần tử nhỏ nhất đầu tiền và phần tử lớn nhất cuối cùng trong dãy đó
#include "Search.h"

int main()
{
	int n; // is the number of elements in the array
	scanf("%d", &n);
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	inputArray(a, n);
	swapFirstMinLastMax(a, n);
	showArray(a, n);
	return 0;
}