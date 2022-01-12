#ifndef ___IntStack
#define ___IntStack

typedef enum {
	STACK_A = 1,
	STACK_B = 2
}StackName;

typedef struct {
	int max; // ���� �뷮
	int ptrA; // ���� ������A
	int ptrB; // ���� ������B
	int* stk; // ù ��� ������;
}IntStack;

int Initialize(IntStack* s, int max);

int Push(IntStack* s, int x, int stackName);

int Pop(IntStack* s, int* x, int stackName);

int Peek(IntStack* s, int* x, int stackName);

void Clear(IntStack* s);

int Capacity(const IntStack* s);

int ReturnBindex(IntStack* s);

int Size(const IntStack* s, int stackName);

int IsEmpty(const IntStack* s, int stackName);

int IsFull(const IntStack* s);

int Search(IntStack* s, int x, int* stackName);

void Print(IntStack* s);

void Terminate(IntStack* s);

#endif // !___IntStack
