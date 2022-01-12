#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int Initialize(IntQueue* q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = (int*)malloc(sizeof(int) * max)) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

void EnqueFront(IntQueue* q, int x)
{
	if (--q->front < 0) q->front = q->max-1;
	q->que[q->front] = x;
}

void EnqueBack(IntQueue* q, int x)
{
	q->que[q->rear++] = x;
	if (q->rear == q->max) q->rear = 0;
}

void DequeFront(IntQueue* q, int* x)
{
	*x = q->que[q->front++];
	if (q->front == q->max) q->front = 0;
}

void DequeBack(IntQueue* q, int* x)
{
	if (--q->rear < 0) q->rear = q->max;
	*x = q->que[q->rear];
}

int Enque(IntQueue* q, int x, int ForB)
{
	if (IsFull(q)) return -1;
	if (ForB == FRONT) EnqueFront(q, x);
	else EnqueBack(q, x);
	q->num++;
	return 0;
}

int Deque(IntQueue* q, int* x, int ForB)
{
	if (IsEmpty(q)) return -1;
	if (ForB == FRONT) DequeFront(q, x);
	else DequeBack(q, x);
	q->num--;
	return 0;
}

int Peek(const IntQueue* q, int* x, int ForB)
{
	if (q->num <= 0) return -1;
	if (ForB == FRONT) PeekFront(q, x);
	else PeekBack(q, x);
	return 0;
}

void PeekFront(const IntQueue* q, int* x)
{
	*x = q->que[q->front];
}

void PeekBack(const IntQueue* q, int* x)
{
	int temp = q->rear - 1;
	if (temp < 0) temp = q->max;
	*x = q->que[temp];
}

void Clear(IntQueue* q)
{
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntQueue* q)
{
	return q->max;
}

int Size(const IntQueue* q)
{
	return q->num;
}

int IsEmpty(const IntQueue* q)
{
	return q->num <= 0;
}

int IsFull(const IntQueue* q)
{
	return q->num >= q->max;
}

int Search(const IntQueue* q, int x)
{
	int idx;
	for (int i = 0; i < q->num; i++)
	{
		idx = (q->front + i) % q->max;
		if (q->que[idx] == x) return idx;
	}
	return -1;
}

void Print(const IntQueue* q)
{
	for (int i = 0; i < q->num; i++)
		printf("%d ", q->que[(q->front + i) % q->max]);
	putchar('\n');
}

void Terminate(IntQueue* q)
{
	if (q->que != NULL) free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}
