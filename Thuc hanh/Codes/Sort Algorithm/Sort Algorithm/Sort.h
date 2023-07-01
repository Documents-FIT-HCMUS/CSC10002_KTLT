#pragma once


bool asc(int, int);
bool des(int, int);
void swap(int&, int&);
void interchangeSort(int*, int, bool (*order)(int, int)); //for Array
void printArray(int*, int);
void interchangeSort(SList*, bool (*order)(int, int)); //for SList

void selectionSort(int*, int, bool (*order)(int, int)); //for Array
void selectionSort(SList*, bool (*order)(int, int)); //for SList

//quickSort for Array
int partition(int*, int, int, bool (*order)(int, int)); 
void quickSort(int*, int, int, bool (*order)(int, int));

struct Node
{
	int data;
	struct Node* next;
};
void push(struct Node**, int);
void printList(struct Node*);
struct Node* getTail(struct Node*);
struct Node* partition(struct Node*, struct Node*, struct Node**, struct Node**);
struct Node* quickSortRecur(struct Node*, struct Node*);
void quickSort(struct Node**);

