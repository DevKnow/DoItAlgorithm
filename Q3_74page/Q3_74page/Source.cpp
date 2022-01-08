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
	printf("사람 수: ");
	scanf("%d", &number);
	height = (int*)calloc(number, sizeof(int));

	puts("사람의 키를 입력하세요.");
	for (i = 0; i < number; i++) {
		printf("a[%d]: ", i);
		scanf("%d", &height[i]);
	}
	printf("모든 사람의 키 평균은 %.2f입니다./n", aveof(height, number));

	free(height);

	return 0;
}