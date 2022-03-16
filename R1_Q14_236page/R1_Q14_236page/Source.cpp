#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)

void Quick(int a[], int left, int right) {
	IntStack lstack; /* 분할하는 앞쪽 요소의 인덱스를 저장할 스택 */
	IntStack rstack; /* 분할하는 뒤쪽 요소의 인덱스를 저장할 스택 */

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	printf("a[%d] ~ a[%d]를 스택에 푸시\n", left, right);
	printf("앞쪽 스택:");   Print(&lstack);
	printf("뒤쪽 스택:");   Print(&rstack);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];

		printf("====================================================\n");
		printf("Pop한 배열의 범위: a[%d] ~ a[%d]\n", left, right);
		printf("====================================================\n");

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);

			printf("a[%d] ~ a[%d]를 스택에 푸시.\n", left, pr);
			printf("앞쪽 스택:");   Print(&lstack);
			printf("뒤쪽 스택:");   Print(&rstack);
		}
		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);

			printf("a[%d] ~ a[%d]를 스택에 푸시.\n", pl, right);
			printf("앞쪽 스택:");   Print(&lstack);
			printf("뒤쪽 스택:");   Print(&rstack);
		}
	}

	Terminate(&lstack);
	Terminate(&rstack);
}

int main() {
	int i, nx;
	int* x;
	puts("배열을 나눕니다.");
	printf("요소 개수: "); scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	Quick(x, 0, nx - 1);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}