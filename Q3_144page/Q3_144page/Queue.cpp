#include "Queue.h"

int Init(ArrayIntQueue* q, int max) {
	if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
		max = 0;
		return -1;
	}
	q->max = max;
	q->num = 0;
	return 0;
}

int Enqueue(ArrayIntQueue* q, int x) {
	if (IsGonnaFull(q)) return -1;
	q->que[q->num++] = x;
	return 1;
}

int Dequeue(ArrayIntQueue* q, int* x) {
	if (IsGonnaEmpty(q)) return -1;
	*x = q->que[0];
	for (int i = 1; i < q->num; i++)
		q->que[i - 1] = q->que[i];
	q->num--;
	return 1;
}

bool IsGonnaFull(ArrayIntQueue* q) {
	if ((q->num + 1) > q->max) return true;
	return false;
}

bool IsGonnaEmpty(ArrayIntQueue* q) {
	if ((q->num - 1) < 0) return true;
	return false;
}

int Size(const ArrayIntQueue* q) {
	return q->num;
}

int Capacity(const ArrayIntQueue* q) {
	return q->max;
}

void PrintQueue(const ArrayIntQueue* q){
	for (int i = 0; i < q->num; i++)
		printf("%d ", q->que[i]);
	putchar('\n');
}

void Terminate(ArrayIntQueue* q){
	if (q->que != NULL) free(q->que);
	q->max = 0;
	q->num = 0;
}
