// số nguyên dương n >> n số nguyên của một dãy số >> một số nguyên k (0 ≤ k < n).
// Hãy xóa phần tử ở chỉ số k
#include "doublelinkedlist.h"

int main()
{
	DList lst;
	initializeDList(lst);
	int n;
	cin >> n;
	inputNintegers(n, lst);
	int k;
	cin >> k;
	lst = deleteAtk(k, lst);
	showHeadList(lst);
	return 0;
}