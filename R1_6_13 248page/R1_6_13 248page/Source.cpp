#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Merge(const int a[], int na, const int b[], int nb, int c[]) {
	int pa = 0, pb = 0, pc = 0;
	while (pa < na && pb < nb)
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
	while (pa < na) // a 배열의 요소를 덜 추가했을 때
		c[pc++] = a[pa++];
	while (pb < nb) // b 배열의 요소를 덜 추가했을 때
		c[pc++] = b[pb++];
}

int main() {
	int na, nb;
	int* a, *b, *c;
	printf("a 배열의 요소 개수: "); scanf("%d", &na);
	printf("b 배열의 요소 개수: "); scanf("%d", &nb);

	a = (int*)malloc(sizeof(int) * na);
	b = (int*)malloc(sizeof(int) * nb);
	c = (int*)malloc(sizeof(int) * (na + nb));

	printf("a[0]: "); scanf("%d", &a[0]);
	for (int i = 1; i < na; i++) {
		do {
			printf("a[%d]: ", i); scanf("%d", &a[i]);
		} while (a[i]<a[i-1]);
	}

	printf("\nb[0]: "); scanf("%d", &b[0]);
	for (int i = 1; i < nb; i++) {
		do {
			printf("b[%d]: ", i); scanf("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}

	Merge(a, na, b, nb, c);
	puts("배열 a와 배열 b를 병합하여 배열 c에 저장 완료");

	for (int i = 0; i < (na + nb); i++) {
		printf("c[%2d]: %2d\n", i, c[i]);
	}

	free(a); free(b); free(c);

	return 0;
}