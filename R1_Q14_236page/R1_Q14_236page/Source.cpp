#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)

void Quick(int a[], int left, int right) {
	IntStack lstack; /* �����ϴ� ���� ����� �ε����� ������ ���� */
	IntStack rstack; /* �����ϴ� ���� ����� �ε����� ������ ���� */

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	printf("a[%d] ~ a[%d]�� ���ÿ� Ǫ��\n", left, right);
	printf("���� ����:");   Print(&lstack);
	printf("���� ����:");   Print(&rstack);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];

		printf("====================================================\n");
		printf("Pop�� �迭�� ����: a[%d] ~ a[%d]\n", left, right);
		printf("====================================================\n");

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);

			printf("a[%d] ~ a[%d]�� ���ÿ� Ǫ��.\n", left, pr);
			printf("���� ����:");   Print(&lstack);
			printf("���� ����:");   Print(&rstack);
		}
		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);

			printf("a[%d] ~ a[%d]�� ���ÿ� Ǫ��.\n", pl, right);
			printf("���� ����:");   Print(&lstack);
			printf("���� ����:");   Print(&rstack);
		}
	}

	Terminate(&lstack);
	Terminate(&rstack);
}

int main() {
	int i, nx;
	int* x;
	puts("�迭�� �����ϴ�.");
	printf("��� ����: "); scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	Quick(x, 0, nx - 1);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}