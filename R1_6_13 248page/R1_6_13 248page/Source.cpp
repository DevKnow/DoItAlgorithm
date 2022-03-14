#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Merge(const int a[], int na, const int b[], int nb, int c[]) {
	int pa = 0, pb = 0, pc = 0;
	while (pa < na && pb < nb)
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
	while (pa < na) // a �迭�� ��Ҹ� �� �߰����� ��
		c[pc++] = a[pa++];
	while (pb < nb) // b �迭�� ��Ҹ� �� �߰����� ��
		c[pc++] = b[pb++];
}

int main() {
	int na, nb;
	int* a, *b, *c;
	printf("a �迭�� ��� ����: "); scanf("%d", &na);
	printf("b �迭�� ��� ����: "); scanf("%d", &nb);

	a = (int*)malloc(sizeof(int) * na);
	b = (int*)malloc(sizeof(int) * nb);
	c = (int*)malloc(sizeof(int) * (na + nb));

	printf("a[0]: "); scanf("%d", &a[0]);
	for (int i = 1; i < na; i++) {
		do {
			printf("a[%d]: ", i); scanf("%d", &a[i]);
		} while (a[i]<a[i-1]);
	}

	printf("\nb[0]: "); scanf("%d", &b[0]);
	for (int i = 1; i < nb; i++) {
		do {
			printf("b[%d]: ", i); scanf("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}

	Merge(a, na, b, nb, c);
	puts("�迭 a�� �迭 b�� �����Ͽ� �迭 c�� ���� �Ϸ�");

	for (int i = 0; i < (na + nb); i++) {
		printf("c[%2d]: %2d\n", i, c[i]);
	}

	free(a); free(b); free(c);

	return 0;
}