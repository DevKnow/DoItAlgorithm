#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t=x;x=y;y=t;}while(0)

void insertion(int a[], int n) {
	for (int i = 0; i<n-1 ; i++) {
		int min = i;

		for (int j = i; j < n; j++)
			if (a[j] < a[min])
				min = j;
		
		for (int j = 0; j < n; j++)
			printf("%3c", j == i ? '*' : j == min ? '+' : ' ');
		putchar('\n');

		for (int j = 0; j < n; j++)
			printf("%3d", a[j]);
		putchar('\n');

		swap(int, a[i], a[min]);
	}
	putchar('\n');
	for (int j = 0; j < n; j++)
		printf("%3d", a[j]);
	putchar('\n');
}

int main() {
	int nx;
	int* x;
	puts("단순 삽입 정렬");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d]:", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}