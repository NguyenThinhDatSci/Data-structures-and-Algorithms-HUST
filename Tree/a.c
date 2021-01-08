#include<stdio.h>
#include<stdlib.h>
int a[] = { 3,2,1,5,4 };
//using namespace std;

typedef struct node {
	int data;
	int* left;
	int* right;
}node;

node* NewNode(int v)
{
	node* q = (node*)malloc(sizeof(node));
	q->data = v;
	q->left = NULL;
	q->right = NULL;
	return q;
}

node* insert(node* t, int x) {
	if (t == NULL) {
		node* temp = NewNode(x);
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else {
		if (x < t->data) {
			t->left = insert(t->left, x);
		}
		else {
			t->right = insert(t->right, x);
		}
	}
}
void printTree(node* t) {
	if (t != NULL) {
		printTree(t->left);
		printf("%d ", t->data);
		printTree(t->right);
	}
}
int main() {
	int n, x;
	n = 5;
	node* t = NULL;
	for (int i = 0; i < n; i++) {
		
		t = insert(t, a[i]);
	}
	printTree(t);
}