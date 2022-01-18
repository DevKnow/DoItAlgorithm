#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)do {type t=x; x=y; y=t;}while(0)

void bubble(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i-1; j++) {
			if (a[j] > a[j + 1])
				swap(int, a[j], a[j + 1]);
		}
	}
}

int main() {
	int i, nx;
	puts("Q1 �������� �տ�������");
	printf("��� ����: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}