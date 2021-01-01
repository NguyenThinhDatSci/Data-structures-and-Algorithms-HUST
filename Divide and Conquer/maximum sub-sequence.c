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
	FILE* f = fopen("C:/Users/Nguyen Thinh/Desktop/NguyenThinhDatSci/Data-structures-and-Algorithms-HUST/MSS.txt", "r");
	fscanf(f, "%d", &n);

	x = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		fscanf(f, "%d", x + i);
	fclose(f);
	show_arr();
}

int maxLeft(int* x, int l, int r)
{
	int max = INT_MIN;
	int sum = 0;
	for (int i = r; i >= l; i--)
	{
		sum += x[i];
		if (sum > max) max = sum;
	}
	return max;
}

int maxRight(int* x, int l, int r)
{
	int max = INT_MIN;
	int sum = 0;
	for (int i = l; i <= r; i++)
	{
		sum += x[i];
		if (sum > max) max = sum;
	}
	return max;
}

int maxSeq(int* x, int l, int r)
{
	if (l == r) return x[l];
	int mid = (l + r) / 2;
	//device
	int mL = maxSeq(x, l, mid);
	int mR = maxSeq(x, mid + 1, r);
	//conquer
	int mS = maxLeft(x, l, mid) + maxRight(x, mid + 1, r);
	int max = mL;
	if (max < mR) max = mR;
	if (max < mS) max = mS;
	return max;
}

int main()
{
	readFile();
	printf("%d", maxSeq(x, 0, n - 1));
	return 0;
}