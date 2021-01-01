#include<stdio.h>
#include<limits.h>

int n;
int costSum = 0;
int cmin;
int x[100], trace[100];
int c[100][100];
int sign[100];
int min = INT_MAX;

void show_c()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d", c[i][j]);
		puts("");
	}
}

void inputReadFile() 
{
	FILE *f = fopen("C:\\Users\\Nguyen Thinh\\Desktop\\NguyenThinhDatSci\\Data-structures-and-Algorithms-HUST\\TSP-15.inp", "r");
	fscanf(f, "%d", &n);

	int cmin = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fscanf(f, "%d", &c[i][j]);
			if (cmin > c[i][j] && i != j) cmin = c[i][j];
		}
	}
	fclose(f);
}


void display()
{
	for (int i = 1; i <= n; i++)
	{
		printf("%3d", trace[i]);
	}
	printf("  1");
	puts("");
}

void TRY(int k)
{
	for (int v = 2; v <= n; v++)
	{
		if (sign[v] == 0)
		{
			x[k] = v;
			sign[v] = 1;
			costSum += c[x[k - 1]][v];
			if (k == n)
			{
				if (min > costSum + c[v][1]) {
					min = costSum + c[v][1];
					//printf("%d\n", min);
					for (int i = 1; i <= n; i++)
					{
						trace[i] = x[i];
					}
				}
			}
			else
			{
				int gk = costSum + cmin * (n - k + 1);
				if (gk < min)
					TRY(k + 1);
			}
			costSum -= c[x[k-1]][v];
			sign[v] = 0;
		}
	}
}

int main()
{
	x[1] = 1;
	sign[1] = 1;
	inputReadFile();
	TRY(2);
	display();
	printf("minimum total cost = %d\n", min);
	return 0;
}