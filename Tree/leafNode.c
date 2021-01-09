#include<stdio.h>
#include<stdlib.h>

int n = 7;
int a[] = { 4, 7, 2, 1, 3, 2, 5 };
int count = 0;

typedef struct Node
{
	int value;
	int* left;
	int* right;
} Node;

Node* root = NULL;

Node* makeNode(int v)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->value = v;
	q->left = NULL;
	q->right = NULL;
	return q;
}

Node* insertLast(Node* r, int v)
{
	if (r == NULL)
	{
		Node* q = makeNode(v);
		return q;
	}
	else
	{
		if (v < r->value)
			r->left = insertLast(r->left, v);
		else
			r->right = insertLast(r->right, v);
	}
	return r;
}

void leafNode(Node* r)
{
	if(r != NULL)
		if ((r->left == NULL) && (r->right == NULL))
			count++;
		else
		{
			leafNode(r->left);
			leafNode(r->right);
		}
}

void printTree(Node* h)
{
	if (h != NULL)
	{
		printTree(h->left);
		printf("%d ", h->value);
		printTree(h->right);
	}
}

void freeTree(Node* r)
{
	if (r != NULL)
	{
		freeTree(r->left);
		freeTree(r->right);
		free(r);
	}
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		root = insertLast(root, a[i]);
	}
	leafNode(root);
	printf("%d", count);
	freeTree(root);
	return 0;
}