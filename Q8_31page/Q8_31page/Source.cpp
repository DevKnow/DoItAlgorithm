#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	printf("n�� ��: ");
	scanf("%d", &n);

	int sum = 0;
	
	if (n % 2 == 0)
		sum = (1 + n) * (n / 2);
	else
		sum = n * ((n-1) / 2) + n;

	printf("����: %d\n", sum);

	return 0;
}