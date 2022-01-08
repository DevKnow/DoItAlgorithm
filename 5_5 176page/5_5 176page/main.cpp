#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

void recure(int n) {
	IntStack stk;
	Initialize(&stk, 100);
Top:
	if (n > 0) {
		Push(&stk, n);
		n = n - 1;
		goto Top;
	}
	if (!IsEmpty(&stk)) {
		Pop(&stk, &n);
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
	Terminate(&stk);
}

int main() {
	recure(4);

	return 0;
}