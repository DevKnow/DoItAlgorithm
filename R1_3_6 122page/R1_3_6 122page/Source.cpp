#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int int_compare(const int* a, const int* b) {
	if (*a < *b) return 1;
	else if (*a > *b) return -1;
	else return 0;
}

int main() {
	int nx, ky;
	int* x;
	int* p;
	puts("bsearch 함수 사용하여 검색");
	printf("요소 개수: "); scanf("%d", &nx);
	x = (int*)malloc(sizeof(int) * nx);

	printf("내림차순으로 입력\n");
	printf("x[0]"); scanf("%d", &x[0]);
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] = ", i); scanf("%d", &x[i]);
		} while (x[i] > x[i - 1]);
	}

	printf("검색할 값: "); scanf("%d", &ky);
	p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*))int_compare);
	if (p == NULL)
		puts("검색 실패");
	else
		printf("%d는 x[%d]에 있습니다.", ky, (p - x));
	free(x);

	return 0;
}