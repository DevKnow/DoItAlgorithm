#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int h, w;

	printf("����: "); scanf("%d", &h);
	printf("����: "); scanf("%d", &w);

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w+1; k++)
			printf("*");
		putchar('\n');
	}

	return 0;
}