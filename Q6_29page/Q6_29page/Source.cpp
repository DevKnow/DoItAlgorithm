#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, n;

	int sum;
	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값: ");
	scanf("%d", &n);
	sum = 0;
	i = 1;
	while (true) {
		if (i > n) {
			printf("i=%d: while문을 탈출합니다.\n", i);
			break;
		}
		sum += i;
		i++;
	}
	printf("1부터 %d까지의 합은 %d입니다.", n, sum);

	return 0;
}