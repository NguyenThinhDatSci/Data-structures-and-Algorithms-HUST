// Số nguyên n >> n số nguyên của một dãy số >> Đặt nó vào một danh sách liên kết đơn
// Hai số nguyên k và x, (0 ≤ k ≤ n) >> Chèn giá trị x vào danh sách liên kết tại chỉ số k và in ra màn hình danh sách
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value;
	int* next;
} Node;

Node* head = NULL;

Node* newNode(int n)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->value = n;
	q->next = NULL;
	return q;
}

Node* input(int n, Node* h)
{
	int v;
	scanf("%d", &v);
	h = newNode(v);
	Node* p = h;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &v);
		Node* q = newNode(v);
		p->next = q;
		p = q;
	}
	return h;
}

Node* insertAt(int v, int k, Node* h)
{
	Node* q = newNode(v);
	if (k == 0)
	{
		q->next = h;
		return q;
	}
	Node* p = h;
	while (k > 1)
	{
		p = p->next;
		k--;
	}
	if (p == NULL) return h;
	Node* temp = p->next;
	p->next = q;
	q->next = temp;
	return h;
}

void showLineList()
{
	Node* p = head;
	while (p != NULL)
	{
		printf("%d ", p->value);
		p = p->next;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	head = input(n, head);
	int v, k;
	scanf("%d%d", &k, &v);
	head = insertAt(v, k, head);
	showLineList();
	return 0;
}