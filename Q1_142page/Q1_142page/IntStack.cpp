#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack* s, int max)
{
	s->max = max;
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}
	s->ptr_A = 0;
	s->ptr_B = Capacity(s);
	return 0;
}

int Push(IntStack* s, int x, int ptr)
{
	if (IsFull(s)) // 스택이 가득 참
		return -1;
	if(ptr== PTR_A)
		s->stk[s->ptr_A++] = x;
	else
		s->stk[s->ptr_B--] = x;
	return 0;
}

int Pop(IntStack* s, int* x, int ptr)
{
	if (IsEmpty(s,ptr))  // 스택이 비어있음
		return -1;
	if (ptr == PTR_A)
		*x = s->stk[--s->ptr_A];
	else
		*x = s->stk[++s->ptr_B];
	
	return 0;
}

int Peek(const IntStack* s, int* x,int ptr)
{
	if (IsEmpty(s,ptr))  // 스택이 비어있음
		return -1;
	if (ptr == PTR_A)
		*x = s->stk[s->ptr_A - 1];
	if (ptr == PTR_B)
		*x = s->stk[s->ptr_B + 1];
	return 0;
}

void Clear(IntStack* s)
{
	s->ptr_A = 0;
	s->ptr_B = Capacity(s);
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s, int ptr)
{
	if(ptr==PTR_A)
		return s->ptr_A;
	else
		return Capacity(s)-s->ptr_B;
}

int IsEmpty(const IntStack* s,int ptr)
{
	if (ptr == PTR_A)
		return Size(s, PTR_A) <= 0;
	if (ptr == PTR_B)
		return Size(s, PTR_B) <= 0;
}

int IsFull(const IntStack* s)
{
	return Size(s,PTR_A)+ Size(s, PTR_B) >= Capacity(s);
}

int Search(const IntStack* s, int x,int& stack)
{
	for (int i = s->ptr_A - 1; i >= 0; i--)
		if (s->stk[i] == x) {
			stack = 1;
			return i;
		}
	for (int i = s->ptr_B + 1; i < Capacity(s); i++)
		if (s->stk[i] == x) {
			stack = 2;
			return i;
		}
	return -1;
}

void Print(const IntStack* s, int ptr)
{
	if (Size(s, ptr) == 0) {
		printf("출력할 데이터가 없습니다.\n");
		return;
	}
	if(ptr==PTR_A)
		for (int i = Size(s, ptr)-1; i >= 0; i--)
			printf("%d ", s->stk[i]);
	else if(ptr==PTR_B)
		for (int i = s->ptr_B + 1; i <= Capacity(s); i++)
			printf("%d ", s->stk[i]);
	putchar('\n');
}

void Terminate(IntStack* s)
{
	Clear(s);
	for (int i = 0; i < s->max; i++)
		s->stk[i] = NULL;
	s->ptr_B = 0;
	s->ptr_A = 0;
	s->max = 0;
}
