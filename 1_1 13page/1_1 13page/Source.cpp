#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;

	printf("�� ������ �ִ밪�� ���մϴ�.\n");
	printf("a�� ��: "); scanf("%d", &a);
	printf("b�� ��: "); scanf("%d", &b);
	printf("c�� ��: "); scanf("%d", &c);

	int &max= a > b ? a : b > c ? b : c;

	printf("�ִ밪�� %d�Դϴ�.", max);

	return 0;
}