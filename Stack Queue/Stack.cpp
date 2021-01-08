#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[] = "(]{}[({})])";

typedef struct Node
{
	char letter;
	Node* next;
} Node;

Node* top = NULL;

Node* newNode(int v)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->next = NULL;
	q->letter = v;
	return q;
}

Node* insertLast(char v)
{
	Node* q = newNode(v);
	if (top == NULL) return q;
	q->next = top;
	return q;
}

Node* pop()
{
	Node* p = top -> next;
	free(top);
	return p;
}

void printfList()
{
	Node* p = top;
	while (p != NULL)
	{
		printf("%c ", p->letter);
		p = p->next;
	}
	puts("\n");
}

int check(char v) {
	return v == '(' || v == '{' || v == '[';
}

int match(char u, char v) {
	if (u == '(' && v == ')') {
		return 1;
	}
	if (u == '[' && v == ']') {
		return 1;
	}
	if (u == '{' && v == '}') {
		return 1;
	}
	return 0;
}

int main()
{
	bool ok = true;
	puts("hello I'm stack");
	for (int i = 0; i < strlen(a); i++) {
		if (check(a[i])) {
			top = insertLast(a[i]);
		}
		else {
			if(top == NULL || !match(top->letter, a[i])) {
				ok = false;
				break;
			}
			top = pop();
		}
	}
	if (ok == true) {
		printf("dung");
	}
	else {
		printf("sai");
	}
	
	return 0;
}