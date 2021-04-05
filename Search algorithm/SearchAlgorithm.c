#pragma once
#include "SearchAlgorithm.h"

void inputArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
}

void showArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int linerSearch(int x, int n, int* a)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) return i;
	}
	return -1;
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void swapFirstMinLastMax(int* a, int n)
{
	int minIndex = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[minIndex] < a[i]) minIndex = i;
		if (a[maxIndex] >= a[i]) maxIndex = i;
	}
	swap(&a[minIndex], &a[maxIndex]);
}

int numberOf_x_value(int* a, int n, int x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) count++;
	}
	return count;
}

int binarySearch(int* a, int n, int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid] < x) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	if (a[l] == x) {
		return l;
	}
	return -1;
}

bool sumOfConsecutiveArrElements(int* a, int n, int sum)
{
	int* b = (int*)malloc(sizeof(int) * n); // Array b is used to save sum of consecutive from a[0] to a[i]
	b[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		b[i] = a[i] + b[i - 1];  // declare array b
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] == sum)
		{
			printFromTo(a, 0, i); // display from a[0] to a[i] on screen
			return true;
		}
		/* WAY 01
		if (b[i] < sum)
		{	
			int index = binarySearch(b, n, sum + b[i]);
			if (index > 0)
			{
				printFromTo(a, ++i, index);
				return true;
			}
		}
		*/
		if (b[i] > sum)
		{
			int index = binarySearch(b, n, b[i] - sum); // look for b[index] = b[i] - sum in array b
			if (index > -1)								// b[index] = a0 + a1 + ... +a[index]
			{											// b[i] =  a0 + a1 + ... +a[index] + ... + a[i]
				printFromTo(a, ++index, i); // display from a[index + 1] to a[i] on screen
				return true;
			}
		}
	}
	return false;
}

void printFromTo(int* a, int top, int end)
{
	for (int i = top; i <= end; i++)
	{
		printf("%d ", a[i]);
	}
}

void oddValueEvenIndex(int* a, int n)
{
	int mark = 1;
	for (int i = 0; i < n; i += 2)
	{
		if (a[i] % 2)
		{
			printf("%d ", a[i]);
			mark = 0;
		}
	}
	if (mark) printf("NULL");
}
