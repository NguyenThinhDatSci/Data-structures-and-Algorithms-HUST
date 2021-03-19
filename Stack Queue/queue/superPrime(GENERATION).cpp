/* Số siêu nguyên tố là số:
Bản thân nó là số nguyên tố.
Khi xóa đi lần lượt các chữ số sau cùng của nó, thì số mới vẫn là số nguyên tố.
*/

// Cho một số n, hãy đưa số dãy số siêu nguyên tố nhỏ hơn hoặc bằng n, các số đã được sắp xếp tăng dần.
#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

queue<int> q;

bool checkPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

void superPrime(int n)
{
	int x;
	q.push(2);
	for (int i = 3; i <= 7; i += 2)
	{
		if (i < n)
			q.push(i);
	}
	while (!q.empty())
	{
		for (int i = 1; i <= 9; i += 2)
		{
			int generation = 10 * q.front() + i;
			if (generation <= n)
			{
				if (checkPrime(generation)) q.push(generation);
			}
			else
				break;
		}
		cout << q.front() << " ";
		q.pop();
	}
}

int main()
{
	int n;
	cin >> n;
	superPrime(n);
	return 0;
}