#include <stdio.h>

int main() {
	int i, j;
	printf("  |");
	for (int i = 1; i < 10; i++) {
		printf("%3d",i);
	}
	putchar('\n');
	printf("--+---------------------------\n");
	for (i = 1; i <= 9; i++) {
		printf("%d |",i);
		for (int j = 1; j <= 9; j++)
			printf("%3d", i * j);
		putchar('\n');
	}

	return 0;
}