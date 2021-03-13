// In chuỗi đảo ngược
#include<iostream>
#include<string>
#include<stack>

using namespace std;

void reverseChain(string s)
{
	stack<char> st;
	// push string into stack
	for (int i = 0; i < s.length(); i++)
	{
		st.push(s[i]);
	}
	// export reverse chain
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	string s;
	getline(cin, s);
	reverseChain(s);
	return 0;
}