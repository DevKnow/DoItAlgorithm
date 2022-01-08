#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{ type t=x;x=y;y=t;}while(0)

void bubble(int a[], int n) {
	int k=0;
	while (k < n - 1) {
		int last = n - 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i - 1] > a[i]) {
				swap(int, a[i - 1], a[i]);
				last = i;
			}
		}
		k = last;
	}
}

int main() {
	int i, nx;
	int* x;
	puts("���� ����");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}