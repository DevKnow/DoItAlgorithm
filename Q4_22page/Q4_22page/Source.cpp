#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int med3(int a, int b, int c) {
	if (a >= b)
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
}

int main() {
	int a=3, b=2, c=1;

	printf("세 정수의 중앙값을 구합니다.\n");
	printf("med3(%d,%d,%d)= %d\n", a, b, c, med3(a, b, c));
	printf("med3(%d,%d,%d)= %d\n", a, b, b, med3(a, b, b));
	printf("med3(%d,%d,%d)= %d\n", a, c, b, med3(a, c, b));
	printf("med3(%d,%d,%d)= %d\n", a, b, a, med3(a, b, a));
	printf("med3(%d,%d,%d)= %d\n", b, c, a, med3(b, c, a));
	printf("med3(%d,%d,%d)= %d\n", a, a, b, med3(a, a, b));
	printf("med3(%d,%d,%d)= %d\n", a, a, a, med3(a, a, a));
	printf("med3(%d,%d,%d)= %d\n", b, b, a, med3(b, b, a));
	printf("med3(%d,%d,%d)= %d\n", b, a, c, med3(b, a, c));
	printf("med3(%d,%d,%d)= %d\n", b, a, b, med3(b, a, b));
	printf("med3(%d,%d,%d)= %d\n", c, a, b, med3(c, a, b));
	printf("med3(%d,%d,%d)= %d\n", b, a, a, med3(b, a, a));
	printf("med3(%d,%d,%d)= %d\n", c, b, a, med3(c, b, a));

	return 0;
}