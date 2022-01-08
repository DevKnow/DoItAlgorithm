#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{ type t=x;x=y;y=t;}while(0)

// 그냥 했을 때 35

void bubble(int a[], int n) {
	int start = 0, end = n - 1,count=0, last= end;
	for(int i=0; start < end;i++){
		if (i % 2 == 1) {
			for (int j = end; j > start; j--) {
				if (a[j - 1] > a[j]) {
					swap(int, a[j - 1], a[j]);
					last = j;
					count++;
				}
				count++;
			}
			start = last;
		}
		else {
			for (int j = start; j < end; j++) {
				if (a[j] > a[j+1]) {
					swap(int, a[j] , a[j + 1]);
					last = j;
					count++;
				}
				count++;
			}
			end = last;
		}
	}
	printf("총 횟수: %d", count);
}

void shaker(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	int last = right;
	int count = 0;

	while (left < right) {
		int j;
		for (j = right; j > left; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
				count++;
			}
			count++;
		}
		left = last;

		for (j = left; j < right; j++) {
			if (a[j] > a[j + 1]) {
				swap(int, a[j], a[j + 1]);
				last = j;
				count++;
			}
			count++;
		}
		right = last;
	}
	printf("총 횟수: %d", count);
}

int main() {
	int i, nx;
	int* x;
	puts("버블 정렬");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);

	return 0;
}