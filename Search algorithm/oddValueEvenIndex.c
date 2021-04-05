//  in ra những phần tử lẻ ở chỉ số chẵn, sau mỗi phần tử có đúng một dấu cách, nếu không có phần tử nào thõa mãn thì in ra "NULL"
#include "Search.h"

int main()
{
	int n; // is the number of elements in the array
	scanf("%d", &n);
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	inputArray(a, n);
	oddValueEvenIndex(a, n);
	return 0;
}