#include <stdio.h>
#include <stdlib.h>

int main() {
	int* x;
	x = (int*)calloc(1, sizeof(int));
	if (x == NULL)
		puts("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	else {
		*x = 57;
		printf("*x=%d", *x);
		free(x);
	}

	return 0;
}