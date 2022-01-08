#include <stdio.h>

int main() {
	int i, j;
	printf("-----°ö¼ÀÇ¥-----\n");
	for (i = 1; i <= 9; i++){
		for (int j = 1; j <= 9; j++)
			printf("%3d", i * j);
		putchar('\n');
	}

	return 0;
}