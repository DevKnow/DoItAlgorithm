#include <cstdio>

int max4(int a, int b, int c, int d) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}

int main() {

	int a = 3, b = 2, c = 1,d=4;

	printf("네 정수의 최대값을 구합니다.\n");
	printf("max4(%d,%d,%d,%d)= %d\n", d, a, b, c, max4(d, a, b, c));
	printf("max4(%d,%d,%d,%d)= %d\n", a, b, d, b, max4(a, b, d, b));
	printf("max4(%d,%d,%d,%d)= %d\n", a, d, c, b, max4(a, d, c, b));
	printf("max4(%d,%d,%d,%d)= %d\n", a, b, a, d, max4(a, b, a, d));
	printf("max4(%d,%d,%d,%d)= %d\n", d, b, c, a, max4(d, b, c, a));
	printf("max4(%d,%d,%d,%d)= %d\n", a, d, a, b, max4(a, d, a, b));
	printf("max4(%d,%d,%d,%d)= %d\n", a, a, a, d, max4(a, a, a, d));
	printf("max4(%d,%d,%d,%d)= %d\n", b, b, a, d, max4(b, b, a, d));
	printf("max4(%d,%d,%d,%d)= %d\n", b, a, c, d, max4(b, a, c, d));
	printf("max4(%d,%d,%d,%d)= %d\n", b, a, d, b, max4(b, a, d, b));
	printf("max4(%d,%d,%d,%d)= %d\n", c, d, a, b, max4(c, d, a, b));
	printf("max4(%d,%d,%d,%d)= %d\n", d, d, a, a, max4(d, d, a, a));
	printf("max4(%d,%d,%d,%d)= %d\n", c, b, d, d, max4(c, b, d, d));

	return 0;
}