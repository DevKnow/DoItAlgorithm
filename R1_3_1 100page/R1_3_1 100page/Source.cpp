#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key) {
	int i = 0;
	while (1) {
		if ( i == n) return -1; // �˻� ����
		if (a[i] == key) return i; // �˻� ����
		i++;
	}
}

int main() {

	int nx, ky, idx;
	int* x;
	puts("���� �˻�");
	printf("��� ����: "); scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = ", i); scanf("%d", &x[i]);
	}
	printf("\n�˻��Ϸ��� ��: "); scanf("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("�˻� ����");
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.", ky, idx);
	free(x);

	return 0;
}