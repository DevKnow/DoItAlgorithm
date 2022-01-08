#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;
	int num;
	int* que;
} ArrayIntQueue;

int Init(ArrayIntQueue* q, int max);

int Enqueue(ArrayIntQueue* q, int x);

int Dequeue(ArrayIntQueue* q, int *x);

bool IsGonnaFull(ArrayIntQueue* q);

bool IsGonnaEmpty(ArrayIntQueue* q);

int Size(const ArrayIntQueue* q);

int Capacity(const ArrayIntQueue* q);

void PrintQueue(const ArrayIntQueue* q);

void Terminate(ArrayIntQueue* q);