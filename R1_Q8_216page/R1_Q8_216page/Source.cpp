#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void PrintArr(const int a[], int n);
void PrintPoint(int insertPoint, int curr);


void insertion(int a[], int n) {
	int j;
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		PrintArr(a, n);
		for (j = i; j > 0 && a[j - 1] > temp; j--)
			a[j] = a[j - 1];
		a[j] = temp;
		PrintPoint(j, i);
	}
}

void PrintArr(const int a[], int n) {
	for (int i = 0; i < n; i++)
		printf("%2d ", a[i]);
	putchar('\n');
}

void PrintPoint(int insertPoint, int curr) {
	if (insertPoint == curr) {
		for (int i = 0; i <= curr; i++)
			printf("%2c ", i == curr ? '+' : ' ');
	}
	else {
		for (int i = 0; i <= curr; i++)
			printf("%s", i==insertPoint? "^--": i==curr? "-+ " : i<insertPoint? "   " : "---");
	}
	putchar('\n');
}

int main() {
	int i, nx;
	puts("단순 삽입 정렬");
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}