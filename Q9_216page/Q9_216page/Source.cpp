#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n) {
	int i, j;

	for (i = 1; i < n; i++) {
		int tmp = a[i];
		a[0] = a[i];
		for (j = i; a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		if (j!=0) a[j] = tmp;
	}
}

int main() {
	int nx;
	int* x;
	puts("�ܼ� ���� ����");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	nx += 1;
	for (int i = 1; i < nx; i++) {
		printf("x[%d]:", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (int i = 1; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}