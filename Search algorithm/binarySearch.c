// Số nguyên n > 0 >> n số nguyên cũng một dãy a >> x
// dãy là dãy không giảm.
// Hãy đưa ra chỉ số của phần tử đầu tiên có giá trị bằng x, nếu không tồn tại giá trị đó đưa ra - 1
#include "SearchAlgorithm.h"

int main()
{
	int n; // is the number of elements in the array
	scanf("%d", &n);
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	inputArray(a, n);
	int x;	// is the value to look for
	scanf("%d", &x);
	int indexOfx = binarySearch(a, n, x);	// is the index of x in array
	printf("%d", indexOfx);
	return 0;
}