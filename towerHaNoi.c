
#include<stdio.h>
// TOWER HA NOI
void move(int n, char A, char B, char C)
{
	if (n == 1) printf("%c -> %c\n", A, B);
	else
	{
		move(n - 1, A, C, B);
		move(1, A, B, C);
		move(n - 1, C, B, A);
	}
}

int main()
{
	move(3, 'A', 'B', 'C');
	return 0;
}