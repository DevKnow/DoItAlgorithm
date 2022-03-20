#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void FSort(int a[], int n, int max) {
	int* f = (int*)malloc(sizeof(int) * (max + 1));
	int* b = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i <= max; i++) f[i] = 0; // 0으로 초기화
	for (int i = 0; i < n; i++) f[a[i]]++; // 도수분포표 만들기
	for (int i = 1; i <= max; i++) f[i] += f[i - 1]; // 누적도수분포표 만들기
	for (int i = n-1; i >= 0; i--) b[--f[a[i]]]=a[i]; // 알맞은 위치에 저장
	for (int i = 0; i < n; i++) a[i] = b[i]; // 배열 복사
	
	free(f);
	free(b);
}

int main() {
	const int MAX = 100;
	puts("도수 정렬");
	
	int nx;
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	printf("\n0~%d의 정수를 입력하세요.\n", MAX);
	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d]: ", i); scanf("%d", &x[i]);
		} while (x[i]<0 || x[i]>MAX);
	}

	FSort(x, nx, MAX);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}