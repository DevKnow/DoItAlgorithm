#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static int* buff;

static void MergeSort(int a[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int j = 0;
		int k = left;
		int i;

		MergeSort(a, left, center); //  �迭 �� �κ� ���� ���ķ� ����
		MergeSort(a, center + 1, right); //  �迭 �� �κ� ���� ���ķ� ����

		for (i = left; i <= center; i++) // �迭 �� �κ� �ӽ� �迭�� ��� ������� ����
			buff[p++] = a[i];
		while (i <= right && j < p) // ������ �κ� ó��
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while (j < p)
			a[k++] = buff[j++];
	}
}

int MergeSort(int a[], int n) {
	if ((buff = (int*)malloc(sizeof(int) * n)) == NULL)
		return -1;
	MergeSort(a, 0, n - 1);
	free(buff);
	return 0;
}

int main() {
	puts("���� ����");
	int nx;
	printf("��� ����: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	MergeSort(x, nx);

	puts("������������ �����߽��ϴ�.");

	for (int i = 0; i < nx; i++)
		printf("x[%d]: %d\n", i, x[i]);

	free(x);

	return 0;
}