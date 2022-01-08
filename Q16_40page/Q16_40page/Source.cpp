#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void triangleLB(int n) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i + 1; k++)
			printf("*");
		putchar('\n');
	}
}

void triangleLU(int n) {
	for (int i = 0; i < n; i++) {
		for (int k = n; k > i; k--)
			printf("*");
		putchar('\n');
	}
}

void triangleRU(int n) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++)
			printf(" ");
		for (int k = 0; k < n - i; k++)
			printf("*");
		putchar('\n');
	}
}

void triangleRB(int n) {
	for (int i = 0; i < n; i++) {
		for (int k = n; k > i + 1; k--)
			printf(" ");
		for (int k = 0; k < i + 1; k++)
			printf("*");
		putchar('\n');
	}
}

int main() {
	int n;

	printf("¸î´Ü »ï°¢Çü?: ");
	scanf("%d", &n);

	triangleLB(n);
	triangleLU(n);
	triangleRU(n);
	triangleRB(n);

	return 0;
}