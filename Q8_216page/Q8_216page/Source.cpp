#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n) {
	int j;
	for (int i = 1; i < n; i++) {
		int exg = 0;

		for (int k = 0; k < n; k++)
			printf("%3d", a[k]);
		putchar('\n');

		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
			exg++;
		}
		a[j] = tmp;

		if (exg == 0) {
			for (int k = 0; k < n; k++)
				printf("%3c", k == i ? '+' : ' ');
		}
		else {
			for (int k = 0; k < j; k++)
				printf("   ");
			for (int k = j; k < i; k++)
				printf("%3s", k == j ? "^--" : "---");
			printf("--+");
		}
		putchar('\n');
	}
	for (int k = 0; k < n; k++)
		printf("%3d", a[k]);
	putchar('\n');
}

int main() {
	int nx;
	int* x;
	puts("단순 삽입 정렬");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d]:", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}