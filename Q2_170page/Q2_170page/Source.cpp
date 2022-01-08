#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	int x, y;
	puts("두 정수의 최대공약수를 구합니다.");
	printf("x 정수를 입력하세요: ");
	scanf("%d", &x);
	printf("y 정수를 입력하세요: ");
	scanf("%d", &y);

	printf("최대공약수는 %d입니다.\n", gcd(x, y));

	return 0;
}