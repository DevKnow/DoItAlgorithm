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
	puts("�� ������ �ִ������� ���մϴ�.");
	printf("x ������ �Է��ϼ���: ");
	scanf("%d", &x);
	printf("y ������ �Է��ϼ���: ");
	scanf("%d", &y);

	printf("�ִ������� %d�Դϴ�.\n", gcd(x, y));

	return 0;
}