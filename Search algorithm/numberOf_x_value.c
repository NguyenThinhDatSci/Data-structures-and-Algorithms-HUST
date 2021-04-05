// số nguyên x, hãy đếm xem trong dãy a có bao nhiêu phần tử có giá trị bằng x

#include "Search.h"

int main()
{
	int n; // is the number of elements in the array
	scanf("%d", &n);
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	inputArray(a, n);
	int x; // is the value to be counted
	scanf("%d", &x);
	printf("%d", numberOf_x_value(a, n, x));
	return 0;
}