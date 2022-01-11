#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_compare(const int* a, const int* b) {
	if (*a < *b) return 1;
	else if (*a > *b) return -1;
	else return 0;
}

int main() {
	int nx, ky;
	int* x;
	int* p;
	puts("bsearch �Լ� ����Ͽ� �˻�");
	printf("��� ����: "); scanf("%d", &nx);
	x = (int*)malloc(sizeof(int) * nx);

	printf("������������ �Է�\n");
	printf("x[0]"); scanf("%d", &x[0]);
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] = ", i); scanf("%d", &x[i]);
		} while (x[i] > x[i - 1]);
	}

	printf("�˻��� ��: "); scanf("%d", &ky);
	p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*))int_compare);
	if (p == NULL)
		puts("�˻� ����");
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.", ky, (p - x));
	free(x);

	return 0;
}