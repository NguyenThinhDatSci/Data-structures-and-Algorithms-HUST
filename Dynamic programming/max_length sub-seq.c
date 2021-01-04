#include<stdio.h>
int n;
int* x;
int s[100];

void readfile()
{
	FILE* f = fopen("C:/Users/Nguyen Thinh/Desktop/NguyenThinhDatSci/Data-structures-and-Algorithms-HUST/MSS(dp).txt", "r");
	fscanf(f, "%d", &n);

	x = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d", x + i);
		//printf("%3d", x[i]);
	}
	fclose(f);
}

void solution()
{
	readfile();
	s[0] = 1;
	int rs = s[0];
	for (int i = 1; i < n; i++)
	{
		s[i] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (x[i] > x[j])
				if (s[j] + 1 > s[i])
				{
					s[i] = s[j] + 1;
				}
		}
		rs = rs > s[i] ? rs : s[i];
	}
	printf("%d\n", rs);
}

int main()
{
	solution();
	return 0;
}