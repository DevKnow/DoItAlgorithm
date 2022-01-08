#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	printf("nÀÇ °ª: ");
	scanf("%d", &n);
	
	int sum = 0;
	for (int i = 1; i < n+1; i++)
		sum += i;

	printf("sum: %d", sum);

	return 0;
}