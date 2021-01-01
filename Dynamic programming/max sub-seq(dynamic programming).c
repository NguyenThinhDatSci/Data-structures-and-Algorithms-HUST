#include<stdio.h>
#include<limits.h>
int n;
int* x;

void readFile()
{
	FILE* f = fopen("C:/Users/Nguyen Thinh/Desktop/NguyenThinhDatSci/Data-structures-and-Algorithms-HUST/MSS.txt", "r");
	fscanf(f, "%d", &n);

	x = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		fscanf(f, "%d", x + i);
	fclose(f);
	//show_arr();
}

int maxSeq()
{
	int sum = 0;
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (sum >= 0)
		{
			sum += x[i];
			if (max < sum) max = sum;
		}
		else
			sum = x[i];
	}
	return max;
}

int main()
{
	readFile();
	printf("%d", maxSeq());
	return 0;
}