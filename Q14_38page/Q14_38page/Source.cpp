#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++)
			printf("*");
		putchar('\n');
	}

	return 0;
}