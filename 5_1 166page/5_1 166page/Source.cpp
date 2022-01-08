#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main() {
	int x;
	printf("정수를 입력하세요: ");
	scanf("%d", &x);
	printf("%d의 순차곱셈 값은 %d입니다.", x, factorial(x));
	
	return 0;
}