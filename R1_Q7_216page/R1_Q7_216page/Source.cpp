#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)do {type t=x; x=y; y=t;}while(0)

void PrintArr(const int a[], int n);
void PrintPoint(int a, int b, int n);

void selection(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			
			if (a[j] < a[min]) min = j;
		}
		PrintPoint(i, min ,n);
		PrintArr(a, n);
		swap(int, a[i], a[min]);
	}
}

void PrintArr(const int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d ", a[i]);
	}
	putchar('\n');
}

void PrintPoint(int a, int b, int n) {
	for (int i = 0; i < n; i++) {
		if(i==a) printf("%2c ", '*');
		else if (i == b) printf("%2c ", '+');
		else printf("%2c ", ' ');
	}
	putchar('\n');
}

int main() {
	int i, nx;
	puts("단순 선택 정렬");
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	selection(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}