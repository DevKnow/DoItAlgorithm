#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key) {
	int i = 0;
	a[n] = key; // ���ʸ� �߰�
	while (1) {
		if (a[i] == key) break;
		i++;
	}
	return i == n ? -1 : i;
}

int main() {
	int nx, ky, idx;
	int* x;
	puts("���� �˻�(���ʹ�)");
	printf("��� ����: "); scanf("%d", &nx);
	x = (int*)calloc(nx+1, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = ", i); scanf("%d", &x[i]);
	}
	printf("ã������ Ű ��: "); scanf("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.", ky, idx);

	free(x);
	
	return 0;
}