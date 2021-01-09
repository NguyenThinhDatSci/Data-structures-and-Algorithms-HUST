#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<math.h>

int n = 8;
int a[] = { 4, 7, 2, 1, 3, 2, 5 , 2};

typedef struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
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

int treeLevel(Node* r)
{
	if (r == NULL) return -1;
	else
		return max(treeLevel(r->left), treeLevel(r->right)) + 1;
}

bool checkAVL(Node* r)
{
	if (r == NULL) return true;
	if (abs(treeLevel(r->right) - treeLevel(r->left)) > 1) return false;
	return checkAVL(r->left) && checkAVL(r->right);
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
	if (checkAVL(root)) printf("\nTrue");
	else
		printf("\nFalse");
	freeTree(root);
	return 0;
}