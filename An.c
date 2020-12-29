#include<stdio.h>
int arr[10000];
int top = -1;

int check(int n) {
	int i;
	if (n < 2) {
		return 0;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		for (i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int checkarr(int n) {
	if (n / 10 == 0) {
		return 1;
	}
	else {
		if (check(n / 10) == 0) {
			return 0;
		}
		else {
			checkarr(n / 10);
		}
	}
}

int main() {
	int x;
	scanf("%d", &x);
	int i;
	for (i = 2; i <= x; i++) {
		if (check(i) == 1 && checkarr(i) == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}