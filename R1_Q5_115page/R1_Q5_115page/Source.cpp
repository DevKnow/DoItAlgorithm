#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int bin_search2(const int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	int pc;
	int idx;
	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key) {
			idx = pc;
			for (int i = pc; i >= 0; i--) {
				if (a[i] == key) idx = i;
			}
			return idx;
		}
		else if (a[pc] < key) pl = pc + 1; 
		else pr = pc - 1;
	} while (pl <= pr);

	return -1;
}

int main() {
	int nx, ky, idx;
	puts("��������5");
	printf("��� ����: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = ", i); scanf("%d", &x[i]);
	}
	printf("ã������ ��: "); scanf("%d", &ky);

	idx = bin_search2(x, nx, ky);

	if (idx == -1)
		puts("\n�˻��� �����߽��ϴ�.");
	else
		printf("\n%d�� x[%d] ��ġ�� �ֽ��ϴ�.(���� ���� �ε���)", ky, idx);

	return 0;
}