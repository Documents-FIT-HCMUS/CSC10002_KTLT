#include "SList.h"

void createSList(SList* s, int n)
{
	int x;
	init(s);
;	for (int dem = 1; dem <= n; ++dem)
	{
		cout << "Nhap phan tu thu " << dem << ": ";
		cin >> x;
		addTail(s, x);
	}
}
void printSList(SList* s)
{
	if (isNULL(s))
	{
		cout << "Linked List is empty!";
		return;
	}
	for (SNode* p = s->head; p != NULL; p = p->next)
		cout << p->data << " ";
	cout << endl;
}

void init(SList* s)
{
	s->head = NULL;
}
bool isNULL(SList* s)
{
	if (s->head == NULL) return true;
	return false;
}

SNode* findHead(SList* s)
{
	if (isNULL(s)) return NULL;
	return s->head;
}
SNode* findTail(SList* s)
{
	if (isNULL(s)) return NULL;
	for (SNode* p = s->head; p != NULL; p = p->next)
		if (p->next == NULL) return p;
	return s->head;
}
SNode* findI(SList* s, int i)
{
	if (isNULL(s)) return NULL;
	int dem(0);
	for (SNode* p = s->head; p != NULL; p = p->next)
	{
		++dem;
		if (dem == i) return p;
	}
}

void addHead(SList* s, int x)
{
	SNode* newNode, * temp;
	newNode = new SNode;
	newNode->data = x;
	temp = s->head;
	s->head = newNode;
	newNode->next = temp;
}
void addTail(SList* s, int x)
{
	if (isNULL(s)) addHead(s, x);
	else
	{
		SNode* newNode, * temp;
		newNode = new SNode;
		newNode->data = x;
		newNode->next = NULL;
		temp = findTail(s);
		temp->next = newNode;
	}
}

void removeHead(SList* s)
{
	if (isNULL(s)) return;
	SNode* temp = s->head;
	s->head = temp->next;
	delete temp;
}
void removeTail(SList* s)
{
	if (isNULL(s)) return;
	for (SNode* p = s->head; p != NULL; p = p->next)
		if ((p->next)->next == NULL)
		{
			SNode* temp = p->next;
			p->next = NULL;
			delete temp;
			break;
		}
}
void removeAll(SList* s)
{
	while (!isNULL(s))
		removeHead(s);
}