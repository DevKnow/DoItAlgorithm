#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max3(int& a, int& b, int& c) {
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return max;
}

int main() {
	int a=3, b=2, c=1;

	printf("세 정수의 최대값을 구합니다.\n");
	printf("max3(%d,%d,%d)= %d\n", a, b, c, max3(a, b, c));
	printf("max3(%d,%d,%d)= %d\n", a, b, b, max3(a, b, b));
	printf("max3(%d,%d,%d)= %d\n", a, c, b, max3(a, c, b));
	printf("max3(%d,%d,%d)= %d\n", a, b, a, max3(a, b, a));
	printf("max3(%d,%d,%d)= %d\n", b, c, a, max3(b, c, a));
	printf("max3(%d,%d,%d)= %d\n", a, a, b, max3(a, a, b));
	printf("max3(%d,%d,%d)= %d\n", a, a, a, max3(a, a, a));
	printf("max3(%d,%d,%d)= %d\n", b, b, a, max3(b, b, a));
	printf("max3(%d,%d,%d)= %d\n", b, a, c, max3(b, a, c));
	printf("max3(%d,%d,%d)= %d\n", b, a, b, max3(b, a, b));
	printf("max3(%d,%d,%d)= %d\n", c, a, b, max3(c, a, b));
	printf("max3(%d,%d,%d)= %d\n", b, a, a, max3(b, a, a));
	printf("max3(%d,%d,%d)= %d\n", c, b, a, max3(c, b, a));

	return 0;
}