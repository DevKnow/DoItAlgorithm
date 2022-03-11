#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void fsort(int a[], int n, int max) {
	int i;
	int* f = (int*)malloc(sizeof(int) * (max + 1));
	int *b = (int*)malloc(sizeof(int) * n);

	for (i = 0; i <= max; i++) f[i] = 0;
	for (i = 0; i < n; i++) f[a[i]]++;
	for (i = 1; i <= max; i++) f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];
	for (i = 0; i < n; i++) a[i] = b[i];

	free(b);
	free(f);
}

int main() {
	int i, nx;
	int* x;
	const int max = 100;
	puts("���� ����");
	printf("��� ����: ");

	scanf("%d", &nx);
	x = (int*)malloc(sizeof(int) * nx);
	printf("0 ~ %d�� ������ �Է��ϼ���.\n", max);

	for (i = 0; i < nx; i++) {
		do {
			printf("x[%d]", i); scanf("%d", &x[i]);
		} while (x[i]<0 || x[i]>max);
	}

	fsort(x, nx, max);
	puts("������������ �����߽��ϴ�.");

	for (i = 0; i < nx; i++)
		printf("x[%d]: %d\n", i, x[i]);

	free(x);

	return 0;
}