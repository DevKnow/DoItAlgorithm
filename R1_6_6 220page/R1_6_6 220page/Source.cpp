#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Shell(int a[], int n);

int main() {
	int nx;
	puts("셸 정렬");
	printf("요소개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++){
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}
	Shell(x, nx);
	puts("오름차순으로 정렬 완료");
	for (int i = 0; i < nx; i++)
		printf("x[%d]: %d\n", i, x[i]);
	free(x);
	return 0;
}

void Shell(int a[], int n) {
	int i, j, h;
	for (h = n / 2; h > 0; h /= 2)
		for (i = h; i < n; i++) {
			int temp = a[i];
			for (j = i - h; j >= 0 && a[j] > temp; j -= h)
				a[j + h] = a[j];
			a[j + h] = temp;
		}
}