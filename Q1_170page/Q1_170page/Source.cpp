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
	printf("������ �Է��ϼ���: ");
	scanf("%d", &x);
	printf("%d�� �������� ���� %d�Դϴ�.", x, factorial(x));

	return 0;
}