#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[]);

int main() {
	int a[] = { 1,9,2,9,4,6,7,9 };
	const int size_a = sizeof(a) / sizeof(a[0]);
	int b[size_a];
	int size_b=search_idx(a, size_a, 2, b);
	printf("%d°³\n", size_b);

	return 0;
}

int search_idx(const int a[], int n, int key, int idx[]) {
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == key) {
			idx[count++] = a[i];
		}
	return count;
}
