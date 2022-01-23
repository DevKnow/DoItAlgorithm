#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)do{type t = x; x=y; y=t;}while(0)

void partition(int a[], int n) {
	int pl = 0;
	int pr = n - 1;
	int x = a[n / 2];
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	printf("피벗의 값: %d\n", x);
	puts("피벗 이하의 그룹");
	for (int i = 0; i < pl; i++)
		printf("%d ", a[i]);
	putchar('\n');
	puts("피벗과 일치하는 그룹");
	for (int i = pr+1; i<=pl-1;i++)
		printf("%d ", a[i]);
	putchar('\n');
	puts("피벗 이상의 그룹");
	for (int i = pr+1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

int main() {
	int nx;
	puts("배열을 나눕니다");
	printf("요소 개수 : "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}
	partition(x, nx);
	free(x);

	return 0;
}