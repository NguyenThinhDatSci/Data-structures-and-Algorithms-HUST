#include<stdio.h>
#include<string.h>
int* x, * y;
int** arr;
int m, n;

void show_2DimenArr(int** arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d", arr[i][j]);
		puts("");
	}
}
void show_1DimenArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%3d", arr[i + 1]);
	}
	puts("");
}

void readfile()
{
	FILE* f = fopen("C:/Users/Nguyen Thinh/Desktop/NguyenThinhDatSci/Data-structures-and-Algorithms-HUST/Dynamic programming/cs.txt", "r");
	fscanf(f, "%d%d", &m, &n);

	x = (int*)malloc(sizeof(int) * m);
	y = (int*)malloc(sizeof(int) * n);
	for (int i = 1; i <= m; i++)
		fscanf(f, "%d", x + i);
	for (int i = 1; i <= n; i++)
		fscanf(f, "%d", y + i);
	arr = (int**)calloc(sizeof(int*) * m);
	for (int i = 0; i <= m; i++)
	{
		arr[i] = (int*)calloc(sizeof(int) * n);
	}
	fclose(f);
	show_1DimenArr(x, m);
	show_1DimenArr(y, n);
	//show_2DimenArr(arr, m, n);
}

void solution()
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (arr[i] = y[j]) arr[i - 1][j - 1] += 1;
			else
			{
				arr[i][j] = x[i - 1];
				if (x[i - 1] > y[j - 1]) arr[i][j] = y[j - 1];
			}
		}
}

int main()
{
	readfile();
;	return 0;
}