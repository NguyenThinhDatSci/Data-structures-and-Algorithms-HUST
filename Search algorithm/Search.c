#pragma once
#include "Search.h"

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

int binarySearch(int x, int* a, int left, int right)
{
	if (left == right)
		if (a[left] == x) return left;
		else
			return -1;
	int mid = (left + right) / 2;
	if (a[mid] == x) return mid;
	if (a[mid] > x) return binarySearch(x, a, left, mid);
	if (a[mid] < x) return binarySearch(x, a, mid, right);
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
