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
	srand(time(NULL));

	int i;
	int* height;
	int number= rand() % 16 + 5;

	printf("사람 수: %d\n", number);
	height = (int*)calloc(number, sizeof(int));


	puts("사람의 키를 입력하세요.");
	for (i = 0; i < number; i++) {
		height[i] = 100 + rand() % 90;
		printf("a[%d]= %d\n", i, height[i]);
	}
	printf("가장 키가 큰 사람의 키는 %d입니다./n", maxof(height, number));

	free(height);

	return 0;
}