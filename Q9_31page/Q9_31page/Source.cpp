#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

int BetweenSum(int& a, int& b) {
	int sum = 0;
	if (a < b) {
		for (int i = a; i < b + 1; i++) {
			sum += i;
		}
	}
	else {
		for (int i = b; i < a + 1; i++) {
			sum += i;
		}
	}

	return sum;
}

int main() {
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	int sum = BetweenSum(num1, num2);
	
	printf("sum= %d\n", sum);
	return 0;
}