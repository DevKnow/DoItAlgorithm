#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 선형 검색 알고리즘 이용
void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*)) {
	for (size_t i = 0; i < nmemb; i++) {
		if (compar(((int*)base+i), key) == 0) return (void*)((int*)base + i);
	}
	return NULL;
}

int compare(const int* a, const int* b) {
	if (*a == *b) return 0;
	else return -1;
}

int main() {
	int num, keyValue;
	puts("연습문제7");
	printf("요소 개수: "); scanf("%d", &num);
	int* x = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) {
		printf("x[%d] = ", i); scanf("%d", &x[i]);
	}
	printf("검색할 값: "); scanf("%d", &keyValue);
	int* idx = (int*)seqsearch(&keyValue, x, num, sizeof(int), (int(*)(const void*, const void*))compare);
	if (idx == NULL)
		puts("검색 실패");
	else
		printf("%d는 x[%d]에 있습니다.", keyValue, idx-x);

	free(x);

	return 0;
}