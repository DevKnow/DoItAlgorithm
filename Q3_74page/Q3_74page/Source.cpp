#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double aveof(const int a[], int n) {
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i];
	return (double)sum/n;
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
	printf("��� ����� Ű ����� %.2f�Դϴ�./n", aveof(height, number));

	free(height);

	return 0;
}