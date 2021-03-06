#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n) {
	int j;
	for (int i = 1; i < n; i++) {
		a[0] = a[i];
		int temp = a[i];
		for (j = i; a[j - 1] > temp; j--)
			a[j] = a[j - 1];
		a[j] = temp;
	}
}

int main() {
	int i, nx;
	puts("단순 삽입 정렬");
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * (nx+1));

	for (i = 1; i < nx+1; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	insertion(x, nx+1);

	puts("오름차순으로 정렬했습니다.");
	for (i = 1; i < nx+1; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}