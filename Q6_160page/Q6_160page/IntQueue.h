#ifndef _INT_QUEUE_H__
#define _INT_QUEUE_H__

typedef enum {
	FRONT = 1,
	BACK = 2
};

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* que;
}IntQueue;

int Initialize(IntQueue* q, int max);

int Enque(IntQueue* q, int x, int ForB);

void EnqueFront(IntQueue* q, int x);

void EnqueBack(IntQueue* q, int x);

int Deque(IntQueue* q, int* x, int ForB);

void DequeFront(IntQueue* q, int* x);

void DequeBack(IntQueue* q, int* x);

int Peek(const IntQueue* q, int* x, int ForB);

void PeekFront(const IntQueue* q, int* x);

void PeekBack(const IntQueue* q, int* x);

void Clear(IntQueue* q);

int Capacity(const IntQueue* q);

int Size(const IntQueue* q);

int IsEmpty(const IntQueue* q);

int IsFull(const IntQueue* q);

int Search(const IntQueue* q, int x);

void Print(const IntQueue* q);

void Terminate(IntQueue* q);

#endif // !1