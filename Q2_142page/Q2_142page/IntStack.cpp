#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack* s, int max)
{
	s->ptr = 0;
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack* s, int x)
{
	if (IsFull(s)) // 스택이 가득 참
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

int Pop(IntStack* s, int* x)
{
	if (IsEmpty(s))  // 스택이 비어있음
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

int Peek(const IntStack* s, int* x)
{
	if (IsEmpty(s))  // 스택이 비어있음
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

void Clear(IntStack* s)
{
	s->ptr = 0;
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s)
{
	return s->ptr;
}

int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0;
}

int IsFull(const IntStack* s)
{
	return s->ptr >= Capacity(s);
}

int Search(const IntStack* s, int x)
{
	for (int i = s->ptr - 1; i >= 0; i--)
		if (s->stk[i] == x)
			return i;
	return -1;
}

void Print(const IntStack* s)
{
	if (Size(s) == 0) {
		printf("출력할 데이터가 없습니다.\n");
		return;
	}
	for (int i = Size(s) - 1; i >= 0; i--)
		printf("%d ", s->stk[i]);
	putchar('\n');
}

void Terminate(IntStack* s)
{
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}