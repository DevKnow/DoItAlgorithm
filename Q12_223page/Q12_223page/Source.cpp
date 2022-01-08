#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Shellver1(int a[], int n) {
	int i, j, h, move=0;
	for (h = n / 2; h > 0; h /= 2) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h){
				a[j + h] = a[j];
				move++;
			}
			a[j + h] = tmp;
			move++;
		}
	}
	printf("\nShellver1 func�� ���� �� ����� �̵� Ƚ��: %d\n", move);
}


void Shellver2(int a[], int n) {
	int i, j, h, move=0;

	for (h = 1; h < n / 9; h = h * 3 + 1);

	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h){
				a[j + h] = a[j];
				move++;
			}
			a[j + h] = tmp;
			move++;
		}
	}
	printf("\nShellver2 func�� ���� �� ����� �̵� Ƚ��: %d\n", move);
}

int main() {
	int i, nx;
	int* x;
	puts("�� ����");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	// Shellver1(x, nx);
	Shellver2(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}