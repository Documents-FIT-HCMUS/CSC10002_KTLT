#pragma once
#include <iostream>
#define MAX 1000
using namespace std;

struct stack
{
	int s[MAX];
	int n = 0;
};

void printStack(stack);
bool isEmpty(stack);
bool isFull(stack);
void push(stack&, int);
int pop(stack&);

struct queue
{
	int q[MAX];
	int n = 0, m = 0;
};

bool isEmpty(queue);
bool isFull(queue);
void printQueue(queue);
void enqueue(queue&, int);
int dequeue(queue&);
void queueRearrange(queue&);