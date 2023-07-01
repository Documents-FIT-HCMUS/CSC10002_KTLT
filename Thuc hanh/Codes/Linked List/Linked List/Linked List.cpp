#include <iostream>
using namespace std;


struct DList
{
	DNode* head;
	DNode* tail;
};
struct DNode
{
	int data;
	DNode* next;
	DNode* prev;
};

bool checkNull(DList l)
{
	if (l.head == NULL || l.tail == NULL) return false;
	return true; //return TRUE if it's NULL
}

int DListCount(DList l)
{
	int dem(0);
	for (DNode* p = l.head; p != NULL; p = p->next)
	{
		dem += 1;
	}
	return dem;
}

void createDNode(DList* l)
{
	l->head = NULL;
	l->tail = NULL;
}

DNode* findHead(DList l)
{
	if (checkNull(l) == false) return l.head;
	else return NULL;
}
DNode* findTail(DList l)
{
	if (checkNull(l))
	{
		for (DNode* p = l.head; p != NULL; p = p->next)
		{
			if (p->next == NULL) return p;
		}
	}
	return NULL;
}
DNode* findData(DList l, int x)
{
	if (checkNull(l))
	{
		for (DNode* p = l.head; p != NULL; p = p->next)
		{
			if (p->data == x) return p;
		}
	}
	return NULL;
}
DNode* findI(DList l, int i)
{
	int dem(0);
	if (checkNull(l)) return NULL;
	else
	{
		for (DNode* p = l.head; p != NULL; p = p->next)
		{
			++dem;
			if (dem == i) return p;
		}
	}
}

void addHead(DList* l, int x)
{
	DNode* temp;
	temp = new DNode;
	temp->data = x;
	temp->next = l->head;
	temp->prev = NULL;
	l->head->prev = temp;
	l->head = temp;
}
void addTail(DList* l, int x)
{
	if (checkNull(*l)) addHead(l, x);
	else
	{
		DNode* temp;
		temp = new DNode;
		temp->data = x; //create a new Node
		DNode* tailElement;
		tailElement = findTail(*l);
		tailElement->next = temp;
		temp->next = NULL;
		l->tail = temp;
		temp->prev = tailElement;
	}
}
void addAfterI(DList* l, int i, int x)
{
	if (checkNull(*l)) addHead(l, x);
	else
	{
		DNode* temp, * p;
		temp = new DNode;
		temp->data = x;
		p = findI(*l, i);
		temp->next = p->next;
		p->next->prev = temp;
		p->next = temp;
		temp->prev = p;
	}
}

void removeHead(DList* l)
{
	if (checkNull(*l)) return;
	else
	{
		DNode* temp;
		temp = l->head;
		l->head = temp->next;
		temp->next->prev = NULL;
		temp->next = NULL;
		temp->prev = NULL;
		delete temp;
	}
}
void removeTail(DList* l)
{
	if (checkNull(*l)) return;
	if (DListCount(*l) == 1)
	{
		removeHead(l);
		return;
	}
	DNode* temp, * p;
	temp = findTail(*l);
	p = temp->prev; //element right before the last one
	p->next = NULL;
	l->tail = p;
	temp->next = NULL;
	temp->prev = NULL;
	delete temp;
}
void removeI(DList* l, int i)
{
	if (checkNull(*l)) return;
	if (DListCount(*l) == 1)
	{
		removeHead(l);
		return;
	}
	DNode* temp;
	temp = findI(*l, i);
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	temp->next = NULL;
	temp->prev = NULL;
	delete temp;
}

void removeAll(DList* l)
{
	DNode* p = l->head;
	while (p != NULL) removeHead(l);
}

bool caTauBoCo(int soConNguaDau)
{
	return soConNguaDau >= 1 ? true : false;
}

bool giaDoDon(bool treChoi)
{
	return !treChoi ? true : false;
}

int main()
{
	return 0;
}