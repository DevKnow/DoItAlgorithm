#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{ type t=x;x=y;y=t;}while(0)

void bubble(int a[], int n) {
	int count_swap = 0, count_cmp = 0;

	for (int i = 0; i < n - 1; i++) {
		int exg = 0;
		printf("�н�%d:\n", i);
		for (int j = n - 1; j > i; j--) {
			for (int k = 0; k < n; k++) {
				printf("%3d %c", a[k], k != j - 1? ' ' : a[j - 1] > a[j] ? '+' : '-');
			}
			putchar('\n');
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				count_swap++;
				exg++;
			}
			count_cmp++;
		}
		for (int j = 0; j < n; j++) {
			printf("%3d  ", a[j]);
		}
		putchar('\n');
		if (exg == 0) break;
	}
	printf("�� Ƚ��: %d / ", count_cmp);
	printf("��ȯ Ƚ��: %d\n", count_swap);
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