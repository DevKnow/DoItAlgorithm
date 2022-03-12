#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int* a, const int* b) {
	if (*a < *b) return -1;
	else if (*a > *b) return 1;
	else return 0;
}

int main() {
	puts("qsort 함수에 의한 정렬");

	int nx;
	printf("요소 개수: "); scanf("%d", &nx);

	int* x = (int*)malloc(sizeof(int) * nx);

	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	qsort(x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	puts("오름차순으로 정렬 완료");
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: %d\n", i, x[i]);
	}

	free(x);

	return 0;
}