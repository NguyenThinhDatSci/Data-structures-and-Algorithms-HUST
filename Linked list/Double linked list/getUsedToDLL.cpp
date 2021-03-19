// Nhập vào một số nguyên dương n, hãy cài đặt một danh sách lên kết đôi để lưu các số từ n giảm về 1 và từ 1 răng đến n
// 3 2 1 2 3
#include "doublelinkedlist.h"

int main()
{
	DList lst;
	initializeDList(lst);
	Data data;
	data.value = 1;
	lst = addHead(data, lst);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		data.value = i;
		lst = addHead(data, lst);
		lst = addTail(data, lst);
	}
	showList(lst);
	return 0;
}