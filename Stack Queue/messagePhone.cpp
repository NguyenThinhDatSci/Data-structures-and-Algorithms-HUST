/*Màn hình điện thoại chỉ hiển thị được tối đa k tin nhắn:

Không hiện thị 2 tin nhắn của cùng một SĐT trên cùng một khung hình, SĐT a gửi tin nhắn đến mà trên màn hình đã có tin nhắn của SĐT a >> không thay đổi gì.
SĐT a gửi tin nhắn đến mà trên màn hình chưa có tin nhắn của SĐT a thì :
Nếu màn hình chưa đủ k tin nhắn thì tin nhắn của SĐT a sẽ được chèn vào cuối màn hình.
Nếu màn hình đã có đủ k tin nhắn thì thì màn hình sẽ đẩy tin nhắn trên cùng ra và sau đó chèn tin nhắn của SĐT a vào cuối màn hình.

Cho dãy a là các SĐT sẽ gửi tin nhắn đến.
Hỏi khi nhận được tin nhắn cuối cùng thì màn hình đang hiển thị tin nhắn của các SĐT nào, đưa ra theo thứ tự từ trên xuống dưới của màn hình.
*/
#include<iostream>
#include<queue>

using namespace std;

void input(int *n, int *arr, int *k)
{
	// input n
	cout << "n = ";
	cin >> *n;
	// input arr
	cout << "array: " << endl;
	for (int i = 0; i < *n; i++)
	{
		cin >> arr[i];
	}
	// input k
	cout << "k = ";
	cin >> *k;
}

void messagePhone(int n, int *arr, int k)
{
	queue<int> q;
	// use a vector to mark the occurence of numbers in the queue
	bool b[1001];
	q.push(arr[0]);
	// assigned to array b
	for (int i = 0; i < 1001; i++)
	{
		b[i] = false;
	}
	b[arr[0]] = true;
	for (int i = 1; i < n; i++)
	{
		if (b[arr[i]] == false)
			if (q.size() < k)
			{
				q.push(arr[i]);
				b[arr[i]] = true;
			}
			else
			{
				b[q.front()] = false;
				q.pop();
				q.push(arr[i]);
				b[arr[i]] = true;
			}
	}
	// show queue on screen
	cout << "result: ";
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}

int main()
{
	int n;
	int arr[1001];
	int k;
	input(&n, arr, &k);
	messagePhone(n, arr, k);
	return 0;
}