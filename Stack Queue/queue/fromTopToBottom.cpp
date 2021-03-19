// n nguyên dương >> n số nguyên lần lượt là các phần tử của queue >> một số tự nhiên k.
// Một phép biến đổi sẽ dịch chuyển phần tử đầu tiên ra sau phần tử cuối cùng của dãy
// Hãy trả về dãy sau khi đã biến đổi k lần

#include<iostream>
#include<queue>

using namespace std;

queue<int> qu;

void inputQueue(int n)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		qu.push(x);
	}
}

void fromTopToBottom(int k)
{
	while (k > 0)
	{
		int x = qu.front();
		qu.push(x);
		qu.pop();
		k--;
	}
	while (!qu.empty())
	{
		cout << qu.front() << " ";
		qu.pop();
	}
}

int main()
{
	int n, k;
	cin >> n;
	inputQueue(n);
	cin >> k;
	fromTopToBottom(k);
	return 0;
}