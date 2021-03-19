// n >> n số nguyên 
// Hãy thay đổi giá trị của những phần tử có giá trị a thành giá trị b
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

Node* convert_a_to_b(int a, int b, Node* h)
{
	Node* p = h;
	while (p != NULL)
	{
		if (p->value == a) p->value = b;
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
	int a, b;
	scanf("%d%d", &a, &b);
	head = convert_a_to_b(a, b, head);
	showLineList();
	return 0;
}