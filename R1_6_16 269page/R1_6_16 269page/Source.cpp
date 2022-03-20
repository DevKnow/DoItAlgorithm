#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void FSort(int a[], int n, int max) {
	int* f = (int*)malloc(sizeof(int) * (max + 1));
	int* b = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i <= max; i++) f[i] = 0; // 0���� �ʱ�ȭ
	for (int i = 0; i < n; i++) f[a[i]]++; // ��������ǥ �����
	for (int i = 1; i <= max; i++) f[i] += f[i - 1]; // ������������ǥ �����
	for (int i = n-1; i >= 0; i--) b[--f[a[i]]]=a[i]; // �˸��� ��ġ�� ����
	for (int i = 0; i < n; i++) a[i] = b[i]; // �迭 ����
	
	free(f);
	free(b);
}

int main() {
	const int MAX = 100;
	puts("���� ����");
	
	int nx;
	printf("��� ����: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	printf("\n0~%d�� ������ �Է��ϼ���.\n", MAX);
	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d]: ", i); scanf("%d", &x[i]);
		} while (x[i]<0 || x[i]>MAX);
	}

	FSort(x, nx, MAX);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}