#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t=x; x=y; y=t;}while(0)

void bubble(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;
		printf("패스%d:\n", i);
		for (int j = n - 1; j > i; j--) {
			for (int k = 0; k < n; k++) {
				printf("%2d %2c ", a[k], k != j - 1 ? ' ' : a[j - 1] > a[j] ? '+' : '-');
			}
			putchar('\n');
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		}
		for (int k = 0; k < n; k++) {
			printf("%2d %2c ", a[k], ' ');
		}
		putchar('\n');
		if (exchg == 0) break;
	}
}

int main() {
	int i, nx;
	puts("버블 정렬");
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}