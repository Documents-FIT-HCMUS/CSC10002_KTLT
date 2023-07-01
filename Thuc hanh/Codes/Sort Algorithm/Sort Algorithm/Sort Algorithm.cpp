#include "SList.h"
#include "Sort.h"

//interchangeSort
bool (*order)(int, int);
bool asc(int a, int b)
{
    return a > b;
}
bool des(int a, int b) {
    return a < b;
}
void swap(int& a, int& b) 
{
    if (a == b) return;
    int temp = a;
    a = b;
    b = temp;
}
void printArray(int* a, int n)
{
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
}

void interchangeSort(int* a, int n, bool (*order)(int, int)) //for Array
{
    for (int i = 0; i < n - 1; ++i) 
        for (int j = i + 1; j < n; ++j) 
        {
            if (order(a[i], a[j]) == true) swap(a[i], a[j]);
        }
}
void interchangeSort(SList* s, bool (*order)(int, int)) //for Singly Linked List
{
    SNode* i = s->head;
    SNode* j;
    int temp;
    while (i->next != NULL) 
    {
        for (j = i->next; j != NULL; j = j->next) 
            if (order(i->data, j->data)==true) 
                swap(i->data, j->data);
        i = i->next;
    }
}

//selectionSort
void selectionSort(int* a, int n, bool (*order)(int, int)) //for Array
{
    for (int i = 0; i < n - 1; ++i)
    {
        int temp = i;
        for (int j = i + 1; j < n; ++j)
            if (order(a[temp], a[j])) temp = j;
        swap(a[i], a[temp]);
    }
}
void selectionSort(SList* s, bool (*type)(int, int)) //for SList
{
    SNode* i = s->head;
    SNode* j;
    SNode* temp;
    while ((i->next) != NULL) 
    {
        temp = i;
        for (j = i->next; j != NULL; j = j->next) 
            if (type(temp->data, j->data)) temp = j;
            swap(i->data, temp->data);
        i = i->next;
    }
}

//quickSort
int partition(int* a, int low, int high, bool (*order)(int, int))
{
    int pivot = a[high];    // pivot
    int left = low;
    int right = high - 1;
    while (true) 
    {
        while (left <= right && !order(a[left], pivot)) left++;
        while (right >= left && order(a[right], pivot)) right--;
        if (left >= right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}
void quickSort(int* a, int low, int high, bool (*order)(int, int))
{
    if (low < high)
    {
        int idx = partition(a, low, high, order);
        quickSort(a, low, idx - 1, order);
        quickSort(a, idx + 1, high, order);
    }
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

struct Node* getTail(struct Node* cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

struct Node* partition(struct Node* head, struct Node* end, struct Node** newHead, struct Node** newEnd)
{
	struct Node* pivot = end;
	struct Node* prev = NULL, * cur = head, * tail = pivot;

	while (cur != pivot)
	{
		if (cur->data < pivot->data)
		{
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot 
		{
			// Move cur node to next of tail, and change tail 
			if (prev)
				prev->next = cur->next;
			struct Node* tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newEnd) = tail;
	return pivot;
}

struct Node* quickSortRecur(struct Node* head, struct Node* end)
{ 
	if (!head || head == end)
		return head;

	Node* newHead = NULL, * newEnd = NULL;

	struct Node* pivot = partition(head, end, &newHead, &newEnd);

	if (newHead != pivot)
	{
		struct Node* tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		newHead = quickSortRecur(newHead, tmp);
		tmp = getTail(newHead);
		tmp->next = pivot;
	}
	pivot->next = quickSortRecur(pivot->next, newEnd);
	return newHead;
}
void quickSort(struct Node** headRef)
{
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}

