// số nguyên k (0 ≤ k <n).
// Hãy xóa những phần tử có giá trị lớn hơn giá trị của phần tử ở chỉ số k
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
		Node* q = h;
		return h->next;
		free(q);
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

Node* deleteTheLargerNumber(int k, Node* h)
{
	int v = valueAt_k(k, h);
	Node* p = h;
	int index = -1;
	while (p != NULL)
	{
		index++;
		if (p->value > v)
		{
			p = p->next;
			h = deleteAt(index, h);
			index--;
		}
		else
			p = p->next;
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
	int k;
	scanf("%d", &k);
	head = deleteTheLargerNumber(k, head);
	showLineList();
	return 0;
}