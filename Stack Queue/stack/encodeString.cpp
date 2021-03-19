// Cho một sâu s chỉ gồm các ký tự viết thường
// hãy viết hàm trả về chuỗi mã hóa của sâu này
#include<iostream>
#include<stack>
#include<string>

using namespace std;

string decimalToString(int n)
{
	// assign string s to empty
	string s = "";
	while (n > 0)
	{
		s = char(n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}

void encodeString(string s)
{
	stack<char> st;
	// new string used to store the result
	string str;
	for (int i = 0; i < s.length(); i++)
	{
		// put in stack
		if (st.empty() || st.top() == s[i])
			st.push(s[i]);
		else
		{
			short count = 0;
			// push top in new string
			str = str + st.top();
			// increase count variable
			while (!st.empty())
			{
				count++;
				st.pop();
			}
			str = str + decimalToString(count);
			st.push(s[i]);
		}
	}
	cout << str;
}

int main()
{
	string s;
	getline(cin, s);
	encodeString(s);
	return 0;
}