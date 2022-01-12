#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

int Initialize(ArrayIntQueue* q, int max)
{
	q->num = 0;
	if ((q->que = (int*)malloc(sizeof(int) * max)) == NULL) {
		q->max = 0;
		return -1;
	}
	q->max = max;

	return 0;
}

int Enqueue(ArrayIntQueue* q, int x)
{
	if (q->num >= q->max) return -1;
	q->que[q->num++] = x;
	return 0;
}

int Dequeue(ArrayIntQueue* q, int* x)
{
	if (q->num <= 0) return -1;
	*x= q->que[0];
	for (int i = 1; i < q->num; i++)
		q->que[i - 1] = q->que[i];
	q->num--;
	return 0;
}

int Size(ArrayIntQueue* q)
{
	return q->num;
}

int Capacity(ArrayIntQueue* q)
{
	return q->max;
}

void Terminate(ArrayIntQueue* q)
{
	if (q->que != NULL) free(q->que);
	q->max = q->num = 0;
}
