#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack* s, int max)
{
	s->ptrA = 0;
	s->ptrB = 0;
	if ((s->stk = (int*)malloc(sizeof(int) * max)) == NULL) {
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack* s, int x, int stackName)
{
	if (IsFull(s)) return -1;
	if(stackName==1) s->stk[s->ptrA++] = x;
	else {
		s->stk[ReturnBindex(s)] = x;
		s->ptrB++;
	}
	return 0;
}

int ReturnBindex(IntStack* s) {
	return Capacity(s) - s->ptrB-1;
}

int Pop(IntStack* s, int* x, int stackName)
{
	if (IsEmpty(s, stackName)) return -1;
	if(stackName==1) *x = s->stk[--s->ptrA];
	else {
		--s->ptrB;
		*x = s->stk[ReturnBindex(s)];
	}
	return 0;
}

int Peek(IntStack* s, int* x, int stackName)
{
	if (IsEmpty(s, stackName)) return -1;
	if (stackName == 1) *x = s->stk[s->ptrA-1];
	else  *x = s->stk[ReturnBindex(s)+1];
	return 0;
}

void Clear(IntStack* s)
{
	s->ptrA = 0;
	s->ptrB = 0;
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s, int stackName)
{
	return stackName==1? s->ptrA : s->ptrB;
}

int IsEmpty(const IntStack* s, int stackName)
{
	return stackName==1? s->ptrA <= 0 : s->ptrB <= 0;
}

int IsFull(const IntStack* s)
{
	return s->ptrA+s->ptrB >= s->max;
}

int Search(IntStack* s, int x, int* stackName)
{
	for (int i = 0; i < Size(s, STACK_A); i++)
		if (s->stk[i] == x) {
			*stackName = STACK_A;
			return i;
		}

	for (int i = ReturnBindex(s)+1; i < Capacity(s); i++)
		if (s->stk[i] == x) {
			*stackName = STACK_B;
			return i;
		}

	return -1;
}

void Print(IntStack* s)
{
	printf("Stack A: ");
	for (int i = Size(s, STACK_A)-1; i >= 0; i--)
		printf("%d ", s->stk[i]);

	printf("\nStack B: ");
	for (int i = ReturnBindex(s)+1; i < Capacity(s); i++)
		printf("%d ", s->stk[i]);

	putchar('\n');
}


void Terminate(IntStack* s)
{
	if (s->stk != NULL) free(s->stk);
	s->max = s->ptrA = s->ptrB = 0;
}
