#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n) {
	int i;
	int max = a[0];
	for (i = 0; i < n; i++)
		if (a[i] > max) max = a[i];
	return max;
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
	printf("���� Ű�� ū ����� Ű�� %d�Դϴ�./n",maxof(height,number));
	
	free(height);

	return 0;
}