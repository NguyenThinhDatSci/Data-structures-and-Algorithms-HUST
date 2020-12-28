#include<stdio.h>
int n = 10;
int k = 0;
int S[100];
int a[100], b[100];

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void input_and_sort_ab()
{
	// input data
	for (int i = 0; i < n; i++)
	{
		printf("(a[%d], b[%d]) = ", i, i);
		scanf("%d %d", a + i, b + i);
	}
	// sort in ascending order b
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (b[i] > b[j])
			{
				swap(&b[i], &b[j]);
				swap(&a[i], &a[j]);
			}
		}
}

// display solution
void solution()
{
	printf("%d straight segments\n", k + 1);
	for (int i = 0; i <= k; i++)
	{
		printf("%d %d", a[S[i]], b[S[i]]);
		puts("");
	}
}

void greedy()
{
	int i = 1;
	S[k] = 0;
	while (i < n)
	{
		if (a[i] > b[S[k]])
		{
			S[++k] = i;
		}
		i++;
	}
	solution();
}

int main()
{
	input_and_sort_ab();
	greedy();
	return 0;
}