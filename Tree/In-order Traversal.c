#include<stdio.h>
#include<stdlib.h>
int a[] = { 3,2,1,5,4 };
int n = 5;

typedef struct Node
{
	int value;
	int* left;
	int* right;
} Node;

Node* head = NULL;

Node* NewNode(int v)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->value = v;
	q->left = NULL;
	q->right = NULL;
	return q;
}

Node* insertLast(Node* h, int v)
{
	if (h == NULL)
	{
		Node* q = NewNode(v);
		return q;
	}
	else
	{
		if (v < h->value)
		{
			h->left = insertLast(h->left, v);
		}
		else
		{
			h->right = insertLast(h->right, v);
		}
		return h;
	}
}

void printTree(Node *h)
{
	if (h != NULL)
	{
		printTree(h->left);
		printf("%d ", h->value);
		printTree(h->right);
	}
}

void freeTree(Node* r) {
	if (r == NULL) return;
	freeTree(r->left);
	freeTree(r->right);
	free(r);
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		head = insertLast(head, a[i]);
	}
	printTree(head);
	freeTree(head);
	return 0;
}