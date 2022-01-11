#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[]) {
	int k = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == key) idx[k++] = i;
	return k == 0 ? -1 : k;
}

int main() {
	int nx, ky, result;
	puts("연습문제3");
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	int* idx = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}
	printf("찾으려는 값: "); scanf("%d", &ky);
	result=search_idx(x, nx, ky, idx);

	if (result == -1)
		puts("검색 실패");
	else
		for (int i = 0; i<result; i++)
			printf("%d ", idx[i]);

	return 0;
}