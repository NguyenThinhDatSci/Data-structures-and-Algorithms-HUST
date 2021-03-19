#pragma once
#include<iostream>
using namespace std;

struct Data
{
	int value;
};

struct Node
{
	Data data;
	Node* next;
	Node* prev;
};

struct DList
{
	Node* head;
	Node* tail;
};

// initialize DList

void initializeDList(DList& lst);

// check empty list

bool isEmpty(DList lst);

// create new Node

Node* newNode(Data data);

// add an element to the top list

DList addHead(Data data, DList lst);

// add an element to the end of the list

DList addTail(Data data, DList lst);

// enter n integers as input

void inputNintegers(int n, DList& lst);

// insert an element with a value of x at k index

DList insertAtk(Data data, int k, int n, DList lst);

// delete an element at k index

DList deleteAtk(int k, DList lst);

// Display list on screen

void showHeadList(DList lst);

void showTailList(DList lst);
