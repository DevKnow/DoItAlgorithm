#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void* binsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
int compare(const int* a, const int* b);

int main() {
	int num, keyValue;
	puts("연습문제9");
	printf("요소 개수: "); scanf("%d", &num);
	int* x = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) {
		printf("x[%d] = ", i); scanf("%d", &x[i]);
	}
	printf("검색할 값: "); scanf("%d", &keyValue);
	int* idx = (int*)binsearchx(&keyValue, x, num, sizeof(int), (int(*)(const void*, const void*))compare);
	if (idx == NULL)
		puts("검색 실패");
	else
		printf("%d는 x[%d]에 있습니다.", keyValue, idx - x);

	free(x);

	return 0;
}

void* binsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	int pl = 0;
	int pr = nmemb - 1;
	int pc;
	do {
		pc = (pl + pr) / 2;
		int temp = compar((void*)((int*)base + pc), key);
		if (temp == 0) {
			int* result = (int*)base + pc;
			for (int i = pc; i >= 0; i--)
				if (compar((void*)((int*)base + i), key)==0) result = (int*)base + i;
			return (void*)result;
		}
		else if (temp > 0) pr = pc - 1;
		else pl = pc + 1;
	} while (pl <= pr);
	return NULL;
}

int compare(const int* a, const int* b) {
	if (*a > *b) return 1;
	else if (*a < *b) return -1;
	else return 0;
}
