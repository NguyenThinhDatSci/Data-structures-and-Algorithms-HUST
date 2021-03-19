// Số nguyên n >> n số nguyên của một dãy số.
// Hãy cài đặt nó vào một danh sách liên kết đơn và in ra màn hình danh sách đó
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
	showLineList();
	return 0;
}