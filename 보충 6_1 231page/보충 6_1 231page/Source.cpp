#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)

void Quick(int a[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2]; // 피벗


	printf("a[%d]~[%d]: {", left, right);
	for (int i = left; i < right; i++)
		printf("%d, ", a[i]);
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) Quick(a, left, pr);
	if (pl < right) Quick(a, pl, right);
}

int main() {
	int i, nx;
	int* x;
	puts("배열을 나눕니다.");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	Quick(x, 0, nx - 1);
	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}