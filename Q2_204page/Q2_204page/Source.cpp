#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{ type t=x;x=y;y=t;}while(0)

void bubble(int a[], int n) {
	int i, j;
	int ccnt = 0;
	int scnt = 0;
	for (i = 0; i < n - 1; i++) {
		printf("패스%d:\n", i + 1);
		for (j = n - 1; j > i; j--) {
			for (int k = 0; k < n - 1; k++)
				printf("%3d %c", a[k], (k != j - 1) ? ' ' : (a[j - 1] > a[j]) ? '+' : '-');
			printf("%3d\n", a[n - 1]);
			ccnt++;
			if (a[j - 1] > a[j]) {
				scnt++;
				swap(int, a[j - 1], a[j]);
			}
			putchar('\n');
		}
		for (int k = 0; k < n; k++)
			printf("%3d  ", a[k]);
		putchar('\n');
	}
	printf("비교 %d회\n", ccnt);
	printf("교환 %d회\n", scnt);
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

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}