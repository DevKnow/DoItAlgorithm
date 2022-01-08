#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void nrpira(int n) {
	for (int i = 1; i < n+1; i++) {
		for (int k = 0; k <i-1; k++)
			printf(" ");
		for (int k = 0;; ) {
			if (k == (n-i) * 2 + 1)
				break;
			else {
				printf("%d",(i)%10);
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

	nrpira(n);

	return 0;
}