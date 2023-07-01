#include "SList.h"
#include "Sort.h"

int main()
{
	//interchangeSort 
	//for Array
	int a[10] = { 8,3,1,-1,-5,-2,5,7,3,9 };
	int n = 10;
	cout << "INTERCHANGE SORT\nARRAY:\n";
	cout << "Original:\t";
	printArray(a, n);
	interchangeSort(a, n, asc); //ascending
	cout << "Ascending:\t";
	printArray(a, n);
	interchangeSort(a, n, des); //descending
	cout << "Descending:\t";
	printArray(a, n);
	//for Singly Linked List
	SList s;
	cout << "INTERCHANGE SORT\nLINKED LIST:\n";
	cout << "Nhap n: ";
	cin >> n;
	createSList(&s, n); //somehow addTail didn't work when called, had to input manually, fix later
	cout << "Original:\t";
	printSList(&s);
	interchangeSort(&s, asc); //ascending
	cout << "Ascending:\t";
	printSList(&s);
	interchangeSort(&s, des); //descending
	cout << "Descending:\t";
	printSList(&s);
	removeAll(&s);
	cout << endl;

	//selectionSort
	//for Array
	int b[10] = { 8,3,1,-1,-5,-2,5,7,3,9 };
	n = 10;
	cout << "SELECTION SORT\nARRAY:\n";
	cout << "Original:\t";
	printArray(a, n);
	selectionSort(a, n, asc); //ascending
	cout << "Ascending:\t";
	printArray(a, n);
	selectionSort(a, n, des); //descending
	cout << "Descending:\t";
	printArray(a, n);
	//for Singly Linked List
	cout << "SELECTION SORT\nLINKED LIST:\n";
	cout << "Nhap n: ";
	cin >> n;
	createSList(&s, n); 
	cout << "Original:\t";
	printSList(&s);
	selectionSort(&s, asc); //ascending
	cout << "Ascending:\t";
	printSList(&s);
	selectionSort(&s, des); //descending
	cout << "Descending:\t";
	printSList(&s);
	removeAll(&s);
	cout << endl;

	//quickSort
	//for Array
	int c[10] = { 8,3,1,-1,-5,-2,5,7,3,9 };
	n = 10;
	cout << "QUICK SORT\nARRAY:\n";
	cout << "Original:\t";
	printArray(c, 10);
	quickSort(c, 0, n - 1, asc); //ascending
	cout << "Ascending:\t";
	printArray(c, n);
	quickSort(c, 0, n - 1, des); //descending
	cout << "Descending:\t";
	printArray(c, n);
	//for SList
	struct Node* sl = NULL;
	push(&sl, 5);
	push(&sl, 20);
	push(&sl, 4);
	push(&sl, 3);
	push(&sl, 30);
	cout << "Linked List before sorting \n";
	printList(sl);
	quickSort(&sl);
	cout << "Linked List after sorting \n";
	printList(sl);

	return 0;
}


