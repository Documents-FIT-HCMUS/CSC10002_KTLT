#include "Stack - Queue.h"

int main()
{
	int menu;
	stack s;
	queue q;
	cout << "1. Demo STACK\n2. Demo QUEUE\nChon muc can demo: ";
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << "STACK\n";
		cout << "- Lan luot dua cac so 1 2 3 5 8 vao stack.\n";
		push(s, 1);
		push(s, 2);
		push(s, 3);
		push(s, 5);
		push(s, 8);
		cout << "- So phan tu trong stack hien co la: " << s.n << endl;
		cout << "- Stack chua cac gia tri: ";
		printStack(s);
		cout << "- Pop lan luot ba phan tu cuoi cua stack: ";
		cout << pop(s) << " ";
		cout << pop(s) << " ";
		cout << pop(s) << " ";
		cout << endl;
		cout << "- Stack con lai " << s.n << " phan tu: ";
		printStack(s);
		cout << endl;
		break;
	case 2:
		cout << "QUEUE\n";
		cout << "- Lan luot dua cac so 0 2 4 6 7 9  vao queue.\n";
		enqueue(q, 0);
		enqueue(q, 2);
		enqueue(q, 4);
		enqueue(q, 6);
		enqueue(q, 7);
		enqueue(q, 9);
		cout << "- So phan tu trong queue hien co la: " << q.n - q.m << endl;
		cout << "- Queue chua cac gia tri: ";
		printQueue(q);
		cout << "- Dequeue lan luot ba phan tu cua queue: ";
		cout << dequeue(q) << " ";
		cout << dequeue(q) << " ";
		cout << dequeue(q) << " ";
		cout << endl;
		cout << "- Queue con lai " << q.n - q.m << " phan tu: ";
		printQueue(q);
		cout << endl;
		break;
	default:
		break;
	}

	return 0;
}