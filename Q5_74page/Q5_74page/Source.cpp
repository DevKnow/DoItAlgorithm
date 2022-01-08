#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t=x; x=y;y=t;}while(0)

void arr_reverse(int a[], int n) {
	int i;
	putchar('\n');
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
	for (i = 0; i < n / 2; i++) {

		printf("a[%d]�� a[%d]�� ��ȯ�մϴ�.\n", i, n - i - 1);
		swap(int, a[i], a[n - i - 1]);
		for (int k = 0; k < n; k++)
			printf("%d ", a[k]);
		putchar('\n');
	}
}

int main() {
	int i;
	int* x;
	int nx;

	printf("��� ����: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(x[0]));
	printf("%d���� ������ �Է��ϼ���.\n", nx);

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	arr_reverse(x, nx);

	puts("���� ������ �����մϴ�.");

	free(x);
	return 0;
}