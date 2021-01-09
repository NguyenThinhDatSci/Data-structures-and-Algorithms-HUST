#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n = 7;
int a[] = { 4, 7, 2, 1, 3, 2, 5 };
int max = INT_MIN;

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
		if (r->value > v)
			r->left = insertLast(r->left, v);
		else
			r->right = insertLast(r->right, v);
	}
	return r;
}

void treeLevel(Node* r, int count)
{
	if (r == NULL) return;
	if (r->left == NULL && r->right == NULL)
	{
		if (max < count) max = count;
	}
	else
	{
		treeLevel(r->left, count + 1);
		treeLevel(r->right, count + 1);
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
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		root = insertLast(root, a[i]);
	}
	treeLevel(root, count);
	printf("%d", max);
	freeTree(root);
	return 0;
}