#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {
	int a=1;
	for (int i = 1; i < n+1; i++)
		a = a* i;
	return a;
}

int main() {
	int x;
	printf("정수를 입력하세요: ");
	scanf("%d", &x);
	printf("%d의 순차곱셈 값은 %d입니다.", x, factorial(x));

	return 0;
}