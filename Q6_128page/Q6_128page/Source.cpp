#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long long_cmpr(const long* a, const long* b) {
	if (*a < *b) return 1;
	else if (*a > *b) return -1;
	else return 0;
}

int main(void) {
	long i, nx, ky;
	long* x;
	long* p=NULL;
	puts("bsearch 함수를 사용하여 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = (long*)malloc(sizeof(long) * nx);
	puts("내림차순으로 입력하세요.\n");
	printf("x[0]: ");
	scanf("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i]>x[i-1]);
	}
	printf("검색값: ");
	scanf("%d", &ky);
	if(x!=NULL)
		p = (long*)bsearch(&ky, x, nx, sizeof(long), (int(*)(const void*, const void*))long_cmpr);
	if (p == NULL)
		puts("검색에 실패했습니다");
	else
		printf("%d는(은) x[%d]에 있습니다\n", ky, p-x);

	free(x);

	return 0;
}