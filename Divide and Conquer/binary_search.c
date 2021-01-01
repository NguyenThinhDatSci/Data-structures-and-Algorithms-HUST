#include<stdio.h>
#include<limits.h>
int n;
int* x;

void show_arr()
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", x[i]);
	}
	puts("");
}

void readFile()
{
	FILE* f = fopen("C:\\Users\\Nguyen Thinh\\Desktop\\NguyenThinhDatSci\\Data-structures-and-Algorithms-HUST\\BS-test.txt", "r");
	fscanf(f,"%d", &n);

	x = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		fscanf(f,"%d", x + i);
	fclose(f);
	show_arr();
}

int binarySearch(int *x, int start, int finish, int v)
{
	if (start == finish)
		if (x[start] == v)
			return start;
		else
			return INT_MAX;
	else
	{
		int m = (finish + start) / 2;
		if (x[m] == v) return m;
		else
			if (x[m] < v) return binarySearch(x, m + 1, finish, v);
			else
				return binarySearch(x, start, m - 1, v);
	}
}

int main()
{
	readFile();
	int value = binarySearch(x, 0, n - 1, 0);
	if (value == INT_MAX) printf("NO FIND OUT");
	else
		printf("%d", value);
	return 0;
}