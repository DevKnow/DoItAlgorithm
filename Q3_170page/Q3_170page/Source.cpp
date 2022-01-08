#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int gcd_array(const int a[], int n) {
	int result = a[0];
	for (int i = 1; i < n; i++)
		result=gcd(result, a[i]);
	return result;
}

int main() {
	/*
	int x, y;
	puts("�� ������ �ִ������� ���մϴ�.");
	printf("x ������ �Է��ϼ���: ");
	scanf("%d", &x);
	printf("y ������ �Է��ϼ���: ");
	scanf("%d", &y);
	*/
	int arr[] = {28,56,126};
	printf("�ִ������� %d�Դϴ�.\n", gcd_array(arr,3));

	return 0;
}