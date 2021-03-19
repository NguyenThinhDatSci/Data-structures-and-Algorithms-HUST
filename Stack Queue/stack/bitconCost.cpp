#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> st;
	int n;
	scanf("%d", &n);
	int* a, * b;
	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	st.push(a[n - 1]);
	b[n - 1] = 0;
	int size;
	for (int i = n - 2; i >= 0; i--)
	{
		size = st.size();
		if (a[i] >= st.top())
		{
			/*while (!st.empty() && a[i] >= st.top())
			{
				st.pop();
			}*/
			st.pop();
			if (st.empty()) b[i] = 0;
			else
				b[i] = 1;
			st.push(a[i]);
		}
		else
		{
			st.push(a[i]);
			if (st.size() > size)
				b[i] = 1;
			else
				b[i] = b[i + 1] + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << ' ';
	}
	return 0;
}