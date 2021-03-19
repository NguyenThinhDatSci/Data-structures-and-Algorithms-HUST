// n >= 0, n số nguyên của một dãy số + 2 số nguyên k và x, (0 ≤ k ≤ n).
// Hãy chèn giá trị x vào danh sách liên kết tại chỉ số k
#include "doublelinkedlist.h"

int main()
{
	int n;
	cin >> n;
	DList lst;
	initializeDList(lst);
	Data data;
	inputNintegers(n, lst);
	int x, k;
	cin >> k >> x;
	data.value = x;
	lst = insertAtk(data, k, n, lst);
	showHeadList(lst);
	return 0;
}