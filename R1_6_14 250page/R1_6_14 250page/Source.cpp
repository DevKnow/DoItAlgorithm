#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static int* buff;

static void MergeSort(int a[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int j = 0;
		int k = left;
		int i;

		MergeSort(a, left, center); //  배열 앞 부분 병합 정렬로 정렬
		MergeSort(a, center + 1, right); //  배열 뒷 부분 병합 정렬로 정렬

		for (i = left; i <= center; i++) // 배열 앞 부분 임시 배열에 모두 순서대로 저장
			buff[p++] = a[i];
		while (i <= right && j < p) // 나머지 부분 처리
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while (j < p)
			a[k++] = buff[j++];
	}
}

int MergeSort(int a[], int n) {
	if ((buff = (int*)malloc(sizeof(int) * n)) == NULL)
		return -1;
	MergeSort(a, 0, n - 1);
	free(buff);
	return 0;
}

int main() {
	puts("병합 정렬");
	int nx;
	printf("요소 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);

	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	MergeSort(x, nx);

	puts("오름차순으로 정렬했습니다.");

	for (int i = 0; i < nx; i++)
		printf("x[%d]: %d\n", i, x[i]);

	free(x);

	return 0;
}