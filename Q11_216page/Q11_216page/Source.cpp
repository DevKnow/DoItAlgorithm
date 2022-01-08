#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

void insertion(int a[], int n) {
	int j;

	for (int i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0, pr = i - 1;
		int pc;
		int pd;

		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)  break;
			else if (a[pc] < key) pl = pc + 1;
			else pr = pc - 1;

		} while (pl <= pr);
		pd = (pl <= pr) ? pc + 1 : pr + 1;

		memmove(&a[pd + 1], &a[pd], (i - pd) * sizeof(int));
		a[pd] = key;
	}
}

int main() {
	int nx;
	int* x;
	puts("단순 삽입 정렬");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d]:", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}