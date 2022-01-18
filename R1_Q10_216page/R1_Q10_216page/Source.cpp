#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n) {
	int j;
	for (int i = 1; i < n; i++) {
		int temp = a[i];

		int pl = 0; int pr = i - 1;
		int pc;
		do {
			pc = (pl + pr) / 2;
			if (a[pc] == temp) break;
			if (a[pc] > temp) pr = pc - 1;
			else pl = pc + 1;
		} while (pl <= pr);
		int idx = pl <= pr ? pc + 1 : pr + 1;

		for (j = i; j > idx; j--)
			a[j] = a[j - 1];
		a[idx] = temp;
	}
}

int binarySearch(const int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	int pc;
	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key) return pc;
		if (a[pc] > key) pr = pc - 1;
		else pl = pc + 1;
	} while (pl <= pr);
	return -1;
}

int main() {
	int i, nx;
	puts("Q10 이진 삽입 정렬");
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}