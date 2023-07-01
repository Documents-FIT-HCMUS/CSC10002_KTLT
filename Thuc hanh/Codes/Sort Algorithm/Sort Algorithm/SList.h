#pragma once
#include <iostream>
using namespace std;

struct SNode
{
	int data;
	SNode* next;
};

struct SList
{
	SNode* head;
};



void createSList(SList*, int);
void printSList(SList*);

void init(SList*);
bool isNULL(SList*);

SNode* findHead(SList*);
SNode* findTail(SList*);
SNode* findI(SList*, int);

void addHead(SList*, int);
void addTail(SList*, int);

void removeHead(SList*);
void removeTail(SList*);
void removeAll(SList*);

