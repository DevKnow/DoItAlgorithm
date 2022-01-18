#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)do {type t=x; x=y; y=t;}while(0)

void bubble(int a[], int n) {
	int compare = 0;
	for (int i = 0; i < n - 1; i++) {
		int change = 0;
		compare++;
		if (i % 2 == 1) {
			for (int j = n - 1; j > i; j--) {
				compare++;
				if (a[j] < a[j - 1]) swap(int, a[j], a[j - 1]); compare++; change++;
			}
		}
		else {
			for (int j = 0; j < n - 2; j++) {
				compare++;
				if (a[j] > a[j + 1]) swap(int, a[j], a[j + 1]); compare++; change++;
			}
		}
		if (change == 0) compare++; break;
	}
	printf("총 %d번 비교 및 교환했습니다.\n", compare);
}

int main() {
	int i, nx;
	puts("Q5");
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