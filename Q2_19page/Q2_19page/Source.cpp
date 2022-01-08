#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min3(int& a, int& b, int& c) {
	int min = a;
	if (min > b) min = b;
	if (min > c) min = c;
	return min;
}

int main() {
	int a = 3, b = 2, c = 1;

	printf("세 정수의 최소값을 구합니다.\n");
	printf("min3(%d,%d,%d)= %d\n", a, b, c, min3(a, b, c));
	printf("min3(%d,%d,%d)= %d\n", a, b, b, min3(a, b, b));
	printf("min3(%d,%d,%d)= %d\n", a, c, b, min3(a, c, b));
	printf("min3(%d,%d,%d)= %d\n", a, b, a, min3(a, b, a));
	printf("min3(%d,%d,%d)= %d\n", b, c, a, min3(b, c, a));
	printf("min3(%d,%d,%d)= %d\n", a, a, b, min3(a, a, b));
	printf("min3(%d,%d,%d)= %d\n", a, a, a, min3(a, a, a));
	printf("min3(%d,%d,%d)= %d\n", b, b, a, min3(b, b, a));
	printf("min3(%d,%d,%d)= %d\n", b, a, c, min3(b, a, c));
	printf("min3(%d,%d,%d)= %d\n", b, a, b, min3(b, a, b));
	printf("min3(%d,%d,%d)= %d\n", c, a, b, min3(c, a, b));
	printf("min3(%d,%d,%d)= %d\n", b, a, a, min3(b, a, a));
	printf("min3(%d,%d,%d)= %d\n", c, b, a, min3(c, b, a));

	return 0;
}