#include <stdio.h>
#include <stdlib.h>

void ary_copy(int a[], const int b[], int n);

int main() {
	int *a;
	int b[] = { 1,2,3,4,5 };
	a = (int*)calloc(5, sizeof(b[0]));

	ary_copy(a, b, 5);

	if (a != NULL) {
		for (int i = 0; i < 5; i++)
			printf("%d ", a[i]);
	}

	return 0;
}

void ary_copy(int a[], const int b[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}
