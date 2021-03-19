#include "doublelinkedlist.h"

void initializeDList(DList& lst)
{
	lst.head = lst.tail = NULL;
}

bool isEmpty(DList lst)
{
	if (lst.head == NULL) return true;
	return false;
}

Node* newNode(Data data)
{
	Node* q = new Node;
	q->next = NULL;
	q->prev = NULL;
	q->data = data;
	return q;
}

DList addHead(Data data, DList lst)
{
	Node* q = newNode(data);
	if (isEmpty(lst))
	{
		lst.head = lst.tail = q;
		return lst;
	}
	q->next = lst.head;
	lst.head->prev = q;
	lst.head = q;
	return lst;
}

DList addTail(Data data, DList lst)
{
	Node* q = newNode(data);
	if (isEmpty(lst))
	{
		lst.head = lst.tail = q;
		return lst;
	}
	lst.tail->next = q;
	q->prev = lst.tail;
	lst.tail = q;
	return lst;
}

void inputNintegers(int n, DList& lst)
{
	int value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		Data data = { value };
		lst = addTail(data, lst);
	}
}

DList insertAtk(Data data, int k, int n, DList lst)
{
	Node* q = newNode(data);
	if (k == 0) return addHead(data, lst);
	if (k == n) return addTail(data, lst);
	Node* p = lst.head;
	while (k > 1)
	{
		p = p->next;
		k--;
	}
	Node* pNext = p->next;
	q->prev = p;
	q->next = pNext;
	p->next = q;
	pNext->prev = q;
	return lst;
}

DList deleteAtk(int k, DList lst)
{
	if (isEmpty(lst)) return lst;
	Node* q = lst.head;
	if (k == 0)
	{
		lst.head = lst.head->next;
		free(q);
		return lst;
	}
	while (k > 1)
	{
		k--;
		q = q->next;
	}
	Node* temp = q->next;
	q->next = temp->next;
	if (temp->next != NULL) temp->next->prev = q;
	free(temp);
	return lst;
}

void showHeadList(DList lst)
{
	Node* p = lst.head;
	while (p != NULL)
	{
		cout << p->data.value << " ";
		p = p->next;
	}
	cout << endl;
}

void showTailList(DList lst)
{
	Node* p = lst.tail;
	while (p != NULL)
	{
		cout << p->data.value << " ";
		p = p->prev;
	}
}
