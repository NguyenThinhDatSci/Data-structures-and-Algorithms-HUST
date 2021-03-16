// 0 <= k < n, Hiển thị giá trị tại chỉ số k
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

int valueAt_k(int k, Node* h)
{
	if (k == 0) return h->value;
	Node* p = h;
	while (k > 0)
	{
		p = p->next;
		k--;
	}
	return p->value;
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
	int k;
	scanf("%d", &k);
	printf("%d", valueAt_k(k, head));
	//showLineList();
	return 0;
}