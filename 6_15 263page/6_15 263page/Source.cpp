#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x=y; y=t;}while(0)

static void downHeap(int a[], int left, int right) {
	int temp = a[left];
	int child, parent;
	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;
		int cr = cl + 1;
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;
		if (temp >= a[child])
			break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

void heapSort(int a[], int n) {
	for (int i = (n - 1) / 2; i >= 0; i--)
		downHeap(a, i, n - 1);
	for (int i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);
		downHeap(a, 0, i - 1);
	}
}

int main() {
	puts("힙 정렬");
	int nx;
	printf("요수의 개수: "); scanf("%d", &nx);
	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i); scanf("%d", &x[i]);
	}

	heapSort(x, nx);
	puts("오름차순으로 정렬");

	for (int i = 0; i < nx; i++) {
		printf("x[%d]: %d\n", i, x[i]);
	}

	free(x);

	return 0;
}