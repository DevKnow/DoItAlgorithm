#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)do{type t = x; x=y; y=t;}while(0)

void partition(int a[], int n) {
	int pl = 0;
	int pr = n - 1;
	int x = a[n / 2];
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	printf("�ǹ��� ��: %d\n", x);
	puts("�ǹ� ������ �׷�");
	for (int i = 0; i < pl; i++)
		printf("%d ", a[i]);
	putchar('\n');
	puts("�ǹ��� ��ġ�ϴ� �׷�");
	for (int i = pr+1; i<=pl-1;i++)
		printf("%d ", a[i]);
	putchar('\n');
	puts("�ǹ� �̻��� �׷�");
	for (int i = pr+1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

int main() {
	int nx;
	puts("�迭�� �����ϴ�");
	printf("��� ���� : "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}
	partition(x, nx);
	free(x);

	return 0;
}