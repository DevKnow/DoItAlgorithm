#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Shell(int a[], int n);

int main() {
	int nx;
	puts("�� ���� ����2");
	printf("��Ұ���: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}
	Shell(x, nx);
	puts("������������ ���� �Ϸ�");
	for (int i = 0; i < nx; i++)
		printf("x[%d]: %d\n", i, x[i]);
	free(x);
	return 0;
}

void Shell(int a[], int n) {
	int i, j, h;
	for (h = 1; h < n / 9; h = h * 3 + 1)
		;
	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			int temp = a[i];
			for (j = i - h; j >= 0 && a[j] > temp; j -= h)
				a[j + h] = a[j];
			a[j + h] = temp;
		}
	}
}