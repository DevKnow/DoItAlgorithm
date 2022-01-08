#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{ type t=x;x=y;y=t;}while(0)

void bubble(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int exchg = 0;
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		if (exchg == 0) break;
	}
}

int is_sorted(const int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) return 0;
	}
	return 1;
}

int main() {
	int i, nx;
	int* x;
	puts("버블 정렬");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬했습니다.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	if (is_sorted(x, nx) == 1) printf("정상적으로 오름차순 정렬됨\n");
	else printf("오름차순이 아닙니다.\n");

	free(x);

	return 0;
}