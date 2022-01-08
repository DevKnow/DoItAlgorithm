#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void spira(int n) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n-i-1; k++)
			printf(" ");
		for (int k = 0;; ) {
			if (k == i * 2 + 1)
				break;
			else {
				printf("*");
				k++;
			}
		}
		putchar('\n');
	}
}

int main() {
	int n;

	printf("¸î´Ü »ï°¢Çü?: ");
	scanf("%d", &n);

	spira(n);

	return 0;
}