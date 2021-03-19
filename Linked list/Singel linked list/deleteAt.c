// 0 <= k < n, Xóa phần tử ở chỉ số k
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

Node* deleteAt(int k, Node* h)
{
	if (k == 0)
	{
		Node* q = h->next;
		free(h);
		return q;
	}
	Node* p = h;
	while (k > 1)
	{
		p = p->next;
		k--;
	}
	if (p == NULL) return h;
	Node* q = p->next;
	p->next = q->next;
	free(q);
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
	int k;
	scanf("%d", &k);
	head = deleteAt(k, head);
	showLineList();
	return 0;
}