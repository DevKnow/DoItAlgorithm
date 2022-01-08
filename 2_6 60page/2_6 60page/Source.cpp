#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	printf("사람 수: ");
	scanf("%d", &number);
	height = (int*)calloc(number, sizeof(int));
	srand(time(NULL));

	puts("사람의 키를 입력하세요.");
	for (i = 0; i < number; i++) {
		height[i] = 100 + rand() % 90;
		printf("a[%d]= %d\n", i,height[i]);
	}
	printf("가장 키가 큰 사람의 키는 %d입니다./n", maxof(height, number));

	free(height);

	return 0;
}