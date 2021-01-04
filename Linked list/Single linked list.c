#include<stdio.h>

typedef struct Node
{
	int value;
	int* next;
} Node;

Node* head;

Node* newNode(int v)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->next = NULL;
	q->value = v;
	return q;
}

Node* insertLast(int v)
{
	Node* p = head;
	Node* q = newNode(v);
	if (head == NULL) return q;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
	return head;
}

Node* insertAfter(Node* h, int u, int v)
{
	if (h == NULL) return h;
	if (h->value == u)
	{
		Node* q = newNode(v);
		q->next = h->next;
		h->next = q;
		return h;
	}
	Node* p = head;
	while (p != NULL && p->value != u)
	{
		p = p->next;
	}
	if (p)
	{
		Node* q = newNode(v);
		q->next = p->next;
		p->next = q;
	}
	return h;
}

Node* insertAfterRecursive(Node* h, int u, int v)
{
	if (h == NULL) return h;
	if (h->value == u)
	{
		Node* q = newNode(v);
		q->next = h->next;
		h->next = q;
		return h;
	}
	while (h->value != u)
	{
		h->next = insertAfterRecursive(h->next, u, v);
	}
	//return insertAfterRecursive(h, u, v);
}

void printfList()
{
	Node* p = head;
	while (p != NULL)
	{
		printf("%3d", p->value);
		p = p->next;
	}
}

int main()
{
	for (int i = 1; i < 10; i++)
		head = insertLast(i);
	//insertAfter(head, 1, 0);
	insertAfterRecursive(head, 2, 0);
	printfList();
	return 0;
}