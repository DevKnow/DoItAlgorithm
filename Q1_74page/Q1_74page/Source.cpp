#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int minof(const int a[], int n) {
	int i;
	int min = a[0];
	for (i = 0; i < n; i++)
		if (a[i] < min) min = a[i];
	return min;
}

int main() {
	int i;
	int* height;
	int number;
	printf("��� ��: ");
	scanf("%d", &number);
	height = (int*)calloc(number, sizeof(int));

	puts("����� Ű�� �Է��ϼ���.");
	for (i = 0; i < number; i++) {
		printf("a[%d]: ", i);
		scanf("%d", &height[i]);
	}
	printf("���� Ű�� ���� ����� Ű�� %d�Դϴ�./n", minof(height, number));

	free(height);

	return 0;
}