#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key) {
	int i = 0;
	while (1) {
		if ( i == n) return -1; // 검색 실패
		if (a[i] == key) return i; // 검색 성공
		i++;
	}
}

int main() {

	int nx, ky, idx;
	int* x;
	puts("선형 검색");
	printf("요소 개수: "); scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = ", i); scanf("%d", &x[i]);
	}
	printf("\n검색하려는 값: "); scanf("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("검색 실패");
	else
		printf("%d는 x[%d]에 있습니다.", ky, idx);
	free(x);

	return 0;
}