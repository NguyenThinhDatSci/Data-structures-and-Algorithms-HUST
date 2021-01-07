#include<stdio.h>
#include<stdlib.h>

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
	h->next = insertAfterRecursive(h->next, u, v);
	return h;
}

Node* insertBefore(Node *h, int u, int v)
{
	if (h == NULL) return h;
	if (h->value == u)
	{
		Node* q = newNode(v);
		q->next = h;
		return q;
	}
	Node* p = head;
	Node* pn = p;
	while (p->next != NULL)
	{
		pn = p->next;
		if (pn->value == u) break;
		p = p->next;
	}
	if (pn->value == u) {
		Node* q = newNode(v);
		q->next = pn;
		p->next = q;
	}
	return h;
}

Node* insertBeforeRecursive(Node* h, int u, int v)
{
	if (h == NULL) return h;
	if (h->value == u)
	{
		Node* q = newNode(v);
		q->next = h;
		return q;
	}
	h->next = insertBeforeRecursive(h->next, u, v);
	return h;
}

Node* insertAt(Node* h, int index, int v)
{
	if (h == NULL) return h;
	if (index == 1)
	{
		Node* q = newNode(v);
		q->next = h;
		return q;
	}
	Node* p = h;
	int count = 0;
	while (p != NULL)
	{
		count++;
		if (count == index - 1) break;
		p = p->next;
	}
	if (p != NULL)
	{
		Node* q = newNode(v);
		q->next = p->next;
		p->next = q;
	}
	return h;
}

Node* insertAtRecursive(Node* h, int index, int v)
{
	if (h == NULL || index < 1) return h;
	if (index == 1)
	{
		Node* q = newNode(v);
		q->next = h;
		return q;
	}
	h->next = insertAtRecursive(h->next, index - 1, v);
	return h;
}

Node* removeAt(Node* h, int v)
{
	if (h == NULL) return h;
	if (h->value == v) 
	{
		Node* p = h->next;
		free(h);
		return p;
	}
	Node* p = h;
	Node* pn = p->next;
	while (pn != NULL)
	{
		if (pn->value == v) break;
		p = p->next;
		pn = p->next;
	}
	if (pn != NULL)
	{
		p->next = pn->next;
		free(pn);
	}
	return h;
}

Node* removeAtRecursive(Node* h, int v)
{
	if (h == NULL) return h;
	if (h->value == v)
	{
		Node* p = h->next;
		free(h);
		return p;
	}
	h->next = removeAtRecursive(h->next, v);
	return h;
}

int sum(Node* h)
{
	int sum = 0;
	if (h == NULL) return 0;
	Node* p = h;
	while (p != NULL)
	{
		sum += p->value;
		p = p->next;
	}
	return sum;
}

int sumRecursive(Node* h)
{
	if (h == NULL) return 0;
	else
		return h->value + sumRecursive(h->next);
}

void printfList()
{
	Node* p = head;
	while (p != NULL)
	{
		printf("%3d", p->value);
		p = p->next;
	}
	puts("");
}

void freeList()
{
	if (head != NULL)
	{
		Node* p = head;
		head = head->next;
		free(p);
	}
}

int main()
{
	for (int i = 1; i < 10; i++)
		head = insertLast(i);
	/*head = insertAfter(head, 1, 0);
	head = insertAfterRecursive(head, 5, 0);
	head = insertBefore(head, 3, 7);
	head = insertBeforeRecursive(head, 6, 7);
	head = removeAt(head, 7);
	head = removeAtRecursive(head, 5);
	head = insertAt(head, 0, 10);*/
	head = insertAtRecursive(head, 1, 7);
	printfList();
	//printf("sum = %d", sum(head));
	printf("sum = %d", sumRecursive(head));
	freeList();
	return 0;
}