#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	printf("n의 값: ");
	scanf("%d", &n);

	int sum = 0;
	
	if (n % 2 == 0)
		sum = (1 + n) * (n / 2);
	else
		sum = n * ((n-1) / 2) + n;

	printf("최종: %d\n", sum);

	return 0;
}