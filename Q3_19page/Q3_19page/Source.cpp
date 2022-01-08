#include <cstdio>

int min4(int a, int b, int c, int d) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;
	return min;
}

int main() {

	int a = 3, b = 2, c = 1, d = 4;

	printf("네 정수의 최소값을 구합니다.\n");
	printf("max4(%d,%d,%d,%d)= %d\n", d, a, b, c, min4(d, a, b, c));
	printf("max4(%d,%d,%d,%d)= %d\n", a, b, d, b, min4(a, b, d, b));
	printf("max4(%d,%d,%d,%d)= %d\n", a, d, c, b, min4(a, d, c, b));
	printf("max4(%d,%d,%d,%d)= %d\n", a, b, a, d, min4(a, b, a, d));
	printf("max4(%d,%d,%d,%d)= %d\n", d, b, c, a, min4(d, b, c, a));
	printf("max4(%d,%d,%d,%d)= %d\n", a, d, a, b, min4(a, d, a, b));
	printf("max4(%d,%d,%d,%d)= %d\n", a, a, a, d, min4(a, a, a, d));
	printf("max4(%d,%d,%d,%d)= %d\n", b, b, a, d, min4(b, b, a, d));
	printf("max4(%d,%d,%d,%d)= %d\n", b, a, c, d, min4(b, a, c, d));
	printf("max4(%d,%d,%d,%d)= %d\n", b, a, d, b, min4(b, a, d, b));
	printf("max4(%d,%d,%d,%d)= %d\n", c, d, a, b, min4(c, d, a, b));
	printf("max4(%d,%d,%d,%d)= %d\n", d, d, a, a, min4(d, d, a, a));
	printf("max4(%d,%d,%d,%d)= %d\n", c, b, d, d, min4(c, b, d, d));

	return 0;
}