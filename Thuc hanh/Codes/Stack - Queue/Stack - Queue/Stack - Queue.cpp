#include "Stack - Queue.h"

bool isEmpty(stack s)
{
	return s.n == 0;
}
bool isFull(stack s)
{
	return s.n == MAX;
}
void printStack(stack s)
{
	for (int i = 0; i < s.n; ++i)
	{
		cout << s.s[i] << " ";
	}
	cout << endl;
}
void push(stack& s, int x)
{
	if (isFull(s)) return;
	s.s[s.n] = x;
	++s.n;
}
int pop(stack& s)
{
	return s.s[--s.n];
}

bool isFull(queue q)
{
	return q.n - q.m == MAX;
}

bool isEmpty(queue q)
{
	return q.n = q.m;
}

void printQueue(queue q)
{
	for (int i = 0; i < q.n; ++i)
		cout << q.q[i] << " ";
	cout << endl;
}

void enqueue(queue& q, int x)
{
	if (isFull(q)) return;
	q.q[q.n] = x;
	q.n++;
}

int dequeue(queue& q)
{
	int kq = q.q[q.m];
	q.m++;
	queueRearrange(q);
	return kq;
}

void queueRearrange(queue& q)
{
	for (int i = 0; i < q.n - 1; ++i)
		q.q[i] = q.q[i + 1];
	q.m--;
	q.n--;
}