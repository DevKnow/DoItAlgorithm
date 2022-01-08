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
	puts("두 정수의 최대공약수를 구합니다.");
	printf("x 정수를 입력하세요: ");
	scanf("%d", &x);
	printf("y 정수를 입력하세요: ");
	scanf("%d", &y);
	*/
	int arr[] = {28,56,126};
	printf("최대공약수는 %d입니다.\n", gcd_array(arr,3));

	return 0;
}