#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t=x; x=y; y=t;}while(0)

int is_sorted(const int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) return 0;
	}
	return 1;
}

int main() {
	int i, nx;
	puts("버블 정렬");
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	if (is_sorted(x, nx) != 0)
		puts("오름차순으로 정렬되어 있습습니다.");
	else
		puts("정렬되어 있지 않은 배열입니다.");

	free(x);

	return 0;
}