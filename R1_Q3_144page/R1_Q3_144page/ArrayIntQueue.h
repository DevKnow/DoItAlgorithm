#ifndef __ARRAY_INT_QUEUE_H__
#define __ARRAY_INT_QUEUE_H__

typedef struct {
	int max;
	int num;
	int* que;
}ArrayIntQueue;

int Initialize(ArrayIntQueue* q, int max);

int Enqueue(ArrayIntQueue* q, int x);

int Dequeue(ArrayIntQueue* q, int* x);

int Size(ArrayIntQueue* q);

int Capacity(ArrayIntQueue* q);

void Terminate(ArrayIntQueue* q);


#endif // !__ARRAY_INT_QUEUE_H__
