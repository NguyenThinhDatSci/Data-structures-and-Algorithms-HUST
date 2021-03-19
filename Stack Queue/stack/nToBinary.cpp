// Nhập vào một số nguyên dương n.
// Hãy chuyển n thành mã nhị phân và in chuỗi đó ra màn hình.
#include<iostream>
#include<stack>

using namespace std;

void nToBinary(int n)
{
	stack<short> st;
	// put in stack
	while (n > 0)
	{
		st.push(n % 2);
		n /= 2;
	}
	// export stack
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	int n;
	// fill in n as the number is greater than 0
	do {
		cin >> n;
	} while (n <= 0);
	nToBinary(n);
	return 0;
}